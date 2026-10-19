typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_002C83E0(u8 *p)
{
    p[6]++;
    func_0018C4B0(p, 2);
    func_00185490(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (p[0x20D] != 2) {
        func_00183D10(p);
    }
    func_001757E0(p, 21, 5);
}
