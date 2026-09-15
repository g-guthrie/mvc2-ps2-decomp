typedef unsigned char u8;

void func_00191F50(u8 *a0) {
    asm {
        lwc1 f1, 0x430(a0)
        lui v1, 0x4209
        ori v1, v1, 0x2492
        mtc1 v1, f0
        lwc1 f2, 0x38(a0)
        add.s f0, f0, f1
        c.le.s f2, f0
        nop
        .word 0x45000002
        nop
        swc1 f0, 0x38(a0)
        .word 0x00000000
        jr ra
        nop
    }
}
