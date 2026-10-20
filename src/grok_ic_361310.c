typedef unsigned char u8;
typedef signed char s8;

extern void (*D_00463500[])(u8 *, u8 *);
extern void func_00361880(u8 *);
extern void func_003610F0(u8 *, int, int);

void func_00361310(u8 *p, u8 *q)
{
    p[0x24] = *(s8 *)(q + 0x24);
    D_00463500[p[5]](p, q);
}

void func_00361340(u8 *p)
{
    func_00361880(p);
    func_003610F0(p, 2, 0);
    p[5]++;
}
