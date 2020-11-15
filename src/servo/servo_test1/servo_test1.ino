

//https://www.filipeflop.com/blog/micro-servo-motor-9g-sg90-com-arduino-uno/

#include <Servo.h>

#define SERVO 6 // Digital port 6 PWM

Servo s; // variable servo
int pos; // position servo

#define PIN_LED 4


void setup() {
  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0); // engine in zero position

//  pinMode(PIN_LED, OUTPUT);
}

void loop() {
//  digitalWrite(PIN_LED, HIGH);
//  delay(500);
//  digitalWrite(PIN_LED, LOW);
//  delay(500);
  
//  for (pos = 0; pos < 90; pos++) {
//    s.write(pos);
//    delay(15);
//  }
//  delay(1000);
//  for (pos = 90; pos >= 0; pos--) {
//    s.write(pos);
//    delay(15);
//  }

}
