# Motorized MIDI controller
## Goals
- To build a MIDI controller that can store and recall presets
- To have the physical location of the linear potentiometers on this MIDI controller correspond directly with their relative position in the software
- To be able to precisely control motorized potentiometers

## Specifications
The controller is built over an Arduino Due. It contains 9 motorized linear potentiometers (faders), each of which consists of a potentiometer hooked up to a DC motor. Each motor is connected to an an H-bridge, an integrated circuit which allows for them to be precisely controlled. Each motor requires 3 digital outputs from the Arduino Due--two to signal the motor to go in either direction and an additional one to enable the H-bridge. Additionally, there are three buttons, two to recall presets and one to store a given preset.


## Design process
I started with a single potentiometer attached to an H-bridge on an Arduino Uno. I did this in order to familiarize myself with the wiring of the H-bridge and how to program with DC motors. This initial prototype also had two buttons; one of them was to store a preset and the other was to recall a preset. This prototype functioned properly, so I moved forward to the final version, with 9 motorized potentiometers. There were numerous hurdles to overcome in this process, which I go into in-depth in the "challenges" subsection.

## Outcome
Despite the functionality of the initial prototype, the 9-fader version is non-functional due to hardware migration issues to the Arduino Due. There appear to be issues with the H-bridges properly receiving the logical signals sent by the Arduino, which could be caused by a lack of power going to the Arduino or incongruent levels between the Arduino and the logic-level power rail. This section will be updated as the issue is diagnosed and remedied. 
## Challenges
The main issue that I ran in to was power. Firstly, the H-bridges require two separate voltages, one of them servo-level at 9v and one of them logic-level at 5v. For the 9v, I needed an outboard variable-voltage power supply. I thought the logical power would be easy to resolve, as I could draw 5v from the Arduino, but 9 potentiometers at 10,000 ohms each draw sufficiently large amounts of power that the Arduino crashed whenever the power rail was connected to it. This was not remedied by adding an external USB power supply. To fix this, I had to use a step-down transformer.

I also did not realize when I started my build that I needed H-bridges in order to control the motors. This is something that I should have been aware of, as the motors were rated at 9-36v with a 1 amp power draw and an Arduino alone cannot supply this.
