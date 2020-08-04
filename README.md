SimuLTE
=======

LTE user plane simulation model, compatible with the INET Framework.


Features
--------

General

- eNodeB and UE models
- Form-based configuration editor

PDCP-RRC

- Header compression/decompression
- Logical connection establishment  and maintenance 

RLC

- Multiplexing/Demultiplexing of MAC SDUs
- UM, (AM and TM testing) modes

MAC

- RLC PDUs buffering
- HARQ functionalities (with multi-codeword support)
- Allocation management
- AMC
- Scheduling Policies (MAX C/I, Proportional Fair, DRR)

PHY

- Heterogeneous Net (HetNets) support: Macro, micro, pico eNbs
- Channel Feedback management
- Dummy channel model
- Realistic channel model with
  - cell interference
  - path-loss
  - fast fading
  - shadowing 
  - (an-isotropic antennas - work in progress)

Other

- X2 communication support
- (Relay support - work in progress)
- Distributed Antenna System - DAS (Testing)

Applications

- VoIP
- Gaming
- Trace Based traffic


Limitations
-----------

- User Plane only (Control Plane not modeled)
- FDD only (TDD not supported)
- no EPS bearer support – note: a similar concept, "connections", has 
  been implemented, but they are neither dynamic nor statically 
  configurable via some config file
- radio bearers not implemented, not even statically configured radio 
  bearers (dynamically allocating bearers would need the RRC protocol, 
  which is Control Plane so not implemented)
- handovers not implemented (no X2-based handover, that is; S1-based 
  handover would require an S-GW model)


Using the configuration editor
------------------------------

SimuLTE also contains a form-based configuration editor to edit the most 
often used simulation parameters. To use it, right-click an Ini file, and choose
'Open With | SimuLTE Configuration Editor' from the context menu. Try it on 
'simulations/demo/gui.ini'.


ricardopmarinho modifications:

If you want to run a scenario with one BS use the CAINsimple configuration
- do not change the value of 'numEnB', it will not work;
- if you want to use more BSs, use the CAIN configuration
If you want to run a scenario with more than one BS, adjust the number of BS with the parameter numEnB at the CAIN configuration.

PATH: MY_USER/omnetpp-5.0/samples/simulte


CAIN changes:
pwrThresh definition on PATH/simulations/networks/CAIN.ned - line 35

Network definition file CAIN.ned on PATH/simulations/networks

CAIN node CAIN_UE.ned on PATH/src/corenetwork/nodes

CAINLteRealisticChannelModel.cc and .h on PATH/src/stack/phy/ChannelModel

Included CAINControlInfo class on PATH/src/common/LteControlInfo.msg

Included CAINControlInfo class on PATH/scr/common/LteControlInfo.cc and .h

Included CAINLtePhyUe simple module on PATH/src/stack/phy/LtePhy.ned

Created CAINLtePhyUe.cc and .h on PATH/scr/stack/phy/layer

Included code at the end of PATH/src/stack/phy/layer/LtePhyUeD2D.cc to send the CAINControlInfo and included CAINControlInfo.h on it

included code to store sinr value on table at PATH/src/stack/phy/ChannelModels/LteRealisticChannelModel.cc lines 893~918

created types sinrMapB and sinrMapW and included them on the struct EnbInfo at PATH/src/common/LteCommon.h

Included code on PATH/scr/stack/mac/layer/LteMacUeRealisticSD2D.cc::checkRAC (line 441)=>lines 499 to 534

Included code on PATH/src/stack/mac/layer/LteMacEnb.cc::macHandleRac(line 456)=>lines 460

Included a new LtEPhyFrameType on line 463 from PATH/src/common/LteCommon.h=>CAIN_INFOPKT

Created a new enum type=>CAINDirection (REL, REP, NOTIFY and FWD) on PATH/src/common/LteCommon.h lines 121 to 125

Included parameter "pwrThresh" on PATH/simulations/networks/CAIN.ned=>line 35

Included code on PATH/src/stack/phy/layer/LtePhyEnbD2D.cc=>lines 302-305 (line 307 is from original code) 

Included method handleCainInfoPkt on PATH/src/stack/phy/layer/LtePhyEnb.h and .cc

Included code on PATH/src/stack/phy/layer/LtePhyBase.cc on method LtePhyBase::handleUpperMessage (linha 130) lines 138~144

Created methods getCAINOptions() (lines 76~78), appendOption() (lines 69~74) and setOption() (lines 80~82) on PATH/src/commom/LteControlInfo.cc and  .h lines 109~113

Included std::string CAINoptions (line 38) on PATH/src/commom/LteControlInfo.h

Included code on PATH/src/stack/mac/layer/LteMacEnb.cc lines 476~510

Included  code on PATH/src/commom/LteControlInfo.msg lines 140 and 141

Included code on PATH/src/stack/mac/layer/LteMacUeRealisticD2D.cc lines 518~525

Added two methos od PATH/src/stack/mac/layer/LteMacUeRealisticD2D.cc and .h (handleCainMsg -line 567 .cc and  line 69 .h, getRelay - line 598 .cc line 74 .h getNode line 665 .cc line 79 .h)

Added code on PATH/src/stack/mac/layer/LteMacBase.cc lines 90~93 and 162

Added cainMessage signal on PATH/src/stack/mac/LteMac.ned (lines 138 and 139), PATH/src/stack/mac/layer/LteMacEnb.cc and .h (lines 468~471 and lines 61~64)

Modifications on PATH/src/stack/mac/layer/LteMacEnb.cc to send more than one message (lines 521~534)

Added std::map<MacNodeId, const char*> UesIdToName_ on PATH/src/corenetwork/binder/LteBinder.h (line 57) to map the UEs node id to their names

Added addNodeIdName(MacNodeId nodeId,const char* name) and getUeNodeNameById(MacNodeId nodeId) on PATH/src/corenetwork/binder/LteBinder.h (lines 276~284)

Added code on PATH/src/stack/mac/layer/LteMacUe.cc (lines 92~95)

Added code on PATH/src/stack/mac/layer/LteMacUeRealisticD2D.cc (lines 600~603)

Added LteMacUeRealisticD2D::handleCainMsg on PATH/src/stack/mac/layer/LteMacUeRealisticD2D.cc (line 569)

Added MASSIVEMIMO enum at PATH/src/commom/LteCommon.h (lines 286 and 298)

Modified PATH/src/stack/phy/LtePhy.ned line 40 and included "MASSIVEMIMO" as default (original was OMNI)

Added code on PATH/src/stack/phy/layer/LtePhyEnb.cc (lines 71, 77~79)

Modified PATH/src/stack/phy/layer/LtePhUeD2D.cc::sendFeedback() to scenarios with two BSs

Modified PATH/src/stack/phy/layer/LtePhyBase.cc::sendBroadcast() (line239)
	Added code to broadcast feedback pkt
	comented line sendToChannel(airFrame);

Added sendBroadcast() (line 559) to PATH/src/stack/phy/layer/LtePhUeD2D.cc::sendFeedback()

Added code on PATH/src/stack/phy/layer/LtePhUeD2D.cc::handleAirFrame()
	if(lteInfo->getFrameType()== FEEDBACKPKT && destId != 1){
		binder_->updateSocialMap(destId,sourceId);
		delete lteInfo;
		return;
    	}

Added coe on PATH/src/corenetwork/binder/LteBinder.cc
	void LteBinder::updateSocialMap(MacNodeId ueId, MacNodeId senderId, int qtd){
		std::vector<UeInfo*>* vect = this->getUeList();
		for(unsigned int i = 0; i < vect->size();i++){
			if(ueId == vect->at(i)->id){
				if(senderId != 1)
					vect->operator [](i)->socialMap->operator [](senderId)++;
			}
		}
			printSocialMap(ueId);
	}

	void LteBinder::printSocialMap(MacNodeId ueId){
	    std::vector<UeInfo*>* vect = this->getUeList();
	    EV << "Social Graph from device " << ueId << ":" << endl;
	    for(unsigned int i = 0; i < vect->size();i++){
		if(ueId == vect->at(i)->id){
		    socialGraph::iterator it = vect->operator [](i)->socialMap->begin();
		    socialGraph::iterator itEnd = vect->operator [](i)->socialMap->end();
		    for(;it != itEnd; it++)
			EV << it->first << ": " << it->second << endl;
		}
	    }
	}

Added socialGraph* socialMap to UeInfo on PATH/scr/common/LteCommon.h
	and typedef std::map<MacNodeId,unsigned int> socialGraph;

Included SOC_NTF and SOC_FWD to CAINDirection (PATH/src/common/LteCommon.h line 122) so I don't have to modify the message struct

Included social statistic to PATH/src/stack/mac/LteMac.ned (lines 175 and 176)

Added code to PATH/src/stack/mac/layer/LteMacUeRealisticD2D.cc::checkRAC() (line 549)
	else if(networkType == "Social"){
		MacNodeId destId = binder_->checkSocialId(nodeId_);
		if(destId != getMacCellId()){
		binder_->updateSocialMap(nodeId_,destId,2);
		uinfo->setDestId(destId);
		uinfo->setCAINEnable(true);
		uinfo->setCAINDirection(SOC_NTF);
		uinfo->setCAINOption("");
	}

and void LteMacUeRealisticD2D::handleCainMsg(cPacket* pkt) line 963
case SOC_NTF:
{
	MacNodeId enbId = binder_->getEnbToUe(uinfo->getSourceId());

	EV << "Social notify message arrived from node " << uinfo->getSourceId() << " to"
	" node " << uinfo->getDestId() << endl;

	binder_->updateSocialMap(uinfo->getDestId(),uinfo->getSourceId(),2);
	uinfo->setCAINOption("");
	uinfo->setSourceId(uinfo->getDestId());
	uinfo->setDestId(enbId);
	uinfo->setCAINDirection(SOC_FWD);
	uinfo->setDirection(UL);
	sendLowerPackets(racPkt);
}


Added code to PATH/src/mac/layer/LteMacEnb.cc::macHandleRac(cPacket* pkt)
case SOC_FWD: (line 639)
{
	EV << "Social forward message arrived from node " << uinfo->getSourceId() << " to"
	    " node " << uinfo->getDestId() << endl;
	socialMsg++;
	emit(socialMsgSignal,socialMsg);
	delete pkt;
	return;
}

Adde code to PATH/src/corenetwork/binder/LteBinder.cc
MacNodeId LteBinder::checkSocialId(MacNodeId nodeId){ (line 1152)
    std::vector<EnbInfo*>* vect = this->getEnbList();
    MacNodeId enbId = getEnbToUe(nodeId);
    MacNodeId destId = enbId;
    for(unsigned int i = 0; i < vect->size();i++){
        if(enbId == vect->at(i)->id){
            UeAreaMap* ueMap = vect->operator [](i)->mapUe;
            int area = ueMap->operator [](nodeId);
            EV << "The area is: " << area << endl;
            switch (area) {
            case 1:
                break;
            case 2:
                MacNodeId relayId = findSocialRelay(nodeId);
                if(relayId != 0){
                    destId=relayId;
                }
            }
        }
    }
    return destId;
}

MacNodeId LteBinder::findSocialRelay(MacNodeId nodeId){ (line 1175)

    std::vector<EnbInfo*>* vectEnb = this->getEnbList();
    MacNodeId enbId = getEnbToUe(nodeId);
    UeAreaMap* ueMap;
    for(unsigned int i = 0; i < vectEnb->size();i++){
        if(enbId == vectEnb->at(i)->id){
            ueMap = vectEnb->operator [](i)->mapUe;
            break;
        }
    }

    std::vector<UeInfo*>* vect = this->getUeList();
    unsigned int social = 0;
    EV << "Node id: " << nodeId << endl;
    MacNodeId relayId = 0;
    for(unsigned int i = 0; i < vect->size();i++){
        if(nodeId == vect->at(i)->id){
            socialGraph::iterator it = vect->at(i)->socialMap->begin();
            socialGraph::iterator itEnd = vect->operator [](i)->socialMap->end();
            for(;it != itEnd; it++){
                int area = ueMap->operator [](it->first);
                if((area == 1) && (it->second > social)){
                    relayId = it->first;
                    social = it->second;
                }
            }
            break;
        }
    }
    return relayId;
}
========================== CAIN msg =========================
---------------------------------------------
|Source|Destination|eNB ID|Direction|Options|
---------------------------------------------

========================== SO FAR ==========================

social graph working with 3 devices

========================== NEXT ============================

test with more devices

========================== LAST UPDATE======================

Jun 3th 2020

