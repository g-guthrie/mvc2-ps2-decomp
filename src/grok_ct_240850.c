typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_00240850(u8 *p)
{
    int s0 = 2;
    int s2 = 0x2D;
    p[6]++;
    *(u16 *)(p + 0x1C) = 1;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_00185490(p);
    func_0018C4B0(p, 5);
    if (p[0x20D] != 2) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        s0 = 0;
        s2 = 0x28;
        p[0x20D] = 0;
        func_00183D10(p);
    }
    p[0x1B5] = s2;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    {
        unsigned int offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    }
    func_001757E0(p, 0x15, (s0 + p[0x1B7]) & 0xFF);
}
