typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w189_b.c "-O3 -Op -sdatathreshold 0" */
void func_002E29D0(u8 *p) {
    s16 v;
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00174170(void);
    extern void func_003A1DB0(u8 *, s32);
    s32 r;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v == 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x16, 0x12);
        return;
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        *(s16 *)(p + 0x1C) = 2;
        r = func_00174170();
        if ((r & 0x7F) != 0) {
            func_003A1DB0(p, 0);
        } else {
            func_003A1DB0(p, 1);
        }
    }
}

typedef struct S2CE {
    u8 pad0[6]; u8 b6; u8 pad7[0x34 - 7];
    f32 f34; f32 f38; u8 pad3C[0x5C - 0x3C];
    f32 f5C; f32 f60; u8 pad64[0x68 - 0x64]; f32 f68; f32 f6C;
    u8 pad70[0x1E6 - 0x70]; u8 b1E6; u8 pad1E7[0x209 - 0x1E7]; u8 b209;
    u8 pad20A[0x430 - 0x20A]; f32 f430;
} S2CE;
void func_002CEAB0(S2CE *p) {
    f32 *q60;
    f32 *q6C;
    f32 c;
    u32 t;
    extern void func_00175700(S2CE *);
    p->b209 = 2;
    q60 = &p->f60;
    q6C = &p->f6C;
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    func_00175700(p);
    if (p->f38 <= p->f430) {
        t = p->b6;
        p->b6 = t + 1;
        p->f38 = p->f430;
        *q60 = 0.0f;
        *q6C = 0.0f;
        if (p->b1E6 != 0) {
            c = -0.8333333f;
        } else {
            c = 0.8333333f;
        }
        p->f68 = c;
    }
}

typedef struct V3 { f32 x, y, z; } V3;
void func_0021BC40(u8 *a, u8 *b) {
    V3 v;
    f32 dx, dy, vy;
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_00179160(u8 *, u8 *);
    extern u32 func_00119098(f32);
    func_001266A0(a, 6, 6);
    v = *(V3 *)(a + 0x34);
    *(f32 *)(b + 0x38) = *(f32 *)(b + 0x430);
    func_00179160(a, b);
    dx = (*(f32 *)(a + 0x34) - v.x) / 2.0f;
    dy = (*(f32 *)(a + 0x38) - (vy = v.y)) / 2.0f;
    if (func_00119098(1.0f + dx) > 2 || func_00119098(1.0f + dy) > 2) {
        *(f32 *)(a + 0x34) = v.x + dx;
        *(f32 *)(a + 0x38) = vy + dy;
        a[0x152] = 8;
    }
}

typedef struct S231 {
    u8 pad0[7]; u8 b7; u8 pad8[0x1C - 8]; s16 h1C; u8 pad1E[0x20 - 0x1E]; u8 b20; u8 pad21[0x34 - 0x21];
    f32 f34; f32 f38; u8 pad3C[0x5C - 0x3C]; f32 f5C; f32 f60; u8 pad64[0x68 - 0x64]; f32 f68; f32 f6C;
    u8 pad70[0x151 - 0x70]; s8 b151; u8 pad152[0x1B5 - 0x152]; u8 b1B5; u8 pad1B6[0x1C8 - 0x1B6];
    struct S231 *p1C8; u8 pad1CC[0x1DC - 0x1CC]; struct S231 *p1DC; u8 pad1E0[0x430 - 0x1E0]; f32 f430;
} S231;
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];
