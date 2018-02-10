//SLAVE
#include <Wire.h>

const byte MY_ADDRESS = 42;
const byte OTHER_ADDRESS = 25;
const int ledPin = 3;
int ledState = LOW;
 
void setup () 
  {
  Serial.begin(9600);
  Wire.begin (MY_ADDRESS);
  for (byte i = 2; i <= 7; i++)
    pinMode (i, OUTPUT);
  // set up receive handler
  Wire.onReceive (receiveEvent);
  Wire.onRequest (requestEvent);
  }  // end of setup

void loop() 
  {
  Serial.println("waiting...");
  delay(200);
  }

// called by interrupt service routine when incoming data arrives
void receiveEvent (int howMany)
  {
  for (int i = 0; i < howMany; i++)
  {
    byte c = Wire.read ();
    // toggle requested LED
    Serial.println(c);

switch(c){
  case 'A':
      digitalWrite(5,HIGH);
      delay(1000);
      digitalWrite(5,LOW);
      delay(1000);
    break;
    
  case 'B':
      digitalWrite(6,HIGH);
      delay(1000);
      digitalWrite(6,LOW);
      delay(1000);
    break;
  default:
    Serial.println("Not a valid input command");
    break;
  }
  }
} // end of receiveEvent
byte x = 1;

void requestEvent ()
{
  Serial.print("Request from Master. Sending: ");
  Serial.print(x);
  Serial.print("\n");

  Wire.write(x);
  
}
