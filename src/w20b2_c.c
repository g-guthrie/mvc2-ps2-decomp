typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks: ./try.sh src/w20b2_c.c */
typedef struct {
    u8 pad0[6]; u8 b6; u8 pad7[0x34 - 7];
    f32 f34; f32 f38; u8 pad3c[0x5C - 0x3C];
    f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c;
    u8 pad70[0x150 - 0x70]; s8 b150; u8 pad151[0x20D - 0x151]; u8 b20d;
    u8 pad20e[0x430 - 0x20E]; f32 f430;
} P_c;

void func_001F97D0(P_c *p) {
    extern void func_00347AA0();
    extern void func_00347F90(P_c *, s32);
    extern void func_00183d50(P_c *);
    extern void func_001757E0(P_c *, s32, s32);
    extern void func_001F9930(P_c *);
    extern void func_00175700(P_c *);
    if (p->b150 != 0) {
        p->b150 = 0;
        func_00347AA0(p);
        func_00347F90(p, 0);
    }
    if (p->f38 < p->f430) {
        { u32 t = p->b6; p->b6 = t + 1; }
        p->f5c = 0;
        p->f68 = 0;
        p->f60 = 0;
        p->f6c = 0;
        p->f38 = p->f430;
        p->b20d = 1;
        func_00183d50(p);
        func_001757E0(p, 0x15, 4);
        func_001F9930(p);
        return;
    }
    if (p->f60 < 0.0f) {
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        func_00175700(p);
    } else {
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        func_00175700(p);
    }
}

typedef struct {
    u8 pad0[6]; u8 b6; u8 pad7[0x1C - 7]; s16 h1c; u8 pad1e[0x34 - 0x1E];
    f32 f34; f32 f38; u8 pad3c[0x5C - 0x3C];
    f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c;
    u8 pad70[0x1B2 - 0x70]; s8 b1b2; u8 pad1b3[0x1C4 - 0x1B3]; s32 w1c4;
    u8 pad1c8[0x1E6 - 0x1C8]; u8 b1e6; u8 b1e7; u8 pad1e8[0x1ED - 0x1E8]; u8 b1ed;
    u8 pad1ee[0x20B - 0x1EE]; u8 b20b; u8 pad20c[0x210 - 0x20C]; u8 b210;
    u8 pad211[0x33B - 0x211]; u8 b33b; u8 b33c;
    u8 pad33d[0x40C - 0x33D]; u8 b40c; u8 b40d;
} P_e;

void func_00285020(P_e *p) {
    extern void func_00175700(P_e *);
    extern s32 func_00185980(P_e *);
    extern void func_001757E0(P_e *, s32, s32);
    extern void func_00185770(P_e *, s32);
    extern void func_00383B80(P_e *, s32, s32);
    extern void func_00184540(P_e *);
    p->b40c = 2;
    p->b33c = 5;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    if (p->b1b2 != 0) {
        if (func_00185980(p) == 0) {
            f32 f;
            p->b6 = 5;
            p->b210 = 0;
            p->b40d = 0;
            p->b40c = 0;
            p->b33b = 0;
            p->b33c = 0;
            p->b1ed = 2;
            if (p->b1e6 != 0) f = 2.5f; else f = -2.5f;
            p->f5c = f;
            *(u32 *)&p->f68 = 0;
            *(u32 *)&p->f60 = 0x41892492;
            *(u32 *)&p->f6c = 0xBF4DB6DB;
            func_001757E0(p, 0x16, 0xD);
        } else {
            u32 t = p->b6;
            p->b6 = t + 1;
            p->b20b = 0xC2;
            func_00185770(p, p->w1c4);
            func_00383B80(p, 8, 0);
        }
    } else {
        s16 v = p->h1c - 1;
        p->h1c = v;
        if (v == 0) {
            p->b1e7 = 0;
            func_00184540(p);
        }
    }
}
