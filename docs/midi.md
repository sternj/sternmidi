# What is MIDI?
MIDI is a layer-6 standard for serial communication developed in 1983. It was developed in part as a natural extension of the control voltage communication of modular synthesizers of the 1960s-70s. There were a few issues with these.

<p style = "text-align: center;">
<img src = "./modular.jpg" align = "center" style = "text-align: center; width: 50%" />
</p>

The most obvious one is that these cables take up massive amounts of space and can get messy very quickly. This is because each one can only carry a single signal, limiting its usefulness.


The second one is that there absolutely **had** to be a better way for two devices to communicate than through a massive chunk of wires. Using voltage control to make instruments communicate made sense when the main users of synthesizers were art musicians, but now people were wanting to use synthesizers more like pianos, with similar information being conveyed to multiple devices using a single controller.


Thom Holmes in *Electronic and Experimental Music* states that MIDDI was designed with "two basic applications in mind: connecting and controlling synthesizers ... [and] linking computers to synthesizers". To do this, it had to be fast and compact.


The designers of MIDI achieved this by making it an incredibly lightweight serial protocol. The standard MIDI signal consists of between two and three bytes, which can be encoded, transmitted, and parsed in minuscule amounts of time. The first byte of a MIDI signal is called the "status byte". It contains two hexadecimal digits--the first signifies what the next one or two bytes will be doing, and the second indicates what channel the signal is being broadcast to. For instance, if the status byte was 0x9A, a note-on signal would be sent to channel 10. In general, a channel corresponds to a sound-generator or instrument.

The next one or two bytes are contextual. Each of these data bytes carries a single value, the meaning of which is dictated by the status byte and may take on a value between 0 and 127. In the case of our "note on" signal from the previous paragraph, the second byte would tell the instrument listening on channel 10 what note to play. 0d60 is the value corresponding to a middle C.

Continuing with the case of our "note on" to channel 10, the final byte indicates the velocity with which the note is to be struck. Velocity is somewhat analogous to volume, though notes struck with different velocities may have different tambours as well. For instance, a velocity byte containing the value "0d16" would be a moderately soft note.

Combining a status byte and two data bytes, we have an entire MIDI signal. Let us observe the signal "0x96 0x3C 0x10" would send a note-on signal to channel 6 containing a middle C struck with velocity 16. 

In essence, every MIDI signal is telling a particular device to do a particular thing. Everything you can do with a piano, you can do with MIDI. For instance, there are signals dedicated to turning specific notes on, and there is a signal that frequently corresponds to the sustain pedal. This is not to say that a MIDI piano will sound as good as the real thing (it won't), just that the idea behind MIDI signaling is intuitive.
