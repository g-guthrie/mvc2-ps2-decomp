#pragma padloop on
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u32 D_0044D8A0[];
extern void func_001CA4D0(u8 *);

void func_001CA3C0(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    unsigned int t;
    s32 mode;
    s32 ff;
    t = p[4];
    d = (s32 *)(p + 0xEC);
    q = *(u8 **)(p + 0x18);
    n = 0x31;
    p[4] = t + 1;
    s = (s32 *)(q + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;
    } while (n > 0);
    p[0x13C] = 1;
    mode = 0xB;
    ff = 0xFF;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x24] = (u8)mode;
    *(u32 *)(p + 0xD0) = D_0044D8A0[p[0x20]];
    p[0x21] = (u8)ff;
    *(f32 *)(p + 0x38) = 205.7142791748047f + *(f32 *)(q + 0x34);
    {
        f32 off = -80.0f;
        if (*(s16 *)(q + 0x140) != 0)
            off = -off;
        *(f32 *)(p + 0x34) = off + *(f32 *)(q + 0x34);
    }
    func_001CA4D0(p);
}
