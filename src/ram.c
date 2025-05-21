#include "../includes/ram.h"

uint8_t wram[0x2000];
uint8_t hram[0x80];

uint8_t wram_read(uint16_t address){
    return wram[address - WRAM_ADDRESS_OFFSET];
}

void wram_write(uint16_t address, uint8_t value){
    wram[address - WRAM_ADDRESS_OFFSET] = value;
}

uint8_t hram_read(uint16_t address){
    return hram[address - HRAM_ADDRESS_OFFSET];
}

void hram_write(uint16_t address, uint8_t value){
    hram[address - HRAM_ADDRESS_OFFSET] = value;
}
