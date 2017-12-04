int motorUp = 2;
int motorDown = 3;
int gotten = 0;
int wiper = A0;
double faderMax = 0;
double faderMin = 0;
void calibrateFader() {
  //pin order-- white, blue, green
  
    //Send fader to the top and read max position
   // digitalWrite(enable, HIGH);
    digitalWrite(motorUp, HIGH);
    Serial.print("Going up! \n");
    delay(250);
    Serial.print("Going down! \n");
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

 //   Serial.println(analogRead(A0));
    if(digitalRead(5) == HIGH) {
      Serial.print("Black button pressed\n");
      String str = "Got ";
      
      
      
      gotten = analogRead(A0);
      str += gotten;
      str += "\n";
      Serial.print(str);
    }
    if(digitalRead(4) == HIGH) {
      Serial.print("Red button pressed\n");
       String str = "Got=ing to ";
      str += gotten;
      str += "\n";
      //adapted from codyhazelwood/motorized-fader-arduino
      Serial.print(str);
      if (gotten < analogRead(wiper) - 10 && gotten > faderMin) {
        digitalWrite(motorDown, HIGH);
        while (gotten < analogRead(wiper) - 10) {};  //Loops until motor is done moving
        digitalWrite(motorDown, LOW);
    }
    else if (gotten > analogRead(wiper) + 10 && gotten < faderMax) {
        digitalWrite(motorUp, HIGH);
        while (gotten > analogRead(wiper) + 10) {}; //Loops until motor is done moving
        digitalWrite(motorUp, LOW);
    }
    }

   
  }
