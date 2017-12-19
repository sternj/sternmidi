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

During this process, I designed a faceplate and housing for all of the electronic components to improve stability and portability. I 3D printed this and mounted the components onto it.

Over the course of the design, I refined the wiring to minimize the number of connections needed to the Arduino and improve the stability of the connections on the solderless breadboard. I ultimately migrated the remaining circuitry to a soldered breadboard.

## Outcome
After finishing the construction of the device and solving some timing issues within the Arduino software, the device was fully functional and sending syntactically-correct MIDI signals over the Arduino Uno's built-in serial port. These had to be interpreted by the Hairless Serial-MIDI bridge due to firmware incompatibilities, but observation of the output of the serial bridge demonstrated complete functionality. The code can be found [here]("https://github.com/sternj/sternmidi/tree/master/Projects/sketch_oct16a"). Images can be found on the [Photos]("/photos.html") page.

## Challenges
The first issue I encountered was not only that I didn't know how to solder well, but that soldering takes a rather long time to do. The sconnections that I was building were small and required a variety of techniques to solder, none of which I actually knew.

Building hardware is also time-consuming to an extent that programming is not. With a program, I generally have a testable model within the 48 hours after finishing the design. For this device, my turnaround time was about a month from design to first testable implementation.

I also did not know precisely how much I had to plan. Even with a model of each circuit type and an in-depth understanding of all of them, my build moved forward at a painfully slow pace until I sat down and drew out every single connection that I had to solder and plug in. Even with those designed, I rewired the entire device several times over the process of my build in order to make it neater and more comprehensible, as well as to minimize the probability of random disconnection of wires and to make the wiring able to concisely fit within the box that I designed.

I also ran into issues with the potentiometers. During the process of the build, I was noticing stability issues with the wires I had soldered onto the potentiometers, with random disconnections and false signals coming from each of them. I initially attributed this to well-documented issues with reading from a number of analog ports in serial on the Arduino Uno, but the issues persisted when using only a single potentiometer. Upon consulting with two more experienced circuit designers, I realized that the potentiometers that I had bought to solder with were designed exclusively for use in solderless breadboards, making stable soldered connections with them virtually impossible. To remedy this, I had to completely replace the potentiometers.
