typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;

extern s32 func_00175670(u8 *);
extern void func_0019D520();
void func_0019D4A0(u8 *a, u8 *b) {
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    if (*(s32 *)(a + 0xD0) == *(u16 *)(b + 0x168)) {
        if ((s8)func_00175670(a) >= 0) return;
    }
    func_0019D520(a, b);
}

extern void func_001C1B40(u8 *, u8 *);
extern void (*D_0044CA60[])(u8 *, u8 *);
void func_001C18A0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (*(s16 *)(q + 0x434) == 0) {
        func_001C1B40(p, q);
        p[4] = 2;
        p[0x13C] = 0;
    } else {
        D_0044CA60[p[5]](p, q);
    }
}

extern s32 func_00174170();
extern f32 D_00474780[];
extern f32 D_00474784[];
void func_003BCE40(u8 *p) {
    *(f32 *)(p + 0x34) += D_00474780[(func_00174170() & 7) * 2];
    *(f32 *)(p + 0x38) += D_00474784[(func_00174170() & 7) * 2];
}

extern s32 func_00175700();
extern void func_001757E0();
void func_002ECCA0(u8 *p) {
    s16 v;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x16, 4);
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    }
}

extern s16 D_004C27A4;
extern void *func_003DA750();
extern void func_003547E0();
s32 func_00354760(u8 *p) {
    s32 i;
    u8 *o;
    if (D_004C27A4 < 3) return 0;
    i = 0;
    do {
        o = func_003DA750(0, 1, 1);
        *(s16 *)(o + 0x26) = 0x701;
        o[0x20] = i;
        *(void **)(o + 0x10) = func_003547E0;
        *(u8 **)(o + 0x18) = p;
        i++;
    } while (i < 2);
    return 1;
}


typedef struct { f32 x, y, z; } V3;
extern V3 D_0045FA28;
extern u32 D_004C283C;
extern void func_00340E50();
extern void func_0033FF70();

extern void func_003DF850(s32, s32);

extern s32 func_001E5F30();
extern s32 D_004C2B50;
extern s32 func_00401920(s32);
extern void func_00401868(s32);

extern u8 D_004D18D8[];
extern void func_00131AB0(u8 *, u8 *, s32);
extern void func_001E3710();
void func_00269390(u8 *a, u8 *b) {
    a[6] = 6;
    a[7] = 0;
    *(s16 *)(b + 0xA) = 0x78;
    if ((D_004D18D8[0] & (1 << a[2])) == 0 && *(s8 *)(a + 0x539) != 0) {
        *(s16 *)(b + 0xA) = 0x96;
        func_00131AB0(a, b + 0xA, 6);
    }
    func_001757E0(a, 0x16, 0x21);
    func_001E3710(a, 0x4C);
}

extern u8 *D_0044B898[];
extern s32 D_0044B8A8[];
extern u8 *D_004C2838;
extern void func_003DAA40();
void func_001ACB50(u8 *p) {
    s16 i;
    *(s16 *)(p + 0xCC) = *(s16 *)(D_0044B898[0] + *(s16 *)(p + 0x1C) * 4);
    *(u8 **)(p + 0x84) = D_004C2838;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x3C) += *(f32 *)(p + 0x64);
    i = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = i;
    if (i >= D_0044B8A8[0]) func_003DAA40(p);
}

extern u16 *D_004C26E4;
extern s32 func_001B8D90();
void func_001B8C90(u8 *p) {
    if (*D_004C26E4 != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        func_001B8D90(p);
        return;
    }
    if ((s8)func_00175670(p) < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        *(s16 *)(p + 0x1C) = 0x1E;
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    }
}

extern u8 *D_004C2794;
void func_002C8DD0(u8 *p) {
    s16 v;
    u32 t;
    s16 *q;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v != 0) {
        func_00175700(p);
        return;
    }
    t = p[6];
    p[6] = t + 1;
    p[0x1B5] = 0x3A;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    q = (s16 *)((p[2] << 1) + (u32)D_004C2794);
    q[0x3E] = q[0x3E] + 1;
    func_001757E0(p, 0x15, 0xB);
}

extern void func_001DD450();
void func_001DD3A0(u8 *a, u8 *b) {
    s16 v;
    func_00175700(a);
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    v = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = v;
    if (v == 0) func_001DD450(a, b);
}

extern s16 D_004D1802[];
extern void func_0016B0C0();

void func_002766B0(u8 *p) {
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) < 0) {
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0xE));
    }
}


extern void func_00352710();
extern void func_003DD260();

u8 *func_00352670(u8 *p, u8 a, u8 b, u8 c) {
    u8 *o;
    if ((o = func_003DA750(0, 1, 1)) != 0) {
        *(void **)(o + 0x10) = func_00352710;
        *(u8 **)(o + 0x18) = p;
        o[0x21] = 0;
        o[0x20] = 0;
        *(s16 *)(o + 0x26) = 0x601;
        func_003DD260(o + 0x88);
        o[0x93] = a;
        o[0x90] = b;
        o[0xB1] = c;
    }
    return o;
}

void func_00341000(void) {
    u8 *o;
    if ((o = func_003DA750(0, 6, 0)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00340E50;
        *(s16 *)(o + 0xCC) = 4;
        *(u32 *)(o + 0x84) = D_004C283C;
        *(V3 *)(o + 0x34) = D_0045FA28;
        *(u32 *)(o + 0x44) = 0xCAAC;
        *(s32 *)(o + 0xD0) = 0x805;
        func_0033FF70(o);
    }
}

extern void func_001E3210();
void func_002707E0(u8 *p) {
    u32 t;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        t = p[5];
        p[5] = t + 1;
        func_001E3210(p, 0xA);
    }
}

extern void func_001843A0();
extern void func_00183920();
void func_002DFFA0(u8 *p) {
    u32 v[4];
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) & 1) {
        *(s8 *)(p + 0x151) = *(s8 *)(p + 0x151) ^ 1;
        v[0] = 0x41D55555;
        v[1] = 0x433C9249;
        func_00183920(p, v);
    }
    if (*(s8 *)(p + 0x151) & 2) {
        *(s8 *)(p + 0x151) = *(s8 *)(p + 0x151) ^ 2;
        func_001E3710(p, 0x16);
    }
}

extern void (*D_00463DC8[])(u8 *);
void func_0036FA80(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    u32 t;
    D_00463DC8[p[5]](p);
    if ((*(u8 **)(p + 0x18))[6] == 0xC) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else if (q[0x1E4] != 0x1D || q[0x1FD] != 9) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}

extern u8 D_00445840[];
extern s32 func_001688C0();
s32 func_00166C80(u8 *a, u8 *b, s32 c) {
    s32 t;
    u32 h;
    if (c) {
        a[0x451] = 1;
        a[0x472] = 0;
        return 1;
    }
    a[0x451] = 1;
    t = a[0x472];
    if (t == 0) {
        a[0x472] = 0;
        return func_001688C0(a);
    }
    a[0x472] = t - 1;
    if (*(s8 *)(a + 0x1B4) != 0) {
        t = a[0x472];
        a[0x472] = t + 1;
    }
    t = b[7];
    b[7] = t - 1;
    h = *(u16 *)(b + 4);
    *(u16 *)(b + 4) = h - D_00445840[a[0x454]];
    return 0;
}
