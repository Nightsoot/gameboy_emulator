#include "../includes/gameboy.h"

int tick = 0;
int opcode;
uint8_t imm8 = 0;
uint16_t imm16 = 0;


void startup()
{
    registers.PC = 0x100;
    registers.AF_reg.sub.A = 0x01;
}

int main(void)
{

    startup();
    cartridge_load("/home/david-rice/Downloads/gameboy_emulator/ROMs/03-op sp,hl.gb", &rom_data);

    while (!halted && tick < 200)
    {
        opcode = ROM[registers.PC];
        if (in_array(two_byte_instructions, opcode, 23))
        {
            imm8 = ROM[registers.PC + 1];
            registers.PC += 2;
        }
        else if(in_array(three_byte_instructions, opcode, 17)){
            imm16 = (ROM[registers.PC + 1] << 8) | (ROM[registers.PC + 2]);
            registers.PC += 3;
        }
        else{
            registers.PC += 1;
        }

        no_prefix_opcodes(opcode, imm16, imm8);
        print_opcode(opcode, imm16, imm8);
        printf("AF: %04X, BC: %04X, DE: %04X, HL: %04X, SP: %04X, PC: %04X\n", 
        registers.AF_reg.AF, registers.BC_reg.BC, registers.DE_reg.DE, registers.HL_reg.HL, registers.SP, registers.PC);
        tick++;
    }
}