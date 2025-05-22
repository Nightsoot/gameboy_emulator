#include "../includes/memory_tools.h"

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
        //TODO
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
        //TODO
    }
    else if(address == 0xFFFF){
        //TODO
    }
    else{
        printf("Address out of range\n");
    }

    return 0;
}

void write_memory(uint16_t address, uint8_t value){
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
        //TODO
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
    }
    else if(address < HRAM_END){
        //TODO
    }
    else if(address == 0xFFFF){
        //TODO
    }
    else{
        printf("Address out of range\n");
    }

    return 0;
}

uint16_t double_read_memory(uint16_t address){
    return (((uint16_t) (read_memory(address))) + (((uint16_t) read_memory(address + 1)) << 8));
}

void double_write_memory(uint16_t address, uint16_t value){
    write_memory(address + 1, (uint8_t) ((value & 0xFF00) >> 8));
    write_memory(address, (uint8_t) (value & 0xFF));
}

