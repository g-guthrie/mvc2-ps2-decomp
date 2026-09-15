typedef unsigned char u8;

void func_00278F50(u8 *a0) {
    asm {
        lwc1 f1, 0x118(a0)
        lui a1, 0x3D4C
        ori a1, a1, 0xCCCD
        lui v1, 0x3F80
        mtc1 a1, f0
        mtc1 v1, f2
        add.s f0, f1, f0
        .word 0x46020034
        nop
        .word 0x45010005
        swc1 f0, 0x118(a0)
        .word 0xe4820118
        lbu v1, 0x6(a0)
        addiu v1, v1, 1
        sb v1, 0x6(a0)
        .word 0x00000000
        jr ra
        nop
    }
}
