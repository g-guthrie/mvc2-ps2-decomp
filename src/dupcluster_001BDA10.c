typedef unsigned char u8;

void func_001BDA10(u8 *a0) {
    asm {
        lwc1 f2, 0x118(a0)
        lui v1, 0x3DCC
        ori v1, v1, 0xCCCD
        mtc1 v1, f1
        mtc1 zero, f0
        nop
        sub.s f1, f2, f1
        .word 0x46000836
        nop
        .word 0x45000005
        swc1 f1, 0x118(a0)
        lbu v1, 0x4(a0)
        addiu v1, v1, 1
        sb v1, 0x4(a0)
        sb zero, 0x13C(a0)
        .word 0x00000000
        jr ra
        nop
    }
}
