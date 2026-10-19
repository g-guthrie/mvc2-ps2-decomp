typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00185490(void *);
extern void func_0018C4B0(void *, int);
extern void func_00183D10(void *);
extern int func_001757E0(void *, int, int);
extern void func_00213970(u8 *);

void func_002138D0(u8 *p)
{
    p[6]++;
    *(s16 *)(p + 0x1C) = 0x1C;
    func_00185490(p);
    func_0018C4B0(p, 0xA);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x5C) = 0x413AAAAA;
    if (p[0x1E6] == 0)
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    func_00183D10(p);
    func_001757E0(p, 0xF, 0xA);
    func_00213970(p);
}
