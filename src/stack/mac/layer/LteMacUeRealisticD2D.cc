//
//                           SimuLTE
//
// This file is part of a software released under the license included in file
// "license.pdf". This license can be also found at http://www.ltesimulator.com/
// The above file and the present reference are part of the software itself,
// and cannot be removed from it.
//

#include "stack/mac/layer/LteMacUeRealisticD2D.h"
#include "stack/mac/buffer/harq/LteHarqBufferRx.h"
#include "stack/mac/buffer/LteMacQueue.h"
#include "stack/mac/packet/LteSchedulingGrant.h"
#include "stack/mac/scheduler/LteSchedulerUeUl.h"
#include "stack/mac/layer/LteMacEnbRealistic.h"
#include "stack/mac/buffer/harq_d2d/LteHarqBufferRxD2DMirror.h"
#include "stack/d2dModeSelection/D2DModeSwitchNotification_m.h"
#include "stack/mac/packet/LteRac_m.h"
Define_Module(LteMacUeRealisticD2D);

LteMacUeRealisticD2D::LteMacUeRealisticD2D() :
    LteMacUeRealistic()
{
    racD2DMulticastRequested_ = false;
    bsrD2DMulticastTriggered_ = false;
}

LteMacUeRealisticD2D::~LteMacUeRealisticD2D()
{
}

void LteMacUeRealisticD2D::initialize(int stage)
{
    LteMacUeRealistic::initialize(stage);
    if (stage == 0)
    {
        cainMessageSentSignal = registerSignal("CainMessageSent");
        cainHopMesasgeSentSignal = registerSignal("CainHopMessageSent");
        dropedCainMessageSignal = registerSignal("DropedCainMessage");
        dropedHopMessageSignal = registerSignal("DropedHopMessage");
        // check the RLC module type: if it is not "RealisticD2D", abort simulation
        std::string pdcpType = getParentModule()->par("LtePdcpRrcType").stdstringValue();
        cModule* rlc = getParentModule()->getSubmodule("rlc");
        std::string rlcUmType = rlc->par("LteRlcUmType").stdstringValue();
        bool rlcD2dCapable = rlc->par("d2dCapable").boolValue();
        if (rlcUmType.compare("LteRlcUmRealistic") != 0 || !rlcD2dCapable)
            throw cRuntimeError("LteMacUeRealisticD2D::initialize - %s module found, must be LteRlcUmRealisticD2D. Aborting", rlcUmType.c_str());
        if (pdcpType.compare("LtePdcpRrcUeD2D") != 0)
            throw cRuntimeError("LteMacUeRealisticD2D::initialize - %s module found, must be LtePdcpRrcUeD2D. Aborting", pdcpType.c_str());
    }
    if (stage == 1)
    {
        // get parameters
        usePreconfiguredTxParams_ = par("usePreconfiguredTxParams");
        preconfiguredTxParams_ = getPreconfiguredTxParams();

        // get the reference to the eNB
        enb_ = check_and_cast<LteMacEnbRealisticD2D*>(getSimulation()->getModule(binder_->getOmnetId(getMacCellId()))->getSubmodule("nic")->getSubmodule("mac"));
    }
}

//Function for create only a BSR for the eNB
LteMacPdu* LteMacUeRealisticD2D::makeBsr(int size){

    UserControlInfo* uinfo = new UserControlInfo();
    uinfo->setSourceId(getMacNodeId());
    uinfo->setDestId(getMacCellId());
    uinfo->setDirection(UL);
    uinfo->setUserTxParams(schedulingGrant_->getUserTxParams()->dup());
    LteMacPdu* macPkt = new LteMacPdu("LteMacPdu");
    macPkt->setHeaderLength(MAC_HEADER);
    macPkt->setControlInfo(uinfo);
    macPkt->setTimestamp(NOW);
    MacBsr* bsr = new MacBsr();
    bsr->setTimestamp(simTime().dbl());
    bsr->setSize(size);
    macPkt->pushCe(bsr);
    bsrTriggered_ = false;
    EV << "LteMacUeRealisticD2D::makeBsr() - BSR with size " << size << "created" << endl;
    return macPkt;
}

void LteMacUeRealisticD2D::macPduMake()
{
    EV << "LteMacUeRealisticD2D::macPduMake1" << endl;
    int64 size = 0;

    macPduList_.clear();

    bool bsrAlreadyMade = false;
    // UE is in D2D-mode but it received an UL grant (for BSR)
    if ((bsrTriggered_ || bsrD2DMulticastTriggered_) && schedulingGrant_->getDirection() == UL && scheduleList_->empty())
    {
        // Compute BSR size taking into account only DM flows
        int sizeBsr = 0;
        LteMacBufferMap::const_iterator itbsr;
        for (itbsr = macBuffers_.begin(); itbsr != macBuffers_.end(); itbsr++)
        {
            MacCid cid = itbsr->first;
            Direction connDir = (Direction)connDesc_[cid].getDirection();

            // if the bsr was triggered by D2D (D2D_MULTI), only account for D2D (D2D_MULTI) connections
            if (bsrTriggered_ && connDir != D2D)
                continue;
            if (bsrD2DMulticastTriggered_ && connDir != D2D_MULTI)
                continue;

            sizeBsr += itbsr->second->getQueueOccupancy();

            // take into account the RLC header size
            if (sizeBsr > 0)
            {
                if (connDesc_[cid].getRlcType() == UM)
                    sizeBsr += RLC_HEADER_UM;
                else if (connDesc_[cid].getRlcType() == AM)
                    sizeBsr += RLC_HEADER_AM;
            }
        }

        if (sizeBsr > 0)
        {
            // Call the appropriate function for make a BSR for a D2D communication
            LteMacPdu* macPktBsr = makeBsr(sizeBsr);
            UserControlInfo* info = check_and_cast<UserControlInfo*>(macPktBsr->getControlInfo());
            if (bsrD2DMulticastTriggered_)
            {
                info->setLcid(D2D_MULTI_SHORT_BSR);
                bsrD2DMulticastTriggered_ = false;
            }
            else
                info->setLcid(D2D_SHORT_BSR);

            // Add the created BSR to the PDU List
            if( macPktBsr != NULL )
            {
               macPduList_[ std::pair<MacNodeId, Codeword>( getMacCellId(), 0) ] = macPktBsr;
               bsrAlreadyMade = true;
               EV << "LteMacUeRealisticD2D::macPduMake - BSR D2D created with size " << sizeBsr << "created" << endl;
            }
        }
        else
        {
            bsrD2DMulticastTriggered_ = false;
            bsrTriggered_ = false;
        }
    }

//    EV << "LteMacUeRealisticD2D::macPduMake2" << endl;
    if(!bsrAlreadyMade)
    {
        EV << "LteMacUeRealisticD2D::macPduMake3" << endl;
        // In a D2D communication if BSR was created above this part isn't executed
        // Build a MAC PDU for each scheduled user on each codeword
        LteMacScheduleList::const_iterator it;
        for (it = scheduleList_->begin(); it != scheduleList_->end(); it++)
        {
            EV << "LteMacUeRealisticD2D::macPduMake4" << endl;
            LteMacPdu* macPkt;
            cPacket* pkt;

            MacCid destCid = it->first.first;
            Codeword cw = it->first.second;

            EV << "destCid: " << destCid << endl;

            // get the direction (UL/D2D/D2D_MULTI) and the corresponding destination ID
            FlowControlInfo* lteInfo = &(connDesc_.at(destCid));
            MacNodeId destId = lteInfo->getDestId();
            Direction dir = (Direction)lteInfo->getDirection();

            std::pair<MacNodeId, Codeword> pktId = std::pair<MacNodeId, Codeword>(destId, cw);
            unsigned int sduPerCid = it->second;

            MacPduList::iterator pit = macPduList_.find(pktId);

            if (sduPerCid == 0 && !bsrTriggered_ && !bsrD2DMulticastTriggered_)
            {
                continue;
            }

            // No packets for this user on this codeword
            if (pit == macPduList_.end())
            {
                EV << "LteMacUeRealisticD2D::macPduMake5" << endl;
                // Always goes here because of the macPduList_.clear() at the beginning
                // Build the Control Element of the MAC PDU
                UserControlInfo* uinfo = new UserControlInfo();
                uinfo->setSourceId(getMacNodeId());
                uinfo->setDestId(destId);
                uinfo->setLcid(MacCidToLcid(destCid));
                uinfo->setDirection(dir);
                uinfo->setLcid(MacCidToLcid(SHORT_BSR));
                if (usePreconfiguredTxParams_)
                    uinfo->setUserTxParams(preconfiguredTxParams_->dup());
                else
                    uinfo->setUserTxParams(schedulingGrant_->getUserTxParams()->dup());
                // Create a PDU
                macPkt = new LteMacPdu("LteMacPdu");
                macPkt->setHeaderLength(MAC_HEADER);
                macPkt->setControlInfo(uinfo);
                macPkt->setTimestamp(NOW);
                macPduList_[pktId] = macPkt;
            }
            else
            {
                // Never goes here because of the macPduList_.clear() at the beginning
                macPkt = pit->second;
            }

            while (sduPerCid > 0)
            {
                EV << "LteMacUeRealisticD2D::macPduMake6" << endl;
                EV << "sduPerCid: " << sduPerCid << endl;
                // Add SDU to PDU
                // Find Mac Pkt
                if (mbuf_.find(destCid) == mbuf_.end())
                    throw cRuntimeError("Unable to find mac buffer for cid %d", destCid);

                if (mbuf_[destCid]->empty())
                    throw cRuntimeError("Empty buffer for cid %d, while expected SDUs were %d", destCid, sduPerCid);

                pkt = mbuf_[destCid]->popFront();

                // multicast support
                // this trick gets the group ID from the MAC SDU and sets it in the MAC PDU
                int32 groupId = check_and_cast<LteControlInfo*>(pkt->getControlInfo())->getMulticastGroupId();
                if (groupId >= 0) // for unicast, group id is -1
                    check_and_cast<LteControlInfo*>(macPkt->getControlInfo())->setMulticastGroupId(groupId);

                drop(pkt);

                macPkt->pushSdu(pkt);
                sduPerCid--;
            }

            // consider virtual buffers to compute BSR size
            size += macBuffers_[destCid]->getQueueOccupancy();

            if (size > 0)
            {
                // take into account the RLC header size
                if (connDesc_[destCid].getRlcType() == UM)
                    size += RLC_HEADER_UM;
                else if (connDesc_[destCid].getRlcType() == AM)
                    size += RLC_HEADER_AM;
            }
        }
    }

    // Put MAC PDUs in H-ARQ buffers
    MacPduList::iterator pit;
    for (pit = macPduList_.begin(); pit != macPduList_.end(); pit++)
    {
        MacNodeId destId = pit->first.first;
        Codeword cw = pit->first.second;
        // Check if the HarqTx buffer already exists for the destId
        // Get a reference for the destId TXBuffer
        LteHarqBufferTx* txBuf;
        HarqTxBuffers::iterator hit = harqTxBuffers_.find(destId);
        if ( hit != harqTxBuffers_.end() )
        {
            // The tx buffer already exists
            txBuf = hit->second;
        }
        else
        {
            // The tx buffer does not exist yet for this mac node id, create one
            LteHarqBufferTx* hb;
            // FIXME: hb is never deleted
            UserControlInfo* info = check_and_cast<UserControlInfo*>(pit->second->getControlInfo());
            if (info->getDirection() == UL)
                hb = new LteHarqBufferTx((unsigned int) ENB_TX_HARQ_PROCESSES, this, (LteMacBase*) getMacByMacNodeId(destId));
            else // D2D or D2D_MULTI
                hb = new LteHarqBufferTxD2D((unsigned int) ENB_TX_HARQ_PROCESSES, this, (LteMacBase*) getMacByMacNodeId(destId));
            harqTxBuffers_[destId] = hb;
            txBuf = hb;
        }

        // search for an empty unit within current harq process
        UnitList txList = txBuf->getEmptyUnits(currentHarq_);
        EV << "LteMacUeRealisticD2D::macPduMake - [Used Acid=" << (unsigned int)txList.first << "] , [curr=" << (unsigned int)currentHarq_ << "]" << endl;

        //Get a reference of the LteMacPdu from pit pointer (extract Pdu from the MAP)
        LteMacPdu* macPkt = pit->second;

        /* BSR related operations

        // according to the TS 36.321 v8.7.0, when there are uplink resources assigned to the UE, a BSR
        // has to be send even if there is no data in the user's queues. In few words, a BSR is always
        // triggered and has to be send when there are enough resources

        // TODO implement differentiated BSR attach
        //
        //            // if there's enough space for a LONG BSR, send it
        //            if( (availableBytes >= LONG_BSR_SIZE) ) {
        //                // Create a PDU if data were not scheduled
        //                if (pdu==0)
        //                    pdu = new LteMacPdu();
        //
        //                if(LteDebug::trace("LteSchedulerUeUl::schedule") || LteDebug::trace("LteSchedulerUeUl::schedule@bsrTracing"))
        //                    fprintf(stderr, "%.9f LteSchedulerUeUl::schedule - Node %d, sending a Long BSR...\n",NOW,nodeId);
        //
        //                // create a full BSR
        //                pdu->ctrlPush(fullBufferStatusReport());
        //
        //                // do not reset BSR flag
        //                mac_->bsrTriggered() = true;
        //
        //                availableBytes -= LONG_BSR_SIZE;
        //
        //            }
        //
        //            // if there's space only for a SHORT BSR and there are scheduled flows, send it
        //            else if( (mac_->bsrTriggered() == true) && (availableBytes >= SHORT_BSR_SIZE) && (highestBackloggedFlow != -1) ) {
        //
        //                // Create a PDU if data were not scheduled
        //                if (pdu==0)
        //                    pdu = new LteMacPdu();
        //
        //                if(LteDebug::trace("LteSchedulerUeUl::schedule") || LteDebug::trace("LteSchedulerUeUl::schedule@bsrTracing"))
        //                    fprintf(stderr, "%.9f LteSchedulerUeUl::schedule - Node %d, sending a Short/Truncated BSR...\n",NOW,nodeId);
        //
        //                // create a short BSR
        //                pdu->ctrlPush(shortBufferStatusReport(highestBackloggedFlow));
        //
        //                // do not reset BSR flag
        //                mac_->bsrTriggered() = true;
        //
        //                availableBytes -= SHORT_BSR_SIZE;
        //
        //            }
        //            // if there's a BSR triggered but there's not enough space, collect the appropriate statistic
        //            else if(availableBytes < SHORT_BSR_SIZE && availableBytes < LONG_BSR_SIZE) {
        //                Stat::put(LTE_BSR_SUPPRESSED_NODE,nodeId,1.0);
        //                Stat::put(LTE_BSR_SUPPRESSED_CELL,mac_->cellId(),1.0);
        //            }
        //            Stat::put (LTE_GRANT_WASTED_BYTES_UL, nodeId, availableBytes);
        //        }
        //
        //        // 4) PDU creation
        //
        //        if (pdu!=0) {
        //
        //            pdu->cellId() = mac_->cellId();
        //            pdu->nodeId() = nodeId;
        //            pdu->direction() = mac::UL;
        //            pdu->error() = false;
        //
        //            if(LteDebug::trace("LteSchedulerUeUl::schedule"))
        //                fprintf(stderr, "%.9f LteSchedulerUeUl::schedule - Node %d, creating uplink PDU.\n", NOW, nodeId);
        //
        //        } */

        // Attach BSR to PDU if RAC is won and wasn't already made
        if ((bsrTriggered_ || bsrD2DMulticastTriggered_) && !bsrAlreadyMade )
        {
            MacBsr* bsr = new MacBsr();
            bsr->setTimestamp(simTime().dbl());
            bsr->setSize(size);
            macPkt->pushCe(bsr);
            bsrTriggered_ = false;
            bsrD2DMulticastTriggered_ = false;
            EV << "LteMacUeRealisticD2D::macPduMake - BSR created with size " << size << endl;
        }

        EV << "LteMacUeRealisticD2D: pduMaker created PDU: " << macPkt->info() << endl;

        // TODO: harq test
        // pdu transmission here (if any)
        // txAcid has HARQ_NONE for non-fillable codeword, acid otherwise
        if (txList.second.empty())
        {
            EV << "LteMacUeRealisticD2D() : no available process for this MAC pdu in TxHarqBuffer" << endl;
            delete macPkt;
        }
        else
        {
            //Insert PDU in the Harq Tx Buffer
            //txList.first is the acid
            txBuf->insertPdu(txList.first,cw, macPkt);
        }
    }
}

void LteMacUeRealisticD2D::handleMessage(cMessage* msg)
{
    if (msg->isSelfMessage())
    {
        LteMacUeRealistic::handleMessage(msg);
        return;
    }

    cPacket* pkt = check_and_cast<cPacket *>(msg);
    cGate* incoming = pkt->getArrivalGate();

    if (incoming == down_[IN])
    {
        UserControlInfo *userInfo = check_and_cast<UserControlInfo *>(pkt->getControlInfo());
        if (userInfo->getFrameType() == D2DMODESWITCHPKT)
        {
            EV << "LteMacUeRealisticD2D::handleMessage - Received packet " << pkt->getName() <<
            " from port " << pkt->getArrivalGate()->getName() << endl;

            // message from PHY_to_MAC gate (from lower layer)
            emit(receivedPacketFromLowerLayer, pkt);

            // call handler
            macHandleD2DModeSwitch(pkt);

            return;
        }
    }

    LteMacUeRealistic::handleMessage(msg);
}

void
LteMacUeRealisticD2D::macHandleGrant(cPacket* pkt)
{
    EV << NOW << " LteMacUeRealisticD2D::macHandleGrant - UE [" << nodeId_ << "] - Grant received " << endl;

    // delete old grant
    LteSchedulingGrant* grant = check_and_cast<LteSchedulingGrant*>(pkt);

    //Codeword cw = grant->getCodeword();

    if (schedulingGrant_!=NULL)
    {
        delete schedulingGrant_;
        schedulingGrant_ = NULL;
    }

    // store received grant
    schedulingGrant_=grant;

    if (grant->getPeriodic())
    {
        periodCounter_=grant->getPeriod();
        expirationCounter_=grant->getExpiration();
    }

    EV << NOW << "Node " << nodeId_ << " received grant of blocks " << grant->getTotalGrantedBlocks()
       << ", bytes " << grant->getGrantedCwBytes(0) <<" Direction: "<<dirToA(grant->getDirection()) << endl;

    // clearing pending RAC requests
    racRequested_=false;
    racD2DMulticastRequested_=false;
}

void LteMacUeRealisticD2D::checkRAC()
{
    EV << NOW << " LteMacUeRealisticD2D::checkRAC , Ue  " << nodeId_ << ", racTimer : " << racBackoffTimer_ << " maxRacTryOuts : " << maxRacTryouts_
       << ", raRespTimer:" << raRespTimer_ << endl;

    if (racBackoffTimer_>0)
    {
        racBackoffTimer_--;
        return;
    }

    if(raRespTimer_>0)
    {
        // decrease RAC response timer
        raRespTimer_--;
        EV << NOW << " LteMacUeRealisticD2D::checkRAC - waiting for previous RAC requests to complete (timer=" << raRespTimer_ << ")" << endl;
        return;
    }

    // Avoids double requests whithin same TTI window
    if (racRequested_)
    {
        EV << NOW << " LteMacUeRealisticD2D::checkRAC - double RAC request" << endl;
        racRequested_=false;
        return;
    }
    if (racD2DMulticastRequested_)
    {
        EV << NOW << " LteMacUeRealisticD2D::checkRAC - double RAC request" << endl;
        racD2DMulticastRequested_=false;
        return;
    }

    bool trigger=false;
    bool triggerD2DMulticast=false;

    LteMacBufferMap::const_iterator it;

    for (it = macBuffers_.begin(); it!=macBuffers_.end();++it)
    {
        if (!(it->second->isEmpty()))
        {
            MacCid cid = it->first;
            if (connDesc_.at(cid).getDirection() == D2D_MULTI)
                triggerD2DMulticast = true;
            else
                trigger = true;
            break;
        }
    }

    if (!trigger && !triggerD2DMulticast)
        EV << NOW << "Ue " << nodeId_ << ",RAC aborted, no data in queues " << endl;

    if ((racRequested_=trigger) || (racD2DMulticastRequested_=triggerD2DMulticast))
    {
        LteRac* racReq = new LteRac("RacRequest");
        UserControlInfo* uinfo = new UserControlInfo();
        uinfo->setSourceId(nodeId_);
        uinfo->setDestId(getMacCellId());
        uinfo->setDirection(UL);
        uinfo->setFrameType(RACPKT);
        racReq->setControlInfo(uinfo);

        std::string networkType = this->getParentModule()->getParentModule()->getParentModule()->par("networkType");
        if(networkType == "CAIN"){
            uinfo->setCAINCoord(binder_->getUeCoord(getMacNodeId()));
            uinfo->setEnbCoord(binder_->getEnbCoord(getMacNodeId()));
            uinfo->setCAINEnable(true);
            std::string str = binder_->checkCAINType(nodeId_);
            EV << "Binder string: " << str << endl;
            std::vector<std::string> msgType = getMessageType(str,'|');
            EV << "Message type: " << msgType[0] << endl;
            EV << "Node id: " << nodeId_ << endl;
            MacNodeId enbId = stoi(msgType[2]);
            if(msgType[0] == "NOTIFY"){
                MacNodeId relayId = stoi(msgType[1]);
                EV << "The relay id is: " << relayId << endl;
                uinfo->setCAINDirection(NOTIFY);
                uinfo->setCAINOption("");
                uinfo->setDestId(relayId);
                std::ostringstream stream;
                stream << enbId;
                uinfo->appendOption(stream.str());
                stream.str("");
                stream.clear();
//                uinfo->setDirection(UL);
                cainMessageSent++;
                emit(cainMessageSentSignal,cainMessageSent);
            }else if(msgType[0] == "HOP_NTF"){
                msgType = getMessageType(msgType[1],';');
                MacNodeId relayId = stoi(msgType[0]);
                MacNodeId hopId = stoi(msgType[1]);
                EV << "Hop notify message, relay->" << relayId << " hop->" << hopId << endl;
                uinfo->setCAINDirection(HOP_NTF);
                uinfo->setCAINOption("");
                std::ostringstream stream;
                stream << relayId << "/" << hopId << "/" << enbId;
                uinfo->appendOption(stream.str());
                stream.str("");
                stream.clear();
                uinfo->setDestId(hopId);
                uinfo->setDirection(UL);
                cainHopMessageSent++;
                emit(cainHopMesasgeSentSignal,cainHopMessageSent);
            }else if(msgType[0] == "DIR"){
                uinfo->setCAINDirection(DIR);
                uinfo->setCAINOption("");
            }
        }else if(networkType == "Social"){
            uinfo->setCAINCoord(binder_->getUeCoord(nodeId_));
            uinfo->setEnbCoord(binder_->getEnbCoord(nodeId_));
            uinfo->setCAINEnable(true);
                MacNodeId destId = binder_->checkSocialId(nodeId_);
                if(destId != nodeId_){
                    binder_->updateSocialMap(nodeId_,destId,2);
                    uinfo->setDestId(destId);
                    uinfo->setCAINDirection(SOC_NTF);
                    uinfo->setCAINOption("");
                }else{
//                    uinfo->setDestId(destId);
                    uinfo->setCAINDirection(DIR);
                    uinfo->setCAINOption("");
                }
        }else if(networkType == "4G"){
            uinfo->setCAINCoord(binder_->getUeCoord(getMacNodeId()));
            uinfo->setEnbCoord(binder_->getEnbCoord(getMacNodeId()));
            uinfo->setCAINEnable(true);
            bool send = binder_->checkLteMsg(nodeId_);
            if(send){
                binder_->setRacSevedDev(nodeId_-1025,true);
                uinfo->setCAINDirection(LTE);
                uinfo->setCAINOption("");
            }else{
                uinfo->setCAINDirection(DIR);
                uinfo->setCAINOption("");
            }
        }

        sendLowerPackets(racReq);

        EV << NOW << " Ue  " << nodeId_ << " cell " << cellId_ << " ,RAC request sent to PHY " << endl;

        // wait at least  "raRespWinStart_" TTIs before another RAC request
        raRespTimer_ = raRespWinStart_;
    }
}

void LteMacUeRealisticD2D::macHandleRac(cPacket* pkt)
{
    LteRac* racPkt = check_and_cast<LteRac*>(pkt);

    UserControlInfo* uinfo = check_and_cast<UserControlInfo*>(pkt->getControlInfo());

    ///////////


    EV << "Getting control info from node " << uinfo->getSourceId() << " to node " << uinfo->getDestId()<< endl;
    if(uinfo->getCAINEnable()){
        EV << "CAIN message arriving" << endl;

        if(uinfo->getDestId()==nodeId_){
            EV << "This message is destined to me" << endl;
            handleCainMsg(pkt);
        }

    }else{
        ///////////
    if (racPkt->getSuccess())
    {
        EV << "LteMacUeRealisticD2D::macHandleRac - Ue " << nodeId_ << " won RAC" << endl;
        // is RAC is won, BSR has to be sent
        if (racD2DMulticastRequested_)
            bsrD2DMulticastTriggered_=true;
        else
            bsrTriggered_ = true;

        // reset RAC counter
        currentRacTry_=0;
        //reset RAC backoff timer
        racBackoffTimer_=0;
    }
    else
    {
        // RAC has failed
        if (++currentRacTry_ >= maxRacTryouts_)
        {
            EV << NOW << " Ue " << nodeId_ << ", RAC reached max attempts : " << currentRacTry_ << endl;
            // no more RAC allowed
            //! TODO flush all buffers here
            //reset RAC counter
            currentRacTry_=0;
            //reset RAC backoff timer
            racBackoffTimer_=0;
        }
        else
        {
            // recompute backoff timer
            racBackoffTimer_= uniform(minRacBackoff_,maxRacBackoff_);
            EV << NOW << " Ue " << nodeId_ << " RAC attempt failed, backoff extracted : " << racBackoffTimer_ << endl;
        }
    }
    delete racPkt;
    }
}


void LteMacUeRealisticD2D::handleCainMsg(cPacket* pkt){

    EV << "LteMacUeRealisticD2D::handleCainMsg" << endl;
    LteRac* racPkt = check_and_cast<LteRac*> (pkt);
    UserControlInfo* uinfo = check_and_cast<UserControlInfo*>(
            racPkt->getControlInfo());

    std::string cainOpt = uinfo->getCAINOptions();

    // TODO all RACs are marked are successful
    racPkt->setSuccess(true);


    EV << "CAIN message from id: " << uinfo->getSourceId() << ", to id: " << uinfo->getDestId()
            << " with option: " << cainOpt << endl;

    switch(uinfo->getCAINDirection()){
        case NOTIFY:
        {
            binder_->increaseRelay(uinfo->getDestId());
            binder_->printAllQtdRelay();
            EV << "Receiving a NOTIFY message to node "<< uinfo->getDestId() << endl;

            MacNodeId enbId = binder_->getEnbToUe(uinfo->getSourceId());

//            std::vector<MacNodeId> node = getNode(cainOpt);
//            EV << "The nodes that need a relay are: " << endl;
//            EV << "Node list size: " << node.size() << endl;

            MacNodeId destId = stoi(cainOpt);
            uinfo->setCAINOption("");
            std::ostringstream stream;
            stream << uinfo->getSourceId();
            uinfo->appendOption(stream.str());
            uinfo->setSourceId(uinfo->getDestId());
            uinfo->setDestId(destId);
            uinfo->setCAINDirection(FWD);
            uinfo->setDirection(UL);
            EV << "Source: " << uinfo->getSourceId() << endl;
            EV << "Dest: " << uinfo->getDestId() << endl;
            EV << "Options: " << uinfo->getCAINOptions() << endl;
            sendLowerPackets(racPkt);
            break;
        }
        case REP:
        {
            EV << "Receiving a REP message to node "<< uinfo->getDestId() << endl;

            binder_->decreaseRelay(uinfo->getDestId());
            binder_->printAllQtdRelay();
            std::string opt = uinfo->getCAINOptions();
            std::vector<std::string> node;
            std::string token;
            std::istringstream tokenStream(opt);
            while (std::getline(tokenStream, token, '|'))
            {
                node.push_back(token);
            }
            MacNodeId oldSource = uinfo->getSourceId();
            MacNodeId oldDest = uinfo->getDestId();
            if(node[0] == "OK")
            {
                EV << "Ok to relay message" << endl;
                uinfo->setSourceId(oldDest);
                uinfo->setDestId(oldSource);
                uinfo->setCAINDirection(ANSW);
                uinfo->setCAINEnable(true);
                EV << "Source: " << uinfo->getSourceId() << endl;
                EV << "Dest: " << uinfo->getDestId() << endl;
                EV << "Options: " << uinfo->getCAINOptions() << endl;
                sendLowerPackets(pkt);
            }
            else
            {
                EV << "Not ok to relay message" << endl;
                dropedCainMessage++;
                emit(dropedCainMessageSignal,dropedCainMessage);
                delete pkt;
//                return;
            }
//            endSimulation();

            break;
        }
        case HOP_NTF:
        {
            EV << "Receiving a HOP_NTF message from ID: " << uinfo->getSourceId() << " to destination: " << uinfo->getDestId() << endl;
            std::vector<MacNodeId> node = getHopNodes(cainOpt);
            EV << "The relay node id is: " << node[0] << " and the Hop ID is: " << node[1] << endl;
            uinfo->setDestId(node[0]);
            uinfo->setCAINdest(uinfo->getSourceId());
            std::ostringstream stream;
            stream << nodeId_ << "/" << uinfo->getSourceId() << "/" << node[2];
            uinfo->setCAINOption(stream.str());
            stream.str("");
            stream.clear();
            uinfo->setSourceId(nodeId_);
            uinfo->setCAINDirection(HOP_REL);
            uinfo->setCAINEnable(true);
            EV << "Source: " << uinfo->getSourceId() << endl;
            EV << "Dest: " << uinfo->getDestId() << endl;
            EV << "Options: " << uinfo->getCAINOptions() << endl;
            sendLowerPackets(pkt);
            break;
        }
        case HOP_REL:
        {
            binder_->increaseRelay(nodeId_);
            binder_->printAllQtdRelay();
            EV << "Receiving a HOP_REL message" << endl;
            cainOpt = uinfo->getCAINOptions();
            std::vector<MacNodeId> node = getHopNodes(cainOpt);
            EV << "Hop id: " << node[0] << " ue: " << node[1] <<  endl;

            uinfo->setSourceId(uinfo->getDestId());
            uinfo->setDestId(node[2]);
            uinfo->setCAINDirection(HOP_FWD);
            uinfo->setDirection(UL);
            std::ostringstream stream;
            stream << node[0] << "/" << node[1];
            uinfo->setCAINOption(stream.str());
            stream.str("");
            stream.clear();
            uinfo->setCAINEnable(true);
            EV << "Source: " << uinfo->getSourceId() << endl;
            EV << "Dest: " << uinfo->getDestId() << endl;
            EV << "Options: " << uinfo->getCAINOptions() << endl;
            sendLowerPackets(pkt);
            break;
        }
        case HOP_REP:
        {
            /*
             * Message from Hop node to relay
             *
             * Begin:
             * Source: Hop node
             * Destination: relay
             *
             */
            EV << "Receiving a HOP_REP message" << endl;

            binder_->decreaseRelay(uinfo->getDestId());
            binder_->printAllQtdRelay();
            std::string opt = uinfo->getCAINOptions();
            std::vector<std::string> node;
            std::string token;
            std::istringstream tokenStream(opt);
            while (std::getline(tokenStream, token, '|'))
            {
                node.push_back(token);
            }

            MacNodeId oldSource = uinfo->getSourceId();
            MacNodeId oldDest = uinfo->getDestId();
            if(node[0] == "OK")
            {
                EV << "Ok to relay message" << endl;
                uinfo->setSourceId(oldDest);
                uinfo->setDestId(oldSource);
                uinfo->setCAINDirection(HOP_ANSW);
                uinfo->setCAINEnable(true);
                EV << "Source: " << uinfo->getSourceId() << endl;
                EV << "Dest: " << uinfo->getDestId() << endl;
                EV << "Options: " << uinfo->getCAINOptions() << endl;
                sendLowerPackets(pkt);
            }
            else
            {
                EV << "Not ok to relay message" << endl;
                dropedHopMessage++;
                emit(dropedHopMessageSignal,dropedHopMessage);
                delete pkt;
                return;
            }
            break;
        }
        case SOC_NTF:
        {
            MacNodeId enbId = binder_->getEnbToUe(uinfo->getDestId());

            EV << "Social notify message arrived from node " << uinfo->getSourceId() << " to"
                    " node " << uinfo->getDestId() << endl;

            binder_->updateSocialMap(uinfo->getDestId(),uinfo->getSourceId(),2);
            uinfo->setCAINOption("");
            uinfo->setSourceId(uinfo->getDestId());
            uinfo->setDestId(enbId);
            uinfo->setCAINDirection(SOC_FWD);
            uinfo->setDirection(UL);
            sendLowerPackets(racPkt);
            break;
        }
        case SOC_REP:
        {
            /*
             * Message from Hop node to relay
             *
             * Begin:
             * Source: Hop node
             * Destination: relay
             *
             */
            EV << "Receiving a SOC_REP message from " << uinfo->getSourceId() <<
                    " to " <<uinfo->getDestId()<< endl;


            binder_->decreaseRelay(uinfo->getDestId());
            std::string opt = uinfo->getCAINOptions();
            std::vector<std::string> node;
            std::string token;
            std::istringstream tokenStream(opt);
            while (std::getline(tokenStream, token, '|'))
            {
                node.push_back(token);
            }
            if(node[0] == "OK")
            {
                EV << "Ok to relay message" << endl;
                uinfo->setSourceId(uinfo->getDestId());
                MacNodeId enb = binder_->getEnbToUe(uinfo->getDestId());
                EV<< "enb: " << enb << endl;
                uinfo->setDestId(enb);
                uinfo->setCAINDirection(SOC_ANSW);
                uinfo->setCAINEnable(true);
                EV << "Source: " << uinfo->getSourceId() << endl;
                EV << "Dest: " << uinfo->getDestId() << endl;
                EV << "Options: " << uinfo->getCAINOptions() << endl;
                sendLowerPackets(pkt);
            }
            else
            {
                EV << "Not ok to relay message" << endl;
                dropedHopMessage++;
                emit(dropedHopMessageSignal,dropedHopMessage);
                delete pkt;
                return;
            }
            break;
        }
        default:
            EV << "Unknow CAIN message" << endl;
            break;
    }
}

bool LteMacUeRealisticD2D::checkRepList(MacNodeId nodeId){
    /*
     * find UeInfo for the UE
     * */
    std::vector<UeInfo*>* ueVect = binder_->getUeList();
    for(unsigned int i=0; i < ueVect->size(); i++){
        if(this->getMacNodeId() == ueVect->at(i)->id){
            /*
             * get the repList for this UE
             * */
            rep_list* repList = ueVect->operator [](i)->repList;
            for(unsigned int j=0; j < repList->size(); j++){
                if(repList->at(j) == nodeId)
                    return true;
            }
            return false;
        }
    }

}

void LteMacUeRealisticD2D::removeNodeRepList(MacNodeId nodeId){
    /*
     * find UeInfo for the UE
     * */
    std::vector<UeInfo*>* ueVect = binder_->getUeList();
    for(unsigned int i=0; i < ueVect->size(); i++){
        if(this->getMacNodeId() == ueVect->at(i)->id){
            /*
             * get the repList for this UE
             * */
            rep_list* repList = ueVect->operator [](i)->repList;
            std::vector<MacNodeId>::iterator it = std::find(repList->begin(), repList->end(), nodeId);
            if(it != repList->end()){
                EV << "Node found on repList, removing it" << endl;
                repList->erase(it);
                return;
            }else{
                EV << "Node not found on repList, can not remove it" << endl;
                return;
            }
        }
    }
}

bool LteMacUeRealisticD2D::updateRelayList(MacNodeId relayId){
    /*
     * find EnBInfo for the eNB
     * */

    std::vector<EnbInfo*>* enbVect = binder_->getEnbList();
    for(unsigned int i=0;i< enbVect->size();i++){
        if(1 == enbVect->at(i)->id){

            EV << "Got eNB info" << endl;
            /*
             * get the better metric map
             * */
            sinrMapB* BsMap = enbVect->operator [](i)->Bmap;
            std::map<MacNodeId,double>::iterator it = BsMap->begin();

            /*
             * find UeInfo for the UE
             * */
            std::vector<UeInfo*>* ueVect = binder_->getUeList();
            for(unsigned int j=0; j < ueVect->size(); j++){
                if(this->getMacNodeId() == ueVect->at(j)->id){

                    EV << "Got UE info" << endl;
                    /*
                     * get the relayList for this UE
                     * */
                    relayList* rList = ueVect->operator [](j)->rList;
                    /*
                     * If this relay is already at the list,
                     * erase it to update the value
                     * */
                    if(rList->count(relayId)==1)
                        rList->erase(relayId);
                    for(it = BsMap->begin(); it != BsMap->end();it++){
                        EV << "searching for node " << relayId << endl;
                        EV << "Iterator: "<< it->first << endl;
                        /*
                         * finding the relay at the metric map
                         * */
                        if(it->first == relayId){
                            rList->operator [](relayId)=it->second;
                            return true;
                        }
                    }
                    return false;
                }
            }

        }
    }
    return false;
}

void LteMacUeRealisticD2D::printRelayList(MacNodeId nodeId){
    std::vector<UeInfo*>* ueVect = binder_->getUeList();
    for(unsigned int j=0; j < ueVect->size(); j++){
        if(nodeId == ueVect->at(j)->id){
            /*
             * get the relayList for this UE
             * */
            relayList* rList = ueVect->operator [](j)->rList;
            std::map<MacNodeId,double>::iterator it;
            for(it = rList->begin(); it != rList->end(); it++)
                EV<< "Relay: " << it->first << " metric value: " << it->second << endl;
        }
    }
}

MacNodeId LteMacUeRealisticD2D::getRelay(std::vector<std::string> relayVect){
    std::vector<std::string> relays;
    MacNodeId relay;
    int metric;

    for(int i = 0; i<relayVect.size(); i++){
        std::string token;
        std::istringstream tokenStream(relayVect[i]);
        while (std::getline(tokenStream, token, '/'))
        {
            relays.push_back(token);
        }
        //first iteration -> better relay so far
        if (i==0){
            relay = stoi(relays[0]);
            metric = stoi(relays[1]);
        }else{
            if(metric > stoi(relays[1])){
                relay = stoi(relays[0]);
                metric = stoi(relays[1]);
            }
        }
    }
    return relay;
}

std::vector<MacNodeId> LteMacUeRealisticD2D::getNode(std::string nodeSinr){

    /*
    * nodeSinr division:
    * -----------------------------------------
    * |nodeId/SINR;nodeId/SINR;nodeId/SINR;...|
    * -----------------------------------------
    * */

    int i;
    /*
     * nodes division:
     * -----------------------------------------
     * |nodeId/SINR|nodeId/SINR|nodeId/SINR|...|
     * -----------------------------------------
     * */
    std::vector<std::string> nodes;
    std::vector<MacNodeId> node;
    int metric;
    std::string token;
    std::istringstream tokenStream(nodeSinr);
    while (std::getline(tokenStream, token, ';'))
    {
        nodes.push_back(token);
    }
    /*
     * dest division:
     * -----------------------------------------
     * |nodeId|SINR|nodeId|SINR|nodeId|SINR|...|
     * -----------------------------------------
     * */
    std::vector<std::string> dest;
    for(i = 0; i<nodes.size(); i++){
        std::istringstream tokenStream(nodes[i]);
        while (std::getline(tokenStream, token, '/'))
        {
            dest.push_back(token);
        }
    }
    /*
     * will check node and metric, therefore i+=2
     * */
    for(i=0;i<dest.size();i+=2){
        node.push_back(stoi(dest[i]));
        metric=stoi(dest[i+1]);
    }
    return node;
}

std::vector<MacNodeId> LteMacUeRealisticD2D::getHopNodes(std::string nodeSinr){
    /*
        * nodeSinr division:
        * --------
        * |Hop/UE|
        * --------
        * */

        std::vector<MacNodeId> node;
        std::string token;
        std::istringstream tokenStream(nodeSinr);
        while (std::getline(tokenStream, token, '/'))
        {
            node.push_back(stoi(token));
        }
        return node;

}

void LteMacUeRealisticD2D::handleSelfMessage()
{
    EV << "----- UE MAIN LOOP -----" << endl;

    // extract pdus from all harqrxbuffers and pass them to unmaker
    HarqRxBuffers::iterator hit = harqRxBuffers_.begin();
    HarqRxBuffers::iterator het = harqRxBuffers_.end();
    LteMacPdu *pdu = NULL;
    std::list<LteMacPdu*> pduList;

    for (; hit != het; ++hit)
    {
        pduList=hit->second->extractCorrectPdus();
        while (! pduList.empty())
        {
            pdu=pduList.front();
            pduList.pop_front();
            macPduUnmake(pdu);
        }
    }

    // For each D2D communication, the status of the HARQRxBuffer must be known to the eNB
    // For each HARQ-RX Buffer corresponding to a D2D communication, store "mirror" buffer at the eNB
    HarqRxBuffers::iterator buffIt = harqRxBuffers_.begin();
    for (; buffIt != harqRxBuffers_.end(); ++buffIt)
    {
        MacNodeId senderId = buffIt->first;
        LteHarqBufferRx* buff = buffIt->second;

        // skip the H-ARQ buffer corresponding to DL transmissions
        if (senderId == cellId_)
            continue;

        // TODO skip the H-ARQ buffers corresponding to D2D_MULTI transmissions

        //The constructor "extracts" all the useful information from the harqRxBuffer and put them in a LteHarqBufferRxD2DMirror object
        //That object resides in enB. Because this operation is done after the enb main loop the enb is 1 TTI backward respect to the Receiver
        //This means that enb will check the buffer for retransmission 3 TTI before
        LteHarqBufferRxD2DMirror* mirbuff = new LteHarqBufferRxD2DMirror(buff, (unsigned char)this->par("maxHarqRtx"), senderId);
        enb_->storeRxHarqBufferMirror(nodeId_, mirbuff);
    }

    EV << NOW << "LteMacUeRealisticD2D::handleSelfMessage " << nodeId_ << " - HARQ process " << (unsigned int)currentHarq_ << endl;
    // updating current HARQ process for next TTI

    //unsigned char currentHarq = currentHarq_;

    // no grant available - if user has backlogged data, it will trigger scheduling request
    // no harq counter is updated since no transmission is sent.

    if (schedulingGrant_==NULL)
    {
        EV << NOW << " LteMacUeRealisticD2D::handleSelfMessage " << nodeId_ << " NO configured grant" << endl;

        // if necessary, a RAC request will be sent to obtain a grant
        checkRAC();
        // TODO ensure all operations done  before return ( i.e. move H-ARQ rx purge before this point)
    }
    else if (schedulingGrant_->getPeriodic())
    {
        // Periodic checks
        if(--expirationCounter_ < 0)
        {
            // Periodic grant is expired
            delete schedulingGrant_;
            schedulingGrant_ = NULL;
            // if necessary, a RAC request will be sent to obtain a grant
            checkRAC();
        }
        else if (--periodCounter_>0)
        {
            return;
        }
        else
        {
            // resetting grant period
            periodCounter_=schedulingGrant_->getPeriod();
            // this is periodic grant TTI - continue with frame sending
        }
    }

    bool requestSdu = false;
    if (schedulingGrant_!=NULL) // if a grant is configured
    {
        if(!firstTx)
        {
            EV << "\t currentHarq_ counter initialized " << endl;
            firstTx=true;
            // the eNb will receive the first pdu in 2 TTI, thus initializing acid to 0
//            currentHarq_ = harqRxBuffers_.begin()->second->getProcesses() - 2;
            currentHarq_ = UE_TX_HARQ_PROCESSES - 2;
        }
        EV << "\t " << schedulingGrant_ << endl;

//        //! \TEST  Grant Synchronization check
//        if (!(schedulingGrant_->getPeriodic()))
//        {
//            if ( false /* TODO currentHarq!=grant_->getAcid()*/)
//            {
//                EV << NOW << "FATAL! Ue " << nodeId_ << " Current Process is " << (int)currentHarq << " while Stored grant refers to acid " << /*(int)grant_->getAcid() << */  ". Aborting.   " << endl;
//                abort();
//            }
//        }

        // TODO check if current grant is "NEW TRANSMISSION" or "RETRANSMIT" (periodic grants shall always be "newtx"
//        if ( false/*!grant_->isNewTx() && harqQueue_->rtx(currentHarq) */)
//        {
        //        if ( LteDebug:r:trace("LteMacUeRealisticD2D::newSubFrame") )
        //            fprintf (stderr,"%.9f UE: [%d] Triggering retransmission for acid %d\n",NOW,nodeId_,currentHarq);
        //        // triggering retransmission --- nothing to do here, really!
//        } else {
        // buffer drop should occour here.
//        scheduleList = ueScheduler_->buildSchedList();

        EV << NOW << " LteMacUeRealisticD2D::handleSelfMessage " << nodeId_ << " entered scheduling" << endl;

        bool retx = false;

        HarqTxBuffers::iterator it2;
        LteHarqBufferTx * currHarq;
        for(it2 = harqTxBuffers_.begin(); it2 != harqTxBuffers_.end(); it2++)
        {
            EV << "\t Looking for retx in acid " << (unsigned int)currentHarq_ << endl;
            currHarq = it2->second;

            // check if the current process has unit ready for retx
            bool ready = currHarq->getProcess(currentHarq_)->hasReadyUnits();
            CwList cwListRetx = currHarq->getProcess(currentHarq_)->readyUnitsIds();

            EV << "\t [process=" << (unsigned int)currentHarq_ << "] , [retx=" << ((retx)?"true":"false")
               << "] , [n=" << cwListRetx.size() << "]" << endl;

            // if a retransmission is needed
            if(ready)
            {
                UnitList signal;
                signal.first=currentHarq_;
                signal.second = cwListRetx;
                currHarq->markSelected(signal,schedulingGrant_->getUserTxParams()->getLayers().size());
                retx = true;
            }
        }
        // if no retx is needed, proceed with normal scheduling
        if(!retx)
        {
            scheduleList_ = lcgScheduler_->schedule();
            EV << "LteMacUeRealisticD2D" << endl;
            if ((bsrTriggered_ || bsrD2DMulticastTriggered_) && scheduleList_->empty())
            {
                // no connection scheduled, but we can use this grant to send a BSR to the eNB
                macPduMake();
            }
            else
            {
                requestSdu = macSduRequest(); // return a bool
            }

        }

        // Message that triggers flushing of Tx H-ARQ buffers for all users
        // This way, flushing is performed after the (possible) reception of new MAC PDUs
        cMessage* flushHarqMsg = new cMessage("flushHarqMsg");
        flushHarqMsg->setSchedulingPriority(1);        // after other messages
        scheduleAt(NOW, flushHarqMsg);
    }

    //============================ DEBUG ==========================
    HarqTxBuffers::iterator it;

    EV << "\n htxbuf.size " << harqTxBuffers_.size() << endl;

    int cntOuter = 0;
    int cntInner = 0;
    for(it = harqTxBuffers_.begin(); it != harqTxBuffers_.end(); it++)
    {
        LteHarqBufferTx* currHarq = it->second;
        BufferStatus harqStatus = currHarq->getBufferStatus();
        BufferStatus::iterator jt = harqStatus.begin(), jet= harqStatus.end();

        EV << "\t cicloOuter " << cntOuter << " - bufferStatus.size=" << harqStatus.size() << endl;
        for(; jt != jet; ++jt)
        {
            EV << "\t\t cicloInner " << cntInner << " - jt->size=" << jt->size()
               << " - statusCw(0/1)=" << jt->at(0).second << "/" << jt->at(1).second << endl;
        }
    }
    //======================== END DEBUG ==========================

    unsigned int purged =0;
    // purge from corrupted PDUs all Rx H-HARQ buffers
    for (hit= harqRxBuffers_.begin(); hit != het; ++hit)
    {
        // purge corrupted PDUs only if this buffer is for a DL transmission. Otherwise, if you
        // purge PDUs for D2D communication, also "mirror" buffers will be purged
        if (hit->first == cellId_)
            purged += hit->second->purgeCorruptedPdus();
    }
    EV << NOW << " LteMacUeRealisticD2D::handleSelfMessage Purged " << purged << " PDUS" << endl;

    if (requestSdu == false)
    {
        // update current harq process id
        currentHarq_ = (currentHarq_+1) % harqProcesses_;
    }

    EV << "--- END UE MAIN LOOP ---" << endl;
}


UserTxParams* LteMacUeRealisticD2D::getPreconfiguredTxParams()
{
    UserTxParams* txParams = new UserTxParams();

    // default parameters for D2D
    txParams->isSet() = true;
    txParams->writeTxMode(TRANSMIT_DIVERSITY);
    Rank ri = 1;                                              // rank for TxD is one
    txParams->writeRank(ri);
    txParams->writePmi(intuniform(1, pow(ri, (double) 2)));   // taken from LteFeedbackComputationRealistic::computeFeedback

    Cqi cqi = par("d2dCqi");
    if (cqi < 0 || cqi > 15)
        throw cRuntimeError("LteMacUeRealisticD2D::getPreconfiguredTxParams - CQI %s is not a valid value. Aborting", cqi);
    txParams->writeCqi(std::vector<Cqi>(1,cqi));

    BandSet b;
    for (Band i = 0; i < getDeployer(nodeId_)->getNumBands(); ++i) b.insert(i);

    RemoteSet antennas;
    antennas.insert(MACRO);
    txParams->writeAntennas(antennas);

    return txParams;
}

void LteMacUeRealisticD2D::macHandleD2DModeSwitch(cPacket* pkt)
{
    EV << NOW << " LteMacUeRealisticD2D::macHandleD2DModeSwitch - Start" << endl;

    // all data in the MAC buffers of the connection to be switched are deleted

    D2DModeSwitchNotification* switchPkt = check_and_cast<D2DModeSwitchNotification*>(pkt);
    bool txSide = switchPkt->getTxSide();
    MacNodeId peerId = switchPkt->getPeerId();
    LteD2DMode newMode = switchPkt->getNewMode();
    LteD2DMode oldMode = switchPkt->getOldMode();
    UserControlInfo* uInfo = check_and_cast<UserControlInfo*>(pkt->removeControlInfo());

    if (txSide)
    {
        Direction newDirection = (newMode == DM) ? D2D : UL;
        Direction oldDirection = (oldMode == DM) ? D2D : UL;

        // find the correct connection involved in the mode switch
        MacCid cid;
        FlowControlInfo* lteInfo = NULL;
        std::map<MacCid, FlowControlInfo>::iterator it = connDesc_.begin();
        for (; it != connDesc_.end(); ++it)
        {
            cid = it->first;
            lteInfo = check_and_cast<FlowControlInfo*>(&(it->second));

            if (lteInfo->getD2dRxPeerId() == peerId && (Direction)lteInfo->getDirection() == oldDirection)
            {
                EV << NOW << " LteMacUeRealisticD2D::macHandleD2DModeSwitch - found old connection with cid " << cid << ", erasing buffered data" << endl;
                if (oldDirection != newDirection)
                {
                    // empty virtual buffer for the selected cid
                    LteMacBufferMap::iterator macBuff_it = macBuffers_.find(cid);
                    if (macBuff_it != macBuffers_.end())
                    {
                        while (!(macBuff_it->second->isEmpty()))
                            macBuff_it->second->popFront();
                        delete macBuff_it->second;
                        macBuffers_.erase(macBuff_it);
                    }

                    // empty real buffer for the selected cid (they should be already empty)
                    LteMacBuffers::iterator mBuf_it = mbuf_.find(cid);
                    if (mBuf_it != mbuf_.end())
                    {
                        while (mBuf_it->second->getQueueLength() > 0)
                        {
                            cPacket* pdu = mBuf_it->second->popFront();
                            delete pdu;
                        }
                        delete mBuf_it->second;
                        mbuf_.erase(mBuf_it);
                    }

                    // interrupt H-ARQ processes for SL
                    unsigned int id = peerId;
                    HarqTxBuffers::iterator hit = harqTxBuffers_.find(id);
                    if (hit != harqTxBuffers_.end())
                    {
                        for (int proc = 0; proc < (unsigned int) UE_TX_HARQ_PROCESSES; proc++)
                        {
                            hit->second->forceDropProcess(proc);
                        }
                    }

                    // interrupt H-ARQ processes for UL
                    id = getMacCellId();
                    hit = harqTxBuffers_.find(id);
                    if (hit != harqTxBuffers_.end())
                    {
                        for (int proc = 0; proc < (unsigned int) UE_TX_HARQ_PROCESSES; proc++)
                        {
                            hit->second->forceDropProcess(proc);
                        }
                    }
                }

                // abort BSR requests
                bsrTriggered_ = false;

                D2DModeSwitchNotification* switchPkt_dup = switchPkt->dup();
                switchPkt_dup->setControlInfo(lteInfo->dup());
                switchPkt_dup->setOldConnection(true);
                sendUpperPackets(switchPkt_dup);

                if (oldDirection != newDirection)
                {
                    // remove entry from lcgMap
                    LcgMap::iterator lt = lcgMap_.begin();
                    for (; lt != lcgMap_.end(); )
                    {
                        if (lt->second.first == cid)
                        {
                            lcgMap_.erase(lt++);
                        }
                        else
                        {
                            ++lt;
                        }
                    }
                }
                EV << NOW << " LteMacUeRealisticD2D::macHandleD2DModeSwitch - send switch signal to the RLC TX entity corresponding to the old mode, cid " << cid << endl;
            }
            else if (lteInfo->getD2dRxPeerId() == peerId && (Direction)lteInfo->getDirection() == newDirection)
            {
                EV << NOW << " LteMacUeRealisticD2D::macHandleD2DModeSwitch - send switch signal to the RLC TX entity corresponding to the new mode, cid " << cid << endl;
                if (oldDirection != newDirection)
                {
                    D2DModeSwitchNotification* switchPkt_dup = switchPkt->dup();
                    switchPkt_dup->setOldConnection(false);
                    switchPkt_dup->setControlInfo(lteInfo->dup());
                    sendUpperPackets(switchPkt_dup);
                }
            }
        }
    }
    else   // rx side
    {
        Direction newDirection = (newMode == DM) ? D2D : DL;
        Direction oldDirection = (oldMode == DM) ? D2D : DL;

        // find the correct connection involved in the mode switch
        MacCid cid;
        FlowControlInfo* lteInfo = NULL;
        std::map<MacCid, FlowControlInfo>::iterator it = connDescIn_.begin();
        for (; it != connDescIn_.end(); ++it)
        {
            cid = it->first;
            lteInfo = check_and_cast<FlowControlInfo*>(&(it->second));
            if (lteInfo->getD2dTxPeerId() == peerId && (Direction)lteInfo->getDirection() == oldDirection)
            {
                EV << NOW << " LteMacUeRealisticD2D::macHandleD2DModeSwitch - found old connection with cid " << cid << ", send signal to the RLC RX entity" << endl;
                if (oldDirection != newDirection)
                {
                    // interrupt H-ARQ processes for SL
                    unsigned int id = peerId;
                    HarqRxBuffers::iterator hit = harqRxBuffers_.find(id);
                    if (hit != harqRxBuffers_.end())
                    {
                        for (unsigned int proc = 0; proc < (unsigned int) UE_RX_HARQ_PROCESSES; proc++)
                        {
                            unsigned int numUnits = hit->second->getProcess(proc)->getNumHarqUnits();
                            for (unsigned int i=0; i < numUnits; i++)
                            {

                                hit->second->getProcess(proc)->purgeCorruptedPdu(i); // delete contained PDU
                                hit->second->getProcess(proc)->resetCodeword(i);     // reset unit
                            }
                        }
                    }
                    enb_->deleteRxHarqBufferMirror(nodeId_);

                    // notify that this UE is switching during this TTI
                    resetHarq_[peerId] = NOW;

                    D2DModeSwitchNotification* switchPkt_dup = switchPkt->dup();
                    switchPkt_dup->setControlInfo(lteInfo->dup());
                    switchPkt_dup->setOldConnection(true);
                    sendUpperPackets(switchPkt_dup);
                }
            }
            else if (lteInfo->getD2dTxPeerId() == peerId && (Direction)lteInfo->getDirection() == newDirection)
            {
                EV << NOW << " LteMacUeRealisticD2D::macHandleD2DModeSwitch - found new connection with cid " << cid << ", send signal to the RLC RX entity" << endl;
                if (oldDirection != newDirection)
                {
                    D2DModeSwitchNotification* switchPkt_dup = switchPkt->dup();
                    switchPkt_dup->setOldConnection(false);
                    switchPkt_dup->setControlInfo(lteInfo->dup());
                    sendUpperPackets(switchPkt_dup);
                }
            }
        }
    }
    delete uInfo;
    delete pkt;
}


std::vector<std::string> LteMacUeRealisticD2D::getMessageType(std::string str, char delimeter){
    std::vector<std::string> msgType;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimeter))
    {
        msgType.push_back(token);
    }

    return msgType;
}
