typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern int func_00175700(u8 *);
extern s32 func_00118FA8(f32);
extern int func_001757E0(u8 *, int, int);
extern u8 D_004D18EC;

void func_00319080(u8 *p)
{
    s32 a, b;
    f32 *vx;
    f32 *ax;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    a = func_00118FA8(*(f32 *)(p + 0x5C));
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    vx = (f32 *)(p + 0x5C);
    ax = (f32 *)(p + 0x68);
    b = func_00118FA8(*vx);
    if ((b ^ a) < 0) {
        *vx = 0;
        *ax = 0;
    }
    if ((D_004D18EC & (1 << p[0x1B8])) == 0) {
        s8 t = p[0x2B8] - 1;
        p[0x2B8] = t;
        if (t < 0) {
            p[6]++;
            func_001757E0(p, 0x16, 0x1B);
        }
    } else {
        p[6]++;
        func_001757E0(p, 0x16, 0x1B);
    }
}
