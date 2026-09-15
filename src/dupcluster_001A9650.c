typedef unsigned char u8;
typedef signed int s32;

s32 func_001A9650(u8 *a0) {
    asm {
        .word 0xc4820038
        .word 0x0000102d
        .word 0xc4830060
        .word 0x00000000
        .word 0xc481006c
        .word 0x44800000
        .word 0x46031080
        .word 0x460118c0
        .word 0x46001836
        .word 0x00000000
        .word 0x4500fffb
        .word 0x24420001
        .word 0x460c1036
        .word 0x00000000
        .word 0x4500fff7
        .word 0x00000000
        .word 0x00000000
        jr ra
        nop
    }
}
