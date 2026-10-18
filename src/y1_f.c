typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_00455950[];

s32 func_00281640(u8 *p)
{
    extern s32 func_00189950();
    extern s32 func_0018A580();
    extern void func_0018A990();
    extern void func_00186A60();
    if (func_00189950(p, D_00455950, p + 0x3B8) == 0) return 0;
    if (func_0018A580(p) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            if (*(s8 *)(p + 0x1E8) != 0) return 0;
            { s32 t = *(s8 *)(p + 0x1E8); p[0x1E8] = t + 1; }
        }
    }
    func_0018A990(p, p + 0x3B8);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 6;
    func_00186A60(p, 0x15);
    return 1;
}
extern u8 D_004511C0[];

s32 func_0021CBD0(u8 *p)
{
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    u8 *o = p + 0x2B8;
    if (func_00189310(p, D_004511C0, p + 0x380) == 0) return 0;
    if (o[0xA] != 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            if (*(s8 *)(p + 0x1E8) != 0) return 0;
            { s32 t = *(s8 *)(p + 0x1E8); p[0x1E8] = t + 1; }
        }
    }
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}
extern u8 D_00456D00[];

s32 func_0028DD20(u8 *p)
{
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();

    if (func_00189310(p, D_00456D00, p + 0x380) == 0) return 0;
    {
        u8 *o = p + 0x2B8;
        if (p[0x20D] != 2) {
            if (o[0x1D] != 0) return 0;
        } else {
            if (o[0x1D] > 2) return 0;
            if (p[0x210] == 0) {
                if (*(s8 *)(p + 0x1E8) != 0) return 0;
                { s32 t = *(s8 *)(p + 0x1E8); p[0x1E8] = t + 1; }
            }
        }
    }
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 2;
    func_00186A60(p, 0x15);
    return 1;
}
typedef void (*Fn)(u8 *, u8 *);
extern Fn D_00451180[];

void func_0021C4A0(u8 *p)
{
    extern s8 func_00175700();
    extern void func_00184540();
    extern s32 func_00182E20();
    extern s32 func_00182D30();
    extern void func_001757E0();
    u8 *o, *q;
    q = *(u8 **)(p + 0x1DC);
    o = p + 0x2B8;
    if (func_00175700(p) < 0 && *(s8 *)(o + 0xC) <= 0) {
        *(s8 *)(p + 0x1B1) = -0x80;
        p[0x201] = 0;
        func_00184540(p);
        return;
    }
    if (*(s8 *)(o + 0xC) > 0) {
        if (func_00182E20(p) != 0) p[0x152] = 1;
        {
            s32 t = *(s16 *)(q + 0x270) - 1;
            *(s16 *)(q + 0x270) = t;
        }
        if (func_00182D30(q) != 0) {
            *(s8 *)(o + 0xC) = -1;
            func_001757E0(p, 0xF, 5);
        }
    }
    D_00451180[*(s8 *)(p + 0x151) >> 1](p, q);
}
