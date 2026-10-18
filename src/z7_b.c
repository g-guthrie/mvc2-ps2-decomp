typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0025E340(u8 *p) {
    extern s32 func_00174170();
    extern s32 func_001841C0();
    extern u8 D_00453EC0[];
    u32 f = *(u16 *)(p + 0x354);
    if ((f & 0x3F0) != 0) {
        if (f & 0x200) p[0x20] = 5;
        else if (f & 0x100) p[0x20] = 6;
        else if (f & 0x80) p[0x20] = 7;
        else if (f & 0x40) p[0x20] = 8;
        else if (f & 0x20) p[0x20] = 9;
        else p[0x20] = 10;
    } else {
        p[0x20] = D_00453EC0[(func_00174170() & 0xF) * 2];
    }
    if (func_001841C0(p) > 1) p[0x20] = 5;
}

s32 func_00233560(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    extern u8 D_00452190[];
    u8 *q = p + 0x2B8;
    s32 t;
    if (func_00189310(p, D_00452190, p + 0x390) == 0) return 0;
    if (p[0x1E4] == 0x19) return 0;
    q[6] = 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            t = *(s8 *)(p + 0x1E8);
            if (t != 0) return 0;
            p[0x1E8] = t + 1;
        } else {
            q[6] = 3;
        }
    }
    func_0018A990(p, p + 0x390);
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 2;
    func_00186A60(p, 0x15);
    return 1;
}
