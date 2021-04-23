/**********************************************************************
  Filename    : Control_Motor_by_L293D
  Description : Use PWM to control the direction and speed of the motor.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
int in1Pin = 15;      // Define L293D channel 1 pin
int in2Pin = 33;      // Define L293D channel 2 pin
int enable1Pin = 32;  // Define L293D enable 1 pin
int channel = 0;
int in3Pin = 12;      // Define L293D channel 1 pin
int in4Pin = 14;      // Define L293D channel 2 pin
int enable2Pin = 13;  // Define L293D enable 1 pin
int channel1 = 1;
boolean rotationDir;  // Define a variable to save the motor's rotation direction
int rotationSpeed = 4000;    // Define a variable to save the motor rotation speed
boolean rotationDir2;  // Define a variable to save the motor's rotation direction
int rotationSpeed2 = 4000;    // Define a variable to save the motor rotation speed
#include <DFRobot_PAJ7620U2.h>
DFRobot_PAJ7620U2 paj;

void setup() {
  Serial.begin(115200);
  delay(300);
  Serial.println("Gesture recognition system base on PAJ7620U2");
  while(paj.begin() != 0){
    Serial.println("initial PAJ7620U2 failure! Please check if all the connections are fine, or if the wire sequence is correct?");
    delay(500);
  }
  Serial.println("PAJ7620U2 init completed, start to test the gesture recognition function");
  paj.setGestureHighRate(true);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  pinMode(enable2Pin, OUTPUT);  
  ledcSetup(channel,1000,11);         //Set PWM to 11 bits, range is 0-2047
  ledcAttachPin(enable1Pin,channel);
  ledcSetup(channel1,1000,11);         //Set PWM to 11 bits, range is 0-2047
  ledcAttachPin(enable2Pin,channel1);
}

void loop() {
  DFRobot_PAJ7620U2::eGesture_t gesture = paj.getGesture();
  if(gesture != paj.eGestureNone ){
    Serial.println(gesture);
    if (gesture == 1){//right
      rotationDir = true;
      driveMotor(rotationDir, constrain(rotationSpeed,0,2048));
      delay(300);
      driveMotor(rotationDir, constrain(0,0,2048));
    }
    else if (gesture == 2){//left
      rotationDir = false;
      driveMotor(rotationDir, constrain(rotationSpeed,0,2048));
      delay(300);
      driveMotor(rotationDir, constrain(0,0,2048));      
    }
    else if (gesture == 4){//up
      rotationDir2 = false;
      driveMotor2(rotationDir2, constrain(rotationSpeed,0,2048));
      delay(250);
      driveMotor2(rotationDir2, constrain(0,0,2048));      
    }
    else if(gesture == 8){//down
      rotationDir2 = true;
      driveMotor2(rotationDir2, constrain(rotationSpeed,0,2048));
      delay(200);  
      driveMotor2(rotationDir2, constrain(0,0,2048));    
    }
  }
}

void driveMotor(boolean dir, int spd) {
  // Control motor rotation direction
  if (rotationDir) {
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
  }
  else {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
  }
  // Control motor rotation speed
  ledcWrite(channel, spd);
}

void driveMotor2(boolean dir, int spd) {
  // Control motor rotation direction
  if (rotationDir2) {
    digitalWrite(in3Pin, HIGH);
    digitalWrite(in4Pin, LOW);
  }
  else {
    digitalWrite(in3Pin, LOW);
    digitalWrite(in4Pin, HIGH);
  }
  // Control motor rotation speed
  ledcWrite(channel1, spd);
}
