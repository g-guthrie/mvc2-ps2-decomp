typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } W31;
typedef struct { u8 pad[0x7c]; s16 count[2]; } GameStateC;
extern GameStateC *D_004C2794;
extern u8 *D_004C2840;
typedef struct { u8 pad[0x5C]; f32 f5C; u8 pad60[8]; f32 f68; } PN;

void residual_00382F50(u8 *p)
{
    extern void func_00175910(u8 *, s32, s32, s32);
    extern void func_003831F0(u8 *);
    extern void func_001E3210(u8 *, s32);
    u8 *q;
    f32 k;
    u32 t;
    PN *sa;
    t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    *(W31 *)(p + 0xEC) = *(W31 *)(*(u8 **)(p + 0x8) + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x8))[2];
    p[1] = (*(u8 **)(p + 0x8))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x8) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x8) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x8))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x8))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x8) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x8) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x8) + 0x24);
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = 0x36;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 x = p[2]; s16 y = D_004C2794->count[x]; D_004C2794->count[x] = y + 1; }
    *(u32 *)(p + 0x14C) = 0x302828F0;
    *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x8) + 0x34);
    k = 373.3333129882812f * *(f32 *)(p + 0x50);
    if (*(s16 *)(p + 0x140) == 0) k = -k;
    *(f32 *)(p + 0x34) += k;
    *(s8 *)(p + 0x24) = 0;
    *(f32 *)(p + 0x60) = 0.0f;
    *(f32 *)(p + 0x6C) = 0.0f;
    *(f32 *)(p + 0x5C) = -20.0f;
    *(f32 *)(p + 0x68) = -0.4166666567325592f;
    if (*(s16 *)(p + 0x140) != 0) {
        sa = (PN *)p;
        sa->f5C = -sa->f5C;
        sa->f68 = -sa->f68;
    }
    if (q[0x1FD] == 0) {
        switch (*(u32 *)(D_004C2840 + 0x1C) & 3) {
        case 0:
            *(f32 *)(p + 0x60) = 2.142857074737549f;
            break;
        case 1:
            *(f32 *)(p + 0x60) = -2.142857074737549f;
            break;
        }
    }
    *(f32 *)(p + 0x64) = (1.2000000476837158f * *(f32 *)(q + 0x50) - *(f32 *)(p + 0x50)) / 30.0f;
    *(f32 *)(p + 0x70) = (1.2000000476837158f * *(f32 *)(q + 0x54) - *(f32 *)(p + 0x54)) / 30.0f;
    *(s16 *)(p + 0x1C) = 5;
    *(s16 *)(p + 0x1E) = 0x78;
    *(f32 *)(p + 0xD0) = *(f32 *)(p + 0x34);
    p[0x22] = 1;
    p[0x13C] = 1;
    func_00175910(p, 0x17, 0xB, 0);
    func_003831F0(p);
    func_001E3210(p, 0x1B);
}
