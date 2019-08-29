//
// Generated file, do not edit! Created by nedtool 5.0 from stack/rlc/am/packet/LteRlcAmSdu.msg.
//

#ifndef __LTERLCAMSDU_M_H
#define __LTERLCAMSDU_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "stack/rlc/packet/LteRlcSdu.h"
// }}

/**
 * Class generated from <tt>stack/rlc/am/packet/LteRlcAmSdu.msg:17</tt> by nedtool.
 * <pre>
 * packet LteRlcAmSdu extends LteRlcSdu
 * {
 * }
 * </pre>
 */
class LteRlcAmSdu : public ::LteRlcSdu
{
  protected:

  private:
    void copy(const LteRlcAmSdu& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LteRlcAmSdu&);

  public:
    LteRlcAmSdu(const char *name=nullptr, int kind=0);
    LteRlcAmSdu(const LteRlcAmSdu& other);
    virtual ~LteRlcAmSdu();
    LteRlcAmSdu& operator=(const LteRlcAmSdu& other);
    virtual LteRlcAmSdu *dup() const {return new LteRlcAmSdu(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LteRlcAmSdu& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LteRlcAmSdu& obj) {obj.parsimUnpack(b);}


#endif // ifndef __LTERLCAMSDU_M_H

