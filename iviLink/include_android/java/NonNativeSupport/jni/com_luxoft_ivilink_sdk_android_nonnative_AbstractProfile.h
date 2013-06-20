/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile */

#ifndef _Included_com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile
#define _Included_com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile
#ifdef __cplusplus
extern "C"
{
#endif
/*
 * Class:     com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile
 * Method:    createNativeProfile
 * Signature: (Ljava/lang/String;Ljava/lang/String;[B)V
 */
JNIEXPORT void JNICALL Java_com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile_createNativeProfile
(JNIEnv *, jobject, jstring, jstring, jlong);

/*
 * Class:     com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile
 * Method:    getProfileCallbacks
 * Signature: ()Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile_getProfileApiCallbacks(
        JNIEnv *, jobject, jlong);

/*
 * Class:     com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile
 * Method:    allocateChannel
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jstring JNICALL Java_com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile_allocateChannelNative(
        JNIEnv *, jobject, jlong, jstring, jint);

/*
 * Class:     com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile
 * Method:    allocateChannelAsServer
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jstring JNICALL Java_com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile_allocateChannelAsServerNative(
        JNIEnv *, jobject, jlong, jstring, jint);

/*
 * Class:     com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile
 * Method:    allocateChannelAsClient
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jstring JNICALL Java_com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile_allocateChannelAsClientNative(
        JNIEnv *, jobject, jlong, jstring, jint);

/*
 * Class:     com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile
 * Method:    deallocateChannel
 * Signature: (I)V
 */
JNIEXPORT jstring JNICALL Java_com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile_deallocateChannelNative(
        JNIEnv *, jobject, jlong, jint);

/*
 * Class:     com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile
 * Method:    sendData
 * Signature: ([BI)V
 */
JNIEXPORT jstring JNICALL Java_com_luxoft_ivilink_sdk_android_nonnative_AbstractProfile_sendDataNative(
        JNIEnv *, jobject, jlong, jbyteArray, jint);

#ifdef __cplusplus
}
#endif
#endif
