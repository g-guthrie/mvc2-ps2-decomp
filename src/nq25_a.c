typedef unsigned char u8; typedef signed char s8; typedef short s16; typedef unsigned short u16; typedef int s32; typedef unsigned int u32;

typedef struct { u8 pad[0x1C]; s16 h1C; } SA;
extern u8 *D_004C2970;
extern void (*D_00463790[])(u8 *);

void func_003651B0(u8 *p) {
    extern s32 func_00174470(u8 *);
    extern void func_00365F50(u8 *);
    extern void func_0018D9A0(u8 *);
    extern void func_001E3210(u8 *, s32);
    SA *sa = (SA *)p;
    s16 v;
    if ((v = sa->h1C) == 0 || (v = v - 1, sa->h1C = v, v == 0)) {
        if (func_00174470(p) == 0) {
            p[4] = 3;
            *D_004C2970 = 0;
            func_00365F50(p);
            return;
        }
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[5] = 0;
        func_0018D9A0(p);
        func_001E3210(p, 0x2C);
    } else {
        D_00463790[p[5]](p);
    }
}
