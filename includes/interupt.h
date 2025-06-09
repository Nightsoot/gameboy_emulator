#include "memory_tools.h"
#include "registers.h"

#define CLEAR(a, bit) (a &= ~(1 << bit))

#define VBLANK_HANDLER_ADDRESS 0x40
#define LCD_HANDLER_ADDRESS 0x48
#define TIMER_HANDLER_ADDRESS 0x50
#define SERIAL_HANDLER_ADDRESS 0x58
#define JOYPAD_HANDLER_ADDRESS 0x60

enum interupt_type
{
    VBLANK = (1 << 0),
    LCD = (1 << 1),
    TIMER = (1 << 2),
    SERIAL = (1 << 3),
    JOYPAD = (1 << 4),
};

uint8_t handle_interupt();