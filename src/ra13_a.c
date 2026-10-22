typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
extern u8 *D_004C2974 __attribute__((section(".sdata")));
extern void (*jtbl_004637F0[])(u8 *);
void func_00366350(u8 *p) {
 u8 *o = *(u8 **)(p + 0x18);
 if (o[0x425] != 0 || o[5] == 0 && o[0x1E4] == 0x1D) {
  D_004C2974[0xE] = 1;
 } else {
  D_004C2974[0xE] = 0;
 }
 if (o[5] == 2) D_004C2974[0xF] = 1;
 *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
 jtbl_004637F0[p[5]](p);
}
