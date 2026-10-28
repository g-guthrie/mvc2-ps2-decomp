/* MW 3.0: ./try30.sh src/gr30_d.c "-O3,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 h7C[1]; } G94;
extern G94 *D_004C2794;

typedef struct { f32 x, y, z; } V3;

void residual_00382010(u8 *p) {
    extern void func_00382120(u8 *);
    s32 n;
    u32 *d;
    u32 *s;
    u32 t = p[4];
    p[4] = t + 1;
    d = (u32 *)(p + 0xEC);
    s = (u32 *)(*(u8 **)(p + 0x18) + 0xEC);
    n = 0x31;
    do {
        *d++ = *s++;
        n--;
    } while (n > 0);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x1B5] = 0x38;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 x = p[2]; s16 y = D_004C2794->h7C[x]; D_004C2794->h7C[x] = y + 1; }
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x24] = 0;
    p[0x22] = 0xFF;
    func_00382120(p);
}
