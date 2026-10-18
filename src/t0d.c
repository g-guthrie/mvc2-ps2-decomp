typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00452B70[];
extern s32 func_00189310(u8 *p, u8 *a, u8 *b);
extern void func_00186A60(u8 *p, s32 a);
s32 func_002439D0(u8 *p) {
    s8 v;
    s32 r;
    if ((r = func_00189310(p, D_00452B70, p + 0x398)) == 0) return 0;
    if (p[0x20D] == 2 && p[0x210] == 0) {
        v = p[0x1E8];
        if (v != 0) return 0;
        p[0x1E8] = v + 1;
    }
    if (**(s8 **)(p + 0x420) == 0) return 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 3;
    func_00186A60(p, 0x1D);
    return 1;
}
