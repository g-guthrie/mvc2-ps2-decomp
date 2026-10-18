/* Hand-written SDK assembly: COP0 status read, indexed table accessor with spin trap, VU0 transform loop. */
#define FN(name, body) __asm__(".section .text." #name ",\"ax\",@progbits
.p2align 3\n.globl " #name "\n.ent " #name "\n" #name ":\n.set noreorder\n.set noat\n" body ".set reorder\n.end " #name "\n")
FN(func_001048B0,
  ".word 0x40026000 /* mfc0       $2, $12 */\n"
  "xori $2,$2,1\n"
  "jr $31\n"
  "andi $2,$2,1\n"
  );
FN(func_0040FD00,
  "sll $5,$5,1\n"
  "addu $5,$5,$6\n"
  "sll $5,$5,2\n"
  "addu $5,$5,$4\n"
  "jr $31\n"
  "lw $2,0x28($5)\n"
  "1:\n"
  "nop\nnop\nnop\nnop\nnop\n"
  "b 1b\n"
  "nop\n"
  );
FN(func_00103718,
  ".word 0xD8A40000 /* lqc2       $vf4, 0x0($5) */\n"
  ".word 0xD8A50010 /* lqc2       $vf5, 0x10($5) */\n"
  ".word 0xD8A60020 /* lqc2       $vf6, 0x20($5) */\n"
  ".word 0xD8A70030 /* lqc2       $vf7, 0x30($5) */\n"
  "1:\n"
  ".word 0xD8C80000 /* lqc2       $vf8, 0x0($6) */\n"
  ".word 0x4BE821BC /* vmulax.xyzw $ACC, $vf4, $vf8x */\n"
  ".word 0x4BE828BD /* vmadday.xyzw $ACC, $vf5, $vf8y */\n"
  ".word 0x4BE830BE /* vmaddaz.xyzw $ACC, $vf6, $vf8z */\n"
  ".word 0x4BE83A4B /* vmaddw.xyzw $vf9, $vf7, $vf8w */\n"
  ".word 0x4BE903BC /* vdiv       $Q, $vf0w, $vf9w */\n"
  ".word 0x4A0003BF /* vwaitq */\n"
  ".word 0x4BC04A5C /* vmulq.xyz  $vf9, $vf9, $Q */\n"
  "beqz $8,2f\n"
  ".word 0x4BEA497D /* vftoi4.xyzw $vf10, $vf9 */\n"
  ".word 0x4A6A497C /* vftoi0.zw  $vf10, $vf9 */\n"
  "2:\n"
  ".word 0xF88A0000 /* sqc2       $vf10, 0x0($4) */\n"
  ".word 0x20E7FFFF /* addi       $7, $7, -1 */\n"
  ".word 0x20C60010 /* addi       $6, $6, 16 */\n"
  "bne $0,$7,1b\n"
  ".word 0x20840010 /* addi       $4, $4, 16 */\n"
  "jr $31\n"
  "nop\n"
  );
