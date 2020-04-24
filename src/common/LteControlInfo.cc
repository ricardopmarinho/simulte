//
//                           SimuLTE
//
// This file is part of a software released under the license included in file
// "license.pdf". This license can be also found at http://www.ltesimulator.com/
// The above file and the present reference are part of the software itself,
// and cannot be removed from it.
//

#include "common/LteControlInfo.h"
#include "stack/mac/amc/UserTxParams.h"
#include "common/LteControlInfo_m.h"

UserControlInfo::~UserControlInfo()
{
    if (userTxParams != NULL)
    {
        delete userTxParams;
        userTxParams = NULL;
    }
}

UserControlInfo::UserControlInfo() :
    UserControlInfo_Base()
{
    userTxParams = NULL;
    grantedBlocks.clear();
}

UserControlInfo& UserControlInfo::operator=(const UserControlInfo& other)
{
    if (&other == this)
        return *this;

    if (other.userTxParams != NULL)
    {
        const UserTxParams* txParams = check_and_cast<const UserTxParams*>(other.userTxParams);
        this->userTxParams = txParams->dup();
    }
    else
    {
        this->userTxParams = NULL;
    }
    this->grantedBlocks = other.grantedBlocks;
    this->senderCoord = other.senderCoord;
    UserControlInfo_Base::operator=(other);
    return *this;
}

void UserControlInfo::setCoord(const Coord& coord)
{
    senderCoord = coord;
}

void UserControlInfo::setUserTxParams(const UserTxParams *newParams)
{
    if(userTxParams != NULL){
        delete userTxParams;
    }
    userTxParams = newParams;
}


Coord UserControlInfo::getCoord() const
{
    return senderCoord;
}

void UserControlInfo::appendOption(std::string newOpt){
    if(this->CAINoptions.empty())
        this->CAINoptions=newOpt;
    else
        this->CAINoptions.append(";"+newOpt);
<<<<<<< HEAD
}


void UserControlInfo::setCAINOption(std::string newOpt){
    this->CAINoptions=newOpt;
=======
}


void UserControlInfo::setCAINOption(std::string newOpt){
    this->CAINoptions=newOpt;
}

std::string UserControlInfo::getCAINOptions(){
    return this->CAINoptions;
}


void UserControlInfo::setEnbCoord(const Coord& coord){
    enbCoord = coord;
}
Coord UserControlInfo::getEnbCoord() const{
    return enbCoord;
}
void UserControlInfo::setCAINCoord(const Coord& coord){
    CAINCoord = coord;
}
Coord UserControlInfo::getCAINCoord() const{
    return CAINCoord;
}

void UserControlInfo::setCAINHopCoord(const Coord& coord){
    CAINHopCoord = coord;
}

Coord UserControlInfo::getCAINHopCoord() const{
    return CAINHopCoord;
}

void UserControlInfo::setMapCoord(const coordList& nodes){
    nodesCoord = nodes;
}

coordList UserControlInfo::getMapCoord(){
    return nodesCoord;
}

CAINControlInfo::~CAINControlInfo()
{
    if (userTxParams != NULL)
    {
        delete userTxParams;
        userTxParams = NULL;
    }
}

CAINControlInfo::CAINControlInfo() :
    CAINControlInfo_Base()
{
    userTxParams = NULL;
    grantedBlocks.clear();
>>>>>>> 5bdd6e6e24f045a4424f1e198edd7074414c0413
}

std::string UserControlInfo::getCAINOptions(){
    return this->CAINoptions;
}

<<<<<<< HEAD

void UserControlInfo::setEnbCoord(const Coord& coord){
    enbCoord = coord;
}
Coord UserControlInfo::getEnbCoord() const{
    return enbCoord;
}
void UserControlInfo::setCAINCoord(const Coord& coord){
    CAINCoord = coord;
}
Coord UserControlInfo::getCAINCoord() const{
    return CAINCoord;
}

void UserControlInfo::setCAINHopCoord(const Coord& coord){
    CAINHopCoord = coord;
}

Coord UserControlInfo::getCAINHopCoord() const{
    return CAINHopCoord;
}

void UserControlInfo::setMapCoord(const coordList& nodes){
    nodesCoord = nodes;
}

coordList UserControlInfo::getMapCoord(){
    return nodesCoord;
=======
    if (other.userTxParams != NULL)
    {
        const UserTxParams* txParams = check_and_cast<const UserTxParams*>(other.userTxParams);
        this->userTxParams = txParams->dup();
    }
    else
    {
        this->userTxParams = NULL;
    }
    this->grantedBlocks = other.grantedBlocks;
    this->senderCoord = other.senderCoord;
    CAINControlInfo_Base::operator=(other);
    return *this;
>>>>>>> 5bdd6e6e24f045a4424f1e198edd7074414c0413
}

void CAINControlInfo::setCoord(const Coord& coord)
{
    senderCoord = coord;
}

void CAINControlInfo::setUserTxParams(const UserTxParams *newParams)
{
    if(userTxParams != NULL){
        delete userTxParams;
    }
    userTxParams = newParams;
}


Coord CAINControlInfo::getCoord() const
{
    return senderCoord;
}
