/* Hand-written VU0/COP2 and coprocessor-0 leaf routines. */
#define FN(name, body) __asm__(".section .text." #name ",\"ax\",@progbits
.p2align 3\n.globl " #name "\n.ent " #name "\n" #name ":\n.set noreorder\n.set noat\n" body ".set reorder\n.end " #name "\n")
FN(func_0010CA68,
  ".word 0x40026000 /* mfc0 $v0, $12 */\n"
  ".word 0x3C030001 /* lui $v1, (0x10000 >> 16) */\n"
  ".word 0x00431024 /* and $v0, $v0, $v1 */\n"
  ".word 0x42000038 /* ei */\n"
  ".word 0x03E00008 /* jr $ra */\n"
  ".word 0x0002102B /* sltu $v0, $zero, $v0 */\n"
  );
