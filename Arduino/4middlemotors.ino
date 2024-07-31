#include <ODriveUART.h>
#include <SoftwareSerial.h>
#include <HardwareSerial.h>


SoftwareSerial serial4(A8, 28);

unsigned long baudrate = 19200; // Must match what you configure on the ODrive

ODriveUART odrive1(Serial1);
ODriveUART odrive2(Serial2);
ODriveUART odrive3(Serial3);
ODriveUART odrive4(serial4);

void setup() {
  Serial.begin(9600);
  delay(1000); // Wait for serial port to connect. Needed for native USB
  // Serial.println("Serial started");

  Serial1.begin(baudrate); // Serial to ODrive 1
  Serial2.begin(baudrate); // Serial to ODrive 2
  Serial3.begin(baudrate); // Serial to ODrive 3
  serial4.begin(baudrate); // Serial to ODrive 4

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

  odrive1.clearErrors();
  odrive2.clearErrors();
  odrive3.clearErrors();
  odrive4.clearErrors();

  delay(1000);
  odrive1.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
  odrive2.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
  odrive3.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
  odrive4.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
  odrive1.setPosition(-1.03);
  delay(1000);
  odrive2.setPosition(1.0);
  delay(1000);
  odrive3.setPosition(-1.18);
  delay(1000);
  odrive4.setPosition(1.05);
}

void loop() {
 if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim(); // Remove any leading/trailing whitespace

    if (command == "d") {
      Serial.println("clearing errors");
      odrive1.clearErrors();
      odrive2.clearErrors();
      odrive3.clearErrors();
      odrive4.clearErrors();
      odrive1.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
      odrive2.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
      odrive3.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
      odrive4.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
      odrive1.setPosition(-1.03);
      delay(1000);
      odrive2.setPosition(1.0);
      delay(1000);
      odrive3.setPosition(-1.18);
      delay(1000);
      odrive4.setPosition(1.05);
    }
 }
//   ODriveFeedback feedback1 = odrive1.getFeedback();
//   Serial.print("pos1:");
//   Serial.print(feedback1.pos);
//   Serial.print(", ");
//   Serial.print("vel1:");
//   Serial.print(feedback1.vel);
//   Serial.println();

//   ODriveFeedback feedback2 = odrive2.getFeedback();
//   Serial.print("pos2:");
//   Serial.print(feedback2.pos);
//   Serial.print(", ");
//   Serial.print("vel2:");
//   Serial.print(feedback2.vel);
//   Serial.println();

//   ODriveFeedback feedback3 = odrive3.getFeedback();
//   Serial.print("pos3:");
//   Serial.print(feedback3.pos);
//   Serial.print(", ");
//   Serial.print("vel3:");
//   Serial.print(feedback3.vel);
//   Serial.println();

//   ODriveFeedback feedback4 = odrive4.getFeedback();
//   Serial.print("pos4:");
//   Serial.print(feedback4.pos);
//   Serial.print(", ");
//   Serial.print("vel4:");
//   Serial.print(feedback4.vel);
//   Serial.println();
//   delay(3000);
}