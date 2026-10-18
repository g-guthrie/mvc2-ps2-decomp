typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_002CBEB0(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    extern u8 D_00459FF0[];
    u8 *q;
    u8 k;
    q = p + 0x2B8;
    if (func_00189310(p, D_00459FF0, p + 0x378) == 0)
        return 0;
    if (q[2] != 0)
        return 0;
    k = 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 t;
            if (*(s8 *)(p + 0x1E8) != 0)
                return 0;
            t = *(s8 *)(p + 0x1E8);
            p[0x1E8] = t + 1;
        }
        k = 4;
    }
    func_0018A990(p, p + 0x378);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = k;
    func_00186A60(p, 0x15);
    return 1;
}
