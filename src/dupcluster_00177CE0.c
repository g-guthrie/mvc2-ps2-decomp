typedef unsigned char u8;

void func_00177CE0(u8 *a0) {
    asm {
        lui at, 0x4F
        lui v1, 0x43A0
        lwc1 f0, 0x1F4C(at)
        .word 0x3c05004f
        mtc1 v1, f2
        lwc1 f1, 0x34(a0)
        lui v1, 0x430C
        mtc1 v1, f3
        nop
        sub.s f0, f0, f2
        sub.s f0, f0, f3
        c.le.s f1, f0
        nop
        .word 0x45000003
        addiu a1, a1, 0x1F40
        .word 0x10000009
        sb zero, 0x13C(a0)
        lwc1 f0, 0xC(a1)
        add.s f0, f2, f0
        add.s f0, f3, f0
        c.lt.s f1, f0
        nop
        .word 0x45010002
        nop
        sb zero, 0x13C(a0)
        .word 0x00000000
        jr ra
        nop
    }
}
