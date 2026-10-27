typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

u8 *func_001FB4E0(u8 *p) {
    extern u8 *func_001E7FD0(u8 *);
    u8 t;
    u8 a;
    u8 *r;
    t = (*(u16 *)(p + 0x20E) & 0x1C00) >> 10;
    p[0x22] = t;
    if (t == 0) goto done;
    a = p[0x212];
    if (a == 0) {
        if (p[0x1B7] == 1) {
            if (*(f32 *)(p + 0x38) > 137.14285278320312f) {
                if ((r = func_001E7FD0(p)) != 0) {
                    p[0x20B] = 2;
                    return r;
                }
                goto done;
            }
        }
    }
    if (a == 1) {
        if (p[0x1B7] == 1) {
            if (*(f32 *)(p + 0x38) > 137.14285278320312f) {
                if ((r = func_001E7FD0(p)) != 0) {
                    p[0x20B] = 3;
                    return r;
                }
            }
        }
    }
done:
    return 0;
}
