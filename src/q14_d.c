typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004544F0[];
extern s32 func_00189310(u8 *p, u8 *t, u8 *q);
extern void func_0018A990(u8 *p, u8 *q);
extern void func_00186A60(u8 *p, s32 n);
s32 func_0026B1C0(u8 *p) {
    u8 *q = p + 0x2B8;
    if (func_00189310(p, D_004544F0, p + 0x380) == 0) return 0;
    if (*(s8*)q >= 2) return 0;
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

extern u8 D_00448F00[];
extern s32 func_00189310(u8 *p, u8 *t, u8 *q);
extern s32 func_0018ACD0(u8 *p);
s32 func_00189150(u8 *p) {
    u8 t;
    u8 v;
    if (func_00189310(p, D_00448F00, p + 0x3E8) == 0) return 0;
    t = p[0x20D];
    if (t != 0 && t != 1) return 0;
    if (*(s8*)(p + 0x539) != 0) {
        v = func_0018ACD0(p);
    } else if (*(u16*)(p + 0x3EE) & 0x80) {
        v = 1;
    } else {
        v = 2;
    }
    p[0x1B7] = v;
    return 1;
}
