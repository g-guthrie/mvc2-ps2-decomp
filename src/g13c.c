typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
void func_0027BF80(u8 *p) {
    float f, g;
    u32 t;
    p[0x209] = 1;
    g = *(float *)(p + 0x118);
    f = g - 0.025f;
    *(float *)(p + 0x118) = f;
    if (f <= 0.0f) {
        t = p[6];
        p[6] = t + 1;
        p[0x13C] = 0;
        *(u32 *)(p + 0x118) = 0x3F800000;
        *(s16 *)(p + 0x1C) = 0x14;
    }
}
float func_0016ABA0(u8 *p, s16 *q, s32 mode) {
    float v;
    if (mode == 0) {
        v = 1.6666666f * (float)q[0];
        if (*(s16 *)(p + 0x140) & 1) v = -v;
        v += *(float *)(p + 0x34);
    } else {
        v = 2.1428571f * (float)(-q[2]);
        if (*(s16 *)(p + 0x140) & 2) v = -v;
        v += *(float *)(p + 0x38);
    }
    return v;
}
