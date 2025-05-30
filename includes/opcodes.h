#include <stdint.h>
#include <stdint.h>
#include <stdio.h>
#include "../includes/registers.h"
#include "../includes/memory_tools.h"
#include "../includes/cartridge.h"

#define BIT(a, i) ((a & (0b1 << i)) >> i)

extern uint8_t two_byte_instructions[23];

extern uint8_t three_byte_instructions[17];

extern int halted;

extern char* opcode_names[256];

uint8_t in_array(uint8_t* array, uint8_t target, uint8_t size);

void print_opcode(uint8_t opcode, uint16_t imm16, uint8_t imm8);

uint8_t tell_overflow(uint16_t a, uint16_t b, uint8_t cin, uint8_t bit);

uint8_t no_prefix_opcodes(uint8_t opcode, uint16_t imm16, uint8_t imm8);