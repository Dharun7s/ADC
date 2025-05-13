#include "pico/stdlib.h"
#include "potentiometer.h"  // Include the potentiometer library

int main() {
    stdio_init_all();  // Initialize the standard input/output

    Potentiometer pot(26);  // Create a Potentiometer object, connected to GPIO 26 (ADC0)
    pot.init();  // Initialize the potentiometer

    while (true) {
        uint16_t raw_value = pot.read_raw();  // Read the raw ADC value
        float voltage = pot.read_voltage();   // Convert the ADC value to voltage

        // Print the raw ADC value and the corresponding voltage
        printf("ADC Raw: %u, Voltage: %.2f V\n", raw_value, voltage);

        sleep_ms(500);  // Delay for 500ms before next reading
    }

    return 0;
}
