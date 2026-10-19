typedef unsigned char u8;
typedef float f32;
typedef unsigned int u32;

extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_002913F0(u8 *);

void func_00291370(u8 *p)
{
    p[6]++;
    func_00185490(p);
    func_00175C00(p, 1);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x210] = 0;
    p[0x20D] = 0;
    func_001757E0(p, 0x14, 2);
    func_002913F0(p);
}
