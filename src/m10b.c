typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static s32 func_0028A490(u8 *p) {
    u8 m = p[0x1E6];
    f32 *o = *(f32 **)(p + 0x220);
    f32 a = *(f32 *)(p + 0x34);
    f32 b = o[0x34 / 4];
    if (m == 0) {
        if (a < b) return 1;
    }
    if (m == 0) return 0;
    if (a <= b) return 0;
    return 1;
}
extern void func_0028A530(void *p, u8 *q);
extern void func_0028B0B0(void *p);
void func_0028AE00(u8 *p, u8 *q) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        if (func_0028A490(p)) {
            p[7] = 6;
            q[0x18] = 0;
            func_0028A530(p, q);
        } else {
            func_0028B0B0(p);
        }
    }
}
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
