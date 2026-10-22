typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_006338CC;
extern void func_0041D6D0(u8 *);

void func_0041D640(u8 *p) {
    f32 one;
    *(s16 *)(p + 0x1E) = -9;
    one = 1.0f;
    p[5] = 1;
    p[0x13C] = 1;
    *(f32 *)(p + 0x34) = 9.020000457763672f;
    *(f32 *)(p + 0x38) = -7.619999885559082f;
    *(f32 *)(p + 0x3C) = -13.050000190734863f;
    *(f32 *)(p + 0x50) = one;
    *(f32 *)(p + 0x54) = 0.30000001192092896f;
    *(f32 *)(D_006338CC + 0x80) = one;
    *(f32 *)(D_006338CC + 0x7C) = one;
    *(f32 *)(D_006338CC + 0x78) = one;
    *(void **)(p + 0x10) = (void *)func_0041D6D0;
    func_0041D6D0(p);
}
