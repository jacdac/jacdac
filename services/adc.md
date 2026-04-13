# ADC

    identifier: 0x1d723135
    tags: io
    camel: ADC
    extends: _sensor
    status: experimental

Read in the analogue value of a pin, if it has been set to AnalogIn through the GPIO service. The GPIO service provides the main configuration for access to the GPIO hardware.

## Registers

    packed ro state @ reading {
    repeats:
        pin: u8
        value: u16.16 V
    }

For each pin that has been configured to `AnalogIn` in the GPIO service, the pin number and value is returned to the client. This is streamed at a low-ish speed, but it's also automatically reported whenever
an input pin changes value (throttled to ~100Hz).