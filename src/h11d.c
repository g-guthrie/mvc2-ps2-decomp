typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_00185490(u8 *p) {
    u32 a = p[0x1E6];
    f32 k = -23.333332f;
    f32 v;
    f32 w;
    if (a != 0) k = -k;
    v = *(f32 *)(*(u8 **)(p + 0x220) + 0x34);
    v += k;
    w = *(f32 *)(p + 0x34);
    if ((v < w && a != 0) || (!(v < w) && a == 0)) {
        p[0x1E6] ^= 1;
    }
    *(s16 *)(p + 0x140) = p[0x1E6];
}
