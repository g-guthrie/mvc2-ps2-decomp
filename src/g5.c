typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s8 func_00175700(u8 *p);
extern void func_00186A20(u8 *p);
extern u8 D_004F20CE[];
extern u8 D_00583B92[];
extern u8 D_00583BC6;
extern s32 func_00118FA8(f32 f);
extern f32 D_004F1FCC;
extern f32 D_004F1FC8;

void func_0022B240(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(s8 *)(p + 0x151) == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00186A20(p);
    }
}

void func_00138690(u8 *p) {
    u32 i = p[0x20];
    if (*(s16 *)(D_004F20CE + 0x5B8 * i) == 0 && (D_00583B92[i] & 0x10) != 0) {
        u32 t = p[5];
        p[5] = t + 1;
        p[0x22] = 0;
        D_00583BC6 |= (u8)(1 << *(s8 *)(p + 0x20));
    }
}

void func_003C3CE0(u8 *p, u8 *ignored) {
    s16 *q = (s16 *)(p + 0xD0);
    if (*(s16 *)(p + 0x140) == 0) {
        q[1] = func_00118FA8(D_004F1FCC);
    } else {
        q[1] = func_00118FA8(D_004F1FC8);
    }
    if ((f32)q[0] > 600.0f) {
        q[0] = 600;
    }
}


extern void func_0015E630(u8 *p);
extern void func_0036A620(u8 *p);
extern u8 *func_003DA750(u8 *p, s32 a, s32 b);
extern void func_001DF5C0(void);

void func_00369730(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    q[0x1FE] = 1;
    q[0x201] = 2;
    q[0x209] = 2;
    func_0036A620(p);
    if (func_00175700(p) < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        func_0015E630(p);
        p[0] = 1;
    }
}

u8 *func_001DF540(u8 *p, s32 s) {
    u8 *r = func_003DA750(p, 3, 2);
    if (r != 0) {
        s32 v = (u16)s;
        *(void **)(r + 0x10) = (void *)func_001DF5C0;
        r[0x20] = v >> 8;
        r[0x21] = v;
        *(u32 *)(r + 0x18) = *(u32 *)(p + 0x18);
        *(u8 **)(r + 0x14) = p;
        r[1] = p[1];
        *(s16 *)(r + 0x26) = 0x3800;
    }
    return p;
}

extern void func_001830D0(u8 *p, f32 *v, s32 a, s32 b);

void func_001DE470(u8 *a, u8 *b) {
    a[0x24] = *(s8 *)(b + 0x24);
    if (b[0x169] != 0x15) {
        u32 t = a[4];
        a[4] = t + 1;
    } else {
        if (func_00175700(a) < 0) {
            u32 t = a[4];
            a[4] = t + 1;
            a[0x13C] = 0;
        }
    }
}

void func_00370FD0(u8 *p) {
    s16 v;
    u8 *q = *(u8 **)(p + 0x18);
    if (*(s16 *)(p + 0x1C) == 0x28) {
        q[0x2C6] = 0;
    }
    v = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = v - 1;
    if (v == 0) {
        u32 t = p[4];
        p[4] = t + 1;
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
}

void func_0027C290(u8 *p) {
    if (func_00175700(p) < 0) {
        f32 v[3];
        u32 t = p[6] + 1;
        p[6] = t;
        *(u32 *)&v[0] = 0x40D55555;
        *(u32 *)&v[1] = 0x436DDB6D;
        v[2] = 0;
        func_001830D0(p, v, 1, t);
    }
}


extern void func_0019A540(void);

extern f32 D_004F1FDC;
extern f32 D_004F1FD8;

void func_00126970(f32 *a, f32 *b) {
    if (320.0f + *a > D_004F1FDC) {
        *a = D_004F1FDC - 320.0f;
        *b = D_004F1FDC - 320.0f;
    }
    if (*a - 320.0f < D_004F1FD8) {
        *a = 320.0f + D_004F1FD8;
        *b = 320.0f + D_004F1FD8;
    }
}

extern void func_0019A540(void);

void func_0019A4C0(u8 *p, u8 b) {
    u8 *r = func_003DA750(0, 3, 1);
    if (r != 0) {
        *(void **)(r + 0x10) = (void *)func_0019A540;
        *(u32 *)(r + 0x18) = *(u32 *)(p + 0x18);
        *(u8 **)(r + 0x14) = p;
        *(V3 *)(r + 0x34) = *(V3 *)(p + 0x34);
        r[0x20] = b;
        *(s16 *)(r + 0x26) = 0x601;
    }
}

extern void func_00289E30(u8 *p);

void func_00289CF0(u8 *p) {
    s32 a, b;
    f32 t;
    func_00175700(p);
    func_00289E30(p);
    a = func_00118FA8(*(f32 *)(p + 0x5C));
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    b = func_00118FA8(*(f32 *)(p + 0x5C));
    if ((a ^ b) < 0) {
        u32 c = p[7];
        p[7] = c + 1;
    }
}

extern void func_0028D8B0(u8 *p);
extern void func_00126400();
extern void func_0028D810(u8 *p, u8 *q);
extern void func_001C09A0(u8 *p, s32 a);
extern u8 D_00455DF0[];

void func_0028C6F0(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_0028D8B0(p);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00126400();
        *(s16 *)(p + 0x1E) = 4;
        p[7] = 0;
        func_0028D810(p, D_00455DF0);
        func_001C09A0(p, 9);
    }
}

extern void func_001B8F80();
extern void func_00175580(u8 *p, s32 a, s32 b, s32 c);

void func_001B8F20(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    s32 n;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    p[0x24] = 0;
    n = q[0x15B] - 1;
    if (n < 0) {
        func_001B8F80();
    } else {
        func_00175580(p, 0x1B, 0xB, (s8)n);
    }
}

extern s32 func_0032D620(s32 *out, s32 a);
extern u8 D_00583B9D;
extern u32 D_00583BB0[][2];

void func_0032D660(u8 *p, u8 b) {
    if (D_00583B9D == 0) {
        s32 x;
        u8 r = func_0032D620(&x, *(s8 *)(p + 0x540));
        u32 *e = &D_00583BB0[b][r];
        if ((e[0] & x) != 0) {
            e[0] ^= x;
        }
    }
}

extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern void (*D_0044CF00[])();

void func_001C9B10(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
        p[0x24] = *(s8 *)(q + 0x24);
        D_0044CF00[p[0x20]]();
    }
}
