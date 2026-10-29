/* Hand-written SDK assembly: interrupt-disable primitive. */
#define FN(name, body) __asm__(".section .text." #name ",\"ax\",@progbits\n.p2align 3\n.globl " #name "\n.ent " #name "\n" #name ":\n.set noreorder\n.set noat\n" body ".set reorder\n.end " #name "\n")
FN(func_0010CA20,
  "mfc0 $3,$12\n"
  "lui $2,1\n"
  "and $3,$3,$2\n"
  "beqz $3,2f\n"
  "sltu $4,$0,$3\n"
  "nop\n"
  "1:\n"
  ".word 0x42000039 /* di */\n"
  ".word 0x0000040F /* sync.p */\n"
  "mfc0 $2,$12\n"
  "lui $3,1\n"
  "and $2,$2,$3\n"
  "bnez $2,1b\n"
  "nop\n"
  "jr $31\n"
  "daddu $2,$4,$0\n"
  "2:\n"
  "daddu $4,$0,$0\n"
  "jr $31\n"
  "daddu $2,$4,$0\n"
  );
