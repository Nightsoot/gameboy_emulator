#include "../includes/cartridge.h"

//ROM can be variable size
uint8_t *cart_RAM;
uint8_t *ROM;
int ROM_size;
char* title;
struct ROM_data rom_data;

//reference arrays from Low Level Devel
static const char *ROM_TYPES[] = {
    "ROM ONLY",
    "MBC1",
    "MBC1+RAM",
    "MBC1+RAM+BATTERY",
    "0x04 ???",
    "MBC2",
    "MBC2+BATTERY",
    "0x07 ???",
    "ROM+RAM 1",
    "ROM+RAM+BATTERY 1",
    "0x0A ???",
    "MMM01",
    "MMM01+RAM",
    "MMM01+RAM+BATTERY",
    "0x0E ???",
    "MBC3+TIMER+BATTERY",
    "MBC3+TIMER+RAM+BATTERY 2",
    "MBC3",
    "MBC3+RAM 2",
    "MBC3+RAM+BATTERY 2",
    "0x14 ???",
    "0x15 ???",
    "0x16 ???",
    "0x17 ???",
    "0x18 ???",
    "MBC5",
    "MBC5+RAM",
    "MBC5+RAM+BATTERY",
    "MBC5+RUMBLE",
    "MBC5+RUMBLE+RAM",
    "MBC5+RUMBLE+RAM+BATTERY",
    "0x1F ???",
    "MBC6",
    "0x21 ???",
    "MBC7+SENSOR+RUMBLE+RAM+BATTERY",
};

static const char *LIC_CODE[0xA5] = {
    [0x00] = "None",
    [0x01] = "Nintendo R&D1",
    [0x08] = "Capcom",
    [0x13] = "Electronic Arts",
    [0x18] = "Hudson Soft",
    [0x19] = "b-ai",
    [0x20] = "kss",
    [0x22] = "pow",
    [0x24] = "PCM Complete",
    [0x25] = "san-x",
    [0x28] = "Kemco Japan",
    [0x29] = "seta",
    [0x30] = "Viacom",
    [0x31] = "Nintendo",
    [0x32] = "Bandai",
    [0x33] = "Ocean/Acclaim",
    [0x34] = "Konami",
    [0x35] = "Hector",
    [0x37] = "Taito",
    [0x38] = "Hudson",
    [0x39] = "Banpresto",
    [0x41] = "Ubi Soft",
    [0x42] = "Atlus",
    [0x44] = "Malibu",
    [0x46] = "angel",
    [0x47] = "Bullet-Proof",
    [0x49] = "irem",
    [0x50] = "Absolute",
    [0x51] = "Acclaim",
    [0x52] = "Activision",
    [0x53] = "American sammy",
    [0x54] = "Konami",
    [0x55] = "Hi tech entertainment",
    [0x56] = "LJN",
    [0x57] = "Matchbox",
    [0x58] = "Mattel",
    [0x59] = "Milton Bradley",
    [0x60] = "Titus",
    [0x61] = "Virgin",
    [0x64] = "LucasArts",
    [0x67] = "Ocean",
    [0x69] = "Electronic Arts",
    [0x70] = "Infogrames",
    [0x71] = "Interplay",
    [0x72] = "Broderbund",
    [0x73] = "sculptured",
    [0x75] = "sci",
    [0x78] = "THQ",
    [0x79] = "Accolade",
    [0x80] = "misawa",
    [0x83] = "lozc",
    [0x86] = "Tokuma Shoten Intermedia",
    [0x87] = "Tsukuda Original",
    [0x91] = "Chunsoft",
    [0x92] = "Video system",
    [0x93] = "Ocean/Acclaim",
    [0x95] = "Varie",
    [0x96] = "Yonezawa/s'pal",
    [0x97] = "Kaneko",
    [0x99] = "Pack in soft",
    [0xA4] = "Konami (Yu-Gi-Oh!)"
};

const char *cart_lic_name(struct ROM_data *rom_data) {
    if (rom_data->new_lic_code <= 0xA4) {
        return LIC_CODE[rom_data->lic_code];
    }

    return "UNKNOWN";
}

const char *cart_type_name(struct ROM_data *rom_data) {
    if (rom_data->type <= 0x22) {
        return ROM_TYPES[rom_data->type];
    }

    return "UNKNOWN";
}


uint8_t read_cartridge(char* filename, struct ROM_data *rom_data){

    FILE * file_pointer = fopen(filename, "r");

    if(file_pointer == NULL){
        printf("Failed to open file\n");
        return 255;
    }
    else{
        printf("Opened: %s\n", filename);
    }

    fseek(file_pointer, 0, SEEK_END);
    ROM_size = ftell(file_pointer);
    rewind(file_pointer);

    ROM = (uint8_t *) malloc(ROM_size);
    fread(ROM, ROM_size, 1, file_pointer);
    fclose(file_pointer);

    rom_data = (struct ROM_data *)(ROM + 0x100);
    rom_data->title[15] = 0;
    printf("f: %d\n", ROM[0x101]);

    printf("Cartridge Loaded:\n");
    printf("\t Title    : %s\n", rom_data->title);
    printf("\t Type     : %2.2X (%s)\n", rom_data->type, cart_type_name(rom_data));
    printf("\t ROM Size : %d KB\n", 32 << rom_data->rom_size);
    printf("\t RAM Size : %2.2X\n", rom_data->ram_size);
    printf("\t LIC Code : %2.2X (%s)\n", rom_data->lic_code, cart_lic_name(rom_data));
    printf("\t ROM Vers : %2.2X\n", rom_data->version);

    uint16_t x = 0;
    for (uint16_t i=0x0134; i<=0x014C; i++) {
        x = x - ROM[i] - 1;
    }

    printf("\t Checksum : %2.2X (%s)\n", rom_data->checksum, (x & 0xFF) ? "PASSED" : "FAILED");

    return 1;
}

// int main(void){
//     // read_cartridge("/home/david-rice/Downloads/gameboy_emulator/ROMs/01-special.gb", &rom_data);
//     // read_cartridge("/home/david-rice/Downloads/gameboy_emulator/ROMs/Pokemon - Red Version (USA, Europe) (SGB Enhanced).gb", &rom_data);
//     read_cartridge("/home/david-rice/Downloads/gameboy_emulator/ROMs/dmg-acid2.gb", &rom_data);
//     printf("%d\n", rom_data.rom_size);
//     for (int i = 0x134; i <= 0x14F; i++) {
//     printf("ROM[%x] = 0x%x\n", i, ROM[i]);
// }
// }