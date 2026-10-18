typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_00175700(u8 *);
extern s32 func_00174470(u8 *);
extern s32 func_00394760(u8 *);
extern u8 *D_004C29D4;
s32 func_00392F70(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00174470(p) == 0) {
        s32 r = func_00394760(p);
        *(s8 *)(D_004C29D4 + 8) = -1;
        return r;
    }
}
extern u8 *D_004C2794;
typedef struct { u8 *a; u8 *b; u8 *c; } R171;
typedef struct { u8 pad0[0x18]; R171 r[1]; } G171;

extern void func_001757E0(u8 *, s32, s32);
void func_002C98A0(u8 *p, u8 *q) {
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    t = p[6];
    p[6] = t + 1;
    *(s16 *)(p + 0x1C) = 4;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x1B5] = 0x3D;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    *(s16 *)(((u32)p[2] << 1) + (u32)D_004C2794 + 0x7C) += 1;
    q[0xC] = 1;
    func_001757E0(p, 0x15, 0x12);
}
extern u8 *func_003DA750(s32, s32, s32);
extern void func_0015E6C0();
extern u8 *D_004C2838;
void func_0015E630(u8 *p) {
    u8 *o = func_003DA750(0, 7, 1);
    if (o != 0) {
        o[0x13C] = 0;
        *(void **)(o + 0x10) = func_0015E6C0;
        *(s16 *)(o + 0xCC) = 0xB;
        *(u8 **)(o + 0x84) = D_004C2838;
        *(u32 *)(o + 0xD0) = 0x800D31;
        *(u8 **)(o + 0x18) = p;
        o[1] = p[1];
        *(u32 *)(o + 0x78) = 0x3F000000;
        *(u32 *)(o + 0x7C) = 0x3F000000;
        *(u32 *)(o + 0x80) = 0x3F000000;
        *(u32 *)(o + 0x54) = 0x3F800000;
        *(u32 *)(o + 0xC8) = 0;
    }
}
