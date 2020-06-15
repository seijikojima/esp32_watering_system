#include <ESP32Servo.h>

Servo servo; // create four servo objects 
int servo1Pin = 4;
int val = 0;
int pos = 0;
int max_dig = 120;
unsigned long timerDelay = 1000 * 60 ; // 1 minute

void servo_on() {
  
  for (pos = 0; pos <= max_dig; pos += 1) { // sweep from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);
    delay(50);             // waits 20ms for the servo to reach the position
  }
  for (pos = max_dig; pos >= 0; pos -= 1) { // sweep from 180 degrees to 0 degrees
    servo.write(pos);
    delay(20);
  }
}


void setup() {
    
    // servo定義
    servo.setPeriodHertz(50);      // Standard 50hz servo
    servo.attach(servo1Pin, 500, 2400); // min=500, max=2400 何かの調整
   
    Serial.println("Servo start!");
}

void loop(void) {

  if ((millis() - lastTime) > timerDelay) {
    servo_on();
    lastTime = millis();
  }
  
}
