//https://www.makerguides.com/ir-receiver-remote-arduino-tutorial/
//https://www.digikey.com/en/resources/conversion-calculators/conversion-calculator-resistor-color-code

/* Finding the key codes for your remote. More info: https://www.makerguides.com */
#include <IRremote.h> // include the IRremote library
#define RECEIVER_PIN 2 // define the IR receiver pin

IRrecv receiver(RECEIVER_PIN); // create a receiver object of the IRrecv class
decode_results results; // create a results object of the decode_results class

String str_number = "";
int number = 0;

void setup() {
  Serial.begin(9600); // begin serial communication with a baud rate of 9600
  receiver.enableIRIn(); // enable the receiver
  receiver.blink13(true); // enable blinking of the built-in LED when an IR signal is received
}

void loop() {
  if (receiver.decode(&results)) { // decode the received signal and store it in results
//    Serial.println(results.value, HEX); // print the values in the Serial Monitor
    

    switch (results.value) {
      case 16724175:
//        Serial.println("Key 1 pressed");
        str_number += "1";
        break;
      case 16718055:
//        Serial.println("Key 2 pressed");
        str_number += "2";
        break;
      case 16743045:
//        Serial.println("Key 3 pressed");
        str_number += "3";
        break;
      case 16716015:
//        Serial.println("Key 4 pressed");
        str_number += "4";
        break;
       case 16726215:
//        Serial.println("Key 5 pressed");
        str_number += "5";
        break;
      case 16734885:
//        Serial.println("Key 6 pressed");
        str_number += "6";
        break;
      case 16728765:
//        Serial.println("Key 7 pressed");
        str_number += "7";
        break;
       case 16730805:
//        Serial.println("Key 8 pressed");
        str_number += "8";
        break;
      case 16732845:
//        Serial.println("Key 9 pressed");
        str_number += "9";
        break;
      case 16738455:
//        Serial.println("Key 0 pressed");
        str_number += "0";
        break;
      case 16750695:
        Serial.println("Key 100+ pressed");
        break;
      case 16756815:
        Serial.println("Key 200+ pressed");
        break;
      case 16748655:  // ENTER
        Serial.println("Key EQ pressed");
        if (str_number.length() <=3) {
          number = str_number.toInt();
        } else {
          str_number = "";
        }
        break;
      case 16769055:
        Serial.println("Key VOL- pressed");
        break;
      case 16754775:
        Serial.println("Key VOL+ pressed");
        break;
      case 16761405:
        Serial.println("Key PLAY/PAUSE pressed");
        break;
      case 16753245:
        Serial.println("Key CH- pressed");
        break;
      case 16736925: // CLEAR
//        Serial.println("Key CH pressed");
        str_number = "";
        break;
      case 16769565:
        Serial.println("Key CH+ pressed");
        break;
      case 16720605:
        Serial.println("Key PREV pressed");
        break;
      case 16712445:
        Serial.println("Key NEXT pressed");
        break;
        
//       default:
//        Serial.println("Another key");
    }
    Serial.println(str_number);

    if (number != 0) {
      Serial.println("Final number is: ");  
      Serial.println(number);
    }
    
    
    receiver.resume(); // reset the receiver for the next code
  }
}
