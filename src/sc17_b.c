typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 *v[3]; } Row17;
extern Row17 D_004D18B8[];

s32 func_00252C80(u8 *a)
{
    extern s32 func_001E8310(void *, void *, int, int);
    u8 *s0, *s1, *s2, *s3;
    u32 v;
    s2 = a;
    s0 = D_004D18B8[s2[2]].v[0];
    s1 = *(u8 **)(s2 + 0x1D4);
    s3 = *(u8 **)(s0 + 0x1D4);
    if (func_001E8310(s2, s0, (s16)(s32)s1[2], *(s16 *)(s3 + 4)) != 0) {
        return 1;
    }
    if (func_001E8310(s2, s0, (s16)(s32)s1[2], *(s16 *)(s3 + 6)) != 0) {
        return 1;
    }
    if (func_001E8310(s2, s0, (s16)(s32)s1[2], *(s16 *)(s3 + 8)) != 0) {
        return 1;
    }
    v = *(u16 *)(s3 + 0xA);
    if (v != 0) {
        if (func_001E8310(s2, s0, (s16)(s32)s1[2], (s16)((u32)(u16)v & 0x1FFF)) != 0) {
            return 1;
        }
    }
    return 0;
}
