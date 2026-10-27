typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175670();
void func_001B28C0(u8 *p) {
    u8 t;
    func_00175670(p);
    t = (*(u8 **)(p + 0x18))[6];
    if (t >= 5) {
        if (t != 10) {
            u32 u = p[4];
            p[4] = u + 1;
            return;
        }
    }
}



extern u8 D_0045A640[];
extern s32 func_00189310();
extern void func_0018A990();
extern void func_0018C4B0();
extern void func_00186A60();
s32 func_002D61C0(u8 *p) {
    if (!func_00189310(p, D_0045A640, p + 0x380)) return 0;
    func_0018A990(p, p + 0x380);
    func_0018C4B0(p, 5);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

extern void func_00186A20();
extern s8 func_00175700();
void func_00259730(u8 *p) {
    if (*(s8 *)(p + 0x151)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 1;
        func_00186A20(p);
        *(f32 *)(p + 0x5C) = 0;
        *(f32 *)(p + 0x68) = 0;
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    }
    func_00175700(p);
}

extern void *func_003DA750(s32, s32, s32);
extern void func_003AD6E0();
void func_003AD480(u8 *a, s32 b, s32 c) {
    u8 *o = func_003DA750(0, 1, 0);
    if (o) {
        *(void **)(o + 0x10) = func_003AD6E0;
        *(u8 **)(o + 0x18) = a;
        *(u16 *)(o + 0x1C) = *(u16 *)(a + 0x168);
        o[0x20] = b;
        o[0x21] = c;
        *(s16 *)(o + 0x26) = 0x3002;
    }
}


extern void func_00184540();
extern void func_00385A20();
extern void func_001C09A0();
extern void func_003C9FB0();
void func_003C9F30(u8 *a, s32 b, s32 c) {
    u8 *o = func_003DA750(0, 1, 0);
    if (o) {
        *(void **)(o + 0x10) = func_003C9FB0;
        *(u8 **)(o + 0x18) = a;
        o[1] = a[1];
        *(s16 *)(o + 0x1C) = c;
        o[0x20] = b;
        *(s16 *)(o + 0x26) = 0x3A00;
        *(u32 *)(o + 0xD0) = *(u16 *)(a + 0x168);
    }
}

extern void (*D_0044DEA0[])();
void func_001CF490(u8 *a) {
    u8 *b = *(u8 **)(a + 0x18);
    if (b[4] != 1 || b[5] != 0 || b[0x1E4] != 0x1D || b[0x1FD] != 2) {
        u32 t = a[4];
        a[4] = t + 1;
    } else {
        D_0044DEA0[a[5]](a);
    }
}

extern void func_001C88C0();
void func_001C8830(u8 *p) {
    u8 *o = func_003DA750(0, 3, 0);
    if (o) {
        *(void **)(o + 0x10) = func_001C88C0;
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0x26) = 0x1E01;
        o[0x21] = 0;
    }
    o = func_003DA750(0, 3, 0);
    if (o) {
        *(void **)(o + 0x10) = func_001C88C0;
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0x26) = 0x1E01;
        o[0x21] = 1;
    }
}

static void func_002B5100(u8 *a) {
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    if (*(f32 *)(a + 0x60) * *(f32 *)(a + 0x6C) > 0.0f) *(u32 *)(a + 0x6C) = 0xBFCDB6DB;
}
extern void func_00183d50();
void func_002B6330(u8 *a) {
    a[0x40C] = 2;
    a[0x33C] = 5;
    func_002B5100(a);
    if (*(f32 *)(a + 0x430) > *(f32 *)(a + 0x38)) {
        u32 t = a[6];
        a[6] = t + 1;
        a[0x40D] = 0;
        a[0x40C] = 0;
        a[0x33B] = 0;
        a[0x33C] = 0;
        *(f32 *)(a + 0x38) = *(f32 *)(a + 0x430);
        a[0x20D] = 0;
        func_00183d50(a);
    } else {
        if (!*(s8 *)(a + 0x151)) func_00175700(a);
    }
}

extern void func_001757E0();
void func_002A57C0(u8 *a) {
    s16 v;
    a[0x40C] = 2;
    a[0x33C] = 5;
    func_00175700(a);
    *(s16 *)(a + 0x1E) -= 1;
    v = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = v;
    if (v == 0) {
        u32 t = a[6];
        a[6] = t + 1;
        a[0x40D] = 0;
        a[0x40C] = 0;
        a[0x33B] = 0;
        a[0x33C] = 0;
        func_001757E0(a, 0x16, 0xB);
    }
}

extern void func_001757E0();
void func_003139B0(u8 *a, u8 *b) {
    s8 r;
    a[0x40C] = 2;
    a[0x33C] = 5;
    r = func_00175700(a);
    if (r < 0) {
        u32 t = a[7];
        a[7] = t + 1;
        func_001757E0(a, 0x16, 0x1D);
        *(f32 *)(a + 0x34) = *(s16 *)(b + 0x10);
        *(f32 *)(a + 0x38) = *(f32 *)(a + 0x430);
        a[0x40D] = 0;
        a[0x40C] = 0;
        a[0x33B] = 0;
        a[0x33C] = 0;
    }
}

extern void (*D_00463DD8[])();
void func_0036FCF0(u8 *a) {
    u8 *o = *(u8 **)(a + 0x18);
    u32 t;
    D_00463DD8[a[5]](a);
    if ((*(u8 **)(a + 0x18))[6] == 0xC) {
        t = a[4];
        a[4] = t + 1;
        a[0x13C] = 0;
    } else if (o[0x1E4] != 0x1D || o[0x1FD] != 9) {
        t = a[4];
        a[4] = t + 1;
        a[0x13C] = 0;
    }
}


extern s32 func_0018AB10();
void func_0027C8E0(u8 *a, u8 *b) {
    s16 v;
    func_00175700(a);
    if (*(s8 *)(b + 2) >= 0 && func_0018AB10(a)) {
        *(s8 *)(b + 2) -= 1;
        *(s16 *)(a + 0x1C) += 1;
    }
    v = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = v;
    if (v <= 0) {
        u32 t = a[6];
        a[6] = t + 1;
        func_001757E0(a, 0x15, (u8)(a[0x1B7] + 8));
    }
}

void func_0027F760(u8 *a) {
    func_00175700(a);
    if (a[7] == 0) {
        if (*(s8 *)(a + 0x151)) {
            u32 t;
            *(s8 *)(a + 0x151) = 0;
            t = a[7];
            a[7] = t + 1;
        }
    } else {
        if (*(s8 *)(a + 0x151) == 0) {
            *(f32 *)(a + 0x118) = (f32)*(s8 *)(a + 0x152) / (f32)*(s8 *)(*(u8 **)(a + 0x164) + 2);
        } else {
            u32 t = a[6];
            a[6] = t + 1;
            a[7] = 0;
        }
    }
}

extern u8 D_004D18A0;
extern void func_001E3CE0(int);
s32 func_00134370(u8 *a, u8 *owner_unused) {
    if (D_004D18A0 != 4) return 1;
    if (!a[0x14F]) return 1;
    a[0x14F] = 0;
    a[0x14C] = 2;
    a[5] = 0;
    *(s16 *)(a + 0x1C) = 0;
    a[0x20] = 3;
    func_001E3CE0(0xE);
    return 0;
}
