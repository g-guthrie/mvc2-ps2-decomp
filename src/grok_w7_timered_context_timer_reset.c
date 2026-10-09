typedef unsigned char u8;
typedef signed short s16;

extern void func_003031B0(u8 *);
extern int func_00175700(u8 *);

void func_003030D0(u8 *p, u8 *context)
{
    s16 timer;

    func_003031B0(p);
    func_00175700(p);
    timer = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = timer;
    if (timer == 0) {
        p[7]++;
        *(s16 *)(p + 0x1C) = 28;
        context[0] = 1;
    }
}
