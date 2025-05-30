opcode_names = []

with open("/home/david-rice/Downloads/gameboy_emulator/scripts/opcodes.txt", "r") as f:
    lines = f.readlines()[0:1682]
    for line in lines:
        if(line[0:3] == "def"):
            opcode_names.append(line[4:line.find("(")])
           
def list_to_C_array_string(l):
    print(f"[{len(l)}]" +" = {", end="")
    for i in range(len(l)):
        print('"' + l[i] + '"', end=",")
    print("};")

def fill_in_gaps(l):

    nums = []
    for op in l:
        number = int(op[len(op)-2: len(op)],16)
        nums.append(number)
   
    prev_number = 0
    for num in nums:
        if(num - prev_number > 1):
            for j in range(0, num-prev_number-1):
                l.insert(prev_number+1,"BAD")
        prev_number = num
    
    
fill_in_gaps(opcode_names)
list_to_C_array_string(opcode_names)