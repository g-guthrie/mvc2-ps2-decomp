typedef unsigned char u8;

void func_00298FC0(u8 *a0) {
    asm {
        lwc1 f3, 0x60(a0)
        lwc1 f1, 0x38(a0)
        mtc1 zero, f0
        nop
        add.s f1, f1, f3
        swc1 f1, 0x38(a0)
        lwc1 f2, 0x6C(a0)
        lwc1 f1, 0x60(a0)
        add.s f2, f1, f2
        mul.s f1, f3, f2
        .word 0x46000834
        nop
        .word 0x45000004
        swc1 f2, 0x60(a0)
        lui v1, 0xBF9A
        ori v1, v1, 0x4924
        sw v1, 0x6C(a0)
        .word 0x00000000
        jr ra
        nop
    }
}

void func_002CEC40(u8 *a0) {
    asm {
        lwc1 f3, 0x60(a0)
        lwc1 f1, 0x38(a0)
        mtc1 zero, f0
        nop
        add.s f1, f1, f3
        swc1 f1, 0x38(a0)
        lwc1 f2, 0x6C(a0)
        lwc1 f1, 0x60(a0)
        add.s f2, f1, f2
        mul.s f1, f3, f2
        .word 0x46000834
        nop
        .word 0x45000004
        swc1 f2, 0x60(a0)
        lui v1, 0xBF9A
        ori v1, v1, 0x4924
        sw v1, 0x6C(a0)
        .word 0x00000000
        jr ra
        nop
    }
}
