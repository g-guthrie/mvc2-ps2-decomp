typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 dptoli(double);



typedef struct { u8 p0[0x20]; u8 f20; } S3;
extern s8 D_004D18E0[];
extern s32 D_004C2834;
extern u8 *D_004C2840;
void func_00134E40(void *a) {
    u8 *p = (u8 *)a;
    s32 x;
    s32 c = D_004D18E0[0];
    if (p[0x20] == 0) x = c / 10;
    else x = c % 10;
    *(s16 *)(p + 0xCC) = x + 0x55;
    *(s32 *)(p + 0x84) = D_004C2834;
}
void func_001E40E0(void);
void func_001E4140(void);
void func_001E4150(void);
void func_00127520(void) {
    D_004C2840[3] = 0;
    D_004C2840[4] = 0;
    D_004C2840[5] = 0;
    D_004C2840[6] = 0;
    D_004C2840[7] = 0;
    if (((s8 *)D_004C2840)[0x88] == 0) D_004C2840[2] = 3;
    func_001E40E0();
    func_001E4140();
    func_001E4150();
}

void func_00186A60(void *a, s32 b);
void func_00304A80(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (((s8 *)p)[0x4DD]) {
    case 0:
        p[0x1FD] = 2;
        p[0x1B7] = 0;
        break;
    case 1:
        p[0x1FD] = 0;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 9;
        p[0x1B7] = 1;
        break;
    }
    func_00186A60(p, 0x15);
}

typedef struct { u8 p0[0x34]; float f34; float f38; } S4;
typedef struct { u8 p0[5]; u8 f5; u8 p1[2]; S4 *f8; u8 p2[0x28]; } S5;
void func_001A87F0(void *p, s32 a1);
extern void func_001A8140(u8 *, u8 *);
void func_001A81B0(u8 *p, u8 *q) {
    u32 t = p[5];
    u8 *s;
    float f;
    s = *(u8 **)(p + 8);
    p[5] = t + 1;
    if (s[0x20] == 4) f = -26.666666f;
    else f = -53.333332f;
    if (*(s16 *)(p + 0x140) != 0) f = -f;
    *(float *)(p + 0x34) = *(float *)(s + 0x34) + f;
    *(float *)(p + 0x38) = *(float *)(s + 0x38);
    func_001A8140(p, q);
}

void func_001A88A0(u8 *p, s32 a1, s32 a2) {
    u32 t = p[5];
    u8 *s;
    float f;
    s = *(u8 **)(p + 8);
    p[5] = t + 1;
    if (s[0x20] == 10) f = -26.666666f;
    else f = -53.333332f;
    if (*(s16 *)(p + 0x140) != 0) f = -f;
    *(float *)(p + 0x34) = *(float *)(s + 0x34) + f;
    *(float *)(p + 0x38) = *(float *)(s + 0x38);
    func_001A87F0(p, a1);
}

typedef struct W {
    u8 p0[0x18]; struct W *f18;
} W;
extern u16 *D_004C29AC;
void func_003859F0(void *a);
s8 func_00175700(void *a);
void func_003845E0(u8 *a) {
    u8 *b;
    if (*D_004C29AC != *(u16 *)(*(u8 **)(a + 0x18) + 0x168)) {
        func_003859F0(a);
    } else {
        b = *(u8 **)(a + 0x18);
        *(float *)(a + 0x34) = *(float *)(b + 0x34);
        *(float *)(a + 0x38) = *(float *)(*(u8 **)(a + 0x18) + 0x38);
        a[0x24] = 0;
        if (*(s8 *)(*(u8 **)(a + 0x18) + 0x161) != *(s8 *)(a + 0x161)) func_00175700(a);
    }
}

extern u16 *D_004C26E8;
void func_001B93D0(void *a);
s8 func_00175670(void *a);
void func_001B9350(u8 *a) {
    u8 *b;
    if (*D_004C26E8 != *(u16 *)(*(u8 **)(a + 0x18) + 0x168)) {
        func_001B93D0(a);
    } else {
        b = *(u8 **)(a + 0x18);
        *(float *)(a + 0x34) = *(float *)(b + 0x34);
        *(float *)(a + 0x38) = *(float *)(*(u8 **)(a + 0x18) + 0x38);
        if (func_00175670(a) < 0) func_001B93D0(a);
    }
}

extern u8 *D_004C2840;
extern void (*D_00440900[])(void *);
void func_003DAA40(void *a);
void func_0013FAC0(u8 *a) {
    u8 *g = D_004C2840;
    if (((s8 *)g)[3] != 4 || ((s8 *)g)[0x91] != 0) {
        func_003DAA40(a);
    } else if (*(s16 *)(g + 0xE) == 3) {
        D_00440900[a[0x20]](a);
    }
}

extern s8 D_004BFA44[8];
void func_001C8D60(u8 *a) {
    *(float *)(a + 0x34) = *(float *)(*(u8 **)(a + 0x18) + 0x34);
    *(float *)(a + 0x38) = *(float *)(*(u8 **)(a + 0x18) + 0x38);
    if (*(s16 *)(*(u8 **)(a + 0x18) + 0x140) != 0) {
        *(float *)(a + 0x34) = *(float *)(a + 0x34) + 1.6666666f * (float)D_004BFA44[a[0x20]];
    }
    ((s8 *)a)[0x24] = ((s8 *)*(u8 **)(a + 0x18))[0x24];
    ((s8 *)a)[0x31] = -1;
}

void func_00184540(void *a);
void func_0020B310(u8 *a) {
    if (func_00175700(a) < 0) {
        u32 n = a[6];
        a[6] = n + 1;
        *(s32 *)(a + 0x5C) = 0;
        *(s32 *)(a + 0x60) = 0;
        *(s32 *)(a + 0x68) = 0;
        *(s32 *)(a + 0x6C) = 0;
        *(float *)(a + 0x6C) = -0.8035714f;
        if (a[0x212] == 0) func_00184540(a);
        else func_001757E0(a, 0x15, 4);
    }
}

extern void (*D_004C1CD8[2])(void *);
void func_00372130(u8 *a) {
    u8 *s = *(u8 **)(a + 0x18);
    u8 *t;
    u32 n;
    D_004C1CD8[a[5]](a);
    t = s + 0x2B8;
    if (s[0x2B9] != 0) {
        n = a[4];
        a[4] = n + 1;
        a[0x13C] = 0;
        t[0] = 0;
    } else if (s[5] != 0) {
        n = a[4];
        a[4] = n + 1;
        a[0x13C] = 0;
        t[0] = 0;
    }
}

typedef struct { float x, y, z; } V3;
extern V3 D_004B7F58;
extern s32 D_004C283C;
void func_003356D0(void);
u8 *func_003DA750(s32 a, s32 b, s32 c);
void func_00335950(u8 *a) {
    u8 *o = func_003DA750(0, 6, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_003356D0;
        *(s16 *)(o + 0xCC) = 0x24;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x805;
        *(V3 *)(o + 0x34) = D_004B7F58;
        *(u8 **)(o + 0xC8) = a + 0x88;
        *(u8 **)(o + 0x18) = a;
    }
}

s32 func_00333EC0(void *a);
void func_00333E30(u8 *a) {
    u32 v = (u32)dptoli(*(float *)(a + 0x70) * 65536.0 / 360.0 + 0.5);
    *(u32 *)(a + 0x48) = (u16)v;
    if (func_00333EC0(a) != 0) {
        u32 n = a[5];
        a[5] = n + 1;
        a[6] = 1;
    }
}

extern s8 *D_004C28D8;
void func_002C2FE0(u8 *a) {
    u32 n;
    a[0x40C] = 2;
    a[0x33C] = 5;
    func_00175700(a);
    if (((s8 *)a)[0x151] != 0) {
        n = a[6];
        a[6] = n + 1;
        a[0x151] = 0;
        D_004C28D8[0] = 2;
        if (((s8 *)a)[0x539] != 0 || a[0x269] == 4 || a[0x269] == 5) {
            a[0x22] = 7;
            D_004C28D8[1] = -1;
        } else {
            a[0x22] = 5;
        }
    }
}
