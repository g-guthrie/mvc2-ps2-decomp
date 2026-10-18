/* Hand-written VU0/COP2 and coprocessor-0 leaf routines. */
#define FN(name, body) __asm__(".section .text." #name ",\"ax\",@progbits
.p2align 3\n.globl " #name "\n.ent " #name "\n" #name ":\n.set noreorder\n.set noat\n" body ".set reorder\n.end " #name "\n")
FN(func_00102E28,
  ".word 0xD8A40000 /* lqc2 $vf4, 0x0($a1) */\n"
  ".word 0x44086000 /* mfc1 $t0, $f12 */\n"
  ".word 0x48A82800 /* qmtc2.ni $t0, $vf5 */\n"
  ".word 0x4A6503BC /* vdiv $Q, $vf0w, $vf5x */\n"
  ".word 0x4A0003BF /* vwaitq */\n"
  ".word 0x4BE0211C /* vmulq.xyzw $vf4, $vf4, $Q */\n"
  ".word 0x03E00008 /* jr $ra */\n"
  ".word 0xF8840000 /* sqc2 $vf4, 0x0($a0) */\n"
  );
FN(func_00102C70,
  ".word 0xD8A40000 /* lqc2 $vf4, 0x0($a1) */\n"
  ".word 0xD8A50010 /* lqc2 $vf5, 0x10($a1) */\n"
  ".word 0xD8A60020 /* lqc2 $vf6, 0x20($a1) */\n"
  ".word 0xD8A70030 /* lqc2 $vf7, 0x30($a1) */\n"
  ".word 0xD8C80000 /* lqc2 $vf8, 0x0($a2) */\n"
  ".word 0x4BE821BC /* vmulax.xyzw $ACC, $vf4, $vf8x */\n"
  ".word 0x4BE828BD /* vmadday.xyzw $ACC, $vf5, $vf8y */\n"
  ".word 0x4BE830BE /* vmaddaz.xyzw $ACC, $vf6, $vf8z */\n"
  ".word 0x4BE83A4B /* vmaddw.xyzw $vf9, $vf7, $vf8w */\n"
  ".word 0x03E00008 /* jr $ra */\n"
  ".word 0xF8890000 /* sqc2 $vf9, 0x0($a0) */\n"
  );
FN(func_001037D8,
  ".word 0xD8A40000 /* lqc2 $vf4, 0x0($a1) */\n"
  ".word 0xD8C50000 /* lqc2 $vf5, 0x0($a2) */\n"
  ".word 0x44086000 /* mfc1 $t0, $f12 */\n"
  ".word 0x48A83000 /* qmtc2.ni $t0, $vf6 */\n"
  ".word 0x4A29233C /* vmove.w $vf9, $vf4 */\n"
  ".word 0x4B0001C3 /* vaddw.x $vf7, $vf0, $vf0w */\n"
  ".word 0x4B063A2C /* vsub.x $vf8, $vf7, $vf6 */\n"
  ".word 0x4BC621BC /* vmulax.xyz $ACC, $vf4, $vf6x */\n"
  ".word 0x4BC82A48 /* vmaddx.xyz $vf9, $vf5, $vf8x */\n"
  ".word 0x03E00008 /* jr $ra */\n"
  ".word 0xF8890000 /* sqc2 $vf9, 0x0($a0) */\n"
  );
FN(func_0010CA68,
  ".word 0x40026000 /* mfc0 $v0, $12 */\n"
  ".word 0x3C030001 /* lui $v1, (0x10000 >> 16) */\n"
  ".word 0x00431024 /* and $v0, $v0, $v1 */\n"
  ".word 0x42000038 /* ei */\n"
  ".word 0x03E00008 /* jr $ra */\n"
  ".word 0x0002102B /* sltu $v0, $zero, $v0 */\n"
  );
