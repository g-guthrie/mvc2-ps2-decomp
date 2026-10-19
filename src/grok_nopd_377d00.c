typedef unsigned char u8;
typedef signed char s8;

extern int func_00175910(u8 *, int, int, int);
extern void func_00178F20(u8 *, u8 *);

void func_00377D00(u8 *p, u8 *q)
{
    {
        s8 v = *(s8 *)(q + 337);

        if (v != p[32]) {
            p[32] = v;
            func_00175910(p, 15, 2, p[32] - 1);
        }
    }
    func_00178F20(p, *(u8 **)(p + 480));
    if ((s8)p[337] != 0 || q[484] != 29)
        p[6]++;
}
