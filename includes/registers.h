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

extern struct Registers registers;
extern uint8_t IME;