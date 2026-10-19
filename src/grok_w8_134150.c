typedef unsigned char u8;

extern void func_001345B0(u8 *);
extern void func_00134120(u8 *, u8 *);

void func_00134150(u8 *p, u8 *q)
{
    unsigned r = 0;

    if (p[5] == r) {
        p[5] = r + 1;
        func_001345B0(p);
    }
    func_00134120(p, q);
}
