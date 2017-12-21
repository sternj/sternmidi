int active;
int currBtn1;
int currBtn2;
int  motorMappings[9][3] = {{22,23,24},{25,26,27},{28,29,30},{31,32,33},{34,35,36},{37,38,39},{40,41,42},{43,44,45},{46,47,48}};
double motorCalibration[9][2];
int storedValues1[9];
int storedValues2[9];
void calibrateFader() {
  //pin order-- white, blue, green
    Serial.write("Calibrating\n");
    for(int i = 0; i < 9; i++) {
      digitalWrite(motorMappings[i][2], HIGH);
      digitalWrite(motorMappings[i][0], HIGH);
      delay(250);
       digitalWrite(motorMappings[i][0], LOW);
       motorCalibration[i][1] = analogRead(i);
       digitalWrite(motorMappings[i][1], HIGH);
      delay(250);
       digitalWrite(motorMappings[i][1], LOW);
       motorCalibration[i][0] = analogRead(i);
      digitalWrite(motorMappings[i][0],LOW);
       storedValues1[i] = motorCalibration[i][1] + (motorCalibration[i][1]-motorCalibration[i][0])/2;
    }
}
void setup() {
  Serial.begin(9600);
  calibrateFader();
  // begins to read value from serial monitor
 
  
}

void loop() {
      if(digitalRead(1) != currBtn1) {
        delay(10);
        if(digitalRead(1) != currBtn1) {
          currBtn1 = digitalRead(1);
          active = 1;
          changeValues(storedValues1);
        }
        
      } else if(digitalRead(2) != currBtn2) {
        delay(10);
        if(digitalRead(2) != currBtn2) {
           currBtn2 = digitalRead(2);
           active = 2;
           changeValues(storedValues2);
        }
       
      }else if(digitalRead(3) == HIGH) {
        save(active);
      }
     
   
  }
void changeValues(int bank[]) {
   for(int i = 0; i < 9; ++i) {
          if(abs(bank[i]-analogRead(i)) >= 10) {
            adjustFaderToValue(motorMappings[i],i,bank[i],i,motorCalibration[i]);
            delay(10);
          } 
      }
}
void adjustFaderToValue(int pins[], int potNum, int newValue, int analogPin, double maxAndMin[]) {
  //form of pins-- [upPin, downPin, enablePin]
  //form of maxAndMin-- [min,max]
  if (newValue < analogRead(analogPin) - 10 && analogRead(analogPin) > maxAndMin[0]) {
        digitalWrite(pins[1], HIGH);
        while (analogRead(analogPin) < analogRead(analogPin) - 10) {};  //Loops until motor is done moving
        digitalWrite(pins[1], LOW);
    }
    else if (newValue > analogRead(analogPin) + 10 && analogRead(analogPin) < maxAndMin[1]) {
        digitalWrite(pins[0], HIGH);
        while (analogRead(analogPin) > analogRead(analogPin) + 10) {}; //Loops until motor is done moving
        digitalWrite(pins[0], LOW);
    }
     if (newValue < analogRead(analogPin) - 10 && analogRead(analogPin) > maxAndMin[0]) {
        digitalWrite(pins[1], HIGH);
        while (analogRead(analogPin) < analogRead(analogPin) - 10) {};  //Loops until motor is done moving
        digitalWrite(pins[1], LOW);
    }
    else if (newValue > analogRead(analogPin) + 10 && analogRead(analogPin) < maxAndMin[1]) {
        digitalWrite(pins[0], HIGH);
        while (analogRead(analogPin) > analogRead(analogPin) + 10) {}; //Loops until motor is done moving
        digitalWrite(pins[0], LOW);
    }
}
void save(int active) {
  if(active == 1) {
    for(int i = 0; i < 9; ++i) {
      storedValues1[i] = analogRead(i);
      delay(10);
    }
  } else {
    for(int i = 0; i < 9; ++i) {
      storedValues1[i] = analogRead(i);
      delay(10);
    }
  }
}
