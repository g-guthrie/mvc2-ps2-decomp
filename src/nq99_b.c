typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
extern G3c *D_004C2794;

/* MWCC 3.0.3: ./try.sh src/nq99_b.c "-O3 -Op -sdatathreshold 8" */
#define PAR (*(u8 **)(a + 0x18))

void residual_003CDC90(u8 *o, u8 *a) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003CDDF0(u8 *, u8 *);
    u32 t;
    u32 z;
    t = o[4];
    o[4] = t + 1;
    *(B3c *)(o + 0xEC) = *(B3c *)(PAR + 0xEC);
    o[0x13C] = 1;
    o[2] = PAR[2];
    o[1] = PAR[1];
    *(f32 *)(o + 0x50) = *(f32 *)(PAR + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(PAR + 0x54);
    o[0x1B7] = PAR[0x1B7];
    o[0x1B8] = PAR[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(PAR + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(PAR + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(PAR + 0x24);
    *(s8 *)(o + 0x31) = -1;
    o[2] ^= 1;
    o[0x1B0] = 0x66;
    o[0x1B1] = 6;
    o[0x1B5] = 0x30;
    z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = o[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    func_001757E0(o, 0x17, 0x34);
    func_003CDDF0(o, a);
}
