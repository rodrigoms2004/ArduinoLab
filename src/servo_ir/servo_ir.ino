#include <IRremote.h>
#include <Servo.h>
int IRpin = 11;  // pin for the IR sensor
IRrecv irrecv(IRpin);
decode_results results;
Servo myservo;
void setup()
{
 Serial.begin(9600);
 irrecv.enableIRIn(); // Start the receiver
 myservo.attach(6);  // attaches the servo on pin 9 to the servo object
 myservo.write(0);
}
void loop() 
{
  if (irrecv.decode(&results)) 
  {  
//    Serial.println(results.value);
    if (results.value == 16769055)  // change according to your IR remote button number
    {
        delay(15);
        myservo.write(0);
        Serial.println("0");
    }
    if (results.value == 16754775)  // change according  to your IR remote button number
    {
      delay(15);
      myservo.write(30);
      Serial.println("+30");
    }  
    irrecv.resume();   // Receive the next value
  }
}   
