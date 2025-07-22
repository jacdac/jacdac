# LCD Character Display

    identifier: 0x1f37c56a
    group: display
    status: experimental

An LCD screen that displays character strings.

## Registers

    rw enabled: u8 @ intensity

Determines if the character display is active.

    rw message: string @ value
    
Characters to show.

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



