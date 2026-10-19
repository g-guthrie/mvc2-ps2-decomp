typedef unsigned char u8;
typedef signed short s16;

extern void func_001757E0(u8 *, int, int);
extern void func_00291BB0(u8 *, u8 *);

void residual_00291B40(u8 *p, u8 *q)
{
    q[0x18]++;
    *(s16 *)(p + 0x1C) = 6;
    q[0x19] = 0;
    *(int *)(p + 0x5C) = 0;
    *(int *)(p + 0x68) = 0;
    func_001757E0(p, 22, 8);
    func_00291BB0(p, q);
}
