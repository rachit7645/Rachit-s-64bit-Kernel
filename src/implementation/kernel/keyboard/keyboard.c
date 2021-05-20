#include <stdint.h>
#include <stdbool.h>
#include "keyboard/keyboardScanCodeTranslation.h"
#include "keyboard/keyboard.h"
#include "print.h"

// Define booleans for LSHIFT and RSHIFT
bool isLeftShiftPressed;
bool isRightShiftPressed;

void handle_keyboard(uint8_t scancode) {
    
    // Handle special characters like shift and control
    // The release scancode is the pressing scancode + 0x80
    switch(scancode) {
        case LeftShift:
            isLeftShiftPressed = true;
            return;
        case LeftShift + 0x80:
            isLeftShiftPressed = false;
            return;
        case RightShift:
            isRightShiftPressed = true;
            return;
        case RightShift + 0x80:
            isRightShiftPressed = false;
            return;
        case Enter:
            print_newline();
            print_terminal();
            return;
        case Spacebar:
            print_char(' ');
            return;
        case BackSpace:
            clear_char();
            return;
    }

    // Convert to ascii chars from scancodes.
    char ascii = translate(scancode, isLeftShiftPressed | isRightShiftPressed);

    if(ascii != 0) {
        print_char(ascii);
    }

}