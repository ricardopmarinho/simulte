//
//                           SimuLTE
//
// This file is part of a software released under the license included in file
// "license.pdf". This license can be also found at http://www.ltesimulator.com/
// The above file and the present reference are part of the software itself,
// and cannot be removed from it.
//

#include "stack/mac/layer/LteMacEnb.h"
#include "stack/mac/buffer/harq/LteHarqBufferRx.h"
#include "stack/mac/buffer/LteMacBuffer.h"
#include "stack/mac/buffer/LteMacQueue.h"
#include "stack/phy/packet/LteFeedbackPkt.h"
#include "stack/mac/scheduler/LteSchedulerEnbDl.h"
#include "stack/mac/scheduler/LteSchedulerEnbUl.h"
#include "stack/mac/packet/LteSchedulingGrant.h"
#include "stack/mac/allocator/LteAllocationModule.h"
#include "stack/mac/amc/LteAmc.h"
#include "stack/mac/amc/UserTxParams.h"
#include "stack/mac/packet/LteRac_m.h"
#include "common/LteCommon.h"

Define_Module( LteMacEnb);

/*********************
 * PUBLIC FUNCTIONS
 *********************/

LteMacEnb::LteMacEnb() :
    LteMacBase()
{
    deployer_ = NULL;
    amc_ = NULL;
    enbSchedulerDl_ = NULL;
    enbSchedulerUl_ = NULL;
    numAntennas_ = 0;
    bsrbuf_.clear();
    currentSubFrameType_ = NORMAL_FRAME_TYPE;
    nodeType_ = ENODEB;
    frameIndex_ = 0;
    lastTtiAllocatedRb_ = 0;
}

LteMacEnb::~LteMacEnb()
{
    delete amc_;
    delete enbSchedulerDl_;
    delete enbSchedulerUl_;
    delete tSample_;

    LteMacBufferMap::iterator bit;
    for (bit = bsrbuf_.begin(); bit != bsrbuf_.end(); bit++)
        delete bit->second;
    bsrbuf_.clear();
}

/***********************
 * PROTECTED FUNCTIONS
 ***********************/

LteDeployer* LteMacEnb::getDeployer()
{
    // Get local deployer
    if (deployer_ != NULL)
        return deployer_;

    return check_and_cast<LteDeployer*>(getParentModule()-> // Stack
    getParentModule()-> // Enb
    getSubmodule("deployer")); // Deployer
}

int LteMacEnb::getNumAntennas()
{
    /* Get number of antennas: +1 is for MACRO */
    return deployer_->getNumRus() + 1;
}

SchedDiscipline LteMacEnb::getSchedDiscipline(Direction dir)
{
    if (dir == DL)
        return aToSchedDiscipline(
            par("schedulingDisciplineDl").stdstringValue());
    else if (dir == UL)
        return aToSchedDiscipline(
            par("schedulingDisciplineUl").stdstringValue());
    else
    {
        throw cRuntimeError("LteMacEnb::getSchedDiscipline(): unrecognized direction %d", (int) dir);
    }
}

double LteMacEnb::getLteAdeadline(LteTrafficClass tClass, Direction dir)
{
    std::string a("lteAdeadline");
    a.append(lteTrafficClassToA(tClass));
    a.append(dirToA(dir));
    return par(a.c_str());
}

double LteMacEnb::getLteAslackTerm(LteTrafficClass tClass, Direction dir)
{
    std::string a("lteAslackTerm");
    a.append(lteTrafficClassToA(tClass));
    a.append(dirToA(dir));
    return par(a.c_str());
}

int LteMacEnb::getLteAmaxUrgentBurst(LteTrafficClass tClass, Direction dir)
{
    std::string a("lteAmaxUrgentBurst");
    a.append(lteTrafficClassToA(tClass));
    a.append(dirToA(dir));
    return par(a.c_str());
}
int LteMacEnb::getLteAmaxFairnessBurst(LteTrafficClass tClass, Direction dir)
{
    std::string a("lteAmaxFairnessBurst");
    a.append(lteTrafficClassToA(tClass));
    a.append(dirToA(dir));
    return par(a.c_str());
}

int LteMacEnb::getLteAhistorySize(Direction dir)
{
    std::string a("lteAhistorySize");
    a.append(dirToA(dir));
    return par(a.c_str());
}

int LteMacEnb::getLteAgainHistoryTh(LteTrafficClass tClass, Direction dir)
{
    std::string a("lteAgainHistoryTh");
    a.append(lteTrafficClassToA(tClass));
    a.append(dirToA(dir));
    return par(a.c_str());
}

double LteMacEnb::getZeroLevel(Direction dir, LteSubFrameType type)
{
    std::string a("zeroLevel");
    a.append(SubFrameTypeToA(type));
    a.append(dirToA(dir));
    return par(a.c_str());
}

double LteMacEnb::getIdleLevel(Direction dir, LteSubFrameType type)
{
    std::string a("idleLevel");
    a.append(SubFrameTypeToA(type));
    a.append(dirToA(dir));
    return par(a.c_str());
}

double LteMacEnb::getPowerUnit(Direction dir, LteSubFrameType type)
{
    std::string a("powerUnit");
    a.append(SubFrameTypeToA(type));
    a.append(dirToA(dir));
    return par(a.c_str());
}
double LteMacEnb::getMaxPower(Direction dir, LteSubFrameType type)
{
    std::string a("maxPower");
    a.append(SubFrameTypeToA(type));
    a.append(dirToA(dir));
    return par(a.c_str());
}

unsigned int LteMacEnb::getAllocationRbs(Direction dir)
{
    if (dir == DL)
    {
        return par("lteAallocationRbsDl");
    }
    else
        return par("lteAallocationRbsUl");
}

bool LteMacEnb::getPfTmsAwareFlag(Direction dir)
{
    if (dir == DL)
        return par("pfTmsAwareDL");
    else
        return par("pfTmsAwareUL");
}

void LteMacEnb::deleteQueues(MacNodeId nodeId)
{
    LteMacBase::deleteQueues(nodeId);

    LteMacBufferMap::iterator bit;
    for (bit = bsrbuf_.begin(); bit != bsrbuf_.end();)
    {
        if (MacCidToNodeId(bit->first) == nodeId)
        {
            delete bit->second; // Delete Queue
            bsrbuf_.erase(bit++); // Delete Elem
        }
        else
        {
            ++bit;
        }
    }

    //update harq status in schedulers
//    enbSchedulerDl_->updateHarqDescs();
//    enbSchedulerUl_->updateHarqDescs();

    // remove active connections from the schedulers
    enbSchedulerDl_->removeActiveConnections(nodeId);
    enbSchedulerUl_->removeActiveConnections(nodeId);

    // remove pending RAC requests
    enbSchedulerUl_->removePendingRac(nodeId);
}

void LteMacEnb::initialize(int stage)
{
    LteMacBase::initialize(stage);
    if (stage == inet::INITSTAGE_LOCAL)
    {

        cainMessageSignal = registerSignal("CainMessage");
        cainHopMessageSignal = registerSignal("CainHopMessage");
        DistanceSignal = registerSignal("DistanceSignal");
        hopDistanceSignal = registerSignal("HopDistanceSignal");
        servedDevsSignal = registerSignal("ServedDevs");
        servedHopDevsSignal = registerSignal("ServedHopDevs");
        totalServedDevsSignal = registerSignal("TotalServedDevs");
        racpktSignal = registerSignal("racpkt");
        racDistanceSignal = registerSignal("racDistanceSignal");
        racServedDevsSignal = registerSignal("racServedDevsSignal");

        // TODO: read NED parameters, when will be present
        deployer_ = getDeployer();
        /* Get num RB Dl */
        numRbDl_ = deployer_->getNumRbDl();
        /* Get num RB Ul */
        numRbUl_ = deployer_->getNumRbUl();

        /* Get number of antennas */
        numAntennas_ = getNumAntennas();

        /* Create and initialize MAC Downlink scheduler */
        if (enbSchedulerDl_ == NULL)
        {
            enbSchedulerDl_ = new LteSchedulerEnbDl();
            enbSchedulerDl_->initialize(DL, this);
        }

        /* Create and initialize MAC Uplink scheduler */
        if (enbSchedulerUl_ == NULL)
        {
            enbSchedulerUl_ = new LteSchedulerEnbUl();
            enbSchedulerUl_->initialize(UL, this);
        }
        //Initialize the current sub frame type with the first subframe of the MBSFN pattern
        currentSubFrameType_ = NORMAL_FRAME_TYPE;

        tSample_ = new TaggedSample();
        activatedFrames_ = registerSignal("activatedFrames");
        sleepFrames_ = registerSignal("sleepFrames");
        wastedFrames_ = registerSignal("wastedFrames");
        cqiDlMuMimo0_ = registerSignal("cqiDlMuMimo0");
        cqiDlMuMimo1_ = registerSignal("cqiDlMuMimo1");
        cqiDlMuMimo2_ = registerSignal("cqiDlMuMimo2");
        cqiDlMuMimo3_ = registerSignal("cqiDlMuMimo3");
        cqiDlMuMimo4_ = registerSignal("cqiDlMuMimo4");

        cqiDlTxDiv0_ = registerSignal("cqiDlTxDiv0");
        cqiDlTxDiv1_ = registerSignal("cqiDlTxDiv1");
        cqiDlTxDiv2_ = registerSignal("cqiDlTxDiv2");
        cqiDlTxDiv3_ = registerSignal("cqiDlTxDiv3");
        cqiDlTxDiv4_ = registerSignal("cqiDlTxDiv4");

        cqiDlSpmux0_ = registerSignal("cqiDlSpmux0");
        cqiDlSpmux1_ = registerSignal("cqiDlSpmux1");
        cqiDlSpmux2_ = registerSignal("cqiDlSpmux2");
        cqiDlSpmux3_ = registerSignal("cqiDlSpmux3");
        cqiDlSpmux4_ = registerSignal("cqiDlSpmux4");

        cqiDlSiso0_ = registerSignal("cqiDlSiso0");
        cqiDlSiso1_ = registerSignal("cqiDlSiso1");
        cqiDlSiso2_ = registerSignal("cqiDlSiso2");
        cqiDlSiso3_ = registerSignal("cqiDlSiso3");
        cqiDlSiso4_ = registerSignal("cqiDlSiso4");

        tSample_->module_ = check_and_cast<cComponent*>(this);
        tSample_->id_ = nodeId_;

        eNodeBCount = par("eNodeBCount");
        WATCH(numAntennas_);
        WATCH_MAP(bsrbuf_);
    }
    else if (stage == 1)
    {
        /* Create and initialize AMC module */
        amc_ = new LteAmc(this, binder_, deployer_, numAntennas_);

        /* Insert EnbInfo in the Binder */
        EnbInfo* info = new EnbInfo();
        info->id = nodeId_;            // local mac ID
        info->type = MACRO_ENB;        // eNb Type
        info->init = false;            // flag for phy initialization
        info->eNodeB = this->getParentModule()->getParentModule();  // reference to the eNodeB module
        /////
        info->Bmap = new std::map<MacNodeId,double>();
        info->Wmap = new std::map<MacNodeId,double>();
        info->pwrThresh = getModuleByPath("CAIN")->par("pwrThresh");
        info->Clist = new std::map<MacNodeId,Coord>();
        info->distMap = new relayDist();
        info->mapUe = new UeAreaMap();
        info->relayMap = new ueRelay();
        info->moreRb = new rbIncrease();

        binder_->addEnbInfo(info);

        // register the pair <id,name> to the binder
        const char* moduleName = getParentModule()->getParentModule()->getName();
        binder_->registerName(nodeId_, moduleName);
    }
}

void LteMacEnb::handleMessage(cMessage *msg)
{
    LteMacBase::handleMessage(msg);
}


void LteMacEnb::bufferizeBsr(MacBsr* bsr, MacCid cid)
{
    PacketInfo vpkt(bsr->getSize(), bsr->getTimestamp());

    LteMacBufferMap::iterator it = bsrbuf_.find(cid);
    if (it == bsrbuf_.end())
    {
        // Queue not found for this cid: create
        LteMacBuffer* bsrqueue = new LteMacBuffer();

        bsrqueue->pushBack(vpkt);
        bsrbuf_[cid] = bsrqueue;

        EV << "LteBsrBuffers : Added new BSR buffer for node: "
           << MacCidToNodeId(cid) << " for Lcid: " << MacCidToLcid(cid)
           << " Current BSR size: " << bsr->getSize() << "\n";
    }
    else
    {
        // Found
        LteMacBuffer* bsrqueue = it->second;
        bsrqueue->pushBack(vpkt);

        EV << "LteBsrBuffers : Using old buffer for node: " << MacCidToNodeId(
            cid) << " for Lcid: " << MacCidToLcid(cid)
           << " Current BSR size: " << bsr->getSize() << "\n";
    }

        // signal backlog to Uplink scheduler
    enbSchedulerUl_->backlog(cid);
}

void LteMacEnb::sendGrants(LteMacScheduleList* scheduleList)
{

    EV << NOW << "LteMacEnb::sendGrants " << endl;

    while (!scheduleList->empty())
    {
        LteMacScheduleList::iterator it, ot;
        it = scheduleList->begin();

        Codeword cw = it->first.second;
        Codeword otherCw = MAX_CODEWORDS - cw;

        MacCid cid = it->first.first;
        LogicalCid lcid = MacCidToLcid(cid);
        MacNodeId nodeId = MacCidToNodeId(cid);

        unsigned int granted = it->second;
        unsigned int codewords = 0;

        // removing visited element from scheduleList.
        scheduleList->erase(it);

        if (granted > 0)
        {
            // increment number of allocated Cw
            ++codewords;
        }
        else
        {
            // active cw becomes the "other one"
            cw = otherCw;
        }

        std::pair<unsigned int, Codeword> otherPair(nodeId, otherCw);

        if ((ot = (scheduleList->find(otherPair))) != (scheduleList->end()))
        {
            // increment number of allocated Cw
            ++codewords;

            // removing visited element from scheduleList.
            scheduleList->erase(ot);
        }

        if (granted == 0)
        continue; // avoiding transmission of 0 grant (0 grant should not be created)

        EV << NOW << " LteMacEnb::sendGrants Node[" << getMacNodeId() << "] - "
           << granted << " blocks to grant for user " << nodeId << " on "
           << codewords << " codewords. CW[" << cw << "\\" << otherCw << "]" << endl;

        // TODO Grant is set aperiodic as default
        LteSchedulingGrant* grant = new LteSchedulingGrant("LteGrant");

        grant->setDirection(UL);

        grant->setCodewords(codewords);

        // set total granted blocks
        grant->setTotalGrantedBlocks(granted);

        UserControlInfo* uinfo = new UserControlInfo();
        uinfo->setSourceId(getMacNodeId());
        uinfo->setDestId(nodeId);
        uinfo->setFrameType(GRANTPKT);

        grant->setControlInfo(uinfo);

        // get and set the user's UserTxParams
        const UserTxParams& ui = getAmc()->computeTxParams(nodeId, UL);
        UserTxParams* txPara = new UserTxParams(ui);
        grant->setUserTxParams(txPara);

        // acquiring remote antennas set from user info
        const std::set<Remote>& antennas = ui.readAntennaSet();
        std::set<Remote>::const_iterator antenna_it, antenna_et = antennas.end();
        const unsigned int logicalBands = deployer_->getNumBands();

        //  HANDLE MULTICW
        for (; cw < codewords; ++cw)
        {
            unsigned int grantedBytes = 0;

            for (Band b = 0; b < logicalBands; ++b)
            {
                unsigned int bandAllocatedBlocks = 0;

                for (antenna_it = antennas.begin(); antenna_it != antenna_et; ++antenna_it)
                {
                    bandAllocatedBlocks += enbSchedulerUl_->readPerUeAllocatedBlocks(nodeId,
                        *antenna_it, b);
                }

                grantedBytes += amc_->computeBytesOnNRbs(nodeId, b, cw,
                    bandAllocatedBlocks, UL);
            }

            grant->setGrantedCwBytes(cw, grantedBytes);
            EV << NOW << " LteMacEnb::sendGrants - granting " << grantedBytes << " on cw " << cw << endl;
        }

        RbMap map;

        enbSchedulerUl_->readRbOccupation(nodeId, map);

        grant->setGrantedBlocks(map);

        // send grant to PHY layer
        sendLowerPackets(grant);
    }
}

void LteMacEnb::macHandleRac(cPacket* pkt)
{
    EV << NOW << " LteMacEnb::macHandleRac" << endl;

    racpkt++;
    emit(racpktSignal,racpkt);

    LteRac* racPkt = check_and_cast<LteRac*> (pkt);
    UserControlInfo* uinfo = check_and_cast<UserControlInfo*> (
        racPkt->getControlInfo());

    Coord ueCoord = uinfo->getCoord();
    racDistance = ueCoord.distance(binder_->getEnbCoord());
    emit(racDistanceSignal,racDistance);

    racServedDevscount = binder_->racServedDevscount();
    emit(racServedDevsSignal,racServedDevscount);
    if(uinfo->getCAINEnable() && (uinfo->getCAINDirection()==FWD || uinfo->getCAINDirection()==HOP_FWD || uinfo->getCAINDirection()==HOP_ANSW
            || uinfo->getCAINDirection()==ANSW)){
        EV << "Options: " << uinfo->getCAINOptions() << endl;
        Coord enbCoord = uinfo->getEnbCoord();
        ueCoord = uinfo->getCoord();
        distance = enbCoord.distance(ueCoord);
        emit(DistanceSignal,distance);
        switch (uinfo->getCAINDirection()) {
            case FWD:
            {
                ueCoord = uinfo->getCAINCoord();
                EV << "ENB receiving a CAIN FWD message!" << endl;
                EV << "Node " << uinfo->getSourceId() << " needs more " <<
                        binder_->getIncreaseResourceBlock(uinfo->getSourceId()) << endl;


                std::string opt = uinfo->getCAINOptions();

                if(binder_->getAllocatedRb(uinfo->getSourceId()))
                {
                    EV << "RB allocation ok" << endl;
                    uinfo->setDestId(uinfo->getSourceId());
                    uinfo->setSourceId(1);
                    uinfo->setCAINDirection(REP);
                    uinfo->setCAINOption("");
                    std::ostringstream stream;
                    stream << "OK|" << opt;
                    uinfo->appendOption(stream.str());
                }
                else
                {
                    EV << "RB allocation not ok" << endl;
                    uinfo->setDestId(uinfo->getSourceId());
                    uinfo->setSourceId(1);
                    uinfo->setCAINDirection(REP);
                    uinfo->setCAINOption("");
                    std::ostringstream stream;
                    stream << "NOK|" << opt;
                    uinfo->appendOption(stream.str());
                }

                CainMessage++;
                emit(cainMessageSignal,CainMessage);

                sendLowerPackets(racPkt);

                break;
            }
            case HOP_FWD:
            {
                EV << "ENB receiving a CAIN HOP_FWD message!" << endl;
                EV << "Options: " << uinfo->getCAINOptions() << endl;
                EV << "CAIN Dest: " << uinfo->getCAINdest() << endl;
                EV << "Dest: " << uinfo->getDestId() << endl;

                EV << endl;

                std::vector<MacNodeId> node;
                std::string token;
                std::istringstream tokenStream(uinfo->getCAINOptions());
                while (std::getline(tokenStream, token, '/'))
                {
                    node.push_back(stoi(token));
                }

                if(binder_->getAllocatedRb(uinfo->getSourceId()))
                {
                    EV << "RB allocation ok" << endl;
                    uinfo->setDestId(uinfo->getSourceId());
                    uinfo->setSourceId(1);
                    uinfo->setCAINDirection(HOP_REP);
                    uinfo->setCAINOption("");
                    std::ostringstream stream;
                    stream << "OK|" << node[1];
                    uinfo->appendOption(stream.str());
                }
                else
                {
                    EV << "RB allocation not ok" << endl;
                    uinfo->setDestId(uinfo->getSourceId());
                    uinfo->setSourceId(1);
                    uinfo->setCAINDirection(HOP_REP);
                    uinfo->setCAINOption("");
                    std::ostringstream stream;
                    stream << "NOK|" << node[1];
                    uinfo->appendOption(stream.str());
                }

                cainHopMessage++;
                emit(cainHopMessageSignal,cainHopMessage);

                sendLowerPackets(racPkt);
                break;
            }
            case HOP_ANSW:
            {
                EV << "ENB receiving a CAIN HOP_ANSW message!" << endl;
                EV << "Options: " << uinfo->getCAINOptions() << endl;
                EV << "CAIN Dest: " << uinfo->getCAINdest() << endl;
                EV << "Dest: " << uinfo->getDestId() << endl;

                EV << endl;
                std::vector<std::string> node;
                std::string token;
                std::istringstream tokenStream(uinfo->getCAINOptions());
                while (std::getline(tokenStream, token, '|'))
                {
                    node.push_back(token);
                }

                EV << "Hop message from: " << stoi(node[1]) << endl;
                servHopDevs = binder_->countServedHopDevs();
                emit(servedHopDevsSignal, servHopDevs);
                delete pkt;
                return;
            }
            case ANSW:
            {
                EV << "ENB receiving a CAIN ANSW message!" << endl;
                EV << "Options: " << uinfo->getCAINOptions() << endl;
                EV << "CAIN Dest: " << uinfo->getCAINdest() << endl;
                EV << "Dest: " << uinfo->getDestId() << endl;

                EV << endl;
                std::vector<std::string> node;
                std::string token;
                std::istringstream tokenStream(uinfo->getCAINOptions());
                while (std::getline(tokenStream, token, '|'))
                {
                    node.push_back(token);
                }

                EV << "Message from: " << stoi(node[1]) << endl;
                servDevs = binder_->countServedDevs();
                emit(servedDevsSignal, servDevs);
                delete pkt;
                return;
            }
            default:
                break;
        }

//        EV << endl;
//        binder_->printTotalServedDevs();
//        if(!binder_->getTotalServedDevByIndex(uinfo->getCAINdest()-1025)){
//            binder_->setTotalServedDev(uinfo->getCAINdest()-1025,true);
//        }
//        binder_->printTotalServedDevs();
//        EV << endl;
//
//
//
//        delete pkt;
        return;
    }
    enbSchedulerUl_->signalRac(uinfo->getSourceId());

    // TODO all RACs are marked are successful
    racPkt->setSuccess(true);

    uinfo->setDestId(uinfo->getSourceId());
    uinfo->setSourceId(nodeId_);
    uinfo->setDirection(DL);
    bool cainEnable = getModuleByPath("CAIN")->par("cainNetwork");

    EV << "Cain enable?" << cainEnable << endl;

//    if(cainEnable){
//        std::vector<EnbInfo*>* vect = binder_->getEnbList();
//        for(unsigned int i=0;i< vect->size();i++){
//            if(1 == vect->at(i)->id){
//                sinrMapW* WsMap = vect->operator [](i)->Wmap;
//                sinrMapB* BsMap = vect->operator [](i)->Bmap;
//                coordList* csList = vect->operator [](i)->Clist;
//
//                int qtdThresh = getModuleByPath("CAIN")->par("qtdThresh");
//                int distThresh = getModuleByPath("CAIN")->par("distThresh");
//
//                std::map<MacNodeId,Coord>::iterator Cit;
//                for(Cit = csList->begin(); Cit != csList->end(); Cit++){
//                    EV << "UE id: " << Cit->first << ", coordinate: " << Cit->second << endl;
//                }
//
//                EV << "BsMap size: " << BsMap->size() << endl;
//                EV << "WsMap size: " << WsMap->size() << endl;
//                std::ostringstream stream;
//                if(WsMap->size() > 0 && BsMap->size() > 0){
//                    EV << "=============== SETTING CAIN MESSAGE ===============\n";
//                    //reset any previous option
//                    uinfo->setCAINOption("");
//                    std::map<MacNodeId,double>::iterator it;
//                    std::map<MacNodeId,double> nodes;
//                    for(it = WsMap->begin(); it != WsMap->end(); it++){
//                        MacNodeId node = it->first;
//                        EV << "\nNode " << it->first << " with power " << it->second << " needs find a relay! \n";
//                        /*
//                         * setting options field with the id of the node that needs a relay
//                         * and it's sinr
//                         * */
//                        nodes[node]=it->second;
//                    }
//
//                    std::map<MacNodeId,double>::iterator vecIt;
//
//                    for(vecIt = nodes.begin(); vecIt != nodes.end();vecIt++)
//                        EV << "Node id: " << vecIt->first << ", power: " << vecIt->second << endl;
//
//                    /*
//                     * end of options setting
//                     * */
//
//                    MacNodeId relay;
//                    uinfo->setCAINEnable(true);
//                    uinfo->setENBId(nodeId_);
//                    uinfo->setMapCoord(*csList);
//                    int j;
//                    std::map<MacNodeId,std::map<MacNodeId,double>*> closerList;
//                    for(j = 0, it = BsMap->begin(); j < BsMap->size()-1;it++, j++){
//
//                        /*
//                         * qthThresh -> parameter for the number of closer devices on the closer list
//                         * qtdList -> number of devices already added on the closer list
//                         * distThresh -> parameter to decide if a device is closer enough to enter the list,
//                         * check the value on {Bertier2019}
//                         *
//                         * if(qtdList < qtdThresh){
//                         *
//                         *      if(dist(it->first,UEwl) < distThresh){
//                         *
//                         *          closerList.add(UEwl);
//                         *
//                         *      }
//                         *
//                         * }
//                         *
//                         * */
//                        relay = it->first;
//                        EV << "\nNode " << it->first << " with power " << it->second << " can be a relay! \n";
//                        UserControlInfo* uinfoDup = uinfo->dup();
//                        uinfoDup->setDestId(relay);
//                        uinfoDup->setCAINuePwr(it->second);
//                        uinfoDup->setMapCoord(*csList);
//                        LteRac* racDup = racPkt->dup();
//
//
//                        closerList = generateCloserList(relay,nodes,csList);
//                        std::map<MacNodeId,double>::iterator mapIt = closerList[relay]->begin();
//                        /*
//                         * Sorting the list for the relay
//                         *
//                         * */
//                        std::set<std::pair<MacNodeId,double>, Comparator> sortedListP(
//                                closerList[relay]->begin(), closerList[relay]->end(), compFunctor);
//                        EV << "Sorted List for relay" << relay << endl;
//                        for (std::pair<MacNodeId,double> element : sortedListP){
//                            EV<<element.first<<": " <<element.second<<endl;
//                        }
//
//                        closerList[relay]->clear();
//                        std::map<MacNodeId,double>* closeNode=new std::map<MacNodeId,double>();
//                        EV << "Closer list to relay " << relay << ": " << endl;
//                        int k = 0;
//                        std::list<MacNodeId>* assDev = NULL;
//                        std::vector<UeInfo*>* ueVect = binder_->getUeList();
//                        for(unsigned int ii = 0; ii < ueVect->size(); ii++){
//                            if(ueVect->at(ii)->id == relay)
//                                assDev = ueVect->operator [](ii)->assList;
//                        }
//                        /*
//                         * Iterates over the relay list
//                         * */
//                        for (std::pair<MacNodeId,double> element : sortedListP){
//
//                            updateAssistedList(element.first,assDev);
//                            printAssistedList(relay,assDev);
//
//                            if(k < qtdThresh && element.second < distThresh){
//                                /*
//                                 * If there is nodes close enough to the relay
//                                 * send the CAIN message directly
//                                 * */
//                                EV << element.first << " :: " << element.second << endl;
//                                MacNodeId node = element.first;
//                                double pwr = nodes[node];
//                                stream << node << "/" << pwr;
//                                uinfoDup->appendOption(stream.str());
//                                stream.str("");
//                                stream.clear();
//                                k++;
//
//                                uinfoDup->setCAINDirection(NOTIFY);
//                                closeNode->operator [](element.first) = element.second;
//                                /*Inserts the closest nodes on the list*/
//                                closerList[relay] = closeNode;
//                            }else{
//                                /*
//                                 * When the nodes are far from the relay,
//                                 * initiates a hop forwarding
//                                 * */
//                                if(closerList[relay]->empty()){//when every node is too far from relay
//                                    MacNodeId node = element.first;
//                                    double pwr = element.second;
//                                    stream << node << "/" << pwr;
//                                    uinfoDup->appendOption(stream.str());
//                                    stream.str("");
//                                    stream.clear();
//                                    uinfoDup->setCAINDirection(NOTIFY);
//                                }else{
//                                    closeNode=closerList[relay];
//                                    std::map<MacNodeId,double>::iterator itClose = closeNode->begin();
//                                    EV << "Relay ID: " << relay << ", Hop ID: " << itClose->first << ", UE ID: " << element.first  << endl;
//                                    MacNodeId hop = itClose->first;
//                                    MacNodeId ue = element.first;
//                                    UserControlInfo* uinfoDup2 = uinfo->dup();
//                                    uinfoDup2->setDestId(relay);
//                                    uinfoDup2->setCAINDirection(HOP_NTF);
//                                    uinfoDup2->setCAINuePwr(it->second);
//                                    stream << hop << "/" << ue;
//                                    uinfoDup2->appendOption(stream.str());
//                                    stream.str("");
//                                    stream.clear();
//                                    uinfoDup2->setCAINHopCoord(csList->operator [](element.first));
//                                    LteRac* racDup2 = racPkt->dup();
//                                    racDup2->setControlInfo(uinfoDup2);
//
//                                    EV << "Options: " << uinfoDup2->getCAINOptions() << endl;
//                                    sendLowerPackets(racDup2);
//                                }
//                            }
//
//    //                    uinfoDup->setCAINDirection(NOTIFY);
//    //                    uinfoDup->setCAINOption(uinfo->getCAINOptions());
//    //                    LteRac* racDup = racPkt->dup();
//                        }
//                        racDup->setControlInfo(uinfoDup);
//                        EV << "Options: " << uinfoDup->getCAINOptions() << endl;
//                        sendLowerPackets(racDup);
//                    }
//                    relay = it->first;
//                    EV << "\nNode " << it->first << " with power " << it->second << " can be a relay! \n";
//                    uinfo->setDestId(relay);
//                    uinfo->setCAINuePwr(it->second);
//
//                    closerList = generateCloserList(relay,nodes,csList);
//
//                    /*
//                     * Sorting the list for the relay
//                     *
//                     * */
//                    std::set<std::pair<MacNodeId,double>, Comparator> sortedList(
//                            closerList[relay]->begin(), closerList[relay]->end(), compFunctor);
//
//                    EV << "Sorted List for relay" << relay << endl;
//                    for (std::pair<MacNodeId,double> element : sortedList){
//                        EV<<element.first<<": " <<element.second<<endl;
//                    }
//                    /*
//                     * Start to recreate the closer list
//                     * necessary to find which node will
//                     * be a hop node
//                     * */
//                    closerList[relay]->clear();
//                    std::map<MacNodeId,double>* closeNode=new std::map<MacNodeId,double>();
//                    EV << "Closer list to relay " << relay << ": " << endl;
//                    int k = 0;
//
//                    std::vector<UeInfo*>* ueVect = binder_->getUeList();
//                    std::list<MacNodeId>* assDev = NULL;
//                    for(unsigned int ii = 0; ii < ueVect->size(); ii++){
//                        if(ueVect->at(ii)->id == relay)
//                            assDev = ueVect->operator [](ii)->assList;
//                    }
//                    /*
//                     * Iterates over the relay list
//                     * */
//                    for (std::pair<MacNodeId,double> element : sortedList){
//
//                        updateAssistedList(element.first,assDev);
//                        printAssistedList(relay,assDev);
//
//                        if(k < qtdThresh && element.second < distThresh){
//                            /*
//                             * If there is nodes close enough to the relay
//                             * send the CAIN message directly
//                             * */
//                            EV << element.first << " :: " << element.second << endl;
//                            MacNodeId node = element.first;
//                            double pwr = nodes[node];
//                            stream << node << "/" << pwr;
//                            uinfo->appendOption(stream.str());
//                            stream.str("");
//                            stream.clear();
//                            k++;
//
//                            uinfo->setCAINDirection(NOTIFY);
//                            closeNode->operator [](element.first) = element.second;
//                            /*Inserts the closest nodes on the list*/
//                            closerList[relay] = closeNode;
//                        }else{
//                            /*
//                             * When the nodes are far from the relay,
//                             * initiates a hop forwarding
//                             * */
//                            if(closerList[relay]->empty()){//when every node is too far from relay
//                                MacNodeId node = element.first;
//                                double pwr = element.second;
//                                stream << node << "/" << pwr;
//                                uinfo->appendOption(stream.str());
//                                stream.str("");
//                                stream.clear();
//                                uinfo->setCAINDirection(NOTIFY);
//                            }else{
//                                closeNode=closerList[relay];
//                                std::map<MacNodeId,double>::iterator itClose = closeNode->begin();
//                                EV << "Relay ID: " << relay << ", Hop ID: " << itClose->first << ", UE ID: " << element.first  << endl;
//                                MacNodeId hop = itClose->first;
//                                MacNodeId ue = element.first;
//                                UserControlInfo* uinfoDup = uinfo->dup();
//                                uinfoDup->setDestId(relay);
//                                uinfoDup->setCAINDirection(HOP_NTF);
//                                uinfoDup->setCAINuePwr(it->second);
//                                stream << hop << "/" << ue;
//                                uinfoDup->appendOption(stream.str());
//                                stream.str("");
//                                stream.clear();
//                                uinfoDup->setCAINHopCoord(csList->operator [](element.first));
//                                LteRac* racDup = racPkt->dup();
//                                racDup->setControlInfo(uinfoDup);
//
//                                EV << "Options: " << uinfoDup->getCAINOptions() << endl;
//                                sendLowerPackets(racDup);
//                            }
//                        }
//
//                    }
//
//                    EV << "=============== END OF SETTINGS ===============\n";
//                }
//            }
//        }
//    }

    double freq = getModuleByPath("CAIN.channelControl")->par("carrierFrequency");
    EV << "Carrier frequency: " << freq << "Hz" << endl;


    UserControlInfo* info = check_and_cast<UserControlInfo*>(racPkt->getControlInfo());

    EV << "Source: " << info->getSourceId() << " dest: " << info->getDestId() << endl;

    EV << "Options: " << uinfo->getCAINOptions() << endl;
    sendLowerPackets(racPkt);
}

std::map<MacNodeId,std::map<MacNodeId,double>*> LteMacEnb::generateCloserList(MacNodeId relay, std::map<MacNodeId,double> nodes,coordList* csList){


    /*
     * Creating the closer nodes map
     *
     * ----------------------------------------------------
     * | BL_ue1 | <WL_ue1;dist/WL_ue2;dist/WL_ue2;dist...>|
     * | BL_ue2 | <WL_ue1;dist/WL_ue2;dist/WL_ue2;dist...>|
     * | BL_ue3 | <WL_ue1;dist/WL_ue2;dist/WL_ue2;dist...>|
     * ----------------------------------------------------
     *
     * */


    std::map<MacNodeId,double>::iterator closerNodes;
    std::map<MacNodeId,std::map<MacNodeId,double>*> closerList;

    for(closerNodes = nodes.begin(); closerNodes != nodes.end(); closerNodes++){
//        EV << endl << "Relay id and coord: " << relay << " " << csList->operator [](relay) << endl;
//        EV << "Node id and coord: " << closerNodes->first << " " << csList->operator [](closerNodes->first) << endl;
        double distance = csList->operator [](relay).distance(csList->operator [](closerNodes->first));
//        EV << "Distance: " << distance << endl;
//        EV << "Node " << closerNodes->first << " is close enough" << endl;
        std::map<MacNodeId,double>* closeNode=NULL;
        if(closerList[relay]==NULL){
            closeNode = new std::map<MacNodeId,double>();
        }else{
            closeNode = closerList[relay];
        }
        closeNode->operator [](closerNodes->first) = distance;
        closerList[relay] = closeNode;
    }
    return closerList;
}

void LteMacEnb::updateAssistedList(MacNodeId assistedNode, assistedDevices* assDev){

    if(assDev == NULL)
        assDev = new std::list<MacNodeId>();

    assDev->push_back(assistedNode);

}

void LteMacEnb::printAssistedList(MacNodeId relay, assistedDevices* assDev){

    std::list<MacNodeId>::iterator lIt_begin;
    std::list<MacNodeId>::iterator lIt_end;
    std::list<MacNodeId>::iterator lIt;

    EV << "Relay: " << relay << " - list: ";
    lIt_begin = assDev->begin();
    lIt_end = assDev->end();
    for(lIt = lIt_begin; lIt != lIt_end; lIt++)
        EV << *lIt << " - ";
    EV << endl;
    EV << "List size: " << assDev->size() << endl;

}

void LteMacEnb::macPduMake(LteMacScheduleList* scheduleList)
{
    EV << "----- START LteMacEnb::macPduMake -----\n";
    // Finalizes the scheduling decisions according to the schedule list,
    // detaching sdus from real buffers.

    macPduList_.clear();

    //  Build a MAC pdu for each scheduled user on each codeword
    LteMacScheduleList::const_iterator it;
    for (it = scheduleList->begin(); it != scheduleList->end(); it++)
    {
        LteMacPdu* macPkt;
        cPacket* pkt;
        MacCid destCid = it->first.first;
        Codeword cw = it->first.second;
        MacNodeId destId = MacCidToNodeId(destCid);
        std::pair<MacNodeId, Codeword> pktId = std::pair<MacNodeId, Codeword>(
            destId, cw);
        unsigned int sduPerCid = it->second;
        unsigned int grantedBlocks = 0;
        TxMode txmode;
        while (sduPerCid > 0)
        {
            if ((mbuf_[destCid]->getQueueLength()) < (int) sduPerCid)
            {
                throw cRuntimeError("Abnormal queue length detected while building MAC PDU for cid %d "
                    "Queue real SDU length is %d  while scheduled SDUs are %d",
                    destCid, mbuf_[destCid]->getQueueLength(), sduPerCid);
            }

            // Add SDU to PDU
            // FIXME *move outside cycle* Find Mac Pkt
            MacPduList::iterator pit = macPduList_.find(pktId);

            // No packets for this user on this codeword
            if (pit == macPduList_.end())
            {
                UserControlInfo* uinfo = new UserControlInfo();
                uinfo->setSourceId(getMacNodeId());
                uinfo->setDestId(destId);
                uinfo->setDirection(DL);

                const UserTxParams& txInfo = amc_->computeTxParams(destId, DL);

                UserTxParams* txPara = new UserTxParams(txInfo);

                uinfo->setUserTxParams(txPara);
                txmode = txInfo.readTxMode();
                RbMap rbMap;
                uinfo->setTxMode(txmode);
                uinfo->setCw(cw);
                grantedBlocks = enbSchedulerDl_->readRbOccupation(destId, rbMap);

                uinfo->setGrantedBlocks(rbMap);
                uinfo->setTotalGrantedBlocks(grantedBlocks);

                macPkt = new LteMacPdu("LteMacPdu");
                macPkt->setHeaderLength(MAC_HEADER);
                macPkt->setControlInfo(uinfo);
                macPkt->setTimestamp(NOW);
                macPduList_[pktId] = macPkt;
            }
            else
            {
                macPkt = pit->second;
            }
            if (mbuf_[destCid]->getQueueLength() == 0)
            {
                throw cRuntimeError("Abnormal queue length detected while building MAC PDU for cid %d "
                    "Queue real SDU length is %d  while scheduled SDUs are %d",
                    destCid, mbuf_[destCid]->getQueueLength(), sduPerCid);
            }
            pkt = mbuf_[destCid]->popFront();

            ASSERT(pkt != NULL);

            take(pkt);
            macPkt->pushSdu(pkt);
            sduPerCid--;
        }
    }

    MacPduList::iterator pit;
    for (pit = macPduList_.begin(); pit != macPduList_.end(); pit++)
    {
        MacNodeId destId = pit->first.first;
        Codeword cw = pit->first.second;

        LteHarqBufferTx* txBuf;
        HarqTxBuffers::iterator hit = harqTxBuffers_.find(destId);
        if (hit != harqTxBuffers_.end())
        {
            txBuf = hit->second;
        }
        else
        {
            // FIXME: possible memory leak
            LteHarqBufferTx* hb = new LteHarqBufferTx(ENB_TX_HARQ_PROCESSES,
                this,(LteMacBase*)getMacUe(destId));
            harqTxBuffers_[destId] = hb;
            txBuf = hb;
        }
        UnitList txList = (txBuf->firstAvailable());

        LteMacPdu* macPkt = pit->second;
        EV << "LteMacBase: pduMaker created PDU: " << macPkt->info() << endl;

        // pdu transmission here (if any)
        if (txList.second.empty())
        {
            EV << "macPduMake() : no available process for this MAC pdu in TxHarqBuffer" << endl;
            delete macPkt;
        }
        else
        {
            if (txList.first == HARQ_NONE)
            throw cRuntimeError("LteMacBase: pduMaker sending to uncorrect void H-ARQ process. Aborting");
            txBuf->insertPdu(txList.first, cw, macPkt);
        }
    }
    EV << "------ END LteMacEnb::macPduMake ------\n";
}

void LteMacEnb::macPduUnmake(cPacket* pkt)
{
    LteMacPdu* macPkt = check_and_cast<LteMacPdu*>(pkt);
    while (macPkt->hasSdu())
    {
        // Extract and send SDU
        cPacket* upPkt = macPkt->popSdu();
        take(upPkt);

        // TODO: upPkt->info()
        EV << "LteMacBase: pduUnmaker extracted SDU" << endl;
        sendUpperPackets(upPkt);
    }

    while (macPkt->hasCe())
    {
        // Extract CE
        // TODO: vedere se bsr  per cid o lcid
        MacBsr* bsr = check_and_cast<MacBsr*>(macPkt->popCe());
        UserControlInfo* lteInfo = check_and_cast<UserControlInfo*>(macPkt->getControlInfo());
        MacCid cid = idToMacCid(lteInfo->getSourceId(), 0);
        bufferizeBsr(bsr, cid);
        delete bsr;
    }

    ASSERT(macPkt->getOwner() == this);
    delete macPkt;

}

int LteMacEnb::getNumRbDl()
{
    return numRbDl_;
}

int LteMacEnb::getNumRbUl()
{
    return numRbUl_;
}

bool LteMacEnb::bufferizePacket(cPacket* pkt)
{
    FlowControlInfo* lteInfo = check_and_cast<FlowControlInfo*>(pkt->getControlInfo());
    MacCid cid = idToMacCid(lteInfo->getDestId(), lteInfo->getLcid());
    OmnetId id = getBinder()->getOmnetId(lteInfo->getDestId());
    if(id == 0){
        // destination UE has left the simulation
        delete pkt;
        return false;
    }
    bool ret = false;

    if ((ret = LteMacBase::bufferizePacket(pkt)))
    {
        enbSchedulerDl_->backlog(cid);
    }
    return ret;
}

void LteMacEnb::handleUpperMessage(cPacket* pkt)
{
    FlowControlInfo* lteInfo = check_and_cast<FlowControlInfo*>(pkt->getControlInfo());
    MacCid cid = idToMacCid(lteInfo->getDestId(), lteInfo->getLcid());
    if (LteMacBase::bufferizePacket(pkt))
    {
        enbSchedulerDl_->backlog(cid);
    }
}

void LteMacEnb::handleSelfMessage()
{
    /***************
     *  MAIN LOOP  *
     ***************/
//    std::cout << "TTI: " << NOW << endl;

    EnbType nodeType = deployer_->getEnbType();

    EV << "-----" << ((nodeType==MACRO_ENB)?"MACRO":"MICRO") << " ENB MAIN LOOP -----" << endl;

    EV << "EM LTEMACENB\n";
    /*************
     * END DEBUG
     *************/

    /* Reception */

    // extract pdus from all harqrxbuffers and pass them to unmaker
    HarqRxBuffers::iterator hit = harqRxBuffers_.begin();
    HarqRxBuffers::iterator het = harqRxBuffers_.end();
    LteMacPdu *pdu = NULL;
    std::list<LteMacPdu*> pduList;

    for (; hit != het; hit++)
    {
        pduList = hit->second->extractCorrectPdus();
        while (!pduList.empty())
        {
            pdu = pduList.front();
            pduList.pop_front();
            macPduUnmake(pdu);
        }
    }

    /*UPLINK*/
    EV << "============================================== UPLINK ==============================================" << endl;
    //TODO enable sleep mode also for UPLINK???
    (enbSchedulerUl_->resourceBlocks()) = getNumRbUl();

    enbSchedulerUl_->updateHarqDescs();

    LteMacScheduleList* scheduleListUl = enbSchedulerUl_->schedule();
    // send uplink grants to PHY layer
    sendGrants(scheduleListUl);
    EV << "============================================ END UPLINK ============================================" << endl;

    EV << "============================================ DOWNLINK ==============================================" << endl;
    /*DOWNLINK*/
    // Set current available OFDM space
    (enbSchedulerDl_->resourceBlocks()) = getNumRbDl();

    // use this flag to enable/disable scheduling...don't look at me, this is very useful!!!
    bool activation = true;

    if (activation)
    {
        // perform Downlink scheduling
        LteMacScheduleList* scheduleListDl = enbSchedulerDl_->schedule();
        // creates pdus from schedule list and puts them in harq buffers
        macPduMake(scheduleListDl);
    }
    EV << "========================================== END DOWNLINK ============================================" << endl;

    // purge from corrupted PDUs all Rx H-HARQ buffers for all users
    for (hit = harqRxBuffers_.begin(); hit != het; hit++)
    {
        hit->second->purgeCorruptedPdus();
    }

    // flush Tx H-ARQ buffers for all users
    HarqTxBuffers::iterator it;
    for (it = harqTxBuffers_.begin(); it != harqTxBuffers_.end(); it++)
        it->second->sendSelectedDown();

    EV << "--- END " << ((nodeType==MACRO_ENB)?"MACRO":"MICRO") << " ENB MAIN LOOP ---" << endl;
}

void LteMacEnb::macHandleFeedbackPkt(cPacket *pkt)
{

    EV << "At LteMacEnb::macHandleFeedbackPkt\n";
    LteFeedbackPkt* fb = check_and_cast<LteFeedbackPkt*>(pkt);
    LteFeedbackDoubleVector fbMapDl = fb->getLteFeedbackDoubleVectorDl();
    LteFeedbackDoubleVector fbMapUl = fb->getLteFeedbackDoubleVectorUl();
    //get Source Node Id<
    MacNodeId id = fb->getSourceNodeId();
    LteFeedbackDoubleVector::iterator it;
    LteFeedbackVector::iterator jt;

    for (it = fbMapDl.begin(); it != fbMapDl.end(); ++it)
    {
        unsigned int i = 0;
        for (jt = it->begin(); jt != it->end(); ++jt)
        {
            //            TxMode rx=(TxMode)i;
            if (!jt->isEmptyFeedback())
            {
                amc_->pushFeedback(id, DL, (*jt));
                cqiStatistics(id, DL, (*jt));
            }
            i++;
        }
    }
    for (it = fbMapUl.begin(); it != fbMapUl.end(); ++it)
    {
        for (jt = it->begin(); jt != it->end(); ++jt)
        {
            if (!jt->isEmptyFeedback())
                amc_->pushFeedback(id, UL, (*jt));
        }
    }
    delete fb;
}

void LteMacEnb::updateUserTxParam(cPacket* pkt)
{
    UserControlInfo *lteInfo = check_and_cast<UserControlInfo *>(
        pkt->getControlInfo());

    if (lteInfo->getFrameType() != DATAPKT)
        return; // TODO check if this should be removed.

    Direction dir = (Direction) lteInfo->getDirection();

    const UserTxParams& newParam = amc_->computeTxParams(lteInfo->getDestId(), dir);
    UserTxParams* tmp = new UserTxParams(newParam);

    lteInfo->setUserTxParams(tmp);
    RbMap rbMap;
    lteInfo->setTxMode(newParam.readTxMode());
    LteSchedulerEnb* scheduler = ((dir == DL) ? (LteSchedulerEnb*) enbSchedulerDl_ : (LteSchedulerEnb*) enbSchedulerUl_);

    int grantedBlocks = scheduler->readRbOccupation(lteInfo->getDestId(), rbMap);

    lteInfo->setGrantedBlocks(rbMap);
    lteInfo->setTotalGrantedBlocks(grantedBlocks);
}
ActiveSet LteMacEnb::getActiveSet(Direction dir)
{
    if (dir == DL)
        return enbSchedulerDl_->readActiveConnections();
    else
        return enbSchedulerUl_->readActiveConnections();
}
void LteMacEnb::allocatedRB(unsigned int rb)
{
    lastTtiAllocatedRb_ = rb;
}

void LteMacEnb::cqiStatistics(MacNodeId id, Direction dir, LteFeedback fb)
{
    if (dir == DL)
    {
        tSample_->id_ = id;
        if (fb.getTxMode() == SINGLE_ANTENNA_PORT0)
        {
            for (unsigned int i = 0; i < fb.getBandCqi(0).size(); i++)
            {
                switch (i)
                {
                    case 0:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlSiso0_, tSample_);
                        break;
                    case 1:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlSiso1_, tSample_);
                        break;
                    case 2:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlSiso2_, tSample_);
                        break;
                    case 3:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlSiso3_, tSample_);
                        break;
                    case 4:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlSiso4_, tSample_);
                        break;
                }
            }
        }
        else if (fb.getTxMode() == TRANSMIT_DIVERSITY)
        {
            for (unsigned int i = 0; i < fb.getBandCqi(0).size(); i++)
            {
                switch (i)
                {
                    case 0:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlTxDiv0_, tSample_);
                        break;
                    case 1:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlTxDiv1_, tSample_);
                        break;
                    case 2:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlTxDiv2_, tSample_);
                        break;
                    case 3:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlTxDiv3_, tSample_);
                        break;
                    case 4:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlTxDiv4_, tSample_);
                        break;
                }
            }
        }
        else if (fb.getTxMode() == OL_SPATIAL_MULTIPLEXING)
        {
            for (unsigned int i = 0; i < fb.getBandCqi(0).size(); i++)
            {
                switch (i)
                {
                    case 0:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlSpmux0_, tSample_);
                        break;
                    case 1:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlSpmux1_, tSample_);
                        break;
                    case 2:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlSpmux2_, tSample_);
                        break;
                    case 3:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlSpmux3_, tSample_);
                        break;
                    case 4:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlSpmux4_, tSample_);
                        break;
                }
            }
        }
        else if (fb.getTxMode() == MULTI_USER)
        {
            for (unsigned int i = 0; i < fb.getBandCqi(0).size(); i++)
            {
                switch (i)
                {
                    case 0:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlMuMimo0_, tSample_);
                        break;
                    case 1:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlMuMimo1_, tSample_);
                        break;
                    case 2:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlMuMimo2_, tSample_);
                        break;
                    case 3:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlMuMimo3_, tSample_);
                        break;
                    case 4:
                        tSample_->sample_ = fb.getBandCqi(0)[i];
                        emit(cqiDlMuMimo4_, tSample_);
                        break;
                }
            }
        }
    }
}

unsigned int LteMacEnb::getBandStatus(Band b)
{
    unsigned int i = enbSchedulerDl_->readPerBandAllocatedBlocks(MAIN_PLANE, MACRO, b);
    return i;
}

unsigned int LteMacEnb::getPrevBandStatus(Band b)
{
    unsigned int i = enbSchedulerDl_->getInterferringBlocks(MAIN_PLANE, MACRO, b);
    return i;
}

