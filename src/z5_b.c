typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004C2840;

s32 func_001FC240(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    extern u8 D_0044FE50[];
    u8 v;
    if (func_00189310(p, D_0044FE50, p + 0x388) == 0) return 0;
    if (*(f32 *)(p + 0x38) < 137.142853f + *(f32 *)(p + 0x430)) {
        return 0;
    }
    if (*(s8 *)(p + 0x1E8) != 0) {
        if (p[0x210] == 0) return 0;
    }
    v = 1;
    p[0x1E8] = v;
    func_0018A990(p, p + 0x388);
    p[5] = 0;
    p[6] = 1;
    p[7] = 0;
    p[0x1FD] = v;
    func_00186A60(p, 0x15);
    return 1;
}

typedef struct { u8 p0[0x34]; f32 f34; f32 f38; } O1;

s32 func_0035AAA0(u8 *p, s8 *q) {
    O1 *o;
    O1 *pp = (O1 *)p;
    extern void func_0035AE70();
    o = *(O1 **)(p + 0x18);
    if (q[0xD] == 0) {
        if (((u8*)o)[0x1E4] == 0x1C && ((u8*)o)[0x26A] == 2) {
            q[0xD] = -1;
            q[0xE] = 0x14;
        } else if (((u8*)o)[0] == 0) {
            q[0xD] = -1;
            q[0xE] = 0x14;
        } else {
            return 0;
        }
    }
    if (q[0xE] == 0) return 0;
    {
        s8 v = q[0xE] - 1;
        q[0xE] = v;
        if (v != 0) return 0;
    }
    pp->f34 = o->f34;
    {
        f32 c = 137.142853f; f32 t = o->f38; pp->f38 = t; pp->f38 = t + c;
    }
    p[0x20] = 0;
    func_0035AE70(p);
    return 1;
}
