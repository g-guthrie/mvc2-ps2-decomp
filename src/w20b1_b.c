typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
extern f32 *D_004C26D0;
static void func_00192E30(u8 *p)
{
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s16 *)(p + 0x140))
        *(f32 *)(p + 0x34) += D_004C26D0[0];
    else
        *(f32 *)(p + 0x34) -= D_004C26D0[0];
    *(f32 *)(p + 0x38) += D_004C26D0[1];
}
#pragma padloop on
void func_00192EA0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q;
    s32 n;
    u32 *d;
    u32 *r;
    u32 t;
    f32 z;
    t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    d = (u32 *)(p + 0xEC);
    r = (u32 *)(q + 0xEC);
    n = 49;
    for (; n > 0; --n) {
        *d++ = *r++;
    }
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    p[0x30] = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    p[0x24] = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x13C] = 1;
    p[0x24] = (p[0x21] != 0) ? 0 : 0xB;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(s16 *)(p + 0x1C) = 0;
    if (p[0x20] != 0) z = -30.0f; else z = 0.0f;
    D_004C26D0[0] = z;
    if (p[0x20] != 0) z = 34.28571319580078f; else z = 0.0f;
    D_004C26D0[1] = z;
    func_00192E30(p);
    func_001757E0(p, 0x17, p[0x21] << 1);
}
