typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Four interleaved IEEE-754 components per table entry. */
extern u32 data_u32_004585C0[12];

void func_002A4290(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_00186A20(u8 *);
    f32 value, zero;

    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00186A20(p);
        *(s16 *)(p + 0x1C) = 12;
        if (p[0x1E6] != 0) value = ((f32 *)(data_u32_004585C0 + 0))[p[0x1B7] * 4];
        else value = -((f32 *)(data_u32_004585C0 + 0))[p[0x1B7] * 4];
        *(f32 *)(p + 0x5C) = value;
        if (p[0x1E6] != 0) value = ((f32 *)(data_u32_004585C0 + 1))[p[0x1B7] * 4];
        else value = -((f32 *)(data_u32_004585C0 + 1))[p[0x1B7] * 4];
        *(f32 *)(p + 0x68) = value;
        *(f32 *)(p + 0x60) = ((f32 *)(data_u32_004585C0 + 2))[p[0x1B7] * 4];
        *(f32 *)(p + 0x6C) = ((f32 *)(data_u32_004585C0 + 3))[p[0x1B7] * 4];
    }
    value = (f32)p[0x15B];
    zero = 0.0f;
    if (value != zero) {
        p[0x15B] = 0;
        value *= 1.6666666269302368f;
        if (p[0x1E6] == 0) value *= -1.0f;
        *(f32 *)(p + 0x34) += value;
    }
}
