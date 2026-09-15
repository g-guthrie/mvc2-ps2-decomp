typedef unsigned char u8;

extern void func_003AC020(u8 *);

void func_003ABFE0(u8 *a0) {
    asm {
        lw v1, 0x18(a0)
        lui v0, 0x3F0B
        ori v0, v0, 0x4924
        mtc1 v0, f0
        lw v0, 0x1DC(v1)
        lwc1 f2, 0x38(v1)
        lwc1 f1, 0x38(v0)
        add.s f0, f0, f2
        .word 0x46000836
        nop
        .word 0x45010002
        addiu v1, v0, 0x38
        .word 0xe4620000
        .word 0x00000000
    }
    func_003AC020(a0);
}
