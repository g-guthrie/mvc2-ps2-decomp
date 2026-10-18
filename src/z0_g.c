typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef struct { u8 pad0[0x7C]; s16 f7c[1]; } G7;
extern G7 *D_004C2794;

void func_0034E9C0(u8 *p)
{
    extern void func_0034E760();
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q = *(u8 **)(p + 0x18);
    f32 v;
    p[0x24] = 0;
    p[0x1B0] = 0x44;
    p[0x1B1] = 0x44;
    p[0x1B5] = 0x5D;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_0034E760(p);
    *(f32 *)(p + 0x38) = 377.142853f + *(f32 *)(q + 0x430);
    v = (*(s16 *)(p + 0x140) != 0) ? 14.166666f : -14.166666f;
    *(f32 *)(p + 0x5C) = v;
    *(s32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0xC122DB6D;
    *(u32 *)(p + 0x6C) = 0x3EAB6DB6;
    func_001757E0(p, 0x17, 0x23);
}
