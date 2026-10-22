typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_00453990[];
extern int func_00189310(u8 *, u8 *, u8 *);
extern int func_0025C240(u8 *p);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, int);

/* func_0025C6C0: not yet matched without a stand-in callee. */

extern u8 D_004511D0[];

s32 func_0021CCA0(u8 *p) {
    s32 t;
    if (func_00189310(p, D_004511D0, p + 0x388) == 0) {
        return 0;
    }
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            t = *(s8 *)(p + 0x1E8);
            if (t != 0) {
                return 0;
            }
            p[0x1E8] = t + 1;
        }
    }
    func_0018A990(p, p + 0x388);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 1;
    func_00186A60(p, 0x15);
    *(s16 *)(p + 0x2DA) = 1;
    return 1;
}
