typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001757E0(u8 *, s32, s32);
extern void func_003C3DE0(u8 *, u8 *);

void func_003C3B80(u8 *p, u8 *q)
{
    s32 n;
    s32 *d;
    s32 *s;
    u32 t = p[4];
    n = 0x31;
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
    p[4] = t + 1;
    do {
        *d = *s;
        n--;
        s++;
        d++;
        asm { nop }
        asm { nop }
    } while (n > 0);
    p[0x13C] = 1;
    {
        u16 ff = 0xFFFF;
        p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x13C] = 1;
    p[0x31] = 2;
    *(s16 *)(p + 0xD0) = 0;
    *(s16 *)(p + 0x1C) = 0;
    p[0x1B5] = 0x37;
    *(s16 *)(p + 0x1C0) = 0;
        p[0x1B2] = (u8)ff;
    }
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    *(u32 *)(q + 0x5C) = 0;
    *(u32 *)(q + 0x60) = 0;
    *(u32 *)(q + 0x68) = 0;
    *(u32 *)(q + 0x6C) = 0;
    *(u32 *)(p + 0x5C) = 0x41A00000;
    func_001757E0(p, 0x16, 0xA);
    func_003C3DE0(p, q);
}
