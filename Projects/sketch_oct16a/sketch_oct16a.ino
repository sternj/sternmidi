int fmrBtnStates[8];
int fmrPotStates[8];
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
void setup() {
  Serial.begin(115200);
  for(int i = 2; i < 10; i++) {
     pinMode(i, INPUT);
  }
}

void loop() {
  // Reading in values from analog and digital inputs
  for(int i = 2; i < 10; i++) {
    int temp = digitalRead(i);
    if(temp != fmrBtnStates[i-1]) {
      if(temp == HIGH) {
        MIDI.sendControlChange(i,127,1);
        fmrBtnStates[i-2] = HIGH;
    }
      if(temp == LOW) {
        MIDI.sendControlChange(i,0,1);
        fmrBtnStates[i-2] = LOW;
       }
    }
  }
  for(int i = 0; i < 5; i++) {
  int temp = analogRead(i)/8;
    if(temp != fmrPotStates[i]) {
       MIDI.sendControlChange(i+10,temp,1);
    }
  }



}
