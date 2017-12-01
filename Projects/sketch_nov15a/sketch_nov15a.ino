int motorUp = 2;
int motorDown = 3;

int wiper = A0;
double faderMax = 0;
double faderMin = 0;
void calibrateFader() {
  
    //Send fader to the top and read max position
   // digitalWrite(enable, HIGH);
    digitalWrite(motorUp, HIGH);
    Serial.write("Going up! \n");
    delay(250);
    Serial.write("Going down! \n");
    digitalWrite(motorUp, LOW);
   // digitalWrite(enable, LOW);
    faderMax = analogRead(wiper);

    //Send fader to the bottom and read max position
    digitalWrite(motorDown, HIGH);
    delay(250);
    digitalWrite(motorDown, LOW);
    faderMin = analogRead(wiper);
}
void setup() {
  pinMode(2,OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, INPUT);
pinMode(5, INPUT);
  Serial.begin(9600);
  calibrateFader();
  // begins to read value from serial monitor
 
  
}

void loop() {
  if(Serial.available() > 0) {
    int gotten = Serial.parseInt();
    if(gotten > 127 || gotten <= 0) {
      Serial.write("Invalid value");
      Serial.write("\n");
      return;
    }
    gotten *= 8;
    //More separate subroutines
    while(abs(analogRead(A0)-gotten) >= 7) {
      int cur = analogRead(A0);
      if(cur < gotten) {
        digitalWrite(motorUp, HIGH);
    //    digitalWrite(enable, HIGH);
        while(analogRead(A0) < gotten-10) {};
    //    digitalWrite(enable, LOW);
        digitalWrite(motorUp, LOW);
      } else if(cur < gotten) {
        digitalWrite(motorDown, HIGH);
//        digitalWrite(enable, HIGH);
        while(analogRead(A0) > gotten+10) {};
       // digitalWrite(enable, LOW);
        digitalWrite(motorDown, LOW);
      }
    }
    
   
  }
}



