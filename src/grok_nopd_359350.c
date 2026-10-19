typedef unsigned char u8;
typedef signed char s8;

extern void func_0019DF50(u8 *, int, int);
extern void func_0035A820(u8 *, u8 *);

void residual_00359350(u8 *p, u8 *q)
{
    u8 *r = *(u8 **)(p + 24);

    if ((s8)r[337] < 0) {
        r[337] = 1;
        func_0019DF50(p, 3, 1);
    }
    func_0035A820(p, q);
}
