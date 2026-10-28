typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef double f64;
extern u8 D_00457CD0[];

typedef struct { u8 pad[0x1E8]; s8 b1E8; } SS;

s32 func_00295500(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    f32 d;
    if (func_00189310(p, D_00457CD0, p + 0x3D0) == 0) return 0;
    if (p[0x210] == 0) {
        s32 t = *(s8 *)(p + 0x1E8);
        if (t != 0) return 0;
        ((SS *)p)->b1E8 = t + 1;
    }
    d = *(f32 *)(p + 0x38) - *(f32 *)(p + 0x430);
    if (d < 102.85713958740234f) return 0;
    if ((double)(*(f32 *)(p + 0x60)) < 0) {
        if (d < 102.85713958740234f) return 1;
    }
    func_0018A990(p, p + 0x3D0);
    p[0x1FD] = 0xE;
    p[5] = 0;
    func_00186A60(p, 0x15);
    p[7] = 0;
    p[6] = 0;
    return 1;
}
