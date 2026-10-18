typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00450930[];
extern u8 D_00450934[];

void func_0020D900(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_001757E0(u8 *, s32, u8);
    if (func_00175700(p) < 0) {
        u32 t = p[6];
        u32 k;
        f32 v;
        p[6] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(s16 *)(p + 0x1C) = 0x20;
        k = p[0x212] << 1;
        if (p[0x1E6] != 0) {
            v = *(f32 *)(D_00450930 + (k + p[0x1B7]) * 8);
        } else {
            v = -*(f32 *)(D_00450930 + (k + p[0x1B7]) * 8);
        }
        *(f32 *)(p + 0x5C) = v;
        *(f32 *)(p + 0x60) = *(f32 *)(D_00450934 + (k + p[0x1B7]) * 8);
        func_001E3210(p, 6);
        p[0x168] = (p[0x212] != 0) ? 0x15 : 0x18;
        func_001757E0(p, 0x15, p[0x168] + p[0x1B7] * 2);
    }
}
