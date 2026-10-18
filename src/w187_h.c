typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004BFAA0[2];
extern void (*D_004BFAB0[2])(u8 *, u8 *);
extern void func_00175580(u8 *, s32, u8, s8);

void func_001D9960(u8 *p, u8 *b) {
    s8 *r = (s8 *)(p + 0xD0);
    s8 *c = (s8 *)(b + 0x2B8);
    s8 n = p[0xD3];
    s32 k;
    u32 t;
    p[0xD3] = n - 1;
    if (n == 0) {
        r[2] = r[2] + 1;
        if (r[2] > 5) r[2] = 0;
        r[3] = D_004BFAA0[c[0xD]];
        if (p[0x21] == 0) p[0x168] = 7;
        else p[0x168] = 8;
        k = r[2];
        func_00175580(p, 0x1B, p[0x168], k);
    }
    if (p[0x21] == 0) p[0x24] = 0;
    else p[0x24] = 7;
    if (*(u16 *)(b + 0x168) != *(u16 *)r) {
        t = p[4];
        p[4] = t + 1;
    } else {
        D_004BFAB0[p[5]](p, b);
    }
}
