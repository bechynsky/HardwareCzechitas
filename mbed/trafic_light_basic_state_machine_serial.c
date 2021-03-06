#include "mbed.h"

#define RED 			0
#define REDORANGE	1
#define GREEN 		2
#define ORANGE		3

// Serial port
Serial pc(USBTX, USBRX);

DigitalOut _red(PB_4);
DigitalOut _orange(PB_5);
DigitalOut _green(PB_3);

// we need to save every byte at memory
unsigned char newState(unsigned char currentState) {
	switch(currentState) {
		case RED:
			return REDORANGE;
		case REDORANGE:
			return GREEN;
		case GREEN:
			return ORANGE;
		case ORANGE:
			return RED;
		default:
			return RED;
	}
}

void updateLight(unsigned char state) {
	switch (state) {
		case RED:
			_red = 1;
			_orange = 0;
			_green = 0;			
			break;
		case REDORANGE:
			_red = 1;
			_orange = 1;
			_green = 0;
			break;
		case GREEN:
			_red = 0;
			_orange = 0;
			_green = 1;
			break;
		case ORANGE:
			_red = 0;
			_orange = 1;
			_green = 0;
			break;
	}
}

int main() {
	unsigned char state = RED;
	updateLight(state);
	state = newState(state);
	
	while(1) {
		if (pc.readable()) {
			// we are sending characters, 0 is 48 at ASCII table
			state = pc.getc() - 48;

			updateLight(state);			
		}
	}
}
