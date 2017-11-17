int fmrBtnStates[10];
int pt1;
int pt2;
int pt3;
int pt4;
int pt5;
int loc1 = 0;
int loc2 = 1;
int loc3 = 2;
int loc4 = 3;
int loc5 = 4;
//#include <MIDI.h>
//MIDI_CREATE_DEFAULT_INSTANCE();
void setup() {
  Serial.begin(9600);  
  for(int i = 2; i < 10; i++) {
     pinMode(i, INPUT);
  }
  pinMode(A0, INPUT);
 // pinMode(A1, INPUT);
//  pinMode(A2, INPUT);
 // pinMode(A3, INPUT);
 // pinMode(A4, INPUT);
  pt1 = 0;
  pt2 = 0;
  pt3 = 0;
  pt4 = 0;
  pt5 = 0;
  
}

void loop() {
  // Reading in values from analog and digital INPUTs
  for(int i = 2; i < 10; i++) {
    int temp = digitalRead(i);
    if(temp != fmrBtnStates[i]) {
      if(temp == HIGH) {
     
        String str = "Button ";
        str += i;
        str += " pressed";
        Serial.println(str);
        fmrBtnStates[i] = HIGH;
        delay(5);
    }
      if(temp == LOW) {
        String str = "Button ";
        str += i;
        str += " unpressed";
        Serial.println(str); 
        fmrBtnStates[i] = LOW;
        delay(5);
       }
    }
  }
//  int temp1 = analogRead(A0)/8;
//  if(abs(temp1 - pt1)>3) {
//      pt1 = temp1;
//      String str = "Pot 1 changed to ";
//      str += temp1;
//      Serial.println(str);
//  }
//  temp = analogRead(loc2)/8;
//  if(abs(temp-pt2) > 20) {
//      pt1 = temp;
//      String str = "Pot 2 changed to ";
//      str += temp;
//      Serial.println(str);
//  }
//  temp = analogRead(loc3)/8;
//  if(abs(temp-pt3) > 20) {
//      pt1 = temp;
//      String str = "Pot 3 changed to ";
//      str += temp;
//      Serial.println(str);
//  }
//  temp = analogRead(loc4)/8;
//  if(abs(temp-pt4) > 20) {
//      pt4 = temp;
//      String str = "Pot 4 changed to ";
//      str += temp;
//      Serial.println(str);
//  }temp = analogRead(loc5)/8;
//  if(abs(temp-pt5) > 20) {
//      pt5 = temp;
//      String str = "Pot 5 changed to ";
//      str += temp;
//      Serial.println(str);
//  }
//




}
