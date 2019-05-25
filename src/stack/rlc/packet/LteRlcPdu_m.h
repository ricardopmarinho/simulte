//
// Generated file, do not edit! Created by nedtool 5.0 from stack/rlc/packet/LteRlcPdu.msg.
//

#ifndef __LTERLCPDU_M_H
#define __LTERLCPDU_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>stack/rlc/packet/LteRlcPdu.msg:18</tt> by nedtool.
 * <pre>
 * //
 * // This is the RLC Pdu
 * // flowing through LTE stack: basically
 * // it contains the fields of a fragment
 * // that receiver needs in order to
 * // correctly decode the original packet
 * //
 * packet LteRlcPdu
 * {
 *     @customize(true);
 *     unsigned int totalFragments;    // Total number of fragments
 *     unsigned int snoFragment;        // Sequence number of this fragment
 *     unsigned int snoMainPacket;        // ID of packet (sequence number)
 * }
 * </pre>
 *
 * LteRlcPdu_Base is only useful if it gets subclassed, and LteRlcPdu is derived from it.
 * The minimum code to be written for LteRlcPdu is the following:
 *
 * <pre>
 * class LteRlcPdu : public LteRlcPdu_Base
 * {
 *   private:
 *     void copy(const LteRlcPdu& other) { ... }

 *   public:
 *     LteRlcPdu(const char *name=nullptr, int kind=0) : LteRlcPdu_Base(name,kind) {}
 *     LteRlcPdu(const LteRlcPdu& other) : LteRlcPdu_Base(other) {copy(other);}
 *     LteRlcPdu& operator=(const LteRlcPdu& other) {if (this==&other) return *this; LteRlcPdu_Base::operator=(other); copy(other); return *this;}
 *     virtual LteRlcPdu *dup() const {return new LteRlcPdu(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from LteRlcPdu_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(LteRlcPdu);
 * </pre>
 */
class LteRlcPdu_Base : public ::omnetpp::cPacket
{
  protected:
    unsigned int totalFragments;
    unsigned int snoFragment;
    unsigned int snoMainPacket;

  private:
    void copy(const LteRlcPdu_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LteRlcPdu_Base&);
    // make constructors protected to avoid instantiation
    LteRlcPdu_Base(const char *name=nullptr, int kind=0);
    LteRlcPdu_Base(const LteRlcPdu_Base& other);
    // make assignment operator protected to force the user override it
    LteRlcPdu_Base& operator=(const LteRlcPdu_Base& other);

  public:
    virtual ~LteRlcPdu_Base();
    virtual LteRlcPdu_Base *dup() const {throw omnetpp::cRuntimeError("You forgot to manually add a dup() function to class LteRlcPdu");}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getTotalFragments() const;
    virtual void setTotalFragments(unsigned int totalFragments);
    virtual unsigned int getSnoFragment() const;
    virtual void setSnoFragment(unsigned int snoFragment);
    virtual unsigned int getSnoMainPacket() const;
    virtual void setSnoMainPacket(unsigned int snoMainPacket);
};


#endif // ifndef __LTERLCPDU_M_H

