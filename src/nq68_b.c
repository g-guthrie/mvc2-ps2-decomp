typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

void residual_00367CF0(u8 *p)
{
    extern void func_001754A0(u8 *, s32, s32, s32);
    extern void func_00367E10(u8 *);
    s32 i;
    s32 *s;
    s32 *d;
    p[4]++;
    i = 0x31;
    d = (s32 *)(p + 0xEC);
    s = (s32 *)(*(u8 **)(p + 0x18) + 0xEC);
    do {
        i--;
        *d++ = *s++;
    } while (i > 0);
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
    p[0x24] = 0xC;
    p[0x31] = (*(s8 **)(p + 0x14))[0x31] + (p[0x21] != 0 ? 1 : -1);
    func_001754A0(p, 0x1B, 0x18, -1);
    func_00367E10(p);
}
