#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern s32 func_00174170(void);
extern void func_001754A0(u8 *, s32, s32);

void func_001E1060(u8 *p, u8 *q)
{
    s32 n;
    s32 *d;
    s32 *s;
    u32 t;
    s32 r;
    f32 f;
    s = (s32 *)(q + 0xEC);
    t = p[4];
    n = 0x31;
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
    p[0x24] = 0xF;
    r = (s16)((u8)func_00174170() - 0x80);
    f = ((f32)r * (5.0f / 3.0f)) / 256.0f;
    *(f32 *)(p + 0x5C) = f;
    *(s32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x40092492;
    *(u32 *)(p + 0x6C) = 0xBD892492;
    func_001754A0(p, 0x1B, 0xE);
}
