typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001E3210(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);

void residual_0029FF20(u8 *p)
{
    p[6]++;
    *(s16 *)(p + 0x1C) = 21;
    func_001E3210(p, 43);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x210] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    func_00185490(p);
    func_00175C00(p, 0);
    func_0018C4B0(p, 5);
    *(u32 *)(p + 0x5C) = 0xC1055555;
    if (*(s16 *)(p + 0x140))
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    p[0x209] = 2;
    p[0x20D] = 1;
    func_001757E0(p, 21, 11);
}
