#include "../includes/opcodes.h"

//tell overflow at a given bit
uint8_t tell_overflow(uint16_t a, uint16_t b, uint8_t cin, uint8_t bit){
    uint32_t carry = cin;
    for(int i=1; i<=bit+1; i++){
        carry |= ((BIT(a, i - 1) + BIT(b, i - 1) + BIT(carry, i - 1)) & 0b10) << (i-1);
    }
    return (BIT(carry, bit) ^ BIT(carry, bit+1));
}

uint8_t tell_borrow(uint16_t a, uint16_t b, uint8_t bit){
    uint16_t borrow = BIT(b, 15) > BIT(a, 15);
    for(int i=14; i>=bit; i--){
        borrow |= (BIT(b, i) > (BIT(a, i), BIT(borrow, i+1))) << i;
    }
    return BIT(borrow, bit);
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
    case (0x09):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.HL_reg.HL, registers.BC_reg.BC, 0, 15);
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.HL_reg.HL, registers.BC_reg.BC, 0, 11);
        registers.HL_reg.HL = registers.HL_reg.HL + registers.BC_reg.BC;
        return 8;
    case (0x19):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.HL_reg.HL, registers.DE_reg.DE, 0, 15);
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.HL_reg.HL, registers.DE_reg.DE, 0, 11);
        registers.HL_reg.HL = registers.HL_reg.HL + registers.DE_reg.DE;
        return 8;
    case (0x29):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.HL_reg.HL, registers.HL_reg.HL, 0, 15);
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.HL_reg.HL, registers.HL_reg.HL, 0, 11);
        registers.HL_reg.HL = registers.HL_reg.HL + registers.HL_reg.HL;
        return 8;
    case (0x39):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.HL_reg.HL, registers.SP, 0, 15);
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.HL_reg.HL, registers.SP, 0, 11);
        registers.HL_reg.HL = registers.HL_reg.HL + registers.SP;
        return 8;
    case (0x03):
        registers.BC_reg.BC++;
        return 8;
    case (0x13):
        registers.DE_reg.DE++;
        return 8;
    case (0x23):
        registers.HL_reg.HL++;
        return 8;
    case (0x33):
        registers.SP++;
        return 8;
    case (0x04):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.BC_reg.sub.B, registers.BC_reg.sub.B, 0, 3);
        registers.BC_reg.sub.B++;
        registers.AF_reg.sub.F_reg.flags.z = (registers.BC_reg.sub.B == 0);
        return 4;
    case (0x0C):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.BC_reg.sub.C, registers.BC_reg.sub.C, 0, 3);
        registers.BC_reg.sub.C++;
        registers.AF_reg.sub.F_reg.flags.z = (registers.BC_reg.sub.C == 0);
        return 4;
    case (0x14):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.DE_reg.sub.D, registers.DE_reg.sub.D, 0, 3);
        registers.DE_reg.sub.D++;
        registers.AF_reg.sub.F_reg.flags.z = (registers.DE_reg.sub.D == 0);
        return 4;
    case (0x1C):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.DE_reg.sub.E, registers.DE_reg.sub.E, 0, 3);
        registers.DE_reg.sub.E++;
        registers.AF_reg.sub.F_reg.flags.z = (registers.DE_reg.sub.E == 0);
        return 4;
    case (0x24):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.HL_reg.sub.H, registers.HL_reg.sub.H, 0, 3);
        registers.HL_reg.sub.H++;
        registers.AF_reg.sub.F_reg.flags.z = (registers.HL_reg.sub.H == 0);
        return 4;
    case (0x2C):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.HL_reg.sub.L, registers.HL_reg.sub.L, 0, 3);
        registers.HL_reg.sub.L++;
        registers.AF_reg.sub.F_reg.flags.z = (registers.HL_reg.sub.L == 0);
        return 4;
    case (0x34):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(read_memory(registers.HL_reg.HL), read_memory(registers.HL_reg.HL), 0, 3);
        write_memory(registers.HL_reg.HL, read_memory(registers.HL_reg.HL) + 1);
        registers.AF_reg.sub.F_reg.flags.z = (read_memory(registers.HL_reg.HL) == 0);
        return 12;
    case (0x3C):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.AF_reg.sub.A, 0, 3);
        registers.AF_reg.sub.A++;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    default:
        printf("BAD OPCODE");
        return -1;
    }
}

int main(void){
    uint16_t x = 0xEFFF;
    uint16_t y = 0x1000;
    uint8_t borrow = tell_borrow(x,y, 0);
    printf("BORROW (0x%x - 0x%x): %d\n", x, y, borrow);

    no_prefix_opcodes(0x31, 500, 0);
    printf("SP: %d\n", registers.SP);
    no_prefix_opcodes(0x39, 500, 0);
    no_prefix_opcodes(0x39, 500, 0);
    no_prefix_opcodes(0x23, 0, 0);
    printf("HL: %d\n", registers.HL_reg.HL);
}