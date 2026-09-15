typedef unsigned char u8;

void func_00316940(u8 *a0) {
    asm {
        lwc1 f2, 0x430(a0)
        lui v1, 0x4409
        ori v1, v1, 0x2492
        mtc1 v1, f1
        lwc1 f0, 0x38(a0)
        add.s f1, f1, f2
        .word 0x46000834
        nop
        .word 0x45000002
        nop
        swc1 f1, 0x38(a0)
        .word 0x00000000
        jr ra
        nop
    }
}
