typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00176160(u8 *, int, int, int);
extern void func_003B79A0(u8 *);
void func_0030B1A0(u8 *p)
{
    s16 timer;
    int one = 1;
    func_00175700(p);
    timer = *(s16 *)(p + 0x1C);
    timer--;
    *(s16 *)(p + 0x1C) = timer;
    if (timer != 0) {
        if (*(s8 *)(p + 0x151) == 0)
            return;
        p[0x151] = 0;
        func_00176160(p, one, 5, one);
        func_003B79A0(p);
        return;
    }
    p[6]++;
    func_001757E0(p, 21, 2);
}
