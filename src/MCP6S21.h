// MCP6S21 library for Arduino
// initial release by Sylvain GARNAVAULT - 2015/01/27

#ifndef MCP6S21_h

	#define MCP6S21_h //#define MC6S21_h  problem with redefinition -> Error writing marco name MC6S21_h -> MCP6S21_h
	
	#include "Arduino.h"          // include arduino Core

    #define SLEEP   B00100000     // sleep command
    #define GAIN    B01000000     // write gain register
	#define CHANNEL B01000001     // write channel register

	#define x1     B000           // x1  gain
	#define x2     B001           // x2  gain
	#define x4     B010           // x4  gain
    #define x5     B011           // x5  gain
    #define x8     B100           // x8  gain
    #define x10    B101           // x10 gain
    #define x16    B110           // x16 gain
    #define x32    B111           // x32 gain

	class MCP6S21 {
		public:
			MCP6S21(byte pin);         // initiate object
			void gain(byte value);     // change gain
			void channel(byte value);  // change channel
            void sleep();              // sleep mode
        
		private:
            byte _cs;                  // chip select pin
	};
	
#endif // MCP6S21_h
