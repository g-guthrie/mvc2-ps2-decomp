typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern u8 *func_001E7FD0(u8 *);
u8 *func_002149D0(u8 *p) {
    u8 t = (*(u16 *)(p + 0x20E) & 0xC00) >> 10;
    p[0x22] = t;
    if (t != 0 && p[0x212] == 0 && p[0x1B7] == 1) {
        f32 lim = 137.1428528f + *(f32 *)(p + 0x430);
        if (!(*(f32 *)(p + 0x38) <= lim)) {
            u8 *r = func_001E7FD0(p);
            if (r != 0) {
                p[0x20B] = 0x84;
                return r;
            }
        }
    }
    return 0;
}
