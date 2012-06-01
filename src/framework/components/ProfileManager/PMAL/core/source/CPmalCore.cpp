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
 * @file             CPmalCore.cpp
 * @brief            Header file for PMAL Core class
 * @author           VPlachkov
 ***************************************************************************/

#include <cassert>
#include <cstdlib>

#include "framework/components/ProfileManager/PMAL/core/include/CPmalCore.hpp"
#include "utils/xml/include/pugixml.hpp"


namespace AXIS
{

   namespace PMAL
   {

      Logger CPmalCore::logger = Logger::getInstance(LOG4CPLUS_TEXT("profileManager.Pmal.Core"));

      CPmalCore::CPmalCore(IPMALIpcToCore * pIpc)
         : mpIpc(pIpc)
      {
         assert(pIpc);
      }

      CPmalCore::~CPmalCore()
      {
      }

      CPMALError CPmalCore::getProfileLibPath(Profile::Uid id, std::string& path)
      {
         CPMALError err = mpIpc->getProfileLibPath(id,path);
         if (!err.isNoError())
         {
            LOG4CPLUS_ERROR(logger, static_cast<std::string>(err));
            path = "";
         }
         return err;
      }

      CPMALError CPmalCore::isEnabledProfile(Profile::Uid id, bool& enabled)
      {
         std::map<std::string, std::string> params;
         std::list<AXIS::Profile::Uid> profiles;

         CPMALError err = findProfiles(id, params, profiles, true);
         if (err.isNoError())
         {
            LOG4CPLUS_INFO(logger,
                  "todo: here we cannot distinguish whether profile "
                  "is really disabled or just unknown. "
                  "So the method does not what its name suggests");
            /// @todo: here we cannot distinguish whether profile is really 
            /// disabled or just unknown
            /// So the method does not what its name suggests.

            enabled = !profiles.empty();
         }

         return err;
      }

      CPMALError CPmalCore::findProfiles(AXIS::CUid id,
            const std::map<std::string, std::string> & profileParameters
            , std::list<AXIS::Profile::Uid> & profiles, bool enabledProfiles/* = true*/)
      {
         profiles.clear();
         return mpIpc->findProfiles(id, profileParameters, profiles, enabledProfiles);;
      }

      CPMALError CPmalCore::disableByUid(AXIS::CUid id)
      {
         return mpIpc->disableByUid(id);
      }

      CPMALError CPmalCore::enableByUid(AXIS::CUid id)
      {
         return mpIpc->enableByUid(id);
      }

      CPMALError CPmalCore::enableAll()
      {
         return mpIpc->enableAll();
      }

      CPMALError CPmalCore::getProfileInfo(AXIS::Profile::Uid id, ProfileInfo & profInfo)
      {
         std::string profileManifest;
         CPMALError err = mpIpc->getManifest(id, profileManifest);
         profInfo.params.clear();
         if (err.getCode())
         {
            profInfo.apiUid = CUid("");
            profInfo.complement = CUid("");
            profInfo.name = "";
            profInfo.uid = CUid("");
            profInfo.version = 0;
            return err;
         }

         pugi::xml_document doc;
         pugi::xml_parse_result res = doc.load(profileManifest.c_str());
         if(pugi::status_ok != res.status)
         {
            LOG4CPLUS_ERROR(logger, "CPmpCoreProfileInfo::parseXml() :: Error while parsing Profile manifest");
            return CPMALError(CPMALError::ERROR_MANIFEST_PARSING);
         }

         pugi::xml_node prof = doc.child("profile");
         profInfo.uid = AXIS::Profile::Uid(prof.child_value("uid"));
         profInfo.apiUid = AXIS::Profile::ApiUid(prof.child("api").attribute("uid").value());
         profInfo.name = prof.child_value("name");
         profInfo.version =  atoi(prof.child_value("version"));
         profInfo.complement = AXIS::Profile::Uid(prof.child_value("complement"));

         pugi::xml_node attrs = prof.child("attributes");

         for (pugi::xml_node_iterator it = attrs.begin(); it != attrs.end(); ++it)
         {
            if (it->name() == std::string("attribute"))
            {
               std::string atr = it->attribute("name").value();
               if (atr != "")
               {
                  profInfo.params[atr] = it->attribute("value").value();
               }
            }
         }

         return err;
      }

   }

}