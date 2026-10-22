typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_0016B240(u8 *, s32);
extern void func_0016B0C0(u8 *, s32, s32);
extern s32 func_00185630(u8 *);
extern s32 func_00166C80(u8 *, s32, s32);

s32 func_00166490(u8 *p, s32 b) {
    s32 ok;
    if (func_0016B240(p, 2) == 0) {
        return 0;
    }
    func_0016B0C0(p, b, 0);
    p[0x212] = 0;
    ok = 1;
    p[0x1B7] = ok;
    *(s16 *)(p + 0x20E) = 0x800;
    if (func_00185630(p) == 0) {
        ok = 0;
        p[0x212] = 1;
        if (func_00185630(p) != 0) {
            ok = 1;
        }
    }
    p[0x212] = 0;
    p[0x1B7] = 0;
    *(s16 *)(p + 0x20E) = 0;
    return func_00166C80(p, b, ok);
}
