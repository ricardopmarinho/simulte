//
// Generated file, do not edit! Created by nedtool 5.0 from common/LteControlInfo.msg.
//

#ifndef __LTECONTROLINFO_M_H
#define __LTECONTROLINFO_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
    #include "common/LteCommon.h"
// }}

/**
 * Class generated from <tt>common/LteControlInfo.msg:50</tt> by nedtool.
 * <pre>
 * //
 * // @class LteControlInfo
 * // @brief Base class for FlowControlInfo and UserControlInfo
 * //
 * // This class contains information present in both Flow and User ControlInfo:
 * // - Source MAC Node ID
 * // - Destination MAC Node ID
 * //
 * class LteControlInfo
 * {
 *     uint16 sourceId;                                     // Source MacNodeId
 *     uint16 destId;                                       // Destination MacNodeId
 *     unsigned short direction @enum(Direction);            // Traffic Direction (UL, DL, D2D)
 *     uint16 d2dTxPeerId;
 *     uint16 d2dRxPeerId;
 * 
 *     //# Traffic Control Information
 * 
 *     unsigned short application @enum(ApplicationType);    // Application Type
 *     unsigned short traffic @enum(LteTrafficClass);        // Lte Traffic Type
 * 
 *     //# RLC Control Information
 * 
 *     unsigned short rlcType @enum(LteRlcType);            // RLC Traffic Type
 * 
 *     //# Connection Information
 * 
 *     uint16 lcid;                                        // Logical Connection Identifier
 *     int32 multicastGroupId = -1;                        // Identifier for a multicast group (it is in range [0:[2^28)-1] ) 
 *                                                         // For unicast communications, this field is -1
 * 
 * }
 * </pre>
 */
class LteControlInfo : public ::omnetpp::cObject
{
  protected:
    uint16_t sourceId;
    uint16_t destId;
    unsigned short direction;
    uint16_t d2dTxPeerId;
    uint16_t d2dRxPeerId;
    unsigned short application;
    unsigned short traffic;
    unsigned short rlcType;
    uint16_t lcid;
    int32_t multicastGroupId;

  private:
    void copy(const LteControlInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LteControlInfo&);

  public:
    LteControlInfo();
    LteControlInfo(const LteControlInfo& other);
    virtual ~LteControlInfo();
    LteControlInfo& operator=(const LteControlInfo& other);
    virtual LteControlInfo *dup() const {return new LteControlInfo(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual uint16_t getSourceId() const;
    virtual void setSourceId(uint16_t sourceId);
    virtual uint16_t getDestId() const;
    virtual void setDestId(uint16_t destId);
    virtual unsigned short getDirection() const;
    virtual void setDirection(unsigned short direction);
    virtual uint16_t getD2dTxPeerId() const;
    virtual void setD2dTxPeerId(uint16_t d2dTxPeerId);
    virtual uint16_t getD2dRxPeerId() const;
    virtual void setD2dRxPeerId(uint16_t d2dRxPeerId);
    virtual unsigned short getApplication() const;
    virtual void setApplication(unsigned short application);
    virtual unsigned short getTraffic() const;
    virtual void setTraffic(unsigned short traffic);
    virtual unsigned short getRlcType() const;
    virtual void setRlcType(unsigned short rlcType);
    virtual uint16_t getLcid() const;
    virtual void setLcid(uint16_t lcid);
    virtual int32_t getMulticastGroupId() const;
    virtual void setMulticastGroupId(int32_t multicastGroupId);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LteControlInfo& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LteControlInfo& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>common/LteControlInfo.msg:87</tt> by nedtool.
 * <pre>
 * //
 * // @class FlowControlInfo
 * // @brief contains information flowing from LteIp to Mac
 * //
 * // It contains the following information:
 * // - IP Control Informations: the four tuple, a sequence number and
 * //   the header size (IP + Transport) to be used by pdcp ROHC.
 * // - Traffic Control Informations: Application, Direction, Traffic
 * // - RLC Control Informations: the traffic type (TM, UM, AM)
 * // - Connection information: Logical CID
 * //
 * class FlowControlInfo extends LteControlInfo
 * {
 *     uint32 srcAddr;                                       // source IP
 *     uint32 dstAddr;                                       // destination IP
 *     uint16 srcPort;                                          // source port
 *     uint16 dstPort;                                       // destination port
 *     unsigned int sequenceNumber;                          // packet sequence number
 *     int headerSize;                                       // IP + Transport header size (used by pdcp ROHC)
 * }
 * </pre>
 */
class FlowControlInfo : public ::LteControlInfo
{
  protected:
    uint32_t srcAddr;
    uint32_t dstAddr;
    uint16_t srcPort;
    uint16_t dstPort;
    unsigned int sequenceNumber;
    int headerSize;

  private:
    void copy(const FlowControlInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const FlowControlInfo&);

  public:
    FlowControlInfo();
    FlowControlInfo(const FlowControlInfo& other);
    virtual ~FlowControlInfo();
    FlowControlInfo& operator=(const FlowControlInfo& other);
    virtual FlowControlInfo *dup() const {return new FlowControlInfo(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual uint32_t getSrcAddr() const;
    virtual void setSrcAddr(uint32_t srcAddr);
    virtual uint32_t getDstAddr() const;
    virtual void setDstAddr(uint32_t dstAddr);
    virtual uint16_t getSrcPort() const;
    virtual void setSrcPort(uint16_t srcPort);
    virtual uint16_t getDstPort() const;
    virtual void setDstPort(uint16_t dstPort);
    virtual unsigned int getSequenceNumber() const;
    virtual void setSequenceNumber(unsigned int sequenceNumber);
    virtual int getHeaderSize() const;
    virtual void setHeaderSize(int headerSize);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const FlowControlInfo& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, FlowControlInfo& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>common/LteControlInfo.msg:108</tt> by nedtool.
 * <pre>
 * //
 * // @class UserControlInfo
 * // @brief contains information flowing from Mac to Phy
 * //
 * // It contains the following information:
 * // - H-ARQ Control Information
 * // - PHY Control Informations: Broadcast, Corruption, Type,
 * //   txMode, Resource blocks used, RemoteSet
 * //
 * class UserControlInfo extends LteControlInfo
 * {
 *     @customize(true);
 * 
 *     //# H-ARQ Control Information
 * 
 *     unsigned char acid;                // H-ARQ process identifier
 *     unsigned char cw;                // H-ARQ codeword identifier
 *     unsigned char txNumber = 0;            // number of (re)transmissions for the same pdu (1, 2, 3, 4)
 *     bool ndi = true;                    // new data indicator (new data overwrites a process content if present)
 * 
 *     //# PHY Control Informations
 * 
 *     bool isCorruptible;                                // Frame is corruptible
 *     bool isBroadcast = false;                        // Broadcast packet
 *     bool deciderResult;                                // Decider result
 *     double blerTh;                                    // Calculated BLER threshold for this transmission
 *     double blerValue;                                // Extracted BLER for this transmission (blerValue > blerTh ==> corrupted)
 *     unsigned short txMode @enum(TxMode);                // Traffic Type
 *     unsigned int frameType @enum(LtePhyFrameType);    // Frame Type
 *     double txPower;                                    //Transmission Power
 *     double d2dTxPower;                                 //D2D Transmission Power (used for feedback reporting of D2D links
 *     // blocks granted on all Remotes, all Bands
 *     unsigned int totalGrantedBlocks;
 * 
 *     //#
 *     //# Follows a list of elements only present in
 *     //# the customized class (see LteControlInfo.h):
 *     //#
 *     //# RemoteSet ru;                                // Remote Antenna Set
 *     //# RbMap grantedBlocks;                        // Blocks allocated per Remote, per Band.
 * 
 *      ///////////////////////////
 *     unsigned short CAINDirection @enum(CAINDirection); 	// Traffic Direction (INF, REL, REP)
 *     bool CAINEnable = false;							// False if the message is not a CAIN, true otherwise
 *     uint16 eNBId;
 *     double CAINuePwr;									// Relay's power value
 *     uint16 CAINdest;									// CAIN Served node 
 *     /////////////////////////
 * }
 * </pre>
 *
 * UserControlInfo_Base is only useful if it gets subclassed, and UserControlInfo is derived from it.
 * The minimum code to be written for UserControlInfo is the following:
 *
 * <pre>
 * class UserControlInfo : public UserControlInfo_Base
 * {
 *   private:
 *     void copy(const UserControlInfo& other) { ... }

 *   public:
 *     UserControlInfo() : UserControlInfo_Base() {}
 *     UserControlInfo(const UserControlInfo& other) : UserControlInfo_Base(other) {copy(other);}
 *     UserControlInfo& operator=(const UserControlInfo& other) {if (this==&other) return *this; UserControlInfo_Base::operator=(other); copy(other); return *this;}
 *     virtual UserControlInfo *dup() const {return new UserControlInfo(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from UserControlInfo_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(UserControlInfo);
 * </pre>
 */
class UserControlInfo_Base : public ::LteControlInfo
{
  protected:
    unsigned char acid;
    unsigned char cw;
    unsigned char txNumber;
    bool ndi;
    bool isCorruptible;
    bool isBroadcast;
    bool deciderResult;
    double blerTh;
    double blerValue;
    unsigned short txMode;
    unsigned int frameType;
    double txPower;
    double d2dTxPower;
    unsigned int totalGrantedBlocks;
    unsigned short CAINDirection;
    bool CAINEnable;
    uint16_t eNBId;
    double CAINuePwr;
    uint16_t CAINdest;

  private:
    void copy(const UserControlInfo_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const UserControlInfo_Base&);
    // make constructors protected to avoid instantiation
    UserControlInfo_Base();
    UserControlInfo_Base(const UserControlInfo_Base& other);
    // make assignment operator protected to force the user override it
    UserControlInfo_Base& operator=(const UserControlInfo_Base& other);

  public:
    virtual ~UserControlInfo_Base();
    virtual UserControlInfo_Base *dup() const {throw omnetpp::cRuntimeError("You forgot to manually add a dup() function to class UserControlInfo");}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned char getAcid() const;
    virtual void setAcid(unsigned char acid);
    virtual unsigned char getCw() const;
    virtual void setCw(unsigned char cw);
    virtual unsigned char getTxNumber() const;
    virtual void setTxNumber(unsigned char txNumber);
    virtual bool getNdi() const;
    virtual void setNdi(bool ndi);
    virtual bool getIsCorruptible() const;
    virtual void setIsCorruptible(bool isCorruptible);
    virtual bool getIsBroadcast() const;
    virtual void setIsBroadcast(bool isBroadcast);
    virtual bool getDeciderResult() const;
    virtual void setDeciderResult(bool deciderResult);
    virtual double getBlerTh() const;
    virtual void setBlerTh(double blerTh);
    virtual double getBlerValue() const;
    virtual void setBlerValue(double blerValue);
    virtual unsigned short getTxMode() const;
    virtual void setTxMode(unsigned short txMode);
    virtual unsigned int getFrameType() const;
    virtual void setFrameType(unsigned int frameType);
    virtual double getTxPower() const;
    virtual void setTxPower(double txPower);
    virtual double getD2dTxPower() const;
    virtual void setD2dTxPower(double d2dTxPower);
    virtual unsigned int getTotalGrantedBlocks() const;
    virtual void setTotalGrantedBlocks(unsigned int totalGrantedBlocks);
    virtual unsigned short getCAINDirection() const;
    virtual void setCAINDirection(unsigned short CAINDirection);
    virtual bool getCAINEnable() const;
    virtual void setCAINEnable(bool CAINEnable);
    virtual uint16_t getENBId() const;
    virtual void setENBId(uint16_t eNBId);
    virtual double getCAINuePwr() const;
    virtual void setCAINuePwr(double CAINuePwr);
    virtual uint16_t getCAINdest() const;
    virtual void setCAINdest(uint16_t CAINdest);
};

/**
 * Class generated from <tt>common/LteControlInfo.msg:148</tt> by nedtool.
 * <pre>
 * class CAINControlInfo extends LteControlInfo
 * {
 *     @customize(true);
 * 
 * //# H-ARQ Control Information
 * 
 *     unsigned char acid;                // H-ARQ process identifier
 *     unsigned char cw;                // H-ARQ codeword identifier
 *     unsigned char txNumber = 0;            // number of (re)transmissions for the same pdu (1, 2, 3, 4)
 *     bool ndi = true;                    // new data indicator (new data overwrites a process content if present)
 * 
 *     //# PHY Control Informations
 * 
 *     bool isCorruptible;                                // Frame is corruptible
 *     bool isBroadcast = false;                        // Broadcast packet
 *     bool deciderResult;                                // Decider result
 *     double blerTh;                                    // Calculated BLER threshold for this transmission
 *     double blerValue;                                // Extracted BLER for this transmission (blerValue > blerTh ==> corrupted)
 *     unsigned short txMode @enum(TxMode);                // Traffic Type
 *     unsigned int frameType @enum(LtePhyFrameType);    // Frame Type
 *     double txPower;                                    //Transmission Power
 *     double d2dTxPower;                                 //D2D Transmission Power (used for feedback reporting of D2D links
 *     // blocks granted on all Remotes, all Bands
 *     unsigned int totalGrantedBlocks;
 * 
 *     ///////////////////////////
 *     unsigned short CAINDirection @enum(CAINDirection); 	// Traffic Direction (INF, REL, REP)
 *     /////////////////////////
 * }
 * </pre>
 *
 * CAINControlInfo_Base is only useful if it gets subclassed, and CAINControlInfo is derived from it.
 * The minimum code to be written for CAINControlInfo is the following:
 *
 * <pre>
 * class CAINControlInfo : public CAINControlInfo_Base
 * {
 *   private:
 *     void copy(const CAINControlInfo& other) { ... }

 *   public:
 *     CAINControlInfo() : CAINControlInfo_Base() {}
 *     CAINControlInfo(const CAINControlInfo& other) : CAINControlInfo_Base(other) {copy(other);}
 *     CAINControlInfo& operator=(const CAINControlInfo& other) {if (this==&other) return *this; CAINControlInfo_Base::operator=(other); copy(other); return *this;}
 *     virtual CAINControlInfo *dup() const {return new CAINControlInfo(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from CAINControlInfo_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(CAINControlInfo);
 * </pre>
 */
class CAINControlInfo_Base : public ::LteControlInfo
{
  protected:
    unsigned char acid;
    unsigned char cw;
    unsigned char txNumber;
    bool ndi;
    bool isCorruptible;
    bool isBroadcast;
    bool deciderResult;
    double blerTh;
    double blerValue;
    unsigned short txMode;
    unsigned int frameType;
    double txPower;
    double d2dTxPower;
    unsigned int totalGrantedBlocks;
    unsigned short CAINDirection;

  private:
    void copy(const CAINControlInfo_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const CAINControlInfo_Base&);
    // make constructors protected to avoid instantiation
    CAINControlInfo_Base();
    CAINControlInfo_Base(const CAINControlInfo_Base& other);
    // make assignment operator protected to force the user override it
    CAINControlInfo_Base& operator=(const CAINControlInfo_Base& other);

  public:
    virtual ~CAINControlInfo_Base();
    virtual CAINControlInfo_Base *dup() const {throw omnetpp::cRuntimeError("You forgot to manually add a dup() function to class CAINControlInfo");}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned char getAcid() const;
    virtual void setAcid(unsigned char acid);
    virtual unsigned char getCw() const;
    virtual void setCw(unsigned char cw);
    virtual unsigned char getTxNumber() const;
    virtual void setTxNumber(unsigned char txNumber);
    virtual bool getNdi() const;
    virtual void setNdi(bool ndi);
    virtual bool getIsCorruptible() const;
    virtual void setIsCorruptible(bool isCorruptible);
    virtual bool getIsBroadcast() const;
    virtual void setIsBroadcast(bool isBroadcast);
    virtual bool getDeciderResult() const;
    virtual void setDeciderResult(bool deciderResult);
    virtual double getBlerTh() const;
    virtual void setBlerTh(double blerTh);
    virtual double getBlerValue() const;
    virtual void setBlerValue(double blerValue);
    virtual unsigned short getTxMode() const;
    virtual void setTxMode(unsigned short txMode);
    virtual unsigned int getFrameType() const;
    virtual void setFrameType(unsigned int frameType);
    virtual double getTxPower() const;
    virtual void setTxPower(double txPower);
    virtual double getD2dTxPower() const;
    virtual void setD2dTxPower(double d2dTxPower);
    virtual unsigned int getTotalGrantedBlocks() const;
    virtual void setTotalGrantedBlocks(unsigned int totalGrantedBlocks);
    virtual unsigned short getCAINDirection() const;
    virtual void setCAINDirection(unsigned short CAINDirection);
};


#endif // ifndef __LTECONTROLINFO_M_H

