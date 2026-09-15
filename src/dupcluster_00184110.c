typedef unsigned char u8;
typedef signed int s32;

s32 func_00184110(u8 *a0) {
    asm {
        .word 0x8c820220
        .word 0xc4800034
        .word 0xc4410034
        .word 0x46000841
        .word 0x46016034
        .word 0x00000000
        .word 0x45010007
        .word 0x24020001
        .word 0x46006007
        .word 0x46010036
        .word 0x00000000
        .word 0x45010002
        .word 0x0000102d
        .word 0x24020001
        .word 0x00000000
        jr ra
        nop
    }
}
