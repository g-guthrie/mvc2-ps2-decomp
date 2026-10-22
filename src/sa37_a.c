typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct SA37_D1 {
    u8 pad0[0x13C];
    s8 b13c;
} SA37_D1;

typedef struct SA37_D0 {
    u8 pad0[4];
    u8 b4;
    u8 pad5[0x1E - 5];
    s16 h1e;
    u8 pad20[0x74 - 0x20];
    f32 f74;
    u8 pad78[0xDC - 0x78];
    s32 wDC;
    u8 pade0[0x13C - 0xE0];
    s8 b13c;
} SA37_D0;

void func_00161160(u8 *actor_data) {
    SA37_D0 *p = (SA37_D0 *)actor_data;
    extern void func_00152550(void *, void (*)(u8 *));
    s32 w;
    p->b13c = (*(SA37_D1 **)((u8 *)p + 0x18))->b13c;
    if (p->wDC < 0x15) {
        p->f74 += 0.05000000074505806f;
    } else if (p->wDC >= 0x28) {
        p->f74 -= 0.05000000074505806f;
    } else {
        p->f74 = 1.0f;
    }
    p->h1e = p->h1e + 1;
    if (p->h1e >= 0x50) p->h1e = 0;
    w = p->wDC + 1;
    p->wDC = w;
    if (w >= 0x3D || p->b13c == 0) {
        u32 t = p->b4;
        p->b4 = t + 1;
        func_00152550(p, 0);
    }
}
