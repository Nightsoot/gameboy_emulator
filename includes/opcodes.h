#include <stdint.h>
#include "../includes/registers.h"
#include "../includes/memory_tools.h"

#define BIT(a, i) ((a & (0b1 << i)) >> i)

uint8_t two_byte_instructions[23];

uint8_t three_byte_instructions[17];

uint8_t tell_overflow(uint16_t a, uint16_t b, uint8_t cin, uint8_t bit);

uint8_t no_prefix_opcodes(uint8_t opcode, uint16_t imm16, uint8_t imm8);