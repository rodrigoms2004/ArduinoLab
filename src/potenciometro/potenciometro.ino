
//https://blogmasterwalkershop.com.br/arduino/arduino-utilizando-o-potenciometro-linear/
//https://www.arduino.cc/reference/en/language/functions/math/map/

const int pinPOT = A5;

float potValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinPOT, INPUT);
}

void loop() {
  delay(100);
  potValue = map(analogRead(pinPOT), 0, 1023, 0, 180); // from 0.0 to 180.0
  Serial.println(int(potValue));

}
