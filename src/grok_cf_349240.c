typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001757E0(u8 *, s32, s32);
extern void func_0034A080(u8 *, u8 *);

void func_00349240(u8 *p, u8 *q)
{
    unsigned int offset;
    *(u32 *)(p + 0x14C) = 0x30305040;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0;
    p[0x1B5] = 0x47;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(s16 *)(offset + 0x7C);
    *(u32 *)(p + 0x5C) = 0x42A6AAAA;
    *(u32 *)(p + 0x60) = 0;
    if (*(s16 *)(p + 0x140) == 0)
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    *(u16 *)(p + 0x88) = *(u16 *)(q + 0x168);
    p[0x169] = 0x16;
    p[0x168] = 0x23;
    func_001757E0(p, p[0x169], p[0x168]);
    p[0x150] = 0;
    *(s8 *)(p + 0x31) = -6;
    func_0034A080(p, q);
}
