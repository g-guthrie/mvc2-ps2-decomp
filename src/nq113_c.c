typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* MW 3.0.3: ./try.sh src/nq113_c.c "-O3 -Op -sdatathreshold 8" */

typedef struct { u8 pad[0x7C]; s16 h7c[1]; } G_nq113c;
extern G_nq113c *D_004C2794;
extern u16 D_004C0C68[][2] __attribute__((section(".sdata")));
extern u8 D_004C0C9C[][2] __attribute__((section(".sdata")));

void residual_002AF940(u8 *p) {
    extern void func_0018C4B0(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_001757E0(u8 *, s32, u8);
    u8 *b5, *c0, *b2, *d8, *q2;
    u32 t;
    q2 = p + 2;
    d8 = p + 0x1D8;
    b2 = p + 0x1B2;
    c0 = p + 0x1C0;
    b5 = p + 0x1B5;
    t = p[6];
    p[6] = t + 1;
    *b5 = *(s8 *)(p + 0x1B7) + 0x44;
    *b2 = *(u16 *)c0 = 0;
    *(u32 *)d8 = 0;
    { u32 a = *q2 * 2; a += (u32)D_004C2794; a += 0x7C; ++*(s16 *)a; }
    func_0018C4B0(p, 4);
    func_00185490(p);
    func_00175C00(p, 0);
    *(f32 *)(p + 0x5C) /= 8.0f;
    *(f32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) /= 8.0f;
    *(f32 *)(p + 0x6C) /= 64.0f;
    *(u16 *)(p + 0x1C) = D_004C0C68[*(s32 *)(p + 0xD0)][p[0x1B7]];
    *b5 = D_004C0C9C[*(s32 *)(p + 0xD0)][p[0x1B7]];
    *b2 = *(u16 *)c0 = 0;
    *(u32 *)d8 = 0;
    D_004C2794->h7c[*q2]++;
    func_001757E0(p, 0x15, p[0x1B7] + 0x15);
}
