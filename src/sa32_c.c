typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004B84C8[];

void func_00375CA0(u8 *a, u8 *b) {
    extern f32 func_00417500(s32), func_00417440(s32);
    u8 *c = *(u8 **)(b + 0x14);
    f32 x, t, z, k, w, y;
    t = (f32)D_004B84C8[b[0x20]];
    x = t * func_00417500(*(s32 *)(c + 0x48));
    k = -0.0f;
    y = x + k * func_00417440(*(s32 *)(c + 0x48));
    w = t * func_00417440(*(s32 *)(c + 0x48));
    z = w + k * func_00417500(*(s32 *)(c + 0x48));
    *(f32 *)(b + 0x34) = *(f32 *)(c + 0x34);
    *(f32 *)(b + 0x38) = *(f32 *)(c + 0x38);
    if (a[0x1E6] != 0) y = -y;
    *(f32 *)(b + 0x34) += y;
    *(f32 *)(b + 0x38) += z;
}
