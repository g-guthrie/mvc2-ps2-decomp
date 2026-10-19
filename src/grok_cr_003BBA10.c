typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_003BD840(u8 *);
extern void func_003BD290(u8 *);
extern void func_001757E0(u8 *, int, int);
extern u8 *D_004C2794;

void residual_003BBA10(u8 *p)
{
    u8 *s0;
    f32 f1;
    f32 f2;
    p[4]++;
    p[5] = 0;
    p[6] = 0;
    s0 = *(u8 **)(p + 0x18);
    func_003BD840(p);
    *(f32 *)(p + 0x34) = *(f32 *)(s0 + 0x34);
    *(u32 *)&f2 = 0x40555555;
    *(u32 *)&f1 = 0x42D55555;
    *(s16 *)(p + 0x1C) = 0x60;
    if (!s0[0x1E6]) {
        f1 = -f1;
        f2 = -f2;
    }
    *(f32 *)(p + 0x34) += f1;
    *(f32 *)(p + 0x5C) = f2;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_003BD290(p);
    p[0x1B5] = 0x15;
    *(u16 *)(p + 0x1C0) = 0;
    p[0x1B2] = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 0x19, 0xD);
}
