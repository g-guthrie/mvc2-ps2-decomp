typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001754A0(u8 *, s32, s32);
extern void func_001E3710(u8 *, s32);
extern void func_001D6FD0(u8 *, u8 *);

void residual_001D6E90(u8 *p, u8 *q)
{
    s32 n;
    s32 *d;
    s32 *s;
    s32 k;
    u32 t = p[4];
    p[4] = t + 1;
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
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x24) = 0;
    k = 0xE;
    if (*(s16 *)(p + 0x140) != 0)
        k = -0xE;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + 1.6666666269302368f * (f32)k;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + 330.0f;
    func_001754A0(p, 0x1B, 4);
    func_001E3710(p, 0x4B);
    func_001D6FD0(p, q);
}
