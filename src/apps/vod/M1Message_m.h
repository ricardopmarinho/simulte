//
// Generated file, do not edit! Created by nedtool 5.0 from apps/vod/M1Message.msg.
//

#ifndef __M1MESSAGE_M_H
#define __M1MESSAGE_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "inet/networklayer/common/L3Address.h"
// }}

/**
 * Class generated from <tt>apps/vod/M1Message.msg:16</tt> by nedtool.
 * <pre>
 * message M1Message
 * {
 *     inet::L3Address clientAddr;   // client address
 *     int clientPort;           // client UDP port
 *     long numPkSent;           // number of packets sent
 * }
 * </pre>
 */
class M1Message : public ::omnetpp::cMessage
{
  protected:
    inet::L3Address clientAddr;
    int clientPort;
    long numPkSent;

  private:
    void copy(const M1Message& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const M1Message&);

  public:
    M1Message(const char *name=nullptr, int kind=0);
    M1Message(const M1Message& other);
    virtual ~M1Message();
    M1Message& operator=(const M1Message& other);
    virtual M1Message *dup() const {return new M1Message(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual inet::L3Address& getClientAddr();
    virtual const inet::L3Address& getClientAddr() const {return const_cast<M1Message*>(this)->getClientAddr();}
    virtual void setClientAddr(const inet::L3Address& clientAddr);
    virtual int getClientPort() const;
    virtual void setClientPort(int clientPort);
    virtual long getNumPkSent() const;
    virtual void setNumPkSent(long numPkSent);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const M1Message& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, M1Message& obj) {obj.parsimUnpack(b);}


#endif // ifndef __M1MESSAGE_M_H

