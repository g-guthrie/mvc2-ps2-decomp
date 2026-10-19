typedef unsigned char u8;

extern void func_001345B0(u8 *);
extern void func_00134120(u8 *, u8 *);

void func_00134150(u8 *p, u8 *a1)
{
    if (p[5] == 0) {
        p[5] = 1;
        func_001345B0(p);
    }
    func_00134120(p, a1);
}
