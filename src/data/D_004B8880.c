typedef unsigned int u32;
/* 12-byte records indexed by the scene byte D_004C27D0 in func_003D14F0 (0x003D1514-0x003D1554):
 * +0 is passed to func_00122840/func_00122860 and +4 (D_004B8884) to func_00122860 for
 * scenes 3 and 0xC; +8 is not read by that reader. Seventeen records fill the span up to the
 * legal-notice table at D_004B8950. */
typedef struct { u32 arg0; u32 arg1; u32 word8; } Mvc2SceneCallWords;
Mvc2SceneCallWords D_004B8880[17] = {
    { 0x007F7F7Fu, 0x00000000u, 0x00000000u }, /* 0 */
    { 0x006061E3u, 0x00000000u, 0x00000000u }, /* 1 */
    { 0x00000000u, 0x00000000u, 0x00000000u }, /* 2 */
    { 0x00000000u, 0x00B0459Au, 0x00000000u }, /* 3 */
    { 0x007F7F7Fu, 0x00000000u, 0x00000000u }, /* 4 */
    { 0x00000000u, 0x00000000u, 0x00000000u }, /* 5 */
    { 0x007F7F7Fu, 0x00000000u, 0x00000000u }, /* 6 */
    { 0x007F7F7Fu, 0x00000000u, 0x00000000u }, /* 7 */
    { 0x00000000u, 0x00000000u, 0x00000000u }, /* 8 */
    { 0x00000000u, 0x00000000u, 0x00000000u }, /* 9 */
    { 0x006061E3u, 0x00000000u, 0x00000000u }, /* 10 */
    { 0x00000000u, 0x00000000u, 0x00000000u }, /* 11 */
    { 0x00000000u, 0x00B0459Au, 0x00000000u }, /* 12 */
    { 0x007F7F7Fu, 0x00000000u, 0x00000000u }, /* 13 */
    { 0x00000000u, 0x00000000u, 0x00000000u }, /* 14 */
    { 0x007F7F7Fu, 0x00000000u, 0x00000000u }, /* 15 */
    { 0x007F7F7Fu, 0x00000000u, 0x00000000u }, /* 16 */
};
