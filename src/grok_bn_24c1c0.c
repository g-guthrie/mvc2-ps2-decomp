typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00176160(u8 *, int, int, int);
extern void func_001757E0(u8 *, int, int);
extern void func_00183D10(u8 *);
extern void func_0024C2C0(u8 *);

void residual_0024C1C0(u8 *p)
{
    u8 *q = p + 0x2B8;
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    *(u32 *)(p + 0x2F8) = 0;
    func_00185490(p);
    func_00175C00(p, 0);
    func_00176160(p, 5, 2, 1);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    q[7] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x210] = 0;
    p[0x20D] = 0;
    p[0x1B5] = 0x3D;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    {
        unsigned int offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    }
    func_001757E0(p, 0x16, 1);
    func_00183D10(p);
    func_0024C2C0(p);
}
