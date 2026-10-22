typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_004B7500[];
extern u32 D_004554D0[];
static u8 func_00280D80(u8 *p)
{
    f32 d = *(f32 *)(*(u8 **)(p + 0x220) + 0x34) - *(f32 *)(p + 0x34);
    f32 f;
    u8 r;
    if (*(s16 *)(p + 0x140) != 0) d = -d;
    f = *(f32 *)(p + 0x50);
    if (d > -133.3333282470703f * f) {
        r = 4;
        if (d > 160.0f * f) r++;
    } else {
        r = 0;
        if (d < -226.66665649414062f * f) r++;
        if (d < -320.0f * f) r++;
        if (d < -400.0f * f) r++;
    }
    return r;
}
s32 func_00280EC0(u8 *p)
{
    extern s32 func_00281040(u8 *, u8 *);
    extern s32 func_00174170();
    if (*(u32 *)(p + 0x4C4) & 1) return 0;
    if (func_00280D80(p) >= 4) {
        *(u32 *)(p + 0x4C4) |= 1;
        if (func_00281040(p, D_004B7500) != 0) {
                p[0x450] = 2;
                p[0x451] = 0;
                p[0x452] = 0;
                p[0x453] = 0;
                p[0x495] = 0;
                p[0x496] = 1;
                *(u32 *)(p + 0x484) = D_004554D0[func_00174170() & 3];
            return 1;
        }
    }
    return 0;
}
