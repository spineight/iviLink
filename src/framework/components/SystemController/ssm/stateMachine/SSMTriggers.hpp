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
 * SSMTriggers.hpp
 *
 *  Created on: Mar 30, 2012
 *      Author: Kramchaninov Pavel
 */

#ifndef SSM_TRIGGERS_HPP_
#define SSM_TRIGGERS_HPP_

namespace SystemController
{

enum eSSMTriggers
{
   // TODO: Most likely some triggers will have higher priority then others.

   EMPTY_TRIGGER_QUEUE = 0,
   INITIALIZED,
   CONNECTIVITY_AGENT_STARTED,
   PHISYCAL_CONNECTION_ESTABLISHED,
   PHISYCAL_CONNECTION_LOST,
   CHANNEL_SUPERVISOR_STARTED,
   CHANNEL_CONNECTION_ESTABLISHED,
   CHANNEL_CONNECTION_LOST,
   AUTHENTICATION_ESTABLISHED,
   PROFILE_MANAGER_STARTED
};

}

#endif /* SSM_TRIGGERS_HPP_ */