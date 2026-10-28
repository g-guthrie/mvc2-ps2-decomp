typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_00445E70[];
extern u8 D_00445E90[];
extern u8 D_00445EB0[];
/* func_00169CE0 (src/y11_g.c) case 2 loads *(D_00445E5C + a1 * 4); the
 * selector table D_004461A0 yields case 2 only for a1 = 29..31, so the
 * words read are these three at 0x00445ED0 (= D_00445E5C + 29 * 4). */
u8 *D_00445ED0[3] = { D_00445EB0, D_00445E70, D_00445E90 };
