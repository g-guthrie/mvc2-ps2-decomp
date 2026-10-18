typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#pragma padloop on
void func_003DD1D0(u8 *p, s32 w, s32 h) {
    s32 x, y;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            u8 v = p[3];
            if (v == 0xFF) {
                v = 0x80;
            } else if (v != 0) {
                v >>= 1;
                if (v == 0) {
                    v = 1;
                }
            }
            p[3] = v;
            p += 4;
        }
    }
}
