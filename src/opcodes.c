#include "../includes/opcodes.h"

uint8_t tell_overflow(uint16_t a, uint16_t b, uint8_t cin, uint8_t bit){
    uint32_t carry = cin;
    for(int i=1; i<bit; i++){
        carry |= ((BIT(a,i-1) + BIT(b,i-1) + BIT(carry, i-1)) & 0b1) << i;
    }
    return (BIT(carry, bit) ^ BIT(carry, bit-1));
}

uint8_t no_prefix_opcodes(uint8_t opcode, uint16_t imm16, uint8_t imm8){
    switch (opcode)
    {
    case (0x01):
        registers.BC_reg.BC = imm16;
        return 12;
    case (0x11):
        registers.DE_reg.DE = imm16;
        return 12;
    case (0x21):
        registers.HL_reg.HL = imm16;
        return 12;
    case (0x31):
        registers.SP = imm16;
        return 12;
    case (0x02):
        write_memory(registers.BC_reg.BC, registers.AF_reg.sub.A);
        return 12;
    case (0x12):
        write_memory(registers.DE_reg.DE, registers.AF_reg.sub.A);
        return 12;
    case (0x22):
        write_memory(registers.HL_reg.HL++, registers.AF_reg.sub.A);
        return 12;
    case (0x32):
        write_memory(registers.HL_reg.HL--, registers.AF_reg.sub.A);
        return 12;
    case (0x0A):
        registers.AF_reg.sub.A = read_memory(registers.BC_reg.BC);
        return 8;
    case (0x1A):
        registers.AF_reg.sub.A = read_memory(registers.DE_reg.DE);
        return 8;
    case (0x2A):
        registers.AF_reg.sub.A = read_memory(registers.HL_reg.HL++);
        return 8;
    case (0x3A):
        registers.AF_reg.sub.A = read_memory(registers.HL_reg.HL--);
        return 8;
    case (0x08):
        write_memory(imm16, registers.SP);
        return 20;
    default:
        printf("BAD OPCODE");
        return -1;
    }
}

int main(void){
    uint16_t x = 0xFFFF;
    uint16_t y = 0x0000;
    uint8_t overflow = tell_overflow(x,y, 0, 15);
    printf("OVERFLOW (0x%x + 0x%x): %d\n", x, y, overflow);
}