typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u16 D_004D18DC[];
extern u8 D_004D18DB[];
extern void (*D_004C1F00[2])(u8 *, u8 *);

void func_003A7D10(u8 *p, u8 *q)
{
    extern void func_003A8290(u8 *, u8 *, s32);
    s32 c;
    u32 t;
    f32 k;
    c = q[0x169];
    if (c != 0x16) {
        t = p[4];
        p[4] = t + 1;
        func_003A8290(p, q, c);
        return;
    }
    if (q[5] != 0) {
        t = p[4];
        p[4] = t + 1;
        func_003A8290(p, q, c);
        return;
    }
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    if (*(s16 *)(p + 0x140) == 0) {
        k = -178.3333282470703f;
        *(f32 *)(p + 0x34) += k;
    } else {
        k = 178.3333282470703f;
        *(f32 *)(p + 0x34) += k;
    }
    *(f32 *)(p + 0x38) += 203.57142639160156f;
    if ((D_004D18DC[0] & (1 << D_004D18DB[0])) == 0)
        D_004C1F00[p[5]](p, q);
}
