#include "../includes/interupt.h"

uint8_t handle_interupt()
{
    push16(registers.PC);
    uint8_t flags = get_IF();
    if (flags & (0b1 << 0) == VBLANK)
    {
        printf("VBLANK INTERUPT\n");
        IME = 0;
        CLEAR(flags, 0);
        registers.PC = 0x40;
        return 5;
    }
    else if (flags & (0b1 << 1) == LCD)
    {
        printf("LCD INTERUPT\n");
        IME = 0;
        CLEAR(flags, 1);
        registers.PC = 0x48;
        return 5;
    }
    else if (flags & (0b1 << 2) == TIMER)
    {
        printf("TIMER INTERUPT\n");
        IME = 0;
        CLEAR(flags, 2);
        registers.PC = 0x50;
        return 5;
    }
    else if (flags & (0b1 << 3) == SERIAL)
    {
        printf("SERIAL INTERUPT\n");
        IME = 0;
        CLEAR(flags, 3);
        registers.PC = 0x58;
        return 5;
    }
    else if (flags & (0b1 << 4) == JOYPAD)
    {
        printf("JOYPAD INTERUPT\n");
        IME = 0;
        CLEAR(flags, 4);
        registers.PC = 0x60;
        return 5;
    }

   return 0;
}