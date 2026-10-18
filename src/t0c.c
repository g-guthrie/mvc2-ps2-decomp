typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_001757E0(u8 *p, s32 a, s32 b);
void func_0036D080(u8 *p) {
    u8 *q;
    p[0x13C] = 1;
    q = *(u8 **)(p + 0x14);
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
    q = *(u8 **)(p + 0x14);
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x34);
    q = *(u8 **)(p + 0x14);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    q = *(u8 **)(p + 0x14);
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    *(s16 *)(p + 0x1C) = 0;
    *(s16 *)(p + 0x1E) = 0;
    *(u32 *)(p + 0x5C) = 0;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = 0x41;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    *(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C) += 1;
    p[0x24] = 0xF;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x54) = *(u32 *)(p + 0x50) = 0x3FB33333;
    func_001757E0(p, 0x17, 0x31);
}
typedef struct { f32 x, y, z; } V3;
extern u32 D_004C283C;
extern V3 D_004454F8;
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern s32 func_00417A40(void);
extern void func_0015FB30(void);
void func_0015FDF0(u8 *p) {
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_0015FB30;
        *(u32 *)(o + 0xD0) = 0x41D;
        *(s16 *)(o + 0xCC) = 0x58;
        *(u32 *)(o + 0x84) = D_004C283C;
        *(u8 **)(o + 0x14) = p;
        *(u32 *)(o + 0x78) = 0x3F800000;
        *(u32 *)(o + 0x7C) = 0;
        *(u32 *)(o + 0x80) = 0;
        *(s16 *)(o + 0x1E) = func_00417A40() % 360;
        *(V3 *)(o + 0x50) = D_004454F8;
    }
}
extern int func_00175700(u8 *p);
extern u8 *D_004C2794;
void func_002BDFA0(u8 *p) {
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (p[0x15B] != 0) {
        p[0x15B] = 0;
        p[0x1B5] = 0x62;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        *(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C) += 1;
        *(s16 *)(p + 0x1C0) = 0x10;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x20D] = 2;
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
}
