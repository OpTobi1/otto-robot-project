#include <Servo.h>
#include "LedControl.h"
#include <SoftwareSerial.h>

// --- Distance Sensor ---
#define Trig 13
#define Echo 12

// --- Matrix LED ---
#define DIn 4
#define CS 3
#define CLk 2
#define N 1 // number of Max7219
LedControl lc = LedControl(DIn, CLk, CS, N);

byte big_smile[8] = {0xC3, 0xBD, 0x81, 0x81, 0x81, 0x81, 0x42, 0x3C};
byte small_smile[8] = {0x00, 0xC3, 0xBD, 0x81, 0x81, 0x42, 0x3C, 0x00};

// --- Buzzer ---
#define buzzer 7

// --- Servo Motors ---
Servo myservo1; // Fixed: Added missing semicolon
Servo myservo2; 
Servo myservo3; 
Servo myservo4; 

// --- Bluetooth Connection ---
#define TxPin 5
#define RxPin 6
SoftwareSerial Bluetooth(RxPin, TxPin);

void setup() {
  // 1. Setup Distance Sensor
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT_PULLUP);

  // 2. Setup Matrix LED
  lc.shutdown(0, false); // wakeup MAX72XX
  lc.setIntensity(0, 1); // Set the brightness 0 .. 15
  lc.clearDisplay(0);    // clear the display

  // 3. Setup Buzzer
  pinMode(buzzer, OUTPUT);

  // 4. Setup Servo Motors
  myservo1.attach(8);
  myservo2.attach(9);
  myservo3.attach(10);
  myservo4.attach(11);
  
  // Set initial position for servos
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(90);
  myservo4.write(90);

  // 5. Setup Bluetooth
  Bluetooth.begin(9600);
}

// ==========================================
//             HELPER FUNCTIONS
// ==========================================

long distance() {
  long duration, cm;
  digitalWrite(Trig, LOW); // Trig a LOW pulse beforehand a clean HIGH
  delayMicroseconds(5);
  digitalWrite(Trig, HIGH); // The sensor is triggered by a HIGH pulse
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  duration = pulseIn(Echo, HIGH); // duration is the time (in microseconds)
  cm = duration / 58.2; // s = v * t = 0.017 * t = 1/58 * t
  return cm;
}

void buzzing(int freq) {
  tone(buzzer, freq);
  delay(250);
  noTone(buzzer);
}

// Function that was missing in the original code, added to make the LEDs work
void writeMatrixLed(byte image[8]) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, image[i]);
  }
}

// ==========================================
//               MAIN LOOP
// ==========================================

void loop() {
  long currentDistance = distance();

  // Distance check and collision avoidance
  if (currentDistance > 0 && currentDistance < 20) {
    buzzing(261); // Play warning sound
    writeMatrixLed(small_smile); // Change face when a wall is detected
    delay(500);
  } else {
    writeMatrixLed(big_smile); // Normal face
  }

  // Receive Bluetooth commands
  if (Bluetooth.available() > 0) {
    char tav = Bluetooth.read();
    
    // If the letter 'a' is received, the robot will perform an action
    if (tav == 'a') {
      buzzing(329); // Confirmation sound
      
      // Example servo movement
      for (int k = 90; k < 120; k++) {
        myservo1.write(k);
        myservo2.write(k);
        delay(25);
      }
      
      // Return to initial position
      myservo1.write(90);
      myservo2.write(90);
    }
  }
}