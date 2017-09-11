int buttonState = 0;
int formerButtonState = 0;
int pedalPin = 2;
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(pedalPin);
  //if the state of the pedal changes
  if(buttonState != formerButtonState) {
    if(buttonState == HIGH) {
      //send "on" signal to midi pedal controller (Control 4) on channel 1
     // MIDI.sendControlChange(4,128,1);
      MIDI.sendNoteOn(64,64,1);
    }
    else { //if buttonState == LOW
      //send "off" signal to MIDI pedal controller (Control 4) on channel 1
     // MIDI.sendControlChange(4,0,1);
      MIDI.sendNoteOff(64,64,1);
    }
  }
  formerButtonState = buttonState;
}
