typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_0022C5D0(u8 *);

void func_00227020(u8 *p)
{
    f32 vx, ax;
    if (p[6] == 0) {
        func_00175700(p);
        if ((s8)p[0x151] != 0) {
            p[6]++;
            {
                unsigned int a = 0x41D55555;
                unsigned int b = 0xBF555555;
                vx = *(f32 *)&a;
                ax = *(f32 *)&b;
            }
            if (p[0x1E6] == 0) {
                vx = -vx;
                ax = -ax;
            }
            *(f32 *)(p + 0x5C) = vx;
            *(f32 *)(p + 0x68) = ax;
        }
        return;
    }
    if ((s8)p[0x151] == 2) {
        p[0x151] = 0;
        *(int *)(p + 0x5C) = 0;
        *(int *)(p + 0x68) = 0;
    }
    if (func_00175700(p) < 0)
        func_0022C5D0(p);
}
