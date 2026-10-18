typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;

s32 func_0012BB80(void) {
    s32 n = 0;
    s32 i = 0;
    u32 *w = (u32 *)(D_004C2840 + 0x30);
    do {
        if (i == 0x20) {
            w++;
        }
        if (i < 0x18 || i > 0x1A) {
            if (w[0] & (1 << (i & 0x1F))) {
                n++;
            }
        }
        i++;
    } while (i <= 0x3A);
    return n;
}
