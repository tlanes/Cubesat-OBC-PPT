//MASTER
//Last edited 10/21/17
//Ty and friends
#include <Wire.h>
#include <avr/wdt.h>

const byte MY_ADDRESS = 25;
const byte SLAVE_ADDRESS = 42;
const byte LED = 13;

void setup () 
  {
  Serial.begin(9600);
  Wire.begin (MY_ADDRESS);
  pinMode (LED, OUTPUT);   
  Wire.onReceive(receiveEvent);  
  //wdt_disable(); 
  //wdt_enable(WDT0_4S); //watchdog enabled at 4s
  }  // end of setup

void loop () 
  {
    
  wdt_reset(); //watchdog reset
  
  while (Serial.available()){
   byte x = Serial.read();
   Wire.beginTransmission(SLAVE_ADDRESS);
   Wire.write(x); 
   if (Wire.endTransmission () == 0)
    Serial.println("tx success");
   else
    Serial.println("tx fail");
   Wire.requestFrom(SLAVE_ADDRESS, 1);
   int bytes = Wire.available();
   Serial.print("Slave sent ");
   Serial.print(bytes);
   Serial.print(" of information\n");
   for(int i = 0; i< bytes; i++)
   {
    x = Wire.read();
    Serial.print("Slave Sent: ");
    Serial.print(x, HEX);
    Serial.print("\n");
  }
  }
  delay(500);
  }  // end of loop


void receiveEvent (int howMany)
 {
  for (int i = 0; i < howMany; i++)
    {
    byte b = Wire.read ();
    Serial.println (b); 
    }  // end of for loop
} // end of receiveEvent

