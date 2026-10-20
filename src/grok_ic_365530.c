typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern void func_003655C0(u8 *);

void residual_00365530(u8 *p)
{
    p[5]++;
    *(f32 *)(p + 0x5C) = *(s16 *)(p + 0x140) ? -1.6666666269302368f : 1.6666666269302368f;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x414DB6DB;
    *(u32 *)(p + 0x6C) = 0xBFCDB6DB;
    func_001757E0(p, 0x17, 3);
    func_003655C0(p);
}
