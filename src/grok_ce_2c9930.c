typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00175700(u8 *);

void func_002C9930(u8 *p, u8 *q)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((*(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1) >= 0)
        return;
    func_00175700(p);
    if (*(s8 *)(p + 0x161) == 0)
        return;
    p[6]++;
    p[0x20D] = 2;
    q[2] = 0;
    if (p[0x1E6])
        *(f32 *)(p + 0x5C) = 13.33333301544189453125f;
    else
        *(f32 *)(p + 0x5C) = -13.33333301544189453125f;
    if (p[0x1E6])
        *(f32 *)(p + 0x68) = -0.3125f;
    else
        *(f32 *)(p + 0x68) = 0.3125f;
    *(u32 *)(p + 0x60) = 0x40CDB6DB;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
}
