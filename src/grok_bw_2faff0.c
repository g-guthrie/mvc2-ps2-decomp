typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_003B0860(u8 *, int, int);
extern void func_001E3210(u8 *, int);

void func_002FAFF0(u8 *p)
{
    int i;
    s16 t;

    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_001843A0(p);
        return;
    }
    if (*(s16 *)(p + 0x1E) == 0)
        return;
    t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = (s16)(t - 1);
    if (t != 0)
        return;
    *(s16 *)(p + 0x1C) = 0x1E;
    *(s16 *)(p + 0x1E) -= 1;
    i = 0;
    do {
        func_003B0860(p, 0, i);
        i++;
    } while (i < 6);
    func_001E3210(p, 0x22);
}
