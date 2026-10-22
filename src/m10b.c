typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_0028A490(u8 *p);
extern void func_0028A530(void *p, u8 *q);
extern void func_0028B0B0(void *p);
/* func_0028AE00: not yet matched without a stand-in callee. */
extern u8 D_0045DD90[];
extern s32 func_00189310(void *p, void *a, void *b);
extern void func_00186A60(void *p, s32 a);
s32 func_003225B0(u8 *p) {
    if (func_00189310(p, D_0045DD90, p + 0x390) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (*(s32 *)(p + 0x2B8) > 0) return 0;
    p[0x13C] = 1;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 3;
    func_00186A60(p, 0x1D);
    return 1;
}
