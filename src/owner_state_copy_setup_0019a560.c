#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;
typedef signed int s32;
typedef struct { f32 x,y,z; } V3;
extern u32 D_0044A7B0[];
extern void func_0019A940(u8 *);
void func_0019A560(u8 *p)
{
    s32 i = 49;
    u8 *q;
    u32 *dst;
    u32 *src;
    dst = (u32 *)(p + 0xEC);
    p[4]++;
    q = *(u8 **)(p + 0x18);
    src = (u32 *)(q + 0xEC);
    do {
        *dst++ = *src++;
        i--;
    } while (i > 0);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    p[0x30] = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    ((void (*)(u8 *))D_0044A7B0[p[0x20]])(p);
    func_0019A940(p);
}
