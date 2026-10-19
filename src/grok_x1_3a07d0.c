typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);
extern void func_003A0880(u8 *);

void func_003A07D0(u8 *p)
{
    s16 t = *(s16 *)(p + 0x1C);

    *(s16 *)(p + 0x1C) = (s16)(t - 1);
    if ((s16)(t - 1) != 0 && (s8)p[0x1B2] == 0 && (s8)p[0x1B3] == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
        func_001E7F60(p);
    } else
        func_003A0880(p);
}
