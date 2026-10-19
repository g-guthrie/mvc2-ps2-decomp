#pragma padloop on
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern f32 D_0044DCA0[];
extern f32 D_0044DCA4[];
extern void func_001754A0(u8 *, s32, s32);

void residual_001CC730(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    unsigned int t;
    s8 face10;
    s8 m2;
    t = p[4];
    d = (s32 *)(p + 0xEC);
    n = 0x31;
    p[4] = t + 1;
    s = (s32 *)(*(u8 **)(p + 0x18) + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;
    } while (n > 0);
    face10 = 0xA;
    m2 = (s8)-2;
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
    p[0x24] = face10;
    *(s8 *)(p + 0x31) = m2;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34) + *(f32 *)((u8 *)D_0044DCA0 + (p[0x21] << 3));
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38) + *(f32 *)((u8 *)D_0044DCA4 + (p[0x21] << 3));
    func_001754A0(p, 0x1B, 7);
}
