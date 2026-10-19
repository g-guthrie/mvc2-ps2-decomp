typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern void func_00176160(u8 *, int, int, int);

void func_001B5700(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    p[6]++;
    func_001757E0(p, 0x16, 0x39);
    p[0x24] = 7;
    func_00176160(q, 2, 12, 2);
    *(u32 *)(p + 0x118) = 0x3F000000;
    *(f32 *)(p + 0x50) = 0.3f + *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = 0.2f + *(f32 *)(q + 0x54);
    {
        int six = 6;
        *(u16 *)(p + 0x1C) = six;
    }
    *(u32 *)(p + 0x5C) = 0x3D23D70A;
    *(u32 *)(p + 0x68) = 0xBB83126F;
    *(u32 *)(p + 0x60) = 0x3D23D70A;
    *(u32 *)(p + 0x6C) = 0xBB83126F;
    *(u32 *)(p + 0x70) = 0xC0AB6DB6;
}
