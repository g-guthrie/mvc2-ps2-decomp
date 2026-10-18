typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern void func_003D3080(s32 a);

void func_003D33B0(u8 *p) {
    p[0] = 0;
    p[6] = 0;
    p[7] = 0;
    D_004C2840[0x91] = 0;
    if (*(s8 *)(D_004C2840 + 0x5C) != 0) {
        func_003D3080(0);
    }
}
