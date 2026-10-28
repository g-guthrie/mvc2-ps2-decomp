typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 w[0x31]; } ActorState;
typedef struct { f32 x, y, z; } V3;
typedef void (*Fn39B)(u8 *);
extern Fn39B jtbl_004726F0[];
extern u16 *D_004C2A08;

void residual_0039B880(u8 *p)
{
    u32 t = p[4];
    p[4] = t + 1;
    *(ActorState *)(p + 0xEC) = *(ActorState *)(*(u8 **)(p + 0x18) + 0xEC);
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
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    jtbl_004726F0[p[0x20]](p);
}

void func_0039B980(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    f32 v;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    *D_004C2A08 = *(u16 *)(*(u8 **)(p + 0x18) + 0x168);
    p[0x24] = 0;
    if ((*(u8 **)(p + 0x18))[0x1E6]) v = 120.0f; else v = -120.0f;
    *(f32 *)(p + 0x34) += v;
    func_001757E0(p, 0x17, 5);
}
