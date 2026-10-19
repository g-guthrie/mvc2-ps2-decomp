typedef unsigned char u8;
typedef signed char s8;

extern int func_00175910(u8 *, int, int, int);
extern void func_00388F60(u8 *, u8 *);

void func_00388F00(u8 *p, u8 *q)
{
    p[7]++;
    func_00175910(p, 22, 13, (s8)p[337]);
    func_00388F60(p, q);
}
