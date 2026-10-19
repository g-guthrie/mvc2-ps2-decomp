typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern s32 func_0016B240(u8 *, s32);
extern void func_0016B0C0(u8 *, u8 *, s32);
extern s32 func_00185630(u8 *);
extern s32 func_00166C80(u8 *, u8 *, s32);

s32 func_00166490(u8 *p, u8 *q)
{
    s32 s0 = 1;

    if (func_0016B240(p, 2) == 0)
        return 0;
    func_0016B0C0(p, q, 0);
    p[0x212] = 0;
    p[0x1B7] = s0;
    *(s16 *)(p + 0x20E) = 0x800;
    if (func_00185630(p) == 0) {
        p[0x212] = s0;
        s0 = 0;
        if (func_00185630(p) != 0)
            s0 = 1;
    }
    p[0x212] = 0;
    p[0x1B7] = 0;
    *(s16 *)(p + 0x20E) = 0;
    return func_00166C80(p, q, s0);
}
