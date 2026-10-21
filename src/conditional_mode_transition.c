typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern void func_003031B0(u8 *);
extern int func_00175700(u8 *);
extern void func_001D9D80(u8 *, int, int);

void func_00303000(u8 *p, u8 *context)
{
    func_003031B0(p);
    func_00175700(p);
    if (*(s8 *)(p + 337) != 0) {
        p[7]++;
        *(s16 *)(p + 28) = 10;
        func_001D9D80(p, 2, 1);
    }
}
