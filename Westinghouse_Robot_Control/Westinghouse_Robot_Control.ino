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
  if (throttleTime < 1000) throttleTime = 1000;
  if (throttleTime > 2000) throttleTime = 2000;
  if (steeringTime < 1000) steeringTime = 1000;
  if (steeringTime > 2000) steeringTime = 2000;
  int throttleInput = (throttleTime - 1000) * 255 / 1000;
  int steeringInput = (steeringTime - 1000) * 255 / 1000;
  // math code looks at throttleInput and steeringInput and stores values in leftOutput and rightOutput
  // TODO: put math code here

  // output code takes leftOutput and rightOutput values and sends them to the motor controllers
  leftOutput = leftOutput * 180 / 255;
  rightOutput = rightOutput * 180 / 255;
  leftMotor.write(leftOutput);
  rightMotor.write(rightOutput);

  // update stored values
  lastThrottlePulse = throttlePulse;
  lastSteeringPulse = steeringPulse;
}
