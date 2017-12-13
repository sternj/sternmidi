int motorUp = 2;
int motorDown = 3;
int gotten = 0;
int wiper = A0;
double faderMax = 0;
double faderMin = 0;
int  motorMappings[9][3] = {{22,23,24},{25,26,27},{28,29,30},{31,32,33},{34,35,36},{37,38,39},{40,41,42},{43,44,45},{46,47,48}};
double motorCalibration[9][2];
int storedValues[9];
void calibrateFader() {
  //pin order-- white, blue, green
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
       storedValues[i] = motorCalibration[i][1] + (motorCalibration[i][1]-motorCalibration[i][0])/2;
    }
}
void setup() {
  Serial.begin(9600);
  calibrateFader();
  // begins to read value from serial monitor
 
  
}

void loop() {
      
      for(int i = 0; i < 9; ++i) {
          if(abs(storedValues[i]-analogRead(i)) >= 10) {
            adjustFaderToValue(motorMappings[i],i,storedValues[i],i,motorCalibration[i];
            delay(10);
          } 
      }
   
  }
void adjustFaderToValue(int[] pins, int potNum, int newValue, int analogPin, double[] maxAndMin) {
  //form of pins-- [upPin, downPin, enablePin]
  //form of maxAndMin-- [min,max]
  if (newValue < analogRead(analogPin) - 10 && gotten > maxAndMin[0]) {
        digitalWrite(pins[1], HIGH);
        while (gotten < analogRead(analogPin) - 10) {};  //Loops until motor is done moving
        digitalWrite(pins[1], LOW);
    }
    else if (newValue > analogRead(analogPin) + 10 && gotten < maxAndMin[1]) {
        digitalWrite(pins[0], HIGH);
        while (gotten > analogRead(analogPin) + 10) {}; //Loops until motor is done moving
        digitalWrite(pins[0], LOW);
    }
     if (newValue < analogRead(analogPin) - 10 && gotten > maxAndMin[0]) {
        digitalWrite(pins[1], HIGH);
        while (gotten < analogRead(analogPin) - 10) {};  //Loops until motor is done moving
        digitalWrite(pins[1], LOW);
    }
    else if (newValue > analogRead(analogPin) + 10 && gotten < maxAndMin[1]) {
        digitalWrite(pins[0], HIGH);
        while (gotten > analogRead(analogPin) + 10) {}; //Loops until motor is done moving
        digitalWrite(pins[0], LOW);
    }
  
}
