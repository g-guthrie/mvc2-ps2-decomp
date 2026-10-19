#pragma padloop on
/* Metrowerks 3.0: ./try.sh src/grok_ac_34c940.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001757E0(u8 *, s32, s32);
extern void func_0015E630(u8 *);
extern void func_0034CA70(u8 *);

void residual_0034C940(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    u8 *o;
    u32 t = p[4];
    p[4] = t + 1;
    n = 0x31;
    q = *(u8 **)(p + 0x14);
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;


    } while (n > 0);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x14))[2];
    p[1] = (*(u8 **)(p + 0x14))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x14) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x14) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x14))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x14))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x14) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x14) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x14) + 0x24);
    o = *(u8 **)(p + 0x18);
    p[2] = o[2];
    p[0x1B8] = o[0x1B8];
    p[0x1B0] = 0;
    p[0x1B1] = 0;
    func_001757E0(p, 23, 0);
    func_0015E630(p);
    p[6] = 255;
    func_0034CA70(p);
}
