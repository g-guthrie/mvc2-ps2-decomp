typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern f32 func_003DE700(void);
extern double func_00119058(f32);
u16 func_00417690(void) { double d = func_00119058(func_003DE700()); u32 r = (u32)(65536.0 * d / 6.283185307179586 + 0.5); return (u16)r; }
