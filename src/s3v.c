/* VU0 helpers */
#define FN(name, body) __asm__(".section .text." #name ",\"ax\",@progbits\n.p2align 3\n.globl " #name "\n.ent " #name "\n" #name ":\n.set noreorder\n.set noat\n" body ".set reorder\n.end " #name "\n")
FN(func_00102ED8,
  ".word 0xD8A40000 /* lqc2       $vf4, 0x0($a1) */\n"
  ".word 0x44086000 /* mfc1       $t0, $f12 */\n"
  ".word 0x48A82800 /* qmtc2.ni   $t0, $vf5 */\n"
  ".word 0x4BE52198 /* vmulx.xyzw $vf6, $vf4, $vf5x */\n"
  ".word 0x03E00008 /* jr         $ra */\n"
  ".word 0xF8860000 /* sqc2      $vf6, 0x0($a0) */\n"
  );
FN(func_00103280,
  ".word 0x44086000 /* mfc1       $t0, $f12 */\n"
  ".word 0x44096800 /* mfc1       $t1, $f13 */\n"
  ".word 0xD8A60000 /* lqc2       $vf6, 0x0($a1) */\n"
  ".word 0x48A82000 /* qmtc2.ni   $t0, $vf4 */\n"
  ".word 0x48A92800 /* qmtc2.ni   $t1, $vf5 */\n"
  ".word 0x4BE43190 /* vmaxx.xyzw $vf6, $vf6, $vf4x */\n"
  ".word 0x4BE53194 /* vminix.xyzw $vf6, $vf6, $vf5x */\n"
  ".word 0x03E00008 /* jr         $ra */\n"
  ".word 0xF8860000 /* sqc2      $vf6, 0x0($a0) */\n"
  );
FN(func_00102F98,
  ".word 0x4BE0012C /* vsub.xyzw  $vf4, $vf0, $vf0 */\n"
  ".word 0x4A202128 /* vadd.w     $vf4, $vf4, $vf0 */\n"
  ".word 0x4BE5233D /* vmr32.xyzw $vf5, $vf4 */\n"
  ".word 0x4BE62B3D /* vmr32.xyzw $vf6, $vf5 */\n"
  ".word 0x4BE7333D /* vmr32.xyzw $vf7, $vf6 */\n"
  ".word 0xF8840030 /* sqc2       $vf4, 0x30($a0) */\n"
  ".word 0xF8850020 /* sqc2       $vf5, 0x20($a0) */\n"
  ".word 0xF8860010 /* sqc2       $vf6, 0x10($a0) */\n"
  ".word 0x03E00008 /* jr         $ra */\n"
  ".word 0xF8870000 /* sqc2      $vf7, 0x0($a0) */\n"
  );
FN(func_004135D0,
  ".word 0xD8A40000 /* lqc2       $vf4, 0x0($a1) */\n"
  ".word 0xD8C50000 /* lqc2       $vf5, 0x0($a2) */\n"
  ".word 0xD8C60010 /* lqc2       $vf6, 0x10($a2) */\n"
  ".word 0xD8C70020 /* lqc2       $vf7, 0x20($a2) */\n"
  ".word 0xD8C80030 /* lqc2       $vf8, 0x30($a2) */\n"
  ".word 0x4BE429BC /* vmulax.xyzw $ACC, $vf5, $vf4x */\n"
  ".word 0x4BE430BD /* vmadday.xyzw $ACC, $vf6, $vf4y */\n"
  ".word 0x4BE438BE /* vmaddaz.xyzw $ACC, $vf7, $vf4z */\n"
  ".word 0x4BE4410B /* vmaddw.xyzw $vf4, $vf8, $vf4w */\n"
  ".word 0x4B84217D /* vftoi4.xy  $vf4, $vf4 */\n"
  ".word 0x03E00008 /* jr         $ra */\n"
  ".word 0xF8840000 /* sqc2      $vf4, 0x0($a0) */\n"
  );
