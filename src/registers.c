#include <stdint.h>


struct Registers{
    union {
        struct{
            union{
                uint8_t F;
                struct __PACKED {
                    uint8_t reserved : 4;
                    uint8_t c : 1;
                    uint8_t h : 1;
                    uint8_t n : 1;
                    uint8_t z : 1;
                } flags;
            } F_reg;
            uint8_t A;
        } sub;
        uint16_t AF;
    } AF_reg;

    union {
        struct{
            uint8_t C;
            uint8_t B;
        } sub;
        uint16_t BC;
    } BC_reg;

    union {
        struct{
            uint8_t E;
            uint8_t D;
        } sub;
        uint16_t DE;
    } DE_reg;

    union {
        struct{
            uint8_t L;
            uint8_t H;
        } sub;
        uint16_t HL;
    } HL_reg;

    uint16_t SP;
    uint16_t PC;
};

/*
int main(void){
    struct Registers registers;
    registers.PC = 150;
    printf("PC: %d\n", registers.PC);
    registers.BC_reg.sub.B = 0xFF;
    printf("BC: %x\n", registers.BC_reg.BC);
    registers.AF_reg.AF = 0;
    registers.AF_reg.sub.F_reg.flags.c = 1;
    printf("F: %b\n", registers.AF_reg.sub.F_reg.F);
    printf("AF: %b\n", registers.AF_reg.AF);

    return 0;
}*/