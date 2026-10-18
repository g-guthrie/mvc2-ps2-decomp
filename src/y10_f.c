typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_00457C90[];
s32 func_002951B0(u8 *p) {
    extern s32 func_00189310();
    extern double func_00119058(f32);
    extern void func_0018A990();
    extern void func_00186A60();
    if (func_00189310(p, D_00457C90, p + 0x390) == 0) {
        return 0;
    }
    if (func_00119058(*(f32 *)(p + 0x60)) < 0.0) {
        if (*(f32 *)(p + 0x38) - *(f32 *)(p + 0x430) < 102.85713958740234f) {
            return 0;
        }
    }
    if (p[0x210] == 0) {
        s32 t = *(s8 *)(p + 0x1E8);
        if (t != 0) {
            return 0;
        }
        p[0x1E8] = t + 1;
    }
    func_0018A990(p, p + 0x390);
    p[0x1FD] = 3;
    p[5] = 0;
    func_00186A60(p, 0x15);
    p[7] = 0;
    p[6] = 0;
    return 1;
}

