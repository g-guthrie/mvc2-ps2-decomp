typedef unsigned char u8;
typedef signed short s16;
typedef signed char s8;

extern int func_001757E0(u8 *, int, int);
extern void func_001AC050(u8 *, u8 *);

void residual_001ABFF0(u8 *p, u8 *q)
{
    p[7]++;
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
    func_001757E0(p, 0x17, (u8)((s8)q[0x1E7] + 4));
    func_001AC050(p, q);
}
