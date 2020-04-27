//
//                           SimuLTE
//
// This file is part of a software released under the license included in file
// "license.pdf". This license can be also found at http://www.ltesimulator.com/
// The above file and the present reference are part of the software itself,
// and cannot be removed from it.
//

#ifndef _LTE_LTECONTROLINFO_H_
#define _LTE_LTECONTROLINFO_H_

#include "common/LteControlInfo_m.h"
#include <vector>

class UserTxParams;

using namespace inet;

/**
 * @class UserControlInfo
 * @brief ControlInfo used in the Lte model
 *
 * This is the LteControlInfo Resource Block Vector
 * and Remote Antennas Set
 *
 */
class UserControlInfo : public UserControlInfo_Base
{
  protected:

    const UserTxParams* userTxParams;
    RbMap grantedBlocks;
    /** @brief The movement of the sending host.*/
    //Move senderMovement;
    /** @brief The playground position of the sending host.*/
    Coord senderCoord;
    //////////////////////////////
    std::string CAINoptions;
    Coord enbCoord;
    Coord CAINCoord;
    Coord CAINHopCoord;
    coordList nodesCoord;
    /////////////////////////////

  public:

    /**
     * Constructor: base initialization
     * @param name packet name
     * @param kind packet kind
     */
    UserControlInfo();
    virtual ~UserControlInfo();

    /*
     * Operator = : packet copy
     * @param other source packet
     * @return reference to this packet
     */
    UserControlInfo& operator=(const UserControlInfo& other);

    /**
     * Copy constructor: packet copy
     * @param other source packet
     */
    UserControlInfo(const UserControlInfo& other) :
        UserControlInfo_Base()
    {
        operator=(other);
    }

    /**
     * dup() : packet duplicate
     * @return pointer to duplicate packet
     */
    virtual UserControlInfo *dup() const
    {
        return new UserControlInfo(*this);
    }

    void setUserTxParams(const UserTxParams* arg);

    const UserTxParams* getUserTxParams() const
    {
        return userTxParams;
    }

    const unsigned int getBlocks(Remote antenna, Band b) const
        {
        return grantedBlocks.at(antenna).at(b);
    }

    void setBlocks(Remote antenna, Band b, const unsigned int blocks)
    {
        grantedBlocks[antenna][b] = blocks;
    }

    const RbMap& getGrantedBlocks() const
    {
        return grantedBlocks;
    }

    void setGrantedBlocks(const RbMap& rbMap)
    {
        grantedBlocks = rbMap;
    }

    // struct used to request a feedback computation by nodeB
    FeedbackRequest feedbackReq;
    void setCoord(const Coord& coord);
    Coord getCoord() const;
<<<<<<< HEAD

=======


    /////////////////////////////////////////////////////////////////////////////////////////////////////
    void appendOption(std::string newOpt);
    void setCAINOption(std::string newOpt);
    std::string getCAINOptions();
    void setEnbCoord(const Coord& coord);
    Coord getEnbCoord() const;
    void setCAINCoord(const Coord& coord);
    Coord getCAINCoord() const;
    void setCAINHopCoord(const Coord& coord);
    Coord getCAINHopCoord() const;
    void setMapCoord(const coordList& nodes);
    coordList getMapCoord();
    /////////////////////////////////////////////////////////////////////////////////////////////////////

};

<<<<<<< HEAD
=======
Register_Class(UserControlInfo);

class CAINControlInfo : public CAINControlInfo_Base{
    protected:

        const UserTxParams* userTxParams;
        RbMap grantedBlocks;
        /** @brief The movement of the sending host.*/
        //Move senderMovement;
        /** @brief The playground position of the sending host.*/
        Coord senderCoord;

      public:

        /**
         * Constructor: base initialization
         * @param name packet name
         * @param kind packet kind
         */
        CAINControlInfo();
        virtual ~CAINControlInfo();

        /*
         * Operator = : packet copy
         * @param other source packet
         * @return reference to this packet
         */
        CAINControlInfo& operator=(const CAINControlInfo& other);

        /**
         * Copy constructor: packet copy
         * @param other source packet
         */
        CAINControlInfo(const CAINControlInfo& other) :
            CAINControlInfo_Base()
        {
            operator=(other);
        }

        /**
         * dup() : packet duplicate
         * @return pointer to duplicate packet
         */
        virtual CAINControlInfo *dup() const
        {
            return new CAINControlInfo(*this);
        }

        void setUserTxParams(const UserTxParams* arg);

        const UserTxParams* getUserTxParams() const
        {
            return userTxParams;
        }

        const unsigned int getBlocks(Remote antenna, Band b) const
            {
            return grantedBlocks.at(antenna).at(b);
        }

        void setBlocks(Remote antenna, Band b, const unsigned int blocks)
        {
            grantedBlocks[antenna][b] = blocks;
        }

        const RbMap& getGrantedBlocks() const
        {
            return grantedBlocks;
        }

        void setGrantedBlocks(const RbMap& rbMap)
        {
            grantedBlocks = rbMap;
        }

        // struct used to request a feedback computation by nodeB
        FeedbackRequest feedbackReq;
        void setCoord(const Coord& coord);
        Coord getCoord() const;
};
>>>>>>> 5bdd6e6e24f045a4424f1e198edd7074414c0413

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    void appendOption(std::string newOpt);
    void setCAINOption(std::string newOpt);
    std::string getCAINOptions();
    void setEnbCoord(const Coord& coord);
    Coord getEnbCoord() const;
    void setCAINCoord(const Coord& coord);
    Coord getCAINCoord() const;
    void setCAINHopCoord(const Coord& coord);
    Coord getCAINHopCoord() const;
    void setMapCoord(const coordList& nodes);
    coordList getMapCoord();
    /////////////////////////////////////////////////////////////////////////////////////////////////////

};

>>>>>>> bf91fb2974eb8cc99ac703dad8430d7e62be7846
#endif

