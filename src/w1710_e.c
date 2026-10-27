typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern s8 D_004D1900;
void func_00154A20(V3 *v, s32 unused, s32 c, s32 d, s32 e) {
    extern void *func_003DA750(void *, int, int);
    extern void func_00154B10(u8 *);
    extern u8 *func_00154B60(u8 *, int);
    extern u8 *func_00154C60(u8 *, int);
    extern void func_00154D60(u8 *, int);
    extern void func_00154F10(u8 *, int);
    extern void func_001550D0(f32 *, s32, s32, s32);
    u8 *o;
    if ((o = func_003DA750(0, e, 1)) != 0) {
        D_004D1900 = D_004D1900 + 1;
        o[0x13C] = 0;
        *(void (**)(u8 *))(o + 0x10) = func_00154B10;
        *(V3 *)(o + 0x34) = *v;
        *(u32 *)(o + 0xD0) = 0x800181;
        func_00154B60(o, e);
        func_00154C60(o, e);
        func_00154D60(o, e);
        func_00154F10(o, e);
        func_001550D0(&v->x, c, d, e);
    }
}

typedef struct { u8 pad0[7]; u8 b7; u8 pad8[0x14]; s16 h1c; s16 h1e; u8 pad20[0x14]; f32 f34, f38; u8 pad3c[0x20]; f32 f5c, f60, pad64, f68, f6c; u8 pad70[0xE9]; u8 b159; u8 pad15a[0x82]; u8 *p1dc; u8 pad1e0[0x250]; f32 f430; } S5;
void func_0027F460(S5 *p) {
    extern void func_001E3210();
    extern void func_001757E0();
    extern void func_00280340();
    if (p->h1e != 0) {
        s16 v = p->h1e - 1;
        p->h1e = v;
        func_001E3210(p, 3);
        func_001E3210(p, 0x16);
        return;
    }
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    {
        s16 v = p->h1c - 1;
        p->h1c = v;
        if (v < 0) {
            u32 t = p->b7;
            p->b7 = t + 1;
            p->p1dc[0x13C] = 0;
            p->b159 = 0xFF;
            func_001757E0(p, 0x13, 5);
        }
    }
    if (p->f38 <= p->f430) {
        p->f38 = p->f430;
        func_00280340(p);
    }
}

typedef struct { u8 pad0[7]; u8 b7; u8 pad8[0x2C]; f32 f34, f38; u8 pad3c[0x20]; f32 f5c, f60, pad64, f68, f6c; u8 pad70[0xE1]; s8 b151, b152; u8 pad153[0x3E6]; s8 b539; u8 pad53a[0x2]; } S12;
extern u8 D_004F1F45, D_004F1F46;
void func_001F33C0(S12 *p) {
    extern void func_00175700();
    extern s32 func_0018AAC0();
    extern s32 func_001864A0();
    extern void func_001F72E0();
    extern void func_001757E0();
    s8 *b = (s8 *)((s32)p + 0x2B8);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    if (func_0018AAC0(p) != 0) {
        if (p->b539 != 0) {
            if (p->b151 != 0) {
                s32 v;
                p->b151 = 0;
                v = p->b152;
                if (v != 1) p->b152 = v - 1;
            }
        } else p->b152 = 1;
        b[2] = b[2] + 1;
        if (b[2] > 0xF) b[2] = 0xF;
    }
    if (func_001864A0(p) != 0) {
        u32 t = p->b7;
        p->b7 = t + 1;
        D_004F1F45 = 2;
        D_004F1F46 = 1;
        func_001F72E0(p);
        func_001757E0(p, 0xF, 0x2A);
    }
}
