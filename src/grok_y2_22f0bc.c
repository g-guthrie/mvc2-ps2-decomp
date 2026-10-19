typedef unsigned char u8;

extern int func_00175700(u8 *);
extern void func_003D92F0(u8 *);

void func_0022F100(u8 *p)
{
    p[0x33A] = 0xFF;
    func_003D92F0(p);
    func_00175700(p);
}
