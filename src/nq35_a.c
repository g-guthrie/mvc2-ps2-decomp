typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u16 D_004D18DC[];
extern u8 D_004D18DB[];

void func_001A49A0(u8 *p, s32 a1, u8 *q)
{
    extern s32 func_00174470(u8 *);
    u8 *o;
    if ((D_004D18DC[0] & (1 << D_004D18DB[0])) != 0)
        return;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34) + *(f32 *)(p + 0x5C);
    if (*(s8 *)(q + 4) == 0 && p[0x21] != 0) {
        if (func_00174470(p) == 0) {
        p[4] = 2;
        p[0x13C] = 0;
        o = *(u8 **)(p + 0xC);
        o[0x21] = 1;
        *(s32 *)(o + 0x14) = a1;
        }
        return;
    }
    { u32 t = p[5]; p[5] = t + 1; }
    *(u32 *)(p + 0x68) = 0x41D55555;
    if (*(s16 *)(p + 0x140) != 0)
        *(f32 *)((s32)p + 0x68) = -*(f32 *)((s32)p + 0x68);
}
