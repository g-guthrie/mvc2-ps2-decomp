typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* 003F14C0 */
typedef struct { u8 pad[8]; s32 w8; s32 wc; } N_003F14C0;
extern u8 *func_003F1620(u8 *, u32);
extern s32 D_004C2B04;
void func_003F14C0(u8 *a, s32 b) {
  N_003F14C0 *n;
  D_004C2B04++;
  n = (N_003F14C0 *)func_003F1620(a, b);
  if (n->w8 != -1) func_003F14C0(a, n->w8);
  if (n->wc != -1) func_003F14C0(a, n->wc);
}

