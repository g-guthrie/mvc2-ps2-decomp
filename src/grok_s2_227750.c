typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);

void func_00227750(u8 *p)
{
    f32 f0, f1;
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 24;
        f0 = 15.833333f;
        f1 = -0.3125f;
        if (p[0x1E6]) {
            f0 = -f0;
            f1 = -f1;
        }
        *(f32 *)(p + 0x5C) = f0;
        *(f32 *)(p + 0x68) = f1;
    }
}
