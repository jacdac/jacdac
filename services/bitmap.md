# Bitmap

    identifier: 0xdeadbeef
    tags: C
    group: display
    status: experimental

A color bitmap.

## Dimensions

    const rows: u16 # @ 0x180

Gets the number of rows.

    const columns: u16 # @ 0x181

Gets the number of columns.

## Basic drawing commands

### Fill

command fill @ 0x81 {
    color: u8
}

### Draw line

### Draw/fill circle

### Draw/fill rectangle
