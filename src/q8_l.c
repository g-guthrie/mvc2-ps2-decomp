typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_002C56E0(u8 *p) {
    extern s32 func_00189660();
    extern void func_002CAFC0();
    extern void func_00186A60();
    extern u8 D_00459CB0[];
    u8 *q = p + 0x2B8;
    s32 r = 0;
    u8 one;
    if (func_00189660(p, D_00459CB0, p + 0x3A8) == 0) {
        return r;
    }
    if (p[0x20D] == 2 && p[0x210] == 0) {
        s8 t = *(s8 *)(p + 0x1E8);
        if (t != 0) {
            return r;
        }
        p[0x1E8] = t + 1;
    }
    if (*(s8 *)(p + 0x539) != 0 && p[0x215] != 0) {
        return r;
    }
    one = 1;
    if (p[0x215] != 0) {
        func_002CAFC0(p);
    }
    p[0x1B7] = 1;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 4;
    func_00186A60(p, 0x15);
    q[3] = (p[0x20D] == 2) ? 1 : 0;
    return 1;
}
