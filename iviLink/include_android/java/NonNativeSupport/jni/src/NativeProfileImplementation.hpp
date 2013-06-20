#ifndef __CPROFILE_IMPLEMENTATION_HPP
#define __CPROFILE_IMPLEMENTATION_HPP

#include <string>
#include <jni.h>

#include "NonnativeCallbacksWrapper.hpp"
#include "Logger.hpp"
#include "ProfileLibCommon.hpp"

using iviLink::Buffer;
using iviLink::Channel::tChannelId;

class NativeProfileImplementation: public iviLink::Channel::ChannelHandler,
        public iviLink::BaseProfileApi
{
public:
    virtual std::string getName() const;
    virtual UInt32 getVersion() const;
    virtual iviLink::Profile::Uid getUid() const;
    virtual iviLink::Profile::ApiUid getProfileApiUid() const;

    NativeProfileImplementation(JavaVM* jm, jobject profileExternal,
            iviLink::Profile::IProfileCallbackProxy* pCbProxy);
    virtual ~NativeProfileImplementation();

    iviLink::Error sendData(const char* data, const UInt32 sizeOfData, const UInt32 channelID);

    jobject getProfileCallbacks();

    jobject getExternalProfile();

    iviLink::Error allocateChannel(const std::string& tag, UInt32& channelID, const int priority);

    iviLink::Error allocateChannelAsServer(const std::string& tag, UInt32& channelID,
            const int priority);

    iviLink::Error allocateChannelAsClient(const std::string& tag, UInt32& channelID,
            const int priority);

    iviLink::Error deallocateChannel(const UInt32 channelID);

    // CChannelHandler
    virtual void onBufferOverflow(const iviLink::Channel::tChannelId channelId);
    virtual void onBufferReceived(const tChannelId channel, Buffer const& buffer);

    virtual void onChannelDeleted(const UInt32 channel_id);

    virtual void onConnectionLost();

    virtual void onEnable();

    virtual void onDisable();
private:
    iviLink::Error checkPrioritySerialization(const int priority) const;

private:
    //Pointer to instance of class describing callbacks
    NonnativeCallbacksWrapper* mpAppCallbacks;
    Logger mLogger;

    JavaVM * mpJM;
    jobject mProfileExternal;

    jmethodID midReceiveData;
    jmethodID midOnEnable;
    jmethodID midOnDisable;
    jmethodID midOnConnectionLost;
    jmethodID midChannelDeleted;

    jmethodID midGetName;
    jmethodID midGetVersion;
    jmethodID midGetUID;
    jmethodID midGetProfileAPIUID;

    jmethodID midBufferOverflow;
};

#endif //ANDROID
