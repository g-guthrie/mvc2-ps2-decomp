/* Hand-written nop-padded busy-wait loop (same shape as func_003FB5C0 in sdk5b.c). */
#define FN(name, body) __asm__(".section .text." #name ",\"ax\",@progbits\n.p2align 3\n.globl " #name "\n.ent " #name "\n" #name ":\n.set noreorder\n.set noat\n" body ".set reorder\n.end " #name "\n")
FN(func_0040AF28,
  "ori $2,$0,0x8000\n"
  "addiu $2,$2,-1\n"
  "1:\n"
  "nop\nnop\nnop\nnop\nnop\n"
  "bnel $2,$0,1b\n"
  "addiu $2,$2,-1\n"
  "jr $31\n"
  "nop\n"
  );
