#include "../includes/opcodes.h"

uint8_t two_byte_instructions[23] = {
    0x06,
    0x0E,
    0x16,
    0x1E,
    0x26,
    0x2E,
    0x36,
    0x3E,
    0x18,
    0x20,
    0x28,
    0x30,
    0x38,
    0xC6,
    0xCE,
    0xD6,
    0xDE,
    0xE6,
    0xEE,
    0xF6,
    0xFE,
    0xE8,
    0xF8,
};

uint8_t three_byte_instructions[17] = {
    0x01,
    0x11,
    0x21,
    0x31,
    0x08,
    0xC2,
    0xCA,
    0xD2,
    0xDA,
    0xC3,
    0xC4,
    0xCC,
    0xD4,
    0xDC,
    0xCD,
    0xEA,
    0xFA,
};

char *opcode_names[256] = {
    "NOP_0x00",
    "LD_0x01",
    "LD_0x02",
    "INC_0x03",
    "INC_0x04",
    "DEC_0x05",
    "LD_0x06",
    "RLCA_0x07",
    "LD_0x08",
    "ADD_0x09",
    "LD_0x0A",
    "DEC_0x0B",
    "INC_0x0C",
    "DEC_0x0D",
    "LD_0x0E",
    "RRCA_0x0F",
    "STOP_0x10",
    "LD_0x11",
    "LD_0x12",
    "INC_0x13",
    "INC_0x14",
    "DEC_0x15",
    "LD_0x16",
    "RLA_0x17",
    "JR_0x18",
    "ADD_0x19",
    "LD_0x1A",
    "DEC_0x1B",
    "INC_0x1C",
    "DEC_0x1D",
    "LD_0x1E",
    "RRA_0x1F",
    "JR_0x20",
    "LD_0x21",
    "LD_0x22",
    "INC_0x23",
    "INC_0x24",
    "DEC_0x25",
    "LD_0x26",
    "DDA_0x27",
    "JR_0x28",
    "ADD_0x29",
    "LD_0x2A",
    "DEC_0x2B",
    "INC_0x2C",
    "DEC_0x2D",
    "LD_0x2E",
    "CPL_0x2F",
    "JR_0x30",
    "LD_0x31",
    "LD_0x32",
    "INC_0x33",
    "INC_0x34",
    "DEC_0x35",
    "LD_0x36",
    "SCF_0x37",
    "JR_0x38",
    "ADD_0x39",
    "LD_0x3A",
    "DEC_0x3B",
    "INC_0x3C",
    "DEC_0x3D",
    "LD_0x3E",
    "CCF_0x3F",
    "LD_0x40",
    "LD_0x41",
    "LD_0x42",
    "LD_0x43",
    "LD_0x44",
    "LD_0x45",
    "LD_0x46",
    "LD_0x47",
    "LD_0x48",
    "LD_0x49",
    "LD_0x4A",
    "LD_0x4B",
    "LD_0x4C",
    "LD_0x4D",
    "LD_0x4E",
    "LD_0x4F",
    "LD_0x50",
    "LD_0x51",
    "LD_0x52",
    "LD_0x53",
    "LD_0x54",
    "LD_0x55",
    "LD_0x56",
    "LD_0x57",
    "LD_0x58",
    "LD_0x59",
    "LD_0x5A",
    "LD_0x5B",
    "LD_0x5C",
    "LD_0x5D",
    "LD_0x5E",
    "LD_0x5F",
    "LD_0x60",
    "LD_0x61",
    "LD_0x62",
    "LD_0x63",
    "LD_0x64",
    "LD_0x65",
    "LD_0x66",
    "LD_0x67",
    "LD_0x68",
    "LD_0x69",
    "LD_0x6A",
    "LD_0x6B",
    "LD_0x6C",
    "LD_0x6D",
    "LD_0x6E",
    "LD_0x6F",
    "LD_0x70",
    "LD_0x71",
    "LD_0x72",
    "LD_0x73",
    "LD_0x74",
    "LD_0x75",
    "HALT_0x76",
    "LD_0x77",
    "LD_0x78",
    "LD_0x79",
    "LD_0x7A",
    "LD_0x7B",
    "LD_0x7C",
    "LD_0x7D",
    "LD_0x7E",
    "LD_0x7F",
    "ADD_0x80",
    "ADD_0x81",
    "ADD_0x82",
    "ADD_0x83",
    "ADD_0x84",
    "ADD_0x85",
    "ADD_0x86",
    "ADD_0x87",
    "ADC_0x88",
    "ADC_0x89",
    "ADC_0x8A",
    "ADC_0x8B",
    "ADC_0x8C",
    "ADC_0x8D",
    "ADC_0x8E",
    "ADC_0x8F",
    "SUB_0x90",
    "SUB_0x91",
    "SUB_0x92",
    "SUB_0x93",
    "SUB_0x94",
    "SUB_0x95",
    "SUB_0x96",
    "SUB_0x97",
    "SBC_0x98",
    "SBC_0x99",
    "SBC_0x9A",
    "SBC_0x9B",
    "SBC_0x9C",
    "SBC_0x9D",
    "SBC_0x9E",
    "SBC_0x9F",
    "AND_0xA0",
    "AND_0xA1",
    "AND_0xA2",
    "AND_0xA3",
    "AND_0xA4",
    "AND_0xA5",
    "AND_0xA6",
    "AND_0xA7",
    "XOR_0xA8",
    "XOR_0xA9",
    "XOR_0xAA",
    "XOR_0xAB",
    "XOR_0xAC",
    "XOR_0xAD",
    "XOR_0xAE",
    "XOR_0xAF",
    "OR_0xB0",
    "OR_0xB1",
    "OR_0xB2",
    "OR_0xB3",
    "OR_0xB4",
    "OR_0xB5",
    "OR_0xB6",
    "OR_0xB7",
    "CP_0xB8",
    "CP_0xB9",
    "CP_0xBA",
    "CP_0xBB",
    "CP_0xBC",
    "CP_0xBD",
    "CP_0xBE",
    "CP_0xBF",
    "RET_0xC0",
    "POP_0xC1",
    "JP_0xC2",
    "JP_0xC3",
    "CALL_0xC4",
    "PUSH_0xC5",
    "ADD_0xC6",
    "RST_0xC7",
    "RET_0xC8",
    "RET_0xC9",
    "JP_0xCA",
    "BAD",
    "CALL_0xCC",
    "CALL_0xCD",
    "ADC_0xCE",
    "RST_0xCF",
    "RET_0xD0",
    "POP_0xD1",
    "JP_0xD2",
    "BAD",
    "CALL_0xD4",
    "PUSH_0xD5",
    "SUB_0xD6",
    "RST_0xD7",
    "RET_0xD8",
    "RETI_0xD9",
    "JP_0xDA",
    "BAD",
    "CALL_0xDC",
    "BAD",
    "SBC_0xDE",
    "RST_0xDF",
    "LDH_0xE0",
    "POP_0xE1",
    "LD_0xE2",
    "BAD",
    "BAD",
    "PUSH_0xE5",
    "AND_0xE6",
    "RST_0xE7",
    "ADD_0xE8",
    "JP_0xE9",
    "LD_0xEA",
    "BAD",
    "BAD",
    "BAD",
    "XOR_0xEE",
    "RST_0xEF",
    "LDH_0xF0",
    "POP_0xF1",
    "LD_0xF2",
    "DI_0xF3",
    "BAD",
    "PUSH_0xF5",
    "OR_0xF6",
    "RST_0xF7",
    "LD_0xF8",
    "LD_0xF9",
    "LD_0xFA",
    "EI_0xFB",
    "BAD",
    "BAD",
    "CP_0xFE",
    "RST_0xFF",
};

uint8_t in_array(uint8_t *array, uint8_t target, uint8_t size)
{
    for (int i = 0; i < size; i++)
    {
        // printf("%d: %02X\n",i, array[i]);
        if (target == array[i])
            return 1;
    }
    return 0;
}

void print_opcode(uint8_t opcode, uint16_t imm16, uint8_t imm8)
{
    if (in_array(two_byte_instructions, opcode, 23))
    {
        printf("OPCODE: %s, ARG: %02X\n", opcode_names[opcode], imm8);
    }
    else if (in_array(three_byte_instructions, opcode, 17))
    {
        printf("OPCODE: %s, ARG: %04X\n", opcode_names[opcode], imm16);
    }
    else
    {
        printf("OPCODE: %s\n", opcode_names[opcode]);
    }
}

int halted = 0;

// tell overflow at a given bit
uint8_t tell_overflow(uint16_t a, uint16_t b, uint8_t cin, uint8_t bit)
{
    uint32_t carry = cin;
    for (int i = 1; i <= bit + 1; i++)
    {
        carry |= ((BIT(a, i - 1) + BIT(b, i - 1) + BIT(carry, i - 1)) & 0b10) << (i - 1);
    }
    return (BIT(carry, bit) ^ BIT(carry, bit + 1));
}

uint8_t tell_borrow(uint16_t a, uint16_t b, uint8_t bit)
{
    uint16_t borrow = BIT(b, 15) > BIT(a, 15);
    for (int i = 14; i >= bit; i--)
    {
        borrow |= (BIT(b, i) > (BIT(a, i), BIT(borrow, i + 1))) << i;
    }
    return BIT(borrow, bit);
}


uint8_t no_prefix_opcodes(uint8_t opcode, uint16_t imm16, uint8_t imm8)
{
    uint8_t prev_carry = 0;
    switch (opcode)
    {
    case (0x00):
        return 4;
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
    case (0x0B):
        registers.BC_reg.BC--;
        return 8;
    case (0x1B):
        registers.DE_reg.DE--;
        return 8;
    case (0x2B):
        registers.HL_reg.HL--;
        return 8;
    case (0x3B):
        registers.SP--;
        return 8;
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
        write_memory(registers.HL_reg.HL, read_memory(registers.HL_reg.HL) - 1);
        registers.AF_reg.sub.F_reg.flags.z = (read_memory(registers.HL_reg.HL) == 0);
        return 4;
    case (0x3C):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.AF_reg.sub.A, 0, 3);
        registers.AF_reg.sub.A++;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x05):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.BC_reg.sub.B, registers.BC_reg.sub.B, 4);
        registers.BC_reg.sub.B--;
        registers.AF_reg.sub.F_reg.flags.z = (registers.BC_reg.sub.B == 0);
        return 4;
    case (0x0D):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.BC_reg.sub.C, registers.BC_reg.sub.C, 4);
        registers.BC_reg.sub.C--;
        registers.AF_reg.sub.F_reg.flags.z = (registers.BC_reg.sub.C == 0);
        return 4;
    case (0x15):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.DE_reg.sub.D, registers.DE_reg.sub.D, 4);
        registers.DE_reg.sub.D--;
        registers.AF_reg.sub.F_reg.flags.z = (registers.DE_reg.sub.D == 0);
        return 4;
    case (0x1D):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.DE_reg.sub.E, registers.DE_reg.sub.E, 4);
        registers.DE_reg.sub.E--;
        registers.AF_reg.sub.F_reg.flags.z = (registers.DE_reg.sub.E == 0);
        return 4;
    case (0x25):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.HL_reg.sub.H, registers.HL_reg.sub.H, 4);
        registers.HL_reg.sub.H--;
        registers.AF_reg.sub.F_reg.flags.z = (registers.HL_reg.sub.H == 0);
        return 4;
    case (0x2D):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.HL_reg.sub.L, registers.HL_reg.sub.L, 4);
        registers.HL_reg.sub.L--;
        registers.AF_reg.sub.F_reg.flags.z = (registers.HL_reg.sub.L == 0);
        return 4;
    case (0x35):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(read_memory(registers.HL_reg.HL), read_memory(registers.HL_reg.HL), 4);
        write_memory(registers.HL_reg.HL, read_memory(registers.HL_reg.HL) - 1);
        registers.AF_reg.sub.F_reg.flags.z = (read_memory(registers.HL_reg.HL) == 0);
        return 4;
    case (0x3D):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.AF_reg.sub.A, 4);
        registers.AF_reg.sub.A--;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x06):
        registers.BC_reg.sub.B = imm8;
        return 8;
    case (0x0E):
        registers.BC_reg.sub.C = imm8;
        return 8;
    case (0x16):
        registers.DE_reg.sub.D = imm8;
        return 8;
    case (0x1E):
        registers.DE_reg.sub.E = imm8;
        return 8;
    case (0x26):
        registers.HL_reg.sub.H = imm8;
        return 8;
    case (0x2E):
        registers.HL_reg.sub.L = imm8;
        return 8;
    case (0x36):
        write_memory(registers.HL_reg.HL, imm8);
        return 8;
    case (0x3E):
        registers.AF_reg.sub.A = imm8;
        return 8;
    case (0x07):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.z = 0;
        registers.AF_reg.sub.F_reg.flags.c = BIT(registers.AF_reg.sub.A, 7);
        registers.AF_reg.sub.A = (registers.AF_reg.sub.A << 1) | BIT(registers.AF_reg.sub.A, 7);
        return 4;
    case (0x0F):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.z = 0;
        registers.AF_reg.sub.F_reg.flags.c = BIT(registers.AF_reg.sub.A, 0);
        registers.AF_reg.sub.A = (registers.AF_reg.sub.A >> 1) | (BIT(registers.AF_reg.sub.A, 0) << 7);
        return 4;
    case (0x17):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.z = 0;
        registers.AF_reg.sub.F_reg.flags.c = BIT(registers.AF_reg.sub.A, 7);
        registers.AF_reg.sub.A = (registers.AF_reg.sub.A << 1) | prev_carry;
        return 4;
    case (0x1F):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.z = 0;
        registers.AF_reg.sub.F_reg.flags.c = BIT(registers.AF_reg.sub.A, 0);
        registers.AF_reg.sub.A = (registers.AF_reg.sub.A >> 1) | (prev_carry << 7);
        return 4;
    case (0x27):
        registers.AF_reg.sub.F_reg.flags.h = 0;
        uint8_t adj = 0;
        if (registers.AF_reg.sub.F_reg.flags.n)
        {
            adj += (registers.AF_reg.sub.F_reg.flags.h) ? 0x6 : 0;
            adj += (registers.AF_reg.sub.F_reg.flags.c) ? 0x60 : 0;
            registers.AF_reg.sub.A -= adj;
        }
        else
        {
            adj += (registers.AF_reg.sub.F_reg.flags.h || ((registers.AF_reg.sub.A & 0xF) > 0x9)) ? 0x6 : 0;
            if (registers.AF_reg.sub.F_reg.flags.c || registers.AF_reg.sub.A > 0x99)
            {
                adj += 0x60;
                registers.AF_reg.sub.F_reg.flags.c = 1;
            }
            registers.AF_reg.sub.A += adj;
        }
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x2F):
        registers.AF_reg.sub.F_reg.flags.h = 1;
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.A = ~registers.AF_reg.sub.A;
        return 4;
    case (0x37):
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.c = 1;
        return 4;
    case (0x3F):
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.c = ~registers.AF_reg.sub.F_reg.flags.c;
        return 4;
    case (0x18):
        registers.PC += ((int8_t)imm8);
        return 12;
    case (0x20):
        if (!(registers.AF_reg.sub.F_reg.flags.z))
        {
            registers.PC += ((int8_t)imm8);
            return 12;
        }
        return 8;
    case (0x28):
        if ((registers.AF_reg.sub.F_reg.flags.z))
        {
            registers.PC += ((int8_t)imm8);
            return 12;
        }
        return 8;
    case (0x30):
        if (!(registers.AF_reg.sub.F_reg.flags.c))
        {
            registers.PC += ((int8_t)imm8);
            return 12;
        }
        return 8;
    case (0x38):
        if ((registers.AF_reg.sub.F_reg.flags.c))
        {
            registers.PC += ((int8_t)imm8);
            return 12;
        }
        return 8;
    case (0x01):
        printf("STOP HIT\n");
        return 0;
    case (0x40):
        registers.BC_reg.sub.B = registers.BC_reg.sub.B;
        return 4;
    case (0x41):
        registers.BC_reg.sub.B = registers.BC_reg.sub.C;
        return 4;
    case (0x42):
        registers.BC_reg.sub.B = registers.DE_reg.sub.D;
        return 4;
    case (0x43):
        registers.BC_reg.sub.B = registers.DE_reg.sub.E;
        return 4;
    case (0x44):
        registers.BC_reg.sub.B = registers.HL_reg.sub.H;
        return 4;
    case (0x45):
        registers.BC_reg.sub.B = registers.HL_reg.sub.L;
        return 4;
    case (0x46):
        registers.BC_reg.sub.B = read_memory(registers.HL_reg.HL);
        return 4;
    case (0x47):
        registers.BC_reg.sub.B = registers.AF_reg.sub.A;
        return 4;
    case (0x48):
        registers.BC_reg.sub.C = registers.BC_reg.sub.B;
        return 4;
    case (0x49):
        registers.BC_reg.sub.C = registers.BC_reg.sub.C;
        return 4;
    case (0x4A):
        registers.BC_reg.sub.C = registers.DE_reg.sub.D;
        return 4;
    case (0x4B):
        registers.BC_reg.sub.C = registers.DE_reg.sub.E;
        return 4;
    case (0x4C):
        registers.BC_reg.sub.C = registers.HL_reg.sub.H;
        return 4;
    case (0x4D):
        registers.BC_reg.sub.C = registers.HL_reg.sub.L;
        return 4;
    case (0x4E):
        registers.BC_reg.sub.C = read_memory(registers.HL_reg.HL);
        return 4;
    case (0x4F):
        registers.BC_reg.sub.C = registers.AF_reg.sub.A;
        return 4;
    case (0x50):
        registers.DE_reg.sub.D = registers.BC_reg.sub.B;
        return 4;
    case (0x51):
        registers.DE_reg.sub.D = registers.BC_reg.sub.C;
        return 4;
    case (0x52):
        registers.DE_reg.sub.D = registers.DE_reg.sub.D;
        return 4;
    case (0x53):
        registers.DE_reg.sub.D = registers.DE_reg.sub.E;
        return 4;
    case (0x54):
        registers.DE_reg.sub.D = registers.HL_reg.sub.H;
        return 4;
    case (0x55):
        registers.DE_reg.sub.D = registers.HL_reg.sub.L;
        return 4;
    case (0x56):
        registers.DE_reg.sub.D = read_memory(registers.HL_reg.HL);
        return 4;
    case (0x57):
        registers.DE_reg.sub.D = registers.AF_reg.sub.A;
        return 4;
    case (0x58):
        registers.DE_reg.sub.E = registers.BC_reg.sub.B;
        return 4;
    case (0x59):
        registers.DE_reg.sub.E = registers.BC_reg.sub.C;
        return 4;
    case (0x5A):
        registers.DE_reg.sub.E = registers.DE_reg.sub.D;
        return 4;
    case (0x5B):
        registers.DE_reg.sub.E = registers.DE_reg.sub.E;
        return 4;
    case (0x5C):
        registers.DE_reg.sub.E = registers.HL_reg.sub.H;
        return 4;
    case (0x5D):
        registers.DE_reg.sub.E = registers.HL_reg.sub.L;
        return 4;
    case (0x5E):
        registers.DE_reg.sub.E = read_memory(registers.HL_reg.HL);
        return 4;
    case (0x5F):
        registers.DE_reg.sub.E = registers.AF_reg.sub.A;
        return 4;
    case (0x60):
        registers.HL_reg.sub.H = registers.BC_reg.sub.B;
        return 4;
    case (0x61):
        registers.HL_reg.sub.H = registers.BC_reg.sub.C;
        return 4;
    case (0x62):
        registers.HL_reg.sub.H = registers.DE_reg.sub.D;
        return 4;
    case (0x63):
        registers.HL_reg.sub.H = registers.DE_reg.sub.E;
        return 4;
    case (0x64):
        registers.HL_reg.sub.H = registers.HL_reg.sub.H;
        return 4;
    case (0x65):
        registers.HL_reg.sub.H = registers.HL_reg.sub.L;
        return 4;
    case (0x66):
        registers.HL_reg.sub.H = read_memory(registers.HL_reg.HL);
        return 4;
    case (0x67):
        registers.HL_reg.sub.H = registers.AF_reg.sub.A;
        return 4;
    case (0x68):
        registers.HL_reg.sub.L = registers.BC_reg.sub.B;
        return 4;
    case (0x69):
        registers.HL_reg.sub.L = registers.BC_reg.sub.C;
        return 4;
    case (0x6A):
        registers.HL_reg.sub.L = registers.DE_reg.sub.D;
        return 4;
    case (0x6B):
        registers.HL_reg.sub.L = registers.DE_reg.sub.E;
        return 4;
    case (0x6C):
        registers.HL_reg.sub.L = registers.HL_reg.sub.H;
        return 4;
    case (0x6D):
        registers.HL_reg.sub.L = registers.HL_reg.sub.L;
        return 4;
    case (0x6E):
        registers.HL_reg.sub.L = read_memory(registers.HL_reg.HL);
        return 4;
    case (0x6F):
        registers.HL_reg.sub.L = registers.AF_reg.sub.A;
        return 4;
    case (0x70):
        write_memory(registers.HL_reg.HL, registers.BC_reg.sub.B);
        return 4;
    case (0x71):
        write_memory(registers.HL_reg.HL, registers.BC_reg.sub.C);
        return 4;
    case (0x72):
        write_memory(registers.HL_reg.HL, registers.DE_reg.sub.D);
        return 4;
    case (0x73):
        write_memory(registers.HL_reg.HL, registers.DE_reg.sub.E);
        return 4;
    case (0x74):
        write_memory(registers.HL_reg.HL, registers.HL_reg.sub.H);
        return 4;
    case (0x75):
        write_memory(registers.HL_reg.HL, registers.HL_reg.sub.L);
        return 4;
    case (0x76):
        halted = 1;
        printf("HALT HIT\n");
        exit(-1);
        return 4;
    case (0x77):
        write_memory(registers.HL_reg.HL, registers.AF_reg.sub.A);
        return 4;
    case (0x78):
        registers.AF_reg.sub.A = registers.BC_reg.sub.B;
        return 4;
    case (0x79):
        registers.AF_reg.sub.A = registers.BC_reg.sub.C;
        return 4;
    case (0x7A):
        registers.AF_reg.sub.A = registers.DE_reg.sub.D;
        return 4;
    case (0x7B):
        registers.AF_reg.sub.A = registers.DE_reg.sub.E;
        return 4;
    case (0x7C):
        registers.AF_reg.sub.A = registers.HL_reg.sub.H;
        return 4;
    case (0x7D):
        registers.AF_reg.sub.A = registers.HL_reg.sub.L;
        return 4;
    case (0x7E):
        registers.AF_reg.sub.A = read_memory(registers.HL_reg.HL);
        return 4;
    case (0x7F):
        registers.AF_reg.sub.A = registers.AF_reg.sub.A;
        return 4;
    case (0x80):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.BC_reg.sub.B, 0, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, registers.BC_reg.sub.B, 0, 7);
        registers.AF_reg.sub.A += registers.BC_reg.sub.B;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x81):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.BC_reg.sub.C, 0, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, registers.BC_reg.sub.C, 0, 7);
        registers.AF_reg.sub.A += registers.BC_reg.sub.C;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x82):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.DE_reg.sub.D, 0, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, registers.DE_reg.sub.D, 0, 7);
        registers.AF_reg.sub.A += registers.DE_reg.sub.D;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x83):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.DE_reg.sub.E, 0, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, registers.DE_reg.sub.E, 0, 7);
        registers.AF_reg.sub.A += registers.DE_reg.sub.E;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x84):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.HL_reg.sub.H, 0, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, registers.HL_reg.sub.H, 0, 7);
        registers.AF_reg.sub.A += registers.HL_reg.sub.H;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x85):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.HL_reg.sub.L, 0, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, registers.HL_reg.sub.L, 0, 7);
        registers.AF_reg.sub.A += registers.HL_reg.sub.L;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x86):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, read_memory(registers.HL_reg.HL), 0, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, read_memory(registers.HL_reg.HL), 0, 7);
        registers.AF_reg.sub.A += read_memory(registers.HL_reg.HL);
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x87):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.AF_reg.sub.A, 0, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, registers.AF_reg.sub.A, 0, 7);
        registers.AF_reg.sub.A += registers.AF_reg.sub.A;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x88):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.BC_reg.sub.B, prev_carry, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, registers.BC_reg.sub.B, prev_carry, 7);
        registers.AF_reg.sub.A += registers.BC_reg.sub.B + prev_carry;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x89):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.BC_reg.sub.C, prev_carry, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, registers.BC_reg.sub.C, prev_carry, 7);
        registers.AF_reg.sub.A += registers.BC_reg.sub.C + prev_carry;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x8A):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.DE_reg.sub.D, prev_carry, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, registers.DE_reg.sub.D, prev_carry, 7);
        registers.AF_reg.sub.A += registers.DE_reg.sub.D + prev_carry;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x8B):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.DE_reg.sub.E, prev_carry, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, registers.DE_reg.sub.E, prev_carry, 7);
        registers.AF_reg.sub.A += registers.DE_reg.sub.E + prev_carry;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x8C):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.HL_reg.sub.H, prev_carry, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, registers.HL_reg.sub.H, prev_carry, 7);
        registers.AF_reg.sub.A += registers.HL_reg.sub.H + prev_carry;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x8D):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.HL_reg.sub.L, prev_carry, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, registers.HL_reg.sub.L, prev_carry, 7);
        registers.AF_reg.sub.A += registers.HL_reg.sub.L + prev_carry;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x8E):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, read_memory(registers.HL_reg.HL), prev_carry, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, read_memory(registers.HL_reg.HL), prev_carry, 7);
        registers.AF_reg.sub.A += read_memory(registers.HL_reg.HL) + prev_carry;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x8F):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, registers.AF_reg.sub.A, prev_carry, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, registers.AF_reg.sub.A, prev_carry, 7);
        registers.AF_reg.sub.A += registers.AF_reg.sub.A + prev_carry;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x90):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.BC_reg.sub.B, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < registers.BC_reg.sub.B);
        registers.AF_reg.sub.A -= registers.BC_reg.sub.B;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x91):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.BC_reg.sub.C, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < registers.BC_reg.sub.C);
        registers.AF_reg.sub.A -= registers.BC_reg.sub.C;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x92):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.DE_reg.sub.D, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < registers.DE_reg.sub.D);
        registers.AF_reg.sub.A -= registers.DE_reg.sub.D;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x93):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.DE_reg.sub.E, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < registers.DE_reg.sub.E);
        registers.AF_reg.sub.A -= registers.DE_reg.sub.E;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x94):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.HL_reg.sub.H, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < registers.HL_reg.sub.H);
        registers.AF_reg.sub.A -= registers.HL_reg.sub.H;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x95):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.HL_reg.sub.L, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < registers.HL_reg.sub.L);
        registers.AF_reg.sub.A -= registers.HL_reg.sub.L;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x96):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, read_memory(registers.HL_reg.HL), 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < read_memory(registers.HL_reg.HL));
        registers.AF_reg.sub.A -= read_memory(registers.HL_reg.HL);
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x97):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.AF_reg.sub.A, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < registers.AF_reg.sub.A);
        registers.AF_reg.sub.A -= registers.AF_reg.sub.A;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x98):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.BC_reg.sub.B + prev_carry, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < (registers.BC_reg.sub.B + prev_carry));
        registers.AF_reg.sub.A -= (registers.BC_reg.sub.B + prev_carry);
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x99):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.BC_reg.sub.C + prev_carry, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < (registers.BC_reg.sub.C + prev_carry));
        registers.AF_reg.sub.A -= (registers.BC_reg.sub.C + prev_carry);
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x9A):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.DE_reg.sub.D + prev_carry, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < (registers.DE_reg.sub.D + prev_carry));
        registers.AF_reg.sub.A -= (registers.DE_reg.sub.D + prev_carry);
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x9B):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.DE_reg.sub.E + prev_carry, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < (registers.DE_reg.sub.E + prev_carry));
        registers.AF_reg.sub.A -= (registers.DE_reg.sub.E + prev_carry);
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x9C):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.HL_reg.sub.H + prev_carry, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < (registers.HL_reg.sub.H + prev_carry));
        registers.AF_reg.sub.A -= (registers.HL_reg.sub.H + prev_carry);
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x9D):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.HL_reg.sub.L + prev_carry, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < (registers.HL_reg.sub.L + prev_carry));
        registers.AF_reg.sub.A -= (registers.HL_reg.sub.L + prev_carry);
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x9E):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, read_memory(registers.HL_reg.HL) + prev_carry, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < (read_memory(registers.HL_reg.HL) + prev_carry));
        registers.AF_reg.sub.A -= (read_memory(registers.HL_reg.HL) + prev_carry);
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0x9F):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.AF_reg.sub.A + prev_carry, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < (registers.AF_reg.sub.A + prev_carry));
        registers.AF_reg.sub.A -= (registers.AF_reg.sub.A + prev_carry);
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xA0):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 1;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A &= registers.BC_reg.sub.B;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xA1):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 1;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A &= registers.BC_reg.sub.C;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xA2):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 1;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A &= registers.DE_reg.sub.D;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xA3):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 1;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A &= registers.DE_reg.sub.E;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xA4):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 1;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A &= registers.HL_reg.sub.H;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xA5):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 1;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A &= registers.HL_reg.sub.L;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xA6):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 1;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A &= read_memory(registers.HL_reg.HL);
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xA7):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 1;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A &= registers.AF_reg.sub.A;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xA8):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A ^= registers.BC_reg.sub.B;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xA9):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A ^= registers.BC_reg.sub.C;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xAA):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A ^= registers.DE_reg.sub.D;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xAB):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A ^= registers.DE_reg.sub.E;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xAC):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A ^= registers.HL_reg.sub.H;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xAD):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A ^= registers.HL_reg.sub.L;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xAE):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A ^= read_memory(registers.HL_reg.HL);
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xAF):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A ^= registers.AF_reg.sub.A;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xB0):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A |= registers.BC_reg.sub.B;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xB1):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A |= registers.BC_reg.sub.C;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xB2):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A |= registers.DE_reg.sub.D;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xB3):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A |= registers.DE_reg.sub.E;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xB4):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A |= registers.HL_reg.sub.H;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xB5):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A |= registers.HL_reg.sub.L;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xB6):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A |= read_memory(registers.HL_reg.HL);
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xB7):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A |= registers.AF_reg.sub.A;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 4;
    case (0xB8):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.BC_reg.sub.B, 4);
        registers.AF_reg.sub.F_reg.flags.c = registers.AF_reg.sub.A < registers.BC_reg.sub.B;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == registers.BC_reg.sub.B);
        return 4;
    case (0xB9):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.BC_reg.sub.C, 4);
        registers.AF_reg.sub.F_reg.flags.c = registers.AF_reg.sub.A < registers.BC_reg.sub.C;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == registers.BC_reg.sub.C);
        return 4;
    case (0xBA):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.DE_reg.sub.D, 4);
        registers.AF_reg.sub.F_reg.flags.c = registers.AF_reg.sub.A < registers.DE_reg.sub.D;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == registers.DE_reg.sub.D);
        return 4;
    case (0xBB):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.DE_reg.sub.E, 4);
        registers.AF_reg.sub.F_reg.flags.c = registers.AF_reg.sub.A < registers.DE_reg.sub.E;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == registers.DE_reg.sub.E);
        return 4;
    case (0xBC):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.HL_reg.sub.H, 4);
        registers.AF_reg.sub.F_reg.flags.c = registers.AF_reg.sub.A < registers.HL_reg.sub.H;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == registers.HL_reg.sub.H);
        return 4;
    case (0xBD):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.HL_reg.sub.L, 4);
        registers.AF_reg.sub.F_reg.flags.c = registers.AF_reg.sub.A < registers.HL_reg.sub.L;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == registers.HL_reg.sub.L);
        return 4;
    case (0xBE):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, read_memory(registers.HL_reg.HL), 4);
        registers.AF_reg.sub.F_reg.flags.c = registers.AF_reg.sub.A < read_memory(registers.HL_reg.HL);
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == read_memory(registers.HL_reg.HL));
        return 4;
    case (0xBF):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, registers.AF_reg.sub.A, 4);
        registers.AF_reg.sub.F_reg.flags.c = registers.AF_reg.sub.A < registers.AF_reg.sub.A;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == registers.AF_reg.sub.A);
        return 4;
    case (0xC6):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, imm8, 0, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, imm8, 0, 7);
        registers.AF_reg.sub.A += imm8;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 8;
    case (0xCE):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.AF_reg.sub.A, imm8, prev_carry, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.AF_reg.sub.A, imm8, prev_carry, 7);
        registers.AF_reg.sub.A += imm8 + prev_carry;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 8;
    case (0xD6):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, imm8, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < imm8);
        registers.AF_reg.sub.A -= imm8;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 8;
    case (0xDE):
        prev_carry = registers.AF_reg.sub.F_reg.flags.c;
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, imm8 + prev_carry, 4);
        registers.AF_reg.sub.F_reg.flags.c = (registers.AF_reg.sub.A < (imm8 + prev_carry));
        registers.AF_reg.sub.A -= (imm8 + prev_carry);
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 8;
    case (0xE6):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 1;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A &= imm8;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 8;
    case (0xEE):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A ^= imm8;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 8;
    case (0xF6):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = 0;
        registers.AF_reg.sub.F_reg.flags.c = 0;
        registers.AF_reg.sub.A |= imm8;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == 0);
        return 8;
    case (0xFE):
        registers.AF_reg.sub.F_reg.flags.n = 1;
        registers.AF_reg.sub.F_reg.flags.h = tell_borrow(registers.AF_reg.sub.A, imm8, 4);
        registers.AF_reg.sub.F_reg.flags.c = registers.AF_reg.sub.A < imm8;
        registers.AF_reg.sub.F_reg.flags.z = (registers.AF_reg.sub.A == imm8);
        return 8;
    case (0xC0):
        if (!(registers.AF_reg.sub.F_reg.flags.z))
        {
            registers.PC = pop16();
            return 20;
        }
        return 8;
    case (0xC8):
        if ((registers.AF_reg.sub.F_reg.flags.z))
        {
            registers.PC = pop16();
            return 20;
        }
        return 8;
    case (0xD0):
        if (!(registers.AF_reg.sub.F_reg.flags.c))
        {
            registers.PC = pop16();
            return 20;
        }
        return 8;
    case (0xD8):
        if ((registers.AF_reg.sub.F_reg.flags.c))
        {
            registers.PC = pop16();
            return 20;
        }
        return 8;
    case (0xC9):
        registers.PC = pop16();
        return 16;
    case (0xD9):
        registers.PC = pop16();
        IME = 1;
        return 16;
    case (0xC2):
        if (!(registers.AF_reg.sub.F_reg.flags.z))
        {
            registers.PC = imm16;
            return 16;
        }
        return 12;
    case (0xCA):
        if ((registers.AF_reg.sub.F_reg.flags.z))
        {
            registers.PC = imm16;
            return 16;
        }
        return 12;
    case (0xD2):
        if (!(registers.AF_reg.sub.F_reg.flags.c))
        {
            registers.PC = imm16;
            return 16;
        }
        return 12;
    case (0xDA):
        if ((registers.AF_reg.sub.F_reg.flags.c))
        {
            registers.PC = imm16;
            return 16;
        }
        return 12;
    case (0xC3):
        registers.PC = imm16;
        return 12;
    case (0xE9):
        registers.PC = registers.HL_reg.HL;
        return 4;
    case (0xC4):
        if (!(registers.AF_reg.sub.F_reg.flags.z))
        {
            push16(registers.PC);
            registers.PC = imm16;
            return 24;
        }
        return 12;
    case (0xCC):
        if ((registers.AF_reg.sub.F_reg.flags.z))
        {
            push16(registers.PC);
            registers.PC = imm16;
            return 24;
        }
        return 12;
    case (0xD4):
        if (!(registers.AF_reg.sub.F_reg.flags.c))
        {
            push16(registers.PC);
            registers.PC = imm16;
            return 24;
        }
        return 12;
    case (0xDC):
        if ((registers.AF_reg.sub.F_reg.flags.c))
        {
            push16(registers.PC);
            registers.PC = imm16;
            return 24;
        }
        return 12;
    case (0xCD):
        push16(registers.PC);
        registers.PC = imm16;
        return 24;
    case (0xC7):
        push16(registers.PC);
        registers.PC = 0;
        return 16;
    case (0xCF):
        push16(registers.PC);
        registers.PC = 8;
        return 16;
    case (0xD7):
        push16(registers.PC);
        registers.PC = 16;
        return 16;
    case (0xDF):
        push16(registers.PC);
        registers.PC = 24;
        return 16;
    case (0xE7):
        push16(registers.PC);
        registers.PC = 32;
        return 16;
    case (0xEF):
        push16(registers.PC);
        registers.PC = 40;
        return 16;
    case (0xF7):
        push16(registers.PC);
        registers.PC = 48;
        return 16;
    case (0xFF):
        push16(registers.PC);
        registers.PC = 56;
        return 16;
    case (0xC1):
        registers.BC_reg.BC = pop16();
        return 16;
    case (0xD1):
        registers.DE_reg.DE = pop16();
        return 16;
    case (0xE1):
        registers.HL_reg.HL = pop16();
        return 16;
    case (0xF1):
        registers.AF_reg.AF = pop16();
        return 16;
    case (0xC5):
        push16(registers.BC_reg.BC);
        return 16;
    case (0xD5):
        push16(registers.DE_reg.DE);
        return 16;
    case (0xE5):
        push16(registers.HL_reg.HL);
        return 16;
    case (0xF5):
        push16(registers.AF_reg.AF);
        return 16;
    case (0xE2):
        write_memory(registers.BC_reg.sub.C + 0xFF00, registers.AF_reg.sub.A);
        return 8;
    case (0xE0):
        write_memory(imm8 + 0xFF00, registers.AF_reg.sub.A);
        return 12;
    case (0xEA):
        write_memory(imm16, registers.AF_reg.sub.A);
        return 16;
    case (0xF2):
        registers.AF_reg.sub.A = read_memory(registers.BC_reg.sub.C + 0xFF00);
        return 8;
    case (0xF0):
        registers.AF_reg.sub.A = read_memory(imm8 + 0xFF00);
        return 8;
    case (0xFA):
        registers.AF_reg.sub.A = read_memory(imm16);
        return 8;
    case (0xE8):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.SP, imm8, 0, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.SP, imm8, 0, 7);
        registers.SP += (int8_t)imm8;
        registers.AF_reg.sub.F_reg.flags.z = 0;
        return 16;
    case (0xF8):
        registers.AF_reg.sub.F_reg.flags.n = 0;
        registers.AF_reg.sub.F_reg.flags.h = tell_overflow(registers.SP, imm8, 0, 3);
        registers.AF_reg.sub.F_reg.flags.c = tell_overflow(registers.SP, imm8, 0, 7);
        registers.HL_reg.HL = (registers.SP + ((int8_t)imm8));
        registers.AF_reg.sub.F_reg.flags.z = 0;
        return 16;
    case (0xF9):
        registers.SP = registers.HL_reg.HL;
        return 8;
    case (0xF3):
        IME = 0;
        return 4;
    case (0xFB):
        IME = 1;
        return 4;
    default:
        printf("BAD OPCODE: %d\n", opcode);
        exit(-1);
        return -1;
    }
}

// int main(void)
// {
//     uint16_t x = 0xEFFF;
//     uint16_t y = 0x1000;
//     uint8_t borrow = tell_borrow(x, y, 0);
//     printf("BORROW (0x%x - 0x%x): %d\n", x, y, borrow);

//     no_prefix_opcodes(0x31, 500, 0);
//     printf("SP: %d\n", registers.SP);
//     no_prefix_opcodes(0x39, 500, 0);
//     no_prefix_opcodes(0x39, 500, 0);
//     no_prefix_opcodes(0x23, 0, 0);
//     printf("HL: %d\n", registers.HL_reg.HL);
// }