typedef unsigned char u8;
typedef signed short s16;

extern int func_001757E0(u8 *, int, int);
extern void func_001AB500(u8 *, u8 *);

void func_001AB4A0(u8 *p, u8 *q)
{
    p[7]++;
    *(s16 *)(p + 320) = *(s16 *)(q + 320);
    func_001757E0(p, 23, 33);
    func_001AB500(p, q);
}
