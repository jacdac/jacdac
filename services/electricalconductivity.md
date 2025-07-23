# Electrical Conductivity

    identifier: 0x1e9778c5
    extends: _sensor
    group: environment
    status: rc

A sensor that measures electrical conductivity (EC) of a medium.

## Registers

    ro electrical_conductivity: u22.10 S/m @reading

The EC reading of the sensor.

    ro electrical_conductivity_error: u22.10 S/m @reading_error

The error on the EC reading.

    const min_electrical_conductivity: u22.10 S/m @min_reading
    
Lowest EC that can be reported.

    const max_electrical_conductivity: u22.10 S/m @ max_reading

Highest EC that can be reported.
