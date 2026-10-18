typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

typedef struct { u8 b0, b1, b2, b3, b4, b5, b6, b7; s16 h8, hA, hC, hE; u8 pad10[4]; s32 w14; s8 b18; u8 pad19[0x83]; s8 f9c; } G840;
extern G840 *D_004C2840;
typedef struct { u8 pad[0x5B8]; } E20;
extern E20 D_004F20B0[];

void func_003D8A30(u8 *p) {
    extern s32 func_0016D130();
    extern s32 func_003D9000(void *);
    extern void func_003D8B70();
    extern void func_00171210();
    s32 i;
    s16 t;
    if (p[6] != 0) return;
    if (p[0x84] != 0) {
        u32 m = p[0x85];
        u8 n = m - 1;
        p[0x85] = n;
        if (n > 0) return;
        p[0x84] = 0;
    }
    if (func_0016D130() != 0) return;
    switch (D_004C2840->f9c) { case 0: break; default: return; }
    t = *(s16 *)(p + 0x12) - 1;
    *(s16 *)(p + 0x12) = t;
    if (t > 0) {
        t = *(s16 *)(p + 0x14);
        if (t != 0) {
            t -= 1;
            *(s16 *)(p + 0x14) = t;
            if (t > 0) return;
        }
        *(s16 *)(p + 0x3C) = 0;
        for (i = 0; i < 6; i++) {
            if (func_003D9000(&D_004F20B0[i]) != 0) return;
        }
    }
    *(s16 *)(p + 0x3C) = 0;
    func_003D8B70();
    func_00171210();
    if (*(s8 *)(p + 0x3E) > 0 || p[3] != 0) p[1] = 10;
    p[0] = 6;
    *(s16 *)(p + 0x12) = 0x82;
}
