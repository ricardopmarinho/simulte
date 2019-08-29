/*
 * CAINLteRealisticChannelModel.h
 *
 *  Created on: Apr 15, 2019
 *      Author: ricardo
 */

#ifndef STACK_PHY_CHANNELMODEL_CAINLTEREALISTICCHANNELMODEL_H_
#define STACK_PHY_CHANNELMODEL_CAINLTEREALISTICCHANNELMODEL_H_

#include "stack/phy/ChannelModel/LteRealisticChannelModel.h"

class CAINLteRealisticChannelModel : public LteRealisticChannelModel {
private:
    // Carrier Frequency
    double carrierFrequency_;

    // stores my Playground Coords
    const Coord& myCoord_;

    // Information needed about the playground
    bool useTorus_;

    // eNodeB Height
    double hNodeB_;

    // UE Height
    double hUe_;

    // average Building Heights
    double hBuilding_;

    // Average street's wide
    double wStreet_;

    // enable/disable the shadowing
    bool shadowing_;

    // enable/disable intercell interference computation
    bool enableExtCellInterference_;
    bool enableMultiCellInterference_;
    bool enableD2DInCellInterference_;

    typedef std::pair<simtime_t, Coord> Position;

    // last position of current user
    std::map<MacNodeId, std::queue<Position> > positionHistory_;

    // scenario
    DeploymentScenario scenario_;

    // map that stores for each user if is in Line of Sight or not with eNodeB
    std::map<MacNodeId, bool> losMap_;

    // Store the last computed shadowing for each user
    std::map<MacNodeId, std::pair<simtime_t, double> > lastComputedSF_;

    //correlation distance used in shadowing computation and
    //also used to recompute the probability of LOS
    double correlationDistance_;

    //percentage of error probability reduction for each h-arq retransmission
    double harqReduction_;

    // eigen values of channel matrix
    //used to compute the rank
    double lambdaMinTh_;
    double lambdaMaxTh_;
    double lambdaRatioTh_;

    //Antenna gain of eNodeB
    double antennaGainEnB_;

    //Antenna gain of micro node
    double antennaGainMicro_;

    //Antenna gain of UE
    double antennaGainUe_;

    //Thermal noise
    double thermalNoise_;

    //pointer to Binder module
    LteBinder* binder_;

    //Cable loss
    double cableLoss_;

    //UE noise figure
    double ueNoiseFigure_;

    //eNodeB noise figure
    double bsNoiseFigure_;

    //Enabale disable fading
    bool fading_;

    //Number of fading paths in jakes fading
    int fadingPaths_;

    //avg delay spred in jakes fading
    double delayRMS_;

    bool tolerateMaxDistViolation_;

    //Struct used to store information about jakes fading
    struct JakesFadingData
    {
        std::vector<double> angleOfArrival;
        std::vector<simtime_t> delaySpread;
    };

    // for each node and for each band we store information about jakes fading
    std::map<MacNodeId, std::vector<JakesFadingData> > jakesFadingMap_;

    typedef std::vector<JakesFadingData> JakesFadingVector;
    typedef std::map<MacNodeId, JakesFadingVector> JakesFadingMap;

//    typedef std::map<MacNodeId,std::vector<JakesFadingData> > JakesFadingMap;

    enum FadingType
    {
        RAYLEIGH, JAKES
    };

    //Fading type (JAKES or RAYLEIGH)
    FadingType fadingType_;

    //enable or disable the dynamic computation of LOS NLOS probability for each user
    bool dynamicLos_;

    //if dynamicLos is false this boolean is initialized to true if all user will be in LOS or false otherwise
    bool fixedLos_;
public:
    CAINLteRealisticChannelModel(ParameterMap& params, const Coord& myCoord, unsigned int band);
    virtual ~CAINLteRealisticChannelModel();
    std::vector<double> getSINR(LteAirFrame *frame, UserControlInfo* lteInfo);
};

#endif /* STACK_PHY_CHANNELMODEL_CAINLTEREALISTICCHANNELMODEL_H_ */
