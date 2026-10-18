typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_0045CB20[];
s32 func_00305040(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    if (func_00189310(p, D_0045CB20, p + 0x388) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 v = *(s8 *)(p + 0x1E8);
            if (v != 0) return 0;
            p[0x1E8] = v + 1;
        }
    }
    func_0018A990(p, p + 0x388);
    p[5] = 0;
    p[6] = 0;
    p[7] = 1;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}
