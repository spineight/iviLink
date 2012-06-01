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
 * @file             CPmpCoreProtocol.hpp
 * @brief            Header file for CPmpCoreProtocol class
 * @author           VPlachkov
 ***************************************************************************/

#ifndef CPMPCOREPROTOCOL_HPP_
#define CPMPCOREPROTOCOL_HPP_

#include "utils/misc/include/Logger.hpp"
#include "utils/misc/include/UID.hpp"

#include "framework/components/ProfileManager/PMP/interaction/include/IPmpProtocol.hpp"
#include "framework/components/ProfileManager/PMP/interaction/include/IPmpCoreProtocol.hpp"

namespace AXIS
{

   namespace PMP
   {

      /**
       * Class is used for make requests on another size
       */
      class CPmpCoreProtocol : public IPmpCoreProtocol
      {
      public:
         /**
          * Constructor
          * @param pPmpProtocol is pointer to object thar implements PMP Protocol interface
          */
         CPmpCoreProtocol(IPmpProtocol * pPmpProtocol);

         /**
          * Destructor
          */
         virtual ~CPmpCoreProtocol();

         /**
          * Functions below makes requests on another side, serializes data and waits for responce
          */
         virtual CError getAvailableProfileComplements(std::list<Profile::Uid> & complements);
         virtual CError reloadProfilesFromRepository();
         virtual CError resetProfileState();
         virtual CError lock(AXIS::CUid id);
         virtual CError unlock(AXIS::CUid id);
         virtual CError unlockAll();
         virtual CError disableByClient(AXIS::CUid id);
         virtual CError enableByClient(AXIS::CUid id);
         virtual CError enableByClientAll();

      private:
         IPmpProtocol * mpPmpProtocol; ///< Pointer to PMP Protocol Interface

         static Logger msLogger;       ///< object of logger
      };

   }

}

#endif /* CPMPCOREPROTOCOL_HPP_ */
