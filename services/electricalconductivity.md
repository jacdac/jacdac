# Electrical Conductivity

    identifier: 0x1f1f7277
    extends: _sensor
    group: environment
    status: rc

A sensor that measures electrical conductivity (EC) of a medium.

## Registers

    ro electrical_conductivity: u22.10 uS/cm @reading

The EC reading of the sensor.

    ro electrical_conductivity_error: u22.10 uS/cm @reading_error

The error on the EC reading.

    const min_electrical_conductivity: u22.10 uS/cm @min_reading
    
Lowest EC that can be reported.

    const max_electrical_conductivity: u22.10 uS/cm @ max_reading

Highest EC that can be reported.
