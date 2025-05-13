cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(potentiometer_adc_lib C CXX)  # C++ enabled
pico_sdk_init()

# Add the library and source files
add_library(potentiometer STATIC
    potentiometer.cpp  # Include the potentiometer source file
)

# Add your main executable
add_executable(main
    main.cpp
)

# Link the library to your executable
target_link_libraries(main
    potentiometer
    pico_stdlib
    hardware_adc
)

# Enable USB output, if necessary
pico_add_extra_outputs(main)
