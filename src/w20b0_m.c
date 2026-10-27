typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

u8 *func_001F6160(u8 *a) {
    extern u8 *func_001E7FD0(u8 *);
    u8 *r;
    u16 *s0;
    s0 = (u16 *)(a + 0x2B8);
    switch (a[0x20D]) {
    case 2:
        if ((*(u16 *)(a + 0x20E) & 0x1C00) == 0) return 0;
        if (a[0x212] != 0) return 0;
        if (a[0x1B7] == 0) return 0;
        r = func_001E7FD0(a);
        if (r != 0) {
            a[0x20B] = 8;
            *s0 = *(u16 *)(a + 0x20E);
            return r;
        }
    case 1:
        if ((*(u16 *)(a + 0x20E) & 0x800) == 0) return 0;
        if (a[0x212] == 0) return 0;
        if (a[0x1B7] == 0) return 0;
        r = func_001E7FD0(a);
        if (r != 0) {
            a[0x20B] = 2;
            *s0 = *(u16 *)(a + 0x20E);
            return r;
        }
    default:
        if ((*(u16 *)(a + 0x20E) & 0xC00) == 0) return 0;
        if (a[0x1B7] == 0) return 0;
        if (a[0x212] == 0) {
            r = func_001E7FD0(a);
            if (r != 0) {
                a[0x20B] = 0;
                *s0 = *(u16 *)(a + 0x20E);
                return r;
            }
        } else {
            r = func_001E7FD0(a);
            if (r != 0) {
                a[0x20B] = 1;
                *s0 = *(u16 *)(a + 0x20E);
                return r;
            }
        }
        return 0;
    }
}
