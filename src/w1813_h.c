typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00453170[];

s32 func_0024DB40(u8 *p)
{
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    extern void func_001AD170(u8 *, s32, s32);
    u8 *q = p + 0x2B8;
    if (func_00189310(p, D_00453170, p + 0x3A0) == 0) return 0;
    if (p[0x20D] == 2) {
        s32 t = *(s8 *)(p + 0x1E8);
        if (t != 0) return 0;
        p[0x1E8] = t + 1;
    }
    func_0018A990(p, p + 0x3A0);
    if (p[0x1B7] == 0) {
        q[5] = 0;
        q[0xE] = 0;
        p[5] = 0;
        if (p[0x20D] == 2) {
            p[6] = 1;
        } else {
            p[6] = 0;
        }
        p[7] = 0;
        p[0x1FD] = 4;
        func_00186A60(p, 0x15);
        return 1;
    }
    if (*(s8 *)(q + 5) != 0) return 0;
    q[5] = 1;
    q[0xE] = 0;
    q[6] = 0;
    func_001AD170(p, 0xD, 0);
    return 0;
}
