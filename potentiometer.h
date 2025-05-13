#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include "hardware/adc.h"

// Potentiometer class definition
class Potentiometer {
public:
    // Constructor, takes the GPIO pin number for ADC
    Potentiometer(uint pin);
    
    // Method to initialize the ADC pin
    void init();
    
    // Method to read the ADC value
    uint16_t read_raw();
    
    // Method to get the corresponding voltage (float)
    float read_voltage();

private:
    uint pin; // GPIO pin for the potentiometer
};

#endif // POTENTIOMETER_H
