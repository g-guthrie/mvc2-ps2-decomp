typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern u8 *func_003DA750(s32, s32, s32);
extern u8 *func_003DA780(s32, s32, s32);
extern void func_00160710(void);
extern void func_00160B80(u8 *);
extern void func_00160600(u8 *);
extern void func_00199200(void);
extern s32 func_00189310(u8 *, void *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, s32);
extern s32 func_00153AA0(u8 *);
extern void func_00170DA0(s32, s32, s32, s32);
extern u8 D_00454500[];
extern s32 D_004C2838;
extern s32 D_004C283C;
extern f32 D_004F1F4C[];

s32 func_0026B250(u8 *p) {
    u8 *q = p + 0x2B8;
    if (func_00189310(p, D_00454500, p + 0x3A8) == 0) return 0;
    if (*(s8 *)q >= 2) return 0;
    func_0018A990(p, p + 0x3A8);
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 8;
    func_00186A60(p, 0x15);
    return 1;
}

