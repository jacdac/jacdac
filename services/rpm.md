# Rotations Per Minute

    identifier: 0x19f8e291
    extends: _sensor
    group: movement
    status: rc

A sensor that measures RPM (rotations per minute) of a rotor.

## Registers

    ro rpm: i24.8 rpm @ reading

The RPM reading of the sensor.

    const clicks_per_turn: u8 @ 0x180
    
The amount of ticks for 1 full rotation.

    const min_rpm: i24.8 rpm @ min_reading

Lowest rpm that can be reported.

    const max_rpm: i24.8 rpm @ max_reading

Highest rpm that can be reported.
