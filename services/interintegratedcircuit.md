# Inter-Integrated Circuit

    identifier: 0x13ca8637
    group: io
    status: rc

Tunnels Inter-Integrated Circuit (I2C) protocol packets via Jacdac packets.

## Commands

    command writei2c @ 0x83 {
        payload: bytes
    }

Sends byte array to I2C.

    command readi2c @ 0x84 { 
        payload: bytes
    }

Reads byte array from I2C.

