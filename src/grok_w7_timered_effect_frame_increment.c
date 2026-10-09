typedef unsigned char u8;
typedef signed short s16;

extern void func_003031B0(u8 *);
extern int func_00175700(u8 *);
extern void func_003B10B0(u8 *, int, int);

void func_00303060(u8 *p)
{
    s16 timer;

    func_003031B0(p);
    func_00175700(p);
    timer = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = timer;
    if (timer == 0) {
        p[7]++;
        func_003B10B0(p, 0, 1);
    }
}
