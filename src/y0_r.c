typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_0045BD10[];

s32 func_002F6B00(u8 *p)
{
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    u8 *q;
    s32 i, n, v;
    q = p + 0x2B8;
    if (func_00189310(p, D_0045BD10, p + 0x380) == 0)
        return 0;
    n = 0;
    i = 0;
    do {
        if (q[i] != 0)
            n++;
        i++;
    } while (i < 6);
    if (n == 6)
        return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            v = *(s8 *)(p + 0x1E8);
            if (v != 0)
                return 0;
            p[0x1E8] = v + 1;
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

s32 func_0031CCD0(u8 *p)
{
    extern void func_00175700();
    extern void func_00184540();
    extern void func_00183d50();
    extern void func_001757E0();
    u8 k;
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 0x1B2) != 0) {
        *(u32 *)(p + 0x5C) = 0x40BAAAAA;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x41700000;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        if (p[0x1E6] != 0)
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(s8 *)(p + 0x1E7) = -1;
        k = p[0x1E6];
        func_00184540(p);
        p[0x1E6] = k;
        *(s16 *)(p + 0x140) = k;
    } else if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_00183d50(p);
        func_001757E0(p, 1, 3);
    }
}
