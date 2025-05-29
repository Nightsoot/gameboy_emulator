#include "../includes/gameboy.h"

int tick = 0;

uint8_t in_array(uint8_t *array, uint8_t target){
    for(int i=0; i<sizeof(array); i++){
        if(target == array[i]) return 1;
    }
    return 0;
}

int main(void){
    
}