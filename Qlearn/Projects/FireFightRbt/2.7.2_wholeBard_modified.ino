// Obstacle Avoiding Robot Code
// Based on Arduino
// Author: Aswin

// IR Sensor Pins
const int RightIRsensor = A5;
const int FrontIRsensor = A4;
const int LeftIRsensor = A3;

// Robot Wheels
const int LeftMtrInput1 = 2;
const int LeftMtrInput2 = 3;
const int RightMtrInput1 = 4;
const int RightMtrInput2 = 5;

// Motor PWM Speed Control Pins
const int EnableLeftMtr = 10;
const int EnableRightMtr = 11;

// Variables
int dist2FireFront;
int dist2FireRight;
int dist2FireLeft;

void setup() {
  // Serial Monitor
  Serial.begin(9600);

  // Pinmode Setup
  // Output
  pinMode(LeftMtrInput1, OUTPUT);
  pinMode(LeftMtrInput2, OUTPUT);
  pinMode(RightMtrInput1, OUTPUT);
  pinMode(RightMtrInput2, OUTPUT);
  // Motor Driver
  pinMode(EnableLeftMtr, OUTPUT);
  pinMode(EnableRightMtr, OUTPUT);
  // Input IR Sensors
  pinMode(RightIRsensor, INPUT);
  pinMode(FrontIRsensor, INPUT);
  pinMode(LeftIRsensor, INPUT);
}

void loop() {
  // Read the IR Sensor Values
  dist2FireFront = analogRead(FrontIRsensor);
  dist2FireRight = analogRead(RightIRsensor);
  dist2FireLeft = analogRead(LeftIRsensor);

  // If there is no obstacle in front, move forward
  if (dist2FireFront > 200 && dist2FireLeft > 200 && dist2FireRight > 200) {
    move_robotFrwd();
  }

  // If there is an obstacle in front and to the left, move right
  else if (dist2FireFront < 200 && dist2FireLeft < 200 && dist2FireRight > 200) {
    move_robotRight();
  }

  // If there is an obstacle in front and to the right, move left
  else if (dist2FireFront < 200 && dist2FireRight < 200 && dist2FireLeft > 200) {
    move_robotLeft();
  }

  // If there is an obstacle in front and to the left and right, move backward
  else {
    move_robotBack();
    delay(500);
    //break;
  }

  // Delay for 500 milliseconds
  delay(500);
}

void move_robotFrwd() {
  // Set the motor directions to move forward
  digitalWrite(LeftMtrInput1, HIGH);
  digitalWrite(LeftMtrInput2, LOW);
  digitalWrite(RightMtrInput1, HIGH);
  digitalWrite(RightMtrInput2, LOW);

  // Set the motor speeds
  analogWrite(EnableLeftMtr, 255);
  analogWrite(EnableRightMtr, 255);
}

void move_robotRight() {
  // Set the motor directions to move right
  digitalWrite(LeftMtrInput1, HIGH);
  digitalWrite(LeftMtrInput2, LOW);
  digitalWrite(RightMtrInput1, LOW);
  digitalWrite(RightMtrInput2, LOW);

  // Set the motor speeds
  analogWrite(EnableLeftMtr, 255);
  analogWrite(EnableRightMtr, 0);
}

void move_robotLeft() {
  // Set the motor directions to move left
  digitalWrite(LeftMtrInput1, LOW);
  digitalWrite(LeftMtrInput2, LOW);
  digitalWrite(RightMtrInput1, HIGH);
  digitalWrite(RightMtrInput2, LOW);

  // Set the motor speeds
  analogWrite(EnableLeftMtr, 0);
  analogWrite(EnableRightMtr, 255);
}

void move_robotBack() {
  // Set the motor directions to move backward
  digitalWrite(LeftMtrInput1, LOW);
  digitalWrite(LeftMtrInput2, HIGH);
  digitalWrite(RightMtrInput1, LOW);
  digitalWrite(RightMtrInput2, HIGH);

  // Set the motor speeds
  analogWrite(EnableLeftMtr, 255);
  analogWrite(EnableRightMtr, 255);
}
