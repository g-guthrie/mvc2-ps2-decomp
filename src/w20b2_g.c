typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks: ./try.sh src/w20b2_g.c "-O3 -Op -sdatathreshold 0" */
typedef struct {
    u8 pad0[6]; u8 b6; u8 pad7[0x1E - 7]; s16 h1e; u8 b20; u8 b21; u8 pad22[0x34 - 0x22];
    f32 f34; f32 f38; u8 pad3c[0x5C - 0x3C];
    f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c;
    u8 pad70[0x140 - 0x70]; s16 h140;
} P_g;
extern s16 D_00476100[];
extern s16 D_00476102[];

void func_003C88C0(P_g *p, void *q) {
    extern s32 func_00174470(P_g *);
    extern void func_00175700(P_g *);
    extern void func_003C9200(P_g *, void *);
    extern void func_003C84E0(P_g *, void *, f32, f32);
    if (p->b6 == 0) {
        u32 t = p->b6;
        s16 a, c;
        p->b6 = t + 1;
        a = D_00476100[p->b20 * 2 + p->b21 * 6];
        c = D_00476102[p->b20 * 2 + p->b21 * 6];
        if (p->h140 != 0) {
            a = -a;
            c = -c;
        }
        p->h1e = 0x32;
        p->f34 = p->f34 + 1.6666666f * a;
        func_003C84E0(p, q, 1.6666666f * c, 1028.5714f);
    } else {
        if (func_00174470(p) != 0) {
            s16 h;
            func_00175700(p);
            p->f34 += p->f5c;
            p->f5c += p->f68;
            p->f38 += p->f60;
            p->f60 += p->f6c;
            h = p->h1e - 1;
            p->h1e = h;
            if (h < 0) func_003C9200(p, q);
        } else {
            func_003C9200(p, q);
        }
    }
}

typedef struct { u8 pad0[0x38]; f32 f38; } O_h;
typedef struct {
    u8 pad0[5]; u8 b5; u8 pad6[0x12]; O_h *p18; s16 h1c; u8 pad1e[0x34 - 0x1E];
    f32 f34; f32 f38; u8 pad3c[0x5C - 0x3C];
    f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c;
} P_h;
extern f32 D_00463C00[];

void func_00370480(P_h *p) {
    extern void func_00370730(P_h *);
    extern s32 func_00174170(void);
    extern void func_001E3710(P_h *, s32);
    extern void func_0015B200(P_h *, f32 *, s32, s32);
    f32 v[4];
    f32 *tab;
    f32 *py;
    s16 a;
    tab = D_00463C00;
    func_00370730(p);
    a = p->h1c;
    p->h1c = a - 1;
    if (a == 0) {
        u32 t = p->b5;
        p->b5 = t + 1;
        p->h1c = 8;
    } else {
        if (p->h1c % 6 == 0) {
            v[2] = 0;
            v[0] = p->f34;
            py = &v[1];
            *py = p->f38 - 102.85713958740234f;
            v[0] += tab[func_00174170() & 0xF];
            *py += tab[(func_00174170() & 0xF) + 16];
            func_001E3710(p, 0x49);
            func_0015B200(p, v, 1, 0xC9);
        }
        if (p->f38 <= 102.85713958740234f + p->p18->f38) {
            p->f5c = 0;
            p->f60 = 0;
            p->f68 = 0;
            p->f6c = 0;
        }
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
    }
}
