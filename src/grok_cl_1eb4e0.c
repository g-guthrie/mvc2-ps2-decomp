typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_0018C4B0(u8 *, s32);
extern void func_00186A20(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern u8 *D_004C2794;

void residual_001EB4E0(u8 *p)
{
    f32 spd;
    p[6]++;
    func_00185490(p);
    func_00183D10(p);
    func_0018C4B0(p, 0xA);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x1B5] = (s8)p[0x1B7] + 0x39;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    {
        u32 bits = 0x41092492;
        *(u32 *)(p + 0x60) = bits;
        bits = 0xBF4DB6DB;
        *(u32 *)(p + 0x6C) = bits;
    }
    func_00186A20(p);
    if (p[0x1B7]) {
        u32 bits = 0x40C80000;
        spd = *(f32 *)&bits;
    } else {
        u32 bits = 0x40855555;
        spd = *(f32 *)&bits;
    }
    if (p[0x1E6])
        *(f32 *)(p + 0x5C) = spd;
    else
        *(f32 *)(p + 0x5C) = -spd;
    *(u32 *)(p + 0x68) = 0;
    func_001757E0(p, 0x15, 4);
}
