/*
 *
 * iviLINK SDK, version 1.1.2
 * http://www.ivilink.net
 * Cross Platform Application Communication Stack for In-Vehicle Applications
 *
 * Copyright (C) 2012-2013, Luxoft Professional Corp., member of IBS group
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; version 2.1.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 *
 */


/**
 * @file                PmpInteractionProtocol.hpp
 * @ingroup             Profile Manager
 * @author              Plachkov Vyacheslav <vplachkov@luxoft.com>
 * @date                10.01.2013
 *
 * Class used to manage PMP protocol entities
 */


#ifndef PMPINTERACTIONPROTOCOL_HPP_
#define PMPINTERACTIONPROTOCOL_HPP_

#include "Logger.hpp"

namespace iviLink
{
namespace PMP
{

class PmpProtocol;
class PmpCoreProtocol;
class PmpPimProtocol;
class PmpSessionProtocol;
class EventFactory;

class PmpInteractionProtocol
{
public:
    PmpInteractionProtocol();
    ~PmpInteractionProtocol();
    void init(EventFactory * eventFactory);

    bool connect();
    void disconnect();
    bool ready();
    bool isReady() const;

    PmpCoreProtocol * coreProtocol();
    PmpPimProtocol * pimProtocol();
    PmpSessionProtocol * sessionProtocol();

private:
    PmpProtocol * mPmpProtocol;
    PmpCoreProtocol * mCoreProtocol;
    PmpPimProtocol * mPimProtocol;
    PmpSessionProtocol * mSessionProtocol;
    EventFactory * mEventFactory;

    static Logger msLogger;          ///< object of logger
};

} /* namespace PMP */
} /* namespace iviLink */
#endif /* PMPINTERACTIONPROTOCOL_HPP_ */
