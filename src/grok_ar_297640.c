typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_0018C4B0(u8 *, s32);
extern void func_00186A20(u8 *);
extern void func_001757E0(u8 *, s32, s32);

void residual_00297640(u8 *p)
{
    f32 d;
    p[6]++;
    func_00185490(p);
    func_00183D10(p);
    func_0018C4B0(p, 8);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x1B5] = (u8)(*(s8 *)(p + 0x1B7) + 0x3A);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    *(u32 *)(p + 0x60) = 0x40CDB6DB;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    func_00186A20(p);
    if (p[0x1B7])
        d = 6.25f;
    else
        d = 4.166666507720947f;
    if (p[0x1E6])
        *(f32 *)(p + 0x5C) = d;
    else
        *(f32 *)(p + 0x5C) = -d;
    *(u32 *)(p + 0x68) = 0;
    func_001757E0(p, 0x15, 4);
}
