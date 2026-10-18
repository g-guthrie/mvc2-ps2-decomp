typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_00370C30(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (q[0x1E4] != 0x1D || q[0x1FD] != 5) {
        f32 v;
        p[5] = 5;
        if (*(s16 *)(p + 0x140) != 0) {
            v = -15.83333301544189f;
        } else {
            v = 15.83333301544189f;
        }
        *(f32 *)(p + 0x5C) = v;
        if (*(s16 *)(p + 0x140) != 0) {
            v = -0.3125f;
        } else {
            v = 0.3125f;
        }
        *(f32 *)(p + 0x68) = v;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(s16 *)(p + 0x1C) = 0x3C;
        q[0x2C6] = 0;
    } else {
        s16 h = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = h - 1;
        if (h == 0) {
            u32 t = p[5];
            p[5] = t + 1;
            *(s16 *)(p + 0x1C) = 0x18;
        } else {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        }
    }
}
