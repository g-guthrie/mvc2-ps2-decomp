typedef unsigned char u8;
typedef signed short s16;

extern void func_00175700(u8 *);
extern void func_00176160(u8 *, int, int);
extern void func_001757E0(u8 *, int, int);

void residual_0024F880(u8 *p)
{
    s16 v;

    func_00175700(p);
    v = *(s16 *)(p + 0x1C);
    if (v == 2) {
        p[6] += 3;
        p[0x168] = 2;
    } else if (v == 1) {
        p[6] += 2;
        p[0x168] = 1;
        func_00176160(p, 5, 0);
    } else if (v == 0) {
        p[6]++;
        p[0x168] = 0;
    }
    func_001757E0(p, 0x13, p[0x168]);
}
