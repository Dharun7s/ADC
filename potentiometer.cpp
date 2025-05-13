#include "potentiometer.h"
#include "hardware/adc.h"

Potentiometer::Potentiometer(uint pin) : pin(pin) {}

void Potentiometer::init() {
    adc_init();  // Initialize ADC system
    adc_gpio_init(pin);  // Initialize the GPIO pin for ADC
    adc_select_input(pin - 26);  // Select the appropriate ADC input
}

uint16_t Potentiometer::read_raw() {
    return adc_read();  // Read and return the 12-bit raw ADC value
}

float Potentiometer::read_voltage() {
    uint16_t raw_value = read_raw();  // Get the raw ADC value
    return (float)raw_value * 3.3f / (1 << 12);  // Convert raw value to voltage
}
