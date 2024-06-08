// Define motor pins
#define MOTOR1_EN 9 // Enable pin for left motor
#define MOTOR1_IN1 8 // Control pin 1 for left motor
#define MOTOR1_IN2 7 // Control pin 2 for left motor
#define MOTOR2_EN 10 // Enable pin for right motor
#define MOTOR2_IN1 12 // Control pin 1 for right motor
#define MOTOR2_IN2 11 // Control pin 2 for right motor

// Define IR sensor pins
#define LEFT_IR A0
#define RIGHT_IR A1

// Define IR sensor threshold values
#define THRESHOLD 500 // Adjust this threshold value according to your sensor readings

void setup() {
  // Motor pins setup
  pinMode(MOTOR1_EN, OUTPUT);
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_EN, OUTPUT);
  pinMode(MOTOR2_IN1, OUTPUT);
  pinMode(MOTOR2_IN2, OUTPUT);
  
  // IR sensor pins setup
  pinMode(LEFT_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);
}

void loop() {
  int leftSensorValue = analogRead(LEFT_IR);
  int rightSensorValue = analogRead(RIGHT_IR);

  // If both sensors detect the line, move forward
  if (leftSensorValue > THRESHOLD && rightSensorValue > THRESHOLD) {
    moveForward();
  } 
  // If left sensor detects the line, turn left
  else if (leftSensorValue > THRESHOLD) {
    turnLeft();
  } 
  // If right sensor detects the line, turn right
  else if (rightSensorValue > THRESHOLD) {
    turnRight();
  } 
  // If neither sensor detects the line, stop
  else {
    stopMoving();
  }
}

// Function to move the robot forward
void moveForward() {
  digitalWrite(MOTOR1_IN1, HIGH);
  digitalWrite(MOTOR1_IN2, LOW);
  digitalWrite(MOTOR2_IN1, HIGH);
  digitalWrite(MOTOR2_IN2, LOW);
  analogWrite(MOTOR1_EN, 200); // Adjust speed as needed
  analogWrite(MOTOR2_EN, 200); // Adjust speed as needed
}

// Function to turn the robot left
void turnLeft() {
  digitalWrite(MOTOR1_IN1, LOW);
  digitalWrite(MOTOR1_IN2, HIGH);
  digitalWrite(MOTOR2_IN1, HIGH);
  digitalWrite(MOTOR2_IN2, LOW);
  analogWrite(MOTOR1_EN, 150); // Adjust speed as needed
  analogWrite(MOTOR2_EN, 150); // Adjust speed as needed
}

// Function to turn the robot right
void turnRight() {
  digitalWrite(MOTOR1_IN1, HIGH);
  digitalWrite(MOTOR1_IN2, LOW);
  digitalWrite(MOTOR2_IN1, LOW);
  digitalWrite(MOTOR2_IN2, HIGH);
  analogWrite(MOTOR1_EN, 150); // Adjust speed as needed
  analogWrite(MOTOR2_EN, 150); // Adjust speed as needed
}

// Function to stop the robot
void stopMoving() {
  digitalWrite(MOTOR1_IN1, LOW);
  digitalWrite(MOTOR1_IN2, LOW);
  digitalWrite(MOTOR2_IN1, LOW);
  digitalWrite(MOTOR2_IN2, LOW);
  analogWrite(MOTOR1_EN, 0);
  analogWrite(MOTOR2_EN, 0);
}
