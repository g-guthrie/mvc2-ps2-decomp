typedef unsigned char u8;
typedef signed char s8;
static void func_002CE6E0(u8 *p) {
    *(float *)(p + 52) += *(float *)(p + 92);
    *(float *)(p + 92) += *(float *)(p + 104);
    *(float *)(p + 56) += *(float *)(p + 96);
    *(float *)(p + 96) += *(float *)(p + 108);
    if (*(float *)(p + 56) <= *(float *)(p + 1072))
        *(float *)(p + 56) = *(float *)(p + 1072);
}
extern int func_00175700(u8 *);
extern void func_0039BC20(u8 *, int);
void func_002CE850(u8 *p)
{
    func_002CE6E0(p);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        p[6]++;
        func_0039BC20(p, 1);
    }
}
