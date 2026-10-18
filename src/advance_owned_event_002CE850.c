typedef unsigned char u8;
typedef signed char s8;
extern void func_002CE6E0(u8 *);
extern void func_00175700(void);
extern void func_0039BC20(u8 *, int);
void func_002CE850(u8 *p)
{
    func_002CE6E0(p);
    func_00175700();
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        p[6]++;
        func_0039BC20(p, 1);
    }
}
