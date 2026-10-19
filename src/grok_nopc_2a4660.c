typedef unsigned char u8;
typedef float f32;
typedef unsigned int u32;

extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_002A4660(u8 *p)
{
    p[6]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_00183D10(p);
    func_001757E0(p, 0x15, 0x18);
}
