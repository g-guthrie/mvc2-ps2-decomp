typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 * const D_00478B50[4];

void func_003EB810(u8 *src, u8 *dst, s32 stride) {
    s32 j, k, i;
    s32 * const *tp = D_00478B50;
    for (k = 0; k < 4; k++) {
        s32 *t = *tp++;
        for (j = 0; j < 2; j++) {
            for (i = 0; i < 32; i += 8) {
                dst[0] = src[t[0]];
                dst[1] = src[t[1]];
                dst[2] = src[t[2]];
                dst[3] = src[t[3]];
                dst[4] = src[t[4]];
                dst[5] = src[t[5]];
                dst[6] = src[t[6]];
                dst[7] = src[t[7]];
                t += 8;
                dst += 8;
            }
            dst += (stride << 8) - 32;
        }
        src += 0x200;
    }
}
