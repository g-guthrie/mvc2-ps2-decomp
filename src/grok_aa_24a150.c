typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_0024A150(u8 *p)
{
    s16 t;

    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        if (p[0x1E6] == 0)
            *(u32 *)(p + 0x5C) = 0xC1555555;
        else
            *(u32 *)(p + 0x5C) = 0x41555555;
    }
    t = *(s16 *)(p + 0x1C);
    t = t - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t <= 0) {
        p[6]++;
        if (p[0x1E6] == 0)
            *(u32 *)(p + 0x68) = 0x3E855555;
        else
            *(u32 *)(p + 0x68) = 0xBE855555;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 2, 5);
    }
}
