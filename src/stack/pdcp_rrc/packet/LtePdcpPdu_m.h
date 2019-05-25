//
// Generated file, do not edit! Created by nedtool 5.0 from stack/pdcp_rrc/packet/LtePdcpPdu.msg.
//

#ifndef __LTEPDCPPDU_M_H
#define __LTEPDCPPDU_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>stack/pdcp_rrc/packet/LtePdcpPdu.msg:15</tt> by nedtool.
 * <pre>
 * //
 * // This is the PDCP message flowing through LTE stack.
 * //
 * packet LtePdcpPdu
 * {
 * }
 * </pre>
 */
class LtePdcpPdu : public ::omnetpp::cPacket
{
  protected:

  private:
    void copy(const LtePdcpPdu& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LtePdcpPdu&);

  public:
    LtePdcpPdu(const char *name=nullptr, int kind=0);
    LtePdcpPdu(const LtePdcpPdu& other);
    virtual ~LtePdcpPdu();
    LtePdcpPdu& operator=(const LtePdcpPdu& other);
    virtual LtePdcpPdu *dup() const {return new LtePdcpPdu(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LtePdcpPdu& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LtePdcpPdu& obj) {obj.parsimUnpack(b);}


#endif // ifndef __LTEPDCPPDU_M_H

