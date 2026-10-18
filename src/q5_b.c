typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00186A60(u8 *, s32);

void func_0024D5C0(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0:
        p[0x1FD] = 0;
        p[0x1B7] = 1;
        break;
    case 1:
        p[0x1FD] = 8;
        break;
    case 2:
        p[0x1FD] = 9;
        break;
    }
    func_00186A60(p, 0x15);
}

extern void (*D_0044E4F0[])();

void func_001D5470(u8 *a, u8 *b) {
    if (b[5] != 0 || b[0x1E4] != 0x1D) {
        a[4] = 2;
        a[0x13C] = 0;
    } else {
        D_0044E4F0[a[5]](a, b);
    }
}

extern s8 func_00175700(u8 *);
extern s32 func_001E7FD0(u8 *);
extern void func_00185640(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);

void func_00228950(u8 *a) {
    s32 r;
    if (func_00175700(a) < 0) {
        if ((r = func_001E7FD0(a)) != 0) {
            a[0x20B] = 0xC1;
            func_00185640(a, r);
        } else {
            a[6]++;
            func_001757E0(a, 0x15, 0x1B);
        }
    }
}

typedef struct P36 { u8 p0[0x34]; f32 f34; f32 f38; f32 f3c; u8 p40[0x100]; s16 h140; } P36;
extern void func_001757E0(u8 *, s32, s32);

void func_0036CAD0(P36 *self) {
    u8 *a = (u8 *)self;
    a[0x13C] = 1;
    self->f34 = (*(P36 **)(a + 0x18))->f34;
    self->f38 = (*(P36 **)(a + 0x18))->f38;
    self->f3c = (*(P36 **)(a + 0x18))->f3c;
    self->f34 += (f32)((*(P36 **)(a + 0x18))->h140 != 0 ? -0x10 : 0x10);
    self->f38 += 176.0f;
    *(u32 *)(a + 0x68) = 0;
    *(u32 *)(a + 0x6C) = 0;
    a[0x169] = 0x17;
    func_001757E0(a, a[0x169], 0x21);
}

typedef struct { f32 x, y, z; } V3;
extern s8 func_00175700(u8 *);
extern void func_001830D0(u8 *, V3 *, s32, s32);

void func_002BDF00(u8 *a) {
    a[0x40C] = 2;
    a[0x33C] = 5;
    a[0x405] = (a[0x269] == 6) ? 2 : 0;
    func_00175700(a);
    if (*(s8 *)(a + 0x151) != 0) {
        V3 v;
        u32 n = a[6] + 1;
        a[6] = n;
        a[0x151] = 0;
        a[0x404] = 0;
        a[0x405] = 0;
        v.x = 30.0f;
        v.y = 120.0f;
        v.z = 0.0f;
        func_001830D0(a, &v, 1, n);
    }
}

typedef struct { s8 p0, p1, b2, b3, b4, b5, b6, b7, b8, b9, bA, bB; s8 pad[4]; } E3D;
typedef struct { u8 p0[6]; s8 b6; u8 p7; s8 b8[2]; u8 p0a[0x16]; s16 h20[8]; } O3D;
extern E3D D_004F7D10[];
extern O3D D_004F7FC0[];
extern s8 D_004F7FC6;

void func_003D47E0(void) {
    O3D *o = D_004F7FC0;
    s32 i = 0;
    E3D *e;
    s32 j = 0;
    O3D *oo;
    D_004F7FC6 = 0;
    do {
        e = (E3D *)((u8 *)D_004F7D10 + j);
        oo = (O3D *)((u8 *)o + j);
        o->b6 |= e->b2 << i;
        o->b8[i] = e->b3;
        oo->h20[0] = e->b4;
        oo->h20[1] = e->b5;
        oo->h20[2] = e->b6;
        oo->h20[3] = e->b7;
        oo->h20[4] = e->bA;
        oo->h20[5] = e->b8;
        oo->h20[6] = e->bB;
        oo->h20[7] = e->b9;
        i++;
        j += 0x10;
    } while (i < 2);
}

typedef struct S217 {
    u8 p0[6]; u8 b6; u8 b7; u8 p8[0x2C]; f32 f34; f32 f38; u8 p3c[0x20];
    f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c;
} S217;
extern s8 func_00175700(u8 *);
extern s32 func_001864a0(u8 *);
extern void func_001757E0(u8 *, s32, s32);

void func_00217F90(S217 *a) {
    a->f34 += a->f5c;
    a->f5c += a->f68;
    a->f38 += a->f60;
    a->f60 += a->f6c;
    func_00175700((u8 *)a);
    if (func_001864a0((u8 *)a) != 0) {
        u32 t = a->b6;
        a->b6 = t + 1;
        a->b7 = 0;
        a->f34 -= a->f5c;
        *((u8 *)a + 0x20D) = 0;
        func_001757E0((u8 *)a, 0x12, 2);
    }
}

typedef struct S20A {
    u8 p0[7]; u8 b7; u8 p8[0x14]; s16 h1c; u8 p1e[0x16]; f32 f34; f32 f38; u8 p3c[0x20];
    f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c;
} S20A;
extern s8 func_00175700(u8 *);

void func_0020A430(S20A *a, u8 *b) {
    f32 *p5c;
    f32 *p68;
    func_00175700((u8 *)a);
    p5c = &a->f5c;
    p68 = &a->f68;
    a->f34 += a->f5c;
    a->f5c += a->f68;
    a->f38 += a->f60;
    a->f60 += a->f6c;
    {
        s16 c = a->h1c - 1;
        a->h1c = c;
        if (c == 0) {
            u32 t = a->b7;
            a->b7 = t + 1;
            a->f34 = *(f32 *)(b + 0x10);
            *(u32 *)p5c = 0;
            *(u32 *)p68 = 0;
        }
    }
}

extern s8 func_00175700(u8 *);
extern void func_00184540(u8 *);
extern void func_0037D930(u8 *, s32);
extern void func_001BBD80(u8 *, s32);

void func_00274CB0(u8 *a) {
    if (func_00175700(a) < 0) {
        func_00184540(a);
        return;
    }
    if (a[0x1FC] == 2) {
        if (*(s8 *)(a + 0x151) == 2) {
            a[0x151] = 0;
            func_0037D930(a, 2);
            func_001BBD80(a, 2);
            *(u32 *)(a + 0x60) = 0;
            *(u32 *)(a + 0x6C) = 0;
            *(u32 *)(a + 0x60) = 0x41055555;
            *(u32 *)(a + 0x6C) = 0xBFC80000;
        }
        if (*(s8 *)(a + 0x151) == 3) {
            a[0x151] = 0;
            func_001BBD80(a, 5);
        }
    }
}

typedef struct S159 {
    u8 p0[4]; u8 b4[2]; u8 b6[2]; u8 p8[0x14]; s16 h1c; u8 p1e[0x16]; f32 f34; u8 p38[4]; f32 f3c;
    u8 p40[0x10]; f32 f50; f32 f54; f32 f58; f32 f5c; u8 p60[4]; f32 f64; u8 p68[0x10]; f32 f78; f32 f7c; f32 f80;
} S159;
extern u8 D_00444F10[];
extern u8 D_00444F20[];
extern f32 func_00154710(u8 *, u8 *, s32);
extern void func_003DAA40();

void func_00159EA0(S159 *a) {
    f32 r;
    if (a->h1c >= 0xD) {
        func_003DAA40(a);
        return;
    }
    r = func_00154710(D_00444F10, a->b4, a->h1c);
    a->f50 = r;
    a->f54 = r;
    a->f58 = a->f50;
    a->f34 += a->f5c;
    a->f3c += a->f64;
    r = func_00154710(D_00444F20, a->b6, a->h1c);
    a->f78 = r;
    a->f7c = r;
    a->f80 = a->f78;
    a->h1c++;
}

typedef struct S1778 {
    u8 p0[2]; u8 b2; u8 p3[3]; u8 b6; u8 p7[0x15]; s16 h1c; u8 p1e[0x16]; u8 p34[0x2C]; f32 f60;
} S1778;
extern void func_0018F320();
extern s8 func_00175700(u8 *);
extern s32 func_001864a0(u8 *);
extern void func_001E3B30();
extern void func_00158C70(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);

void func_001778D0(S1778 *a) {
    u32 t;
    func_0018F320(a);
    func_00175700((u8 *)a);
    if (a->h1c == 0) {
        if (a->f60 > 0.0f) {
            a->h1c = 1;
            func_001757E0((u8 *)a, 0xD, 0x1D);
        }
    }
    if (func_001864a0((u8 *)a) != 0) {
        func_001E3B30(a);
        func_00158C70((u8 *)a + 0x34, a->b2);
        t = a->b6;
        a->b6 = t + 1;
        *((u8 *)a + 0x20D) = 3;
        func_001757E0((u8 *)a, 0xD, 0x1A);
    }
}
