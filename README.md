# Environment setup




## Console Web Client (using Google Chrome)

The Movesense console will display all functionality of your Movesense environment on a simple web page.

1. Download the Movesense Device Library here
2. Download/Clone the starter code from the course repository (IMPORTANT: when cloning, ensure you are in the movesense-device-lib directory from the previous step)
3. Navigate to the web client HTML file (movesense-device-lib/myApp/web_client/Movesense Webclient.html)
4. Connect a Movesense device and input '0' into the command input to ensure the 'Hello' command works as provided in the starter code




## Showcase App

A key tool for your development environment throughout this course is the Movesense showcase app. This will provide an interface to view your sensor data in real time, and to update your device's firmware.

The Movesense Showcase App can be downloaded on your smartphone: iOS or Android




## Movesense Code

The provided repository features the starter code environment that will be used for each technical assignment throughout this course. This features the web client that will be used to execute the applications you develop, as well code that runs to interface directly with your device.




## Build Command Process

Each time you modify code running on the Movesense device (i.e. interface.cpp, myApp.cpp) you will need to rebuild the app and update the device's firmware. This process can be completed through the following steps:




- First pull the Movesense build environment container:
`docker pull movesense/sensor-build-env:latest`
- After that go to the cloned repository folder
`cd movesense-device-lib`
- start the docker image on terminal (replace with the path to your movesense-device-lib):

*Linux or Mac:*

``docker run -it --rm -v `pwd`:/movesense:delegated movesense/sensor-build-env:latest``

*Windows*:

`docker run -it --rm -v c:/MyProject/Folder/movesense-device-lib:/movesense:delegated movesense/sensor-build-env:latest`

- after docker prompt starts:
`cd /movesense`
`mkdir myBuild`
`cd myBuild`
- Now, run the CMake (needs to be done only once unless you add files to the project). It's possible to build both the debug and release version. In both cases the command will contain the following:

`cmake -G Ninja -DMOVESENSE_CORE_LIBRARY=../MovesenseCoreLib/ -DCMAKE_TOOLCHAIN_FILE=../MovesenseCoreLib/toolchain/gcc-nrf52.cmake ../myApp`




--Notes--

Similarly, if you would like to build another application, just replace the <sample_directory> with your relative path to the CMakeLists.txt  file of the application desired to be built. For example: ../samples/hello_world_app:

`cmake -G Ninja -DMOVESENSE_CORE_LIBRARY=../MovesenseCoreLib/ -DCMAKE_TOOLCHAIN_FILE=../MovesenseCoreLib/toolchain/gcc-nrf52.cmake <sample_directory>`

---

To build a release version it's necessary to specify the CMAKE_BUILD_TYPE option with the Release value:

`cmake -G Ninja -DMOVESENSE_CORE_LIBRARY=../MovesenseCoreLib/ -DCMAKE_TOOLCHAIN_FILE=../MovesenseCoreLib/toolchain/gcc-nrf52.cmake -DCMAKE_BUILD_TYPE=Release <sample_directory>`




- After that only the last step remains:

`ninja pkgs`

The created Movesense_combined.hex and the DFU packages can be found in the same directory.

The produced DFU package must now be uploaded to the Movesense device through the showcase app. This can be completed with the following steps:

- Install the Movesense Showcase App on your smart phone (both IOS and Android versions available). 
- Send the DFU zip file, which should be named as Movesense_dfu.zip or something similar, to your smart phone. Place the file under the "Movesense" folder.
- Open the Movesense Showcase app and connect your sensor. Select the sensor you want to pair from the sensors list. (Ensure that you have turned on Bluetooth on your phone, and refer to the video guide Links to an external site if you need help)
- Go to "Device Firmware Upgrade" and "Select firmware".
- The DFU zip file that we just created should now be visible in the "Uploaded files". Choose your file and then tap "Select Firmware".
- Confirm the sensor location by choosing "Available DFU Target" on the list. Your sensor will go to DFU mode and red light is on. Tap "Update Selected Target" to start the update.
- Updating can take several minutes. When the update is ready, the red light will turn off and the sensor will be reconnected to the application. If it's not reconnected, go to the "Sensors" tab and connect your sensor manually.
- To verify the update has succeeded, check the "Sensor info", and you should see the App name "My App". Now you can disconnect the sensor.




## LED Blink

Your main task for this homework is to modify the Movesense's interface code to provide a command for blinking the Movesense device's LED light 3 times with 2 second pauses in between in each blink.




## Submit
- Record a video showing:
  - The blink code open in the programming environment on your laptop. Please explain the code that you added 
  - The LED blinking on the Movesense device in the following pattern: 3 blinks, pause 2 seconds, 3 blinks, pause 2 seconds, etc. 
- Upload the video to YouTube. We suggest logging to YouTube using your Andrew account 
- Set the visibility of the video so that the TAs and instructor can access the video. We suggest setting the visibility to unlisted or privately accessible to anyone with an Andrew ID 
- Submit the YouTube URL 





