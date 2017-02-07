by Yichen Wu
UCLA UID:504294181

## Introduction

This project uses two servos to play music! One plucks a steel ruler, and the other adjust the length of ruler being plucked to control tone.

Demo video of DoReMi can be found in the "Demo" folder. (I should let the continuous servo run a bit longer in that video.)

## What you'll need for this project

1. ESP8266-12E board that has built in WIFI. Surely you can adapt the code to other platforms, but this is the one that is used here.
2. A compatible motor shield (Not necessary, but good to have.)
2. Micro-USB male to USB male cable. You'll need this to connect it to your PC.
3. One continuous movement servo and a standard servo
4. An L-shaped box (plastic, wood or metal). I bought mine from Daiso.
5. A steel ruler
6. A plastic ruler.
7. Some toothpicks.
8. A drill (It's a bit of work. I didn't 3D print it because of time limitation, but you may try.)

There are pictures in the "Pictures" folder.

## Setup Arduino IDE Environment with esp8266-12e board

To get familiar with esp8266, you may view esp8266-12e-quick.pdf provided by UCLA Prof. Mehta. That's how I did.

Here are some key links from the pdf.
http://www.instructables.com/id/Programming-the-ESP8266-12E-using-Arduino-software/?ALLSTEPS

drivers for all OSes can be found here:
https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx

Pick Board: "Node MCU 1.0 (ESP-12 Module)"

Upload Speed: 115200

Programmer: AVRISP mkll

## Understand building blocks

Before you go to the final code, you may start with modular programs I included if you are not familiar with them:

Blink_esp8266

BlinkWithWifi_esp8266 
(http://www.instructables.com/id/Programming-a-HTTP-Server-on-ESP-8266-12E/?ALLSTEPS)

ServoTest_esp8266 (also used for tuning)

InterruptTest_esp8266

## Procedures

following the order of pictures:

1. Buy materials and tools.

2. A steel ruler can produce a much louder sound than a plastic one. But be sure to pick a thin one. Otherwise, it's gonna take too much force to pluck it.

3. Fix the continuous servo as the plucker. It produces enough force and rotates at almost constant velocity, which makes it perfect for the task.

4. Make a slot for the steel ruler to slide in. Hot glue half of the plastic ruler as the top side. If the slot is too thick, add a one-side-smooth paper. It requires some vertical force on the steel ruler for it make a good sound.

5. Hot glue the other servo to the box;

6. Make a linkage that linearize the rotational motion servo produces with the other half of plastic ruler.

7. Fix the linkage and now steel ruler moves linearly!

8. Drill a dent on the side of top ruler to allow a greater range of movement.

9. Make a plucker with toothpicks. 

10. Upload code and tune this intrument. You'll need to take down the positions of each note.

## Possible improvements

1. Handcrafting cannot make perfect mechanical parts. Try 3D printing or some good workshops to make it better.

2. One can try auto tuning with an additional mic input. 