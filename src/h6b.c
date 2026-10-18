typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
extern int func_00189310(u8 *, void *, u8 *);
extern u8 D_0044FEC0[];
s32 func_001FC8B0(u8 *p) {
    if (func_00189310(p, D_0044FEC0, p + 0x3B8) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    p[0x20] = 0;
    p[0x26C] = 6;
    return 1;
}
extern s8 func_00175700(u8 *);
extern void func_00126400(void);
extern void func_001843A0(u8 *);
void func_002F44F0(u8 *p, u16 *q) {
    if (func_00175700(p) < 0) {
        func_00126400();
        if (*q < 10) {
            u32 t = p[0x1E6];
            p[0x1E6] = t ^ 1;
            *(s16 *)(p + 0x140) = p[0x1E6];
        }
        func_001843A0(p);
    }
}
extern s8 func_00175700(u8 *);
extern void func_00198170(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);
void func_0034AB80(u8 *p) {
    s32 v;
    func_00175700(p);
    v = *(s8 *)(p + 0x151);
    if (v != 0) {
        if ((s8)v == 0x3F) {
            u32 t = p[5];
            p[5] = t + 1;
            func_00198170(p, 3);
            func_001757E0(p, 0x16, 0x12);
        } else {
            p[0x151] = 0;
        }
    }
}
extern int func_00189310(u8 *, void *, u8 *);
extern void func_00186A60(u8 *, s32);
extern u8 D_0045BD70[];
s32 func_002F6F10(u8 *p) {
    if (p[0x2CE] != 0) return 0;
    if (func_00189310(p, D_0045BD70, p + 0x3A8) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 10;
    func_00186A60(p, 0x1D);
    return 1;
}
extern s8 func_00175700(u8 *);
void func_0028FF00(u8 *p) {
    if (func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0x14, 2);
    }
    func_00175700(p);
}
