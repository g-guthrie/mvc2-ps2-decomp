typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001EC2D0(u8 *);

void func_001EC660(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 22, 2);
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    } else {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x38) + -0.13392857f;
        func_001EC2D0(p);
    }
}
