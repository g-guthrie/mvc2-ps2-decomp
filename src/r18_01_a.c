/* func_003BFDC0: parent-copy residual after dispatch head func_003BFD90.
 * MW 3.0 (011126): ./try30.sh src/r18_01_a.c "-O3 -Op -sdatathreshold 8".
 * The 0x34 store is written through a struct member (OS.x): with the plain
 * *(f32 *)(o + 0x34) store, MW 3.0 CSEs that address with the o + 0x34 call
 * argument and schedules the addiu a0 at the top of the float block. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { u8 pad[0x34]; f32 x, y, z; } OS;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
extern G3c *D_004C2794;

void func_003BFDC0(u8 *o, u8 *a) {
    extern u8 func_001748C0(u8 *, V3 *);
    extern void func_00174910(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003C0800(u8 *);
    extern void func_003C0560(u8 *, s32);
    u32 t;
    s32 v;
    s16 i;
    V3 tmp;
    u8 *q;
    t = o[4];
    o[4] = t + 1;
    *(B3c *)(o + 0xEC) = *(B3c *)(a + 0xEC);
    o[0x13C] = 1;
    o[2] = a[2];
    o[1] = a[1];
    *(f32 *)(o + 0x50) = *(f32 *)(a + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(a + 0x54);
    o[0x1B7] = a[0x1B7];
    o[0x1B8] = a[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(a + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(a + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(a + 0x24);
    *(s8 *)(o + 0x31) = -1;
    o[0x24] = 8;
    o[0x21] = 0;
    o[0x1B0] = 0x46;
    o[0x1B1] = 0;
    o[0x1B5] = 0x44;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = o[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    *(u16 *)(o + 0x1C0) |= 0x200;
    *(s32 *)(a + 0x2CC) = 4;
    v = 0x18;
    if (*(s16 *)(o + 0x140) != 0)
        v = -0x18;
    ((OS *)o)->x = *(f32 *)(a + 0x34) + 1.6666666269302368f * (f32)v;
    *(f32 *)(o + 0x38) = 342.85711669921875f + *(f32 *)(a + 0x38);
    *(s32 *)(o + 0x6C) = 0;
    *(s32 *)(o + 0x68) = 0;
    q = *(u8 **)(a + 0x220);
    tmp = *(V3 *)(q + 0x34);
    tmp.y += 2.142857074737549f * (f32)(q[0x14C] >> 1);
    o[0x22] = (func_001748C0(o + 0x34, &tmp) + 4) >> 3;
    func_00174910(o, 0x7D0);
    *(s16 *)(o + 0x1E) = 0x14;
    func_001757E0(o, 0x16, 0x18);
    *(s16 *)(o + 0x140) = 0;
    o[0x15D] = ((o[0x22] + 8) & 0x1F) >> 1;
    func_003C0800(o);
    for (i = 2; i < 8; i++)
        func_003C0560(o, i);
}

