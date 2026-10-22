typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002277D0(u8 *p)
{
    extern void func_00175700(void);
    extern void func_001757E0(u8 *, s32, s32);
    s16 v;
    f32 c;
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700();
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        t = p[6];
        p[6] = t + 1;
        c = -0.5208333134651184f;
        if (p[0x1E6] != 0) c = -c;
        *(f32 *)(p + 0x68) = c;
        func_001757E0(p, 2, 3);
    }
}

void func_00319A50(u8 *p)
{
    extern void func_00318500(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern s8 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00176160(u8 *, s32, s32, s32);
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        func_00318500(p);
        func_001757E0(p, 0x14, 2);
        return;
    }
    if (func_00175700(p) < 0) {
        func_001843A0(p);
    } else if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        if (p[0x15B] != 0) {
            func_00175C00(p, 0);
        } else {
            func_00176160(p, 0, p[0x25] * 2 + 6, 1);
        }
    }
}

void func_002670A0(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_00267E20(u8 *);
    extern u8 *func_001B3E30(u8 *, int, int);
    s8 a;
    f32 c;
    if (func_00175700(p) < 0) {
        func_00267E20(p);
        return;
    }
    a = *(s8 *)(p + 0x151);
    if (a == 1) {
        *(s8 *)(p + 0x151) = 0;
        func_001B3E30(p, 0x16, 0xD);
        func_001B3E30(p, 0x17, 0xD);
        func_001B3E30(p, 0x18, 0xD);
    } else if (a == 2) {
        *(s8 *)(p + 0x151) = 0;
        if (*(s16 *)(p + 0x140) != 0) c = 26.666666030883789f;
        else c = -26.666666030883789f;
        *(f32 *)(p + 0x34) += c;
    }
}

void func_0022F9E0(u8 *p, u8 *q)
{
    extern void func_00175700(u8 *);
    extern s32 func_001864A0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00183D50(u8 *);
    u32 t;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864A0(p) != 0) {
        t = p[7];
        p[7] = t + 1;
        p[0x169] = 0x15;
        if (q[0xE] != 0) {
            p[0x168] = *(s8 *)(p + 0x1B7) + 7;
        } else {
            p[0x168] = *(s8 *)(p + 0x1B7) + 0xB;
        }
        func_001757E0(p, p[0x169], p[0x168]);
        func_00183D50(p);
    }
}

extern f32 D_004F1FC8;
extern f32 D_004F1FCC;
s32 func_001BF5C0(u8 *p)
{
    s32 r = 1;
    s16 h = *(s16 *)(p + 0x140);
    if ((h == 0 && *(f32 *)(p + 0x34) < D_004F1FC8 - 1.6666666269302368f * (f32)(u32)p[0x14F]) ||
        (h != 0 && !(*(f32 *)(p + 0x34) <= D_004F1FCC + 1.6666666269302368f * (f32)(u32)p[0x14F])))
        r = 0;
    return r;
}

void func_001FE480(u8 *p)
{
    extern int func_00175700(u8 *);
    extern void func_001E3270(u8 *, s32, f32);
    extern void func_001843A0(u8 *);
    u8 *b; f32 *v5c; f32 *v60; f32 *v68; f32 *v6c;
    b = p + 0x2B8;
    v5c = (f32 *)(p + 0x5C);
    v68 = (f32 *)(p + 0x68);
    v60 = (f32 *)(p + 0x60);
    v6c = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) < 0) {
        *v5c = 0;
        *v60 = 0;
        *v68 = 0;
        *v6c = 0;
        b[0x1C] = 0;
        func_001E3270(p, 0x1F, 32.0f);
        func_001843A0(p);
    }
}

void func_002211E0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern s32 func_001864A0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 *v5c; f32 *v60; f32 *v68; f32 *v6c;
    f32 z = 0.0f;
    u32 t;
    func_00175700(p);
    v5c = (f32 *)(p + 0x5C);
    v68 = (f32 *)(p + 0x68);
    v60 = (f32 *)(p + 0x60);
    v6c = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) < z) {
        *(f32 *)(p + 0x5C) = z;
        if (func_001864A0(p) != 0) {
            t = p[6];
            p[6] = t + 1;
            p[0x20D] = 0;
            func_001757E0(p, 0x15, 0xE);
            *v5c = 0;
            *v60 = 0;
            *v68 = 0;
            *v6c = 0;
        }
    }
}

void func_003ADE90(u8 *p)
{
    f32 lim;
    f32 y;
    u8 *r;
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (p[5] != 0) lim = 17.14285659790039f;
    else lim = 7.5f;
    if (!(*(f32 *)(p + 0x60) <= lim)) {
        *(u32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x60) = lim;
    }
    r = *(u8 **)(p + 0x18);
    y = 102.85713958740234f + *(f32 *)(r + 0x38);
    if (p[0x21] != 0) y += 34.28571319580078f;
    if (p[5] != 0) y += 274.28570556640625f;
    if (!(*(f32 *)(p + 0x38) <= y)) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}

void func_002E2230(u8 *p)
{
    extern s32 func_00174170(void);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_003D92F0(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_00175700(u8 *);
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        switch (p[0x20]) {
        case 0:
            if ((func_00174170() & 1) != 0) {
                func_001757E0(p, 0x13, 0);
            } else {
                func_001757E0(p, 0x13, 1);
            }
            break;
        case 1:
        case 3:
        case 4:
            func_001757E0(p, 0x13, 3);
            break;
        case 2:
            func_001757E0(p, 0x13, 2);
            break;
        }
    }
    if (func_003D92F0(p) != 0) {
        func_001843A0(p);
    } else {
        func_00175700(p);
    }
}

extern f32 D_004F1FD0;
void func_003C2B50(u8 *p)
{
    extern s32 func_00118FA8(f32);
    s16 *a;
    u32 t;
    *(f32 *)(p + 0x34) = 320.0f + D_004F1FC8;
    a = (s16 *)(p + 0xD0);
    a[1] = func_00118FA8(68.57142639160156f + D_004F1FD0);
    a[0] = func_00118FA8((f32)a[0] + *(f32 *)(p + 0x60));
    *(f32 *)(p + 0x38) = (f32)(a[1] - a[0]);
    if (!((f32)a[0] < 51.42856979370117f)) {
        a[0] = 0x33;
        *(f32 *)(p + 0x38) = (f32)(a[1] - a[0]);
        t = p[5];
        p[5] = t + 1;
    }
}

void func_0022B130(u8 *p)
{
    extern void func_00175700(u8 *);
    f32 z = 0.0f;
    f32 c1, c2;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < z)) {
        *(f32 *)(p + 0x68) = z;
        *(f32 *)(p + 0x5C) = z;
    }
    if (*(s8 *)(p + 0x151) == 2) {
        *(s8 *)(p + 0x151) = 0;
        c1 = -16.66666603088379f;
        c2 = 0.625f;
        if (*(s16 *)(p + 0x140) != 0) {
            c1 = -c1;
            c2 = -c2;
        }
        *(f32 *)(p + 0x5C) = c1;
        *(f32 *)(p + 0x68) = c2;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        c1 = -20.0f;
        c2 = 0.625f;
        if (*(s16 *)(p + 0x140) != 0) {
            c1 = -c1;
            c2 = -c2;
        }
        *(f32 *)(p + 0x5C) = c1;
        *(f32 *)(p + 0x68) = c2;
        *(f32 *)(p + 0x60) = 34.28571319580078f;
        *(f32 *)(p + 0x6C) = -1.0714285373687744f;
    }
}

void func_002BA430(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00183D50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 z = 0.0f;
    f32 old;
    f32 *a;
    f32 *b;
    u32 t;
    old = *(f32 *)(p + 0x5C);
    a = (f32 *)(p + 0x5C);
    b = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((old > z && *(f32 *)(p + 0x5C) < z) || (old < 0 && *(f32 *)(p + 0x5C) > 0)) {
        *a = 0;
        *b = 0;
    }
    func_00175700(p);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183D50(p);
        func_001757E0(p, 0x15, 5);
    }
}

void func_00201260(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001830D0(u8 *, f32 *, s32);
    f32 v[4];
    u8 *s;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    s = p + 0x2B8;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if (func_00175700(p) < 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        *(s16 *)(p + 0x1C) = 0x1E;
        *(u32 *)(p + 0x5C) = 0x41555555;
        *(u32 *)(p + 0x68) = 0xBDD55555;
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        p[0x20D] = 2;
        func_001757E0(p, 0x16, 7);
        s[0x1C] = 1;
        v[0] = -26.66666603088379f;
        v[1] = 137.14285278320312f;
        func_001830D0(p, v, 1);
    }
}

void func_00391B50(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    if (p[6] == 0) {
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) <= *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
            t = p[6];
            p[6] = t + 1;
            *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
            func_001757E0(p, 0x17, 1);
        }
    } else {
        func_00175700(p);
        if (*(s8 *)(p + 0x151) == 0) {
            t = p[5];
            p[5] = t + 1;
            p[6] = 0;
            *(f32 *)(p + 0x60) *= -1.0f;
            *(f32 *)(p + 0x60) /= 2.0f;
            *(s16 *)(p + 0x1C) = 0x40;
            func_001757E0(p, 0x17, 0);
        }
    }
}

s32 func_0037F550(u8 *p)
{
    s32 r = 1;
    s16 h = *(s16 *)(p + 0x140);
    if ((h == 0 && *(f32 *)(p + 0x34) < D_004F1FC8 - 1.6666666269302368f * (f32)(u32)p[0x14F]) ||
        (h != 0 && !(*(f32 *)(p + 0x34) <= D_004F1FCC + 1.6666666269302368f * (f32)(u32)p[0x14F])))
        r = 0;
    return r;
}
