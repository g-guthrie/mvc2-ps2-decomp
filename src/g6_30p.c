typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *D_004D3690[]; void func_003DA6F0(u8 idx){ u8 *n = D_004D3690[idx];
while (n) { (*(void (**)(u8 *))(n + 0x10))(n); n = *(u8 **)(n + 0xC); } }
