typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* 003EB210 */
extern void func_003EB260(void);
extern void func_003EB5D0(void);
s32 func_003EB210(s32 a, s32 b, s32 c, s32 d, s32 t0) {
  switch (t0) {
  case 0: func_003EB260(); return 0;
  case 1: func_003EB5D0(); return 0;
  default: return -1;
  }
}

