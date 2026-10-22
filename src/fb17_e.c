typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern f32 D_00583C10[];
extern f32 D_00583C14[];
extern f32 D_00583C18[];

void func_00336C60(u8 *p)
{
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    if (*(s16 *)(p + 0x1C) > 0x64) {
        p[4] = 0;
        *(s16 *)(p + 0x1C) = 0;
        return;
    }
    *(u32 *)(p + 0x40) = (u32)(s32)(0.5 + 65536.0 * (f64)*(f32 *)(p + 0x5C) / 360.0) & 0xFFFF;
    *(u32 *)(p + 0x44) = (u32)(s32)(0.5 + 65536.0 * (f64)*(f32 *)(p + 0x60) / 360.0) & 0xFFFF;
    *(u32 *)(p + 0x48) = (u32)(s32)(0.5 + 65536.0 * (f64)*(f32 *)(p + 0x64) / 360.0) & 0xFFFF;
    *(u32 *)(p + 0x40) += (u32)(s32)(0.5 + 65536.0 * (f64)((f32)*(s16 *)(p + 0x1C) * D_00583C10[p[0x23] * 3]) / 360.0) & 0xFFFF;
    *(u32 *)(p + 0x44) += (u32)(s32)(0.5 + 65536.0 * (f64)((f32)*(s16 *)(p + 0x1C) * D_00583C14[p[0x23] * 3]) / 360.0) & 0xFFFF;
    *(u32 *)(p + 0x48) += (u32)(s32)(0.5 + 65536.0 * (f64)((f32)*(s16 *)(p + 0x1C) * D_00583C18[p[0x23] * 3]) / 360.0) & 0xFFFF;
}
