typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_0022A2C0(u8 *p)
{
    if (p[0x269] == 6) {
        p[0x404] = 255;
        p[0x405] = 16;
    }
    p[6]++;
    *(int *)(p + 0x5C) = 0;
    *(int *)(p + 0x60) = 0;
    *(int *)(p + 0x68) = 0;
    *(int *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    func_00183D10(p);
    *(u16 *)(p + 0x1C) = 0x20;
    *(u16 *)(p + 0x1E) = 6;
    {
        f32 vx = -5.833333015441895f;
        if (*(short *)(p + 0x140))
            vx = -vx;
        *(f32 *)(p + 0x5C) = vx;
    }
    func_001757E0(p, 22, 5);
}
