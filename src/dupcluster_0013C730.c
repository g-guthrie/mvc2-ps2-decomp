typedef unsigned char u8;
typedef signed int s32;

s32 func_0013C730(u8 *a0, u8 *a1) {
    asm {
        lw a1, 0x44(a1)
        lui v0, 0x4663
        lw v1, 0x44(a0)
        ori v0, v0, 0x9000
        mtc1 v0, f0
        addu v0, a1, v1
        mtc1 v0, f1
        nop
        cvt.s.w f1, f1
        c.le.s f1, f0
        nop
        .word 0x4501000c
        .word 0x0000102d
        lui v0, 0x4747
        ori v0, v0, 0x1C00
        mtc1 v0, f0
        nop
        c.lt.s f1, f0
        nop
        .word 0x45000003
        addiu v0, zero, 1
        .word 0x10000002
        nop
        .word 0x0000102d
        .word 0x00000000
        jr ra
        nop
    }
}
