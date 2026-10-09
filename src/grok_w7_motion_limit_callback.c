typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);

void func_00306E80(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);

    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430))
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);

    func_00175700(p);
    if (*(s8 *)(p + 0x150) != 0) {
        *(s8 *)(p + 0x150) = 0;
        p[6]++;
    }
}
