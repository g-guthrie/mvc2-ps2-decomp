typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00399570(u8 *p) {
    extern s32 func_00174470(u8 *);
    extern void func_00399690(u8 *);
    extern void func_001E7F60(u8 *);
    extern s32 func_00175700(u8 *);
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    s8 r;
    if (func_00174470(p) == 0) {
        func_00399690(p);
        return;
    }
    func_001E7F60(p);
    r = func_00175700(p);
    if (r < 0) {
        func_00399690(p);
        return;
    }
    *(f32 *)(p + 0x5C) = 8.333333f * func_00417500(((0x50 - p[0x22]) & 0x3F) << 10);
    *(f32 *)(p + 0x60) = 10.714285f * func_00417440(((0x50 - p[0x22]) & 0x3F) << 10);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x5C) + *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x60) + *(f32 *)(p + 0x6C);
}
