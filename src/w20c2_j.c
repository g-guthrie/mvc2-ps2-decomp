typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_00168E80(); extern void func_001695A0(u8 *); extern void func_00169F40(u8 *); extern s32 func_00169AE0(u8 *, s32); extern s32 func_00169BC0(u8 *, s32);
s32 func_00169960(u8 *p){
  u8 *q;
  if (p[0x496] == 0) {
    q = *(u8 **)(p + 0x220);
    if (q[5] == 0) {
      if (q[0x1E4] < 2) { func_00168E80(); func_001695A0(p); return 1; }
      if (p[0x1E4] >= 5 && p[0x1E4] < 10) { func_00168E80(); func_001695A0(p); return 1; }
    }
  }
  switch (p[0x451]) {
    case 0: p[0x451] = p[0x451] + 1; func_00169F40(p);
    case 1: return func_00169AE0(p, 2);
    case 2: return func_00169BC0(p, 2);
  }
  return 0;
}
