/*
 * Test FlySky IBus interface on an Arduino Mega.
 *  Connect FS-iA6B receiver to Serial1.
 */

#include <SomeSerial.h>
#include "iBUSSome.h"

#define SOFTPORT  // если определено используем SofwareSerial
#define SERIAL1   //328PB ONLY

#ifdef  SOFTPORT
SomeSerial IBusPort(2, 3); // RX, TX
iBUSSome IBusSerial(IBusPort);
#else
  #ifdef SERIAL1
  SomeSerial IBusSerial(&Serial1);
  #else
  SomeSerial IBusSerial(&Serial);
  #endif
#endif 

void setup() 
{
  Serial.begin(115200);
  IBusSerial.begin(Serial1);
}

void loop() 
{
 IBusSerial.loop();
  Serial.println(IBusSerial.readChannel(0), HEX);
}
