typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_0020D2F0(u8 *);
extern s32 func_0020D250(u8 *, u8 *, s32);
s32 func_0020C0E0(u8 *a, u8 *b) {
    u32 h;
    s32 r;
    if (func_0020D2F0(a) != 0) {
        return func_0020D250(a, b, 5);
    }
    h = *(u16 *)(a + 0x35E);
    if (h & 0x300) {
        a[0x1B7] = (h & 0x100) ? 1 : 0;
        return func_0020D250(a, b, 3);
    } else if (h & 0x60) {
        if (h & 0x1000) {
            r = func_0020D250(a, b, 6);
        } else {
            a[0x1B7] = (h & 0x20) ? 1 : 0;
            r = func_0020D250(a, b, 4);
        }
        return r;
    } else if (h & 0x2000) {
        return func_0020D250(a, b, 1);
    } else if (h & 0x1000) {
        return func_0020D250(a, b, 2);
    } else if (h & 0x800) {
        return func_0020D250(a, b, 7);
    }
}
