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
extern void func_00170DA0(s32, s32, s32, s16);
extern u8 D_00454500[];
extern s32 D_004C2838;
extern s32 D_004C283C;
extern f32 D_004F1F4C[];

void func_00311820(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x5C) = 0xC0C80000;
        *(u32 *)(p + 0x68) = 0x3DD55555;
        *(u32 *)(p + 0x60) = 0x41809249;
        *(u32 *)(p + 0x6C) = 0xBF676DB6;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}

void func_00160570(void) {
    u8 *a;
    if ((a = func_003DA780(0, 10, 1)) == 0) return;
    {
        a[0x13C] = 1;
        *(u32 *)(a + 0x10) = (u32)func_00160710;
        *(s16 *)(a + 0xCC) = 0xEE;
        *(s32 *)(a + 0x84) = D_004C2838;
        *(f32 *)(a + 0x34) = D_004F1F4C[0];
        *(u32 *)(a + 0x3C) = 0xC7C35000;
        *(s32 *)(a + 0xD0) = 0xB;
        *(s16 *)(a + 0x1C) = 0;
        func_00160B80(a);
        func_00160600(a);
    }
}

void func_00275500(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 2) {
        u32 t = p[0x20];
        p[0x20] = t + 1;
        *(u32 *)(p + 0x118) = 0x3F800000;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
    if (*(s8 *)(p + 0x151) == 3) {
        *(f32 *)(p + 0x118) += 0.016f;
    }
}

void func_00199170(u8 *a) {
    u8 *r = func_003DA750(0, 3, 0);
    if (r) {
        *(u32 *)(r + 0x10) = (u32)func_00199200;
        *(u8 **)(r + 0x18) = a;
        r[0x20] = 0;
        r[0x21] = 0;
        *(s16 *)(r + 0x26) = 0x401;
    }
    r = func_003DA750(0, 3, 0);
    if (r) {
        *(u32 *)(r + 0x10) = (u32)func_00199200;
        *(u8 **)(r + 0x18) = a;
        r[0x20] = 0;
        r[0x21] = 1;
        *(s16 *)(r + 0x26) = 0x401;
    }
}

void func_0032FA60(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = v;
    if (*(s16 *)(p + 0x1C) >= 1000) *(s16 *)(p + 0x1C) = 0;
    func_00170DA0(D_004C283C, 0x14, func_00153AA0(p), *(s16 *)(p + 0xCC));
    *(s32 *)(p + 0xE0) = 0;
    *(f32 *)(p + 0xE4) = -0.001f * *(s16 *)(p + 0x1C);
    *(u32 *)(p + 0xD0) |= 0x20000;
}
