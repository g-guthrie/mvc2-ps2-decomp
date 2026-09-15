typedef unsigned char u8;

void func_003CD5A0(u8 *a0) {
    asm {
        lwc1 f3, 0x60(a0)
        lui v1, 0x3D4C
        lwc1 f2, 0x38(a0)
        ori v1, v1, 0xCCCD
        mtc1 v1, f1
        mtc1 zero, f0
        add.s f2, f2, f3
        swc1 f2, 0x38(a0)
        lwc1 f3, 0x6C(a0)
        lwc1 f2, 0x60(a0)
        add.s f2, f2, f3
        swc1 f2, 0x60(a0)
        lwc1 f2, 0x118(a0)
        sub.s f1, f2, f1
        c.lt.s f1, f0
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
