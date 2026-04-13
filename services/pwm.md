# PWM

    identifier: 0x1aada0c2
    tags: io
    camel: PWM

Set the PWM output for a pin. The pins are indexed `0 ... num_pins-1`.The indexing does not correspond to hardware pin names, nor labels on the board (see `get_pin_info` command for that), and should **not** be exposed to the user.

This service does not rely on the GPIO service, enabling a pin will set that pin in the GPIO service to `Alternate` mode.

## Registers

    ro num_pins: u8 # { absolute_max=128 } @ 0x180

Return the number of pins supporting PWM.

    ro frequencies @ 0x181 {
    repeats: 
        frequency: u32 Hz 
    } 

Return the supported frequencies for use by the pins.

    ro concurrent_pwm: u8 # @ 0x182

Return the number of pins that can have PWM enabled simultaneously, 0 for no limit. 

## Commands

    enum Mode: u8 {
        PWMDisabled = 0
        PWMEnabled = 1
    }

    command SetMode @ 0x80 {
        pin: u8
        mode: Mode
    }

Set the enabled state of PWM on a specific pin by its number. If the maximum number of concurrent PWM pins is exceeded, the command will fail.

    packed command SetDutyCycle @ 0x81 {
        pin: u8
        duty_cycle: u0.16 /100
    }

Set the duty cycle for a specific pin.

    packed command SetFrequency @ 0x82 {
        pin: u8
        frequency: u32 Hz
    }

Set the frequency for a specific pin. If the frequency is not supported, the closest supported frequency will be used instead.

    command pin_info @ 0x83 {
        pin: u8
    } 
    packed report {
        pin: u8
        hw_pin: u8
        mode: Mode
        duty_cycle: u0.16 /100
        frequency: u32 Hz
        label: string
    }

Get the info about a specific pin by its number.

    command pin_by_label @ 0x84 {
        label: string
    } 
    packed report {
        pin: u8
        hw_pin: u8
        mode: Mode
        duty_cycle: u0.16 /100
        frequency: u32 Hz
        label: string
    }

Get the info about a specific pin by its label.

    command pin_by_hw_pin @ 0x85 {
        hw_pin: u8
    } 
    packed report {
        pin: u8
        hw_pin: u8
        mode: Mode
        duty_cycle: u0.16 /100
        frequency: u32 Hz
        label: string
    }

Get the info about a specific pin by its hardware pin number.