typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);

void residual_00215490(u8 *p)
{
    f32 *ax;
    f32 *vx;
    ax = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    vx = (f32 *)(p + 0x5C);
    *vx += *ax;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if ((s8)p[0x151] == 2) {
        p[6]++;
        *vx = 0;
        *ax = 0;
        *(int *)(p + 0x60) = 0xC0CDB6DB;
        *(int *)(p + 0x6C) = 0xBF4DB6DB;
    }
}
