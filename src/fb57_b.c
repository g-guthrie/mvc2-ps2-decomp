typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003BB260(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    extern void func_00175700();
    extern s32 func_003BD4A0(u8 *);
    extern s8 func_001748C0(u8 *, f32 *);
    extern f32 func_00417440(s16);
    u8 *q;
    f32 v[3];
    f32 a, b, x, d, z;
    u32 t;
    s16 h;
    s8 ang;

    if (p[7] == 0) {
        t = p[7]; p[7] = t + 1;
        a = 6.666666507720947f;
        b = 0.4166666567325592f;
        h = *(s16 *)(p + 0x140) ^ 1;
        *(s16 *)(p + 0x140) = h;
        if (h == 0) {
            a = -a;
            b = -b;
        }
        *(f32 *)(p + 0x5C) = a;
        *(f32 *)(p + 0x68) = b;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_001757E0(p, 0x19, 0x14);
        func_001E7F60(p);
        return;
    }
    q = *(u8 **)(p + 0x18);
    v[0] = *(f32 *)(q + 0x34);
    v[1] = 274.2857055664063f + *(f32 *)(q + 0x38);
    ang = func_001748C0(p + 0x34, v);
    x = func_00417440((s16)(((0x30 - ((ang << 1) & 0xFF)) & 0x3F) << 10));
    x = 1000.0f * x;
    x = 230400.0f * x / 125000.0f / 256.0f;
    *(f32 *)(p + 0x60) = 2.142857074737549f * x;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    d = *(f32 *)(q + 0x34) - *(f32 *)(p + 0x34);
    if (*(s16 *)(p + 0x140) == 0) d = -d;
    z = 0.0f;
    if (d < z) {
        func_003BD4A0(p);
        return;
    }
    func_00175700(p);
    func_001E7F60(p);
}
