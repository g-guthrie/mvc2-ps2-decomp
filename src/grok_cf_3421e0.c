typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern f64 func_00119B08(s32);
extern f64 func_001195D0(f64, f64);
extern f64 func_00119858(f64, f64);
extern f64 func_00119510(f64, f64);
extern s32 func_00119BC0(f64);
extern f32 func_00417440(s32);
extern f32 D_00460608[];
extern f32 D_004605E4[];

void func_003421E0(u8 *p)
{
    s32 idx = p[0x20];
    f32 s = func_00417440((s32)(u16)func_00119BC0(
        func_00119510(0.5, func_00119858(func_001195D0(65536.0, func_00119B08(*(s16 *)(p + 0x1C))), 360.0))));
    *(f32 *)(p + 0x38) = D_004605E4[idx * 3] + D_00460608[idx] * s;
    *(s16 *)(p + 0x1C) = (s16)(*(s16 *)(p + 0x1C) + 1);
    if (*(s16 *)(p + 0x1C) >= 360)
        *(s16 *)(p + 0x1C) = 0;
}
