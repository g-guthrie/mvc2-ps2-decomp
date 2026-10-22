typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;

void func_001FB000(u8 *p)
{
    extern void func_00183d50();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    f32 *v1, *a1, *a2, *a3;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    v1 = (f32 *)(p + 0x5C);
    a2 = (f32 *)(p + 0x68);
    a1 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    a3 = (f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[6]++;
        p[0x20D] = 0;
        *v1 = 0;
        *a1 = 0;
        *a2 = 0;
        *a3 = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183d50(p);
        func_001757E0(p, 0x14, 7);
    } else {
        func_00175700(p);
    }
}

void func_0031F800(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00175910(u8 *, s32, s32, s32);
    s16 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        p[7]++;
        *(u32 *)(p + 0x5C) = 0xC0555555;
        if (p[0x1E6] != 0)
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(u32 *)(p + 0x60) = 0x414DB6DB;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        func_00175910(p, 1, 1, 4);
    }
}
extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];

void func_00260A40(u8 *p)
{
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_0036BFF0(u8 *, s32, s32, s32);
    extern s32 func_00174170();
    extern void func_001E3210(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    f32 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[6]++;
    func_001266A0(p, 1, 0xD);
    if (*(s16 *)(p + 0x140) != 0)
        v = 80.0f + D_004F1FC8[0];
    else
        v = D_004F1FCC[0] - 80.0f;
    *(f32 *)(p + 0x34) = v;
    *(s16 *)(p + 0x1C) = 0xB4;
    func_0036BFF0(p, 0xF, 0x13, 0xF);
    p[7] = func_00174170();
    { u32 t = p[7]; p[7] = t & 1; }
    func_001E3210(p, 5);
    func_001757E0(p, 0x16, 0xB);
    func_00175700(p);
}

void func_002BC490(u8 *p, f32 *q)
{
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x38) <= *q)) {
        if (!(*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)))
            return;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
    }
    p[6]++;
    *(f32 *)(p + 0x5C) /= 2.0f;
    *(f32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    func_001757E0(p, 0x15, 0x16);
}

void func_0021A340(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00175910(u8 *, s32, s32, s32);
    s16 v;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[7]++;
        *(u32 *)(p + 0x5C) = 0xC0555555;
        if (p[0x1E6] != 0)
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(u32 *)(p + 0x60) = 0x414DB6DB;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        func_00175910(p, 1, 1, 4);
    }
}

void func_003BEA80(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    f32 z = 0.0f;
    f32 d;
    s16 v;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1E) + 0x2000;
    *(s16 *)(p + 0x1E) = v;
    if (v == 0)
        p[0x1B2] = 0;
    d = *(f32 *)(p + 0x34) - (f32) * (s32 *)(p + 0xD0);
    if (d < z)
        d = -d;
    if (d < 80.0f) {
        p[5]++;
        func_001757E0(p, 0x16, 1);
    }
    func_001E7F60(p);
}

void func_003134E0(u8 *p, u8 *q)
{
    extern void func_00313BF0();
    extern void func_00313B80(u8 *, u8 *);
    extern void func_00313C40(u8 *, u8 *);
    extern void func_00313C70(u8 *, u8 *);
    extern s8 func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
    func_00313BF0(p);
    func_00313B80(p, q);
    if (q[0xF] == 0)
        func_00313C40(p, q);
    else
        func_00313C70(p, q);
    if (*(s8 *)(p + 0x151) == 0) {
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    if (func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 0x16, 0x16);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
    }
}

void func_002774C0(u8 *p)
{
    u8 a;
    extern void func_00275A40(u8 *);
    extern s8 func_00175700();
    extern void func_00184540(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_0037A810(u8 *, u8);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00275A40(p);
    if (func_00175700() < 0) {
        if (p[0x20D] != 2)
            func_001843A0(p);
        else
            func_00184540(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        *(s32 *)(p + 0x2C8) = 1;
        if (*(s32 *)(p + 0x2C4) != 0)
            *(s32 *)(p + 0x2C8) = 0;
        a = 0;
        if (p[0x20D] == 2)
            a = 2;
        func_0037A810(p, a);
        *(s32 *)(p + 0x2CC) = 1;
    }
}

void func_001BE470(u8 *p, u8 *q, s32 n)
{
    extern s32 func_00174170();
    extern s32 func_001BC720(u8 *, u8 *, u8, s32);
    u8 a, m;
    if ((p[0x23] & 3) == 3 || (func_00174170() & 3) != 0) {
        func_001BC720(q, p, 1, n);
        return;
    }
    if ((func_00174170() & 1)) {
        if (!(p[0x23] & 1)) {
            a = 7;
            m = 1;
        } else {
            a = 8;
            m = 2;
        }
    } else {
        if (!(p[0x23] & 2)) {
            a = 8;
            m = 2;
        } else {
            a = 7;
            m = 1;
        }
    }
    if (func_001BC720(q, p, a, n))
        p[0x23] |= m;
}
extern void (*D_0044B160[])(u8 *, u8 *, u8 *);

void func_001A4770(u8 *a, void *owner)
{
    u8 *b = (u8 *)owner;
    u8 *c = b + 0x2B8;
    if (b[0x1E4] == 0x1C || b[5] != 0 || b[0x1FD] != 4 || *(s8 *)(c + 4) < 0) {
        a[4] = 2;
        a[0x13C] = 0;
    } else {
        a[0x24] = 0xC;
        D_0044B160[a[5]](a, b, c);
    }
}
