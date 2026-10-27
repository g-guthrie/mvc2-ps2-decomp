typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
extern V3 D_004B1940[];

extern void func_0013E760(u8 *p);

/* func_0013EA00: not yet matched without a stand-in callee. */

typedef struct { u8 pad0[0x7C]; s16 h7c[1]; } G12;
extern G12 *D_004C2794;
typedef struct { f32 x, y; u8 b8; } G40;
extern G40 *D_004C2940;

void func_0023E180(u8 *p, s32 a1) {
    extern void func_00185490(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00183D10(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0023E260(u8 *, s32);
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    { u32 t = p[6]; p[6] = t + 1; }
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x1B5] = 0x4F;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]]++;
    func_001757E0(p, 0x16, 0xA);
    func_0023E260(p, a1);
}

void residual_002ECA50(u8 *p, s32 a1) {
    extern void func_00185490(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00183D10(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_002ECB30(u8 *, s32);
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    { u32 t = p[6]; p[6] = t + 1; }
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x1B5] = 0x3E;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]]++;
    func_001757E0(p, 0x16, 3);
    func_002ECB30(p, a1);
}

void func_00182AA0(u8 *p, u8 *q, u8 *r) {
    extern void func_001843A0(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00186CE0(u8 *, s32);
    f32 k = 35.0f + (*(f32 *)(r + 0xC) - 320.0f) - 160.0f;

    if (p[1] == 0x29)
        k -= 53.33333206176758f;

    if (*(f32 *)(p + 0x34) <= k) {
        if (q[5] != 0 || p[0x1E4] != 10) {
            *(f32 *)(p + 0x34) = k;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x215] = 0;
            func_001843A0(p);
            func_00175C00(p, 1);
            if (q[5] == 0) {
                func_00186CE0(p, 10);
                return;
            }
        }
    } else if (q[5] == 0 && p[0x1E4] != 10) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x215] = 0;
        func_001843A0(p);
        func_00175C00(p, 1);
        func_00186CE0(p, 10);
    }
}

void func_00311490(u8 *p) {
    extern s8 func_00175700();
    extern void func_00184540();
    extern void func_001DD8A0();
    if (func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    if (*(s8 *)(p + 0x151) & 2) {
        *(s8 *)(p + 0x151) &= ~2;
        func_001DD8A0(p, 9, 6);
    }
    if (*(s8 *)(p + 0x151) & 4) {
        *(s8 *)(p + 0x151) &= ~4;
        func_001DD8A0(p, 9, 7);
    }
    if (*(s8 *)(p + 0x151) & 8) {
        *(s8 *)(p + 0x151) &= ~8;
        p[0x1B5] = 0x1B;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->h7c[p[2]]++;
    }
}

void func_0034DC70(u8 *p) {
    extern f32 func_00417500();
    extern f32 func_00417440();
    f32 a, b;
    a = 10.0f * func_00417500(((0x28 - p[0x22]) & 0x1F) << 11);
    a += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x5C) = a;
    D_004C2940->x += a;
    b = 12.857142448425293f * func_00417440(((0x28 - p[0x22]) & 0x1F) << 11);
    if (D_004C2940->b8) b *= -1.0f;
    b += *(f32 *)(p + 0x6C);
    *(f32 *)(p + 0x60) = b;
    D_004C2940->y += b;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34) + D_004C2940->x;
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38) + D_004C2940->y;
}

void func_0026A5B0(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    u8 *q = *(u8 **)(p + 0x1DC);
    f32 k = 0.04166666790843010f;
    *(s32 *)(q + 0x48) += 0x2000;
    *(f32 *)(q + 0x50) -= k;
    *(f32 *)(q + 0x54) -= k;
    *(f32 *)(*(u8 **)(p + 0x1DC) + 0x34) += *(f32 *)(*(u8 **)(p + 0x1DC) + 0x5C);
    *(f32 *)(*(u8 **)(p + 0x1DC) + 0x5C) += *(f32 *)(*(u8 **)(p + 0x1DC) + 0x68);
    *(f32 *)(*(u8 **)(p + 0x1DC) + 0x38) += *(f32 *)(*(u8 **)(p + 0x1DC) + 0x60);
    *(f32 *)(*(u8 **)(p + 0x1DC) + 0x60) += *(f32 *)(*(u8 **)(p + 0x1DC) + 0x6C);
    func_00175700(p);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) {
            u32 t = p[6]; p[6] = t + 1;
            q[0x13C] = 0;
            q[0x159] = 0xFF;
            func_001757E0(p, 0x15, 0xF);
        }
    }
}

void func_00349040(u8 *p, u8 *q) {
    extern void func_00175910();
    extern void func_0034A080();
    u8 *r = *(u8 **)(p + 0x14);
    u16 *d = (u16 *)(p + 0x88);
    *(u32 *)(p + 0x14C) = 0x20202020;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0;
    p[0x1B5] = 0x45;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]]++;
    *(u32 *)(p + 0x5C) = 0x43055555;
    *(u32 *)(p + 0x68) = 0x42A00000;
    if (*(s16 *)(p + 0x140) == 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    *d = *(u16 *)(q + 0x168);
    p[0x169] = 0x16;
    p[0x168] = 0x1F;
    func_00175910(p, p[0x169], p[0x168], *(s8 *)(r + 0x151));
    *(s8 *)(p + 0x31) = -4;
    func_0034A080(p, q);
}

void func_00324FF0(u8 *p) {
    extern void func_00185490();
    extern void func_00183D10();
    extern void func_0018C4B0();
    extern void func_001757E0();
    extern void func_003CD090();
    extern s8 func_00175700();
    extern void func_003266E0();
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        func_00185490(p);
        func_00183D10(p);
        func_0018C4B0(p, 5);
        p[0x20D] = 0;
        p[0x1B5] = 0x7B;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->h7c[p[2]]++;
        func_001757E0(p, 0x15, 7);
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        func_003CD090(p, 3);
    }
    if (func_00175700(p) < 0) {
        f32 k = -26.66666603088379f;
        if (*(s16 *)(p + 0x140) != 0) k = -k;
        *(f32 *)(p + 0x34) += k;
        func_003266E0(p);
    }
}

void func_00382AC0(u8 *p) {
    extern void func_00175910();
    extern void func_001E7F60();
    if (*(*(u8 **)(p + 0x14) + 4) >= 2) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    {
        *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 8) + 0x34);
    }
    if (*(*(u8 **)(p + 8) + 0x20) == 4) {
        *(f32 *)(p + 0x38) += 306.4285583496094f * *(f32 *)(p + 0x54);
    } else {
        *(f32 *)(p + 0x38) += 66.4285659790039f * *(f32 *)(p + 0x54);
    }
    {
        if (p[0x21] != *(s8 *)(*(u8 **)(p + 0x14) + 0x161)) {
            p[0x21] = *(s8 *)(*(u8 **)(p + 0x14) + 0x161);
            func_00175910(p, 0x17, 0xA, p[0x21] - 1);
        }
    }
    if (p[0x21] == 0) func_001E7F60(p);
}


void func_002DD710(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s16 *)(p + 0x1C) == 0x16) {
        *(u32 *)(p + 0x5C) = 0xC1200000;
        *(u32 *)(p + 0x68) = 0x3ED55555;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_001757E0(p, 2, 2);
    }
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            u32 t = p[6]; p[6] = t + 1;
        }
    }
}

#define ADDS \
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C); \
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68); \
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60); \
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);

void func_002322C0(u8 *p, s32 a1) {
    extern s8 func_00175700();
    extern void func_001757E0();
    extern void func_00230020();
    if (func_00175700(p) >= 0) {
        ADDS
    } else {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        { u32 t = p[7]; p[7] = t + 1; }
        p[0x169] = 0x16;
        p[0x168] = 0xB;
        func_001757E0(p, p[0x169], p[0x168]);
        ADDS
        func_00230020(p, a1);
    }
}

typedef struct { u8 pad0[0x10]; void (*cb)(u8 *); u8 pad14[4]; u8 *owner; u8 pad1c[4]; u8 b20; u8 b21; u8 pad22[4]; s16 h26; } ENT;
void func_00351AE0(u8 *p, u8 q) {
    extern ENT *func_003DA750(s32, s32, s32);
    extern void func_00351BF0(u8 *);
    ENT *o;
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        o->cb = func_00351BF0;
        o->owner = p;
        o->b20 = q;
        o->b21 = 0;
        o->h26 = 0x505;
        *(f32 *)((u8 *)o + 0x34) = *(f32 *)(p + 0x34);
        *(f32 *)((u8 *)o + 0x38) = *(f32 *)(p + 0x38);
    }
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        o->cb = func_00351BF0;
        o->owner = p;
        o->b20 = q;
        o->b21 = 1;
        o->h26 = 0x505;
        *(f32 *)((u8 *)o + 0x34) = *(f32 *)(p + 0x34);
        *(f32 *)((u8 *)o + 0x38) = *(f32 *)(p + 0x38);
    }
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        o->cb = func_00351BF0;
        o->owner = p;
        o->b20 = q;
        o->b21 = 3;
        o->h26 = 0x505;
        *(f32 *)((u8 *)o + 0x34) = *(f32 *)(p + 0x34);
        *(f32 *)((u8 *)o + 0x38) = *(f32 *)(p + 0x38);
    }
}

typedef struct { u8 pad[0x160]; s8 b[8]; } S160;

void func_00319650(u8 *p) {
    extern u8 *func_00319410();
    extern s8 func_00175700();
    extern void func_001757E0();
    extern void func_001843A0();
    u8 *o;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((o = func_00319410((*(u8 **)(p + 0x220))[2], 0)) != 0) goto have;
    if ((o = func_00319410((*(u8 **)(p + 0x220))[2], 1)) != 0) goto have;
    if ((o = func_00319410((*(u8 **)(p + 0x220))[2], 2)) == 0) goto none;
have:
    if (o[0x425] != 0) goto none;
    {
        s8 v;
        func_00175700(p);
        v = *(s8 *)(p + 0x2B8) - 1;
        *(s8 *)(p + 0x2B8) = v;
        if (v < 0) {
            u32 t = p[6]; p[6] = t + 1;
            p[0x1B5] = 0x40;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->h7c[p[2]]++;
            func_001757E0(p, 0x16, 0x19);
        }
    }
    return;
none:
    {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_001843A0(p);
    }
}

void func_002C6950(S160 *a) {
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_001E3210();
    u8 *p = (u8 *)a;
    u8 *q = p + 0x2B8;
    switch (p[0x1FC]) {
    case 0:
    case 1:
        if (func_00175700(p) < 0) func_001843A0(p);
        break;
    case 2:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        } else {
            if (q[2] == 0 && *(s8 *)(p + 0x1B2) != 0) {
                q[2] = 1;
                func_001E3210(p, 3);
            }
            {
                s8 *r = a->b;
                s8 f = r[1];
                s8 *w = r + 1;
                if (f != 0) {
                    *w = 0;
                    p[0x1B5] = 0x19;
                    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                    *(u32 *)(p + 0x1D8) = 0;
                    D_004C2794->h7c[p[2]]++;
                }
            }
        }
        break;
    }
}


void func_002D87D0(u8 *p) {
    extern void func_00175C00();
    extern void func_00185490();
    extern void func_00183D10();
    extern void func_001757E0();
    extern void func_001D0500();
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_00183920();
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00175C00(p, 0);
        func_00185490(p);
        func_00183D10(p);
        p[0x1B5] = 0x40;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->h7c[p[2]]++;
        func_001757E0(p, 0x15, 0x20);
        func_001D0500(p, 1);
        return;
    }
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    {
        u32 u = p[6];
        if (u == 1 && *(s8 *)(p + 0x151) != 0) {
            u32 v[3];
            p[6] = u + 1;
            *(s8 *)(p + 0x151) = 0;
            v[0] = 0x42B40000;
            v[1] = 0x43340000;
            func_00183920(p, v);
        }
    }
}

typedef struct { u8 pad[0x1C]; s32 w1c; } G1C;
extern G1C *D_004C2840;
extern s32 D_004BFAF8;
extern s32 D_004BFAFC;
extern s32 D_004BFB00;

void func_001E97C0(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0();
    p[0x169] = 7;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        func_001E3710(p, 0x14);
        *(s32 **)(p + 0x408) = &D_004BFAF8;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        func_001E3710(p, 0x15);
        *(s32 **)(p + 0x408) = &D_004BFAFC;
        p[0x1BB] = 1;
        break;
    case 2:
        if (*(u16 *)(p + 0x20E) & 0x800) {
            p[0x169] = 0x14;
            p[0x168] = 0;
            p[0x1B5] = 0x12;
            p[6] = 1;
        } else {
            p[0x168] = 2;
            p[0x1B5] = 2;
            func_001E3710(p, 0x16);
            p[6] = 0;
        }
        *(s32 **)(p + 0x408) = &D_004BFB00;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]]++;
    func_001757E0(p, p[0x169], p[0x168]);
}

extern void func_001E3710(u8 *, s32);
extern int func_001757E0(u8 *, s32, s32);

void func_001E98F0(u8 *p) {
    p[0x169] = 7;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 6;
        func_001E3710(p, 0x14);
        *(s32 **)(p + 0x408) = &D_004BFAF8;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 7;
        func_001E3710(p, 0x15);
        *(s32 **)(p + 0x408) = &D_004BFAFC;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 8;
        func_001E3710(p, 0x16);
        *(s32 **)(p + 0x408) = &D_004BFB00;
        p[0x1BB] = 2;
        break;
    }
    /* Retail explicitly reloads and writes this byte; original intent is unknown. */
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]]++;
    func_001757E0(p, 9, p[0x168]);
}



void func_00182970(u8 *p, u8 *q, u8 *r) {
    extern void func_001843A0(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00186CE0(u8 *, s32);
    f32 k = 160.0f + (320.0f + *(f32 *)(r + 0xC) - 35.0f);
    if (p[1] == 0x29) k += 53.33333206176758f;
    if (!(*(f32 *)(p + 0x34) < k)) {
        if (q[5] != 0 || p[0x1E4] != 10) {
            *(f32 *)(p + 0x34) = k;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x215] = 0;
            func_001843A0(p);
            func_00175C00(p, 1);
            if (q[5] == 0) {
                func_00186CE0(p, 10);
                return;
            }
        }
    } else {
        if (q[5] == 0 && p[0x1E4] != 10) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x215] = 0;
            func_001843A0(p);
            func_00175C00(p, 1);
            func_00186CE0(p, 10);
        }
    }
}

typedef struct { u8 prefix[0x1B5]; u8 action; } ActorActionView;
typedef char ActorActionOffsetCheck[
    ((u32)&((ActorActionView *)0)->action == 0x1B5) ? 1 : -1];
extern s32 D_004C0A78, D_004C0A7C, D_004C0A80;
void func_00295A60(u8 *p) {
    extern void func_001E3710(u8 *, int);
    extern int func_001757E0(u8 *, int, int);
    u32 t;
    p[0x169] = 7;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        func_001E3710(p, 0x14);
        *(void **)(p + 0x408) = &D_004C0A78;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        func_001E3710(p, 0x15);
        *(void **)(p + 0x408) = &D_004C0A7C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        func_001E3710(p, 0x16);
        p[6] = 0;
        if (*(u16 *)(p + 0x20E) & 0x800) {
            p[6] = 1;
            p[0x169] = 0x14;
            p[0x168] = 0;
            p[0x1B5] = 0x12;
        }
        *(void **)(p + 0x408) = &D_004C0A80;
        p[0x1BB] = 2;
        break;
    }
    t = p[0x1B5];
    ((ActorActionView *)p)->action = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]]++;
    func_001757E0(p, p[0x169], p[0x168]);
}

extern s32 D_004C0EC4, D_004C0EC8, D_004C0ECC;
void func_002CC700(u8 *p) {
    extern void func_001E3710(u8 *, int);
    extern int func_001757E0(u8 *, int, int);
    u32 t;
    p[0x169] = 8;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 3;
        func_001E3710(p, 0x14);
        *(void **)(p + 0x408) = &D_004C0EC4;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 4;
        func_001E3710(p, 0x15);
        *(void **)(p + 0x408) = &D_004C0EC8;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 5;
        p[6] = 0;
        if (*(u16 *)(p + 0x20E) & 0x800) {
            p[6] = 1;
            p[0x169] = 0x14;
            p[0x168] = 0;
            p[0x1B5] = 0x12;
        }
        func_001E3710(p, 0x16);
        *(void **)(p + 0x408) = &D_004C0ECC;
        p[0x1BB] = 2;
        break;
    }
    t = p[0x1B5];
    ((ActorActionView *)p)->action = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]]++;
    func_001757E0(p, p[0x169], p[0x168]);
}

extern s32 D_004C0A84, D_004C0A88, D_004C0A8C;
void func_00295C90(u8 *p) {
    extern void func_001E3710(u8 *, int);
    extern int func_001757E0(u8 *, int, int);
    u32 t;
    p[0x169] = 8;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 3;
        func_001E3710(p, 0x14);
        *(void **)(p + 0x408) = &D_004C0A84;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 4;
        func_001E3710(p, 0x15);
        *(void **)(p + 0x408) = &D_004C0A88;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 5;
        func_001E3710(p, 0x16);
        p[6] = 0;
        if (*(u16 *)(p + 0x20E) & 0x800) {
            p[6] = 1;
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            p[0x169] = 0x14;
            p[0x168] = 1;
            p[0x1B5] = 0x14;
        }
        *(void **)(p + 0x408) = &D_004C0A8C;
        p[0x1BB] = 2;
        break;
    }
    t = p[0x1B5];
    ((ActorActionView *)p)->action = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]]++;
    func_001757E0(p, p[0x169], p[0x168]);
}
