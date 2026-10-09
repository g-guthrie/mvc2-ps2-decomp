typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;
typedef union FloatBits {
    f32 value;
    u32 bits;
} FloatBits;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);

void func_00306F20(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);

    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430))
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);

    if ((s8)func_00175700(p) >= 0)
        return;

    if (p[7] == 0) {
        func_001843A0(p);
    } else {
        ((FloatBits *)(p + 0x6C))->bits = 0xBF4DB6DB;
        func_00184540(p);
    }
}
