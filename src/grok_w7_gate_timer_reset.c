typedef unsigned char u8;
typedef signed short s16;

extern int func_00175700(u8 *);
extern int func_0018AB10(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_003071C0(u8 *p, u8 *context)
{
    s16 timer;

    context[10] = 3;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (func_0018AB10(p) != 0)
        return;

    timer = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = timer - 1;
    if (timer == 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[6]++;
        func_001757E0(p, 22, 2);
    }
}
