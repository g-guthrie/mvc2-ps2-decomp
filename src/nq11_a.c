typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FC8;
extern f32 D_004F1FCC;

void residual_001A7BA0(u8 *p, u8 *b)
{
    extern void func_001A7C50(u8 *, u8 *);
    u32 t = p[5];
    p[5] = t + 1;
    if (*(s16 *)(p + 0x140) == 0) {
        *(f32 *)(p + 0x34) = 186.66665649414062f + D_004F1FCC;
    } else {
        *(f32 *)(p + 0x34) = D_004F1FC8 - 186.66665649414062f;
    }
    *(f32 *)(p + 0x38) = *(f32 *)(b + 0x430);
    if (*(s16 *)(p + 0x140) == 0) {
        *(u32 *)(p + 0x5C) = 0xC1555555;
        *(u32 *)(p + 0x68) = 0x3ED55555;
    } else {
        *(u32 *)(p + 0x5C) = 0x41555555;
        *(u32 *)(p + 0x68) = 0xBED55555;
    }
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001A7C50(p, b);
}
