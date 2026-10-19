typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern f32 func_001C3A20(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_001C2D30(u8 *, u8 *);

void func_001C2C70(u8 *p, u8 *q)
{
    f32 r;
    p[7]++;
    r = func_001C3A20(q, 0x30);
    {
        f32 z = 0.0f;
        if (*(f32 *)(p + 0x34) - r < z) {
        *(u16 *)(p + 0x140) = 1;
        *(u32 *)(p + 0x5C) = 0x40E2AAAA;
    } else {
        *(u16 *)(p + 0x140) = 0;
        *(u32 *)(p + 0x5C) = 0xC0E2AAAA;
    }
    *(u32 *)(p + 0x68) = 0;
    if (p[6] != p[0xD6])
        func_001757E0(p, 0x19, 5);
    }
    func_001C2D30(p, q);
}
