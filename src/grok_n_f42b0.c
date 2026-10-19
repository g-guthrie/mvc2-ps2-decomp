typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001F0420(u8 *);
extern int func_001757E0(u8 *, int, int);
extern u8 *D_004C2794;

void residual_001F42B0(u8 *p)
{
    p[6]++;
    p[0x1B5] = 0x37;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001F0420(p);
    *(u32 *)(p + 0x5C) = 0x40855555;
    *(u32 *)(p + 0x68) = 0;
    if (p[0x1E6] == 0)
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    func_001757E0(p, 0x15, 8);
}
