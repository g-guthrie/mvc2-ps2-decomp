typedef unsigned char u8;
typedef float f32;
typedef unsigned int u32;

extern void func_00175C00(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_00290890(u8 *);

void residual_00290820(u8 *p)
{
    p[7]++;
    func_00175C00(p, 0);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x210] = 0;
    p[0x20D] = 0;
    func_001757E0(p, 0x13, 4);
    func_00290890(p);
}
