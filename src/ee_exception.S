/* Exception handler: saves state to the $k0 area and returns with eret.
 *
 * Hand-written assembly in the original executable (no compiler emits
 * these instruction sequences). Transcribed from the retail instruction
 * stream; assembled with GNU as 2.10-ee-001003-1 and verified byte for byte. */
.set noreorder
.set noat

.section .text.func_0010C6C0,"ax",@progbits
.align 2
.globl func_0010C6C0
.ent func_0010C6C0
func_0010C6C0:
    lui        $26, %hi(D_004C8140)
    addiu      $26, $26, %lo(D_004C8140)
    sq         $1, 0x10($26)
    sq         $2, 0x20($26)
    sq         $3, 0x30($26)
    sq         $4, 0x40($26)
    sq         $5, 0x50($26)
    sq         $6, 0x60($26)
    sq         $7, 0x70($26)
    sq         $8, 0x80($26)
    sq         $9, 0x90($26)
    sq         $10, 0xA0($26)
    sq         $11, 0xB0($26)
    sq         $12, 0xC0($26)
    sq         $13, 0xD0($26)
    sq         $14, 0xE0($26)
    sq         $15, 0xF0($26)
    sq         $16, 0x100($26)
    sq         $17, 0x110($26)
    sq         $18, 0x120($26)
    sq         $19, 0x130($26)
    sq         $20, 0x140($26)
    sq         $21, 0x150($26)
    sq         $22, 0x160($26)
    sq         $23, 0x170($26)
    sq         $24, 0x180($26)
    sq         $25, 0x190($26)
    sq         $28, 0x1C0($26)
    sq         $29, 0x1D0($26)
    sq         $30, 0x1E0($26)
    sq         $31, 0x1F0($26)
    mfhi       $2
    lui        $1, %hi(D_004C8340)
    sd         $2, %lo(D_004C8340)($1)
    mfhi1      $2
    lui        $1, %hi(D_004C8348)
    sd         $2, %lo(D_004C8348)($1)
    mflo       $2
    lui        $1, %hi(D_004C8350)
    sd         $2, %lo(D_004C8350)($1)
    mflo1      $2
    lui        $1, %hi(D_004C8358)
    sd         $2, %lo(D_004C8358)($1)
    mfsa       $2
    lui        $1, %hi(D_004C8360)
    sd         $2, %lo(D_004C8360)($1)
    mfc0       $4, $12
    mfc0       $5, $13
    mfc0       $6, $14
    mfc0       $7, $8
    lui        $8, %hi(D_004C8140)
    addiu      $8, $8, %lo(D_004C8140)
    lui        $1, %hi(D_004C8368)
    sw         $6, %lo(D_004C8368)($1)
    lui        $1, %hi(D_0010C7C0)
    addiu      $1, $1, %lo(D_0010C7C0)
    mtc0       $1, $14
    sync.p
    mfc0       $1, $12
    addiu      $2, $0, -0x2
    and        $1, $1, $2
    mtc0       $1, $12
    sync.p
    eret
    lui        $1, %hi(D_00438658)
    lw         $1, %lo(D_00438658)($1)
    lui        $29, %hi(D_004C8140)
    jalr       $1
    addiu     $29, $29, %lo(D_004C8140)
    addiu      $3, $0, -0x54
    syscall    0
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    mfc0       $1, $12
    addiu      $26, $0, -0x1C
    and        $1, $1, $26
    mtc0       $1, $12
    sync.p
    lui        $2, %hi(D_004C8368)
    lw         $2, %lo(D_004C8368)($2)
    mtc0       $2, $14
    sync.p
    lui        $2, %hi(D_004C8340)
    ld         $2, %lo(D_004C8340)($2)
    mthi       $2
    lui        $2, %hi(D_004C8348)
    ld         $2, %lo(D_004C8348)($2)
    mthi1      $2
    lui        $2, %hi(D_004C8350)
    ld         $2, %lo(D_004C8350)($2)
    mtlo       $2
    lui        $2, %hi(D_004C8358)
    ld         $2, %lo(D_004C8358)($2)
    mtlo1      $2
    lui        $2, %hi(D_004C8360)
    ld         $2, %lo(D_004C8360)($2)
    mtsa       $2
    sync.p
    lui        $26, %hi(D_004C8140)
    addiu      $26, $26, %lo(D_004C8140)
    lq         $1, 0x10($26)
    lq         $2, 0x20($26)
    lq         $3, 0x30($26)
    lq         $4, 0x40($26)
    lq         $5, 0x50($26)
    lq         $6, 0x60($26)
    lq         $7, 0x70($26)
    lq         $8, 0x80($26)
    lq         $9, 0x90($26)
    lq         $10, 0xA0($26)
    lq         $11, 0xB0($26)
    lq         $12, 0xC0($26)
    lq         $13, 0xD0($26)
    lq         $14, 0xE0($26)
    lq         $15, 0xF0($26)
    lq         $16, 0x100($26)
    lq         $17, 0x110($26)
    lq         $18, 0x120($26)
    lq         $19, 0x130($26)
    lq         $20, 0x140($26)
    lq         $21, 0x150($26)
    lq         $22, 0x160($26)
    lq         $23, 0x170($26)
    lq         $24, 0x180($26)
    lq         $25, 0x190($26)
    lq         $28, 0x1C0($26)
    lq         $29, 0x1D0($26)
    lq         $30, 0x1E0($26)
    lq         $31, 0x1F0($26)
    mfc0       $26, $12
    ori        $26, $26, 0x13
    mtc0       $26, $12
    sync.p
    eret
    nop
    nop
    nop
.L0010C900:
    lui        $26, %hi(D_004C8140)
    addiu      $26, $26, %lo(D_004C8140)
    sq         $1, 0x10($26)
    sq         $2, 0x20($26)
    sq         $3, 0x30($26)
    sq         $4, 0x40($26)
    sq         $5, 0x50($26)
    sq         $6, 0x60($26)
    sq         $7, 0x70($26)
    sq         $8, 0x80($26)
    sq         $9, 0x90($26)
    sq         $10, 0xA0($26)
    sq         $11, 0xB0($26)
    sq         $12, 0xC0($26)
    sq         $13, 0xD0($26)
    sq         $14, 0xE0($26)
    sq         $15, 0xF0($26)
    sq         $16, 0x100($26)
    sq         $17, 0x110($26)
    sq         $18, 0x120($26)
    sq         $19, 0x130($26)
    sq         $20, 0x140($26)
    sq         $21, 0x150($26)
    sq         $22, 0x160($26)
    sq         $23, 0x170($26)
    sq         $24, 0x180($26)
    sq         $25, 0x190($26)
    sq         $28, 0x1C0($26)
    sq         $29, 0x1D0($26)
    sq         $30, 0x1E0($26)
    sq         $31, 0x1F0($26)
    mfhi       $2
    lui        $1, %hi(D_004C8340)
    sd         $2, %lo(D_004C8340)($1)
    mfhi1      $2
    lui        $1, %hi(D_004C8348)
    sd         $2, %lo(D_004C8348)($1)
    mflo       $2
    lui        $1, %hi(D_004C8350)
    sd         $2, %lo(D_004C8350)($1)
    mflo1      $2
    lui        $1, %hi(D_004C8358)
    sd         $2, %lo(D_004C8358)($1)
    mfsa       $2
    lui        $1, %hi(D_004C8360)
    sd         $2, %lo(D_004C8360)($1)
    mfc0       $4, $12
    mfc0       $5, $13
    mfc0       $6, $14
    mfc0       $7, $8
    mfc0       $8, $23
    lui        $9, %hi(D_004C8140)
    addiu      $9, $9, %lo(D_004C8140)
    lui        $1, %hi(D_0010C9FC)
    addiu      $1, $1, %lo(D_0010C9FC)
    mtc0       $1, $14
    sync.p
    mfc0       $1, $12
    addiu      $2, $0, -0x2
    and        $1, $1, $2
    mtc0       $1, $12
    sync.p
    eret
    andi       $2, $5, 0x7C
    lui        $1, %hi(D_00438660)
    addu       $1, $1, $2
    lw         $1, %lo(D_00438660)($1)
    lui        $29, %hi(D_004C8140)
    jalr       $1
    addiu     $29, $29, %lo(D_004C8140)
    break      1023, 1023
.end func_0010C6C0
