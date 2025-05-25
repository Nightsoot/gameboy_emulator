#generation of these opcodes follwos teh "blocks" in the Pan Docs

u8_regs_read = [
    "registers.BC_reg.sub.B",
    "registers.BC_reg.sub.C",
    "registers.DE_reg.sub.D",
    "registers.DE_reg.sub.E",
    "registers.HL_reg.sub.H",
    "registers.HL_reg.sub.L",
    "write_memory(registers.HL_reg.HL)",
    "registers.AF_reg.sub.A",
]

u8_regs_write = [
    "registers.BC_reg.sub.B",
    "registers.BC_reg.sub.C",
    "registers.DE_reg.sub.D",
    "registers.DE_reg.sub.E",
    "registers.HL_reg.sub.H",
    "registers.HL_reg.sub.L",
    "read_memory(registers.HL_reg.HL)",
    "registers.AF_reg.sub.A",
]

u16_regs = [
    "registers.BC_reg.BC",
    "registers.DE_reg.DE",
    "registers.HL_reg.HL",
    "registers.SP",
]

u16_stack_regs = [
    "registers.BC_reg.BC",
    "registers.DE_reg.DE",
    "registers.HL_reg.HL",
    "registers.AF_reg.AF",
]

u16_mem_regs_read = [
    "read_memory(registers.BC_reg.BC)",
    "read_memory(registers.DE_reg.DE)",
    "read_memory(registers.HL_reg.HL++)",
    "read_memory(registers.HL_reg.HL--)",
]

u16_mem_regs_write = [
    "write_memory(registers.BC_reg.BC",
    "write_memory(registers.DE_reg.DE",
    "write_memory(registers.HL_reg.HL++",
    "write_memory(registers.HL_reg.HL--",
]

cond = [
    "!(registers.AF_reg.sub.F_reg.flags.z)",
    "(registers.AF_reg.sub.F_reg.flags.z)",
    "!(registers.AF_reg.sub.F_reg.flags.c)",
    "(registers.AF_reg.sub.F_reg.flags.c)",
]


def ld_ops():
    const = 0b00000001
    #ld with r16
    for i in range(0, 4):
        print(f"case(0x{(const + (i<<4)):02X}):")
        print(f"    {u16_regs[i]} = imm16;")
        print(f"    return 12;")
        
    const = 0b00000010
    #ld with mem_r16 and A
    for i in range(0, 4):
        print(f"case(0x{(const + (i<<4)):02X}):")
        print(f"    {u16_mem_regs_write[i]},{u8_regs_read[7]});")
        print(f"    return 12;")
        
    const = 0b00001010
    #ld with mem_r16 and A
    for i in range(0, 4):
        print(f"case(0x{(const + (i<<4)):02X}):")
        print(f"    {u8_regs_write[7]} = {u16_mem_regs_read[i]};")
        print(f"    return 8;")
        
    #special case
    print(f"case(0x08):")
    print(f"    write_memory(imm16, registers.SP);")
    print(f"    return 20;")
        
        
def inc_r16():
    const = 0b00000011
    for i in range(0, 4):
        print(f"case(0x{(const + (i<<4)):02X}):")
        print(f"    {u16_regs[i]}++;")
        print(f"    return 8;")
        
def dec_r16():
    const = 0b00001001
    for i in range(0, 4):
        print(f"case(0x{(const + (i<<4)):02X}):")
        print(f"    {u16_regs[i]}--;")
        print(f"    return 8;")
        
ld_ops();