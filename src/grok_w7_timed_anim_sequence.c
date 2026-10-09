typedef unsigned char u8;
typedef signed short s16;
extern void *func_003B5A40(u8 *, int);
extern void func_001E3210(u8 *, int);
extern int func_001757E0(u8 *, int, int);
void func_00307AD0(u8 *p, void *context)
{
    s16 timer;
    p[0x40C] = 2;
    p[0x33C] = 5;
    timer = *(s16 *)(p + 0x1C);
    timer--;
    *(s16 *)(p + 0x1C) = timer;
    if (timer != 0)
        return;
    if (func_003B5A40(p, 2) != 0) {
        func_001E3210(p, 47);
        timer = *(s16 *)(p + 0x1E);
        timer--;
        *(s16 *)(p + 0x1E) = timer;
        if (timer == 0) {
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            p[6]++;
            func_001757E0(p, 22, 4);
        }
    }
    *(s16 *)(p + 0x1C) = 30;
}
