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

two_byte_instructions = []
three_byte_instructions = []


def ld_ops():
    const = 0b00000001
    #ld with r16
    for i in range(0, 4):
        print(f"case(0x{(const + (i<<4)):02X}):")
        three_byte_instructions.append(f"0x{(const + (i<<4)):02X}")
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
    three_byte_instructions.append(f"0x08")
    print(f"    return 20;")
        
        
def inc_r16():
    const = 0b00000011
    for i in range(0, 4):
        print(f"case(0x{(const + (i<<4)):02X}):")
        print(f"    {u16_regs[i]}++;")
        print(f"    return 8;")
        
def dec_r16():
    const = 0b00001011
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
        two_byte_instructions.append(f"0x{(const + (i<<3)):02X}")
        
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
    #This one is very weird
    print(f"case(0x27):")
    print(f"    {flags['h']} = 0;")
    print(f"    uint8_t adj = 0;")
    print(f"    if({flags['n']})" + "{")
    print(f"        adj += ({flags['h']}) ? 0x6 : 0;")
    print(f"        adj += ({flags['c']}) ? 0x60: 0;")
    print(f"        {u8_regs_write[7]} -= adj;")
    print("     }")
    print(f"    else" + "{")
    print(f"        adj += ({flags['h']} || (({u8_regs_write[7]} & 0xF) > 0x9)) ? 0x6: 0;")
    print(f"        if({flags['c']} || {u8_regs_read[7]} > 0x99)" + "{")
    print(f"            adj += 0x60;")
    print(f"            {flags['c']} = 1;")
    print("         }")
    print(f"        {u8_regs_write[7]} += adj;")
    print("     }")
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
    two_byte_instructions.append(f"0x18")
    print(f"    return 12;")
    
    #JRC
    const = 0b00100000
    for i in range(0, 4):
        print(f"case(0x{(const + (i<<3)):02X}):")
        print(f"    if({cond[i]})" + "{")
        print(f"    registers.PC += ((int8_t) imm8);")
        print(f"    return 12;" + "\n}")
        print(f"    return 8;")
        two_byte_instructions.append(f"0x{(const + (i<<3)):02X}")
    
    print(f"case(0x01):")
    print(f'    printf("STOP HIT");')
    print(f"    return 0;")

def ld_r8_r8():
    const = 0b01000000
    for i in range(0, 64):
        print(f"case(0x{(const + (i<<0)):02X}):")
        print(f"    {u8_regs_write[(i & (0b111 << 3)) >> 3]} = {u8_regs_read[i & 0b111]};")
        print(f"    return 4;")

def arithmetic():
    const = 0b10000000
    # ADD A r8
    for i in range(0, 8):
        print(f"case(0x{(const + (i<<0)):02X}):")
        print(f"    {flags['n']} = 0;")
        print(f"    {flags['h']} = tell_overflow({u8_regs_read[7]}, {u8_regs_read[i]}, 0, 3);")
        print(f"    {flags['c']} = tell_overflow({u8_regs_read[7]}, {u8_regs_read[i]}, 0, 7);")
        print(f"    {u8_regs_write[7]} += {u8_regs_read[i]};")
        print(f"    {flags['z']} = ({u8_regs_write[7]} == 0);")
        print(f"    return 4;")
        
    const = 0b10001000
    # ADC A r8
    for i in range(0, 8):
        print(f"case(0x{(const + (i<<0)):02X}):")
        print(f"    uint8_t prev_carry = {flags['c']};")
        print(f"    {flags['n']} = 0;")
        print(f"    {flags['h']} = tell_overflow({u8_regs_read[7]}, {u8_regs_read[i]}, prev_carry, 3);")
        print(f"    {flags['c']} = tell_overflow({u8_regs_read[7]}, {u8_regs_read[i]}, prev_carry, 7);")
        print(f"    {u8_regs_write[7]} += {u8_regs_read[i]} + prev_carry;")
        print(f"    {flags['z']} = ({u8_regs_write[7]} == 0);")
        print(f"    return 4;")
        
    const = 0b10010000
    # SUB A r8
    for i in range(0, 8):
        print(f"case(0x{(const + (i<<0)):02X}):")
        print(f"    {flags['n']} = 1;")
        print(f"    {flags['h']} = tell_borrow({u8_regs_read[7]}, {u8_regs_read[i]}, 4);")
        print(f"    {flags['c']} = ({u8_regs_read[7]} < {u8_regs_read[i]});")
        print(f"    {u8_regs_write[7]} -= {u8_regs_read[i]};")
        print(f"    {flags['z']} = ({u8_regs_write[7]} == 0);")
        print(f"    return 4;")
        
    const = 0b10011000
    # SBC A r8
    for i in range(0, 8):
        print(f"case(0x{(const + (i<<0)):02X}):")
        print(f"    uint8_t prev_carry = {flags['c']};")
        print(f"    {flags['n']} = 1;")
        print(f"    {flags['h']} = tell_borrow({u8_regs_read[7]}, {u8_regs_read[i]} +, prev_carry, 4);")
        print(f"    {flags['c']} = ({u8_regs_read[7]} < ({u8_regs_read[i]} + prev_carry));")
        print(f"    {u8_regs_write[7]} -= ({u8_regs_read[i]} + prev_carry);")
        print(f"    {flags['z']} = ({u8_regs_write[7]} == 0);")
        print(f"    return 4;")
        
    const = 0b10100000
    # AND A r8
    for i in range(0, 8):
        print(f"case(0x{(const + (i<<0)):02X}):")
        print(f"    {flags['n']} = 0;")
        print(f"    {flags['h']} = 1;")
        print(f"    {flags['c']} = 0;")
        print(f"    {u8_regs_write[7]} &= {u8_regs_read[i]};")
        print(f"    {flags['z']} = ({u8_regs_write[7]} == 0);")
        print(f"    return 4;")
        
    const = 0b10101000
    # XOR A r8
    for i in range(0, 8):
        print(f"case(0x{(const + (i<<0)):02X}):")
        print(f"    {flags['n']} = 0;")
        print(f"    {flags['h']} = 0;")
        print(f"    {flags['c']} = 0;")
        print(f"    {u8_regs_write[7]} ^= {u8_regs_read[i]};")
        print(f"    {flags['z']} = ({u8_regs_write[7]} == 0);")
        print(f"    return 4;")
        
    const = 0b10110000
    # OR A r8
    for i in range(0, 8):
        print(f"case(0x{(const + (i<<0)):02X}):")
        print(f"    {flags['n']} = 0;")
        print(f"    {flags['h']} = 0;")
        print(f"    {flags['c']} = 0;")
        print(f"    {u8_regs_write[7]} |= {u8_regs_read[i]};")
        print(f"    {flags['z']} = ({u8_regs_write[7]} == 0);")
        print(f"    return 4;")
        
    const = 0b10111000
    # CP A r8
    for i in range(0, 8):
        print(f"case(0x{(const + (i<<0)):02X}):")
        print(f"    {flags['n']} = 1;")
        print(f"    {flags['h']} = tell_borrow({u8_regs_read[7]}, {u8_regs_read[i]}, 4);")
        print(f"    {flags['c']} = {u8_regs_read[7]} < {u8_regs_read[i]}")
        print(f"    {flags['z']} = ({u8_regs_write[7]} == {u8_regs_read[i]});")
        print(f"    return 4;")

    print(f"case(0xC6):")
    print(f"    {flags['n']} = 0;")
    print(f"    {flags['h']} = tell_overflow({u8_regs_read[7]}, imm8, 0, 3);")
    print(f"    {flags['c']} = tell_overflow({u8_regs_read[7]}, imm8, 0, 7);")
    print(f"    {u8_regs_write[7]} += imm8;")
    print(f"    {flags['z']} = ({u8_regs_write[7]} == 0);")
    print(f"    return 8;")
    two_byte_instructions.append(f"0xC6")
    
    print(f"case(0xCE):")
    print(f"    uint8_t prev_carry = {flags['c']};")
    print(f"    {flags['n']} = 0;")
    print(f"    {flags['h']} = tell_overflow({u8_regs_read[7]}, imm8, prev_carry, 3);")
    print(f"    {flags['c']} = tell_overflow({u8_regs_read[7]}, imm8, prev_carry, 7);")
    print(f"    {u8_regs_write[7]} += imm8 + prev_carry;")
    print(f"    {flags['z']} = ({u8_regs_write[7]} == 0);")
    print(f"    return 8;")
    two_byte_instructions.append(f"0xCE")
     
    print(f"case(0xD6):")
    print(f"    {flags['n']} = 1;")
    print(f"    {flags['h']} = tell_borrow({u8_regs_read[7]}, imm8, 4);")
    print(f"    {flags['c']} = ({u8_regs_read[7]} < imm8);")
    print(f"    {u8_regs_write[7]} -= imm8;")
    print(f"    {flags['z']} = ({u8_regs_write[7]} == 0);")
    print(f"    return 8;")
    two_byte_instructions.append(f"0xD6")
    
    print(f"case(0xDE):")
    print(f"    uint8_t prev_carry = {flags['c']};")
    print(f"    {flags['n']} = 1;")
    print(f"    {flags['h']} = tell_borrow({u8_regs_read[7]}, imm8 +, prev_carry, 4);")
    print(f"    {flags['c']} = ({u8_regs_read[7]} < (imm8 + prev_carry));")
    print(f"    {u8_regs_write[7]} -= (imm8 + prev_carry);")
    print(f"    {flags['z']} = ({u8_regs_write[7]} == 0);")
    print(f"    return 8;")
    two_byte_instructions.append(f"0xDE")
    
    print(f"case(0xE6):")
    print(f"    {flags['n']} = 0;")
    print(f"    {flags['h']} = 1;")
    print(f"    {flags['c']} = 0;")
    print(f"    {u8_regs_write[7]} &= imm8;")
    print(f"    {flags['z']} = ({u8_regs_write[7]} == 0);")
    print(f"    return 8;")
    two_byte_instructions.append(f"0xE6")
    
    print(f"case(0xEE):")
    print(f"    {flags['n']} = 0;")
    print(f"    {flags['h']} = 0;")
    print(f"    {flags['c']} = 0;")
    print(f"    {u8_regs_write[7]} ^= imm8;")
    print(f"    {flags['z']} = ({u8_regs_write[7]} == 0);")
    print(f"    return 8;")
    two_byte_instructions.append(f"0xEE")
    
    print(f"case(0xF6):")
    print(f"    {flags['n']} = 0;")
    print(f"    {flags['h']} = 0;")
    print(f"    {flags['c']} = 0;")
    print(f"    {u8_regs_write[7]} |= imm8;")
    print(f"    {flags['z']} = ({u8_regs_write[7]} == 0);")
    print(f"    return 8;")
    two_byte_instructions.append(f"0xF6")
    
    print(f"case(0xFE):")
    print(f"    {flags['n']} = 1;")
    print(f"    {flags['h']} = tell_borrow({u8_regs_read[7]}, imm8, 4);")
    print(f"    {flags['c']} = {u8_regs_read[7]} < imm8;")
    print(f"    {flags['z']} = ({u8_regs_write[7]} == imm8);")
    print(f"    return 8;")
    two_byte_instructions.append(f"0xFE")
    
def control_flow():
    const = 0b11000000
    
    for i in range(0, 4):
        print(f"case(0x{(const + (i<<3)):02X}):")
        print(f"    if({cond[i]})" + "{")
        print(f"        registers.PC = pop16();")
        print(f"        return 20;" + "\n}")
        print(f"    return 8;")

    print(f"case(0xC9):")
    print(f"    registers.PC = pop16();")
    print(f"    return 16;")
    
    print(f"case(0xD9):")
    print(f"    registers.PC = pop16();")
    print(f"    IME = 1;")
    print(f"    return 16;")
    
    const = 0b11000010
    
    for i in range(0, 4):
        print(f"case(0x{(const + (i<<3)):02X}):")
        print(f"    if({cond[i]})" + "{")
        print(f"        registers.PC = imm16;")
        print(f"        return 16;" + "\n}")
        print(f"    return 12;")
        three_byte_instructions.append(f"0x{(const + (i<<3)):02X}")
        
    print(f"case(0xC3):")
    print(f"    registers.PC = imm16;")
    three_byte_instructions.append(f"0xC3")
    print(f"    return 12;")
    
    print(f"case(0xE9):")
    print(f"    registers.PC = registers.HL_reg.HL;")
    print(f"    return 4;")
    
    const = 0b11000100
    
    for i in range(0, 4):
        print(f"case(0x{(const + (i<<3)):02X}):")
        print(f"    if({cond[i]})" + "{")
        print(f"        push16(registers.PC);")
        print(f"        registers.PC = imm16;")
        three_byte_instructions.append(f"0x{(const + (i<<3)):02X}")
        print(f"        return 24;" + "\n}")
        print(f"    return 12;")

    print(f"case(0xCD):")
    print(f"    push16(registers.PC);")
    print(f"    registers.PC = imm16;")
    print(f"    return 24;")
    three_byte_instructions.append(f"0xCD")
    
    const = 0b11000111 
    
    for i in range(0, 8):
        print(f"case(0x{(const + (i<<3)):02X}):")
        print(f"    push16(registers.PC);")
        print(f"    registers.PC = {i*8};")
        print(f"    return 16;")

    const = 0b11000001
    
    for i in range(0, 4):
        print(f"case(0x{(const + (i<<4)):02X}):")
        print(f"    {u16_stack_regs[i]} = pop16();")
        print(f"    return 16;")
        
    const = 0b11000101
    
    for i in range(0, 4):
        print(f"case(0x{(const + (i<<4)):02X}):")
        print(f"    push16({u16_stack_regs[i]});")
        print(f"    return 16;")
        
def other_block3():
    print(f"case(0xE2):")
    print(f"    write_memory({u8_regs_read[1]} + 0xFF00, {u8_regs_read[7]});")
    print(f"    return 8;")
    
    print(f"case(0xE0):")
    print(f"    write_memory(imm8 + 0xFF00, {u8_regs_read[7]});")
    print(f"    return 12;")
    
    print(f"case(0xEA):")
    print(f"    write_memory(imm16, {u8_regs_read[7]});")
    print(f"    return 16;")
    three_byte_instructions.append(f"0xEA")
    
    print(f"case(0xF2):")
    print(f"    {u8_regs_read[7]} = read_memory({u8_regs_read[1]} + 0xFF00);")
    print(f"    return 8;")
    
    print(f"case(0xF0):")
    print(f"    {u8_regs_read[7]} = read_memory(imm8 + 0xFF00);")
    print(f"    return 8;")
    
    print(f"case(0xFA):")
    print(f"    {u8_regs_read[7]} = read_memory(imm16);")
    print(f"    return 8;")
    three_byte_instructions.append(f"0xFA")
    
    print(f"case(0xE8):")
    print(f"    {flags['n']} = 0;")
    print(f"    {flags['h']} = tell_overflow(registers.SP, imm8, 0, 3);")
    print(f"    {flags['c']} = tell_overflow(registers.SP, imm8, 0, 7);")
    print(f"    registers.SP += (int8_t) imm8;")
    print(f"    {flags['z']} = 0;")
    print(f"    return 16;")
    two_byte_instructions.append(f"0xE8")
    
    print(f"case(0xF8):")
    print(f"    {flags['n']} = 0;")
    print(f"    {flags['h']} = tell_overflow(registers.SP, imm8, 0, 3);")
    print(f"    {flags['c']} = tell_overflow(registers.SP, imm8, 0, 7);")
    print(f"    registers.HL = (registers.SP + ((int8_t) imm8));")
    print(f"    {flags['z']} = 0;")
    print(f"    return 16;")
    two_byte_instructions.append(f"0xF8")
    
    print(f"case(0xF9):")
    print(f"    registers.SP = registers.HL;")
    print(f"    return 8;")
  
    print(f"case(0xF3):")
    print(f"    IME = 0;")
    print(f"    return 4;")
    
    print(f"case(0xFB):")
    print(f"    IME = 1;")
    print(f"    return 4;")
  
# control_flow();

def everything1():
    ld_ops()
    inc_r16()
    dec_r16()
    add_r16()
    inc_r8()
    dec_r8()
    ld_r8()
    
def everything2():
    misc_block0()
    JR()
    ld_r8_r8()
    arithmetic()
    control_flow()
    other_block3()
    
def list_to_C_array(l):
    print(f"[{len(l)}]" +" = {", end="")
    for i in range(len(l)):
        print(l[i], end=",")
    print("};")
    
everything1()
everything2()

list_to_C_array(three_byte_instructions)