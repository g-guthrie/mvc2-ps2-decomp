typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);

void residual_00263F10(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        volatile int *z;
        p[0x151] = 0;
        p[6]++;
        z = (int *)(p + 0x5C);
        z[0] = 0;
        z[1] = 0;
        z[2] = 0;
        z[3] = 0;
        if (p[0x1E6])
            *(unsigned int *)(p + 0x5C) = 0x417D5555;
        else
            *(unsigned int *)(p + 0x5C) = 0xC17D5555;
        {
            f32 add;
            if (p[0x1E6])
                *(unsigned int *)&add = 0x41D55555;
            else
                *(unsigned int *)&add = 0xC1D55555;
            *(f32 *)(p + 0x34) += add;
        }
    }
}
