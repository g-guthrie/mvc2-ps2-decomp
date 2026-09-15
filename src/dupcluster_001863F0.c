typedef unsigned char u8;

void func_001863F0(u8 *a0) {
    asm {
        lwc1 f2, 0x68(a0)
        mtc1 zero, f1
        nop
        .word 0x46011032
        nop
        .word 0x45010009
        nop
        lwc1 f0, 0x5C(a0)
        mul.s f0, f2, f0
        .word 0x46010036
        nop
        .word 0x45010003
        nop
        .word 0xe4810068
        .word 0xe481005c
        .word 0x00000000
        jr ra
        nop
    }
}
