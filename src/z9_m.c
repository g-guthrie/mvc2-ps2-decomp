typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct Q1 {
    u8 pad0[0x1E]; s16 s1e; u8 pad20[0x1B2 - 0x20]; s8 b1b2;
} Q1;
typedef struct {
    u8 p0[4]; u8 b4; u8 pad5[0x18 - 5]; Q1 *q18; u8 pad1c[0x34 - 0x1C];
    f32 f34; f32 f38; u8 pad3c[0x5C - 0x3C];
    f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c;
    u8 pad70[0x1B2 - 0x70]; s8 b1b2; s8 b1b3;
} A1;

void func_0039D5F0(A1 *p) {
    s32 x;
    extern int func_00174470(const void *);
    extern void func_001E7F60();
    extern void func_0039E450();
    extern void func_0015B200();
    extern void func_001E3710();
    if (p->q18->b1b2 == 0) {
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        if (func_00174470(p) != 0) {
            func_001E7F60(p);
            return;
        }
    }
    p->q18->s1e -= 1;
    if (p->b1b3 == 0 && ((x = p->b1b2) == 0 || ((s8)x & 1) == 0)) {
        func_0039E450(p);
    } else {
        u32 t = p->b4;
        p->b4 = t + 1;
        func_0015B200(p, &p->f34, 1, 8);
        func_001E3710(p, 0x49);
    }
}

typedef struct Y1 { u8 pad[0x34]; f32 f34; } Y1;
typedef struct {
    u8 p0[0x20]; u8 b20; u8 pad21[0x34 - 0x21]; f32 f34; u8 pad38[0x5C - 0x38]; f32 f5c;
    u8 pad60[0x140 - 0x60]; s16 s140; u8 pad142[0x220 - 0x142]; Y1 *y220;
    u8 pad224[0x354 - 0x224]; u16 h354; u8 pad356[0x539 - 0x356]; s8 b539;
} B1;

s32 func_00324830(B1 *p) {
    extern void func_00324A00();
    extern void func_001757E0(B1 *, s32, u8);
    s32 h = p->h354;
    f32 d, v, z;
    s32 k;
    s32 c;
    if (p->b539 != 0) {
        d = p->y220->f34 - p->f34;
        h = 0;
        if (!(d <= 266.6666564941406f)) h = 0x400;
        if (d < -266.6666564941406f) h = 0x800;
    }
    if ((h & 0xC00) != 0) {
        p->b20 = 1;
        v = 5.0f;
        if ((h & 0x800) != 0) v = -v;
        p->f5c = v;
        func_00324A00(p);
        k = 7;
        z = 0.0f;
        c = 0;
        if (!(p->f5c <= z)) c = 1;
        if (p->s140 != c) k = 14;
        func_001757E0(p, 0x16, k);
        return 1;
    }
    return 0;
}

typedef struct {
    u8 p0[0x34]; f32 f34; u8 pad38[0x5C - 0x38]; f32 f5c; u8 pad60[0x68 - 0x60]; f32 f68;
    u8 pad6c[0x151 - 0x6C]; s8 b151; u8 pad152[0x1E6 - 0x152]; u8 b1e6;
} C1;

void func_00320C80(C1 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_001E3710();
    f32 *a1, *a2;
    s32 v;
    f32 c;
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    v = p->b151;
    if (v & 1) {
        p->b151 = v ^ 1;
        *(u32 *)&p->f5c = 0xC0FD5555;
        *(u32 *)&p->f68 = 0x3E200000;
        if (p->b1e6 != 0) {
            p->f5c = -p->f5c;
            p->f68 = -p->f68;
        }
        func_001E3710(p, 0x29);
    }
    p->f34 += p->f5c;
    a1 = &p->f5c;
    a2 = &p->f68;
    p->f5c += p->f68;
    v = p->b151;
    if (v & 2) {
        p->b151 = v ^ 2;
        *(u32 *)a1 = 0;
        *(u32 *)a2 = 0;
        c = -53.33333206176758f;
        if (p->b1e6 != 0) c = -c;
        p->f34 += c;
    }
}
