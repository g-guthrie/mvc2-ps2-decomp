/* Update bobbing height from the frame angle and selected amplitude/baseline. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern f32 func_00417440(u32);
extern f32 D_00460608[];
extern f32 D_004605E4[];

void func_003421E0(u8 *p)
{
    s32 idx = p[0x20];
    f32 s = func_00417440((u32)(u16)(unsigned int)((double)*(s16 *)(p + 0x1C) * 65536.0 / 360.0 + 0.5));
    {
        f32 amplitude = D_00460608[idx];
        f32 baseline = D_004605E4[idx * 3];
        s = amplitude * s;
        *(f32 *)(p + 0x38) = baseline + s;
    }
    *(s16 *)(p + 0x1C) = (s16)(*(s16 *)(p + 0x1C) + 1);
    if (*(s16 *)(p + 0x1C) >= 360)
        *(s16 *)(p + 0x1C) = 0;
}
