int motorUp = 1;
int motorDown = 2;
void setup() {
  
 
  // begins to read value from serial monitor
  Serial.begin(9600);
  
}

void loop() {
  if(Serial.available() > 0) {
    int gotten = Serial.parseInt();
    if(gotten > 127 || gotten <= 0) {
      Serial.writeln("Invalid value");
      continue;
    }
    gotten *= 8;
    //More separate subroutines
    while(abs(analogRead(A0)-gotten) >= 7) {
      int cur = analogRead(A0);
      if(cur < gotten) {
        digitalWrite(motorUp, HIGH);
        while(analogRead(A0) < gotten-10) {};
        digitalWrite(motorUp, LOW);
      } else if(cur < gotten) {
        digitalWrite(motorDown, HIGH);
        while(analogRead(A0) > gotten+10) {};
        digitalWrite(motorDown, LOW);
      }
    }
    
   
 // }
   digitalWrite(2, HIGH);
}


