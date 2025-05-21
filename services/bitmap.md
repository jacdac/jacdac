# Bitmap

    identifier: 0x148451d0
    tags: C
    group: display
    status: experimental

A color bitmap.

## Registers

    const rows: u16 # @ 0x180

Gets the number of rows.

    const columns: u16 # @ 0x181

Gets the number of columns.

## Commands

### Fill

    command fill @ 0x80 {
        color: u8
    }

### Draw line

### Draw/fill circle

### Draw/fill rectangle
