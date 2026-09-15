typedef unsigned char u8;

void func_0023E0B0(u8 *a0) {
    asm {
        lui at, 0x4F
        lui v1, 0x4255
        lwc1 f1, 0x1FC8(at)
        ori v1, v1, 0x5555
        mtc1 v1, f2
        lwc1 f0, 0x34(a0)
        add.s f1, f2, f1
        c.le.s f1, f0
        nop
        bc1t skip1
        swc1 f1, 0x34(a0)
skip1:
        lui at, 0x4F
        lui v1, 0x4255
        lwc1 f2, 0x1FCC(at)
        ori v1, v1, 0x5555
        mtc1 v1, f1
        lwc1 f0, 0x34(a0)
        sub.s f1, f2, f1
        c.lt.s f1, f0
        nop
        bc1f skip2
        swc1 f1, 0x34(a0)
skip2:
        jr ra
        nop
    }
}
