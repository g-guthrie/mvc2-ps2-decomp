typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00126400(int);
extern void func_0022C580(u8 *);

void func_0022C070(u8 *p)
{
    u8 *q;
    func_00175700(p);
    if ((s8)p[0x151] == 0)
        return;
    q = *(u8 **)(p + 0x1DC);
    *(u8 **)(q + 0x1C8) = p;
    q[0x20A] = 1;
    q[0x20D] = 2;
    q[0x1E6] = p[0x1E6];
    {
        int st = 0x20;
        if (*(int *)(p + 0x2D0) != 0)
            st = 0x24;
        q[0x1B5] = (u8)st;
    }
    p[6]++;
    p[0x151] = 0;
    p[0x1E6] ^= 1;
    *(s16 *)(p + 0x140) ^= 1;
    *(int *)(p + 0x5C) = 0;
    *(int *)(p + 0x60) = 0;
    *(int *)(p + 0x68) = 0;
    *(int *)(p + 0x6C) = 0;
    *(unsigned int *)(p + 0x6C) = 0xBF4DB6DB;
    func_00126400((int)q);
    func_0022C580(p);
}
