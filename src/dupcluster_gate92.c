typedef unsigned char u8;

void func_00229040(u8 *a0) {
    asm {
        lwc1 f1, 0x5C(a0)
        addiu a1, a0, 0x5C
        lwc1 f0, 0x34(a0)
        mtc1 zero, f2
        add.s f0, f0, f1
        swc1 f0, 0x34(a0)
        lwc1 f1, 0x68(a0)
        lwc1 f0, 0x5C(a0)
        add.s f1, f0, f1
        swc1 f1, 0x5C(a0)
        lwc1 f0, 0x68(a0)
        mul.s f0, f1, f0
        c.le.s f0, f2
        nop
        .word 0x45010006
        .word 0x24860068
        .word 0x90830006
        .word 0x24630001
        .word 0xa0830006
        .word 0xe4a20000
        .word 0xe4c20000
        .word 0x00000000
        jr ra
        nop
    }
}
