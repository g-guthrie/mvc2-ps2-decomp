/* EE C runtime start-up (crt0): clears the GPRs and .bss, sets up the stack,
 * heap and thread, calls the static constructors, then main, then exits.
 *
 * Hand-written assembly in the original executable (no compiler emits
 * these instruction sequences). Transcribed from the retail instruction
 * stream; assembled with GNU as 2.10-ee-001003-1 and verified byte for byte. */
.set noreorder
.set noat

.section .text._start,"ax",@progbits
.align 2
.globl _start
.ent _start
_start:
    padduw     $1, $0, $0
    padduw     $2, $0, $0
    padduw     $3, $0, $0
    padduw     $4, $0, $0
    padduw     $5, $0, $0
    padduw     $6, $0, $0
    padduw     $7, $0, $0
    padduw     $8, $0, $0
    padduw     $9, $0, $0
    padduw     $10, $0, $0
    padduw     $11, $0, $0
    padduw     $12, $0, $0
    padduw     $13, $0, $0
    padduw     $14, $0, $0
    padduw     $15, $0, $0
    padduw     $16, $0, $0
    padduw     $17, $0, $0
    padduw     $18, $0, $0
    padduw     $19, $0, $0
    padduw     $20, $0, $0
    padduw     $21, $0, $0
    padduw     $22, $0, $0
    padduw     $23, $0, $0
    padduw     $24, $0, $0
    padduw     $25, $0, $0
    padduw     $28, $0, $0
    padduw     $29, $0, $0
    padduw     $30, $0, $0
    padduw     $31, $0, $0
    mthi       $0
    mthi1      $0
    mtlo       $0
    mtlo1      $0
    mtsah      $0, 0x0
    mtc1       $0, $f0
    mtc1       $0, $f1
    mtc1       $0, $f2
    mtc1       $0, $f3
    mtc1       $0, $f4
    mtc1       $0, $f5
    mtc1       $0, $f6
    mtc1       $0, $f7
    mtc1       $0, $f8
    mtc1       $0, $f9
    mtc1       $0, $f10
    mtc1       $0, $f11
    mtc1       $0, $f12
    mtc1       $0, $f13
    mtc1       $0, $f14
    mtc1       $0, $f15
    mtc1       $0, $f16
    mtc1       $0, $f17
    mtc1       $0, $f18
    mtc1       $0, $f19
    mtc1       $0, $f20
    mtc1       $0, $f21
    mtc1       $0, $f22
    mtc1       $0, $f23
    mtc1       $0, $f24
    mtc1       $0, $f25
    mtc1       $0, $f26
    mtc1       $0, $f27
    mtc1       $0, $f28
    mtc1       $0, $f29
    mtc1       $0, $f30
    mtc1       $0, $f31
    adda.s     $f0, $f1
    sync.p
    ctc1       $0, $31
    lui        $2, %hi(D_004C2580)
    lui        $3, %hi(D_00634380)
    addiu      $2, $2, %lo(D_004C2580)
    addiu      $3, $3, %lo(D_00634380)
.L0010012C:
    sq         $0, 0x0($2)
    nop
    sltu       $1, $2, $3
    nop
    nop
    bnez       $1, .L0010012C
    addiu     $2, $2, 0x10
    lui        $4, %hi(_gp)
    lui        $5, %hi(D_01F00000)
    lui        $6, %hi(func_00100000)
    lui        $7, %hi(D_004C2C00)
    lui        $8, %hi(func_001001D0)
    addiu      $4, $4, %lo(_gp)
    addiu      $5, $5, %lo(D_01F00000)
    addiu      $6, $6, %lo(func_00100000)
    addiu      $7, $7, %lo(D_004C2C00)
    addiu      $8, $8, %lo(func_001001D0)
    or         $28, $4, $0
    addiu      $3, $0, 0x3C
    syscall    0
    or         $29, $2, $0
    lui        $4, %hi(D_00634380)
    lui        $5, (0x0 >> 16)
    addiu      $4, $4, %lo(D_00634380)
    addiu      $5, $5, -0x1
    addiu      $3, $0, 0x3D
    syscall    0
    jal        func_0010CCA8
    nop
    jal        func_00104060
    or        $4, $0, $0
    ei
    lui        $2, %hi(D_004C2C00)
    addiu      $2, $2, %lo(D_004C2C00)
    lw         $4, 0x0($2)
    jal        func_00170C30
    addiu     $5, $2, 0x4
    j          func_0010D090
    or        $4, $2, $0
.end _start

.section .text.func_001001D0,"ax",@progbits
.align 2
.globl func_001001D0
.ent func_001001D0
func_001001D0:
    addiu      $3, $0, 0x23
    syscall    0
.end func_001001D0
