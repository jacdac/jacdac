# Bitmap

    identifier: 0x1bb168b8
    tags: C
    group: display
    status: experimental

A color bitmap.

## Registers

    const height: u16 # @ 0x180

Gets the height of the bitmap.

    const width: u16 # @ 0x181

Gets the width of the bitmap.

## Commands

### Fill

    command fill @ 0x80 {
        color: u8
    }

### Draw line

### Draw/fill circle

### Draw/fill rectangle
