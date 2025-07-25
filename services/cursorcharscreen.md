# Cursor Character Screen

    identifier: 0x195ee163
    group: display
    status: rc

A screen that displays characters, typically a LCD/OLED character screen.

## Registers

    rw enabled: boolean 

Enable or disable the screen.

    const rows: u8 # @ 0x180

Gets the number of rows.

    const columns: u8 # @ 0x181

Gets the number of columns.

## Commands

    command home @ 0x83 { }

Returns the cursor to the upper-left corner.

    command clear @ 0x84 { }

Clears the display.

    command setCursor @ 0x85 { 
        x: u8
        y: u8
    }

Sets the x / y position of cursor in the character grid.

    command show @ 0x86 {
        message: string
    }

Shows a message at the current cursor position.