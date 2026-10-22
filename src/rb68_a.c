typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x4C]; s8 b4C; u8 pad1[3]; s8 b50; u8 pad2[8]; s8 b59; } G40A0;
typedef struct { u16 h[10]; } E40A0;
typedef struct { u8 a; u8 b; u8 pad; u8 c; u8 *w; } T40A0;
extern G40A0 *D_004C2840;
extern E40A0 D_004F4484[];
extern E40A0 D_004F4490[];
extern T40A0 D_004B91F0[];

void func_003D40A0(u8 *p, s32 i) {
    extern void func_003D7350(u8, u8, s32, u8 *);
    extern void func_001E3CE0(s32);
    extern s32 func_001315E0(s8);
    extern s32 func_00131750(s8);
    extern void func_0012FA40(s32);
    volatile T40A0 *t;
    s32 n;
    s32 o;
    E40A0 *q;
    E40A0 *r;
    s32 v;
    n = 0;
    t = D_004B91F0;
    do {
        func_003D7350(t->a, t->b, t->c, t->w);
        n++;
        t++;
    } while (n < 3);
    o = *(s8 *)(p + 0xE);
    q = &D_004F4484[i];
    r = &D_004F4490[i];
    if (((q->h[0] | r->h[0]) & 0x2000) != 0) p[0xE] = o - 1;
    if (((q->h[0] | r->h[0]) & 0x1000) != 0) {
        s8 u = p[0xE];
        p[0xE] = u + 1;
    }
    v = *(s8 *)(p + 0xE) + 2;
    p[0xE] = v % 2;
    p[0xF] = *(s8 *)(p + 0xE) + 5;
    if ((s8)o != *(s8 *)(p + 0xE)) func_001E3CE0(1);
    v = func_001315E0(i);
    if (((v & 0xFFFF) & q->h[0]) != 0) {
        if (*(s8 *)(p + 0xE) == 0) {
            D_004C2840->b50 = 1;
            func_0012FA40(0);
            D_004C2840->b59 = D_004C2840->b4C;
        } else {
            p[0xD] = 0;
            p[0xE] = 3;
            if (D_004C2840->b4C == 2) {
                p[0xD] = 2;
                p[0xE] = 4;
            }
        }
        func_001E3CE0(2);
    }
    if (func_00131750(i) != 0) {
        p[0xD] = 0;
        p[0xE] = 3;
        if (D_004C2840->b4C == 2) {
            p[0xD] = 2;
            p[0xE] = 4;
        }
    }
}
