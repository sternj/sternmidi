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

For information on the static controller, see its [page]({{"/staticmidi.html" | absolute_url}})

For information on the motorized controller, see its [page]({{"/motormidi.html" | absolute_url}})

#### Challenges
I initially thought that most of my issues with this project would be in implementing the software for serial communication from the Arduino. This turned out to be the simplest part of the entire process. The hardware proved to be incredibly time-consuming. I did not account for how long it would take to solder, how many issues were caused by my inexperience in choosing electronic parts, and how time-intensive the actual process of construction is. After I completed designs, the turnaround time to an even remotely testable product was at least two weeks, accounting for procedural hiccups. Learning to effectively solder took, on its own, a month. I go into further 
