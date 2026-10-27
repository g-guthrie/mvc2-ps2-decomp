typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_001757E0(u8 *, s32, s32);
extern u8 *D_004C2840;
extern void func_00176160(u8 *, s32, s32, s32);
void func_001CF720(u8 *p) {
    u8 *o = *(u8 **)(p + 0x18);
    if (*(u32 *)(D_004C2840 + 0x1C) & 1) {
        func_00176160(o, 1, o[0x25] * 2, 1);
    } else {
        func_00176160(o, 1, o[0x25] * 2 + 1, 1);
    }
}
extern void func_0015D010(u8 *, void *);
void func_002E06F0(u8 *p) {
    u32 v[4];
    v[0] = 0xC2A00000;
    v[1] = 0x43892492;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    p[6] = 0;
    p[7] = 0;
    func_001757E0(p, 0xF, 2);
}
extern u8 *D_004C2794;
void func_002189D0(u8 *p) {
    u32 t = p[0x15B];
    if (t != 0) {
        s32 a = (s8)t;
        s32 x = (s8)p[0x1B7] * 2 + 0x4B;
        s16 *e;
        p[0x1B5] = x + a;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        e = (s16 *)D_004C2794;
        e[0x3E + p[2]] += 1;
        p[0x15B] = 0;
    }
}
extern void *D_0045E8A8[];
void func_003327F0(u8 *p) {
    ((void (*)(u8 *))D_0045E8A8[p[5]])(p);
    *(f32 *)(p + 0x58) = *(f32 *)(*(u8 **)(p + 0x14) + 0x58);
    *(u32 *)(*(u8 **)(p + 0x14) + 0xD8) = *(u32 *)(p + 0xD8);
    *(u32 *)(*(u8 **)(p + 0x14) + 0xDC) = *(u32 *)(p + 0xDC);
}
void func_0019E510(u8 *p,u8 *work_unused) {
    u8 *o = *(u8 **)(p + 0x18);
    p[5] = 0;
    p[0x13C] = 0;
    *(u32 *)(p + 0x5C) = 0x430A5555;
    *(u32 *)(p + 0x60) = 0x43160000;
    if (*(s16 *)(o + 0x140) == 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34) + *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38) + *(f32 *)(p + 0x60);
    func_001757E0(p, 0x17, 0x27);
}
extern s32 func_00175700(u8 *);
extern void func_001E7F60(u8 *);
void func_0034C5A0(u8 *p) {
    u8 *o = *(u8 **)(p + 0x18);
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[6];
        p[6] = t + 1;
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34) + *(f32 *)(p + 0x64);
        func_00175700(p);
        func_001E7F60(p);
    }
}
extern u8 *func_003DA750(u8 *, s32, s32);
extern void func_003B6AA0();
void func_003B6A30(u8 *a, u8 b) {
    u8 *o = func_003DA750(a, 1, 2);
    if (o != 0) {
        *(void **)(o + 0x10) = func_003B6AA0;
        *(u32 *)(o + 0x18) = *(u32 *)(a + 0x18);
        *(u8 **)(o + 0x14) = a;
        o[0x20] = a[0x20];
        o[0x21] = b;
        *(s16 *)(o + 0x26) = 0x3403;
    }
}
extern void func_001DEE30(u8 *, s32);
extern void func_001DEEF0(u8 *p, s32 b);
extern void func_001DEF30(u8 *, s32);
/* func_001DF110: not yet matched without a stand-in callee. */
extern void func_00224BB0(u8 *p);
/* func_00224E30: not yet matched without a stand-in callee. */
extern s16 D_004C2008[4];
extern void func_001E3210(u8 *, s32);
void func_003B60A0(u8 *p) {
    u32 t = p[5];
    p[5] = t + 1;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(s16 *)(p + 0x1C) = D_004C2008[p[0x21]];
    p[0xAA] = 3;
    func_001E3210(p, 0x23);
    func_001757E0(p, 0x15, 0x18);
}
extern void func_0016B0C0(u8 *, u8 *, s32);
s32 func_00166F40(u8 *p, u8 *q) {
    u8 *b;
    u32 off;
    func_0016B0C0(p, q, 0);
    b = *(u8 **)q;
    off = *(u16 *)(q + 4);
    b += off;
    *(u16 *)(q + 4) = off + 8;
    p[0x492] = b[*(u8 *)(*(u8 **)(p + 0x220) + 0x21B) & 7];
    p[0x494] = 1;
    p[0x451] = 0;
    p[0x452] = 0;
    p[0x453] = 0;
    return 1;
}
extern void (*D_004C1DB0[2])(u8 *, u8 *);
extern void func_00389920(u8 *, u8 *);
void func_00389510(u8 *p) {
    u8 *o = *(u8 **)(p + 0x18);
    if (o[0x1E4] != 0x1D) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        p[0x24] = *(s8 *)(o + 0x24);
        func_00389920(p, o);
        D_004C1DB0[p[5]](p, o);
    }
}
extern s32 func_001745B0(u8 *);
extern void func_0036A8A0(u8 *);
extern void func_0038F520();
void func_0038F4A0(u8 *a, u8 b, u8 c) {
    u8 *o = func_003DA750(0, 1, 0);
    if (o != 0) {
        *(void **)(o + 0x10) = func_0038F520;
        *(u8 **)(o + 0x18) = a;
        o[0x20] = b;
        o[0x22] = c;
        *(s16 *)(o + 0x26) = 0x1F00;
        *(u32 *)(o + 0xD0) = *(u16 *)(a + 0x168);
        o[1] = a[1];
    }
}
extern void func_00377E10(u8 *);
extern void func_00184540(u8 *);
extern void func_001843A0(u8 *);
extern void func_00270B60(u8 *p);
/* func_00270D30: not yet matched without a stand-in callee. */
extern u16 *D_004C26FC;
extern void func_001BB970();
u8 *func_001BB8E0(u8 *a, u8 b) {
    u8 *o = func_003DA750(0, 3, 0);
    if (o != 0) {
        *(void **)(o + 0x10) = func_001BB970;
        *(u8 **)(o + 0x18) = a;
        *(s16 *)(o + 0x140) = *(s16 *)(*(u8 **)(o + 0x18) + 0x140);
        *(s16 *)(o + 0x26) = 0x1700;
        D_004C26FC = (u16 *)(o + 0xD0);
        *D_004C26FC = *(u16 *)(*(u8 **)(o + 0x18) + 0x168);
        o[0x23] = b;
        return o;
    }
    return 0;
}
extern s32 func_00197810(u8 *, u8 *);
extern void (*D_004BF588[2])(u8 *, u8 *);
void func_00196980(u8 *a, u8 *b) {
    u8 *s0 = a + 0x88;
    u8 *s1 = b + 0x2B8;
    if (func_00197810(a, b) != 0) {
        if (b[0x1E4] != 0x16) s1[0xC] = 0;
        s0[0] = 0;
    }
    D_004BF588[a[5]](a, b);
}
extern void func_00175670(u8 *);
extern void func_001AFC90(u8 *, u8 *);
void func_001ADC90(u8 *p) {
    u8 *o = *(u8 **)(p + 0x18);
    if (o[5] != 0 || o[0x1E4] != 0x15 || o[0x1FD] != 4 || *(s8 *)(o + 0x151) == 0) {
        func_001AFC90(p, o);
    } else {
        func_00175670(p);
        *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    }
}
extern void func_001820A0(u8 *);
extern void func_00182300(u8 *);
extern void func_00226DA0(u8 *);
extern s32 func_001864A0(u8 *);
extern void func_001865B0(u8 *);
void func_00226D10(u8 *p) {
    func_001820A0(p);
    func_00182300(p);
    if (*(s32 *)(p + 0x334) == 0) {
        if ((s8)func_00175700(p) < 0) {
            func_00184540(p);
        } else if (func_001864A0(p) != 0) {
            func_001865B0(p);
        }
    } else {
        func_00226DA0(p);
    }
}
extern void func_003A6D90(u8 *, u8 *);
void func_003A6D00(u8 *a, u8 *b) {
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    if ((s8)func_00175700(a) < 0) {
        u32 t = a[4];
        a[4] = t + 1;
        func_003A6D90(a, b);
    }
}
void func_00302B10(u8 *p) {
    u32 t = p[6];
    s16 *e;
    p[6] = t + 1;
    p[0x20D] = 2;
    *(u32 *)(p + 0x5C) = 0xC1F00000;
    if (p[0x1E6] != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0xBE892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    p[0x1B5] = 0x3F;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    e = (s16 *)D_004C2794;
    e[0x3E + p[2]] += 1;
    func_001757E0(p, 0x14, 1);
}
extern s32 func_0034D520(u8 *);
void func_0020B610(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) < 0) {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001843A0(p);
    } else if (*(s8 *)(p + 0x151) != 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[0x151] = 0;
        func_0034D520(p);
    }
}
extern void func_00178F20(u8 *);
extern void func_0018FDB0(u8 *);
extern void func_001E3710(u8 *, s32);
extern void func_001548D0(u8 *, void *, s32);
void func_0021C410(u8 *a, u8 *b) {
    u32 v[4];
    a[0x151] = 0;
    a[0x2C4] = 1;
    func_00178F20(a);
    *(u8 **)(b + 0x1C8) = a;
    b[0x1B5] = 0x24;
    func_0018FDB0(a);
    func_001E3210(a, 3);
    func_001E3710(a, 2);
    v[0] = 0xC2A00000;
    v[1] = 0x41892492;
    func_001548D0(a, v, 2);
}
void func_001CADD0(u8 *p, u8 x) {
    u8 *o = *(u8 **)(p + 0x18);
    s32 y = (s8)x;
    u32 n = p[0xD6] + 1;
    p[0xD6] = n;
    p[0xD6] = (s8)(n & 0xFF) & 3;
    p[0xD7] = y * 8 + *(s8 *)(p + 0xD6) * 2;
    *(f32 *)(p + 0x5C) = ((f32 *)*(u8 **)(p + 0xD0))[p[0xD7]];
    {
        u32 i = p[0xD7] << 2;
        *(f32 *)(p + 0x60) = *(f32 *)(i + *(u32 *)(p + 0xD0) + 4);
    }
    if (*(s16 *)(o + 0x140) != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
}
void func_0036A530(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001745B0(p) == 0) {
        func_0036A8A0(p); return;
    }
}
