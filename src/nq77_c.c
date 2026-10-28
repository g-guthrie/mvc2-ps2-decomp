typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void residual_003714A0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    u8 a;
    f32 k;

    if (q[0x1E4] != 0x1D || q[0x1FD] != 5) {
        p[5] = 2;
        return;
    }
    a = (*(u8 **)(p + 0x14))[5];
    if (a >= 5) {
        p[5] = 2;
        return;
    }
    if (a == 4) {
        p[5]++;
    }
    *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x14) + 0x140);
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x14) + 0x3C);
    if (p[0x23] != 0) {
        k = 112.0f;
        *(f32 *)(p + 0x34) += *(s16 *)(p + 0x140) ? k : -k;
    } else {
        k = -18.66666603088379f;
        *(f32 *)(p + 0x34) += *(s16 *)(p + 0x140) ? k : -k;
    }
    *(f32 *)(p + 0x38) -= 96.0f;
}
