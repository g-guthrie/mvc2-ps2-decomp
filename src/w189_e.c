typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w189_e.c "-O3 -Op -sdatathreshold 256" */
extern s32 D_004C0258[4];
extern s8 D_004C0260[4];
typedef struct P23C { u8 pad0[7]; u8 b7; u8 pad8[0x1C - 8]; s16 h1C; s16 h1E; u8 pad20[0x5C - 0x20]; f32 f5C; u8 pad60[0x68 - 0x60]; f32 f68; u8 pad6C[0x151 - 0x6C]; s8 b151; u8 pad152[0x1B7 - 0x152]; u8 b1B7; u8 pad1B8[0x1E6 - 0x1B8]; u8 b1E6; } P23C;
void func_0023C040(P23C *p) {
    u32 t;
    s32 v;
    f32 c;
    f32 e;
    extern void func_00175700(P23C *);
    extern void func_001E3210(P23C *, s32);
    extern void func_001A31D0(P23C *, s32, s32);
    func_00175700(p);
    if (p->b151 != 0) {
        t = p->b7;
        p->b7 = t + 1;
        v = D_004C0258[p->b1B7];
        if (p->b1E6 != 0) {
            e = (1.6666666269302368f * (f32)v) / 65536.0f;
        } else {
            e = -((1.6666666269302368f * (f32)v) / 65536.0f);
        }
        p->f5C = e;
        c = (p->b1E6 != 0) ? -0.1041666641831398f : 0.1041666641831398f;
        p->f68 = c;
        p->h1C = D_004C0260[p->b1B7];
        p->h1E = 8;
        func_001E3210(p, 0x14);
        func_001E3210(p, 0x20);
        func_001A31D0(p, 5, 0);
    }
}

typedef struct E16 { u8 b0; u8 pad1[0x33]; f32 f34; f32 f38; u8 pad3C[0x14C - 0x3C]; u8 b14C; u8 b14D; u8 b14E; u8 pad14F[0x1B8 - 0x14F]; u8 b1B8; u8 pad1B9[0x5B8 - 0x1B9]; } E16;
typedef struct Q16 { u8 pad0[0x34]; f32 f34; } Q16;
typedef struct P16 { u8 pad0[2]; u8 b2; u8 pad3[0x34 - 3]; f32 f34; f32 f38; u8 pad3C[0x220 - 0x3C]; Q16 *p220; u8 pad224[0x498 - 0x224]; f32 f498; f32 f49C; f32 f4A0; } P16;
extern E16 D_004F20B0[];
void func_0016A000(P16 *p) {
    E16 *e;
    f32 d, f, g;
    s32 i;
    s32 best;
    f32 zero = 0.0f;
    d = p->p220->f34 - p->f34;
    if (d < zero) d = -d;
    e = &D_004F20B0[p->b2 ^ 1];
    best = -1;
    i = 0;
    do {
        if (e->b0 != 0) {
            f = e->f34 - p->f34;
            if (f < zero) f = -f;
            if (!(d < f)) {
                best = e->b1B8;
                d = f;
            }
        }
        i++;
        e += 2;
    } while (i < 3);
    if (best != -1) e = &D_004F20B0[best];
    p->f49C = d;
    p->f4A0 = e->f38 - p->f38;
    f = p->f49C;
    g = (f32)(u32)e->b14E;
    p->f498 = f - 1.6666666269302368f * g;
}

typedef struct P67 { u8 pad0[2]; u8 b2; u8 pad3[0x34 - 3]; f32 f34; f32 f38; } P67;
typedef struct Q67 { u8 pad0[5]; s8 b5; } Q67;
