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

/***************************************************************************
 * Project           AXIS
 * (c) copyright     2012
 * Company           LUXOFT
 * @file             CAppManProtoServer.hpp
 * @brief            Header file for server of AppMan-Protocol (AppMan-App interaction)
 * @author           VPlachkov
 ***************************************************************************/

#ifndef CAPPMANPROTOSERVER_HPP_
#define CAPPMANPROTOSERVER_HPP_

#include <map>

#include "utils/misc/include/Logger.hpp"
#include "utils/ipc/include/CIpc.hpp"
#include "utils/ipc/include/ICallbackHandler.hpp"
#include "framework/libraries/AppMan/AmpForApp/include/IAppManProto.hpp"
#include "framework/libraries/AppMan/AmpForApp/include/IAppManProtoAmpToApp.hpp"
#include "framework/libraries/AppMan/AmpForApp/include/IConnection.hpp"
#include "framework/libraries/AppMan/AmpForApp/include/IConnectionHandler.hpp"

class CMutex;

namespace AXIS
{

   namespace AppMan
   {

      namespace Ipc
      {

         /**
          * Class implements server side of communication protocol betwenn AMP and applications.
          * This server side is used in AMP
          */
         class CAppManProtoServer   : public IAppManProtoAmpToApp
                                    , public AXIS::Ipc::ICallbackHandler
                                    , public IConnection
         {
         public:
            /**
             * Constructor
             */
            CAppManProtoServer();

            /**
             * Virtual destructor
             */
            virtual ~CAppManProtoServer();

            /**
             * Inits server side protocol. It's a handler for app requests to AMP
             * @param pServer is pointer to object of IPC protocol
             */
            void init (IAppManProto * pServer);

            /**
             * Inits connectin handler
             */
            void initConnectionHandler(IConnectionHandler * pHandler);

            /**
             * Function begin IPC communication with applications (starts waiting for
             * requests from applications
             */
            bool startWaitingForClients();

         private:
            /**
             * Callback is called in case of new connection
             * @param dirId is ID of application in IPC library
             */
            virtual void OnConnection(AXIS::Ipc::DirectionID dirId);

            /**
             * Callback is called in case of losing connection
             * @param dirId is ID of application in IPC library
             */
            virtual void OnConnectionLost(AXIS::Ipc::DirectionID dirId);

            /**
             * Callback is called in case of incoming requests
             */
            virtual void OnRequest(AXIS::Ipc::MsgID id, UInt8 const* pPayload,
                  UInt32 payloadSize, UInt8* const pResponseBuffer,
                  UInt32& bufferSize, AXIS::Ipc::DirectionID dirId);

            /**
             * Makes request to application to start session
             * @param pid of application
             * @param session is UID of session
             * @param service is UID of service
             */
            virtual CError sessionRequest(pid_t pid, AXIS::Service::SessionUid session,
                  AXIS::Service::Uid service);

            /**
             * Makes request to app to get launch information
             * @param pid of application
             * @param launchInfo is string with launch information
             */
            virtual CError getAppLaunchInfo(pid_t pid, std::string & launchInfo);

            /**
             * Function is used to check connection with application
             * @param pid of application
             * @return true if connection is OK
             */
            virtual bool checkConnection(pid_t pid);

            /**
             * Function is used to generate IDs for IPC messages to applications
             */
            AXIS::Ipc::MsgID genId();

            IAppManProto * mpServer; ///< Pointer to server side handler of request from applications
            IConnectionHandler * mpConnectionHandler; ///< Pointer to connection status handler
            AXIS::Ipc::CIpc * mpIpc; ///< Pointer to object of IPC connection
            AXIS::Ipc::MsgID mId; ///< ID of last IPC message
            std::map<pid_t, AXIS::Ipc::DirectionID> mClients; ///< map of DirIDs of applications connected to AMP
            CMutex * mpClientsMutex; ///< Mutex for mClients

            static Logger msLogger; ///< Object of logger
         };

      }

   }

}

#endif /* CAPPMANPROTOSERVER_HPP_ */
