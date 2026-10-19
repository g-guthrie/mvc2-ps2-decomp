typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001D0F90(u8 *, int, int);
extern void func_001E3210(u8 *, int);

void func_002D9FE0(u8 *p)
{
    f32 vx;
    f32 ax;

    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 0x10;
        vx = -16.66666603088379f;
        ax = 0.20833332836621094f;
        if (p[0x1E6]) {
            vx = -vx;
            ax = -ax;
        }
        *(f32 *)(p + 0x5C) = vx;
        *(f32 *)(p + 0x68) = ax;
        *(f32 *)(p + 0x60) = 0;
        *(f32 *)(p + 0x6C) = 0;
        if (p[0x1E5] != 10)
            func_001D0F90(p, 1, 0);
        func_001E3210(p, 0x21);
    }
}
