/* Hand-written SDK assembly routines (VU0 helpers, delay loops, word copies). */
#define FN(name, body) __asm__(".section .text." #name ",\"ax\",@progbits
.p2align 3\n.globl " #name "\n.ent " #name "\n" #name ":\n.set noreorder\n.set noat\n" body ".set reorder\n.end " #name "\n")
FN(func_00102EF0,
  ".word 0xD8C40000 /* lqc2 $vf4, 0x0($a2) */\n"
  ".word 0xD8A50030 /* lqc2 $vf5, 0x30($a1) */\n"
  ".word 0x78A70000 /* lq $a3, 0x0($a1) */\n"
  ".word 0x78A80010 /* lq $t0, 0x10($a1) */\n"
  ".word 0x78A90020 /* lq $t1, 0x20($a1) */\n"
  ".word 0x4BC42968 /* vadd.xyz $vf5, $vf5, $vf4 */\n"
  ".word 0x7C870000 /* sq $a3, 0x0($a0) */\n"
  ".word 0x7C880010 /* sq $t0, 0x10($a0) */\n"
  ".word 0x7C890020 /* sq $t1, 0x20($a0) */\n"
  ".word 0x03E00008 /* jr $ra */\n"
  ".word 0xF8850030 /* sqc2 $vf5, 0x30($a0) */\n"
  );
