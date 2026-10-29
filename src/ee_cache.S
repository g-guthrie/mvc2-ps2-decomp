/* Data-cache writeback/invalidate loop (cache 0x18 + sync) and the lone
 * jr $ra stub that follows it.
 *
 * Hand-written assembly in the original executable (no compiler emits
 * these instruction sequences). Transcribed from the retail instruction
 * stream; assembled with GNU as 2.10-ee-001003-1 and verified byte for byte. */
.set noreorder
.set noat

.section .text.func_00106578,"ax",@progbits
.align 2
.globl func_00106578
.ent func_00106578
func_00106578:
    lui        $25, (0xFFFFFFC0 >> 16)
    ori        $25, $25, (0xFFFFFFC0 & 0xFFFF)
    blez       $5, .L0010661C
    addu      $10, $4, $5
    and        $8, $4, $25
    addiu      $10, $10, -0x1
    and        $9, $10, $25
    subu       $10, $9, $8
    srl        $11, $10, 6
    addiu      $11, $11, 0x1
    andi       $9, $11, 0x7
    beqz       $9, .L001065C8
    srl       $10, $11, 3
.L001065AC:
    sync
    cache      0x18, 0x0($8)
    sync
    addiu      $9, $9, -0x1
    nop
    bgtz       $9, .L001065AC
    addiu     $8, $8, 0x40
.L001065C8:
    beqz       $10, .L0010661C
.L001065CC:
    addiu     $10, $10, -0x1
    sync
    cache      0x18, 0x0($8)
    sync
    cache      0x18, 0x40($8)
    sync
    cache      0x18, 0x80($8)
    sync
    cache      0x18, 0xC0($8)
    sync
    cache      0x18, 0x100($8)
    sync
    cache      0x18, 0x140($8)
    sync
    cache      0x18, 0x180($8)
    sync
    cache      0x18, 0x1C0($8)
    sync
    bgtz       $10, .L001065CC
    addiu     $8, $8, 0x200
.L0010661C:
    jr         $31
    nop
.end func_00106578

.section .text.func_00106624,"ax",@progbits
.align 2
.globl func_00106624
.ent func_00106624
func_00106624:
    jr         $31
.end func_00106624
