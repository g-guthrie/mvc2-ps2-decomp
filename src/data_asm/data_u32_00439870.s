/*
 * data_u32_00439870: mixed unit.
 *   0x00439870..0x004398A0  last 0x30 bytes of the 0x80076000 image: (syscall, handler)
 *                           lookup table at runtime 0x80076710 (scanned by kpatch76).
 *   0x004398A0..0x004398C8  D_004398A0: 0x28-byte user-mode stub copied by func_0010D170
 *                           (func_0010D118, syscall 0x5A) to 0x00082000.
 *   0x004398C8..0x00439920  D_004398C8 SetSyscall table, saved-handler slots and the
 *                           "PsIIlibpad  2500" SDK version string (not copied).
 */

    .set noreorder
    .set noat
    .set nomacro

    .section .data
    .align 2
    .globl data_u32_00439870
    .type data_u32_00439870, @object
data_u32_00439870:
    .set stub82000_RT, 0x00082000

/* data: retail 0x00439870..0x004398A0 */
    .word 0x000000FC            /* 00439870 syscall number */
    .word 0x80076440            /* 00439874 handler 0x80076440 (runtime 0x80076710, scanned by code at 0x80076000) */
    .word 0x000000FE            /* 00439878 syscall number */
    .word 0x80076440            /* 0043987C handler 0x80076440 (runtime 0x80076718, scanned by code at 0x80076000) */
    .word 0x000000FD            /* 00439880 syscall number */
    .word 0x800762A0            /* 00439884 handler 0x800762A0 (runtime 0x80076720, scanned by code at 0x80076000) */
    .word 0x000000FF            /* 00439888 syscall number */
    .word 0x800762A0            /* 0043988C handler 0x800762A0 (runtime 0x80076728, scanned by code at 0x80076000) */
    .word 0x0000012C            /* 00439890 syscall number */
    .word 0x80076488            /* 00439894 handler 0x80076488 (runtime 0x80076730, scanned by code at 0x80076000) */
    .word 0x00000008            /* 00439898 syscall number */
    .word 0x800766C0            /* 0043989C handler 0x800766C0 (runtime 0x80076738, scanned by code at 0x80076000) */

/* code: retail 0x004398A0..0x004398C8, runs at 0x00082000..0x00082028 */
stub82000:
    lui $29,0x8                 /* 00082000 3C1D0008 */
    jalr $3                     /* 00082004 0060F809 */
    addiu $29,$29,8128          /* 00082008 27BD1FC0 */
    addiu $3,$0,-8              /* 0008200C 2403FFF8 */
    syscall                     /* 00082010 0000000C */
    nop                         /* 00082014 00000000 */
    nop                         /* 00082018 00000000 */
    nop                         /* 0008201C 00000000 */
    nop                         /* 00082020 00000000 */
    nop                         /* 00082024 00000000 */

/* data: retail 0x004398C8..0x00439920 */
    .word 0x0000005A            /* 004398C8 D_004398C8: SetSyscall table, syscall 0x5A */
    .word 0x0010D128            /* 004398CC -> func_0010D128 */
    .word 0x0000005B            /* 004398D0 syscall 0x5B */
    .word 0x80076000            /* 004398D4 -> 0x80076000 (kpatch76 entry) */
    .word 0x000000FC            /* 004398D8 saved-handler slots for syscalls 0xFC,0xFE,0xFD,0xFF,0x12C,0x08 (filled at runtime) */
    .word 0x00000000            /* 004398DC */
    .word 0x000000FE            /* 004398E0 */
    .word 0x00000000            /* 004398E4 */
    .word 0x000000FD            /* 004398E8 */
    .word 0x00000000            /* 004398EC */
    .word 0x000000FF            /* 004398F0 */
    .word 0x00000000            /* 004398F4 */
    .word 0x0000012C            /* 004398F8 */
    .word 0x00000000            /* 004398FC */
    .word 0x00000008            /* 00439900 */
    .word 0x00000000            /* 00439904 */
    .ascii "PsIIlibpad  2500"              /* 00439908, 16 bytes */
    .word 0x00000000            /* 00439918 */
    .word 0x00000001            /* 0043991C SDK module record tail */

    .size data_u32_00439870, . - data_u32_00439870
