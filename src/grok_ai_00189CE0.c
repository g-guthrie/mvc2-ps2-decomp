typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004BF514[];
extern void func_0018A920(u8 *, u8 *);

u8 func_00189CE0(u8 *a, u8 *b, u8 *c)
{
    s8 v;
    s32 t;
    u8 n;
    u8 look;
    v = (s8)c[1] - 1;
    c[1] = v;
    if (v <= 0)
        return c[0] = 0;
    t = (u16)((*(u16 *)(a + 0x35E) & 0x3C00) >> 10);
    if (t != 0) {
        u32 dir = (u16)t;
        n = c[3];
        look = D_004BF514[(n + 1) & 3];
        if (dir == look)
            c[4] = 1;
        else if (dir == D_004BF514[look & 3])
            c[4] = 0xFF;
        else
            return 0;
        c[0]++;
        c[2]--;
        c[3] = ((s8)c[3] + (s8)c[4]) & 3;
        func_0018A920(a, c);
    }
    return 0;
}
