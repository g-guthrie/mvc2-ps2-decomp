typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);

void residual_002986A0(u8 *p)
{
    f32 vx, vy;
    p[6]++;
    func_00185490(p);
    func_0018C4B0(p, 2);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    *(s16 *)(p + 0x1C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (p[0x212])
        vx = -16.666666030883789f;
    else
        vx = -23.333332061767578f;
    if (p[0x212])
        vy = 0.67708331346511841f;
    else
        vy = 0.78125f;
    if (p[0x1E6])
        *(f32 *)(p + 0x5C) = vx;
    else
        *(f32 *)(p + 0x5C) = -vx;
    if (p[0x1E6])
        *(f32 *)(p + 0x68) = vy;
    else
        *(f32 *)(p + 0x68) = -vy;
    {
        s32 a = 0x15;
        func_001757E0(p, a, a);
    }
}
