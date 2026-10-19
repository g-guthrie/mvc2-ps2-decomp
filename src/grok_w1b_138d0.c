typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00213970(u8 *);

void residual_002138D0(u8 *p)
{
    p[6]++;
    *(s16 *)(p + 0x1C) = 28;
    func_00185490(p);
    func_0018C4B0(p, 10);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x5C) = 0x413AAAAA;
    if (p[0x1E6] == 0)
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    func_00183D10(p);
    func_001757E0(p, 0x0F, 0x0A);
    func_00213970(p);
}
