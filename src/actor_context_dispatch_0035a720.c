/* Provisional: side and selector bounds and callback ownership remain unresolved. */
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
extern u8 D_004D18A6;
extern s32 func_0035AAA0(u8 *, s8 *);
extern void (*jtbl_00463130[])(u8 *, u8 *);
void func_0035A720(u8 *actor,u8 *context) {
 u8 *owner=*(u8 **)(actor+0x18);
 owner[0x2c6]=1;
 if (!(D_004D18A6 & (1 << (owner[2]^1))) && !func_0035AAA0(actor,(s8 *)context))
  jtbl_00463130[actor[0x21]](actor,context);
}
