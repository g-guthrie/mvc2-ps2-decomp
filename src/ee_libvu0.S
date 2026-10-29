/* libvu0 VU0 macro-mode kernels (sceVu0*): fixed-register lqc2/vmul/sqc2
 * matrix and vector routines.
 *
 * Hand-written assembly in the original executable (no compiler emits
 * these instruction sequences). Transcribed from the retail instruction
 * stream; assembled with GNU as 2.10-ee-001003-1 and verified byte for byte. */
.set noreorder
.set noat

.section .text.func_00102CA0,"ax",@progbits
.align 2
.globl func_00102CA0
.ent func_00102CA0
func_00102CA0:
    lqc2       $vf4, 0x0($5)
    lqc2       $vf5, 0x10($5)
    lqc2       $vf6, 0x20($5)
    lqc2       $vf7, 0x30($5)
    addiu      $7, $0, 0x4
.L00102CB4:
    lqc2       $vf8, 0x0($6)
    vmulax.xyzw ACC, $vf4, $vf8x
    vmadday.xyzw ACC, $vf5, $vf8y
    vmaddaz.xyzw ACC, $vf6, $vf8z
    vmaddw.xyzw $vf9, $vf7, $vf8w
    sqc2       $vf9, 0x0($4)
    addi       $7, $7, -0x1
    addi       $6, $6, 0x10
    bne        $0, $7, .L00102CB4
    addi      $4, $4, 0x10
    jr         $31
    nop
.end func_00102CA0

.section .text.func_00102D70,"ax",@progbits
.align 2
.globl func_00102D70
.ent func_00102D70
func_00102D70:
    lq         $8, 0x0($5)
    lq         $9, 0x10($5)
    lq         $10, 0x20($5)
    lq         $11, 0x30($5)
    pextlw     $12, $9, $8
    pextuw     $13, $9, $8
    pextlw     $14, $11, $10
    pextuw     $15, $11, $10
    pcpyld     $8, $14, $12
    pcpyud     $9, $12, $14
    pcpyld     $10, $15, $13
    pcpyud     $11, $13, $15
    sq         $8, 0x0($4)
    sq         $9, 0x10($4)
    sq         $10, 0x20($4)
    jr         $31
    sq        $11, 0x30($4)
.end func_00102D70

.section .text.func_00102DB8,"ax",@progbits
.align 2
.globl func_00102DB8
.ent func_00102DB8
func_00102DB8:
    lq         $8, 0x0($5)
    lq         $9, 0x10($5)
    lq         $10, 0x20($5)
    lqc2       $vf4, 0x30($5)
    vmove.xyzw $vf5, $vf4
    vsub.xyz   $vf4, $vf4, $vf4
    vmove.xyzw $vf9, $vf4
    qmfc2.ni   $11, $vf4
    pextlw     $12, $9, $8
    pextuw     $13, $9, $8
    pextlw     $14, $11, $10
    pextuw     $15, $11, $10
    pcpyld     $8, $14, $12
    pcpyud     $9, $12, $14
    pcpyld     $10, $15, $13
    qmtc2.ni   $8, $vf6
    qmtc2.ni   $9, $vf7
    qmtc2.ni   $10, $vf8
    vmulax.xyz ACC, $vf6, $vf5x
    vmadday.xyz ACC, $vf7, $vf5y
    vmaddz.xyz $vf4, $vf8, $vf5z
    vsub.xyz   $vf4, $vf9, $vf4
    sq         $8, 0x0($4)
    sq         $9, 0x10($4)
    sq         $10, 0x20($4)
    jr         $31
    sqc2      $vf4, 0x30($4)
.end func_00102DB8

.section .text.func_00102EF0,"ax",@progbits
.align 2
.globl func_00102EF0
.ent func_00102EF0
func_00102EF0:
    lqc2       $vf4, 0x0($6)
    lqc2       $vf5, 0x30($5)
    lq         $7, 0x0($5)
    lq         $8, 0x10($5)
    lq         $9, 0x20($5)
    vadd.xyz   $vf5, $vf5, $vf4
    sq         $7, 0x0($4)
    sq         $8, 0x10($4)
    sq         $9, 0x20($4)
    jr         $31
    sqc2      $vf5, 0x30($4)
.end func_00102EF0

.section .text.func_00102F20,"ax",@progbits
.align 2
.globl func_00102F20
.ent func_00102F20
func_00102F20:
    lq         $6, 0x0($5)
    jr         $31
    sq        $6, 0x0($4)
.end func_00102F20

.section .text.func_00102FC0,"ax",@progbits
.align 2
.globl func_00102FC0
.ent func_00102FC0
func_00102FC0:
    lui        $8, %hi(D_00438210)
    addiu      $8, $8, %lo(D_00438210)
    lqc2       $vf5, 0x0($8)
    vmr32.w    $vf6, $vf6
    vaddx.x    $vf4, $vf0, $vf6x
    vmul.x     $vf6, $vf6, $vf6
    vmulx.yzw  $vf4, $vf4, $vf0x
    vmulw.xyzw $vf8, $vf5, $vf6w
    vsub.xyzw  $vf5, $vf0, $vf0
    vmulx.xyzw $vf8, $vf8, $vf6x
    vmulx.xyz  $vf8, $vf8, $vf6x
    vaddw.x    $vf4, $vf4, $vf8w
    vmulx.xy   $vf8, $vf8, $vf6x
    vaddz.x    $vf4, $vf4, $vf8z
    vmulx.x    $vf8, $vf8, $vf6x
    vaddy.x    $vf4, $vf4, $vf8y
    vaddx.x    $vf4, $vf4, $vf8x
    vaddx.xy   $vf4, $vf5, $vf4x
    vmul.x     $vf7, $vf4, $vf4
    vsubx.w    $vf7, $vf0, $vf7x
    .word      0x4B8703BD                    # vsqrt      Q, $vf7w # 00000000 <InstrIdType: R5900_COP2_SPECIAL2>
    vwaitq
    bnez       $7, .L00103028
    vaddq.x   $vf7, $vf0, Q
    b          .L0010302C
    vaddx.x   $vf4, $vf5, $vf7x
.L00103028:
    vsubx.x    $vf4, $vf5, $vf7x
.L0010302C:
    jr         $31
    nop
.end func_00102FC0

.section .text.func_00103038,"ax",@progbits
.align 2
.globl func_00103038
.ent func_00103038
func_00103038:
    mtc1       $0, $f0
    c.lt.s     $f12, $f0
    lui        $1, (0x3FC90FDB >> 16)
    ori        $1, $1, (0x3FC90FDB & 0xFFFF)
    mtc1       $1, $f0
    bc1f       .L00103060
    nop
    add.s      $f12, $f0, $f12
    j          .L00103068
    addiu     $7, $0, 0x1
.L00103060:
    sub.s      $f12, $f0, $f12
    daddu      $7, $0, $0
.L00103068:
    mfc1       $8, $f12
    qmtc2.ni   $8, $vf6
    daddu      $6, $31, $0
    jal        func_00102FC0
    nop
    daddu      $31, $6, $0
    vmove.xyzw $vf6, $vf5
    vmove.xyzw $vf7, $vf5
    vmove.xyzw $vf9, $vf0
    vsub.xyz   $vf9, $vf9, $vf9
    vmr32.xyzw $vf8, $vf9
    vsub.zw    $vf4, $vf4, $vf4
    vaddx.y    $vf6, $vf5, $vf4x
    vaddy.x    $vf6, $vf5, $vf4y
    vsubx.x    $vf7, $vf5, $vf4x
    vaddy.y    $vf7, $vf5, $vf4y
    addiu      $7, $0, 0x4
.L001030AC:
    lqc2       $vf4, 0x0($5)
    vmulax.xyzw ACC, $vf6, $vf4x
    vmadday.xyzw ACC, $vf7, $vf4y
    vmaddaz.xyzw ACC, $vf8, $vf4z
    vmaddw.xyzw $vf5, $vf9, $vf4w
    sqc2       $vf5, 0x0($4)
    addi       $7, $7, -0x1
    addi       $5, $5, 0x10
    bne        $0, $7, .L001030AC
    addi      $4, $4, 0x10
    jr         $31
    nop
.end func_00103038

.section .text.func_001030E0,"ax",@progbits
.align 2
.globl func_001030E0
.ent func_001030E0
func_001030E0:
    mtc1       $0, $f0
    c.lt.s     $f12, $f0
    lui        $1, (0x3FC90FDB >> 16)
    ori        $1, $1, (0x3FC90FDB & 0xFFFF)
    mtc1       $1, $f0
    bc1f       .L00103108
    nop
    add.s      $f12, $f0, $f12
    j          .L00103110
    addiu     $7, $0, 0x1
.L00103108:
    sub.s      $f12, $f0, $f12
    daddu      $7, $0, $0
.L00103110:
    mfc1       $8, $f12
    qmtc2.ni   $8, $vf6
    daddu      $6, $31, $0
    jal        func_00102FC0
    nop
    daddu      $31, $6, $0
    vmove.xyzw $vf6, $vf5
    vmove.xyzw $vf7, $vf5
    vmove.xyzw $vf8, $vf5
    vmove.xyzw $vf9, $vf5
    vaddw.x    $vf6, $vf5, $vf0w
    vaddw.w    $vf9, $vf5, $vf0w
    vsub.zw    $vf4, $vf4, $vf4
    vaddx.z    $vf7, $vf5, $vf4x
    vaddy.y    $vf7, $vf5, $vf4y
    vsubx.y    $vf8, $vf5, $vf4x
    vaddy.z    $vf8, $vf5, $vf4y
    addiu      $7, $0, 0x4
.L00103158:
    lqc2       $vf4, 0x0($5)
    vmulax.xyzw ACC, $vf6, $vf4x
    vmadday.xyzw ACC, $vf7, $vf4y
    vmaddaz.xyzw ACC, $vf8, $vf4z
    vmaddw.xyzw $vf5, $vf9, $vf4w
    sqc2       $vf5, 0x0($4)
    addi       $7, $7, -0x1
    addi       $5, $5, 0x10
    bne        $0, $7, .L00103158
    addi      $4, $4, 0x10
    jr         $31
    nop
.end func_001030E0

.section .text.func_00103188,"ax",@progbits
.align 2
.globl func_00103188
.ent func_00103188
func_00103188:
    mtc1       $0, $f0
    c.lt.s     $f12, $f0
    lui        $1, (0x3FC90FDB >> 16)
    ori        $1, $1, (0x3FC90FDB & 0xFFFF)
    mtc1       $1, $f0
    bc1f       .L001031B0
    nop
    add.s      $f12, $f0, $f12
    j          .L001031B8
    addiu     $7, $0, 0x1
.L001031B0:
    sub.s      $f12, $f0, $f12
    daddu      $7, $0, $0
.L001031B8:
    mfc1       $8, $f12
    qmtc2.ni   $8, $vf6
    daddu      $6, $31, $0
    jal        func_00102FC0
    nop
    daddu      $31, $6, $0
    vmove.xyzw $vf6, $vf5
    vmove.xyzw $vf7, $vf5
    vmove.xyzw $vf8, $vf5
    vmove.xyzw $vf9, $vf5
    vaddw.y    $vf7, $vf5, $vf0w
    vaddw.w    $vf9, $vf5, $vf0w
    vsub.zw    $vf4, $vf4, $vf4
    vsubx.z    $vf6, $vf5, $vf4x
    vaddy.x    $vf6, $vf5, $vf4y
    vaddx.x    $vf8, $vf5, $vf4x
    vaddy.z    $vf8, $vf5, $vf4y
    addiu      $7, $0, 0x4
.L00103200:
    lqc2       $vf4, 0x0($5)
    vmulax.xyzw ACC, $vf6, $vf4x
    vmadday.xyzw ACC, $vf7, $vf4y
    vmaddaz.xyzw ACC, $vf8, $vf4z
    vmaddw.xyzw $vf5, $vf9, $vf4w
    sqc2       $vf5, 0x0($4)
    addi       $7, $7, -0x1
    addi       $5, $5, 0x10
    bne        $0, $7, .L00103200
    addi      $4, $4, 0x10
    jr         $31
    nop
.end func_00103188

.section .text.func_00103718,"ax",@progbits
.align 2
.globl func_00103718
.ent func_00103718
func_00103718:
    lqc2       $vf4, 0x0($5)
    lqc2       $vf5, 0x10($5)
    lqc2       $vf6, 0x20($5)
    lqc2       $vf7, 0x30($5)
.L00103728:
    lqc2       $vf8, 0x0($6)
    vmulax.xyzw ACC, $vf4, $vf8x
    vmadday.xyzw ACC, $vf5, $vf8y
    vmaddaz.xyzw ACC, $vf6, $vf8z
    vmaddw.xyzw $vf9, $vf7, $vf8w
    vdiv       Q, $vf0w, $vf9w
    vwaitq
    vmulq.xyz  $vf9, $vf9, Q
    beqz       $8, .L00103754
    vftoi4.xyzw $vf10, $vf9
    vftoi0.zw  $vf10, $vf9
.L00103754:
    sqc2       $vf10, 0x0($4)
    addi       $7, $7, -0x1
    addi       $6, $6, 0x10
    bne        $0, $7, .L00103728
    addi      $4, $4, 0x10
    jr         $31
    nop
.end func_00103718

.section .text.func_001038C8,"ax",@progbits
.align 2
.globl func_001038C8
.ent func_001038C8
func_001038C8:
    lqc2       $vf8, 0x0($7)
    lqc2       $vf4, 0x0($6)
    lqc2       $vf5, 0x10($6)
    lqc2       $vf6, 0x20($6)
    lqc2       $vf7, 0x30($6)
    lqc2       $vf9, 0x0($4)
    lqc2       $vf10, 0x0($5)
    lqc2       $vf11, 0x0($4)
    lqc2       $vf12, 0x0($5)
.L001038EC:
    vmulax.xyzw ACC, $vf4, $vf8x
    vmadday.xyzw ACC, $vf5, $vf8y
    vmaddaz.xyzw ACC, $vf6, $vf8z
    vmaddw.xyzw $vf8, $vf7, $vf8w
    vmulw.xyz  $vf11, $vf9, $vf8w
    vmulw.xyz  $vf12, $vf10, $vf8w
    vnop
    vnop
    ctc2.ni    $0, $vi16
    vsub.xyw   $vf11, $vf8, $vf11
    vsub.xyw   $vf12, $vf12, $vf8
    vmove.w    $vf11, $vf9
    vmove.w    $vf12, $vf10
    vnop
    addi       $7, $7, 0x10
    lqc2       $vf8, 0x0($7)
    addi       $8, $8, -0x1
    cfc2.ni    $2, $vi16
    andi       $2, $2, 0xC0
    beqz       $2, .L0010394C
    nop
    bne        $0, $8, .L001038EC
    nop
    addi       $2, $0, 0x1
.L0010394C:
    jr         $31
    nop
.end func_001038C8
