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
Network definition file CAIN.ned on PATH/simulations/networks

CAIN node CAIN_UE.ned on PATH/src/corenetwork/nodes

CAINLteRealisticChannelModel.cc and .h on PATH/src/stack/phy/ChannelModel

Included CAINControlInfo class on PATH/src/common/LteControlInfo.msg

Included CAINControlInfo class on PATH/scr/common/LteControlInfo.cc and .h

Included CAINLtePhyUe simple module on PATH/src/stack/phy/LtePhy.ned

Created CAINLtePhyUe.cc and .h on PATH/scr/stack/phy/layer

Included code at the end of PATH/src/stack/phy/layer/LtePhyUeD2D.cc to send the CAINControlInfo and included CAINControlInfo.h on it

included code to store sinr value on table at PATH/src/stack/phy/ChannelModels/LteRealisticChannelModel.cc lines 894~904

created a type sinrMap and included it on the struct EnbInfo at PATH/src/common/LteCommon.h

Included code on PATH/scr/stack/phy/layer/LteMacUeRealisticSD2D.cc::checkRAC (line 441)=>lines 499 to 534

Included code on PATH/src/stack/mac/layer/LteMacEnb.cc::macHandleRac(line 456)=>lines 460, 466 to 481

Included a new LtEPhyFrameType on line 463 from PATH/src/common/LteCommon.h=>CAIN_INFOPKT

Created a new enum type=>CAINDirection (REL, REP and NOTiFY) on PATH/src/common/LteCommon.h lines 121 to 125

Included parameter "pwrThresh" on PATH/simulations/networks/CAIN.ned=>line 35

>>>>>>> 4cbe087e605fb1c675305b54f533c6a9832b3fc9
