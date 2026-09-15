typedef unsigned char u8;

void func_001C4C30(u8 *a0) {
    asm {
        lwc1 f2, 0x5C(a0)
        lwc1 f1, 0x34(a0)
        mtc1 zero, f0
        nop
        add.s f1, f1, f2
        swc1 f1, 0x34(a0)
        lwc1 f2, 0x68(a0)
        lwc1 f1, 0x5C(a0)
        add.s f1, f1, f2
        swc1 f1, 0x5C(a0)
        lwc1 f2, 0x60(a0)
        lwc1 f1, 0x38(a0)
        add.s f1, f1, f2
        swc1 f1, 0x38(a0)
        lwc1 f2, 0x6C(a0)
        lwc1 f1, 0x60(a0)
        add.s f1, f1, f2
        c.le.s f1, f0
        nop
        .word 0x45000004
        swc1 f1, 0x60(a0)
        lbu v1, 0x5(a0)
        addiu v1, v1, 1
        sb v1, 0x5(a0)
        .word 0x00000000
        jr ra
        nop
    }
}
