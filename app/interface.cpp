#include "testApp.h"
#include "interface.h"

// Functions for serializing binary data in data forwarding method
#include "meas_acc/resources.h"
#include "meas_gyro/resources.h"
#include "meas_magn/resources.h"
#include "meas_imu/resources.h"
#include "meas_ecg/resources.h"
#include "meas_hr/resources.h"
#include "movesense_time/resources.h"
#include "meas_temp/resources.h"
#include "sbem-code/sbem_definitions.h"

//Commands formated as byte array with [Command, reference, data?...] (data optional)
enum Commands 
{
    HELLO = 0,
    BEGIN_SUB=1,
    END_SUB=2,
    TOGGLE_LED=4,
    FORWARD_SUB=5,
    END_ALL_SUB=9,
    TOGGLE_DATASTREAM=6,
};
//Responses formated as byte array with [Response, reference, data?...] (data optional)
enum Responses 
{
    COMMAND_RESULT = 1,
    DATA = 2,
    ERROR = 3,
};

const char IMUPath[]="/Meas/IMU6/104";
const uint8_t DEFAULT_REFERENCE=99; //appears as 63 in hex
bool ledStatus=false;
bool forwardData=false;
void testApp::handleCommand(uint8_t cmd, uint8_t reference, const uint8_t values[], size_t len){
    switch (cmd)
    {
        case Commands::HELLO:
        {
            // Hello response, for use as a sanity check <3
            uint8_t helloMsg[] = {'H','e','l','l','o','!'};
            sendPacket(helloMsg, sizeof(helloMsg), reference, Responses::COMMAND_RESULT);
        }
        break;
        case Commands::BEGIN_SUB:
        {
            //unsubscribes to prevent duplicate subscriptions
            unsubscribe(DEFAULT_REFERENCE);
            //subscribes to the path given above, in this case the IMU at 104hz
            subscribe(IMUPath, sizeof(IMUPath), DEFAULT_REFERENCE);
        }
        break;
        case Commands::END_SUB:
        {
            //unsubscribes only from default service
            unsubscribe(DEFAULT_REFERENCE);
        }
        break;
        case Commands::TOGGLE_LED:
        {
            ledStatus=!ledStatus;
            ledSet(ledStatus);
            if(ledStatus){
                uint8_t msg[] = "toggled LED to on";
                sendPacket(msg, sizeof(msg), reference, Responses::COMMAND_RESULT);
            } else {
                uint8_t msg[] = "toggled LED to off";
                sendPacket(msg, sizeof(msg), reference, Responses::COMMAND_RESULT);
            }
        }
        break;
        case Commands::FORWARD_SUB:
        {
            subscribe((const char*) values, len, reference);
        }
        break;
        case Commands::TOGGLE_DATASTREAM:
        {
            forwardData=!forwardData;
            if(forwardData){
                uint8_t msg[] = "Will now forward";
                sendPacket(msg, sizeof(msg), reference, Responses::COMMAND_RESULT);
            }
        }
        break;
        case Commands::END_ALL_SUB:
        {
            unsubscribeAllStreams();
            uint8_t msg[] = "All subscriptions ended";
            sendPacket(msg, sizeof(msg), reference, Responses::COMMAND_RESULT);
        }
        break;
        default:
        {
            uint8_t errorMsg[] = "Command byte matches no cases";
            sendPacket(errorMsg, sizeof(errorMsg), reference, Responses::COMMAND_RESULT);
        }
    }
}

int airState=0;
uint32_t start=0;

void testApp::processData(wb::ResourceId resourceId, const wb::Value &value){
    //this function just forwards the recieved value over the connection 
    if(forwardData){
        DataSub* ds=findDataSub(resourceId);
        //this should suffice for all reasonable uses... GATT isn't equipped
        //to handle the thousand hertz streams anyways lol
        //besides, only 64 bits can be sent back per packet with current implementation
        uint8_t buffer[512];
        //uses this function to allow for multiple types of subscription
        //the length may be longer than our 64 character limit,
        //but the sendPacket function restricts message length so it doesn't matter.
        size_t length = getSbemLength(resourceId.localResourceId, value);
        writeToSbemBuffer(&buffer, length<512? length:512, 0, resourceId.localResourceId, value);
        //sendPacket((const uint8_t*) &length, 4, ds->clientReference);
        sendPacket((const uint8_t*) &buffer, length, ds->clientReference, Responses::DATA);
        return;
    }

    //this code detects if the device is in freefall and sends
    //the time it was falling for over the connection when it lands.
    const WB_RES::IMU6Data &data = value.convertTo<WB_RES::IMU6Data&>();
    const wb::Array<wb::FloatVector3D> &accData = data.arrayAcc;
    for (size_t i = 0; i < accData.size(); i++){
        wb::FloatVector3D accValue = accData[i];
        //we calculate the squared magnitude of the forces on the unit.
        //a unit in freefall would ideally have 0 acceleration on it
        float accelerationSq = accValue.mX * accValue.mX +
                                accValue.mY * accValue.mY +
                                accValue.mZ * accValue.mZ;
        //9 (about .3G or 3m/s squared) is uses as the thresold value for being in freefall
        if(accelerationSq<9.0f){
            //at 104hz, the sensor polls every tenth of a second but only periodically
            //forwards a subscription notification with a timestamp pertaining to the
            //first measurement. A datum later in the packet should have its time adjusted.
            start = airState? start : data.timestamp+10*i;
            airState++;
        } else {
            //using 20 sensor polls (.2 seconds at 104 hz) as a arbitrary cutoff point
            if(airState>10){
                uint32_t end = data.timestamp+10*i;
                uint32_t dif = end-start;
                //we make a pointer to the value we want to send.
                //we only want to send a single uint32_t, so we know where the
                //relevant bytes are and how many we need to send.
                uint8_t* difPtr = (uint8_t*) &dif;
                sendPacket(difPtr, 4, DEFAULT_REFERENCE, Responses::DATA);
            }
            airState=0;
        }
    }
}