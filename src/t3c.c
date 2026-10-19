typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 a, b, c, d; } Q_001F9A40;
typedef struct { u8 p0[6]; u8 b6; u8 p7[0x2D]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0xE1]; s8 b151; u8 p152[0x65]; u8 b1b7; u8 p1b8[0x2E]; u8 b1e6; } S_001F9A40;
typedef struct { u8 p0[0x22]; u8 b22; u8 p23[0x13]; f32 f38; } S_001C7760;
extern s32 func_00175700();
extern void func_001843A0();
extern Q_001F9A40 D_0044FBB0[];
extern void func_001F9B00();
extern u8 *func_001B3E30(u8 *, int, int);
extern f32 func_00417440(s16);
extern void func_0031AF50();
extern void func_003C4910();

void func_00257CC0(u8 *p) {
    s8 v = p[0x151];
    if (v != 0) {
        f32 d;
        if (p[0x1E6] != 0) {
            d = 1.66666662693f * (f32)v;
        } else {
            d = -(1.66666662693f * (f32)v);
        }
        *(f32 *)(p + 0x34) += d;
    }
    {
        s8 r = func_00175700(p);
        if (r < 0) func_001843A0(p);
    }
}

void func_001F9A40(S_001F9A40 *p) {
    if (p->b151 == 0) {
        u32 t = p->b6;
        Q_001F9A40 *q = D_0044FBB0;
        p->b6 = t + 1;
        q = q + p->b1b7;
        p->f5c = q->a;
        p->f68 = q->b;
        p->f60 = q->c;
        p->f6c = q->d;
        p->f68 += -0.0520833320915699f;
        if (p->b1e6 == 0) {
            p->f5c = -p->f5c;
            p->f68 = -p->f68;
        }
        func_001F9B00(p);
    }
    func_00175700(p);
}

void func_00269690(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        p[6] = 8;
        p[7] = 0;
        return;
    }
    if ((s8)p[0x151] == 1) {
        p[0x151] = 0;
        func_001B3E30(p, 0x20, 0xD);
        func_001B3E30(p, 0x21, 0xD);
    } else if ((s8)p[0x151] == 2) {
        f32 d;
        p[0x151] = 0;
        if (*(s16 *)(p + 0x140) != 0) d = -66.66666412353516f;
        else d = 66.66666412353516f;
        *(f32 *)(p + 0x34) += d;
    }
}

void func_001C7760(u8 *p) {
    f32 r, v;
    u32 t;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x70);
    r = func_00417440(((0x50 - p[0x22]) & 0x3F) << 10);
    v = 1000.0f * r;
    v = 204800.0f * v / 125000.0f / 256.0f;
    v = 2.142857074737549f * v;
    *(f32 *)(p + 0x38) += v;
    t = p[0x22];
    p[0x22] = t + 1;
    t = p[0x22];
    p[0x22] = t & 0x3F;
    func_00175700(p);
}

void func_0031A800(u8 *a, u8 *b) {
    if (b[5] == 2 && (*(u8 **)(b + 0x1C8))[1] == 0x38 && b[0x20A] == 0x12) {
        if (!(*(f32 *)(b + 0x38) <= 342.85711669921875f)) {
            u32 t = a[6];
            a[6] = t + 1;
            *(u8 **)(b + 0x1C8) = a;
            b[0x1B5] = 0x46;
            b[0x20A] = 0x13;
            b[0x20B] = 3;
            b[7] = 0;
            b[6] = 0;
            b[0x1B4] = 0xA;
            func_003C4910(a, 0x12, 0);
        }
    } else {
        func_0031AF50(a, b);
    }
}
