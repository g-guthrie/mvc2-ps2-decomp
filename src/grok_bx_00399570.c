typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern s32 func_00174470(u8 *);
extern void func_00399690(u8 *);
extern void func_001E7F60(u8 *);
extern s8 func_00175700(u8 *);
extern f32 func_00417500(s32);
extern f32 func_00417440(s32);

void func_00399570(u8 *p)
{
    f32 sc;
    if (!func_00174470(p)) {
        func_00399690(p);
        return;
    }
    func_001E7F60(p);
    if (func_00175700(p) < 0) {
        func_00399690(p);
        return;
    }
    sc = 8.33333301544189453125f;
    *(f32 *)(p + 0x5C) = sc * func_00417500(((0x50 - p[0x22]) & 0x3F) << 10);
    sc = 10.7142848968505859375f;
    *(f32 *)(p + 0x60) = sc * func_00417440(((0x50 - p[0x22]) & 0x3F) << 10);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
}
