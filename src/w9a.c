typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001ACBE0(void *p, void *q, s32 a, s32 b);
void func_001ACD40(void *p, void *q, s8 c) {
    s32 i;
    if (c <= 2) {
        i = 0;
        do {
            func_001ACBE0(p, q, c, i);
            i++;
        } while (i < 6);
    }
}

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_003AD6E0(void);
void func_003AD500(u8 *p) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r != 0) {
        *(u32 *)(r + 0x10) = (u32)func_003AD6E0;
        *(u32 *)(r + 0x18) = *(u32 *)(p + 0x18);
        *(u16 *)(r + 0x1C) = *(u16 *)(*(u8 **)(p + 0x18) + 0x168);
        r[0x20] = 3;
        r[0x21] = p[0x21];
        r[0x22] = p[0x22];
        r[5] = p[5];
        *(s16 *)(r + 0x26) = 0x3002;
    }
}

extern void (*D_0044ED70[])(void *, void *);
void func_001DD9A0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    s8 v;
    D_0044ED70[p[0x20]](p, q);
    p[0x24] = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) p[0x24] = 7;
    if (*(s8 *)(p + 0x24) < 0) p[0x24] = 0;
}

extern s32 func_0018F270(void *p);
extern void func_0018CDF0(void *p, void *q);
void func_0018DB70(u8 *p, void *q) {
    if (func_0018F270(p) != 0) {
        p[0x248] = 1;
        p[0x243] = 12;
        if (p[0x242] > 0x1B) p[0x242] = 0x1B;
        p[0x249] = 1;
        p[0x247] = 2;
        func_0018CDF0(p, q);
    } else {
        p[0x248] = 0;
        p[0x247] = 1;
        func_0018CDF0(p, q);
    }
}

extern s32 func_00175700(void *p);
extern s32 func_001843A0(void *p);
extern s32 func_00184540(void *p);
extern void func_00372BE0(void *p, s32 a);
s32 func_00265A10(u8 *p) {
    s8 r;
    p[0x40C] = 2;
    p[0x33C] = 5;
    r = func_00175700(p);
    if (r < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        if (p[0x20D] == 0) {
            return func_001843A0(p);
        } else {
            func_00184540(p);
        }
    } else if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_00372BE0(p, 0);
    }
}

extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_002CDEB0(void *p);
void func_002CE030(u8 *p) {
    s8 r;
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    r = func_00175700(p);
    if (r < 0) {
        t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 3;
        func_001757E0(p, 0x15, 6);
        func_002CDEB0(p);
    }
}

typedef struct { f32 x, y, z; } V3;
extern void func_00163C70(void);
void func_00163E60(V3 *src, s32 flag) {
    u8 *r = func_003DA750(0, 0x2F, 1);
    if (r != 0) {
        r[0x13C] = 1;
        *(u32 *)(r + 0x10) = (u32)func_00163C70;
        *(u32 *)(r + 0xD0) = 0x800405;
        *(V3 *)(r + 0x34) = *src;
        *(u32 *)(r + 0x78) = 0x3F800000;
        *(u32 *)(r + 0x7C) = 0x3F800000;
        *(u32 *)(r + 0x80) = 0x3F800000;
        *(u32 *)(r + 0x44) = flag ? 0x4000 : 0xC001;
        *(u32 *)(r + 0xD4) = 3;
    }
}

typedef struct { u8 pad[8]; s32 a; u8 pad2[6]; u16 b; u16 c; u16 d; u8 pad3[0x18]; } E30;
extern E30 D_004F54D0[];
void func_001B5AE0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    u16 m;
    E30 *e;
    s32 i;
    if (*(u16 *)(p + 0xD0) == *(u16 *)(q + 0x168)) return;
    p[4] = 2;
    switch (q[0x169]) {
    case 7:
    case 8:
    case 0xB:
        return;
    }
    m = 0xF000;
    i = *(s16 *)(q + 0x13E) + 2;
    e = &D_004F54D0[i];
    e->a = 1;
    e->b |= m;
    e->c |= 0xF000;
    e->d |= 0xF000;
}

extern u8 D_004D18A0;
extern void func_00186CE0(void *p, s32 a);
void func_0017AE20(u8 *p) {
    s16 v;
    *(s8 *)(p + 0x1F4) = -0x4C;
    p[0x1F3] = 0xFF;
    if (D_004D18A0 < 5) {
        if (*(s16 *)(p + 0x434) <= 0) {
            func_00175700(p);
            return;
        }
        v = *(s16 *)(p + 0x1F8) - 1;
        *(s16 *)(p + 0x1F8) = v;
        if (v >= 0) {
            if (*(s8 *)(p + 0x1F7) != 0) {
                func_00175700(p);
                return;
            }
        }
    }
    p[0x1F7] = 0;
    p[0x203] = 8;
    func_00186CE0(p, 0);
}

extern void func_001E3210(void *p, s32 a);
extern void func_001CEA60(void *p);
void func_002C8460(u8 *p, u8 *q) {
    s8 r;
    u32 t;
    if (*(s8 *)(p + 0x161) != 0) q[4] = 1;
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        q[4] = 1;
    }
    r = func_00175700(p);
    if (r < 0) {
        t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x14;
        q[4] = 1;
        p[0x13C] = 0;
        p[0x209] = 1;
        func_001E3210(p, 0x1B);
        func_001CEA60(p);
    }
}

extern void func_001830D0(void *p, void *v, s32 a);
void func_002B5FB0(u8 *p) {
    u32 v[4];
    u32 t;
    u8 x;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (p[0x269] == 6) {
        x = 2;
    } else {
        x = 0;
    }
    p[0x405] = x;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) < 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0xC1555555;
        v[1] = 0x431E9249;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}
