typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_001757E0(u8 *, int, int);
extern void func_001AD1E0(u8 *, int, int);
extern void func_00365E30(u8 *);

void func_00365D80(u8 *p)
{
    {
        f32 v;
        p[5]++;
        if (*(s16 *)(p + 0x140))
            v = 0.625f;
        else
            v = -0.625f;
        *(f32 *)(p + 0x5C) = v;
    }
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x40092492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    func_001757E0(p, 0x17, 7);
    func_001AD1E0(p, 0x11, 1);
    func_001AD1E0(p, 0x11, 1);
    func_00365E30(p);
}
