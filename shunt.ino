#include <AFMotor.h>

AF_DCMotor motor(1); // To the tracks

int S1 = 38;
int S2 = 40;
int S3 = 42;
int S4 = 44;

int T1T = 22;
int T1C = 23;
int T2T = 24;
int T2C = 25;

// Set all sensor variables to false
Sensor1 = false;
Sensor2 = false;
Sensor3 = false;
Sensor4 = false;

int sensorCount = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(T1T, OUTPUT);
  pinMode(T1C, OUTPUT);
  pinMode(T2T, OUTPUT);
  pinMode(T2C, OUTPUT);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);

  delay(2000); // Wait 5 seconds

  // Initial state of points (close 1, throw 2)
  close1();
  delay(400);
  throw2();

  motor.run(RELEASE);
}

void loop() {
  // Forward loco
  motor.run(FORWARD);
  motor.setSpeed(255);
  
  //while(digitalRead(S4) != LOW){}
  
  while(Sensor4 == false){
    // If sensor is triggerd
    if(digitalRead(S4) != LOW) {
      // Poll another 10 times to confirm
      for(i = 0; i < 10; i++){
        if(digitalRead(S4) != LOW){
          sensorCount++;
        }
      }

      // confirm positive 10 times
      if(sensorCount == 10) {
        Sensor4 = true;
      }

      // reset sensorCount
      sensorCount = 0;
    }
  }
  // reset sensor
  Sensor4 = false;

  // Stop Loco
  motor.setSpeed(0);

  delay(5000);
  close2();
  delay(5000);
  
  // Reverse loco
  motor.run(BACKWARD);
  motor.setSpeed(255);
  
  //while(digitalRead(S1) != LOW){}

  while(Sensor1 == false){
    // If sensor is triggerd
    if(digitalRead(S1) != LOW) {
      // Poll another 10 times to confirm
      for(i = 0; i < 10; i++){
        if(digitalRead(S1) != LOW){
          sensorCount++;
        }
      }

      // confirm positive 10 times
      if(sensorCount == 10) {
        Sensor1 = true;
      }

      // reset sensorCount
      sensorCount = 0;
    }
  }
  // reset sensor
  Sensor1 = false;

  // Stop loco
  motor.setSpeed(0);

  delay(5000);
  throw1();
  delay(5000);

  // Forward loco
  motor.run(FORWARD);
  motor.setSpeed(255);
  
  //while(digitalRead(S3) != LOW){}

  while(Sensor3 == false){
    // If sensor is triggerd
    if(digitalRead(S3) != LOW) {
      // Poll another 10 times to confirm
      for(i = 0; i < 10; i++){
        if(digitalRead(S3) != LOW){
          sensorCount++;
        }
      }

      // confirm positive 10 times
      if(sensorCount == 10) {
        Sensor3 = true;
      }

      // reset sensorCount
      sensorCount = 0;
    }
  }
  // reset sensor
  Sensor3 = false;

  // Stop loco
  motor.setSpeed(0);
  
  delay(5000);
  throw2();
  delay(5000);

  // Reverse loco
  motor.run(BACKWARD);
  motor.setSpeed(255);
  
  //while(digitalRead(S2) != LOW){}

  while(Sensor2 == false){
    // If sensor is triggerd
    if(digitalRead(S2) != LOW) {
      // Poll another 10 times to confirm
      for(i = 0; i < 10; i++){
        if(digitalRead(S2) != LOW){
          sensorCount++;
        }
      }

      // confirm positive 10 times
      if(sensorCount == 10) {
        Sensor2 = true;
      }

      // reset sensorCount
      sensorCount = 0;
    }
  }
  // reset sensor
  Sensor2 = false;

  // Stop loco
  motor.setSpeed(0);
  
  delay(5000);
  close1();
  delay(5000);
  
}

void throw1() {
  digitalWrite(T1T, HIGH);
  delay(100);
  digitalWrite(T1T, LOW);
  delay(100);
}
void close1() {
  digitalWrite(T1C, HIGH);
  delay(100);
  digitalWrite(T1C, LOW);
  delay(100);
}
void throw2() {
  digitalWrite(T2T, HIGH);
  delay(100);
  digitalWrite(T2T, LOW);
  delay(100);
}
void close2() {
  digitalWrite(T2C, HIGH);
  delay(100);
  digitalWrite(T2C, LOW);
  delay(100);
}
