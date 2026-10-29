/* newlib libc/machine/r5900 MMI routines: memchr, memcmp, memcpy, memmove,
 * memset, strcat, strcmp, strcpy, strlen, strncat, strncmp, strncpy.
 *
 * Hand-written assembly in the original executable (no compiler emits
 * these instruction sequences). Transcribed from the retail instruction
 * stream; assembled with GNU as 2.10-ee-001003-1 and verified byte for byte. */
.set noreorder
.set noat

.section .text.func_0011D5C8,"ax",@progbits
.align 2
.globl func_0011D5C8
.ent func_0011D5C8
func_0011D5C8:
    sltiu      $2, $6, 0x10
    bnez       $2, .L0011D668
    andi      $5, $5, 0xFF
    andi       $2, $4, 0xF
    bnez       $2, .L0011D668
    daddu     $7, $4, $0
    dsll       $3, $5, 8
    lui        $2, (0x1010101 >> 16)
    ori        $2, $2, (0x1010101 & 0xFFFF)
    dsll       $2, $2, 16
    ori        $2, $2, 0x101
    dsll       $2, $2, 16
    ori        $2, $2, 0x101
    daddu      $10, $3, $5
    lui        $3, (0x80808080 >> 16)
    ori        $3, $3, (0x80808080 & 0xFFFF)
    dsll       $3, $3, 16
    ori        $3, $3, 0x8080
    dsll       $3, $3, 16
    ori        $3, $3, 0x8080
    pcpyh      $8, $10
    pcpyld     $9, $8, $8
    daddu      $4, $2, $0
    pcpyld     $8, $3, $3
.L0011D628:
    lq         $2, 0x0($7)
    pxor       $2, $2, $9
    pcpyld     $10, $4, $4
    pnor       $3, $0, $2
    psubb      $2, $2, $10
    pand       $2, $2, $3
    pand       $2, $2, $8
    pcpyud     $3, $2, $9
    or         $2, $2, $3
    bnel       $2, $0, .L0011D668
    daddu     $4, $7, $0
    addiu      $6, $6, -0x10
    sltiu      $2, $6, 0x10
    beqz       $2, .L0011D628
    addiu     $7, $7, 0x10
    daddu      $4, $7, $0
.L0011D668:
    lui        $2, (0xFFFFFFFF >> 16)
    addiu      $6, $6, -0x1
    ori        $2, $2, (0xFFFFFFFF & 0xFFFF)
    beq        $6, $2, .L0011D698
    nop
    lui        $3, (0xFFFFFFFF >> 16)
    ori        $3, $3, (0xFFFFFFFF & 0xFFFF)
.L0011D684:
    lbu        $2, 0x0($4)
    beq        $2, $5, .L0011D6A0
    addiu     $6, $6, -0x1
    bne        $6, $3, .L0011D684
    addiu     $4, $4, 0x1
.L0011D698:
    jr         $31
    daddu     $2, $0, $0
.L0011D6A0:
    jr         $31
    daddu     $2, $4, $0
.end func_0011D5C8

.section .text.func_0011D6A8,"ax",@progbits
.align 2
.globl func_0011D6A8
.ent func_0011D6A8
func_0011D6A8:
    sltiu      $2, $6, 0x10
    bnez       $2, .L0011D6F4
    or        $2, $4, $5
    andi       $2, $2, 0xF
    bnez       $2, .L0011D6F4
    nop
.L0011D6C0:
    lq         $3, 0x0($4)
    sltiu      $7, $6, 0x20
    lq         $2, 0x0($5)
    addiu      $4, $4, 0x10
    pxor       $8, $2, $3
    addiu      $2, $5, 0x10
    pcpyud     $10, $8, $7
    or         $9, $10, $8
    movz       $5, $2, $9
    bnel       $9, $0, .L0011D6F4
    addiu     $4, $4, -0x10
    beqz       $7, .L0011D6C0
    addiu     $6, $6, -0x10
.L0011D6F4:
    lui        $2, (0xFFFFFFFF >> 16)
    addiu      $6, $6, -0x1
    ori        $2, $2, (0xFFFFFFFF & 0xFFFF)
    beq        $6, $2, .L0011D734
    nop
    lui        $7, (0xFFFFFFFF >> 16)
    ori        $7, $7, (0xFFFFFFFF & 0xFFFF)
.L0011D710:
    lbu        $3, 0x0($4)
    lbu        $2, 0x0($5)
    beq        $3, $2, .L0011D728
    addiu     $4, $4, 0x1
    jr         $31
    subu      $2, $3, $2
.L0011D728:
    addiu      $6, $6, -0x1
    bne        $6, $7, .L0011D710
    addiu     $5, $5, 0x1
.L0011D734:
    jr         $31
    daddu     $2, $0, $0
.end func_0011D6A8

.section .text.func_0011D740,"ax",@progbits
.align 2
.globl func_0011D740
.ent func_0011D740
func_0011D740:
    daddu      $8, $4, $0
    sltiu      $2, $6, 0x20
    bnez       $2, .L0011D7BC
    daddu     $3, $8, $0
    or         $2, $5, $8
    andi       $2, $2, 0xF
    bnel       $2, $0, .L0011D7C0
    addiu     $6, $6, -0x1
    daddu      $7, $8, $0
.L0011D764:
    lq         $3, 0x0($5)
    addiu      $6, $6, -0x20
    addiu      $5, $5, 0x10
    sltiu      $4, $6, 0x20
    sq         $3, 0x0($7)
    addiu      $7, $7, 0x10
    lq         $2, 0x0($5)
    addiu      $5, $5, 0x10
    sq         $2, 0x0($7)
    beqz       $4, .L0011D764
    addiu     $7, $7, 0x10
    sltiu      $2, $6, 0x8
    bnez       $2, .L0011D7BC
    daddu     $3, $7, $0
.L0011D79C:
    ld         $3, 0x0($5)
    addiu      $6, $6, -0x8
    addiu      $5, $5, 0x8
    sltiu      $2, $6, 0x8
    sd         $3, 0x0($7)
    beqz       $2, .L0011D79C
    addiu     $7, $7, 0x8
    daddu      $3, $7, $0
.L0011D7BC:
    addiu      $6, $6, -0x1
.L0011D7C0:
    addiu      $2, $0, -0x1
    beq        $6, $2, .L0011D7E8
    daddu     $4, $2, $0
.L0011D7CC:
    lbu        $2, 0x0($5)
    addiu      $6, $6, -0x1
    addiu      $5, $5, 0x1
    sb         $2, 0x0($3)
    addiu      $3, $3, 0x1
    bne        $6, $4, .L0011D7CC
    nop
.L0011D7E8:
    jr         $31
    daddu     $2, $8, $0
.end func_0011D740

.section .text.func_0011D7F0,"ax",@progbits
.align 2
.globl func_0011D7F0
.ent func_0011D7F0
func_0011D7F0:
    daddu      $8, $4, $0
    sltu       $2, $5, $8
    beqz       $2, .L0011D848
    daddu     $3, $8, $0
    addu       $7, $5, $6
    sltu       $2, $8, $7
    beqz       $2, .L0011D848
    addiu     $2, $0, -0x1
    addu       $3, $8, $6
    addiu      $6, $6, -0x1
    beq        $6, $2, .L0011D8EC
    daddu     $5, $7, $0
    daddu      $4, $2, $0
.L0011D824:
    addiu      $5, $5, -0x1
    addiu      $3, $3, -0x1
    lbu        $2, 0x0($5)
    addiu      $6, $6, -0x1
    sb         $2, 0x0($3)
    bne        $6, $4, .L0011D824
    nop
    jr         $31
    daddu     $2, $8, $0
.L0011D848:
    sltiu      $2, $6, 0x20
    bnel       $2, $0, .L0011D8C4
    addiu     $6, $6, -0x1
    or         $2, $5, $3
    andi       $2, $2, 0xF
    bnel       $2, $0, .L0011D8C4
    addiu     $6, $6, -0x1
    daddu      $7, $3, $0
.L0011D868:
    lq         $3, 0x0($5)
    addiu      $6, $6, -0x20
    addiu      $5, $5, 0x10
    sltiu      $4, $6, 0x20
    sq         $3, 0x0($7)
    addiu      $7, $7, 0x10
    lq         $2, 0x0($5)
    addiu      $5, $5, 0x10
    sq         $2, 0x0($7)
    beqz       $4, .L0011D868
    addiu     $7, $7, 0x10
    sltiu      $2, $6, 0x8
    bnez       $2, .L0011D8C0
    daddu     $3, $7, $0
.L0011D8A0:
    ld         $3, 0x0($5)
    addiu      $6, $6, -0x8
    addiu      $5, $5, 0x8
    sltiu      $2, $6, 0x8
    sd         $3, 0x0($7)
    beqz       $2, .L0011D8A0
    addiu     $7, $7, 0x8
    daddu      $3, $7, $0
.L0011D8C0:
    addiu      $6, $6, -0x1
.L0011D8C4:
    addiu      $2, $0, -0x1
    beq        $6, $2, .L0011D8EC
    daddu     $4, $2, $0
.L0011D8D0:
    lbu        $2, 0x0($5)
    addiu      $6, $6, -0x1
    addiu      $5, $5, 0x1
    sb         $2, 0x0($3)
    addiu      $3, $3, 0x1
    bne        $6, $4, .L0011D8D0
    nop
.L0011D8EC:
    jr         $31
    daddu     $2, $8, $0
.end func_0011D7F0

.section .text.func_0011D8F8,"ax",@progbits
.align 2
.globl func_0011D8F8
.ent func_0011D8F8
func_0011D8F8:
    sltiu      $2, $6, 0x8
    bnez       $2, .L0011D978
    daddu     $3, $4, $0
    andi       $2, $4, 0xF
    bnez       $2, .L0011D978
    daddu     $7, $4, $0
    andi       $9, $5, 0xFF
    sltiu      $10, $6, 0x20
    daddu      $8, $9, $0
    dsll       $3, $8, 8
    or         $8, $3, $9
    pcpyh      $3, $8
    bnez       $10, .L0011D964
    sltiu     $2, $6, 0x8
    pcpyld     $8, $3, $3
.L0011D934:
    sq         $8, 0x0($7)
    addiu      $6, $6, -0x20
    addiu      $7, $7, 0x10
    sltiu      $2, $6, 0x20
    sq         $8, 0x0($7)
    beqz       $2, .L0011D934
    addiu     $7, $7, 0x10
    b          .L0011D964
    sltiu     $2, $6, 0x8
.L0011D958:
    addiu      $6, $6, -0x8
    addiu      $7, $7, 0x8
    sltiu      $2, $6, 0x8
.L0011D964:
    nop
    nop
    beql       $2, $0, .L0011D958
    sd        $3, 0x0($7)
    daddu      $3, $7, $0
.L0011D978:
    lui        $2, (0xFFFFFFFF >> 16)
    addiu      $6, $6, -0x1
    ori        $2, $2, (0xFFFFFFFF & 0xFFFF)
    beq        $6, $2, .L0011D9B0
    nop
    lui        $2, (0xFFFFFFFF >> 16)
    ori        $2, $2, (0xFFFFFFFF & 0xFFFF)
.L0011D994:
    sb         $5, 0x0($3)
    addiu      $6, $6, -0x1
    addiu      $3, $3, 0x1
    nop
    nop
    bne        $6, $2, .L0011D994
    nop
.L0011D9B0:
    jr         $31
    daddu     $2, $4, $0
.end func_0011D8F8

.section .text.func_0011FC10,"ax",@progbits
.align 2
.globl func_0011FC10
.ent func_0011FC10
func_0011FC10:
    addiu      $29, $29, -0x20
    sq         $16, 0x0($29)
    daddu      $16, $4, $0
    andi       $2, $16, 0x7
    bnez       $2, .L0011FD04
    sq        $31, 0x10($29)
    andi       $2, $16, 0xF
    lui        $3, (0x1010101 >> 16)
    ori        $3, $3, (0x1010101 & 0xFFFF)
    dsll       $3, $3, 16
    ori        $3, $3, 0x101
    dsll       $3, $3, 16
    ori        $3, $3, 0x101
    lui        $4, (0x80808080 >> 16)
    ori        $4, $4, (0x80808080 & 0xFFFF)
    dsll       $4, $4, 16
    ori        $4, $4, 0x8080
    dsll       $4, $4, 16
    ori        $4, $4, 0x8080
    bnez       $2, .L0011FCC0
    ld        $6, 0x0($16)
    lq         $2, 0x0($16)
    pcpyld     $7, $3, $3
    pcpyld     $8, $4, $4
    psubb      $3, $2, $7
    pnor       $2, $0, $2
    pand       $3, $3, $2
    pand       $3, $3, $8
    pcpyud     $2, $3, $3
    or         $3, $2, $3
    bnez       $3, .L0011FD04
    daddu     $4, $16, $0
    addiu      $6, $4, 0x10
.L0011FC94:
    lq         $2, 0x0($6)
    pnor       $3, $0, $2
    psubb      $2, $2, $7
    pand       $2, $2, $3
    pand       $2, $2, $8
    pcpyud     $3, $2, $2
    or         $2, $2, $3
    beql       $2, $0, .L0011FC94
    addiu     $6, $6, 0x10
    b          .L0011FD04
    daddu     $4, $6, $0
.L0011FCC0:
    daddu      $7, $3, $0
    daddu      $8, $4, $0
    dsubu      $3, $6, $3
    nor        $2, $0, $6
    and        $3, $3, $2
    and        $3, $3, $4
    bnez       $3, .L0011FD04
    daddu     $4, $16, $0
    addiu      $6, $16, 0x8
.L0011FCE4:
    ld         $2, 0x0($6)
    nor        $3, $0, $2
    dsubu      $2, $2, $7
    and        $2, $2, $3
    and        $2, $2, $8
    beql       $2, $0, .L0011FCE4
    addiu     $6, $6, 0x8
    daddu      $4, $6, $0
.L0011FD04:
    lb         $2, 0x0($4)
    nop
    nop
    nop
    nop
    bnel       $2, $0, .L0011FD04
    addiu     $4, $4, 0x1
    jal        func_0011FE88
    nop
    daddu      $2, $16, $0
    lq         $31, 0x10($29)
    lq         $16, 0x0($29)
    jr         $31
    addiu     $29, $29, 0x20
.end func_0011FC10

.section .text.func_0011FD40,"ax",@progbits
.align 2
.globl func_0011FD40
.ent func_0011FD40
func_0011FD40:
    or         $8, $4, $5
    andi       $2, $8, 0x7
    bnel       $2, $0, .L0011FE70
    lb        $2, 0x0($4)
    andi       $9, $8, 0xF
    lui        $7, (0x1010101 >> 16)
    ori        $7, $7, (0x1010101 & 0xFFFF)
    dsll       $7, $7, 16
    ori        $7, $7, 0x101
    dsll       $7, $7, 16
    ori        $7, $7, 0x101
    lui        $6, (0x80808080 >> 16)
    ori        $6, $6, (0x80808080 & 0xFFFF)
    dsll       $6, $6, 16
    ori        $6, $6, 0x8080
    dsll       $6, $6, 16
    ori        $6, $6, 0x8080
    bnez       $9, .L0011FE04
    ld        $2, 0x0($5)
    lq         $3, 0x0($4)
    pcpyld     $8, $7, $7
    lq         $2, 0x0($5)
    pcpyld     $10, $6, $6
    psubw      $7, $2, $3
    pcpyud     $6, $7, $4
    or         $3, $6, $7
    bnel       $3, $0, .L0011FE70
    lb        $2, 0x0($4)
    lq         $2, 0x0($4)
    pnor       $3, $0, $2
.L0011FDB8:
    psubb      $2, $2, $8
    pand       $2, $2, $3
    pand       $2, $2, $10
    pcpyud     $3, $2, $4
    or         $6, $3, $2
    beqz       $6, .L0011FDDC
    addiu     $4, $4, 0x10
    jr         $31
    daddu     $2, $0, $0
.L0011FDDC:
    addiu      $5, $5, 0x10
    lq         $2, 0x0($4)
    lq         $3, 0x0($5)
    psubw      $7, $2, $3
    pcpyud     $6, $7, $4
    or         $9, $6, $7
    beql       $9, $0, .L0011FDB8
    pnor      $3, $0, $2
    b          .L0011FE70
    lb        $2, 0x0($4)
.L0011FE04:
    ld         $3, 0x0($4)
    bnel       $3, $2, .L0011FE70
    lb        $2, 0x0($4)
    ld         $2, 0x0($4)
    nor        $8, $0, $2
.L0011FE18:
    dsubu      $2, $2, $7
    and        $2, $2, $8
    and        $2, $2, $6
    beqz       $2, .L0011FE34
    addiu     $4, $4, 0x8
    jr         $31
    daddu     $2, $0, $0
.L0011FE34:
    addiu      $5, $5, 0x8
    ld         $2, 0x0($4)
    ld         $3, 0x0($5)
    beql       $3, $2, .L0011FE18
    nor       $8, $0, $2
    b          .L0011FE70
    lb        $2, 0x0($4)
.L0011FE50:
    sll        $2, $3, 24
    lb         $3, 0x0($5)
    sra        $2, $2, 24
    bnel       $2, $3, .L0011FE78
    lbu       $3, 0x0($4)
    addiu      $4, $4, 0x1
    addiu      $5, $5, 0x1
    lb         $2, 0x0($4)
.L0011FE70:
    bnez       $2, .L0011FE50
    lbu       $3, 0x0($4)
.L0011FE78:
    lbu        $2, 0x0($5)
    jr         $31
    subu      $2, $3, $2
.end func_0011FD40

.section .text.func_0011FE88,"ax",@progbits
.align 2
.globl func_0011FE88
.ent func_0011FE88
func_0011FE88:
    daddu      $7, $4, $0
    or         $8, $5, $7
    andi       $2, $8, 0x7
    bnez       $2, .L0011FF78
    daddu     $3, $7, $0
    andi       $2, $8, 0xF
    lui        $9, (0x1010101 >> 16)
    ori        $9, $9, (0x1010101 & 0xFFFF)
    dsll       $9, $9, 16
    ori        $9, $9, 0x101
    dsll       $9, $9, 16
    ori        $9, $9, 0x101
    lui        $4, (0x80808080 >> 16)
    ori        $4, $4, (0x80808080 & 0xFFFF)
    dsll       $4, $4, 16
    ori        $4, $4, 0x8080
    dsll       $4, $4, 16
    ori        $4, $4, 0x8080
    bnel       $2, $0, .L0011FF38
    ld        $10, 0x0($5)
    pcpyld     $10, $9, $9
    lq         $9, 0x0($5)
    pcpyld     $8, $4, $4
    psubb      $2, $9, $10
    pnor       $3, $0, $9
    pand       $2, $2, $3
    pand       $2, $2, $8
    pcpyud     $4, $2, $9
    or         $3, $2, $4
    bnez       $3, .L0011FF74
    daddu     $6, $7, $0
.L0011FF04:
    sq         $9, 0x0($6)
    addiu      $5, $5, 0x10
    lq         $9, 0x0($5)
    psubb      $2, $9, $10
    pnor       $3, $0, $9
    pand       $2, $2, $3
    pand       $2, $2, $8
    pcpyud     $4, $2, $9
    or         $3, $2, $4
    beqz       $3, .L0011FF04
    addiu     $6, $6, 0x10
    b          .L0011FF78
    daddu     $3, $6, $0
.L0011FF38:
    dsubu      $2, $10, $9
    nor        $3, $0, $10
    and        $2, $2, $3
    and        $2, $2, $4
    bnez       $2, .L0011FF74
    daddu     $6, $7, $0
.L0011FF50:
    sd         $10, 0x0($6)
    addiu      $5, $5, 0x8
    ld         $10, 0x0($5)
    nor        $2, $0, $10
    dsubu      $3, $10, $9
    and        $3, $3, $2
    and        $3, $3, $4
    beqz       $3, .L0011FF50
    addiu     $6, $6, 0x8
.L0011FF74:
    daddu      $3, $6, $0
.L0011FF78:
    lbu        $2, 0x0($5)
    addiu      $5, $5, 0x1
    sb         $2, 0x0($3)
    sll        $2, $2, 24
    addiu      $3, $3, 0x1
    bnez       $2, .L0011FF78
    nop
    jr         $31
    daddu     $2, $7, $0
.end func_0011FE88

.section .text.func_0011FFA0,"ax",@progbits
.align 2
.globl func_0011FFA0
.ent func_0011FFA0
func_0011FFA0:
    andi       $2, $4, 0x7
    bnez       $2, .L001200B4
    daddu     $7, $4, $0
    andi       $3, $4, 0xF
    lui        $2, (0x1010101 >> 16)
    ori        $2, $2, (0x1010101 & 0xFFFF)
    dsll       $2, $2, 16
    ori        $2, $2, 0x101
    dsll       $2, $2, 16
    ori        $2, $2, 0x101
    bnez       $3, .L00120044
    daddu     $5, $4, $0
    lq         $3, 0x0($5)
    pcpyld     $8, $2, $2
    lui        $4, (0x80808080 >> 16)
    ori        $4, $4, (0x80808080 & 0xFFFF)
    dsll       $4, $4, 16
    ori        $4, $4, 0x8080
    dsll       $4, $4, 16
    ori        $4, $4, 0x8080
    psubb      $2, $3, $8
    pnor       $3, $0, $3
    pcpyld     $9, $4, $4
    pand       $2, $2, $3
    pand       $2, $2, $9
    pcpyud     $3, $2, $8
    or         $6, $3, $2
    bnel       $6, $0, .L001200B4
    daddu     $4, $5, $0
    addiu      $5, $5, 0x10
.L00120018:
    lq         $2, 0x0($5)
    pnor       $3, $0, $2
    psubb      $2, $2, $8
    pand       $2, $2, $3
    pand       $4, $2, $9
    pcpyud     $3, $4, $6
    or         $3, $3, $4
    beql       $3, $0, .L00120018
    addiu     $5, $5, 0x10
    b          .L001200B4
    daddu     $4, $5, $0
.L00120044:
    ld         $3, 0x0($5)
    lui        $4, (0x80808080 >> 16)
    ori        $4, $4, (0x80808080 & 0xFFFF)
    dsll       $4, $4, 16
    ori        $4, $4, 0x8080
    dsll       $4, $4, 16
    ori        $4, $4, 0x8080
    dsubu      $2, $3, $2
    nor        $3, $0, $3
    and        $2, $2, $3
    and        $2, $2, $4
    bnel       $2, $0, .L001200B4
    daddu     $4, $5, $0
    lui        $6, (0x1010101 >> 16)
    ori        $6, $6, (0x1010101 & 0xFFFF)
    dsll       $6, $6, 16
    ori        $6, $6, 0x101
    dsll       $6, $6, 16
    ori        $6, $6, 0x101
    addiu      $5, $5, 0x8
.L00120094:
    ld         $2, 0x0($5)
    nor        $3, $0, $2
    dsubu      $2, $2, $6
    and        $2, $2, $3
    and        $2, $2, $4
    beql       $2, $0, .L00120094
    addiu     $5, $5, 0x8
    daddu      $4, $5, $0
.L001200B4:
    lb         $2, 0x0($4)
    nop
    nop
    nop
    nop
    bnel       $2, $0, .L001200B4
    addiu     $4, $4, 0x1
    jr         $31
    subu      $2, $4, $7
.end func_0011FFA0

.section .text.func_001200D8,"ax",@progbits
.align 2
.globl func_001200D8
.ent func_001200D8
func_001200D8:
    daddu      $8, $4, $0
    andi       $2, $8, 0x7
    bnel       $2, $0, .L001201F4
    lb        $2, 0x0($4)
    andi       $3, $8, 0xF
    bnel       $3, $0, .L00120184
    ld        $2, 0x0($8)
    lui        $7, (0x1010101 >> 16)
    ori        $7, $7, (0x1010101 & 0xFFFF)
    dsll       $7, $7, 16
    ori        $7, $7, 0x101
    dsll       $7, $7, 16
    ori        $7, $7, 0x101
    lq         $2, 0x0($8)
    pcpyld     $9, $7, $7
    lui        $4, (0x80808080 >> 16)
    ori        $4, $4, (0x80808080 & 0xFFFF)
    dsll       $4, $4, 16
    ori        $4, $4, 0x8080
    dsll       $4, $4, 16
    ori        $4, $4, 0x8080
    psubb      $3, $2, $9
    pnor       $2, $0, $2
    pcpyld     $10, $4, $4
    pand       $3, $3, $2
    pand       $3, $3, $10
    pcpyud     $2, $3, $4
    or         $3, $3, $2
    bnez       $3, .L001201EC
    daddu     $7, $8, $0
    addiu      $7, $7, 0x10
    nop
.L00120158:
    lq         $2, 0x0($7)
    pnor       $3, $0, $2
    psubb      $2, $2, $9
    pand       $2, $2, $3
    pand       $2, $2, $10
    pcpyud     $3, $2, $4
    or         $2, $2, $3
    beqz       $2, .L00120158
    addiu     $7, $7, 0x10
    b          .L001201EC
    addiu     $7, $7, -0x10
.L00120184:
    lui        $9, (0x1010101 >> 16)
    ori        $9, $9, (0x1010101 & 0xFFFF)
    dsll       $9, $9, 16
    ori        $9, $9, 0x101
    dsll       $9, $9, 16
    ori        $9, $9, 0x101
    lui        $4, (0x80808080 >> 16)
    ori        $4, $4, (0x80808080 & 0xFFFF)
    dsll       $4, $4, 16
    ori        $4, $4, 0x8080
    dsll       $4, $4, 16
    ori        $4, $4, 0x8080
    dsubu      $3, $2, $9
    nor        $2, $0, $2
    and        $3, $3, $2
    and        $3, $3, $4
    bnez       $3, .L001201EC
    daddu     $7, $8, $0
    addiu      $7, $7, 0x8
.L001201D0:
    ld         $2, 0x0($7)
    nor        $3, $0, $2
    dsubu      $2, $2, $9
    and        $2, $2, $3
    and        $2, $2, $4
    beql       $2, $0, .L001201D0
    addiu     $7, $7, 0x8
.L001201EC:
    daddu      $4, $7, $0
    lb         $2, 0x0($4)
.L001201F4:
    beqz       $2, .L0012021C
    addiu     $6, $6, -0x1
    addiu      $4, $4, 0x1
.L00120200:
    lb         $2, 0x0($4)
    nop
    nop
    nop
    nop
    bnel       $2, $0, .L00120200
    addiu     $4, $4, 0x1
.L0012021C:
    lui        $2, (0xFFFFFFFF >> 16)
    ori        $2, $2, (0xFFFFFFFF & 0xFFFF)
    beq        $6, $2, .L0012027C
    nop
    lbu        $2, 0x0($5)
    addiu      $5, $5, 0x1
    sb         $2, 0x0($4)
    sll        $2, $2, 24
    beqz       $2, .L0012027C
    addiu     $4, $4, 0x1
    lui        $3, (0xFFFFFFFF >> 16)
    ori        $3, $3, (0xFFFFFFFF & 0xFFFF)
    nop
.L00120250:
    beql       $6, $0, .L00120258
    sb        $0, 0x0($4)
.L00120258:
    addiu      $6, $6, -0x1
    beq        $6, $3, .L0012027C
    nop
    lbu        $2, 0x0($5)
    addiu      $5, $5, 0x1
    sb         $2, 0x0($4)
    sll        $2, $2, 24
    bnez       $2, .L00120250
    addiu     $4, $4, 0x1
.L0012027C:
    jr         $31
    daddu     $2, $8, $0
.end func_001200D8

.section .text.func_00120288,"ax",@progbits
.align 2
.globl func_00120288
.ent func_00120288
func_00120288:
    bnez       $6, .L00120298
    or        $3, $4, $5
.L00120290:
    jr         $31
    daddu     $2, $0, $0
.L00120298:
    andi       $2, $3, 0x7
    bnez       $2, .L001203F4
    daddu     $2, $6, $0
    andi       $2, $3, 0xF
    sltiu      $7, $6, 0x10
    lui        $9, (0x1010101 >> 16)
    ori        $9, $9, (0x1010101 & 0xFFFF)
    dsll       $9, $9, 16
    ori        $9, $9, 0x101
    dsll       $9, $9, 16
    ori        $9, $9, 0x101
    or         $2, $2, $7
    bnez       $2, .L00120370
    daddu     $7, $4, $0
    lq         $3, 0x0($4)
    pcpyld     $10, $9, $9
    lq         $2, 0x0($5)
    lui        $8, (0x80808080 >> 16)
    ori        $8, $8, (0x80808080 & 0xFFFF)
    dsll       $8, $8, 16
    ori        $8, $8, 0x8080
    dsll       $8, $8, 16
    ori        $8, $8, 0x8080
    psubw      $3, $3, $2
    pcpyld     $9, $8, $8
    pcpyud     $2, $3, $4
    daddu      $8, $5, $0
    or         $3, $2, $3
    bnez       $3, .L001203F4
    daddu     $2, $6, $0
    addiu      $6, $6, -0x10
.L00120314:
    beqz       $6, .L00120290
    nop
    lq         $2, 0x0($7)
    pnor       $3, $0, $2
    psubb      $2, $2, $10
    pand       $2, $2, $3
    pand       $3, $2, $9
    pcpyud     $2, $3, $4
    or         $2, $2, $3
    bnez       $2, .L00120290
    addiu     $7, $7, 0x10
    sltiu      $2, $6, 0x10
    lq         $3, 0x0($7)
    bnez       $2, .L001203E8
    addiu     $8, $8, 0x10
    lq         $2, 0x0($8)
    psubw      $3, $3, $2
    pcpyud     $2, $3, $4
    or         $2, $2, $3
    beql       $2, $0, .L00120314
    addiu     $6, $6, -0x10
    b          .L001203EC
    daddu     $4, $7, $0
.L00120370:
    sltiu      $2, $6, 0x8
    bnez       $2, .L001203E8
    daddu     $8, $5, $0
    ld         $3, 0x0($4)
    ld         $2, 0x0($5)
    bne        $3, $2, .L001203F4
    daddu     $2, $6, $0
    addiu      $6, $6, -0x8
    lui        $10, (0x80808080 >> 16)
    ori        $10, $10, (0x80808080 & 0xFFFF)
    dsll       $10, $10, 16
    ori        $10, $10, 0x8080
    dsll       $10, $10, 16
    ori        $10, $10, 0x8080
.L001203A8:
    beqz       $6, .L00120290
    nop
    ld         $2, 0x0($7)
    nor        $3, $0, $2
    dsubu      $2, $2, $9
    and        $2, $2, $3
    and        $2, $2, $10
    bnez       $2, .L00120290
    addiu     $7, $7, 0x8
    sltiu      $2, $6, 0x8
    bnez       $2, .L001203E8
    addiu     $8, $8, 0x8
    ld         $3, 0x0($7)
    ld         $2, 0x0($8)
    beql       $3, $2, .L001203A8
    addiu     $6, $6, -0x8
.L001203E8:
    daddu      $4, $7, $0
.L001203EC:
    daddu      $5, $8, $0
    daddu      $2, $6, $0
.L001203F4:
    beqz       $2, .L00120430
    addiu     $6, $6, -0x1
    b          .L00120424
    lb        $3, 0x0($4)
    nop
.L00120408:
    beqz       $6, .L00120290
    nop
    beqz       $7, .L00120290
    addiu     $4, $4, 0x1
    addiu      $5, $5, 0x1
    lb         $3, 0x0($4)
    addiu      $6, $6, -0x1
.L00120424:
    lb         $2, 0x0($5)
    beq        $3, $2, .L00120408
    lbu       $7, 0x0($4)
.L00120430:
    lbu        $2, 0x0($5)
    lbu        $3, 0x0($4)
    jr         $31
    subu      $2, $3, $2
.end func_00120288

.section .text.func_00120440,"ax",@progbits
.align 2
.globl func_00120440
.ent func_00120440
func_00120440:
    daddu      $8, $4, $0
    or         $7, $5, $4
    addiu      $10, $0, 0x10
    andi       $2, $7, 0x7
    addiu      $9, $0, 0x8
    bnez       $2, .L001205A8
    andi      $2, $7, 0xF
    movz       $9, $10, $2
    bnez       $2, .L00120514
    sltu      $2, $6, $9
    bnez       $2, .L001205A8
    nop
    lui        $7, (0x1010101 >> 16)
    ori        $7, $7, (0x1010101 & 0xFFFF)
    dsll       $7, $7, 16
    ori        $7, $7, 0x101
    dsll       $7, $7, 16
    ori        $7, $7, 0x101
    lq         $3, 0x0($5)
    pcpyld     $9, $7, $7
    pnor       $3, $0, $3
    lui        $7, (0x80808080 >> 16)
    ori        $7, $7, (0x80808080 & 0xFFFF)
    dsll       $7, $7, 16
    ori        $7, $7, 0x8080
    dsll       $7, $7, 16
    ori        $7, $7, 0x8080
    psubb      $2, $3, $9
    pcpyld     $10, $7, $7
    pand       $2, $2, $3
    pand       $2, $2, $10
    pcpyud     $3, $2, $4
    or         $3, $2, $3
    bnez       $3, .L001205A4
    daddu     $7, $8, $0
    lq         $3, 0x0($5)
    addiu      $6, $6, -0x10
    addiu      $5, $5, 0x10
    sltiu      $2, $6, 0x10
    sq         $3, 0x0($7)
    bnez       $2, .L001205A4
    addiu     $7, $7, 0x10
    lq         $2, 0x0($5)
    pnor       $3, $0, $2
    psubb      $2, $2, $9
    pand       $2, $2, $3
    pand       $2, $2, $10
    pcpyud     $3, $2, $4
    or         $2, $2, $3
    beql       $2, $0, .L00120570
    lq        $3, 0x0($5)
    b          .L001205A8
    daddu     $4, $7, $0
.L00120514:
    bnez       $2, .L001205A8
    nop
    ld         $3, 0x0($5)
    lui        $9, (0x1010101 >> 16)
    ori        $9, $9, (0x1010101 & 0xFFFF)
    dsll       $9, $9, 16
    ori        $9, $9, 0x101
    dsll       $9, $9, 16
    ori        $9, $9, 0x101
    lui        $10, (0x80808080 >> 16)
    ori        $10, $10, (0x80808080 & 0xFFFF)
    dsll       $10, $10, 16
    ori        $10, $10, 0x8080
    dsll       $10, $10, 16
    ori        $10, $10, 0x8080
    dsubu      $2, $3, $9
    nor        $3, $0, $3
    and        $2, $2, $3
    and        $2, $2, $10
    bnez       $2, .L001205A4
    daddu     $7, $8, $0
    ld         $3, 0x0($5)
    nop
.L00120570:
    addiu      $6, $6, -0x8
    addiu      $5, $5, 0x8
    sltiu      $2, $6, 0x8
    sd         $3, 0x0($7)
    bnez       $2, .L001205A4
    addiu     $7, $7, 0x8
    ld         $2, 0x0($5)
    nor        $3, $0, $2
    dsubu      $2, $2, $9
    and        $2, $2, $3
    and        $2, $2, $10
    beql       $2, $0, .L00120570
    ld        $3, 0x0($5)
.L001205A4:
    daddu      $4, $7, $0
.L001205A8:
    beqz       $6, .L001205F4
    daddu     $2, $6, $0
    lbu        $2, 0x0($5)
    addiu      $6, $6, -0x1
    addiu      $5, $5, 0x1
    sb         $2, 0x0($4)
    sll        $2, $2, 24
    bnez       $2, .L001205A8
    addiu     $4, $4, 0x1
    daddu      $2, $6, $0
    beqz       $2, .L001205F4
    addiu     $6, $6, -0x1
.L001205D8:
    sb         $0, 0x0($4)
    daddu      $2, $6, $0
    addiu      $4, $4, 0x1
    addiu      $6, $6, -0x1
    nop
    bnez       $2, .L001205D8
    nop
.L001205F4:
    jr         $31
    daddu     $2, $8, $0
.end func_00120440
