#include "mbed.h"

#define RED 		0
#define REDORANGE	1
#define GREEN 		2
#define ORANGE		3

#define GREEN_RED_WAIT	3
#define ORANGE_WAIT		1

DigitalOut _red(PB_4);  // Arduino D5
DigitalOut _orange(PB_5);  // Arduino D4
DigitalOut _green(PB_3);  // Arduino D3

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
			wait(GREEN_RED_WAIT);
			break;
		case REDORANGE:
			_red = 1;
			_orange = 1;
			_green = 0;
			wait(ORANGE_WAIT);
			break;
		case GREEN:
			_red = 0;
			_orange = 0;
			_green = 1;
			wait(GREEN_RED_WAIT);
			break;
		case ORANGE:
			_red = 0;
			_orange = 1;
			_green = 0;
			wait(ORANGE_WAIT);
			break;
	}
}

int main() {
	unsigned char state = 0;
	
	
	while(1) {
		updateLight(state);
		state = newState(state);
	}
}
