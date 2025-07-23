# Character Screen

    identifier: 0x195ee163
    group: display
    status: stable

A screen that displays characters, typically a LCD/OLED character screen.

## Registers

    rw message: string @ value

Text to show.

    rw enabled?: u0.16 / @ intensity

Enable or disable the screen.

    enum Variant : u8 {
        LCD = 1,
        OLED = 2,
        Braille = 3,
    }
    const variant?: Variant @ variant

Describes the type of character LED screen.

    enum TextDirection : u8 {
        LeftToRight = 1,
        RightToLeft = 2
    }
    rw text_direction?: TextDirection @ 0x82

Specifies the RTL or LTR direction of the text.

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
