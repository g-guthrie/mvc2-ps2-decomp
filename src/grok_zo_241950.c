typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern int func_0035EAE0(u8 *);

void residual_00241950(u8 *p, u8 *q)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[7]++;
        q[3] = 1;
        if (!func_0035EAE0(p)) {
            p[6] = 2;
            p[7] = 0;
        }
    }
}
