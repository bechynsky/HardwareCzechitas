#include "mbed.h"

DigitalOut _red(PB_4); // Arduino D5
DigitalOut _orange(PB_5); // Arduino D4
DigitalOut _green(PB_3); // Arduino D3

int main() {
	while(1) {
		_red = 1;
		_orange = 0;
		_green = 0;
		wait(3);
		
		_red = 1;
		_orange = 1;
		_green = 0;
		wait(1);
		
		_red = 0;
		_orange = 0;
		_green = 1;
		wait(3);
		
		_red = 0;
		_orange = 1;
		_green = 0;
		wait(1);
	}
}
