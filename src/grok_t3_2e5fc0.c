typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern int func_00175700(u8 *);
extern void func_003A38B0(u8 *);
extern s16 D_004C27A4;

void residual_002E5FC0(u8 *p, u8 *q)
{
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        {
            s16 g = D_004C27A4;
            if (g >= 7) {
                p[7]++;
                q[2] = 0;
                q[4] = 6;
                func_003A38B0(p);
            } else
                p[6] = 2;
            (void)g;
        }
    }
}
