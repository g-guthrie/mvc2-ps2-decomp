typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern f32 D_004BF698[] __attribute__((section(".sdata")));
extern void func_001757E0(u8 *, s32, s32);

void residual_001A4014(u8 *p, u8 *q)
{
    s32 n;
    s32 *d;
    s32 *s;
    f32 v;

    asm { nop }
    asm { nop }
    asm { nop }
    p[4]++;
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
    *(s8 *)(p + 0x24) = 0xC;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    if (p[0x20] == 0) {
        v = D_004BF698[q[0x1B7]];
        if (*(s16 *)(p + 0x140) != 0)
            v = -v;
        *(f32 *)(p + 0x5C) = v;
        *(f32 *)(p + 0x68) = v;
        *(s16 *)(p + 0x1C) = 8;
    } else {
        p[5] = 3;
    }
    func_001757E0(p, 0x17, 0x13);
}
