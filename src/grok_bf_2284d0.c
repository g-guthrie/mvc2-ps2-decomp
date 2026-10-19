typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void residual_002284D0(u8 *p)
{
    p[6]++;
    func_00185490(p);
    if (p[0x20D] != 2) {
        p[0x20D] = 0;
        func_00183D10(p);
    }
    func_0018C4B0(p, 1);
    *(u32 *)(p + 0x2D0) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    {
        u32 a = 0xC1855555;
        u32 b = 0x3EA00000;
        f32 f0 = *(f32 *)&a;
        f32 f1 = *(f32 *)&b;
    if (p[0x1E6]) {
        f0 = -f0;
        f1 = -f1;
    }
        *(f32 *)(p + 0x5C) = f0;
        *(f32 *)(p + 0x68) = f1;
    }
    func_001757E0(p, 0x15, 0x16);
}
