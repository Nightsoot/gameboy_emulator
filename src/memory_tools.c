#include "../includes/memory_tools.h"

uint8_t IE = 0;

uint8_t read_memory(uint16_t address){
    if(address < ROM_END){
        //TODO
    }
    else if(address < VRAM_END){
        //TODO
    }
    else if(address < EXT_RAM_END){
        //TODO
    }
    else if(address < WRAM_END){
        wram_read(address);
    }
    else if(address < ERAM_END){
        //TODO
    }
    else if(address < OAM_END){
        //TODO
    }
    else if(address < UNUSABLE_END){
        //TODO
    }
    else if(address < IO_END){
        //TODO
    }
    else if(address < HRAM_END){
        hram_read(address);
    }
    else if(address == 0xFFFF){
        return IE;
    }
    else{
        printf("Address out of range\n");
    }

    return 0;
}

void write_memory(uint16_t address, uint8_t value){
    if(address < ROM_END){
        //TODO
        printf("UNSUPPORTED\n");
    }
    else if(address < VRAM_END){
        //TODO
        printf("UNSUPPORTED\n");
    }
    else if(address < EXT_RAM_END){
        //TODO
        printf("UNSUPPORTED\n");
    }
    else if(address < WRAM_END){
        wram_write(address, value);
    }
    else if(address < ERAM_END){
        //TODO
        printf("ECHO RAM WRITE\n");
    }
    else if(address < OAM_END){
        //TODO
    }
    else if(address < UNUSABLE_END){
        //TODO
        printf("UNUSABLE MEMORY WRITE\n");
    }
    else if(address < IO_END){
        //TODO
        printf("UNSUPPORTED\n");
    }
    else if(address < HRAM_END){
        hram_write(address, value);
    }
    else if(address == 0xFFFF){
        IE = value;
    }
    else{
        printf("Address out of range\n");
    }
}

uint16_t double_read_memory(uint16_t address){
    return (((uint16_t) (read_memory(address))) + (((uint16_t) read_memory(address + 1)) << 8));
}

void double_write_memory(uint16_t address, uint16_t value){
    write_memory(address + 1, (uint8_t) ((value & 0xFF00) >> 8));
    write_memory(address, (uint8_t) (value & 0xFF));
}

uint8_t get_IF(){
    return read_memory(IF_ADDRESS);
}

void set_IF(uint8_t value)
{
    write_memory(IF_ADDRESS, value);
}

uint8_t pop()
{
    return read_memory(registers.SP++);
}

uint8_t pop16()
{
    return (pop() << 8) | pop();
}

void push(uint8_t value)
{
    write_memory(registers.SP--, value);
}

void push16(uint16_t value)
{
    push((value & 0xFF00) >> 8);
    push(value & 0x00FF);
}