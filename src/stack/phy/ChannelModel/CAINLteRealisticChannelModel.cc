/*
 * CAINLteRealisticChannelModel.cpp
 *
 *  Created on: Apr 15, 2019
 *      Author: ricardo
 */

#include <CAINLteRealisticChannelModel.h>
#include "stack/phy/ChannelModel/CAINLteRealisticChannelModel.h"
#include "stack/phy/packet/LteAirFrame.h"
#include "corenetwork/binder/LteBinder.h"
#include "corenetwork/deployer/LteDeployer.h"
#include "stack/mac/amc/UserTxParams.h"
#include "common/LteCommon.h"
#include "corenetwork/nodes/ExtCell.h"
#include "stack/phy/layer/LtePhyUe.h"

using namespace std;

CAINLteRealisticChannelModel::CAINLteRealisticChannelModel(ParameterMap& params,
        const Coord& myCoord, unsigned int band)
        : LteRealisticChannelModel(params, myCoord, band), myCoord_(myCoord)
    {


}

CAINLteRealisticChannelModel::~CAINLteRealisticChannelModel() {
    // TODO Auto-generated destructor stub
}

double CAINcomputeAngle(Coord center, Coord point) {
    double relx, rely, arcoSen, angle, dist;

    // compute distance between points
    dist = point.distance(center);

    // compute distance along the axis
    relx = point.x - center.x;
    rely = point.y - center.y;

    // compute the arc sine
    arcoSen = asin(rely / dist) * 180.0 / M_PI;

    // adjust the angle depending on the quadrants
    if (relx < 0 && rely > 0) // quadrant II
        angle = 180.0 - arcoSen;
    else if (relx < 0 && rely <= 0) // quadrant III
        angle = 180.0 - arcoSen;
    else if (relx > 0 && rely < 0) // quadrant IV
        angle = 360.0 + arcoSen;
    else
        // quadrant I
        angle = arcoSen;

    //    EV << "CAINcomputeAngle: angle[" << angle <<"] - arcoSen[" << arcoSen <<
    //          "] - relativePos[" << relx << "," << rely <<
    //          "] - siny[" << rely/dist << "] - senx[" << relx/dist <<
    //          "]" << endl;

    return angle;
}

double CAINcomputeAngolarAttenuation(double angle) {
    double angolarAtt;
    double angolarAttMin = 25;
    // compute attenuation due to angolar position
    // see TR 36.814 V9.0.0 for more details
    angolarAtt = 12 * pow(angle / 70.0, 2);

    //  EV << "\t angolarAtt[" << angolarAtt << "]" << endl;
    // max value for angolar attenuation is 25 dB
    if (angolarAtt > angolarAttMin)
        angolarAtt = angolarAttMin;

    return angolarAtt;
}

std::vector<double> CAINLteRealisticChannelModel::getSINR(LteAirFrame *frame, UserControlInfo* lteInfo){

    // same code as in LteRealisticChannelModel::getSINR

    AttenuationVector::iterator it;
        //get tx power
        double recvPower = lteInfo->getTxPower(); // dBm

        //get move object associated to the packet
        //this object is refereed to eNodeB if direction is DL or UE if direction is UL
        Coord coord = lteInfo->getCoord();

        // position of eNb and UE
        Coord ueCoord;
        Coord enbCoord;

        double antennaGainTx = 0.0;
        double antennaGainRx = 0.0;
        double noiseFigure = 0.0;
        double speed = 0.0;

        // true if we are computing a CQI for the DL direction
        bool cqiDl = false;

        MacNodeId ueId = 0;
        MacNodeId eNbId = 0;

        EnbType eNbType;

        Direction dir = (Direction) lteInfo->getDirection();

        EV << "------------ GET SINR ----------------" << endl;
        //===================== PARAMETERS SETUP ============================
        /*
         * if direction is DL and this is not a feedback packet,
         * this function has been called by LteRealisticChannelModel::error() in the UE
         *
         *         DownLink error computation
         */
        if (dir == DL && (lteInfo->getFrameType() != FEEDBACKPKT))
        {
            //set noise Figure
            noiseFigure = ueNoiseFigure_; //dB
            //set antenna gain Figure
            antennaGainTx = antennaGainEnB_; //dB
            antennaGainRx = antennaGainUe_;  //dB

            // get MacId for Ue and eNb
            ueId = lteInfo->getDestId();
            eNbId = lteInfo->getSourceId();

            // get position of Ue and eNb
            ueCoord = myCoord_;
            enbCoord = lteInfo->getCoord();

            speed = computeSpeed(ueId, myCoord_);
        }
        /*
         * If direction is UL OR
         * if the packet is a feedback packet
         * it means that this function is called by the feedback computation module
         *
         * located in the eNodeB that compute the feedback received by the UE
         * Hence the UE macNodeId can be taken by the sourceId of the lteInfo
         * and the speed of the UE is contained by the Move object associated to the lteinfo
         */
        else // UL/DL CQI & UL error computation
        {
            // get MacId for Ue and eNb
            ueId = lteInfo->getSourceId();
            eNbId = lteInfo->getDestId();
            eNbType = getDeployer(eNbId)->getEnbType();

            if (dir == DL)
            {
                //set noise Figure
                noiseFigure = ueNoiseFigure_; //dB
                //set antenna gain Figure
                antennaGainTx = antennaGainEnB_; //dB
                antennaGainRx = antennaGainUe_;  //dB

                // use the jakes map in the UE side
                cqiDl = true;
            }
            else // if( dir == UL )
            {
                // TODO check if antennaGainEnB should be added in UL direction too
                antennaGainTx = antennaGainUe_;
                antennaGainRx = antennaGainEnB_;
                noiseFigure = bsNoiseFigure_;

                // use the jakes map in the eNb side
                cqiDl = false;
            }
            speed = computeSpeed(ueId, coord);

            // get position of Ue and eNb
            ueCoord = coord;
            enbCoord = myCoord_;
        }

        EV << "LteRealisticChannelModel::getSINR - srcId=" << lteInfo->getSourceId()
                           << " - destId=" << lteInfo->getDestId()
                           << " - DIR=" << (( dir==DL )?"DL" : "UL")
                           << " - frameType=" << ((lteInfo->getFrameType()==FEEDBACKPKT)?"feedback":"other")
                           << endl
                           << (( getDeployer(eNbId)->getEnbType() == MACRO_ENB )? "MACRO" : "MICRO") << " - txPwr " << lteInfo->getTxPower()
                           << " - ueCoord[" << ueCoord << "] - enbCoord[" << enbCoord << "] - ueId[" << ueId << "] - enbId[" << eNbId << "]" <<
                           endl;
        //=================== END PARAMETERS SETUP =======================

        //=============== PATH LOSS + SHADOWING + FADING =================
        EV << "\t using parameters - noiseFigure=" << noiseFigure << " - antennaGainTx=" << antennaGainTx << " - antennaGainRx=" << antennaGainRx <<
                " - txPwr=" << lteInfo->getTxPower() << " - for ueId=" << ueId << endl;

        // attenuation for the desired signal
        double attenuation;
        if ((lteInfo->getFrameType() == FEEDBACKPKT))
            attenuation = getAttenuation(ueId, UL, coord); // dB
        else
            attenuation = getAttenuation(ueId, dir, coord); // dB

        //compute attenuation (PATHLOSS + SHADOWING)
        recvPower -= attenuation; // (dBm-dB)=dBm

        //add antenna gain
        recvPower += antennaGainTx; // (dBm+dB)=dBm
        recvPower += antennaGainRx; // (dBm+dB)=dBm

        //sub cable loss
        recvPower -= cableLoss_; // (dBm-dB)=dBm

        //=============== ANGOLAR ATTENUATION =================
        if (dir == DL)
        {
            //get tx angle
            LtePhyBase* ltePhy = check_and_cast<LtePhyBase*>(
                    getSimulation()->getModule(binder_->getOmnetId(eNbId))->getSubmodule(
                            "nic")->getSubmodule("phy"));

            if (ltePhy->getTxDirection() == ANISOTROPIC)
            {
                // get tx angle
                double txAngle = ltePhy->getTxAngle();

                // compute the angle between uePosition and reference axis, considering the eNb as center
                double ueAngle = CAINcomputeAngle(enbCoord, ueCoord);

                // compute the reception angle between ue and eNb
                double recvAngle = fabs(txAngle - ueAngle);

                if (recvAngle > 180)
                    recvAngle = 360 - recvAngle;

                // compute attenuation due to sectorial tx
                double angolarAtt = CAINcomputeAngolarAttenuation(recvAngle);

                recvPower -= angolarAtt;
            }
            // else, antenna is omni-directional
        }
        //=============== END ANGOLAR ATTENUATION =================

        std::vector<double> snrVector;

        // compute and add interference due to fading
        // Apply fading for each band
        // if the phy layer is localized we can assume that for each logical band we have different fading attenuation
        // if the phy layer is distributed the number of logical band should be set to 1
        double fadingAttenuation = 0;
        //for each logical band
        for (unsigned int i = 0; i < band_; i++)
        {
            fadingAttenuation = 0;
            //if fading is enabled
            if (fading_)
            {
                //Appling fading
                if (fadingType_ == RAYLEIGH)
                    fadingAttenuation = rayleighFading(ueId, i);

                else if (fadingType_ == JAKES)
                    fadingAttenuation = jakesFading(ueId, speed, i, cqiDl);
            }
            // add fading contribution to the received pwr
            double finalRecvPower = recvPower + fadingAttenuation; // (dBm+dB)=dBm

            //if txmode is multi user the tx power is dived by the number of paired user
            // in db divede by 2 means -3db
            if (lteInfo->getTxMode() == MULTI_USER)
            {
                finalRecvPower -= 3;
            }

            EV << " LteRealisticChannelModel::getSINR node " << ueId
               << ((lteInfo->getFrameType() == FEEDBACKPKT) ?
                " FEEDBACK PACKET " : " NORMAL PACKET ")
               << " band " << i << " recvPower " << recvPower
               << " direction " << dirToA(dir) << " antenna gain tx "
               << antennaGainTx << " antenna gain rx " << antennaGainRx
               << " noise figure " << noiseFigure
               << " cable loss   " << cableLoss_
               << " attenuation (pathloss + shadowing) " << attenuation
               << " speed " << speed << " thermal noise " << thermalNoise_
               << " fading attenuation " << fadingAttenuation << endl;

          //  lteInfo->getPwrThresh() < recvPower ? EV << "MENOR\n" : EV <<"MAIOR\n";

            EV << "CHEGOU 2" << "\n";
            snrVector.push_back(finalRecvPower);
        }
        //============ END PATH LOSS + SHADOWING + FADING ===============

        /*
         * The SINR will be calculated as follows
         *
         *              Pwr
         * SINR = ---------
         *           N  +  I
         *
         * Ndb = thermalNoise_ + noiseFigure (measured in decibel)
         * I = extCellInterference + multiCellInterference
         */

        //============ MULTI CELL INTERFERENCE COMPUTATION =================
        //vector containing the sum of multiCell interference for each band
        std::vector<double> multiCellInterference; // Linear value (mW)
        // prepare data structure
        multiCellInterference.resize(band_, 0);
        if (enableMultiCellInterference_ && dir == DL)
        {
            computeMultiCellInterference(eNbId, ueId, ueCoord, (lteInfo->getFrameType() == FEEDBACKPKT), &multiCellInterference);
        }

        //============ EXTCELL INTERFERENCE COMPUTATION =================
        //vector containing the sum of multiCell interference for each band
        std::vector<double> extCellInterference; // Linear value (mW)
        // prepare data structure
        extCellInterference.resize(band_, 0);
        if (enableExtCellInterference_ && dir == DL)
        {
            computeExtCellInterference(eNbId, ueId, ueCoord, (lteInfo->getFrameType() == FEEDBACKPKT), &extCellInterference); // dBm
        }

        //===================== SINR COMPUTATION ========================
        if ((enableExtCellInterference_ || enableMultiCellInterference_) && dir == DL)
        {
            // compute and linearize total noise
            double totN = dBmToLinear(thermalNoise_ + noiseFigure);

            // denominator expressed in dBm as (N+extCell+multiCell)
            double den;
            EV << "LteRealisticChannelModel::getSINR - distance from my eNb=" << enbCoord.distance(ueCoord) << " - DIR=" << (( dir==DL )?"DL" : "UL") << endl;

            // add interference for each band
            for (unsigned int i = 0; i < band_; i++)
            {
                //               (      mW            +  mW  +        mW            )
                den = linearToDBm(extCellInterference[i] + totN + multiCellInterference[i]);

                EV << "\t ext[" << extCellInterference[i] << "] - multi[" << multiCellInterference[i] << "] - recvPwr["
                   << dBmToLinear(snrVector[i]) << "] - sinr[" << snrVector[i]-den << "]\n";

                // compute final SINR
                snrVector[i] -= den;
            }
        }
        // compute snr with no intercell interference
        else
        {
            for (unsigned int i = 0; i < band_; i++)
            {
                // compute final SINR
                snrVector[i] = snrVector[i] - noiseFigure - thermalNoise_;
                EV << "LteRealisticChannelModel::getSINR - distance from eNb=" << enbCoord.distance(coord) << " - DIR=" << (( dir==DL )?"DL" : "UL") << " - snr[" << snrVector[i] << "]\n";
            }
        }

                //if sender is an eNodeB
        if (dir == DL)
            //store the position of user
            updatePositionHistory(ueId, myCoord_);
        //sender is an UE
        else
            updatePositionHistory(ueId, coord);
        return snrVector;
}
