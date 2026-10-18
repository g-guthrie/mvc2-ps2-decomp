typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FD8; extern f32 D_004F1FDC;
void func_0035ADE0(u8 *p) {
    f32 x = *(f32 *)(p + 0x34);
    f32 lo = 53.33333206f + D_004F1FD8;
    if (!(lo <= x)) { *(f32 *)(p + 0x34) = lo; }
    else {
        f32 hi = D_004F1FDC - 53.33333206f;
        if (hi < x) *(f32 *)(p + 0x34) = hi;
        return;
    }
}
