#generation of these opcodes follwos teh "blocks" in the Pan Docs

u8_regs_read = [
    "registers.BC_reg.sub.B",
    "registers.BC_reg.sub.C",
    "registers.DE_reg.sub.D",
    "registers.DE_reg.sub.E",
    "registers.HL_reg.sub.H",
    "registers.HL_reg.sub.L",
    "read_memory(registers.HL_reg.HL)",
    "registers.AF_reg.sub.A",
]

u8_regs_write = [
    "registers.BC_reg.sub.B",
    "registers.BC_reg.sub.C",
    "registers.DE_reg.sub.D",
    "registers.DE_reg.sub.E",
    "registers.HL_reg.sub.H",
    "registers.HL_reg.sub.L",
    "write_memory(registers.HL_reg.HL)",
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

flags = {
    "c": "registers.AF_reg.sub.F_reg.flags.c",
    "h": "registers.AF_reg.sub.F_reg.flags.h",
    "z": "registers.AF_reg.sub.F_reg.flags.z",
    "n": "registers.AF_reg.sub.F_reg.flags.n",
}


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
        
def add_r16():
    const = 0b00001001
    for i in range(0, 4):
        print(f"case(0x{(const + (i<<4)):02X}):")
        print(f"    {flags['n']} = 0;")
        print(f"    {flags['c']} = tell_overflow(registers.HL_reg.HL, {u16_regs[i]}, 0, 15);")
        print(f"    {flags['h']} = tell_overflow(registers.HL_reg.HL, {u16_regs[i]}, 0, 11);")
        print(f"    registers.HL_reg.HL = registers.HL_reg.HL + {u16_regs[i]};")
        print(f"    return 8;")
        
def inc_r8():
    const = 0b00000100
    for i in range(0, 8):
        print(f"case(0x{(const + (i<<3)):02X}):")
        print(f"    {flags['n']} = 0;")
        print(f"    {flags['h']} = tell_overflow({u8_regs_read[i]}, {u8_regs_read[i]}, 0, 3);")
        print(f"    {u8_regs_write[i]}++;")
        print(f"    {flags['z']} = ({u8_regs_read[i]} == 0);")
        print(f"    return 4;")
        
def dec_r8():
    const = 0b00000101
    for i in range(0, 8):
        print(f"case(0x{(const + (i<<3)):02X}):")
        print(f"    {flags['n']} = 1;")
        print(f"    {flags['h']} = tell_borrow({u8_regs_read[i]}, {u8_regs_read[i]}, 4);")
        print(f"    {u8_regs_write[i]}--;")
        print(f"    {flags['z']} = ({u8_regs_read[i]} == 0);")
        print(f"    return 4;")
    
def ld_r8():
    const = 0b00000110
    for i in range(0, 8):
        print(f"case(0x{(const + (i<<3)):02X}):")
        print(f"    {u8_regs_write[i]} = imm8;")
        print(f"    return 8;")
        
def misc_block0():
    #RLCA
    print(f"case(0x07):")
    print(f"    {flags['n']} = 0;")
    print(f"    {flags['h']} = 0;")
    print(f"    {flags['z']} = 0;")
    print(f"    {flags['c']} = BIT({u8_regs_write[7]}, 7);")
    print(f"    {u8_regs_write[7]} = ({u8_regs_write[7]} << 1) | BIT({u8_regs_write[7]}, 7);")
    print(f"    return 4;")
    
    #RRCA
    print(f"case(0x0F):")
    print(f"    {flags['n']} = 0;")
    print(f"    {flags['h']} = 0;")
    print(f"    {flags['z']} = 0;")
    print(f"    {flags['c']} = BIT({u8_regs_write[7]}, 0);")
    print(f"    {u8_regs_write[7]} = ({u8_regs_write[7]} >> 1) | (BIT({u8_regs_write[7]}, 0) << 7);")
    print(f"    return 4;")
    
    #RLA
    print(f"case(0x17):")
    print(f"    uint8_t prev_carry = {flags['c']};")
    print(f"    {flags['n']} = 0;")
    print(f"    {flags['h']} = 0;")
    print(f"    {flags['z']} = 0;")
    print(f"    {flags['c']} = BIT({u8_regs_write[7]}, 7);")
    print(f"    {u8_regs_write[7]} = ({u8_regs_write[7]} << 1) | prev_carry;")
    print(f"    return 4;")
    
    #RRA
    print(f"case(0x1F):")
    print(f"    uint8_t prev_carry = {flags['c']};")
    print(f"    {flags['n']} = 0;")
    print(f"    {flags['h']} = 0;")
    print(f"    {flags['z']} = 0;")
    print(f"    {flags['c']} = BIT({u8_regs_write[7]}, 0);")
    print(f"    {u8_regs_write[7]} = ({u8_regs_write[7]} >> 1) | (prev_carry << 7);")
    print(f"    return 4;")
    
    #DAA
    print(f"case(0x27):")
    print(f"    {flags['h']} = 0;")
    print(f"    uint8_t adj = 0;")
    print(f"    if({flags['n']})")
    print(f"        adj += ({flags['h']}) ? 0x6 : 0;")
    print(f"        adj += ({flags['c']}) ? 0x60: 0;")
    print(f"        {u8_regs_write[7]} -= adj;")
    print(f"    else")
    print(f"        adj += ({flags['h']} || (({u8_regs_write[7]} & 0xF) > 0x9)) ? 0x6: 0;")
    print(f"        if({flags['c']} || {u8_regs_read[7]} > 0x99)")
    print(f"            adj += 0x60;")
    print(f"            {flags['c']} = 1;")
    print(f"        {u8_regs_write[7]} += adj;")
    print(f"    {flags['z']} = ({u8_regs_read[7]} == 0);")
    print(f"    return 4;")
    
    #CPL
    print(f"case(0x2F):")
    print(f"    {flags['h']} = 1;")
    print(f"    {flags['n']} = 1;")
    print(f"    {u8_regs_write[7]} = ~{u8_regs_write[7]};")
    print(f"    return 4;")
    
    #SCF
    print(f"case(0x37):")
    print(f"    {flags['h']} = 0;")
    print(f"    {flags['n']} = 0;")
    print(f"    {flags['c']} = 1;")
    print(f"    return 4;")
    
    #CCF
    print(f"case(0x3F):")
    print(f"    {flags['h']} = 0;")
    print(f"    {flags['n']} = 0;")
    print(f"    {flags['c']} = ~{flags['c']};")
    print(f"    return 4;")
  
def JR():
    #JR
    print(f"case(0x18):")
    print(f"    registers.PC += ((int8_t) imm8);")  
    print(f"    return 12;")
    
    #JRC
    const = 0b00100000
    for i in range(0, 4):
        print(f"case(0x{(const + (i<<3)):02X}):")
        print(f"    if({cond[i]})")
        print(f"    registers.PC += ((int8_t) imm8);")
        print(f"    return 12;")
        print(f"    return 8;")
    
    print(f"case(0x01):")
    print(f'    printf("STOP HIT\ n");')
    print(f"    return 0;")

def ld_r8_r8():
    const = 0b01000000
    for i in range(0, 64):
        print(f"case(0x{(const + (i<<0)):02X}):")
        print(f"    {u8_regs_write[(i & (0b111 << 3)) >> 3]} = {u8_regs_read[i & 0b111]};")
        print(f"    return 4;")

  
ld_r8_r8();