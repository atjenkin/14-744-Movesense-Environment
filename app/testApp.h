#pragma once

#include <whiteboard/LaunchableModule.h>
#include <whiteboard/ResourceClient.h>

class testApp FINAL : private wb::ResourceClient, public wb::LaunchableModule
{
public:
    /** Name of this class. Used in StartupProvider list. */
    static const char* const LAUNCHABLE_NAME;
    testApp();
    ~testApp();

private:
    /** @see whiteboard::ILaunchableModule::initModule */
    virtual bool initModule() OVERRIDE;
    /** @see whiteboard::ILaunchableModule::deinitModule */
    virtual void deinitModule() OVERRIDE;
    /** @see whiteboard::ILaunchableModule::startModule */
    virtual bool startModule() OVERRIDE;
    /** @see whiteboard::ILaunchableModule::stopModule */
    virtual void stopModule() OVERRIDE;

    /** @see whiteboard::ResourceClient::onPostResult */
    virtual void onPostResult(wb::RequestId requestId,
                              wb::ResourceId resourceId,
                              wb::Result resultCode,
                              const wb::Value& rResultData) OVERRIDE;

    /** @see whiteboard::ResourceClient::onGetResult */
    virtual void onGetResult(wb::RequestId requestId,
                             wb::ResourceId resourceId,
                             wb::Result resultCode,
                             const wb::Value& rResultData);

    /** @see whiteboard::ResourceClient::onGetResult */
    virtual void onSubscribeResult(wb::RequestId requestId,
                                   wb::ResourceId resourceId,
                                   wb::Result resultCode,
                                   const wb::Value& rResultData);

    /** @see whiteboard::ResourceClient::onNotify */
    virtual void onNotify(wb::ResourceId resourceId,
                          const wb::Value& rValue,
                          const wb::ParameterList& rParameters);

private:
    void configGattSvc();
    void unsubscribeAllStreams();

    wb::ResourceId mCommandCharResource;
    wb::ResourceId mDataCharResource;
    wb::TimerId mMeasurementTimer;

    int32_t mSensorSvcHandle;
    int32_t mCommandCharHandle;
    int32_t mDataCharHandle;

    bool mNotificationsEnabled;

    // Data subscriptions

    struct DataSub {
        wb::ResourceId resourceId;
        uint8_t clientReference;
        bool subStarted;
        bool subCompleted;
    };
    static constexpr size_t MAX_DATASUB_COUNT = 4;
    DataSub mDataSubs[MAX_DATASUB_COUNT];

    DataSub *getFreeDataSubSlot();

    // Buffer for outgoing data messages (MTU -3)
    uint8_t mDataMsgBuffer[158];

    DataSub* findDataSub(const wb::ResourceId resourceId);
    DataSub* findDataSubByRef(const uint8_t clientReference);
  
    void handleIncomingCommand(const wb::Array<uint8> &commandData);
    //returns basic status; reference CANNOT be 0
    //currently confirms null termination and non-zero reference
    bool subscribe(const char path[], size_t pathlen, uint8_t reference);
    void unsubscribe(uint8_t reference);
    //send information over GATT connection, arbitrary maximum of 64 bits
    void sendPacket(const uint8_t data[], size_t len, uint8_t reference=0, uint8_t type=2);

    //controls for hardware LED, true is on, false is off
    void ledSet(bool on);

    //called with any incomming data from subscribed sensors
    void processData(wb::ResourceId resourceId, const wb::Value &value);
    //called with raw serial input from GATT connection
    void handleCommand(uint8_t cmd, uint8_t reference, const uint8_t values[], size_t len);
};
