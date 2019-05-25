#
# OMNeT++/OMNEST Makefile for libsimulte
#
# This file was generated with the command:
#  opp_makemake -f --deep --make-so -O out -I../../inet/src -L../../inet/out/$$\(CONFIGNAME\)/src -lINET -KINET_PROJ=../../inet
#

# Name of target to be created (-o option)
TARGET = libsimulte$(SHARED_LIB_SUFFIX)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../../inet/src \
    -I. \
    -Iapps \
    -Iapps/alert \
    -Iapps/vod \
    -Iapps/voip \
    -Icommon \
    -Icommon/timer \
    -Icorenetwork \
    -Icorenetwork/binder \
    -Icorenetwork/deployer \
    -Icorenetwork/lteip \
    -Icorenetwork/nodes \
    -Iepc \
    -Iepc/gtp \
    -Istack \
    -Istack/compManager \
    -Istack/compManager/compManagerProportional \
    -Istack/d2dModeSelection \
    -Istack/d2dModeSelection/d2dModeSelectionBestCqi \
    -Istack/handoverManager \
    -Istack/mac \
    -Istack/mac/allocator \
    -Istack/mac/amc \
    -Istack/mac/buffer \
    -Istack/mac/buffer/harq \
    -Istack/mac/buffer/harq_d2d \
    -Istack/mac/layer \
    -Istack/mac/packet \
    -Istack/mac/scheduler \
    -Istack/mac/scheduling_modules \
    -Istack/pdcp_rrc \
    -Istack/pdcp_rrc/layer \
    -Istack/pdcp_rrc/layer/entity \
    -Istack/pdcp_rrc/packet \
    -Istack/phy \
    -Istack/phy/ChannelModel \
    -Istack/phy/das \
    -Istack/phy/feedback \
    -Istack/phy/feedback/testFeedback \
    -Istack/phy/layer \
    -Istack/phy/packet \
    -Istack/rlc \
    -Istack/rlc/am \
    -Istack/rlc/am/buffer \
    -Istack/rlc/am/packet \
    -Istack/rlc/packet \
    -Istack/rlc/tm \
    -Istack/rlc/um \
    -Istack/rlc/um/buffer \
    -Istack/rlc/um/entity \
    -Iworld \
    -Iworld/radio \
    -Ix2 \
    -Ix2/packet

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../../inet/out/$(CONFIGNAME)/src  -lINET
LIBS += -Wl,-rpath,`abspath ../../inet/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS = \
    $O/apps/alert/AlertSender.o \
    $O/apps/alert/AlertReceiver.o \
    $O/apps/vod/VoDUDPClient.o \
    $O/apps/vod/VoDUDPServer.o \
    $O/apps/voip/VoIPReceiver.o \
    $O/apps/voip/VoIPSender.o \
    $O/common/lterecorder.o \
    $O/common/LteControlInfo.o \
    $O/common/LteCommon.o \
    $O/common/timer/TTimer.o \
    $O/corenetwork/binder/PhyPisaData.o \
    $O/corenetwork/binder/LteBinder.o \
    $O/corenetwork/deployer/LteDeployer.o \
    $O/corenetwork/lteip/IP2lte.o \
    $O/corenetwork/lteip/InternetQueue.o \
    $O/corenetwork/lteip/LteIp.o \
    $O/corenetwork/nodes/UnUuMux.o \
    $O/corenetwork/nodes/InternetMux.o \
    $O/corenetwork/nodes/ExtCell.o \
    $O/epc/TrafficFlowFilterSimplified.o \
    $O/epc/gtp_common.o \
    $O/epc/TrafficFlowFilter.o \
    $O/epc/gtp/TftControlInfo.o \
    $O/epc/gtp/GtpUserX2.o \
    $O/epc/gtp/GtpUser.o \
    $O/epc/gtp/GtpUserSimplified.o \
    $O/stack/compManager/LteCompManagerBase.o \
    $O/stack/compManager/compManagerProportional/LteCompManagerProportional.o \
    $O/stack/d2dModeSelection/D2DModeSelectionBase.o \
    $O/stack/d2dModeSelection/d2dModeSelectionBestCqi/D2DModeSelectionBestCqi.o \
    $O/stack/handoverManager/LteHandoverManager.o \
    $O/stack/mac/allocator/LteAllocationModule.o \
    $O/stack/mac/amc/AmcPilotD2D.o \
    $O/stack/mac/amc/LteAmc.o \
    $O/stack/mac/amc/AmcPilotAuto.o \
    $O/stack/mac/amc/LteMcs.o \
    $O/stack/mac/buffer/LteMacBuffer.o \
    $O/stack/mac/buffer/LteMacQueue.o \
    $O/stack/mac/buffer/harq/LteHarqProcessTx.o \
    $O/stack/mac/buffer/harq/LteHarqProcessRx.o \
    $O/stack/mac/buffer/harq/LteHarqBufferTx.o \
    $O/stack/mac/buffer/harq/LteHarqUnitTx.o \
    $O/stack/mac/buffer/harq/LteHarqBufferRx.o \
    $O/stack/mac/buffer/harq_d2d/LteHarqProcessRxD2D.o \
    $O/stack/mac/buffer/harq_d2d/LteHarqUnitTxD2D.o \
    $O/stack/mac/buffer/harq_d2d/LteHarqBufferRxD2D.o \
    $O/stack/mac/buffer/harq_d2d/LteHarqBufferRxD2DMirror.o \
    $O/stack/mac/buffer/harq_d2d/LteHarqBufferTxD2D.o \
    $O/stack/mac/buffer/harq_d2d/LteHarqProcessRxD2DMirror.o \
    $O/stack/mac/buffer/harq_d2d/LteHarqProcessTxD2D.o \
    $O/stack/mac/layer/LteMacUeRealistic.o \
    $O/stack/mac/layer/LteMacUe.o \
    $O/stack/mac/layer/LteMacUeD2D.o \
    $O/stack/mac/layer/LteMacRelayUe.o \
    $O/stack/mac/layer/LteMacEnbRealistic.o \
    $O/stack/mac/layer/LteMacEnbD2D.o \
    $O/stack/mac/layer/LteMacRelayEnb.o \
    $O/stack/mac/layer/LteMacBase.o \
    $O/stack/mac/layer/LteMacEnb.o \
    $O/stack/mac/layer/LteMacEnbRealisticD2D.o \
    $O/stack/mac/layer/LteMacUeRealisticD2D.o \
    $O/stack/mac/scheduler/LteSchedulerEnbUl.o \
    $O/stack/mac/scheduler/LteScheduler.o \
    $O/stack/mac/scheduler/LteSchedulerUeUl.o \
    $O/stack/mac/scheduler/LcgSchedulerRealistic.o \
    $O/stack/mac/scheduler/LteSchedulerEnbDl.o \
    $O/stack/mac/scheduler/LteSchedulerEnb.o \
    $O/stack/mac/scheduler/LcgScheduler.o \
    $O/stack/mac/scheduler/LteSchedulerEnbDlRealistic.o \
    $O/stack/mac/scheduling_modules/LteMaxCiOptMB.o \
    $O/stack/mac/scheduling_modules/LteMaxCiComp.o \
    $O/stack/mac/scheduling_modules/LteMaxCi.o \
    $O/stack/mac/scheduling_modules/LteDrr.o \
    $O/stack/mac/scheduling_modules/LteMaxCiMultiband.o \
    $O/stack/mac/scheduling_modules/LtePf.o \
    $O/stack/pdcp_rrc/ConnectionsTable.o \
    $O/stack/pdcp_rrc/layer/LtePdcpRrc.o \
    $O/stack/pdcp_rrc/layer/LtePdcpRrcEnbD2D.o \
    $O/stack/pdcp_rrc/layer/LtePdcpRrcUeD2D.o \
    $O/stack/pdcp_rrc/layer/entity/LtePdcpEntity.o \
    $O/stack/phy/ChannelModel/LteChannelModel.o \
    $O/stack/phy/ChannelModel/CAINLteRealisticChannelModel.o \
    $O/stack/phy/ChannelModel/LteRealisticChannelModel.o \
    $O/stack/phy/ChannelModel/LteDummyChannelModel.o \
    $O/stack/phy/das/DasFilter.o \
    $O/stack/phy/das/RemoteAntennaSet.o \
    $O/stack/phy/feedback/LteFeedbackComputationDummy.o \
    $O/stack/phy/feedback/LteFeedback.o \
    $O/stack/phy/feedback/LteFeedbackComputation.o \
    $O/stack/phy/feedback/LteDlFeedbackGenerator.o \
    $O/stack/phy/feedback/LteFeedbackComputationRealistic.o \
    $O/stack/phy/feedback/testFeedback/FeedbackTester.o \
    $O/stack/phy/layer/LtePhyEnb.o \
    $O/stack/phy/layer/LtePhyEnbD2D.o \
    $O/stack/phy/layer/LtePhyUeD2D.o \
    $O/stack/phy/layer/CAINLtePhyUe.o \
    $O/stack/phy/layer/LtePhyBase.o \
    $O/stack/phy/layer/LtePhyRelay.o \
    $O/stack/phy/layer/LtePhyUe.o \
    $O/stack/phy/packet/LteAirFrame.o \
    $O/stack/phy/packet/LteFeedbackPkt.o \
    $O/stack/rlc/LteRlcMux.o \
    $O/stack/rlc/am/LteRlcAm.o \
    $O/stack/rlc/am/buffer/AmRxQueue.o \
    $O/stack/rlc/am/buffer/AmTxQueue.o \
    $O/stack/rlc/am/packet/LteRlcAmPdu.o \
    $O/stack/rlc/packet/LteRlcDataPdu.o \
    $O/stack/rlc/tm/LteRlcTm.o \
    $O/stack/rlc/um/LteRlcUmRealisticD2D.o \
    $O/stack/rlc/um/LteRlcUmRealistic.o \
    $O/stack/rlc/um/LteRlcUm.o \
    $O/stack/rlc/um/buffer/UmFragbuf.o \
    $O/stack/rlc/um/buffer/UmRxQueue.o \
    $O/stack/rlc/um/buffer/UmTxQueue.o \
    $O/stack/rlc/um/entity/UmTxEntity.o \
    $O/stack/rlc/um/entity/UmRxEntity.o \
    $O/world/radio/LteChannelControl.o \
    $O/world/radio/ChannelControl.o \
    $O/world/radio/ChannelAccess.o \
    $O/x2/LteX2Manager.o \
    $O/x2/X2AppClient.o \
    $O/x2/X2AppServer.o \
    $O/apps/alert/AlertPacket_m.o \
    $O/apps/vod/VoDPacket_m.o \
    $O/apps/vod/M1Message_m.o \
    $O/apps/voip/VoipPacket_m.o \
    $O/common/LteControlInfo_m.o \
    $O/common/CAINInfo_m.o \
    $O/common/timer/TMultiTimerMsg_m.o \
    $O/common/timer/TTimerMsg_m.o \
    $O/epc/gtp/GtpUserMsg_m.o \
    $O/stack/d2dModeSelection/D2DModeSwitchNotification_m.o \
    $O/stack/mac/packet/LteSchedulingGrant_m.o \
    $O/stack/mac/packet/LteRac_m.o \
    $O/stack/mac/packet/LteMacSduRequest_m.o \
    $O/stack/mac/packet/LteHarqFeedback_m.o \
    $O/stack/mac/packet/LteMacPdu_m.o \
    $O/stack/pdcp_rrc/packet/LtePdcpPdu_m.o \
    $O/stack/phy/packet/LteFeedbackPkt_m.o \
    $O/stack/phy/packet/LteAirFrame_m.o \
    $O/stack/phy/packet/AirFrame_m.o \
    $O/stack/rlc/am/packet/LteRlcAmSdu_m.o \
    $O/stack/rlc/am/packet/LteRlcAmPdu_m.o \
    $O/stack/rlc/packet/LteRlcPdu_m.o \
    $O/stack/rlc/packet/LteRlcDataPdu_m.o \
    $O/stack/rlc/packet/LteRlcSdu_m.o \
    $O/x2/packet/X2ControlInfo_m.o \
    $O/x2/packet/LteX2Message_m.o

# Message files
MSGFILES = \
    apps/alert/AlertPacket.msg \
    apps/vod/VoDPacket.msg \
    apps/vod/M1Message.msg \
    apps/voip/VoipPacket.msg \
    common/LteControlInfo.msg \
    common/CAINInfo.msg \
    common/timer/TMultiTimerMsg.msg \
    common/timer/TTimerMsg.msg \
    epc/gtp/GtpUserMsg.msg \
    stack/d2dModeSelection/D2DModeSwitchNotification.msg \
    stack/mac/packet/LteSchedulingGrant.msg \
    stack/mac/packet/LteRac.msg \
    stack/mac/packet/LteMacSduRequest.msg \
    stack/mac/packet/LteHarqFeedback.msg \
    stack/mac/packet/LteMacPdu.msg \
    stack/pdcp_rrc/packet/LtePdcpPdu.msg \
    stack/phy/packet/LteFeedbackPkt.msg \
    stack/phy/packet/LteAirFrame.msg \
    stack/phy/packet/AirFrame.msg \
    stack/rlc/am/packet/LteRlcAmSdu.msg \
    stack/rlc/am/packet/LteRlcAmPdu.msg \
    stack/rlc/packet/LteRlcPdu.msg \
    stack/rlc/packet/LteRlcDataPdu.msg \
    stack/rlc/packet/LteRlcSdu.msg \
    x2/packet/X2ControlInfo.msg \
    x2/packet/LteX2Message.msg

# SM files
SMFILES =

# Other makefile variables (-K)
INET_PROJ=../../inet

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppenvir$D $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)
SMCOPTS =

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# inserted from file 'makefrag':
#
# on Windows we have to link with the winsock2 library as it is no longer added
# to the omnetpp system libraries by default (as of OMNeT++ 5.1)
#
ifeq ($(PLATFORM),win32.x86_64)
  LIBS += -lws2_32
endif

# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating shared library: $@
	$(Q)$(SHLIB_LD) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS) $(LDFLAGS)
	$(Q)$(SHLIB_POSTPROCESS) $O/$(TARGET)

.PHONY: all clean cleanall depend msgheaders smheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

%_sm.cc %_sm.h: %.sm
	$(qecho) SMC: $<
	$(Q)$(SMC) -c++ -suffix cc $(SMCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

smheaders: $(SMFILES:.sm=_sm.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f simulte simulte.exe libsimulte.so libsimulte.a libsimulte.dll libsimulte.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h ./*_sm.cc ./*_sm.h
	$(Q)-rm -f apps/*_m.cc apps/*_m.h apps/*_sm.cc apps/*_sm.h
	$(Q)-rm -f apps/alert/*_m.cc apps/alert/*_m.h apps/alert/*_sm.cc apps/alert/*_sm.h
	$(Q)-rm -f apps/vod/*_m.cc apps/vod/*_m.h apps/vod/*_sm.cc apps/vod/*_sm.h
	$(Q)-rm -f apps/voip/*_m.cc apps/voip/*_m.h apps/voip/*_sm.cc apps/voip/*_sm.h
	$(Q)-rm -f common/*_m.cc common/*_m.h common/*_sm.cc common/*_sm.h
	$(Q)-rm -f common/timer/*_m.cc common/timer/*_m.h common/timer/*_sm.cc common/timer/*_sm.h
	$(Q)-rm -f corenetwork/*_m.cc corenetwork/*_m.h corenetwork/*_sm.cc corenetwork/*_sm.h
	$(Q)-rm -f corenetwork/binder/*_m.cc corenetwork/binder/*_m.h corenetwork/binder/*_sm.cc corenetwork/binder/*_sm.h
	$(Q)-rm -f corenetwork/deployer/*_m.cc corenetwork/deployer/*_m.h corenetwork/deployer/*_sm.cc corenetwork/deployer/*_sm.h
	$(Q)-rm -f corenetwork/lteip/*_m.cc corenetwork/lteip/*_m.h corenetwork/lteip/*_sm.cc corenetwork/lteip/*_sm.h
	$(Q)-rm -f corenetwork/nodes/*_m.cc corenetwork/nodes/*_m.h corenetwork/nodes/*_sm.cc corenetwork/nodes/*_sm.h
	$(Q)-rm -f epc/*_m.cc epc/*_m.h epc/*_sm.cc epc/*_sm.h
	$(Q)-rm -f epc/gtp/*_m.cc epc/gtp/*_m.h epc/gtp/*_sm.cc epc/gtp/*_sm.h
	$(Q)-rm -f stack/*_m.cc stack/*_m.h stack/*_sm.cc stack/*_sm.h
	$(Q)-rm -f stack/compManager/*_m.cc stack/compManager/*_m.h stack/compManager/*_sm.cc stack/compManager/*_sm.h
	$(Q)-rm -f stack/compManager/compManagerProportional/*_m.cc stack/compManager/compManagerProportional/*_m.h stack/compManager/compManagerProportional/*_sm.cc stack/compManager/compManagerProportional/*_sm.h
	$(Q)-rm -f stack/d2dModeSelection/*_m.cc stack/d2dModeSelection/*_m.h stack/d2dModeSelection/*_sm.cc stack/d2dModeSelection/*_sm.h
	$(Q)-rm -f stack/d2dModeSelection/d2dModeSelectionBestCqi/*_m.cc stack/d2dModeSelection/d2dModeSelectionBestCqi/*_m.h stack/d2dModeSelection/d2dModeSelectionBestCqi/*_sm.cc stack/d2dModeSelection/d2dModeSelectionBestCqi/*_sm.h
	$(Q)-rm -f stack/handoverManager/*_m.cc stack/handoverManager/*_m.h stack/handoverManager/*_sm.cc stack/handoverManager/*_sm.h
	$(Q)-rm -f stack/mac/*_m.cc stack/mac/*_m.h stack/mac/*_sm.cc stack/mac/*_sm.h
	$(Q)-rm -f stack/mac/allocator/*_m.cc stack/mac/allocator/*_m.h stack/mac/allocator/*_sm.cc stack/mac/allocator/*_sm.h
	$(Q)-rm -f stack/mac/amc/*_m.cc stack/mac/amc/*_m.h stack/mac/amc/*_sm.cc stack/mac/amc/*_sm.h
	$(Q)-rm -f stack/mac/buffer/*_m.cc stack/mac/buffer/*_m.h stack/mac/buffer/*_sm.cc stack/mac/buffer/*_sm.h
	$(Q)-rm -f stack/mac/buffer/harq/*_m.cc stack/mac/buffer/harq/*_m.h stack/mac/buffer/harq/*_sm.cc stack/mac/buffer/harq/*_sm.h
	$(Q)-rm -f stack/mac/buffer/harq_d2d/*_m.cc stack/mac/buffer/harq_d2d/*_m.h stack/mac/buffer/harq_d2d/*_sm.cc stack/mac/buffer/harq_d2d/*_sm.h
	$(Q)-rm -f stack/mac/layer/*_m.cc stack/mac/layer/*_m.h stack/mac/layer/*_sm.cc stack/mac/layer/*_sm.h
	$(Q)-rm -f stack/mac/packet/*_m.cc stack/mac/packet/*_m.h stack/mac/packet/*_sm.cc stack/mac/packet/*_sm.h
	$(Q)-rm -f stack/mac/scheduler/*_m.cc stack/mac/scheduler/*_m.h stack/mac/scheduler/*_sm.cc stack/mac/scheduler/*_sm.h
	$(Q)-rm -f stack/mac/scheduling_modules/*_m.cc stack/mac/scheduling_modules/*_m.h stack/mac/scheduling_modules/*_sm.cc stack/mac/scheduling_modules/*_sm.h
	$(Q)-rm -f stack/pdcp_rrc/*_m.cc stack/pdcp_rrc/*_m.h stack/pdcp_rrc/*_sm.cc stack/pdcp_rrc/*_sm.h
	$(Q)-rm -f stack/pdcp_rrc/layer/*_m.cc stack/pdcp_rrc/layer/*_m.h stack/pdcp_rrc/layer/*_sm.cc stack/pdcp_rrc/layer/*_sm.h
	$(Q)-rm -f stack/pdcp_rrc/layer/entity/*_m.cc stack/pdcp_rrc/layer/entity/*_m.h stack/pdcp_rrc/layer/entity/*_sm.cc stack/pdcp_rrc/layer/entity/*_sm.h
	$(Q)-rm -f stack/pdcp_rrc/packet/*_m.cc stack/pdcp_rrc/packet/*_m.h stack/pdcp_rrc/packet/*_sm.cc stack/pdcp_rrc/packet/*_sm.h
	$(Q)-rm -f stack/phy/*_m.cc stack/phy/*_m.h stack/phy/*_sm.cc stack/phy/*_sm.h
	$(Q)-rm -f stack/phy/ChannelModel/*_m.cc stack/phy/ChannelModel/*_m.h stack/phy/ChannelModel/*_sm.cc stack/phy/ChannelModel/*_sm.h
	$(Q)-rm -f stack/phy/das/*_m.cc stack/phy/das/*_m.h stack/phy/das/*_sm.cc stack/phy/das/*_sm.h
	$(Q)-rm -f stack/phy/feedback/*_m.cc stack/phy/feedback/*_m.h stack/phy/feedback/*_sm.cc stack/phy/feedback/*_sm.h
	$(Q)-rm -f stack/phy/feedback/testFeedback/*_m.cc stack/phy/feedback/testFeedback/*_m.h stack/phy/feedback/testFeedback/*_sm.cc stack/phy/feedback/testFeedback/*_sm.h
	$(Q)-rm -f stack/phy/layer/*_m.cc stack/phy/layer/*_m.h stack/phy/layer/*_sm.cc stack/phy/layer/*_sm.h
	$(Q)-rm -f stack/phy/packet/*_m.cc stack/phy/packet/*_m.h stack/phy/packet/*_sm.cc stack/phy/packet/*_sm.h
	$(Q)-rm -f stack/rlc/*_m.cc stack/rlc/*_m.h stack/rlc/*_sm.cc stack/rlc/*_sm.h
	$(Q)-rm -f stack/rlc/am/*_m.cc stack/rlc/am/*_m.h stack/rlc/am/*_sm.cc stack/rlc/am/*_sm.h
	$(Q)-rm -f stack/rlc/am/buffer/*_m.cc stack/rlc/am/buffer/*_m.h stack/rlc/am/buffer/*_sm.cc stack/rlc/am/buffer/*_sm.h
	$(Q)-rm -f stack/rlc/am/packet/*_m.cc stack/rlc/am/packet/*_m.h stack/rlc/am/packet/*_sm.cc stack/rlc/am/packet/*_sm.h
	$(Q)-rm -f stack/rlc/packet/*_m.cc stack/rlc/packet/*_m.h stack/rlc/packet/*_sm.cc stack/rlc/packet/*_sm.h
	$(Q)-rm -f stack/rlc/tm/*_m.cc stack/rlc/tm/*_m.h stack/rlc/tm/*_sm.cc stack/rlc/tm/*_sm.h
	$(Q)-rm -f stack/rlc/um/*_m.cc stack/rlc/um/*_m.h stack/rlc/um/*_sm.cc stack/rlc/um/*_sm.h
	$(Q)-rm -f stack/rlc/um/buffer/*_m.cc stack/rlc/um/buffer/*_m.h stack/rlc/um/buffer/*_sm.cc stack/rlc/um/buffer/*_sm.h
	$(Q)-rm -f stack/rlc/um/entity/*_m.cc stack/rlc/um/entity/*_m.h stack/rlc/um/entity/*_sm.cc stack/rlc/um/entity/*_sm.h
	$(Q)-rm -f world/*_m.cc world/*_m.h world/*_sm.cc world/*_sm.h
	$(Q)-rm -f world/radio/*_m.cc world/radio/*_m.h world/radio/*_sm.cc world/radio/*_sm.h
	$(Q)-rm -f x2/*_m.cc x2/*_m.h x2/*_sm.cc x2/*_sm.h
	$(Q)-rm -f x2/packet/*_m.cc x2/packet/*_m.h x2/packet/*_sm.cc x2/packet/*_sm.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES) $(SM_CC_FILES)  ./*.cc apps/*.cc apps/alert/*.cc apps/vod/*.cc apps/voip/*.cc common/*.cc common/timer/*.cc corenetwork/*.cc corenetwork/binder/*.cc corenetwork/deployer/*.cc corenetwork/lteip/*.cc corenetwork/nodes/*.cc epc/*.cc epc/gtp/*.cc stack/*.cc stack/compManager/*.cc stack/compManager/compManagerProportional/*.cc stack/d2dModeSelection/*.cc stack/d2dModeSelection/d2dModeSelectionBestCqi/*.cc stack/handoverManager/*.cc stack/mac/*.cc stack/mac/allocator/*.cc stack/mac/amc/*.cc stack/mac/buffer/*.cc stack/mac/buffer/harq/*.cc stack/mac/buffer/harq_d2d/*.cc stack/mac/layer/*.cc stack/mac/packet/*.cc stack/mac/scheduler/*.cc stack/mac/scheduling_modules/*.cc stack/pdcp_rrc/*.cc stack/pdcp_rrc/layer/*.cc stack/pdcp_rrc/layer/entity/*.cc stack/pdcp_rrc/packet/*.cc stack/phy/*.cc stack/phy/ChannelModel/*.cc stack/phy/das/*.cc stack/phy/feedback/*.cc stack/phy/feedback/testFeedback/*.cc stack/phy/layer/*.cc stack/phy/packet/*.cc stack/rlc/*.cc stack/rlc/am/*.cc stack/rlc/am/buffer/*.cc stack/rlc/am/packet/*.cc stack/rlc/packet/*.cc stack/rlc/tm/*.cc stack/rlc/um/*.cc stack/rlc/um/buffer/*.cc stack/rlc/um/entity/*.cc world/*.cc world/radio/*.cc x2/*.cc x2/packet/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/apps/alert/AlertPacket_m.o: apps/alert/AlertPacket_m.cc \
	apps/alert/AlertPacket_m.h
$O/apps/alert/AlertReceiver.o: apps/alert/AlertReceiver.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/ModuleAccess.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPSocket.h \
	apps/alert/AlertPacket_m.h \
	apps/alert/AlertReceiver.h
$O/apps/alert/AlertSender.o: apps/alert/AlertSender.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/ModuleAccess.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPSocket.h \
	apps/alert/AlertPacket_m.h \
	apps/alert/AlertSender.h
$O/apps/vod/M1Message_m.o: apps/vod/M1Message_m.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	apps/vod/M1Message_m.h
$O/apps/vod/VoDPacket_m.o: apps/vod/VoDPacket_m.cc \
	apps/vod/VoDPacket_m.h
$O/apps/vod/VoDUDPClient.o: apps/vod/VoDUDPClient.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPSocket.h \
	apps/vod/VoDPacket_m.h \
	apps/vod/VoDUDPClient.h \
	apps/vod/VoDUDPStruct.h \
	common/lterecorder.h
$O/apps/vod/VoDUDPServer.o: apps/vod/VoDUDPServer.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPSocket.h \
	apps/vod/M1Message_m.h \
	apps/vod/VoDPacket_m.h \
	apps/vod/VoDUDPServer.h \
	apps/vod/VoDUDPStruct.h
$O/apps/voip/VoIPReceiver.o: apps/voip/VoIPReceiver.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPSocket.h \
	apps/voip/VoIPReceiver.h \
	apps/voip/VoipPacket_m.h \
	common/lterecorder.h
$O/apps/voip/VoIPSender.o: apps/voip/VoIPSender.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPSocket.h \
	apps/voip/VoIPSender.h \
	apps/voip/VoipPacket_m.h
$O/apps/voip/VoipPacket_m.o: apps/voip/VoipPacket_m.cc \
	apps/voip/VoipPacket_m.h
$O/common/CAINInfo_m.o: common/CAINInfo_m.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/CAINInfo_m.h \
	common/LteCommon.h \
	common/lterecorder.h
$O/common/LteCommon.o: common/LteCommon.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/common/LteControlInfo.o: common/LteControlInfo.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h
$O/common/LteControlInfo_m.o: common/LteControlInfo_m.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h
$O/common/lterecorder.o: common/lterecorder.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/nodes/ExtCell.h
$O/common/timer/TMultiTimerMsg_m.o: common/timer/TMultiTimerMsg_m.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimerMsg_m.h
$O/common/timer/TTimer.o: common/timer/TTimer.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h
$O/common/timer/TTimerMsg_m.o: common/timer/TTimerMsg_m.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/lterecorder.h \
	common/timer/TTimerMsg_m.h
$O/corenetwork/binder/LteBinder.o: corenetwork/binder/LteBinder.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	corenetwork/nodes/InternetMux.h \
	stack/phy/das/RemoteAntennaSet.h
$O/corenetwork/binder/PhyPisaData.o: corenetwork/binder/PhyPisaData.cc \
	corenetwork/binder/PhyPisaData.h
$O/corenetwork/deployer/LteDeployer.o: corenetwork/deployer/LteDeployer.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/ModuleAccess.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/geometry/common/CanvasProjection.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/common/geometry/common/EulerAngles.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Rotation.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/mobility/base/MobilityBase.h \
	$(INET_PROJ)/src/inet/mobility/contract/IMobility.h \
	$(INET_PROJ)/src/inet/mobility/static/StationaryMobility.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/phy/das/RemoteAntennaSet.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h
$O/corenetwork/lteip/IP2lte.o: corenetwork/lteip/IP2lte.cc \
	$(INET_PROJ)/src/inet/common/ByteArray.h \
	$(INET_PROJ)/src/inet/common/ByteArray_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/ModuleAccess.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/ITransportPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment_m.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDP.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket_m.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/lteip/IP2lte.h \
	corenetwork/nodes/ExtCell.h \
	stack/handoverManager/LteHandoverManager.h \
	stack/handoverManager/X2HandoverControlMsg.h \
	stack/handoverManager/X2HandoverDataMsg.h \
	stack/mac/layer/LteMacBase.h \
	stack/phy/das/RemoteAntennaSet.h \
	x2/packet/LteX2Message.h \
	x2/packet/LteX2Message_m.h \
	x2/packet/X2ControlInfo_m.h \
	x2/packet/X2InformationElement.h
$O/corenetwork/lteip/InternetQueue.o: corenetwork/lteip/InternetQueue.cc \
	corenetwork/lteip/InternetQueue.h
$O/corenetwork/lteip/LteIp.o: corenetwork/lteip/LteIp.cc \
	$(INET_PROJ)/src/inet/common/ByteArray.h \
	$(INET_PROJ)/src/inet/common/ByteArray_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/ModuleAccess.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/ProtocolMap.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/queue/AbstractQueue.h \
	$(INET_PROJ)/src/inet/common/queue/QueueBase.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkProtocolControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo_m.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/ITransportPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment_m.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDP.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket_m.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/lteip/LteIp.h \
	corenetwork/nodes/ExtCell.h \
	stack/phy/das/RemoteAntennaSet.h
$O/corenetwork/nodes/ExtCell.o: corenetwork/nodes/ExtCell.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/nodes/ExtCell.h
$O/corenetwork/nodes/InternetMux.o: corenetwork/nodes/InternetMux.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/nodes/ExtCell.h \
	corenetwork/nodes/InternetMux.h
$O/corenetwork/nodes/UnUuMux.o: corenetwork/nodes/UnUuMux.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/nodes/UnUuMux.h
$O/epc/TrafficFlowFilter.o: epc/TrafficFlowFilter.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkProtocolControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo_m.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	epc/TrafficFlowFilter.h \
	epc/gtp/TftControlInfo.h \
	epc/gtp_common.h
$O/epc/TrafficFlowFilterSimplified.o: epc/TrafficFlowFilterSimplified.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkProtocolControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo_m.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/nodes/ExtCell.h \
	epc/TrafficFlowFilterSimplified.h \
	epc/gtp/TftControlInfo.h \
	epc/gtp_common.h
$O/epc/gtp_common.o: epc/gtp_common.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	epc/gtp_common.h
$O/epc/gtp/GtpUser.o: epc/gtp/GtpUser.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkProtocolControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo_m.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPSocket.h \
	epc/gtp/GtpUser.h \
	epc/gtp/GtpUserMsg_m.h \
	epc/gtp/TftControlInfo.h \
	epc/gtp_common.h
$O/epc/gtp/GtpUserMsg_m.o: epc/gtp/GtpUserMsg_m.cc \
	epc/gtp/GtpUserMsg_m.h
$O/epc/gtp/GtpUserSimplified.o: epc/gtp/GtpUserSimplified.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkProtocolControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo_m.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPSocket.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/nodes/ExtCell.h \
	epc/gtp/GtpUserMsg_m.h \
	epc/gtp/GtpUserSimplified.h \
	epc/gtp/TftControlInfo.h \
	epc/gtp_common.h
$O/epc/gtp/GtpUserX2.o: epc/gtp/GtpUserX2.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPSocket.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/nodes/ExtCell.h \
	epc/gtp/GtpUserMsg_m.h \
	epc/gtp/GtpUserX2.h \
	epc/gtp_common.h \
	x2/packet/LteX2Message.h \
	x2/packet/LteX2Message_m.h \
	x2/packet/X2InformationElement.h
$O/epc/gtp/TftControlInfo.o: epc/gtp/TftControlInfo.cc \
	epc/gtp/TftControlInfo.h
$O/stack/compManager/LteCompManagerBase.o: stack/compManager/LteCompManagerBase.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/compManager/LteCompManagerBase.h \
	stack/compManager/X2CompMsg.h \
	stack/compManager/X2CompReplyIE.h \
	stack/compManager/X2CompRequestIE.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	x2/packet/LteX2Message.h \
	x2/packet/LteX2Message_m.h \
	x2/packet/X2ControlInfo_m.h \
	x2/packet/X2InformationElement.h
$O/stack/compManager/compManagerProportional/LteCompManagerProportional.o: stack/compManager/compManagerProportional/LteCompManagerProportional.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/compManager/LteCompManagerBase.h \
	stack/compManager/X2CompMsg.h \
	stack/compManager/X2CompReplyIE.h \
	stack/compManager/X2CompRequestIE.h \
	stack/compManager/compManagerProportional/LteCompManagerProportional.h \
	stack/compManager/compManagerProportional/X2CompProportionalReplyIE.h \
	stack/compManager/compManagerProportional/X2CompProportionalRequestIE.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	x2/packet/LteX2Message.h \
	x2/packet/LteX2Message_m.h \
	x2/packet/X2ControlInfo_m.h \
	x2/packet/X2InformationElement.h
$O/stack/d2dModeSelection/D2DModeSelectionBase.o: stack/d2dModeSelection/D2DModeSelectionBase.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/d2dModeSelection/D2DModeSelectionBase.h \
	stack/d2dModeSelection/D2DModeSwitchNotification_m.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/harq_d2d/LteHarqBufferRxD2DMirror.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessRxD2DMirror.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/layer/LteMacEnbD2D.h \
	stack/mac/layer/LteMacEnbRealistic.h \
	stack/mac/layer/LteMacEnbRealisticD2D.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/d2dModeSelection/D2DModeSwitchNotification_m.o: stack/d2dModeSelection/D2DModeSwitchNotification_m.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/lterecorder.h \
	stack/d2dModeSelection/D2DModeSwitchNotification_m.h
$O/stack/d2dModeSelection/d2dModeSelectionBestCqi/D2DModeSelectionBestCqi.o: stack/d2dModeSelection/d2dModeSelectionBestCqi/D2DModeSelectionBestCqi.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/d2dModeSelection/D2DModeSelectionBase.h \
	stack/d2dModeSelection/d2dModeSelectionBestCqi/D2DModeSelectionBestCqi.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/handoverManager/LteHandoverManager.o: stack/handoverManager/LteHandoverManager.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/lteip/IP2lte.h \
	corenetwork/nodes/ExtCell.h \
	stack/handoverManager/LteHandoverManager.h \
	stack/handoverManager/X2HandoverCommandIE.h \
	stack/handoverManager/X2HandoverControlMsg.h \
	stack/handoverManager/X2HandoverDataMsg.h \
	x2/packet/LteX2Message.h \
	x2/packet/LteX2Message_m.h \
	x2/packet/X2ControlInfo_m.h \
	x2/packet/X2InformationElement.h
$O/stack/mac/allocator/LteAllocationModule.o: stack/mac/allocator/LteAllocationModule.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/allocator/LteAllocationModule.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/amc/AmcPilotAuto.o: stack/mac/amc/AmcPilotAuto.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/AmcPilotAuto.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/amc/AmcPilotD2D.o: stack/mac/amc/AmcPilotD2D.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/AmcPilotD2D.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/amc/LteAmc.o: stack/mac/amc/LteAmc.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/AmcPilotAuto.h \
	stack/mac/amc/AmcPilotD2D.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/amc/LteMcs.o: stack/mac/amc/LteMcs.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/lterecorder.h \
	stack/mac/amc/LteMcs.h
$O/stack/mac/buffer/LteMacBuffer.o: stack/mac/buffer/LteMacBuffer.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/lterecorder.h \
	stack/mac/buffer/LteMacBuffer.h
$O/stack/mac/buffer/LteMacQueue.o: stack/mac/buffer/LteMacQueue.cc \
	stack/mac/buffer/LteMacQueue.h \
	stack/rlc/packet/LteRlcPdu_m.h
$O/stack/mac/buffer/harq/LteHarqBufferRx.o: stack/mac/buffer/harq/LteHarqBufferRx.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqBufferRx.h \
	stack/mac/buffer/harq/LteHarqProcessRx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/buffer/harq/LteHarqBufferTx.o: stack/mac/buffer/harq/LteHarqBufferTx.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h
$O/stack/mac/buffer/harq/LteHarqProcessRx.o: stack/mac/buffer/harq/LteHarqProcessRx.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/mac/buffer/harq/LteHarqProcessRx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h
$O/stack/mac/buffer/harq/LteHarqProcessTx.o: stack/mac/buffer/harq/LteHarqProcessTx.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h
$O/stack/mac/buffer/harq/LteHarqUnitTx.o: stack/mac/buffer/harq/LteHarqUnitTx.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/buffer/harq_d2d/LteHarqBufferRxD2D.o: stack/mac/buffer/harq_d2d/LteHarqBufferRxD2D.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqBufferRx.h \
	stack/mac/buffer/harq/LteHarqProcessRx.h \
	stack/mac/buffer/harq_d2d/LteHarqBufferRxD2D.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessRxD2D.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/buffer/harq_d2d/LteHarqBufferRxD2DMirror.o: stack/mac/buffer/harq_d2d/LteHarqBufferRxD2DMirror.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/lterecorder.h \
	stack/mac/buffer/harq/LteHarqBufferRx.h \
	stack/mac/buffer/harq/LteHarqProcessRx.h \
	stack/mac/buffer/harq_d2d/LteHarqBufferRxD2DMirror.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessRxD2DMirror.h \
	stack/mac/layer/LteMacBase.h
$O/stack/mac/buffer/harq_d2d/LteHarqBufferTxD2D.o: stack/mac/buffer/harq_d2d/LteHarqBufferTxD2D.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/buffer/harq_d2d/LteHarqBufferTxD2D.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessTxD2D.h \
	stack/mac/buffer/harq_d2d/LteHarqUnitTxD2D.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h
$O/stack/mac/buffer/harq_d2d/LteHarqProcessRxD2D.o: stack/mac/buffer/harq_d2d/LteHarqProcessRxD2D.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/mac/buffer/harq/LteHarqProcessRx.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessRxD2D.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h
$O/stack/mac/buffer/harq_d2d/LteHarqProcessRxD2DMirror.o: stack/mac/buffer/harq_d2d/LteHarqProcessRxD2DMirror.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/lterecorder.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessRxD2DMirror.h
$O/stack/mac/buffer/harq_d2d/LteHarqProcessTxD2D.o: stack/mac/buffer/harq_d2d/LteHarqProcessTxD2D.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessTxD2D.h \
	stack/mac/buffer/harq_d2d/LteHarqUnitTxD2D.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h
$O/stack/mac/buffer/harq_d2d/LteHarqUnitTxD2D.o: stack/mac/buffer/harq_d2d/LteHarqUnitTxD2D.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/buffer/harq_d2d/LteHarqUnitTxD2D.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/layer/LteMacBase.o: stack/mac/layer/LteMacBase.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/LteMacQueue.h \
	stack/mac/buffer/harq/LteHarqBufferRx.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessRx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/buffer/harq_d2d/LteHarqBufferRxD2D.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessRxD2D.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/rlc/packet/LteRlcPdu_m.h
$O/stack/mac/layer/LteMacEnb.o: stack/mac/layer/LteMacEnb.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/allocator/LteAllocationModule.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/LteMacQueue.h \
	stack/mac/buffer/harq/LteHarqBufferRx.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessRx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/packet/LteRac_m.h \
	stack/mac/packet/LteSchedulingGrant.h \
	stack/mac/packet/LteSchedulingGrant_m.h \
	stack/mac/scheduler/LteSchedulerEnb.h \
	stack/mac/scheduler/LteSchedulerEnbDl.h \
	stack/mac/scheduler/LteSchedulerEnbUl.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/packet/LteFeedbackPkt.h \
	stack/phy/packet/LteFeedbackPkt_m.h \
	stack/rlc/packet/LteRlcPdu_m.h
$O/stack/mac/layer/LteMacEnbD2D.o: stack/mac/layer/LteMacEnbD2D.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/d2dModeSelection/D2DModeSwitchNotification_m.h \
	stack/mac/allocator/LteAllocationModule.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/AmcPilotD2D.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/LteMacQueue.h \
	stack/mac/buffer/harq/LteHarqBufferRx.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessRx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/buffer/harq_d2d/LteHarqBufferRxD2DMirror.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessRxD2DMirror.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/layer/LteMacEnbD2D.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/packet/LteRac_m.h \
	stack/mac/packet/LteSchedulingGrant.h \
	stack/mac/packet/LteSchedulingGrant_m.h \
	stack/mac/scheduler/LteSchedulerEnb.h \
	stack/mac/scheduler/LteSchedulerEnbDl.h \
	stack/mac/scheduler/LteSchedulerEnbUl.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/packet/LteFeedbackPkt.h \
	stack/phy/packet/LteFeedbackPkt_m.h \
	stack/rlc/packet/LteRlcPdu_m.h
$O/stack/mac/layer/LteMacEnbRealistic.o: stack/mac/layer/LteMacEnbRealistic.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/allocator/LteAllocationModule.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/LteMacQueue.h \
	stack/mac/buffer/harq/LteHarqBufferRx.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessRx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/layer/LteMacEnbRealistic.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/packet/LteMacSduRequest.h \
	stack/mac/packet/LteMacSduRequest_m.h \
	stack/mac/packet/LteRac_m.h \
	stack/mac/packet/LteSchedulingGrant.h \
	stack/mac/packet/LteSchedulingGrant_m.h \
	stack/mac/scheduler/LteSchedulerEnb.h \
	stack/mac/scheduler/LteSchedulerEnbDl.h \
	stack/mac/scheduler/LteSchedulerEnbDlRealistic.h \
	stack/mac/scheduler/LteSchedulerEnbUl.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/packet/LteFeedbackPkt.h \
	stack/phy/packet/LteFeedbackPkt_m.h \
	stack/rlc/packet/LteRlcPdu_m.h
$O/stack/mac/layer/LteMacEnbRealisticD2D.o: stack/mac/layer/LteMacEnbRealisticD2D.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/d2dModeSelection/D2DModeSwitchNotification_m.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/AmcPilotD2D.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/harq/LteHarqBufferRx.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessRx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/buffer/harq_d2d/LteHarqBufferRxD2DMirror.h \
	stack/mac/buffer/harq_d2d/LteHarqBufferTxD2D.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessRxD2DMirror.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessTxD2D.h \
	stack/mac/buffer/harq_d2d/LteHarqUnitTxD2D.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/layer/LteMacEnbRealistic.h \
	stack/mac/layer/LteMacEnbRealisticD2D.h \
	stack/mac/layer/LteMacUe.h \
	stack/mac/layer/LteMacUeRealistic.h \
	stack/mac/layer/LteMacUeRealisticD2D.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/packet/LteSchedulingGrant.h \
	stack/mac/packet/LteSchedulingGrant_m.h \
	stack/mac/scheduler/LteSchedulerEnb.h \
	stack/mac/scheduler/LteSchedulerEnbUl.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/packet/LteFeedbackPkt.h \
	stack/phy/packet/LteFeedbackPkt_m.h
$O/stack/mac/layer/LteMacRelayEnb.o: stack/mac/layer/LteMacRelayEnb.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/layer/LteMacRelayEnb.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/layer/LteMacRelayUe.o: stack/mac/layer/LteMacRelayUe.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacRelayUe.h \
	stack/mac/layer/LteMacUe.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h
$O/stack/mac/layer/LteMacUe.o: stack/mac/layer/LteMacUe.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/ModuleAccess.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4InterfaceData.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/LteMacQueue.h \
	stack/mac/buffer/harq/LteHarqBufferRx.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessRx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/layer/LteMacUe.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/packet/LteRac_m.h \
	stack/mac/packet/LteSchedulingGrant.h \
	stack/mac/packet/LteSchedulingGrant_m.h \
	stack/mac/scheduler/LteSchedulerUeUl.h \
	stack/phy/ChannelModel/LteChannelModel.h \
	stack/phy/ChannelModel/LteDummyChannelModel.h \
	stack/phy/ChannelModel/LteRealisticChannelModel.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h \
	stack/phy/feedback/LteFeedbackComputationRealistic.h \
	stack/phy/layer/LtePhyBase.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/LteAirFrame.h \
	stack/phy/packet/LteAirFrame_m.h \
	stack/phy/packet/ModulationType.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h
$O/stack/mac/layer/LteMacUeD2D.o: stack/mac/layer/LteMacUeD2D.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/d2dModeSelection/D2DModeSwitchNotification_m.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/LteMacQueue.h \
	stack/mac/buffer/harq/LteHarqBufferRx.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessRx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/buffer/harq_d2d/LteHarqBufferRxD2DMirror.h \
	stack/mac/buffer/harq_d2d/LteHarqBufferTxD2D.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessRxD2DMirror.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessTxD2D.h \
	stack/mac/buffer/harq_d2d/LteHarqUnitTxD2D.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/layer/LteMacEnbD2D.h \
	stack/mac/layer/LteMacUe.h \
	stack/mac/layer/LteMacUeD2D.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/packet/LteRac_m.h \
	stack/mac/packet/LteSchedulingGrant.h \
	stack/mac/packet/LteSchedulingGrant_m.h \
	stack/mac/scheduler/LteSchedulerUeUl.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/rlc/packet/LteRlcPdu_m.h
$O/stack/mac/layer/LteMacUeRealistic.o: stack/mac/layer/LteMacUeRealistic.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/ModuleAccess.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4InterfaceData.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/LteMacQueue.h \
	stack/mac/buffer/harq/LteHarqBufferRx.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessRx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacUe.h \
	stack/mac/layer/LteMacUeRealistic.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/packet/LteMacSduRequest.h \
	stack/mac/packet/LteMacSduRequest_m.h \
	stack/mac/packet/LteRac_m.h \
	stack/mac/packet/LteSchedulingGrant.h \
	stack/mac/packet/LteSchedulingGrant_m.h \
	stack/mac/scheduler/LteSchedulerUeUl.h \
	stack/rlc/packet/LteRlcPdu_m.h
$O/stack/mac/layer/LteMacUeRealisticD2D.o: stack/mac/layer/LteMacUeRealisticD2D.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/CAINInfo_m.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/d2dModeSelection/D2DModeSwitchNotification_m.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/LteMacQueue.h \
	stack/mac/buffer/harq/LteHarqBufferRx.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessRx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/buffer/harq_d2d/LteHarqBufferRxD2DMirror.h \
	stack/mac/buffer/harq_d2d/LteHarqBufferTxD2D.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessRxD2DMirror.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessTxD2D.h \
	stack/mac/buffer/harq_d2d/LteHarqUnitTxD2D.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/layer/LteMacEnbRealistic.h \
	stack/mac/layer/LteMacEnbRealisticD2D.h \
	stack/mac/layer/LteMacUe.h \
	stack/mac/layer/LteMacUeRealistic.h \
	stack/mac/layer/LteMacUeRealisticD2D.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/packet/LteRac_m.h \
	stack/mac/packet/LteSchedulingGrant.h \
	stack/mac/packet/LteSchedulingGrant_m.h \
	stack/mac/scheduler/LteSchedulerUeUl.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/rlc/packet/LteRlcPdu_m.h
$O/stack/mac/packet/LteHarqFeedback_m.o: stack/mac/packet/LteHarqFeedback_m.cc \
	stack/mac/packet/LteHarqFeedback_m.h
$O/stack/mac/packet/LteMacPdu_m.o: stack/mac/packet/LteMacPdu_m.cc \
	stack/mac/packet/LteMacPdu_m.h
$O/stack/mac/packet/LteMacSduRequest_m.o: stack/mac/packet/LteMacSduRequest_m.cc \
	stack/mac/packet/LteMacSduRequest_m.h
$O/stack/mac/packet/LteRac_m.o: stack/mac/packet/LteRac_m.cc \
	stack/mac/packet/LteRac_m.h
$O/stack/mac/packet/LteSchedulingGrant_m.o: stack/mac/packet/LteSchedulingGrant_m.cc \
	stack/mac/packet/LteSchedulingGrant_m.h
$O/stack/mac/scheduler/LcgScheduler.o: stack/mac/scheduler/LcgScheduler.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacUe.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/scheduler/LcgScheduler.h
$O/stack/mac/scheduler/LcgSchedulerRealistic.o: stack/mac/scheduler/LcgSchedulerRealistic.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacUe.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/scheduler/LcgScheduler.h \
	stack/mac/scheduler/LcgSchedulerRealistic.h
$O/stack/mac/scheduler/LteScheduler.o: stack/mac/scheduler/LteScheduler.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/scheduler/LteScheduler.h \
	stack/mac/scheduler/LteSchedulerEnb.h \
	stack/mac/scheduler/LteSchedulerEnbUl.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/scheduler/LteSchedulerEnb.o: stack/mac/scheduler/LteSchedulerEnb.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/Circular.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/allocator/LteAllocationModule.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/LteMacQueue.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/scheduler/LteScheduler.h \
	stack/mac/scheduler/LteSchedulerEnb.h \
	stack/mac/scheduling_modules/LteDrr.h \
	stack/mac/scheduling_modules/LteMaxCi.h \
	stack/mac/scheduling_modules/LteMaxCiComp.h \
	stack/mac/scheduling_modules/LteMaxCiMultiband.h \
	stack/mac/scheduling_modules/LteMaxCiOptMB.h \
	stack/mac/scheduling_modules/LtePf.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/rlc/packet/LteRlcPdu_m.h
$O/stack/mac/scheduler/LteSchedulerEnbDl.o: stack/mac/scheduler/LteSchedulerEnbDl.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/allocator/LteAllocationModule.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/scheduler/LteScheduler.h \
	stack/mac/scheduler/LteSchedulerEnb.h \
	stack/mac/scheduler/LteSchedulerEnbDl.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/scheduler/LteSchedulerEnbDlRealistic.o: stack/mac/scheduler/LteSchedulerEnbDlRealistic.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/allocator/LteAllocationModule.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/scheduler/LteScheduler.h \
	stack/mac/scheduler/LteSchedulerEnb.h \
	stack/mac/scheduler/LteSchedulerEnbDl.h \
	stack/mac/scheduler/LteSchedulerEnbDlRealistic.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/scheduler/LteSchedulerEnbUl.o: stack/mac/scheduler/LteSchedulerEnbUl.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/d2dModeSelection/D2DModeSwitchNotification_m.h \
	stack/mac/allocator/LteAllocationModule.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/harq/LteHarqBufferRx.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessRx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/buffer/harq_d2d/LteHarqBufferRxD2DMirror.h \
	stack/mac/buffer/harq_d2d/LteHarqProcessRxD2DMirror.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/layer/LteMacEnbD2D.h \
	stack/mac/layer/LteMacEnbRealistic.h \
	stack/mac/layer/LteMacEnbRealisticD2D.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/scheduler/LteSchedulerEnb.h \
	stack/mac/scheduler/LteSchedulerEnbUl.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/scheduler/LteSchedulerUeUl.o: stack/mac/scheduler/LteSchedulerUeUl.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacUe.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/packet/LteSchedulingGrant.h \
	stack/mac/packet/LteSchedulingGrant_m.h \
	stack/mac/scheduler/LcgScheduler.h \
	stack/mac/scheduler/LcgSchedulerRealistic.h \
	stack/mac/scheduler/LteSchedulerUeUl.h
$O/stack/mac/scheduling_modules/LteDrr.o: stack/mac/scheduling_modules/LteDrr.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/Circular.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/scheduler/LteScheduler.h \
	stack/mac/scheduler/LteSchedulerEnb.h \
	stack/mac/scheduling_modules/LteDrr.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/scheduling_modules/LteMaxCi.o: stack/mac/scheduling_modules/LteMaxCi.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/scheduler/LteScheduler.h \
	stack/mac/scheduler/LteSchedulerEnb.h \
	stack/mac/scheduling_modules/LteMaxCi.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/scheduling_modules/LteMaxCiComp.o: stack/mac/scheduling_modules/LteMaxCiComp.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/scheduler/LteScheduler.h \
	stack/mac/scheduler/LteSchedulerEnb.h \
	stack/mac/scheduling_modules/LteMaxCiComp.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/scheduling_modules/LteMaxCiMultiband.o: stack/mac/scheduling_modules/LteMaxCiMultiband.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/scheduler/LteScheduler.h \
	stack/mac/scheduler/LteSchedulerEnb.h \
	stack/mac/scheduling_modules/LteMaxCiMultiband.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/scheduling_modules/LteMaxCiOptMB.o: stack/mac/scheduling_modules/LteMaxCiOptMB.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/LteMacBuffer.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/scheduler/LteScheduler.h \
	stack/mac/scheduler/LteSchedulerEnb.h \
	stack/mac/scheduling_modules/LteMaxCiOptMB.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/mac/scheduling_modules/LtePf.o: stack/mac/scheduling_modules/LtePf.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/mac/scheduler/LteScheduler.h \
	stack/mac/scheduler/LteSchedulerEnb.h \
	stack/mac/scheduling_modules/LtePf.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/pdcp_rrc/ConnectionsTable.o: stack/pdcp_rrc/ConnectionsTable.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/lterecorder.h \
	stack/pdcp_rrc/ConnectionsTable.h
$O/stack/pdcp_rrc/layer/LtePdcpRrc.o: stack/pdcp_rrc/layer/LtePdcpRrc.cc \
	$(INET_PROJ)/src/inet/common/ByteArray.h \
	$(INET_PROJ)/src/inet/common/ByteArray_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/ProtocolMap.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/queue/AbstractQueue.h \
	$(INET_PROJ)/src/inet/common/queue/QueueBase.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkProtocolControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo_m.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/ITransportPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment_m.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDP.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket_m.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/lteip/LteIp.h \
	corenetwork/nodes/ExtCell.h \
	stack/pdcp_rrc/ConnectionsTable.h \
	stack/pdcp_rrc/layer/LtePdcpRrc.h \
	stack/pdcp_rrc/layer/entity/LtePdcpEntity.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h
$O/stack/pdcp_rrc/layer/LtePdcpRrcEnbD2D.o: stack/pdcp_rrc/layer/LtePdcpRrcEnbD2D.cc \
	$(INET_PROJ)/src/inet/common/ByteArray.h \
	$(INET_PROJ)/src/inet/common/ByteArray_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/ProtocolMap.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/queue/AbstractQueue.h \
	$(INET_PROJ)/src/inet/common/queue/QueueBase.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkProtocolControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo_m.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/ITransportPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment_m.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDP.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket_m.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/lteip/LteIp.h \
	corenetwork/nodes/ExtCell.h \
	stack/d2dModeSelection/D2DModeSwitchNotification_m.h \
	stack/pdcp_rrc/ConnectionsTable.h \
	stack/pdcp_rrc/layer/LtePdcpRrc.h \
	stack/pdcp_rrc/layer/LtePdcpRrcEnbD2D.h \
	stack/pdcp_rrc/layer/entity/LtePdcpEntity.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h
$O/stack/pdcp_rrc/layer/LtePdcpRrcUeD2D.o: stack/pdcp_rrc/layer/LtePdcpRrcUeD2D.cc \
	$(INET_PROJ)/src/inet/common/ByteArray.h \
	$(INET_PROJ)/src/inet/common/ByteArray_m.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/ProtocolMap.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/queue/AbstractQueue.h \
	$(INET_PROJ)/src/inet/common/queue/QueueBase.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkProtocolControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4ControlInfo_m.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/ITransportPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment.h \
	$(INET_PROJ)/src/inet/transportlayer/tcp_common/TCPSegment_m.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDP.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/udp/UDPPacket_m.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/lteip/LteIp.h \
	corenetwork/nodes/ExtCell.h \
	stack/d2dModeSelection/D2DModeSwitchNotification_m.h \
	stack/pdcp_rrc/ConnectionsTable.h \
	stack/pdcp_rrc/layer/LtePdcpRrc.h \
	stack/pdcp_rrc/layer/LtePdcpRrcUeD2D.h \
	stack/pdcp_rrc/layer/entity/LtePdcpEntity.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h
$O/stack/pdcp_rrc/layer/entity/LtePdcpEntity.o: stack/pdcp_rrc/layer/entity/LtePdcpEntity.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/pdcp_rrc/layer/entity/LtePdcpEntity.h
$O/stack/pdcp_rrc/packet/LtePdcpPdu_m.o: stack/pdcp_rrc/packet/LtePdcpPdu_m.cc \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h
$O/stack/phy/ChannelModel/CAINLteRealisticChannelModel.o: stack/phy/ChannelModel/CAINLteRealisticChannelModel.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/layer/LteMacUe.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h \
	stack/phy/ChannelModel/CAINLteRealisticChannelModel.h \
	stack/phy/ChannelModel/LteChannelModel.h \
	stack/phy/ChannelModel/LteDummyChannelModel.h \
	stack/phy/ChannelModel/LteRealisticChannelModel.h \
	stack/phy/das/DasFilter.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h \
	stack/phy/feedback/LteFeedbackComputationRealistic.h \
	stack/phy/layer/CAINLtePhyUe.h \
	stack/phy/layer/LtePhyBase.h \
	stack/phy/layer/LtePhyEnb.h \
	stack/phy/layer/LtePhyUe.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/LteAirFrame.h \
	stack/phy/packet/LteAirFrame_m.h \
	stack/phy/packet/ModulationType.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/LteRlcUm.h \
	stack/rlc/um/buffer/UmFragbuf.h \
	stack/rlc/um/buffer/UmRxQueue.h \
	stack/rlc/um/buffer/UmTxQueue.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h
$O/stack/phy/ChannelModel/LteChannelModel.o: stack/phy/ChannelModel/LteChannelModel.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/phy/ChannelModel/LteChannelModel.h
$O/stack/phy/ChannelModel/LteDummyChannelModel.o: stack/phy/ChannelModel/LteDummyChannelModel.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/phy/ChannelModel/LteChannelModel.h \
	stack/phy/ChannelModel/LteDummyChannelModel.h
$O/stack/phy/ChannelModel/LteRealisticChannelModel.o: stack/phy/ChannelModel/LteRealisticChannelModel.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/layer/LteMacUe.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h \
	stack/phy/ChannelModel/LteChannelModel.h \
	stack/phy/ChannelModel/LteDummyChannelModel.h \
	stack/phy/ChannelModel/LteRealisticChannelModel.h \
	stack/phy/das/DasFilter.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h \
	stack/phy/feedback/LteFeedbackComputationRealistic.h \
	stack/phy/layer/CAINLtePhyUe.h \
	stack/phy/layer/LtePhyBase.h \
	stack/phy/layer/LtePhyEnb.h \
	stack/phy/layer/LtePhyUe.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/LteAirFrame.h \
	stack/phy/packet/LteAirFrame_m.h \
	stack/phy/packet/ModulationType.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/LteRlcUm.h \
	stack/rlc/um/buffer/UmFragbuf.h \
	stack/rlc/um/buffer/UmRxQueue.h \
	stack/rlc/um/buffer/UmTxQueue.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h
$O/stack/phy/das/DasFilter.o: stack/phy/das/DasFilter.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/phy/ChannelModel/LteChannelModel.h \
	stack/phy/ChannelModel/LteDummyChannelModel.h \
	stack/phy/ChannelModel/LteRealisticChannelModel.h \
	stack/phy/das/DasFilter.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h \
	stack/phy/feedback/LteFeedbackComputationRealistic.h \
	stack/phy/layer/LtePhyBase.h \
	stack/phy/layer/LtePhyEnb.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/LteAirFrame.h \
	stack/phy/packet/LteAirFrame_m.h \
	stack/phy/packet/ModulationType.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h
$O/stack/phy/das/RemoteAntennaSet.o: stack/phy/das/RemoteAntennaSet.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	stack/phy/das/RemoteAntennaSet.h
$O/stack/phy/feedback/LteDlFeedbackGenerator.o: stack/phy/feedback/LteDlFeedbackGenerator.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/layer/LteMacUe.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h \
	stack/phy/ChannelModel/LteChannelModel.h \
	stack/phy/ChannelModel/LteDummyChannelModel.h \
	stack/phy/ChannelModel/LteRealisticChannelModel.h \
	stack/phy/das/DasFilter.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteDlFeedbackGenerator.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h \
	stack/phy/feedback/LteFeedbackComputationDummy.h \
	stack/phy/feedback/LteFeedbackComputationRealistic.h \
	stack/phy/layer/CAINLtePhyUe.h \
	stack/phy/layer/LtePhyBase.h \
	stack/phy/layer/LtePhyEnb.h \
	stack/phy/layer/LtePhyUe.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/LteAirFrame.h \
	stack/phy/packet/LteAirFrame_m.h \
	stack/phy/packet/ModulationType.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/LteRlcUm.h \
	stack/rlc/um/buffer/UmFragbuf.h \
	stack/rlc/um/buffer/UmRxQueue.h \
	stack/rlc/um/buffer/UmTxQueue.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h
$O/stack/phy/feedback/LteFeedback.o: stack/phy/feedback/LteFeedback.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/lterecorder.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/phy/feedback/LteFeedback.h
$O/stack/phy/feedback/LteFeedbackComputation.o: stack/phy/feedback/LteFeedbackComputation.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/lterecorder.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h
$O/stack/phy/feedback/LteFeedbackComputationDummy.o: stack/phy/feedback/LteFeedbackComputationDummy.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/lterecorder.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h \
	stack/phy/feedback/LteFeedbackComputationDummy.h
$O/stack/phy/feedback/LteFeedbackComputationRealistic.o: stack/phy/feedback/LteFeedbackComputationRealistic.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h \
	stack/phy/feedback/LteFeedbackComputationRealistic.h
$O/stack/phy/feedback/testFeedback/FeedbackTester.o: stack/phy/feedback/testFeedback/FeedbackTester.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/phy/ChannelModel/LteChannelModel.h \
	stack/phy/ChannelModel/LteDummyChannelModel.h \
	stack/phy/ChannelModel/LteRealisticChannelModel.h \
	stack/phy/das/DasFilter.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteDlFeedbackGenerator.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h \
	stack/phy/feedback/LteFeedbackComputationDummy.h \
	stack/phy/feedback/LteFeedbackComputationRealistic.h \
	stack/phy/feedback/testFeedback/FeedbackTester.h \
	stack/phy/layer/LtePhyBase.h \
	stack/phy/layer/LtePhyEnb.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/LteAirFrame.h \
	stack/phy/packet/LteAirFrame_m.h \
	stack/phy/packet/ModulationType.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h
$O/stack/phy/layer/CAINLtePhyUe.o: stack/phy/layer/CAINLtePhyUe.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/lteip/IP2lte.h \
	corenetwork/nodes/ExtCell.h \
	stack/handoverManager/LteHandoverManager.h \
	stack/handoverManager/X2HandoverControlMsg.h \
	stack/handoverManager/X2HandoverDataMsg.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/phy/ChannelModel/LteChannelModel.h \
	stack/phy/ChannelModel/LteDummyChannelModel.h \
	stack/phy/ChannelModel/LteRealisticChannelModel.h \
	stack/phy/das/DasFilter.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteDlFeedbackGenerator.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h \
	stack/phy/feedback/LteFeedbackComputationDummy.h \
	stack/phy/feedback/LteFeedbackComputationRealistic.h \
	stack/phy/layer/CAINLtePhyUe.h \
	stack/phy/layer/LtePhyBase.h \
	stack/phy/layer/LtePhyEnb.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/LteAirFrame.h \
	stack/phy/packet/LteAirFrame_m.h \
	stack/phy/packet/LteFeedbackPkt.h \
	stack/phy/packet/LteFeedbackPkt_m.h \
	stack/phy/packet/ModulationType.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	x2/packet/LteX2Message.h \
	x2/packet/LteX2Message_m.h \
	x2/packet/X2ControlInfo_m.h \
	x2/packet/X2InformationElement.h
$O/stack/phy/layer/LtePhyBase.o: stack/phy/layer/LtePhyBase.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/phy/ChannelModel/LteChannelModel.h \
	stack/phy/ChannelModel/LteDummyChannelModel.h \
	stack/phy/ChannelModel/LteRealisticChannelModel.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h \
	stack/phy/feedback/LteFeedbackComputationRealistic.h \
	stack/phy/layer/LtePhyBase.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/LteAirFrame.h \
	stack/phy/packet/LteAirFrame_m.h \
	stack/phy/packet/ModulationType.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h
$O/stack/phy/layer/LtePhyEnb.o: stack/phy/layer/LtePhyEnb.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/phy/ChannelModel/LteChannelModel.h \
	stack/phy/ChannelModel/LteDummyChannelModel.h \
	stack/phy/ChannelModel/LteRealisticChannelModel.h \
	stack/phy/das/DasFilter.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h \
	stack/phy/feedback/LteFeedbackComputationRealistic.h \
	stack/phy/layer/LtePhyBase.h \
	stack/phy/layer/LtePhyEnb.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/LteAirFrame.h \
	stack/phy/packet/LteAirFrame_m.h \
	stack/phy/packet/LteFeedbackPkt.h \
	stack/phy/packet/LteFeedbackPkt_m.h \
	stack/phy/packet/ModulationType.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h
$O/stack/phy/layer/LtePhyEnbD2D.o: stack/phy/layer/LtePhyEnbD2D.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/phy/ChannelModel/LteChannelModel.h \
	stack/phy/ChannelModel/LteDummyChannelModel.h \
	stack/phy/ChannelModel/LteRealisticChannelModel.h \
	stack/phy/das/DasFilter.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h \
	stack/phy/feedback/LteFeedbackComputationRealistic.h \
	stack/phy/layer/LtePhyBase.h \
	stack/phy/layer/LtePhyEnb.h \
	stack/phy/layer/LtePhyEnbD2D.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/LteAirFrame.h \
	stack/phy/packet/LteAirFrame_m.h \
	stack/phy/packet/LteFeedbackPkt.h \
	stack/phy/packet/LteFeedbackPkt_m.h \
	stack/phy/packet/ModulationType.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h
$O/stack/phy/layer/LtePhyRelay.o: stack/phy/layer/LtePhyRelay.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/phy/ChannelModel/LteChannelModel.h \
	stack/phy/ChannelModel/LteDummyChannelModel.h \
	stack/phy/ChannelModel/LteRealisticChannelModel.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h \
	stack/phy/feedback/LteFeedbackComputationRealistic.h \
	stack/phy/layer/LtePhyBase.h \
	stack/phy/layer/LtePhyRelay.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/LteAirFrame.h \
	stack/phy/packet/LteAirFrame_m.h \
	stack/phy/packet/ModulationType.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h
$O/stack/phy/layer/LtePhyUe.o: stack/phy/layer/LtePhyUe.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/TLVOption.h \
	$(INET_PROJ)/src/inet/common/TLVOption_m.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/IPProtocolId_m.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/INetworkDatagram.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Datagram_m.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/lteip/IP2lte.h \
	corenetwork/nodes/ExtCell.h \
	stack/handoverManager/LteHandoverManager.h \
	stack/handoverManager/X2HandoverControlMsg.h \
	stack/handoverManager/X2HandoverDataMsg.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/layer/LteMacUe.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h \
	stack/phy/ChannelModel/LteChannelModel.h \
	stack/phy/ChannelModel/LteDummyChannelModel.h \
	stack/phy/ChannelModel/LteRealisticChannelModel.h \
	stack/phy/das/DasFilter.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteDlFeedbackGenerator.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h \
	stack/phy/feedback/LteFeedbackComputationDummy.h \
	stack/phy/feedback/LteFeedbackComputationRealistic.h \
	stack/phy/layer/CAINLtePhyUe.h \
	stack/phy/layer/LtePhyBase.h \
	stack/phy/layer/LtePhyEnb.h \
	stack/phy/layer/LtePhyUe.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/LteAirFrame.h \
	stack/phy/packet/LteAirFrame_m.h \
	stack/phy/packet/LteFeedbackPkt.h \
	stack/phy/packet/LteFeedbackPkt_m.h \
	stack/phy/packet/ModulationType.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/LteRlcUm.h \
	stack/rlc/um/buffer/UmFragbuf.h \
	stack/rlc/um/buffer/UmRxQueue.h \
	stack/rlc/um/buffer/UmTxQueue.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	x2/packet/LteX2Message.h \
	x2/packet/LteX2Message_m.h \
	x2/packet/X2ControlInfo_m.h \
	x2/packet/X2InformationElement.h
$O/stack/phy/layer/LtePhyUeD2D.o: stack/phy/layer/LtePhyUeD2D.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/d2dModeSelection/D2DModeSelectionBase.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/buffer/harq/LteHarqBufferTx.h \
	stack/mac/buffer/harq/LteHarqProcessTx.h \
	stack/mac/buffer/harq/LteHarqUnitTx.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/mac/layer/LteMacUe.h \
	stack/mac/packet/LteHarqFeedback_m.h \
	stack/mac/packet/LteMacPdu.h \
	stack/mac/packet/LteMacPdu_m.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h \
	stack/phy/ChannelModel/LteChannelModel.h \
	stack/phy/ChannelModel/LteDummyChannelModel.h \
	stack/phy/ChannelModel/LteRealisticChannelModel.h \
	stack/phy/das/DasFilter.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/feedback/LteFeedbackComputation.h \
	stack/phy/feedback/LteFeedbackComputationRealistic.h \
	stack/phy/layer/CAINLtePhyUe.h \
	stack/phy/layer/LtePhyBase.h \
	stack/phy/layer/LtePhyEnb.h \
	stack/phy/layer/LtePhyUe.h \
	stack/phy/layer/LtePhyUeD2D.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/LteAirFrame.h \
	stack/phy/packet/LteAirFrame_m.h \
	stack/phy/packet/LteFeedbackPkt.h \
	stack/phy/packet/LteFeedbackPkt_m.h \
	stack/phy/packet/ModulationType.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/LteRlcUm.h \
	stack/rlc/um/buffer/UmFragbuf.h \
	stack/rlc/um/buffer/UmRxQueue.h \
	stack/rlc/um/buffer/UmTxQueue.h \
	world/radio/ChannelAccess.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h
$O/stack/phy/packet/AirFrame_m.o: stack/phy/packet/AirFrame_m.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/ModulationType.h
$O/stack/phy/packet/LteAirFrame.o: stack/phy/packet/LteAirFrame.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/LteAirFrame.h \
	stack/phy/packet/LteAirFrame_m.h \
	stack/phy/packet/ModulationType.h
$O/stack/phy/packet/LteAirFrame_m.o: stack/phy/packet/LteAirFrame_m.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/LteAirFrame_m.h \
	stack/phy/packet/ModulationType.h
$O/stack/phy/packet/LteFeedbackPkt.o: stack/phy/packet/LteFeedbackPkt.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/lterecorder.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/phy/feedback/LteFeedback.h \
	stack/phy/packet/LteFeedbackPkt.h \
	stack/phy/packet/LteFeedbackPkt_m.h
$O/stack/phy/packet/LteFeedbackPkt_m.o: stack/phy/packet/LteFeedbackPkt_m.cc \
	stack/phy/packet/LteFeedbackPkt_m.h
$O/stack/rlc/LteRlcMux.o: stack/rlc/LteRlcMux.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/rlc/LteRlcMux.h
$O/stack/rlc/am/LteRlcAm.o: stack/rlc/am/LteRlcAm.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/am/LteRlcAm.h \
	stack/rlc/am/buffer/AmRxQueue.h \
	stack/rlc/am/buffer/AmTxQueue.h \
	stack/rlc/am/packet/LteRlcAmPdu.h \
	stack/rlc/am/packet/LteRlcAmPdu_m.h \
	stack/rlc/am/packet/LteRlcAmSdu_m.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/buffer/UmFragbuf.h
$O/stack/rlc/am/buffer/AmRxQueue.o: stack/rlc/am/buffer/AmRxQueue.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	stack/mac/layer/LteMacBase.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/am/LteRlcAm.h \
	stack/rlc/am/buffer/AmRxQueue.h \
	stack/rlc/am/packet/LteRlcAmPdu.h \
	stack/rlc/am/packet/LteRlcAmPdu_m.h \
	stack/rlc/am/packet/LteRlcAmSdu_m.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/buffer/UmFragbuf.h
$O/stack/rlc/am/buffer/AmTxQueue.o: stack/rlc/am/buffer/AmTxQueue.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	stack/mac/layer/LteMacBase.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/am/LteRlcAm.h \
	stack/rlc/am/buffer/AmTxQueue.h \
	stack/rlc/am/packet/LteRlcAmPdu.h \
	stack/rlc/am/packet/LteRlcAmPdu_m.h \
	stack/rlc/am/packet/LteRlcAmSdu_m.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/buffer/UmFragbuf.h
$O/stack/rlc/am/packet/LteRlcAmPdu.o: stack/rlc/am/packet/LteRlcAmPdu.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/am/packet/LteRlcAmPdu.h \
	stack/rlc/am/packet/LteRlcAmPdu_m.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/buffer/UmFragbuf.h
$O/stack/rlc/am/packet/LteRlcAmPdu_m.o: stack/rlc/am/packet/LteRlcAmPdu_m.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/am/packet/LteRlcAmPdu_m.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/buffer/UmFragbuf.h
$O/stack/rlc/am/packet/LteRlcAmSdu_m.o: stack/rlc/am/packet/LteRlcAmSdu_m.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/rlc/am/packet/LteRlcAmSdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h
$O/stack/rlc/packet/LteRlcDataPdu.o: stack/rlc/packet/LteRlcDataPdu.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/packet/LteRlcDataPdu.h \
	stack/rlc/packet/LteRlcDataPdu_m.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/buffer/UmFragbuf.h
$O/stack/rlc/packet/LteRlcDataPdu_m.o: stack/rlc/packet/LteRlcDataPdu_m.cc \
	stack/rlc/packet/LteRlcDataPdu_m.h
$O/stack/rlc/packet/LteRlcPdu_m.o: stack/rlc/packet/LteRlcPdu_m.cc \
	stack/rlc/packet/LteRlcPdu_m.h
$O/stack/rlc/packet/LteRlcSdu_m.o: stack/rlc/packet/LteRlcSdu_m.cc \
	stack/rlc/packet/LteRlcSdu_m.h
$O/stack/rlc/tm/LteRlcTm.o: stack/rlc/tm/LteRlcTm.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/tm/LteRlcTm.h \
	stack/rlc/um/buffer/UmFragbuf.h
$O/stack/rlc/um/LteRlcUm.o: stack/rlc/um/LteRlcUm.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	stack/d2dModeSelection/D2DModeSwitchNotification_m.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/LteRlcUm.h \
	stack/rlc/um/buffer/UmFragbuf.h \
	stack/rlc/um/buffer/UmRxQueue.h \
	stack/rlc/um/buffer/UmTxQueue.h
$O/stack/rlc/um/LteRlcUmRealistic.o: stack/rlc/um/LteRlcUmRealistic.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/packet/LteMacSduRequest.h \
	stack/mac/packet/LteMacSduRequest_m.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/packet/LteRlcDataPdu.h \
	stack/rlc/packet/LteRlcDataPdu_m.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/LteRlcUm.h \
	stack/rlc/um/LteRlcUmRealistic.h \
	stack/rlc/um/buffer/UmFragbuf.h \
	stack/rlc/um/buffer/UmRxQueue.h \
	stack/rlc/um/buffer/UmTxQueue.h \
	stack/rlc/um/entity/UmRxEntity.h \
	stack/rlc/um/entity/UmTxEntity.h
$O/stack/rlc/um/LteRlcUmRealisticD2D.o: stack/rlc/um/LteRlcUmRealisticD2D.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	stack/d2dModeSelection/D2DModeSwitchNotification_m.h \
	stack/mac/layer/LteMacBase.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/packet/LteRlcDataPdu.h \
	stack/rlc/packet/LteRlcDataPdu_m.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/LteRlcUm.h \
	stack/rlc/um/LteRlcUmRealistic.h \
	stack/rlc/um/LteRlcUmRealisticD2D.h \
	stack/rlc/um/buffer/UmFragbuf.h \
	stack/rlc/um/buffer/UmRxQueue.h \
	stack/rlc/um/buffer/UmTxQueue.h \
	stack/rlc/um/entity/UmRxEntity.h \
	stack/rlc/um/entity/UmTxEntity.h
$O/stack/rlc/um/buffer/UmFragbuf.o: stack/rlc/um/buffer/UmFragbuf.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	stack/rlc/um/buffer/UmFragbuf.h
$O/stack/rlc/um/buffer/UmRxQueue.o: stack/rlc/um/buffer/UmRxQueue.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/LteRlcUm.h \
	stack/rlc/um/buffer/UmFragbuf.h \
	stack/rlc/um/buffer/UmRxQueue.h \
	stack/rlc/um/buffer/UmTxQueue.h
$O/stack/rlc/um/buffer/UmTxQueue.o: stack/rlc/um/buffer/UmTxQueue.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/LteRlcUm.h \
	stack/rlc/um/buffer/UmFragbuf.h \
	stack/rlc/um/buffer/UmRxQueue.h \
	stack/rlc/um/buffer/UmTxQueue.h
$O/stack/rlc/um/entity/UmRxEntity.o: stack/rlc/um/entity/UmRxEntity.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/packet/LteRlcDataPdu.h \
	stack/rlc/packet/LteRlcDataPdu_m.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/LteRlcUm.h \
	stack/rlc/um/LteRlcUmRealistic.h \
	stack/rlc/um/buffer/UmFragbuf.h \
	stack/rlc/um/buffer/UmRxQueue.h \
	stack/rlc/um/buffer/UmTxQueue.h \
	stack/rlc/um/entity/UmRxEntity.h \
	stack/rlc/um/entity/UmTxEntity.h
$O/stack/rlc/um/entity/UmTxEntity.o: stack/rlc/um/entity/UmTxEntity.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/LteControlInfo.h \
	common/LteControlInfo_m.h \
	common/lterecorder.h \
	common/timer/TMultiTimerMsg_m.h \
	common/timer/TTimer.h \
	common/timer/TTimerMsg_m.h \
	stack/mac/layer/LteMacBase.h \
	stack/pdcp_rrc/packet/LtePdcpPdu_m.h \
	stack/rlc/LteRlcDefs.h \
	stack/rlc/packet/LteRlcDataPdu.h \
	stack/rlc/packet/LteRlcDataPdu_m.h \
	stack/rlc/packet/LteRlcPdu.h \
	stack/rlc/packet/LteRlcPdu_m.h \
	stack/rlc/packet/LteRlcSdu.h \
	stack/rlc/packet/LteRlcSdu_m.h \
	stack/rlc/um/LteRlcUm.h \
	stack/rlc/um/LteRlcUmRealistic.h \
	stack/rlc/um/buffer/UmFragbuf.h \
	stack/rlc/um/buffer/UmRxQueue.h \
	stack/rlc/um/buffer/UmTxQueue.h \
	stack/rlc/um/entity/UmRxEntity.h \
	stack/rlc/um/entity/UmTxEntity.h
$O/world/radio/ChannelAccess.o: world/radio/ChannelAccess.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/ModuleAccess.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/common/geometry/common/EulerAngles.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/mobility/contract/IMobility.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	world/radio/ChannelAccess.h \
	world/radio/IChannelControl.h
$O/world/radio/ChannelControl.o: world/radio/ChannelControl.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/ModulationType.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h
$O/world/radio/LteChannelControl.o: world/radio/LteChannelControl.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	stack/phy/packet/AirFrame_m.h \
	stack/phy/packet/ModulationType.h \
	world/radio/ChannelControl.h \
	world/radio/IChannelControl.h \
	world/radio/LteChannelControl.h
$O/x2/LteX2Manager.o: x2/LteX2Manager.cc \
	$(INET_PROJ)/src/inet/applications/sctpapp/SCTPClient.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/PatternMatcher.h \
	$(INET_PROJ)/src/inet/common/Topology.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/lifecycle/LifecycleOperation.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/configurator/base/NetworkConfiguratorBase.h \
	$(INET_PROJ)/src/inet/networklayer/configurator/ipv4/IPv4NetworkConfigurator.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IIPv4RoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Route.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/sctp/SCTPCommand.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/sctp/SCTPCommand_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/sctp/SCTPSocket.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/nodes/ExtCell.h \
	x2/LteX2Manager.h \
	x2/X2AppClient.h \
	x2/packet/LteX2Message.h \
	x2/packet/LteX2Message_m.h \
	x2/packet/X2ControlInfo_m.h \
	x2/packet/X2InformationElement.h
$O/x2/X2AppClient.o: x2/X2AppClient.cc \
	$(INET_PROJ)/src/inet/applications/sctpapp/SCTPClient.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/lifecycle/LifecycleOperation.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3AddressResolver.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IIPv4RoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Route.h \
	$(INET_PROJ)/src/inet/networklayer/ipv6/IPv6Route.h \
	$(INET_PROJ)/src/inet/networklayer/ipv6/IPv6RoutingTable.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/ITransportPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/sctp/SCTPCommand.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/sctp/SCTPCommand_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/sctp/SCTPSocket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPSocket.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTP.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTPAssociation.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTPGapList.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTPMessage.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTPMessage_m.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTPQueue.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTPReceiveStream.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTPSendStream.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/deployer/LteDeployer.h \
	corenetwork/nodes/ExtCell.h \
	stack/mac/amc/AmcPilot.h \
	stack/mac/amc/LteAmc.h \
	stack/mac/amc/LteMcs.h \
	stack/mac/amc/UserTxParams.h \
	stack/mac/layer/LteMacBase.h \
	stack/mac/layer/LteMacEnb.h \
	stack/phy/das/RemoteAntennaSet.h \
	stack/phy/feedback/LteFeedback.h \
	x2/X2AppClient.h
$O/x2/X2AppServer.o: x2/X2AppServer.cc \
	$(INET_PROJ)/src/inet/applications/sctpapp/SCTPServer.h \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/NotifierConsts.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/common/lifecycle/ILifecycle.h \
	$(INET_PROJ)/src/inet/common/lifecycle/LifecycleOperation.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/inet/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IInterfaceTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoute.h \
	$(INET_PROJ)/src/inet/networklayer/contract/IRoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IIPv4RoutingTable.h \
	$(INET_PROJ)/src/inet/networklayer/ipv4/IPv4Route.h \
	$(INET_PROJ)/src/inet/networklayer/ipv6/IPv6Route.h \
	$(INET_PROJ)/src/inet/networklayer/ipv6/IPv6RoutingTable.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/ITransportPacket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/sctp/SCTPCommand.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/sctp/SCTPCommand_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/sctp/SCTPSocket.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPControlInfo_m.h \
	$(INET_PROJ)/src/inet/transportlayer/contract/udp/UDPSocket.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTP.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTPAssociation.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTPGapList.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTPMessage.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTPMessage_m.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTPQueue.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTPReceiveStream.h \
	$(INET_PROJ)/src/inet/transportlayer/sctp/SCTPSendStream.h \
	common/LteCommon.h \
	common/lterecorder.h \
	corenetwork/binder/LteBinder.h \
	corenetwork/binder/PhyPisaData.h \
	corenetwork/nodes/ExtCell.h \
	x2/X2AppServer.h
$O/x2/packet/LteX2Message_m.o: x2/packet/LteX2Message_m.cc \
	x2/packet/LteX2Message_m.h
$O/x2/packet/X2ControlInfo_m.o: x2/packet/X2ControlInfo_m.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	common/LteCommon.h \
	common/lterecorder.h \
	x2/packet/X2ControlInfo_m.h

