typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_00154790(f32 *, s16, int, int);
extern void func_001E3B70(u8 *, int);

void residual_002D5D30(u8 *p)
{
    f32 v[3];
    u8 *q;

    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0)
        return;
    p[0x151] = 0;
    p[6]++;
    {
        u32 bits = 0x432B6DB6;
        v[1] = *(f32 *)&bits + *(f32 *)(p + 0x38);
    }
    {
        u32 bits = 0xC2555555;
        if (p[0x1E6])
            bits = 0x42555555;
        *(u32 *)&v[0] = bits;
    }
    v[0] += *(f32 *)(p + 0x34);
    func_00154790(v, *(s16 *)(p + 0x140), 1, 0);
    func_001E3B70(*(u8 **)(p + 0x1DC), 0);
    q = *(u8 **)(p + 0x1DC);
    *(u8 **)(q + 0x1C8) = p;
    q[0x20A] = 1;
    q[0x1B5] = 0x22;
    *(u32 *)(p + 0x60) = 0x41BC9249;
    *(u32 *)(p + 0x6C) = 0xBF700000;
    {
        u32 bits = 0x40855555;
        if (p[0x1E6])
            bits = 0xC0855555;
        *(u32 *)(p + 0x5C) = bits;
    }
}
