typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_002555E0(u8 *p);

/* func_0025AC10: not yet matched without a stand-in callee. */

void func_00225DE0(u8 *p) {
    extern void func_00186A60();
    s32 v;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    v = *(s8 *)(p + 0x4DD);
    switch (v) {
    case 0: p[0x1FD] = 1; p[0x1B7] = 0; break;
    case 1: p[0x1FD] = 0; p[0x1B7] = 0; break;
    case 2: p[0x1FD] = 1; p[0x1B7] = 0; break;
    }
    func_00186A60(p, 0x15);
}

void func_002576C0(u8 *p) {
    extern void func_00183d50();
    extern s32 func_00175700();
    extern void func_001843A0();
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        func_00183d50();
        p[0x20D] = 0;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    }
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}

void func_002A5690(u8 *p) {
    extern void func_00175700();
    extern void func_001266A0();
    extern void func_001830D0();
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001266A0(p, 1, 0xD);
        v[0] = 0xC2855555;
        v[1] = 0x41BC9249;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}

void func_002A3BF0(u8 *p) {
    extern void func_00175700();
    extern void func_00183d50();
    extern void func_001757E0();
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183d50(p);
        func_001757E0(p, 0x15, (u8)(p[0x1B7] ? 0xF : 0xE));
    }
}

typedef struct { f32 x, y, z; } V3;
typedef struct { f32 a, b, c, d; } V4;

void func_003674C0(u8 *p) {
    extern void func_00367F60();
    extern void func_001E7F60();
    u8 *q = *(u8 **)(p + 0x14);
    if (q[4] > 1) {
        func_00367F60(p);
        return;
    }
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    q = *(u8 **)(p + 0x14);
    *(V4 *)(p + 0x150) = *(V4 *)(q + 0x150);
    *(f32 *)(p + 0x160) = *(f32 *)(q + 0x160);
    q = *(u8 **)(p + 0x14);
    *(s32 *)(p + 0x1D4) = *(s32 *)(q + 0x1D4);
    q = *(u8 **)(p + 0x14);
    if (q[4] == 1 && q[5] == 0) func_001E7F60(p);
}

void func_00318000(u8 *p) {
    extern s32 func_00175700();
    extern void func_001843A0();
    f32 z = 0.0f;
    f32 *v1, *a0;
    if ((s8)func_00175700(p) >= 0) {
        v1 = (f32 *)(p + 0x5C);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        a0 = (f32 *)(p + 0x68);
        if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < z)) {
            *v1 = z;
            *a0 = z;
        }
    } else {
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_001843A0(p);
    }
}

void func_0036F4A0(u8 *p, u8 *q, s32 *r) {
    extern void func_001E3210();
    u8 *c = *(u8 **)(p + 0x1C4);
    s32 v = 1;
    if (c[3] == 0) {
        u32 t = c[5];
        if (t == 3 && t != 2 && c[0x425] == 0 && c[0x20D] != 3 && *(s16 *)(c + 0x434) != 0) {
            if ((*(u32 *)(c + 0x428) & 0x7000000) != 0) return;
            if (t == 3) {
                func_001E3210(p, 0x24);
                *r = 1;
                return;
            }
        }
    }
    *(s16 *)(q + 0x1C) = v;
    q[0x23] = *(s8 *)(p + 0x23) + 1;
    q[0x151] = 0;
    p[5] = 2;
}

void func_001CCC90(u8 *a, u8 b) {
    extern u8 *func_003DA750();
    extern void func_001CCD40();
    u8 *o;
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        *(void **)(o + 0x10) = func_001CCD40;
        *(u8 **)(o + 0x18) = a;
        *(s16 *)(o + 0x26) = 0x2200;
        o[1] = a[1];
        o[0x20] = b;
        o[0x21] = 0;
    }
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        *(void **)(o + 0x10) = func_001CCD40;
        *(u8 **)(o + 0x18) = a;
        *(s16 *)(o + 0x26) = 0x2200;
        o[1] = a[1];
        o[0x20] = b;
        o[0x21] = 1;
    }
}

void func_00316730(u8 *p, u8 *q) {
    extern void func_00175700();
    extern void func_00316940();
    extern void func_00316980();
    u8 *s1 = *(u8 **)(p + 0x1DC);
    u32 t;
    p[0x152] = 1;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00316940(p, q);
    func_00316980(p, q);
    t = q[0x17];
    q[0x17] = t - 1;
    if (t == 0) {
        u32 u;
        q[0x17] = 0x20;
        p[0x24] = *(s8 *)(s1 + 0x24) + 1;
        u = p[6];
        p[6] = u + 1;
    }
}

extern void func_001CB680(u8 *p, u8 *o);

/* func_001CB920: not yet matched without a stand-in callee. */
