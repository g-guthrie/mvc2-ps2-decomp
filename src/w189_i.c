typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w189_i.c "-O3,p -sdatathreshold 0" */
typedef struct T41C { u8 pad[0x1C]; s32 w1C; u8 pad20[0x170 - 0x20]; } T41C;
typedef struct A41C { s32 w0; u32 w4; s32 w8; s32 wC; } A41C;
extern T41C D_005BF2F0[];
extern s32 func_003DD030(s32);
s32 func_0041C010(A41C *a, u32 idx, f32 *src) {
    u8 *base;
    u16 *p2;
    u16 *p3;
    u16 off;
    u16 cnt;
    s32 i;
    s32 j;
    u32 fl;
    s32 n;
    u32 pos;
    f32 *d;
    n = a->w0 - 1;
    base = (u8 *)(u32)func_003DD030(((T41C *)((u8 *)D_005BF2F0 + n * 0x170))->w1C);
    p2 = (u16 *)(u32)func_003DD030(a->w8);
    off = p2[(u16)idx * 2];
    cnt = p2[(u16)idx * 2 + 1];
    p3 = (u16 *)(u32)func_003DD030(a->wC);
    fl = a->w4;
    j = off;
    for (i = 0; i < cnt; i++, j++) {
        pos = (u32)base + p3[j];
        if (fl & 1) {
            d = (f32 *)(pos | 0x20000000);
            d[0] = src[0];
            d[1] = src[1];
            d[2] = src[2];
            pos += 0x10;
        }
        if (fl & 2) pos += 0x10;
        if (fl & 4) {
            d = (f32 *)(pos | 0x20000000);
            d[0] = src[4];
            d[1] = src[5];
            d[2] = src[6];
            d[3] = src[7];
            pos += 0x10;
        }
        if (fl & 8) {
            d = (f32 *)(pos | 0x20000000);
            d[0] = src[8];
            d[1] = src[9];
        }
    }
    return 1;
}
