typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_003CAA20(void);
extern void func_003CAB20(u8 *, u8 *, s32);

u8 *func_003CA7E0(u8 *p, s32 n)
{
    u8 *o;
    s32 i;
    s32 *src;
    s32 *dst;
    o = func_003DA750(0, 1, 1);
    if (o == 0)
        return o;
    *(void **)(o + 0x10) = func_003CAA20;
    *(u8 **)(o + 0x18) = p;
    o[1] = p[1];
    *(s16 *)(o + 0x26) = 0x3A01;
    o[0x20] = n;
    src = (s32 *)(p + 0xEC);
    dst = (s32 *)(o + 0xEC);
    for (i = 0x31; i > 0; i--)
        *dst++ = *src++;
    o[0x13C] = 1;
    o[2] = p[2];
    o[1] = p[1];
    *(f32 *)(o + 0x50) = *(f32 *)(p + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(p + 0x54);
    o[0x1B7] = p[0x1B7];
    o[0x1B8] = p[0x1B8];
    o[0x30] = p[0x30];
    *(f32 *)(o + 0x50) = *(f32 *)(p + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(p + 0x54);
    *(f32 *)(o + 0x58) = *(f32 *)(p + 0x58);
    o[0x24] = p[0x24];
    o[0x24] = 8;
    func_003CAB20(o, p, 1);
    return o;
}
