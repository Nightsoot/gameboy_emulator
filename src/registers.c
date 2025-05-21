#include <stdint.h>


struct registers{
    union {
        struct{
            uint8_t A;
            union{
                uint8_t F;
                struct __PACKED {
                    uint8_t z : 1;
                    uint8_t n : 1;
                    uint8_t h : 1;
                    uint8_t c : 1;
                    uint8_t reserved : 4;
                } flags;
            } F_reg;
        } sub;
        uint16_t AF;
    } AF_reg;

    union {
        struct{
            uint8_t B;
            uint8_t C;
        } sub;
        uint16_t BC;
    } BC_reg;

    union {
        struct{
            uint8_t D;
            uint8_t E;
        } sub;
        uint16_t DE;
    } DE_reg;

    uint16_t SP;
    uint16_t PC;
};