/* 
 *  iviLINK SDK, version 0.9 (for preview only)                                      
 *    http://www.ivilink.net                                                         
 *  Cross Platform Application Communication Stack for In-Vehicle Applications       
 *                                                                                   
 *  Copyright (C) 2012, Luxoft Professional Corp., member of IBS group               
 *                                                                                   
 *  This library is free software; you can redistribute it and/or                    
 *  modify it under the terms of the GNU Lesser General Public                       
 *  License as published by the Free Software Foundation; version 2.1.               
 *                                                                                   
 *  This library is distributed in the hope that it will be useful,                  
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of                   
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU                
 *  Lesser General Public License for more details.                                  
 *                                                                                   
 *  You should have received a copy of the GNU Lesser General Public                 
 *  License along with this library; if not, write to the Free Software              
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA   
 * 
 * 
 * 
 * 
 */

/*
 * MessageProtocolBase.h
 *
 *  Created on: Mar 19, 2012
 *      Author: Kramchaninov Pavel
 */

#ifndef SYSTEM_CONTROLLER_MSG_PROXY_AM_HPP
#define SYSTEM_CONTROLLER_MSG_PROXY_AM_HPP

#include <string>
#include "utils/misc/include/CError.hpp"
#include "utils/ipc/include/ICallbackHandler.hpp"
#include "utils/ipc/include/common.hpp"
#include "utils/ipc/include/CIpc.hpp"

using namespace std;
using namespace AXIS::Ipc;

namespace AppManMsgProtocol
{

class SystemControllerMsgProxy : public AXIS::Ipc::ICallbackHandler
{
private:

	const char* getName() {return "SystemControllerMsgProxy";}

	AXIS::Ipc::CIpc* mpIpc;

public:
	explicit SystemControllerMsgProxy(const string connectionName);
	virtual ~SystemControllerMsgProxy();

protected:

   // Outgoing messages
   //
   
   // Incoming messages
   // should be implemented by implementation

   virtual CError onShutDown() = 0;

protected:
   // from ICallbackHandler

   CError connect();
   virtual void OnConnection(AXIS::Ipc::DirectionID);
   virtual void OnConnectionLost(AXIS::Ipc::DirectionID);
   virtual void OnRequest(AXIS::Ipc::MsgID id, UInt8 const* pPayload, UInt32 payloadSize, UInt8* const pResponseBuffer, UInt32& bufferSize, AXIS::Ipc::DirectionID);

protected:

   class CMsgIdGen
   {
   public:
      CMsgIdGen();
      ~CMsgIdGen();
      AXIS::Ipc::MsgID getNext();
   private:
      AXIS::Ipc::MsgID mId;
   };

   CMsgIdGen mMsgIdGen;


   bool isConnected() const;

   enum
   {
      BUFFER_SIZE = 4096
   };

   UInt8 mReadBuffer[BUFFER_SIZE];
   UInt8 mWriteBuffer[BUFFER_SIZE];
};

}

#endif /* SYSTEM_CONTROLLER_MSG_PROXY_AM_HPP */