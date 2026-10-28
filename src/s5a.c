/* Hand-written SDK assembly: VU0 check and nop-padded busy-wait. */
#define FN(name, body) __asm__(".section .text." #name ",\"ax\",@progbits\n.p2align 3\n.globl " #name "\n.ent " #name "\n" #name ":\n.set noreorder\n.set noat\n" body ".set reorder\n.end " #name "\n")
FN(func_00105540,
  "lui $3,0x1000\n"
  "ori $3,$3,0xF130\n"
  "1:\n"
  "lw $2,0($3)\n"
  "andi $2,$2,0x8000\n"
  "nop\n"
  "nop\n"
  "nop\n"
  "bnez $2,1b\n"
  "nop\n"
  "lui $3,0x1000\n"
  "daddu $2,$4,$0\n"
  "ori $3,$3,0xF180\n"
  "jr $31\n"
  "sb $4,0($3)\n"
  );
