#pragma padloop on
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001754A0(u8 *, s32, s32);
extern void func_001C0320(u8 *);

void residual_001C01E0(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    n = 0x31;
    d = (s32 *)(p + 0xEC);
    p[4]++;
    s = (s32 *)(*(u8 **)(p + 0x18) + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;
    } while (n > 0);
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
    *(s8 *)(p + 0x24) = 0;
    func_001754A0(p, 0x1B, 5);
    if (p[0x21] != 0)
        *(s16 *)(p + 0x140) ^= 1;
    *(f32 *)(p + 0x50) *= 0.8f;
    *(f32 *)(p + 0x54) *= 0.8f;
    func_001C0320(p);
}
