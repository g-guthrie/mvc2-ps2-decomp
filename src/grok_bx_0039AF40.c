typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern u8 D_004D18A6;
extern void (*D_004726C0[])(u8 *);
extern void func_001757E0(u8 *, s32, s32);

void func_0039AF40(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    f32 add;
    if (p[5] > 0) {
        if (D_004D18A6 & (1 << (p[2] ^ 1)))
            return;
        if (D_004D18A6 & (1 << p[2]))
            return;
        if (q[0x404])
            return;
    }
    p[0x24] = 0;
    q = *(u8 **)(p + 0x18);
    if (q[5] || *(s8 *)(p + 0x1B3)) {
        p[4]++;
        add = 102.85713958740234375f;
        *(f32 *)(p + 0x38) += add;
        func_001757E0(p, 0x17, 4);
        return;
    }
    *(s8 *)(p + 0x1B4) = *(s8 *)(q + 0x1B4);
    if (*(s8 *)(p + 0x1B4)) {
        s8 t = *(s8 *)(p + 0x1B4) - 1;
        *(s8 *)(p + 0x1B4) = t;
        if (t < 0)
            *(s8 *)(p + 0x1B4) = 0;
        return;
    }
    D_004726C0[p[5]](p);
}
