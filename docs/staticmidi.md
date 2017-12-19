# The static MIDI controller

## Goals
- To build a device which can be used to control digital instruments and related software
- To learn how USB-MIDI devices are programmed and interact with computers
- To learn the circuit design and soldering skills necessary for building the responsive MIDI controller

## Specifications
This controller is built around an Arduino Uno. It contains eight toggle switches and three buttons, each of which, upon state change, sends a MIDI control change signal to a pre-specified channel. Because of the limitations of the Arduino platform and my knowledge of MIDI, the signal types and controller numbers are hard-coded in. There are also 5 linear-taper potentiometers, which also send MIDI control change signals within a range of 0-127. Each of the toggle switches also has an LED light indicating its status.

## Design process
This controller consists of only three types of circuits. The first is a binary switch circuit, which connects a signal input to a logical HIGH voltage when activated and grounds it otherwise. The second is a circuit connecting a potentiometer to a logical HIGH voltage, an analog input, and ground. The third is simply a chain of LED lights wired in parallel. I first built and tested each of these circuits individually, and then I constructed a composite board consisting of all 3 types together.

I then immediately attempted soldering all 9 binary switch circuits into a perfboard simultaneously. This proved to be ill-advised as I did not know how to solder or how to design a circuit so that it can easily be migrated to a perfboard. As this did not work whatsoever, I scrapped my work, trying again with a solderless breadboard. This functioned as expected.

During this process, I designed a faceplate and housing for all of the electronic components to improve stability and portability. I 3D printed this 
