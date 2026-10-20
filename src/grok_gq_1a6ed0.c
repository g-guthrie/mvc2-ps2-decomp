typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001A6F90(u8 *, u8 *);

void residual_001A6ED0(u8 *p, u8 *q)
{
    s32 n;
    s32 *d;
    s32 *s;
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
    n = 0x31;
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
        s32 m = -8;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    {
        u32 t = p[4];
        p[4] = t + 1;
    }
    p[0x13C] = 0;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = (s8)m;
    }
    *(s16 *)(p + 0x140) = 0;
    func_001A6F90(p, q);
}
