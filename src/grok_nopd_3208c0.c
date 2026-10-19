typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern void func_00185490(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_003208C0(u8 *p)
{
    p[6]++;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 0x430);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_00185490(p);
    func_001757E0(p, 20, 0);
}
