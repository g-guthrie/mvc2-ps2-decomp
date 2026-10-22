typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0041CD30(u8 *p) {
    u8 *q;
    f32 c, k;
    if (p[4] != 0) {
        q = *(u8 **)(p + 0xD8);
        if (p[5] == 0) {
            c = 0.010000000707805157f;
            *(f32 *)(p + 0x50) += c;
            *(f32 *)(p + 0x54) += c;
            if (q != 0) {
                c = 0.013333333656191826f;
                *(f32 *)(q + 0x50) += c;
                *(f32 *)(q + 0x54) += c;
            }
            c = 1.2999999523162842f;
            if (!(*(f32 *)(p + 0x50) < c)) {
                *(f32 *)(p + 0x54) = c;
                *(f32 *)(p + 0x50) = c;
                if (q != 0) {
                    *(u32 *)(q + 0x54) = 0x3FB33333;
                    *(u32 *)(q + 0x50) = 0x3FB33333;
                }
                p[5] = 1;
            }
        } else {
            c = 0.010000000707805157f;
            *(f32 *)(p + 0x50) -= c;
            *(f32 *)(p + 0x54) -= c;
            if (q != 0) {
                c = 0.013333333656191826f;
                *(f32 *)(q + 0x50) -= c;
                *(f32 *)(q + 0x54) -= c;
            }
            c = 1.0099999904632568f;
            if (*(f32 *)(p + 0x50) <= c) {
                *(f32 *)(p + 0x54) = c;
                *(f32 *)(p + 0x50) = c;
                if (q != 0) {
                    *(f32 *)(q + 0x54) = c;
                    *(f32 *)(q + 0x50) = c;
                }
                p[5] = 0;
            }
        }
    }
}
