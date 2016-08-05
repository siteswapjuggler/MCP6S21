// MCP6S21 library for Arduino
// initial release by Sylvain GARNAVAULT - 2015/01/27

#include "MCP6S21.h"
#include "Arduino.h"
#include "SPI.h"

////////////////////////
//     INITIATION     //
////////////////////////

MCP6S21::MCP6S21(byte pin) {
	_cs = pin;                              // choose the chip select pin
	pinMode(_cs,OUTPUT);                    // set the pin as output
    digitalWrite(_cs,HIGH);                 // set the pin to default HIGH state
    SPI.begin();                            // initiate SPI
    }

/////////////////////////
//  PUBLIC  METHODS    //
/////////////////////////


void MCP6S21::gain(byte value) {
	digitalWrite(_cs,LOW);              // select CHIP
	SPI.transfer(GAIN);                 // send GAIN command
	SPI.transfer(value);                // transfer data
	digitalWrite(_cs,HIGH);             // end transmission
	}

void MCP6S21::channel(byte value) {
	digitalWrite(_cs,LOW);              // select chip
	SPI.transfer(CHANNEL);              // send CHANNEL command
    SPI.transfer(value);                // send address
    digitalWrite(_cs,HIGH);             // end transmission
	}

void MCP6S21::sleep() {
	digitalWrite(_cs,LOW);              // select chip
	SPI.transfer(SLEEP);                // send SLEEP command
    SPI.transfer(0x00);                 // complete 16bit command
	digitalWrite(_cs,HIGH);             // release chip, signal end transfer
	}
