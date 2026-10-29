/* Hand-written SDK assembly: COP0 status read. */
#define FN(name, body) __asm__(".section .text." #name ",\"ax\",@progbits
.p2align 3\n.globl " #name "\n.ent " #name "\n" #name ":\n.set noreorder\n.set noat\n" body ".set reorder\n.end " #name "\n")
FN(func_001048B0,
  ".word 0x40026000 /* mfc0       $2, $12 */\n"
  "xori $2,$2,1\n"
  "jr $31\n"
  "andi $2,$2,1\n"
  );
