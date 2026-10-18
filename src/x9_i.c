typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00177630(u8 *p) {
    extern void func_0018F320();
    extern void func_00175700();
    extern void func_001757E0();
    extern s32 func_001864a0();
    extern void func_00158C70();
    extern void func_001E3B30();
    f32 z = 0.0f;
    func_0018F320(p);
    func_00175700(p);
    if (*(s16 *)(p + 0x1C) == 0) {
        if (*(f32 *)(p + 0x60) <= z) {
            *(s16 *)(p + 0x1C) = 1;
            func_001757E0(p, 0xD, 0x1D);
        }
    }
    if (*(f32 *)(p + 0x60) <= z) {
        if (func_001864a0(p) != 0) {
            u32 t;
            func_00158C70(p + 0x34, p[2]);
            t = p[6];
            p[6] = t + 1;
            p[0x20D] = 3;
            func_001757E0(p, 0xD, 0x1A);
            func_001E3B30(p);
        }
    }
}

typedef struct {
    u8 pad0[0x38];
    f32 f38;
    u8 pad1[0x5C - 0x3C];
    f32 f5c, f60;
    u8 pad2[0x68 - 0x64];
    f32 f68, f6c;
    u8 pad3[0x430 - 0x70];
    f32 f430;
} Sc;

void func_00230FC0(u8 *p, u8 *q) {
    extern void func_00231CA0();
    Sc *e = *(Sc **)(q + 4);
    f32 z = 0.0f;
    f32 a = e->f60;
    if (a <= z) {
        f32 b = 2.142857074737549f;
        if (a < 32.14285659790039f) {
            a = 32.14285659790039f;
        }
        { f32 c = e->f6c; if (b < c) { b = c; } }
        a += b;
        a += a;
        a += e->f430;
        if (e->f38 < a) {
            u32 t;
            e->f38 = a;
            *(s32 *)&e->f5c = 0;
            *(s32 *)&e->f60 = 0;
            *(s32 *)&e->f68 = 0;
            *(s32 *)&e->f6c = 0;
            t = p[6];
            p[6] = t + 1;
            p[7] = 0;
            func_00231CA0(p, q);
        }
    }
}

typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad1[0x34 - 0x21];
    f32 f34, f38, f3c;
    u8 pad2[0x5C - 0x40];
    f32 f5c;
    u8 pad3[0x140 - 0x60];
    s16 f140;
} Sd;

void func_003A5930(Sd *a, Sd *b) {
    a->f34 = b->f34;
    a->f38 = b->f38;
    a->f3c = b->f3c;
    if (a->f20 == 2) {
        if (a->f140 == 0) {
            a->f34 += -26.66666603088379f;
        } else {
            a->f34 += 26.66666603088379f;
        }
    } else {
        if (a->f140 == 0) {
            a->f34 += -53.33333206176758f;
        } else {
            a->f34 += 53.33333206176758f;
        }
    }
    a->f34 += a->f5c;
}
