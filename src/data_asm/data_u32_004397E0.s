/*
 * data_u32_004397E0: part of the 0x80076000 kernel-patch image (see
 * data_u32_004390C0); runs at 0x80076680. Installed by func_0010D170 via
 * func_0010D118 (syscall 0x5A, kernel Copy of D_00439160, 0x740 bytes).
 * Whole unit is code (exception-return helper using COP0 Status/EPC and eret);
 * the last two words are nop padding.
 */

    .set noreorder
    .set noat
    .set nomacro

    .section .data
    .align 2
    .globl data_u32_004397E0
    .type data_u32_004397E0, @object
data_u32_004397E0:
    .set kpatch76_eret_RT, 0x80076680

/* code: retail 0x004397E0..0x00439850, runs at 0x80076680..0x800766F0 */
kpatch76_eret:
    lui $26,0x8007              /* 80076680 3C1A8007 */
    sw $31,27712($26)           /* 80076684 AF5F6C40 */
    lui $26,0x8007              /* 80076688 3C1A8007 */
    sw $29,27728($26)           /* 8007668C AF5D6C50 */
    mtc0 $4,$14                 /* 80076690 40847000 */ /* cop0 epc */
    sync.p                      /* 80076694 0000040F */
    daddu $3,$5,$0              /* 80076698 00A0182D */
    daddu $4,$6,$0              /* 8007669C 00C0202D */
    daddu $5,$7,$0              /* 800766A0 00E0282D */
    daddu $6,$8,$0              /* 800766A4 0100302D */
    mfc0 $26,$12                /* 800766A8 401A6000 */ /* cop0 sr */
    ori $26,$26,0x12            /* 800766AC 375A0012 */
    mtc0 $26,$12                /* 800766B0 409A6000 */ /* cop0 sr */
    sync.p                      /* 800766B4 0000040F */
    eret                        /* 800766B8 42000018 */
    nop                         /* 800766BC 00000000 */
    mfc0 $1,$12                 /* 800766C0 40016000 */ /* cop0 sr */
    addiu $26,$0,-28            /* 800766C4 241AFFE4 */
    and $1,$1,$26               /* 800766C8 003A0824 */
    mtc0 $1,$12                 /* 800766CC 40816000 */ /* cop0 sr */
    sync.p                      /* 800766D0 0000040F */
    lui $26,0x8007              /* 800766D4 3C1A8007 */
    lw $31,27712($26)           /* 800766D8 8F5F6C40 */
    lui $26,0x8007              /* 800766DC 3C1A8007 */
    jr $31                      /* 800766E0 03E00008 */
    lw $29,27728($26)           /* 800766E4 8F5D6C50 */
    nop                         /* 800766E8 00000000 */
    nop                         /* 800766EC 00000000 */

    .size data_u32_004397E0, . - data_u32_004397E0
