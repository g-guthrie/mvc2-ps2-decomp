typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;

void func_003B1AA0(u8 *p, u8 *q)
{
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    if (p[0x20] == 2) {
        if (*(s16 *)(p + 0x140) == 0)
            *(f32 *)(p + 0x34) += -26.666666f;
        else
            *(f32 *)(p + 0x34) += 26.666666f;
    } else {
        if (*(s16 *)(p + 0x140) == 0)
            *(f32 *)(p + 0x34) += -53.3333321f;
        else
            *(f32 *)(p + 0x34) += 53.3333321f;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
}

void func_001FDF90(u8 *p)
{
    extern s8 func_00175700();
    extern void func_001E3270(u8 *, s32, f32);
    extern void func_001843A0(u8 *);
    u8 *c;
    f32 *a;
    f32 *d;
    f32 *b;
    f32 *e;
    c = (u8 *)(p + 0x2B8);
    a = (f32 *)(p + 0x5C);
    b = (f32 *)(p + 0x68);
    d = (f32 *)(p + 0x60);
    e = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00175700(p) < 0) {
        *a = 0;
        *d = 0;
        *b = 0;
        *e = 0;
        c[0x1C] = 0;
        func_001E3270(p, 0x1F, 32.0f);
        func_001843A0(p);
    }
}

void func_002C2CD0(u8 *p)
{
    extern s8 func_00175700();
    extern void func_002C5030(u8 *);
    f32 v;
    u8 t;
    u8 *q;
    if (func_00175700(p) < 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 0x10;
        p[0x209] = 1;
        p[0x13C] = 0;
        p[0x159] = 0xFF;
        t = p[0x1B7];
        q = *(u8 **)(p + 0x220);
        if (t == 0)
            v = 160.0f;
        if (t == 1)
            v = -160.0f;
        if (t == 2)
            v = 426.666656f;
        if (t == 3)
            v = -426.666656f;
        if (p[0x1E6] == 0)
            v = -v;
        *(f32 *)(p + 0x5C) = (*(f32 *)(q + 0x34) + v - *(f32 *)(p + 0x34)) / 16.0f;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x6C) = 0;
    }
    func_002C5030(p);
}

void func_00174A40(u8 *p, s32 n)
{
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    f32 a = 256.0f * (f32)n;
    s16 ang = (s16)(((40 - p[0x22]) & 0x1F) << 11);
    *(f32 *)(p + 0x34) += 1.66666663f * (a * (1000.0f * func_00417500(ang)) / 100000.0f / 256.0f);
    *(f32 *)(p + 0x38) += 2.14285707f * (a * (1000.0f * func_00417440(ang)) / 125000.0f / 256.0f);
}

void func_0026A850(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001264D0();
    extern void func_001E3210(u8 *, s32);
    extern void func_0015B660(f32 *, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_001266A0(u8 *, s32, s32);
    f32 v[4];
    f32 c, t;
    u8 *q;
    func_00175700(p);
    if (*(s8 *)(*(u8 **)(p + 0x14) + 0x151) != 0) {
        p[6]++;
        func_001757E0(p, 0x15, 0x10);
        q = *(u8 **)(p + 0x1DC);
        q[0x13C] = 1;
        *(u32 *)(q + 0x50) = 0x3F800000;
        *(u32 *)(q + 0x54) = 0x3F800000;
        q[0x1B5] = 0x3D;
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        func_001264D0();
        func_001E3210(p, 0x2B);
        v[0] = *(f32 *)(p + 0x34);
        if (*(s16 *)(p + 0x140) != 0)
            c = 186.666656f;
        else
            c = -186.666656f;
        v[0] += c;
        t = *(f32 *)(p + 0x38);
        v[1] = t;
        v[1] += 80.0f;
        func_0015B660(v, 1);
        func_001E3710(p, 0x49);
        func_001266A0(p, 0xD, 7);
    }
}
