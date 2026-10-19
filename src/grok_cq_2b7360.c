typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_001830D0(u8 *, f32 *, int);

void func_002B7360(u8 *p)
{
    f32 v[3];
    u8 two = 2;

    p[0x40C] = two;
    p[0x33C] = 5;
    if (p[0x269] == 6)
        p[0x405] = two;
    else
        p[0x405] = 0;
    func_00175700(p);
    if ((s8)p[0x151] < 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        p[6]++;
        p[7] = 0;
        p[0x151] = 0;
        v[0] = -5.0f;
        *(u32 *)&v[1] = 0x4313DB6D;
        v[2] = 0.0f;
        func_001830D0(p, v, 3);
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        if (*(s16 *)(p + 0x140))
            *(u32 *)(p + 0x5C) = 0x40555555;
        else
            *(u32 *)(p + 0x5C) = 0xC0555555;
    }
}
