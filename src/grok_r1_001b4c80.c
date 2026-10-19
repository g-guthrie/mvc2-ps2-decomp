typedef unsigned char u8;
typedef signed short s16;

extern void func_001B5350(u8 *, u8 *);
extern void func_001B4C00(u8 *, u8 *);
extern int func_001754A0(u8 *, int, int);
extern void func_001B4BD0(u8 *);

void residual_001B4C80(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    p[6] = 2;
    p[0x13C] = 1;
    if (p[0x22] & 1)
        *(s16 *)(q + 0x140) ^= 1;
    func_001B5350(q, p);
    if (p[0x22] & 1)
        *(s16 *)(q + 0x140) ^= 1;
    func_001B4C00(q, p);
    func_001754A0(p, 0x1B, p[0x20]);
    func_001B4BD0(p);
}
