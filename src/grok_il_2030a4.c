typedef unsigned char u8;
typedef signed char s8;

extern void func_00186A60(u8 *, int);

void residual_002030B0(u8 *p)
{
    s8 v;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    v = *(s8 *)(p + 1245);
    switch (v) {
    case 0:
        p[509] = 9;
        break;
    case 1:
        p[509] = 7;
        break;
    case 2:
        p[509] = 9;
        break;
    }
    func_00186A60(p, 29);
}
