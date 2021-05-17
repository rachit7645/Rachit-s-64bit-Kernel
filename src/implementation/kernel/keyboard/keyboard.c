#include <stdint.h>
#include <stdbool.h>
#include "keyboard/keyboardScanCodeTranslation.h"
#include "keyboard/keyboard.h"
#include "print.h"

bool isLeftShiftPressed;
bool isRightShiftPressed;

void handle_keyboard(uint8_t scancode) {
   
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

    char ascii = translate(scancode, isLeftShiftPressed | isRightShiftPressed);

    if(ascii != 0) {
        print_char(ascii);
    }

}