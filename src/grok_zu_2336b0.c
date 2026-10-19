typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern u8 D_004521C0[];
extern s32 func_00189310(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, s32);

s32 func_002336B0(u8 *p)
{
    s32 r = 0;
    if (!func_00189310(p, D_004521C0, p + 0x3A0))
        return r;
    if (!**(s8 **)(p + 0x420))
        return r;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            if ((s8)p[0x1E8] != 0)
                return r;
        }
        if (p[0x1E4] != 0xA && p[0x1E4] != 0xB) {
            f32 g = *(f32 *)(p + 0x430);
            f32 y = *(f32 *)(p + 0x38);
            if (y < g + 25.7142849f)
                return r;
            if (!(y <= g + 929.714233f))
                return r;
        }
    }
    func_0018A990(p, p + 0x3A0);
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 4;
    func_00186A60(p, 0x1D);
    return 1;
}
