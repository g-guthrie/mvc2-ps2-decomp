typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004C2B18[8];
s32 func_004118A8(s32 a, s32 b) { s32 *p = (s32 *)D_004C2B18; p[1] = b; p[0] = a; return (s32)p; }
