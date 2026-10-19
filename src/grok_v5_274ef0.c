typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_0015F8D0(u8 *);
extern void func_00274FB0(u8 *);

void residual_00274EF0(u8 *p)
{
    volatile int *z;
    func_00175700(p);
    z = (int *)(p + 0x5C);
    z[0] = 0;
    z[1] = 0;
    z[2] = 0;
    z[3] = 0;
    if ((s8)p[0x151] == 0) {
        func_0015F8D0(p);
        p[6]++;
        if (p[0x1E6])
            *(unsigned int *)(p + 0x5C) = 0x4192AAAA;
        else
            *(unsigned int *)(p + 0x5C) = 0xC192AAAA;
        if (p[0x1E6])
            *(unsigned int *)(p + 0x68) = 0xBF200000;
        else
            *(unsigned int *)(p + 0x68) = 0x3F200000;
        *(s16 *)(p + 0x1C) = 12;
        func_00274FB0(p);
    }
}
