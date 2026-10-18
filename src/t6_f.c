typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
extern u8 D_00454090[];
s32 func_00262320(u8 *p) {
    if (func_00189310(p, D_00454090, p + 0x378) == 0) return 0;
    if (p[0x20D] == 2 && p[0x210] == 0) {
        s8 t = *(s8 *)(p + 0x1E8);
        if (t != 0) return 0;
        p[0x1E8] = t + 1;
    }
    if (*(s16 *)(p + 0x2D6) != 0) return 0;
    func_0018A990(p, p + 0x378);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

