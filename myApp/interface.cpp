#include "myApp.h"
#include "interface.h"

// sensor libraries for data interperting
#include "meas_acc/resources.h"
#include "meas_gyro/resources.h"
#include "meas_magn/resources.h"
#include "meas_imu/resources.h"

//Commands formated as byte array with [Command, data?...] (data optional)
enum Commands 
{
    HELLO = 0,
    BEGIN_SUB=1,
    END_SUB=2,
};
//Responses formated as byte array with [Response, tag, data?...] (data optional)
enum Responses 
{
    COMMAND_RESULT = 1,
    DATA = 2,
    ERROR = 3,
};
          
const char IMUPath[]="/Meas/IMU6/104";
const uint8_t DEFAULT_REFERENCE=99; //appears as 63 in hex

void myApp::handleCommand(uint8_t cmd, const uint8_t values[], size_t len){
    switch (cmd)
    {
        case Commands::HELLO:
        {
            // Hello response, for use as a sanity check <3
            uint8_t helloMsg[] = {'H','e','l','l','o','!'};
            //tags aren't explicitly necessary, but they're a good way of grouping responses.
            //The included console uses them to filter and format responses.
            uint8_t tag=1;
            sendPacket(helloMsg, sizeof(helloMsg), tag, Responses::COMMAND_RESULT);
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
    }
}

void myApp::processData(wb::ResourceId resourceId, const wb::Value &value){
    
}
