typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern f32 D_004F1F4C;
void func_002A70B0(u8 *p) {
    f32 g = D_004F1F4C;
    double c;
    if (*(s16 *)(p + 0x140) != 0) c = 288.3333339691162;
    else c = -288.3333339691162;
    *(f32 *)(p + 0x34) = g + c;
}
