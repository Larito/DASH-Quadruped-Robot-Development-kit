#include <ODriveUART.h>
#include <SoftwareSerial.h>
#include <HardwareSerial.h>

SoftwareSerial serial4(A9, 28);

unsigned long baudrate = 19200; // Must match what you configure on the ODrive
ODriveUART odrive1(Serial1);
ODriveUART odrive2(Serial2);
ODriveUART odrive3(Serial3);
ODriveUART odrive4(serial4);

void setup() {
  Serial.begin(9600);
  delay(100); // Wait for serial port to connect. Needed for native USB
  // Serial.println("Serial started");

  // Initialize serial ports dynamically based on the number of ODrives
  Serial1.begin(baudrate);
  Serial2.begin(baudrate);
  Serial3.begin(baudrate);
  serial4.begin(baudrate);

  delay(10);

  // Serial.println("Waiting for ODrive 1...");
  while (odrive1.getState() == AXIS_STATE_UNDEFINED) {
    // Serial.println("ODrive 1 state undefined, waiting...");
    delay(100);
    odrive1.clearErrors();
  }
  // Serial.println("Found ODrive 1");

    // Serial.println("Waiting for ODrive 2...");
  while (odrive2.getState() == AXIS_STATE_UNDEFINED) {
    // Serial.println("ODrive 2 state undefined, waiting...");
    delay(100);
    odrive2.clearErrors();
  }
  // Serial.println("Found ODrive 2");

    // Serial.println("Waiting for ODrive 3...");
  while (odrive3.getState() == AXIS_STATE_UNDEFINED) {
    // Serial.println("ODrive 3 state undefined, waiting...");
    delay(100);
    odrive3.clearErrors();
  }
  // Serial.println("Found ODrive 3");

    // Serial.println("Waiting for ODrive 4...");
  while (odrive4.getState() == AXIS_STATE_UNDEFINED) {
    // Serial.println("ODrive 4 state undefined, waiting...");
    delay(100);
    odrive4.clearErrors();
  }
  // Serial.println("Found ODrive 4");
}

void loop() {
    if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "d") {
      // Serial.println("clearing errors");
      odrive1.clearErrors();
      odrive2.clearErrors();
      odrive3.clearErrors();
      odrive4.clearErrors();
    }
    else if (command == "a") { //idle
      // Serial.println("Setting all ODrives to idle");
      odrive1.setState(AXIS_STATE_IDLE);
      odrive2.setState(AXIS_STATE_IDLE);
      odrive3.setState(AXIS_STATE_IDLE);
      odrive4.setState(AXIS_STATE_IDLE);
    }
    else if (command == "x") { //stand
      // Serial.println("setting to down position");
      // moveToPositionGradually4(-1.94, -5.04, 2.08, 5.65, -0.57, -3.32, 0.74, 3.68, 20);
      moveToPositionGradually224(2.08, 5.65, 0.74, 3.68, 20);
      delay(100);
      moveToPositionGradually213(-1.94, -5.04, -0.57, -3.32, 20);
    } 
    else if (command == "s") { //trot
      // Serial.println("Setting all ODrives to trot");
      for(int i=0;i<5;i++){
        moveToPositionGradually224(0.74, 3.68, 1.84, 5.49, 5);
        delay(100);
        moveToPositionGradually224(2.08, 5.65, 0.74, 3.68, 5);

        moveToPositionGradually213(-0.57, -3.32, -2.0, -5.31, 5);
        delay(100);
        moveToPositionGradually213(-1.94, -5.04, -0.57, -3.32, 5);
      }
    } else if (command == "w") { //triangle
      // Serial.println("Triangle sequence");
      odrive1.setPosition(1.86);
      odrive3.setPosition(-0.55);
      odrive2.setPosition(-1.69);
      odrive4.setPosition(0.69);
      for(int i=0;i<5;i++){
        moveToPositionGradually213(1.86, -0.55, 1.9, 0.81, 15); //up
        moveToPositionGradually213(1.9, 0.81, 0.88, 0.58, 15); //front
        moveToPositionGradually213(0.88, 0.58, 1.86, -0.55, 15); //back
        
        moveToPositionGradually224(-1.69, 0.69, -1.63, -0.72, 15); //up
        moveToPositionGradually224(-1.63, -0.72, -0.71, -0.55, 15); //front
        moveToPositionGradually224(-0.71, -0.55, -1.69, 0.69, 15); //back
      }
    }
    }
  // printpos4();

}

// void printpos4(){
//   ODriveFeedback feedback1 = odrive1.getFeedback();
//   Serial.print("inner pos1:");
//   Serial.print(feedback1.pos);
//   Serial.print(", ");
//   Serial.print("vel1:");
//   Serial.print(feedback1.vel);
//   Serial.println();

//   ODriveFeedback feedback2 = odrive2.getFeedback();
//   Serial.print("inner pos2:");
//   Serial.print(feedback2.pos);
//   Serial.print(", ");
//   Serial.print("vel2:");
//   Serial.print(feedback2.vel);
//   Serial.println();

//   ODriveFeedback feedback3 = odrive3.getFeedback();
//   Serial.print("outer pos3:");
//   Serial.print(feedback3.pos);
//   Serial.print(", ");
//   Serial.print("vel3:");
//   Serial.print(feedback3.vel);
//   Serial.println();

//   ODriveFeedback feedback4 = odrive4.getFeedback();
//   Serial.print("outer pos4:");
//   Serial.print(feedback4.pos);
//   Serial.print(", ");
//   Serial.print("vel4:");
//   Serial.print(feedback4.vel);
//   Serial.println();
//   delay(1000);
// }

void moveToPositionGradually213(float currentPosition1, float currentPosition3, float targetPosition1, float targetPosition3, int steps) {
  if (odrive1.getState() != AXIS_STATE_CLOSED_LOOP_CONTROL || odrive3.getState() != AXIS_STATE_CLOSED_LOOP_CONTROL) {
    odrive1.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
    odrive3.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
  }

  odrive1.setPosition(currentPosition1);
  odrive3.setPosition(currentPosition3);

  float stepSize1 = (targetPosition1 - currentPosition1) / steps;
  float stepSize3 = (targetPosition3 - currentPosition3) / steps;

  for (int i = 0; i < steps; i++) {
    currentPosition1 += stepSize1;
    currentPosition3 += stepSize3;
    odrive1.setPosition(currentPosition1);
    odrive3.setPosition(currentPosition3);
    delay(20);
  }
}

void moveToPositionGradually224(float currentPosition2, float currentPosition4, float targetPosition2, float targetPosition4, int steps) {
  if (odrive2.getState() != AXIS_STATE_CLOSED_LOOP_CONTROL || odrive4.getState() != AXIS_STATE_CLOSED_LOOP_CONTROL) {
    odrive2.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
    odrive4.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
  }

  odrive2.setPosition(currentPosition2);
  odrive4.setPosition(currentPosition4);

  float stepSize2 = (targetPosition2 - currentPosition2) / steps;
  float stepSize4 = (targetPosition4 - currentPosition4) / steps;

  for (int i = 0; i < steps; i++) {
    currentPosition2 += stepSize2;
    currentPosition4 += stepSize4;
    odrive2.setPosition(currentPosition2);
    odrive4.setPosition(currentPosition4);
    delay(20);
  }
}

void moveToPositionGradually4(float currentPosition1, float currentPosition3, float currentPosition2, float currentPosition4,float targetPosition1, float targetPosition3, float targetPosition2, float targetPosition4, int steps) {
  if (odrive1.getState() != AXIS_STATE_CLOSED_LOOP_CONTROL || odrive2.getState() != AXIS_STATE_CLOSED_LOOP_CONTROL || odrive3.getState() != AXIS_STATE_CLOSED_LOOP_CONTROL || odrive4.getState() != AXIS_STATE_CLOSED_LOOP_CONTROL) {
    odrive1.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
    odrive2.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
    odrive3.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
    odrive4.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
  }
      odrive1.setPosition(currentPosition1);
      odrive2.setPosition(currentPosition2);
      odrive3.setPosition(currentPosition3);
      odrive4.setPosition(currentPosition4);

  float stepSize1 = (targetPosition1 - currentPosition1) / steps;
  float stepSize2 = (targetPosition2 - currentPosition2) / steps;
  float stepSize3 = (targetPosition3 - currentPosition3) / steps;
  float stepSize4 = (targetPosition4 - currentPosition4) / steps;

  for (int i = 0; i < steps; i++) {
    currentPosition1 += stepSize1;
    currentPosition2 += stepSize2;
    currentPosition3 += stepSize3;
    currentPosition4 += stepSize4;
    odrive1.setPosition(currentPosition1);
    odrive2.setPosition(currentPosition2);
    odrive3.setPosition(currentPosition3);
    odrive4.setPosition(currentPosition4);
    delay(20);
  }
}


