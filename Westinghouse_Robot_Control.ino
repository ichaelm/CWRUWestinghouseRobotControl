#include <Servo.h>

int throttle;
int steering;
long leftOutput;
long rightOutput;
Servo leftMotor;
Servo rightMotor;

int throttleInputPin = 4;
int steeringInputPin = 5;
int leftMotorPin = 2;
int rightMotorPin = 3;

int lastThrottlePulse = 0;
unsigned long throttleTimeStart = 0;
unsigned long throttleTime = 0;
int lastSteeringPulse = 0;
unsigned long steeringTimeStart = 0;
unsigned long steeringTime = 0;


void setup() {
  pinMode(throttleInputPin, INPUT);
  pinMode(steeringInputPin, INPUT);
  leftMotor.attach(leftMotorPin);
  rightMotor.attach(rightMotorPin);
}

void loop() {
  // input code stores values in throttle and steering
  int throttlePulse = digitalRead(throttleInputPin);
  if (throttlePulse == HIGH && lastThrottlePulse == LOW) {
    // throttle pulse just started, so start a timer
    throttleTimeStart = micros();
  } else if (throttlePulse == LOW && lastThrottlePulse == HIGH) {
    throttleTime = micros()-throttleTimeStart;
  }
  int steeringPulse = digitalRead(steeringInputPin);
  if (steeringPulse == HIGH && lastSteeringPulse == LOW) {
    // throttle pulse just started, so start a timer
    steeringTimeStart = micros();
  } else if (steeringPulse == LOW && lastSteeringPulse == HIGH) {
    steeringTime = micros()-steeringTimeStart;
  }
  // math code stores values in leftOutput and rightOutput

  leftOutput = (((throttleTime - 1000) * 180) / 6000);
  rightOutput = (((steeringTime - 1000) * 180) / 6000);
  
  leftMotor.write(leftOutput);
  rightMotor.write(rightOutput);


  lastThrottlePulse = throttlePulse;
  lastSteeringPulse = steeringPulse;
}
