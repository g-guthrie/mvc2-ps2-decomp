typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002C4960(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_0018FDB0(u8 *);
    extern void func_00154790(f32 *, s32, s32, s32);
    extern void func_001266A0(u8 *, s32, s32);
    f32 v[3];
    u8 *q;
    s8 c;
    if (func_00175700(p) < 0)
        func_001843A0(p);
    c = *(s8 *)(p + 0x151);
    if (c == 0)
        return;
    if (c < 0) {
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x1B5] = 0x4A;
        func_0018FDB0(p);
        v[1] = 122.14285278320312f + *(f32 *)(p + 0x38);
        if (*(s16 *)(p + 0x140) != 0)
            *(u32 *)&v[0] = 0x42BE0000;
        else
            *(u32 *)&v[0] = 0xC2BE0000;
        v[0] += *(f32 *)(p + 0x34);
        v[2] = *(f32 *)(p + 0x3C);
        func_00154790(v, *(s16 *)(p + 0x140), 1, 0);
    } else {
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x20D] = 0;
        func_001266A0(p, 0, 0);
        q[0x1B5] = 0x24;
    }
}

void func_003634D0(u8 *p)
{
    extern void func_001ACDC0(u8 *, u8 *, u8);
    extern void func_001E3210(u8 *, s32);
    extern void func_001E7F60(u8 *);
    u8 *q;
    u8 i;
    u32 t;
    q = *(u8 **)(p + 0x18);
    if (q[4] >= 2) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        return;
    }
    *(s32 *)(p + 0x48) -= 0x800;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0 ||
        *(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430) + 34.28571319580078f) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        for (i = 0; i < 6; i++)
            func_001ACDC0(q, p, i);
        func_001E3210(q, 0x27);
        return;
    }
    func_001E7F60(p);
}

s32 func_00164780(u8 *p, u8 *r)
{
    extern s32 func_0016B240(u8 *, s32);
    extern void func_0016B0C0(u8 *, u8 *, s32);
    extern s32 func_001648E0(u8 *, u8 *);
    u8 *q;
    f32 f;
    u16 a3;
    u32 t;
    if (func_0016B240(p, 6) == 0)
        return 0;
    func_0016B0C0(p, r, 0);
    q = *(u8 **)(p + 0x220);
    func_0016B0C0(p, r, 3);
    *(f32 *)(p + 0x460) = *(f32 *)(p + 0x4C8) + 1.6666666269302368f * (f32)(u32)q[0x14E];
    func_0016B0C0(p, r, 1);
    *(s32 *)(p + 0x468) = *(s32 *)(p + 0x4C8);
    f = *(f32 *)(p + 0x460);
    if (q[0x1E6] == 0)
        f = -f;
    f += *(f32 *)(q + 0x34);
    if (f < *(f32 *)(p + 0x34)) {
        *(s32 *)(p + 0x46C) = 0;
        a3 = 0x800;
    } else {
        a3 = 0x400;
        *(s32 *)(p + 0x46C) = 1;
    }
    if (*(s32 *)(p + 0x468) < 0)
        a3 |= 0x1000;
    if (*(s32 *)(p + 0x468) > 0)
        a3 |= 0x2000;
    t = p[0x451];
    p[0x451] = t + 1;
    *(s32 *)(p + 0x464) = p[0x1E4];
    *(s32 *)(p + 0x468) = a3;
    *(s16 *)(p + 0x4F0) = a3;
    *(s8 *)(p + 0x4B6) = -0x4C;
    return func_001648E0(p, r);
}

s32 func_00164E90(u8 *p, u8 *r)
{
    extern void func_00186CE0(u8 *, s32);
    extern s32 func_00164D10(u8 *, u8 *);
    u8 *q;
    f32 f;
    u32 t;
    q = *(u8 **)(p + 0x220);
    *(f32 *)(p + 0x460) += 1.6666666269302368f * (f32)(u32)q[0x14E];
    f = *(f32 *)(p + 0x460);
    if (q[0x1E6] == 0)
        f = -f;
    f += *(f32 *)(q + 0x34);
    if (f < *(f32 *)(p + 0x34)) {
        if (p[0x454] == 0x26 && p[0x1E6] != 0)
            return 0;
        *(s32 *)(p + 0x464) = 0x800;
        *(s32 *)(p + 0x46C) = 0;
        p[0x1E7] = p[0x1E6];
    } else {
        if (p[0x454] == 0x26 && p[0x1E6] == 0)
            return 0;
        *(s32 *)(p + 0x464) = 0x400;
        *(s32 *)(p + 0x46C) = 1;
        p[0x1E7] = *(s8 *)(p + 0x1E6) ^ 1;
    }
    t = p[0x451];
    p[0x451] = t + 1;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    *(s32 *)(p + 0x468) = 1;
    *(s16 *)(p + 0x4F0) = *(s16 *)(p + 0x464);
    *(s8 *)(p + 0x4B6) = -0x4C;
    *(u16 *)(p + 0x35E) = *(u16 *)(p + 0x4F0);
    func_00186CE0(p, 1);
    *(u16 *)(p + 0x35E) = 0;
    return func_00164D10(p, r);
}

void func_002FE620(u8 *p)
{
    extern s32 func_00185980(u8 *);
    extern void func_00185640(u8 *, u8 *);
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *a1;
    u32 t;
    s16 h;
    if (func_00185980(p) != 0) {
        if (p[0x20D] != 2)
            p[0x20B] = 0;
        else
            p[0x20B] = 4;
        t = p[0x20B];
        p[0x20B] = t | 0x40;
        t = p[0x20B];
        p[0x20B] = t | 0x80;
        p[7] = 0;
        p[6] = 0;
        a1 = *(u8 **)(p + 0x1C4);
        *(s32 *)(a1 + 0x6C) = 0;
        *(s32 *)(a1 + 0x68) = 0;
        *(s32 *)(a1 + 0x60) = 0;
        *(s32 *)(a1 + 0x5C) = 0;
        func_00185640(p, a1);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h != 0)
        return;
    t = p[6];
    p[6] = t + 1;
    if (p[0x20D] != 2)
        p[0x168] = *(s8 *)(p + 0x1B7) + 6;
    else
        p[0x168] = *(s8 *)(p + 0x1B7) + 9;
    func_001757E0(p, 0x15, p[0x168]);
    *(f32 *)(p + 0x5C) /= 2.0f;
    *(f32 *)(p + 0x68) /= 8.0f;
    if (p[0x20D] == 2) {
        *(s32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
}
