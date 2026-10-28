/* Hand-written SDK assembly routines (VU0 helpers, delay loops, word copies). */
#define FN(name, body) __asm__(".section .text." #name ",\"ax\",@progbits\n.p2align 3\n.globl " #name "\n.ent " #name "\n" #name ":\n.set noreorder\n.set noat\n" body ".set reorder\n.end " #name "\n")
FN(func_00102CE8,
  ".word 0xD8A40000 /* lqc2       $vf4, 0x0($5) */\n"
  ".word 0xD8C50000 /* lqc2       $vf5, 0x0($6) */\n"
  ".word 0x4BC522FE /* vopmula.xyz $ACC, $vf4, $vf5 */\n"
  ".word 0x4BC429AE /* vopmsub.xyz $vf6, $vf5, $vf4 */\n"
  ".word 0x4A2631AC /* vsub.w     $vf6, $vf6, $vf6 */\n"
  ".word 0x03E00008 /* jr         $31 */\n"
  ".word 0xF8860000 /* sqc2      $vf6, 0x0($4) */\n"
  );
FN(func_00102D08,
  ".word 0xD8840000 /* lqc2       $vf4, 0x0($4) */\n"
  ".word 0xD8A50000 /* lqc2       $vf5, 0x0($5) */\n"
  ".word 0x4BC5216A /* vmul.xyz   $vf5, $vf4, $vf5 */\n"
  ".word 0x4B052941 /* vaddy.x    $vf5, $vf5, $vf5y */\n"
  ".word 0x4B052942 /* vaddz.x    $vf5, $vf5, $vf5z */\n"
  ".word 0x48222800 /* qmfc2.ni   $2, $vf5 */\n"
  ".word 0x44820000 /* mtc1       $2, $f0 */\n"
  ".word 0x03E00008 /* jr         $31 */\n"
  ".word 0x00000000 /* nop */\n"
  );
/* Busy-wait: 50000 rounds of one nop; GCC pads the short loop to five. */
void func_003FB5C0(void)
{
    int i = 50000;
    while (--i, 1) {
        __asm__ volatile("nop");
        if (i == 0) break;
    }
}
/* Busy-wait for *count rounds; spins forever when count is NULL. */
void func_0040DFA8(int unused, int *count)
{
    int n;
    if (count == 0) {
        for (;;) __asm__ volatile("nop");
    }
    n = *count;
    if (n > 0) {
        while (--n, 1) {
            __asm__ volatile("nop");
            if (n == 0) break;
        }
    }
}
FN(func_00103958,
  "lui $2,0x1000\n"
  "lui $4,0x1000\n"
  "ori $2,$2,0x3830\n"
  "ori $4,$4,0x3820\n"
  "sw $0,0($2)\n"
  "lui $3,0x1000\n"
  "sw $0,0($4)\n"
  "ori $3,$3,0x3810\n"
  "addiu $2,$0,1\n"
  "sw $2,0($3)\n"
  ".word 0x4848E000 /* cfc2.ni $8,$vi28 */\n"
  "ori $8,$8,2\n"
  ".word 0x48C8E000 /* ctc2.ni $8,$vi28 */\n"
  ".word 0x0000040F /* sync.p */\n"
  "lui $4,%hi(D_00438220)\n"
  "lui $5,0x1000\n"
  "addiu $4,$4,%lo(D_00438220)\n"
  "ori $5,$5,0x4000\n"
  "lq $2,0($4)\n"
  "sq $2,0($5)\n"
  "lq $3,16($4)\n"
  "jr $31\n"
  "sq $3,0($5)\n"
  );
