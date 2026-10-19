typedef unsigned char u8;
typedef signed short s16;

extern void func_0015E630(u8 *);
extern int func_00175700(u8 *);

void func_003572E0(u8 *p)
{
    s16 v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v <= 0) {
        p[5]++;
        p[0] = 1;
        func_0015E630(p);
    }
    func_00175700(p);
}
