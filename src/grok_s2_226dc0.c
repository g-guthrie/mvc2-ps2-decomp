typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001864A0(u8 *);
extern void func_001865B0(u8 *);

void func_00226DC0(u8 *p)
{
    f32 f;
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[7]++;
        p[0x151] = 0;
        p[0x210] = 0;
        f = -14.166666f;
        if (p[0x1E6])
            f = -f;
        *(f32 *)(p + 0x5C) = f;
        *(int *)(p + 0x68) = 0;
        *(int *)(p + 0x60) = 0xC1892492;
        *(int *)(p + 0x6C) = 0xBF092492;
    }
    if (func_001864A0(p))
        func_001865B0(p);
}
