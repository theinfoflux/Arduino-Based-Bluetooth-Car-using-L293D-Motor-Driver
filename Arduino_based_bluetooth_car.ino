#include <AFMotor.h>
#include <SoftwareSerial.h>

// Define SoftwareSerial pins for HC-05
SoftwareSerial BT(10, 9); // TX=10, RX=9

// Motors
AF_DCMotor motorLeft(4);
AF_DCMotor motorRight(1); 
char command[10];   // buffer for incoming command
int index = 0;      // buffer index
int motorSpeed = 200; // default speed (0-255)

// Motor helpers
void moveForward() {
  motorLeft.setSpeed(motorSpeed);
  motorRight.setSpeed(motorSpeed);
  motorLeft.run(FORWARD);
  motorRight.run(FORWARD);
}

void reverseRobot() {
  motorLeft.setSpeed(motorSpeed);
  motorRight.setSpeed(motorSpeed);
  motorLeft.run(BACKWARD);
  motorRight.run(BACKWARD);
}

void stopRobot() {
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}

void turnLeftSmooth() {
  motorLeft.setSpeed(motorSpeed);
  motorRight.setSpeed(motorSpeed);
  motorLeft.run(RELEASE);
  motorRight.run(FORWARD);
}

void turnRightSmooth() {
  motorLeft.setSpeed(motorSpeed);
  motorRight.setSpeed(motorSpeed);
  motorLeft.run(FORWARD);
  motorRight.run(RELEASE);
  

}


void setup() {
  Serial.begin(9600);
   BT.begin(9600);
 
}

void loop() {

  // Read incoming Bluetooth commands
 while (BT.available() > 0) {
  char c = BT.read();
  Serial.println(c);
switch(c){
  case 'F':
    Serial.println("Forward");
    moveForward(); 
  break;
   case 'B':
   Serial.println("Backward");
  reverseRobot();
  break;
   case 'R':
 turnRightSmooth();
  break;
  case 'L':
  Serial.println("Left");
  turnLeftSmooth();
  break;
  case 'S':
  Serial.println("Stop");
  stopRobot();
  break;
  case'0':
motorSpeed=0;
  break;
  case'1':
motorSpeed=25;
  break;
  case'2':
motorSpeed=50;
  break;

  case'3':
motorSpeed=75;
  break;
  case'4':
motorSpeed=100;
  break;
  case'5':
motorSpeed=125;
  break;
    case'6':
motorSpeed=150;
  break;
  case'7':
motorSpeed=175;
  break;

   case'8':
motorSpeed=200;
  break;
    case'9':
motorSpeed=255;
  break;
  }
}
}
