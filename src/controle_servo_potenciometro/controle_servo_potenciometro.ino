#include <Servo.h>

#define SERVO 6 // digital port 5 PWM
const int pinPOT = A5;
float angle = 0;
int currentAngle = 0;
Servo s;  // servo object
int pos; // position
int offset1 = 14;
// offset angle = original angle + 14

void setup() {
  Serial.begin(9600);
  s.attach(SERVO);
  s.write(0 + offset1); // servo in position 0
  pinMode(pinPOT, INPUT);

}

void loop() {

  currentAngle = s.read();
  angle = map(analogRead(pinPOT), 0, 1023, offset1, 90 + offset1); // from 0 to 90, from 14 to 104

  if (currentAngle != angle) {
      Serial.print("Angle changed to ");
      Serial.print(int(angle));
      Serial.print(" - original angle ");
      Serial.println(int(angle) - offset1);
      s.write(int(angle));
  }

  delay(200);

}
