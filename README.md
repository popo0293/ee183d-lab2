## Introduction



## What you'll need for this project

1. ESP8266-12E board that has built in WIFI. Surely you can adapt the code to other platforms, but this is the one that is used here.
2. Micro-USB male to USB male cable. You'll need this to connect it to your PC.
3. Servo 

## Setup Arduino IDE Environment

http://www.instructables.com/id/Programming-the-ESP8266-12E-using-Arduino-software/?ALLSTEPS

drivers for all OSes can be found here:
https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx

Pick Board: "Node MCU 1.0 (ESP-12 Module)"
Upload Speed 115200
Programmer: AVRISP mkll

To get yourself familiar with the modules, you may start with uploading modular test programs I included:

Blink_esp8266
BlinkWithWifi_esp8266 
(http://www.instructables.com/id/Programming-a-HTTP-Server-on-ESP-8266-12E/?ALLSTEPS)
ServoTest_esp8266
InterruptTest_esp8266