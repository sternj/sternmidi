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
I initially thought that most of my issues with this project would be in implementing the software for serial communication from the Arduino. This turned out to be the simplest part of the entire process. The hardware proved to be incredibly time-consuming. I did not account for how long it would take to solder, how many issues were caused by my inexperience in choosing electronic parts, and how time-intensive the actual process of construction is. After I completed designs, the turnaround time to an even remotely testable product was at least two weeks, accounting for procedural hiccups. Learning to effectively solder took, on its own, a month. I go into further detail in the "challenges" subheading of each project page.

### Personal learning
I very apparently gained moderately-advanced soldering and circuit design skills in the process of this project. However, I also learned critical lessons about time management. Firstly, hardware invariably takes much more time than I would estimate. It is physically more difficult and far more time-consuming to solder than to write code. Because of this, in hardware, precision and time-management carry greater weight than they do even in software. In a similar manner, I learned that I need to do more careful research on hardware dependencies, anticipate missing parts, and leave spare time for shipping.

I also need to be far more vigilant about documenting my progress through multiple media and planning more meticulously. I did not have pictures or schematics for the early phases of each of the projects, and it would have helped me in scaling up my proofs-of-concept to have what I already did more precisely laid-out. There were many times when I did not know which wires were going where, so I was unable to figure out what was going wrong.

On a similar token, however, I became better at designing electronics hardware in a way that is more visually pleasing and more organized. Rather than using any spare wire, on the motorized controller I color-coded the functions of the wires and made sure that the internal wiring on the breadboard was compact and intuitive. Many of the issues that arose in building the first controller simply originated in the fact that I did not take these measures, and the lack of organization forced me to rewire several times, adding unnecessary hours to the process of building it.

I also need to focus more on the end goal, rather than necessarily what is directly in front of me. Frequently, I can persist on an invalid path for far too long, or get distracted by a facet of a project wholly unrelated to the long-term goal. This is something that I need to work on more in future projects, and something that I am working on right now-- I am finishing up this section before attempting to solve navigability issues in this site.  
