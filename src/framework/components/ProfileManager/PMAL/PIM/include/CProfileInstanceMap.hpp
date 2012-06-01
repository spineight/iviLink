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

#ifndef INSTANCEMAP_HPP_
#define INSTANCEMAP_HPP_

#include <map>
#include <vector>
#include <utility>

#include "utils/misc/include/Logger.hpp"
#include "utils/threads/include/CMutex.hpp"

#include "CProfileInternal.hpp"

namespace AXIS {
namespace PMAL {
namespace PIM {


class CProfileInstanceMap
{
public:
   CProfileInstanceMap();
   ~CProfileInstanceMap();


   /**
    * Registers profile instance
    * @param profileUid
    * @param pInstance
    * @return
    */
   CError registerProfile(AXIS::Profile::IUid const& profileUid, AXIS::Profile::CProfileInternal* pInstance);

   /**
    * Unregisters profile instance
    * @param pInstance
    * @return
    */
   CError unregisterProfile(AXIS::Profile::CProfileInternal* pInstance);

   /**
    *
    * @param profileUid
    * @param[out] pInstance
    * @return
    */
   CError find(AXIS::Profile::IUid const& profileUid, AXIS::Profile::CProfileInternal*& pInstance);

   /**
    *
    * @param pInstance
    * @param[out] profileUid
    * @return
    */
   CError find(AXIS::Profile::CProfileInternal* const pInstance, AXIS::Profile::IUid& profileUid);

   /**
    *
    * @param profileUid
    * @return
    */
   CError isKnown(AXIS::Profile::IUid const& profileUid);

   /**
    *
    * @param pInstance
    * @return
    */
   CError isKnown(AXIS::Profile::CProfileInternal* pInstance);

   typedef std::vector<std::pair<AXIS::Profile::IUid, AXIS::Profile::CProfileInternal*> > tProfilesList;

   /**
    * Returns the vector of all registered profiles
    * @param profiles
    * @return
    */
   CError getAllRegisterd(tProfilesList& profiles);



private:

   typedef std::map<AXIS::Profile::IUid, AXIS::Profile::CProfileInternal*> tProfileMap;
   tProfileMap mProfileMap;

   typedef std::map<AXIS::Profile::CProfileInternal*, AXIS::Profile::IUid> tUidMap;
   tUidMap mUidMap;

   CMutex mMutex;

   static Logger msLogger;

};

}  // namespace PIM
}  // namespace ProfileManager
}  // namespace AXIS




#endif /* INSTANCEMAP_HPP_ */