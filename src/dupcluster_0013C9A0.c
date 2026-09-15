typedef unsigned char u8;

void func_0013C9A0(u8 *a0) {
    asm {
        lwc1 f1, 0x74(a0)
        lui v1, 0x3D4C
        ori v1, v1, 0xCCCD
        mtc1 v1, f0
        mtc1 zero, f2
        sub.s f0, f1, f0
        c.le.s f0, f2
        nop
        .word 0x45000006
        swc1 f0, 0x74(a0)
        lbu v1, 0x4(a0)
        addiu v1, v1, 1
        sb v1, 0x4(a0)
        .word 0xe4820074
        sb zero, 0x13C(a0)
        .word 0x00000000
        jr ra
        nop
    }
}
