typedef unsigned char u8;

void func_001822B0(u8 *a0) {
    asm {
        lwc1 f1, 0x60(a0)
        mtc1 zero, f0
        nop
        .word 0x46000834
        nop
        .word 0x45000009
        lui v1, 0xC1AB
        ori v1, v1, 0x6DB6
        mtc1 v1, f0
        nop
        .word 0x46000834
        nop
        .word 0x45000002
        nop
        .word 0xe4800060
        .word 0x00000000
        jr ra
        nop
    }
}
