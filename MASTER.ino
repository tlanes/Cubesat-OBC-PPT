//MASTER
#include <Wire.h>

const byte MY_ADDRESS = 25;
const byte SLAVE_ADDRESS = 42;
const byte LED = 13;

void setup () 
  {
  Serial.begin(9600);
  Wire.begin ();
  pinMode (LED, OUTPUT);   
  Wire.onReceive(receiveEvent);  
  }  // end of setup

void loop () 
  {
  while (Serial.available()){
   byte x = Serial.read();
   Wire.beginTransmission(SLAVE_ADDRESS);
   Wire.write(x); 
   if (Wire.endTransmission () == 0)
    Serial.println("tx success");
   else
    Serial.println("tx fail");
    delay(500);
  }
    
//  for (byte x = 2; x <= 7; x++)
//    {  
//    Wire.beginTransmission (SLAVE_ADDRESS);
//    Wire.write (x);
//    if (Wire.endTransmission () == 0)
//      digitalWrite (LED, HIGH); 
//    else
//      digitalWrite (LED, LOW); 
//      
//    delay (200);
//    }  // end of for loop
  }  // end of loop


void receiveEvent (int howMany)
 {
  for (int i = 0; i < howMany; i++)
    {
    byte b = Wire.read ();
    Serial.println (b); 
    }  // end of for loop
} // end of receiveEvent
