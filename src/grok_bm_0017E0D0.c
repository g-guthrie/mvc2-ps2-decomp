typedef unsigned char u8;
typedef float f32;

extern void func_00175700(u8 *);

void func_0017E0D0(u8 *p)
{
    u8 k = (*(u8 **)(p + 0x1DC))[1];
    if (k == 0x2C || k == 0x31)
        return;
    if (k == 0x36)
        func_00175700(p);
    else if (k == 0x10)
        func_00175700(p);
    p[0x209] = 0;
    if (p[0x20D] != 2)
        return;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
    }
}
