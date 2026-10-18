typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1F4C;

void func_0034E760(u8 *p) {
    double d;
    *(f32 *)(p + 0x34) = D_004F1F4C;
    if (*(s16 *)(p + 0x140) != 0) {
        d = -426.66666412353516;
    } else {
        d = 426.66666412353516;
    }
    *(f32 *)(p + 0x34) += (f32)d;
    p[0x14C] = 0x40;
    p[0x14D] = 0x10;
    p[0x14E] = 0x60;
    p[0x14F] = 0x60;
}
