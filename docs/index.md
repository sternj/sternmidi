# MIDI controllers
### What is MIDI?
MIDI, standing for "Musical instrument digital interface", is a serial protocol designed to facilitate communication between electronic musical instruments. Its initial use was as a hardware-based method for digital communication, but has been adopted for internal signal routing within computers, control in digital audio workstations, and even for workflow improvements in modern digital soundboards.

For more details, go to the page on [MIDI]({{"/midi.html" | absolute_url}})
### Motivations for project
I am a musician, sound engineer, and composer in addition to being a programmer. Having an in-depth understanding of the standards behind the technology that I rely on every day helps me effectively preempt issues and solve them as they arise, implement better integration between normally incongruent products, and make more effective choices about what I use in my studio and in how I train its staff. 
### Plans
The first project will be a static MIDI controller with 8 buttons/switches and 5 linear-taper potentiometers. These will be hooked up to an Arduino Uno, which will send corresponding MIDI signals through its built-in serial port.


The second project will be a controller designed for use with a digitized tonewheel organ (a la Hammond B3). It will enable physical control of the drawbars and allow for presets to be stored and recalled.
### Delivered items
Both controllers were successfully constructed.

For information on the static controller, see its [page]({{"/staticmidi.md | absolute_url"}})

For information on the motorized controller, see its [page]({{"/motormidi.md | absolute_url"}})
