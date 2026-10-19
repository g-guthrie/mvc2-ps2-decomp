typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_0026C800(u8 *);

void residual_0026C740(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        volatile int *z;
        p[6]++;
        z = (int *)(p + 0x5C);
        z[0] = 0;
        z[1] = 0;
        z[2] = 0;
        z[3] = 0;
        if (p[0x1E6])
            *(unsigned int *)(p + 0x5C) = 0xC1055555;
        else
            *(unsigned int *)(p + 0x5C) = 0x41055555;
        if (p[0x1E6])
            *(unsigned int *)(p + 0x68) = 0xBE200000;
        else
            *(unsigned int *)(p + 0x68) = 0x3E200000;
        *(unsigned int *)(p + 0x60) = 0x40F00000;
        *(unsigned int *)(p + 0x6C) = 0xBF4DB6DB;
    }
    func_0026C800(p);
}
