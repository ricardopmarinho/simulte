<<<<<<< HEAD
SimuLTE
=======

LTE user plane simulation model, compatible with the INET Framework.

Dependencies
------------

The current master/head version requires either of

- OMNeT++ 5.0 and INET 3.4
- OMNeT++ 5.1 and INET 3.5

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
=======
# simulte
Adding CAIN network to simulte project

DO NOT copy this project yet. I'm still implementing it and it's just begining.

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

created types sinrMapB and sinrMapW and included it on the struct EnbInfo at PATH/src/common/LteCommon.h

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

========================== CAIN msg =========================
---------------------------------------------
|Source|Destination|eNB ID|Direction|Options|
---------------------------------------------


========================== SO FAR ==========================

modified local and connect address for UEs

========================== NEXT ============================

Adjust connect address when cain messages arrive

========================== LAST UPDATE =====================

07/04/2019 - August 29th


