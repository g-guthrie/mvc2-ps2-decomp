/* MW 3.0: ./try30.sh src/gr32_a.c "-O3,p -Op -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x[0x31]; } S31a;
typedef struct { f32 x, y, z; } V3a;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } Ga;

extern Ga *D_004C2794;

void residual_003829A0(u8 *p)
{
    extern void func_00382AC0(u8 *);
    p[4]++;
    *(S31a *)(p + 0xEC) = *(S31a *)(*(u8 **)(p + 0x14) + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x14))[2];
    p[1] = (*(u8 **)(p + 0x14))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x14) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x14) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x14))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x14))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x14) + 0x30);
    *(V3a *)(p + 0x50) = *(V3a *)(*(u8 **)(p + 0x14) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x14) + 0x24);
    p[0x1B5] = 0x31;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 x = p[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    p[0x21] = 0xFF;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    *(s8 *)(p + 0x31) = *(s8 *)(*(u8 **)(p + 8) + 0x31);
    func_00382AC0(p);
}
