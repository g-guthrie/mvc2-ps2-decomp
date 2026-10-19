typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_003A8B10(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_002F01E0(u8 *);

void residual_002F0110(u8 *p)
{
    p[6]++;
    p[0x1B5] = 0x35;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_00183D10(p);
    p[0x20D] = 0;
    p[0x20] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    {
        u32 bits = 0xC0D55555;
        f32 v = *(f32 *)&bits;
        if (p[0x1E6])
            v = -v;
        *(f32 *)(p + 0x5C) = v;
    }
    *(u32 *)(p + 0x68) = 0;
    func_001757E0(p, 0x15, 0xB);
    *(u32 *)(p + 0x2EC) = (s8)p[0x152];
    func_003A8B10(p);
    func_0018C4B0(p, 0xA);
    func_002F01E0(p);
}
