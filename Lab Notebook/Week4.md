
Here are the schematics for the MIDI controller that I'm building right now while figuring out servo control. The top row is rotary potentiometers, the second pushbuttons, the third row indicator lights for the fourth row, and the fourth row toggle switches. As the toggle switches on the wiring diagram do not demonstrate the fact that there are two independent leads on the switches I have in, the lights aren't present on the wiring diagram. Naturally the components would be attached to the faceplate rather than soldered into a board, I represented it as such simply for the purpose of readability. I am printing out the case in the next few minutes, I just have to make sure I measured the LED slots correctly. 
(picture to be inserted)  \br


I have all of the parts for this build in and I am attaching them right now, the soldering is taking longer than anticipated though. With regards to servo control, I' think that I am going to need some flavor of logic gate but control is doable and simply involves making a feedback loop between an analog input and the resistor part of the motorized fader (linear potentiometer). 



I have no further progress on the JUICE API, as per your advice.



The Arduino Due has been successfully mounted as a USB-MIDI device.



All parts needed for the initial deliverable (that I am prototyping now) have arrived. 



Over the next week, the main thing I have to do is actually acquire the motorized potentiometers. Cost is the major barrier here. Pending that, I should have the code totally done and the case fully designed by the end of the week. This will be so that I can ensure compilation and move on to the next phase of the project. You suggested a performance on the organ, and I have not talked with anyone about that thus far. I think a potential next step would be to attempt to launch a VST organ module on a Raspberry Pi. 



For the final deliverable, I am thinking more and more that a piece of software written in some hybrid of Juice and Max/MSP would be optimal. My current thoughts involve an integrated software/hardware package addressing some issue in workflow in music production. Right now I am thinking about clock and signal integration between analog and digital instruments, but it isn't worth considering for at least a week hence.

#Todo for next week
- START KEEPING REGULAR LAB JOURNAL
