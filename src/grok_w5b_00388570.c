typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;

extern void func_00175910(u8 *, int, int, int);
extern void func_003885F0(u8 *, u8 *);

void residual_00388570(u8 *p, u8 *q)
{
    p[5]++;
    *(s16 *)(p + 0x1C) = 16;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0xBE892492;
    if (*(u32 *)(p + 0xD8))
        func_00175910(p, 23, 9, 4);
    func_003885F0(p, q);
}
