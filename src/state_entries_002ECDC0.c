typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern void func_00185490(void *);
extern void func_00175C00(void *, int);
extern int func_001757E0(void *, int, int);
extern void func_002ECE40(u8 *, u8 *);

void func_002ECDC0(u8 *p, u8 *q)
{
    p[6]++;
    func_00185490(p);
    func_00175C00(p, 0);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    func_001757E0(p, 0x14, 3);
    func_002ECE40(p, q);
}
