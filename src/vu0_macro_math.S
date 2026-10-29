/* VU0 macro-mode matrix product and square-root helpers.
 *
 * Hand-written assembly in the original executable (no compiler emits
 * these instruction sequences). Transcribed from the retail instruction
 * stream; assembled with GNU as 2.10-ee-001003-1 and verified byte for byte. */
.set noreorder
.set noat

.section .text.func_003DE160,"ax",@progbits
.align 2
.globl func_003DE160
.ent func_003DE160
func_003DE160:
    addiu      $29, $29, -0xC0
    addiu      $10, $0, 0x4
    addiu      $9, $29, 0x0
    addiu      $8, $0, 0x8
.L003DE170:
    lw         $7, 0x0($5)
    addiu      $8, $8, -0x1
    lw         $3, 0x4($5)
    sw         $7, 0x0($9)
    addiu      $5, $5, 0x8
    sw         $3, 0x4($9)
    bgtz       $8, .L003DE170
    addiu     $9, $9, 0x8
    addiu      $8, $29, 0x40
    addiu      $7, $0, 0x8
.L003DE198:
    lw         $5, 0x0($6)
    addiu      $7, $7, -0x1
    lw         $3, 0x4($6)
    sw         $5, 0x0($8)
    addiu      $6, $6, 0x8
    sw         $3, 0x4($8)
    bgtz       $7, .L003DE198
    addiu     $8, $8, 0x8
    addiu      $3, $29, 0x0
    addiu      $5, $29, 0x40
    addiu      $6, $29, 0x80
    lqc2       $vf4, 0x0($5)
    lqc2       $vf5, 0x10($5)
    lqc2       $vf6, 0x20($5)
    lqc2       $vf7, 0x30($5)
.L003DE1D4:
    lqc2       $vf8, 0x0($3)
    addi       $10, $10, -0x1
    vmulax.xyzw ACC, $vf4, $vf8x
    vmadday.xyzw ACC, $vf5, $vf8y
    vmaddaz.xyzw ACC, $vf6, $vf8z
    vmaddw.xyzw $vf9, $vf7, $vf8w
    sqc2       $vf9, 0x0($6)
    addi       $3, $3, 0x10
    bne        $0, $10, .L003DE1D4
    addi      $6, $6, 0x10
    addiu      $7, $29, 0x80
    addiu      $6, $0, 0x8
.L003DE204:
    lw         $5, 0x0($7)
    addiu      $6, $6, -0x1
    lw         $3, 0x4($7)
    sw         $5, 0x0($4)
    addiu      $7, $7, 0x8
    sw         $3, 0x4($4)
    bgtz       $6, .L003DE204
    addiu     $4, $4, 0x8
    jr         $31
    addiu     $29, $29, 0xC0
.end func_003DE160

.section .text.func_003DE230,"ax",@progbits
.align 2
.globl func_003DE230
.ent func_003DE230
func_003DE230:
    addiu      $29, $29, -0xC0
    addiu      $10, $0, 0x3
    addiu      $9, $29, 0x0
    addiu      $8, $0, 0x8
.L003DE240:
    lw         $7, 0x0($5)
    addiu      $8, $8, -0x1
    lw         $3, 0x4($5)
    sw         $7, 0x0($9)
    addiu      $5, $5, 0x8
    sw         $3, 0x4($9)
    bgtz       $8, .L003DE240
    addiu     $9, $9, 0x8
    addiu      $8, $29, 0x40
    addiu      $7, $0, 0x8
.L003DE268:
    lw         $5, 0x0($6)
    addiu      $7, $7, -0x1
    lw         $3, 0x4($6)
    sw         $5, 0x0($8)
    addiu      $6, $6, 0x8
    sw         $3, 0x4($8)
    bgtz       $7, .L003DE268
    addiu     $8, $8, 0x8
    addiu      $3, $29, 0x0
    addiu      $5, $29, 0x40
    addiu      $6, $29, 0x80
    lqc2       $vf4, 0x0($5)
    lqc2       $vf5, 0x10($5)
    lqc2       $vf6, 0x20($5)
.L003DE2A0:
    lqc2       $vf8, 0x0($3)
    addi       $10, $10, -0x1
    vmulax.xyz ACC, $vf4, $vf8x
    vmadday.xyz ACC, $vf5, $vf8y
    vmaddz.xyz $vf9, $vf6, $vf8z
    sqc2       $vf9, 0x0($6)
    addi       $3, $3, 0x10
    bne        $0, $10, .L003DE2A0
    addi      $6, $6, 0x10
    lwc1       $f0, 0x80($29)
    swc1       $f0, 0x0($4)
    lwc1       $f0, 0x84($29)
    swc1       $f0, 0x4($4)
    lwc1       $f0, 0x88($29)
    swc1       $f0, 0x8($4)
    lwc1       $f0, 0x90($29)
    swc1       $f0, 0x10($4)
    lwc1       $f0, 0x94($29)
    swc1       $f0, 0x14($4)
    lwc1       $f0, 0x98($29)
    swc1       $f0, 0x18($4)
    lwc1       $f0, 0xA0($29)
    swc1       $f0, 0x20($4)
    lwc1       $f0, 0xA4($29)
    swc1       $f0, 0x24($4)
    lwc1       $f0, 0xA8($29)
    swc1       $f0, 0x28($4)
    jr         $31
    addiu     $29, $29, 0xC0
.end func_003DE230

.section .text.func_003DE7A0,"ax",@progbits
.align 2
.globl func_003DE7A0
.ent func_003DE7A0
func_003DE7A0:
    mfc1       $8, $f12
    nop
    qmtc2.ni   $8, $vf4
    .word      0x4A0403BD                    # vsqrt      Q, $vf4x # 00000000 <InstrIdType: R5900_COP2_SPECIAL2>
    vwaitq
    vaddq.x    $vf4, $vf0, Q
    qmfc2.ni   $8, $vf4
    mtc1       $8, $f0
    jr         $31
    nop
.end func_003DE7A0
