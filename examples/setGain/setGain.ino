/*
  * CS - to digital pin 10  (SS pin)
  * SDI - to digital pin 11 (MOSI pin)
  * CLK - to digital pin 13 (SCK pin) 
*/


#include <SPI.h>
#include <MCP6S21.h>

MCP6S21 PGA(10);

void setup() {
  Serial.begin(115200);
  PGA.gain(x1);  
}

void loop() {
  Serial.println(analogRead(A0));
  delay(1000);
}
