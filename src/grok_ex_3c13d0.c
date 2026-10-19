typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern int func_001757E0(u8 *, s32, s32);
extern void func_003C12D0(u8 *, u32, u32);
extern void func_003C1630(u8 *, u8 *);

void func_003C13D0(u8 *p, u8 *q)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *t1;
    u32 t = p[4];
    n = 0x31;
    t1 = p + 0xD0;
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
    p[4] = t + 1;
    do {
        *d = *s;
        n--;
        s++;
        d++;
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
    p[0x13C] = 1;
    p[0x31] = 2;
    t1[4] = 0;
    *(s16 *)t1 = 0;
    *(u32 *)(q + 0x5C) = 0;
    *(u32 *)(q + 0x60) = 0;
    *(u32 *)(q + 0x68) = 0;
    *(u32 *)(q + 0x6C) = 0;
    *(f32 *)(p + 0x5C) = 6.666666507720947265625f;
    *(f32 *)(p + 0x38) = 68.5714263916015625f + *(f32 *)(q + 0x430);
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    func_001757E0(p, 0x16, 2);
    func_003C12D0(p, 1, 0);
    func_003C12D0(p, 1, 1);
    func_003C12D0(p, 1, 2);
    func_003C1630(p, q);
}
