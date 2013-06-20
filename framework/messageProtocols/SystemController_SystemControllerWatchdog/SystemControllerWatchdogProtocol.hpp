#ifndef SYSTEM_CONTROLLER_WATCHDOG_PROTOCOL_HPP
#define SYSTEM_CONTROLLER_WATCHDOG_PROTOCOL_HPP

enum SystemControllerToWatchdog
{
   SC_WD_LAUNCHED_PHYSICAL_LAYER,
   SC_WD_LAUNCHED_CHANNEL_LAYER,
   SC_WD_LAUNCHED_PROFILE_LAYER,
   SC_WD_LAUNCHED_APPLICATION_LAYER,
   SC_WD_LAUNCHED_AUTHENTICATON,
   SC_WD_STOPPED_AUTHENTICATION,
};

#endif //SYSTEM_CONTROLLER_WATCHDOG_PROTOCOL_HPP