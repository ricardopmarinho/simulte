//
//                           SimuLTE
//
// This file is part of a software released under the license included in file
// "license.pdf". This license can be also found at http://www.ltesimulator.com/
// The above file and the present reference are part of the software itself,
// and cannot be removed from it.
//

#ifndef _LTE_LTEMACUEREALISTICD2D_H_
#define _LTE_LTEMACUEREALISTICD2D_H_

#include "stack/mac/layer/LteMacUeRealistic.h"
#include "stack/mac/layer/LteMacEnbRealisticD2D.h"
#include "stack/mac/buffer/harq_d2d/LteHarqBufferTxD2D.h"

class LteSchedulingGrant;
class LteSchedulerUeUl;
class LteBinder;

class LteMacUeRealisticD2D : public LteMacUeRealistic
{
    // reference to the eNB
    LteMacEnbRealisticD2D* enb_;

    // RAC Handling variables
    bool racD2DMulticastRequested_;
    // Multicast D2D BSR handling
    bool bsrD2DMulticastTriggered_;

    // if true, use the preconfigured TX params for transmission, else use that signaled by the eNB
    bool usePreconfiguredTxParams_;
    UserTxParams* preconfiguredTxParams_;
    UserTxParams* getPreconfiguredTxParams();  // build and return new user tx params

  protected:



    //////////////////
    simsignal_t cainMessageSentSignal;
    simsignal_t cainHopMesasgeSentSignal;
    simsignal_t dropedCainMessageSignal;
    simsignal_t dropedHopMessageSignal;
    long cainMessageSent = 0;
    long cainHopMessageSent = 0;
    long dropedCainMessage = 0;
    long dropedHopMessage = 0;
    //////////////////

    /**
     * Reads MAC parameters for ue and performs initialization.
     */
    virtual void initialize(int stage);

    /**
     * Analyze gate of incoming packet
     * and call proper handler
     */
    virtual void handleMessage(cMessage *msg);

    /**
     * Main loop
     */
    virtual void handleSelfMessage();

    virtual void macHandleGrant(cPacket* pkt);

    /*
     * Checks RAC status
     */
    virtual void checkRAC();

    /*
     * Receives and handles RAC responses
     */
    virtual void macHandleRac(cPacket* pkt);

    /*
     * Handles CAIN message on UE
     * */
    virtual void handleCainMsg(cPacket* pkt);

    /*
     * Returns the chosen relay for the message
     * */
    virtual MacNodeId getRelay(std::vector<std::string> relayVect);

    /*
     * Returns a vector of nodes that need a relay
     * */
    virtual std::vector<MacNodeId> getNode(std::string nodeSinr);

    /*
     * Returns the nodes for the three hop forwarding
     * */
    virtual std::vector<MacNodeId> getHopNodes(std::string nodeSinr);

    void macHandleD2DModeSwitch(cPacket* pkt);

    std::vector<std::string> getMessageType(std::string str, char delimeter);

    virtual LteMacPdu* makeBsr(int size);

    /**
     * macPduMake() creates MAC PDUs (one for each CID)
     * by extracting SDUs from Real Mac Buffers according
     * to the Schedule List.
     * It sends them to H-ARQ (at the moment lower layer)
     *
     * On UE it also adds a BSR control element to the MAC PDU
     * containing the size of its buffer (for that CID)
     */
    virtual void macPduMake();
    /*
     * Check the repList, if the list contains
     * nodeId return true, otherwise, false
     * */
    bool checkRepList(MacNodeId nodeId);

    void removeNodeRepList(MacNodeId nodeId);

    /*
     * Method to update relay list, therefore the UE that
     * calls this method needs a relay.
     * We must search for 'relayId' at the sinrMapB
     * */
    bool updateRelayList(MacNodeId relayId);

    void printRelayList(MacNodeId nodeId);


  public:
    LteMacUeRealisticD2D();
    virtual ~LteMacUeRealisticD2D();

    virtual bool isD2DCapable()
    {
        return true;
    }

    virtual void triggerBsr(MacCid cid)
    {
        if (connDesc_[cid].getDirection() == D2D_MULTI)
            bsrD2DMulticastTriggered_ = true;
        else
            bsrTriggered_ = true;
    }
};

#endif
