typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_0044DAD0[];

typedef struct { f32 x, y, z; } V3sa1l;
static void func_001CB680(u8 *p, u8 *o)
{
    s32 n;
    u32 *d, *s;
    p[4]++;
    s = (u32 *)(o + 236);
    d = (u32 *)(p + 236);
    for (n = 49; n > 0; n--) *d++ = *s++;
    p[316] = 1;
    p[2] = o[2];
    p[1] = o[1];
    *(f32 *)(p + 80) = *(f32 *)(o + 80);
    *(f32 *)(p + 84) = *(f32 *)(o + 84);
    p[439] = o[439];
    p[440] = o[440];
    *(s8 *)(p + 48) = *(s8 *)(o + 48);
    *(V3sa1l *)(p + 80) = *(V3sa1l *)(o + 80);
    *(s8 *)(p + 36) = *(s8 *)(o + 36);
}


void func_001CB9F0(u8 *p, u8 *q)
{
    extern void func_001754A0(u8 *, s32, s32);
    extern s32 func_00174170(void);
    extern void func_003DAA40(u8 *);
    extern s32 func_00175670(u8 *);
    u32 a, b;
    f32 f, g;
    s16 h;
    if (p[4] == 0) {
        func_001CB680(p, q);
        func_001754A0(p, 0x1B, 0x26);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x68) = 0;
        f = (f32)(u32)((func_00174170() & 0x7F) - 0x60);
        f = 1.6666666269302368f * f;
        h = *(s16 *)(q + 0x140);
        *(s16 *)(p + 0x140) = h;
        if (h != 0) f = -f;
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + f;
        g = (f32)(u32)((func_00174170() & 0x3F) + 0x50);
        g = 2.142857074737549f * g;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430) + g;
        *(f32 *)(p + 0x60) = D_0044DAD0[func_00174170() & 3];
        *(u32 *)(p + 0x6C) = 0xBE092492;
        *(s8 *)(p + 0x31) = -1;
    }
    if (q[5] == 3) {
        func_003DAA40(p);
        return;
    }
    if ((s8)func_00175670(p) < 0) {
        func_003DAA40(p);
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
}
