#include <stdint.h>
#include <stdio.h>

#include "ram.h"

#define ROM_END 0x8000
#define VRAM_END 0xA000
#define EXT_RAM_END 0xC000
#define WRAM_END 0xE000
#define ERAM_END 0xFE00
#define OAM_END 0xFEA0
#define UNUSABLE_END 0xFF00
#define IO_END 0xFF80
#define HRAM_END 0xFFFF

uint8_t read_memory(uint16_t address);
void write_memory(uint16_t address, uint8_t value);

uint16_t double_read_memory(uint16_t address);
void double_write_memory(uint16_t address, uint16_t value);