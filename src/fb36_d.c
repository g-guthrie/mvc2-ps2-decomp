typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u32 D_004C2AC0;
extern f32 D_004C2AC8;
extern f32 D_004C2ACC;
extern u8 D_0061BEE0[];
extern u8 D_0061C720[];
extern u8 D_0061BE20[];
extern u8 D_0061BDE0[];

u8 *func_003E38D0(u8 *p, u8 *q) {
    extern s32 func_003DD030(s32);
    extern u8 *func_003DD160(s32, s32);
    extern void func_003DBA30(u8 *, s32, s32, s32, s32);
    extern void func_003DBB60(u8 *, s32, s32);
    extern void func_003DE160(u8 *, u8 *, u8 *);
    extern void func_003DBB20(u8 *, u8 *);
    s32 h;
    u8 *o;
    u8 m[0x40];
    h = func_003DD030(*(s32 *)(p + 0x1C));
    o = func_003DD160(0xD0, 0x10);
    func_003DBA30(o, 0xC, h, 0, 0);
    func_003DBB60(o + 0x10, 0xA, 0);
    *(u32 *)(o + 0x10) = 0x13000000;
    *(f32 *)(o + 0x20) = (f32)((D_004C2AC0 >> 16) & 0xFF) / 255.0f * *(f32 *)(*(u8 **)(p + 0x40) + 0x28);
    *(f32 *)(o + 0x24) = (f32)((D_004C2AC0 >> 8) & 0xFF) / 255.0f * *(f32 *)(*(u8 **)(p + 0x40) + 0x28);
    *(f32 *)(o + 0x28) = (f32)(u32)(D_004C2AC0 & 0xFF) / 255.0f * *(f32 *)(*(u8 **)(p + 0x40) + 0x28);
    *(f32 *)(o + 0x2C) = 0.5f * (f32)((D_004C2AC0 >> 24) & 0xFF);
    func_003DE160(m, D_0061BEE0, D_0061C720);
    func_003DE160(o + 0x30, m, D_0061BE20);
    func_003DE160(o + 0x70, m, D_0061BDE0);
    *(f32 *)(o + 0xB0) = D_004C2AC8;
    *(f32 *)(o + 0xB4) = 1.0f / (D_004C2AC8 - D_004C2ACC);
    *(s32 *)(o + 0xB8) = 0;
    *(s32 *)(o + 0xBC) = 0;
    func_003DBB20(o + 0xC0, q);
    return o;
}
