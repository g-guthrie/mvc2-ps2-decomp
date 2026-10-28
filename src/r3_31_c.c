typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x1C]; s32 h; u8 pad2[0x150]; } T;
typedef struct { s32 n; u32 flags; s32 h2; s32 h3; } P;
extern T D_005BF2F0[];

s32 func_0041BD90(P *p, u16 idx, f32 *dst) {
    f32 *src;
    u8 *a;
    u8 *b;
    u8 *c;
    u32 fl;
    extern s32 func_003DD030(s32);
    T *t;
    s32 i;
    i = p->n - 1;
    t = D_005BF2F0 + i;
    src = (f32 *)(u32)func_003DD030(t->h);
    a = (u8 *)(u32)func_003DD030(p->h2);
    idx = *(u16 *)(a + idx * 4);
    b = (u8 *)(u32)func_003DD030(p->h3);
    src = (f32 *)((u8 *)src + *(u16 *)(b + idx * 2));
    fl = p->flags;
    if (fl & 1) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        src += 4;
    }
    if (fl & 2) {
        src += 4;
    }
    if (fl & 4) {
        dst[4] = src[0];
        dst[5] = src[1];
        dst[6] = src[2];
        dst[7] = src[3];
        src += 4;
    }
    if (fl & 8) {
        dst[8] = src[0];
        dst[9] = src[1];
    }
    return 1;
}
