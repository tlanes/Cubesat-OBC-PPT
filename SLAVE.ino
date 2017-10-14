//SLAVE
#include <Wire.h>

const byte MY_ADDRESS = 42;
const byte OTHER_ADDRESS = 25;
const int ledPin = 3;
int ledState = LOW;
unsigned long previousMillis = 0;
unsigned long interval = 100;
 
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
    for (int i = 0; i < 10000; i++)
    {
      digitalWrite(2,HIGH);
      delayMicroseconds(5);
      digitalWrite(2,LOW);
      delayMicroseconds(5);
      
    }
    break;
  case 'B':
    for (int i = 0; i < 10; i++)
    {
      digitalWrite(3,HIGH);
      delay(500);
      digitalWrite(3,LOW);
      delay(500);
    }
    break;
  case 'C':
    for (int i = 0; i < 10; i++)
    {
      digitalWrite(4,HIGH);
      delay(600);
      digitalWrite(4,LOW);
      delay(600);
    }
    break;
  default:
    Serial.println("Not a valid input command");
    break;
  }
  }
} // end of receiveEvent
byte x = 0x00;

void requestEvent ()
{
  Serial.print("Request from Master. Sending: ");
  Serial.print(x, HEX);
  Serial.print("\n");

  Wire.write(x);
  
}

