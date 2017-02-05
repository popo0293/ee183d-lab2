## Introduction

This project uses two servos to play music! One plucks a string, and the other adjust the length of string plucked to control pitch.

## What you'll need for this project

1. ESP8266-12E board that has built in WIFI. Surely you can adapt the code to other platforms, but this is the one that is used here.
2. A compatible motor shield (Not necessary, but good to have.)
2. Micro-USB male to USB male cable. You'll need this to connect it to your PC.
3. One continuous movement servo and a standard servo
4. A hard box without lid (plastic, wood or metal).
5. Rubber bands.
6. A ruler.

## Setup Arduino IDE Environment with esp8266-12e board

To get familiar with esp8266, you may view the esp8266-12e-quick.pdf provided by UCLA Prof. Mehta.

Here are some key links from the pdf.
http://www.instructables.com/id/Programming-the-ESP8266-12E-using-Arduino-software/?ALLSTEPS

drivers for all OSes can be found here:
https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx

Pick Board: "Node MCU 1.0 (ESP-12 Module)"
Upload Speed 115200
Programmer: AVRISP mkll

## Understand building blocks

Before you go to the final code, you may start with modular programs I included if you are not familiar with them:

Blink_esp8266
BlinkWithWifi_esp8266 
(http://www.instructables.com/id/Programming-a-HTTP-Server-on-ESP-8266-12E/?ALLSTEPS)
ServoTest_esp8266
InterruptTest_esp8266
