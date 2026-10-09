typedef unsigned char u8;
typedef signed short s16;

extern int func_00175700(u8 *);

void func_00303CE0(u8 *p, void *context)
{
    u8 *q = context;
    s16 timer;

    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    timer = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = timer;
    if (timer == 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 10;
        q[6] = 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    }
}
