#include "mbed.h"
 
AnalogIn analog_value(A5);
 
int main() {
    float meas;
    
    printf("\nAnalogIn example\n");
    
    while(1) {
        meas = analog_value.read(); // Converts and read the analog input value (value from 0.0 to 1.0)
        meas = meas * 3300; // Change the value to be in the 0 to 3300 range
        printf("%.0f\n\r", meas * 0.1);
        
        wait(2); // 200 ms
    }
}