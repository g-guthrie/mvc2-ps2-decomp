typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_001A3A10(u8 *, int, int);
extern void func_001E3210(u8 *, int);
extern void func_00186A20(u8 *);
extern f32 D_004528D0[];

void func_00240930(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0)
        return;
    p[6]++;
    if (p[0x20D] != 2)
        func_001A3A10(p, 1, 0);
    {
        f32 d;
        *(u32 *)&d = 0xC2555555;
        if (p[0x1E6])
            d = -d;
        *(f32 *)(p + 0x34) += d;
    }
    {
        f32 *tbl = &D_004528D0[0];
        if (p[0x20D] == 2)
            tbl = &D_004528D0[4];
        tbl = (f32 *)((u8 *)tbl + (p[0x1B7] * 8));
        *(f32 *)(p + 0x5C) = tbl[0];
        *(f32 *)(p + 0x60) = tbl[1];
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0xBFCDB6DB;
        if (p[0x1E6])
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
    func_001A3A10(p, 0, 0);
    func_001E3210(p, 0x14);
    func_00186A20(p);
}
