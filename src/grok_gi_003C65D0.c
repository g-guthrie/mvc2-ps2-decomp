typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001757E0(u8 *, s32, s32);

void residual_003C65D0(u8 *p, u8 *q)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *o;
    f32 vx, vy, addy;
    u32 t = p[4];
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
    n = 0x31;
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
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    o = *(u8 **)(p + 0x14);
    *(f32 *)(p + 0x38) = -53.5714263916015625f + *(f32 *)(o + 0x38);
    addy = 76.66666412353515625f;
    vx = 6.666666507720947265625f;
    vy = -0.4166666567325592041015625f;
    if (*(s16 *)(p + 0x140) != 0) {
        vx = -vx;
        vy = -vy;
        addy = -addy;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34) + addy;
    *(f32 *)(p + 0x5C) = vx;
    *(f32 *)(p + 0x68) = vy;
    *(f32 *)(p + 0x60) = 4.28571414947509765625f;
    *(f32 *)(p + 0x6C) = -0.53571426868438720703125f;
    *(s16 *)(p + 0x1C) = 0x28;
    func_001757E0(p, 0x15, 0x13);
}
