typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern void func_001E7F60(u8 *);
extern s32 func_001E7FD0(u8 *);
extern u8 *func_003DA750(s32, s32, s32);
extern void func_003A2540(void);
extern u16 D_004D18DC;
extern u8 D_004D18DB;

void *func_003A23F0(u8 *a, u8 b, u8 c) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r) {
        *(u32 *)(r + 0x10) = (u32)func_003A2540;
        r[0x20] = b;
        *(s32 *)(r + 0x18) = *(s32 *)(a + 0x18);
        *(u8 **)(r + 0x14) = a;
        r[1] = (*(u8 **)(a + 0x18))[1];
        *(s16 *)(r + 0x26) = 0x2C01;
        r[0x21] = c;
    }
    return r;
}

void func_00354990(u8 *p) {
    if (!(D_004D18DC & (1 << D_004D18DB))) {
        if ((s8)func_00175700(p) < 0) {
            u32 t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
        } else if (p[0x20] == 0) {
            func_001E7F60(p);
        }
    }
}

void func_0036BEF0(u8 *p) {
    s16 t;
    func_00175700(p);
    *(f32 *)(p + 0x50) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x54) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t - 1;
    if (t == 0) {
        u32 u = p[4];
        p[4] = u + 1;
        p[0x13C] = 0;
    }
}

