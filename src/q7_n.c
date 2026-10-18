typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


s32 func_0012AAA0(u16 a, s32 b, s32 c, u32 d) {
    extern void func_001E3CE0();
    u32 m = a & 0x3C00;
    if (m == 0x2000) {
        b--;
        if (d & 1) {
            if (b < 0) {
                b = 0;
                goto next;
            }
        } else {
            if (b < 0) b = c;
        }
        if (d & 2) {
            func_001E3CE0(4);
        } else {
            func_001E3CE0(1);
        }
    }
next:
    if (m == 0x1000) {
        b++;
        if (d & 1) {
            if (c < b) {
                b = c;
                goto done;
            }
        } else {
            if (c < b) b = 0;
        }
        if (d & 2) {
            func_001E3CE0(4);
        } else {
            func_001E3CE0(1);
        }
    }
done:
    return b;
}
