int pot1 = 0;
int pot2 = 1;
int valPot1 = 0;
int valPot2 = 0;
int fmrPot1 = 0;
int fmrPot2 = 0;
int btn1 = 2;
int btn2 = 4;
int btnState1 = 0;
int btnState2 = 0;
int fmrBtn1 = 0;
int fmrBtn2 = 0;
int fmrStates[8];
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
void setup() {
  Serial.begin(115200);
  for(int i = 2; i < 10; i++) {
     pinMode(i, INPUT);
  }
  // put your setup code here, to run once:

}

void loop() {
  // Reading in values from analog and digital inputs
  valPot1 = analogRead(pot1)/8;
  valPot2 = analogRead(pot2)/8;
  btnState1 = digitalRead(btn1);
  btnState2 = digitalRead(btn2);
  for(int i = 2; i < 8; i++) {
    int temp = digitalRead(i);
    if(temp != fmrStates[i-2]) {
    if(temp == HIGH) {
      MIDI.sendControlChange(i-2,127,1);
      fmrStates[i-2] = HIGH;
    }
    if(btnState1 == LOW) {
      MIDI.sendControlChange(3,0,1);
      fmrStates[i-2] = LOW;
    }
  }
  // Checking for changes from previous state
  if(valPot1 != fmrPot1) {
    //send midi signal
    MIDI.sendControlChange(1,valPot1,1);
    fmrPot1 = valPot1;
  }
  if(valPot2 != fmrPot2) {
    //send midi signal
    MIDI.sendControlChange(2,valPot2,1);
    fmrPot2 = valPot2;
  }
  if(btnState1 != fmrBtn1) {
    if(btnState1 == HIGH) {
      MIDI.sendControlChange(3,127,1);
      fmrBtn1 = HIGH;
    }
    if(btnState1 == LOW) {
      MIDI.sendControlChange(3,0,1);
      fmrBtn1 = LOW;
    }
  }
  if(btnState2 != fmrBtn2) {
    if(btnState2 == HIGH) {
      MIDI.sendControlChange(4,127,1);
      fmrBtn2 = HIGH;
    }
    if(btnState2 == LOW) {
      MIDI.sendControlChange(4,0,1);
      fmrBtn2 = LOW;
    }
  }
}
}
