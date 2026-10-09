typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_003B38F0(u8 *, int, int);

void func_00301760(u8 *p)
{
    s16 timer;

    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        func_003B38F0(p, 1, 0);
    }
    timer = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = timer;
    if (timer == 0) {
        p[6]++;
        func_001757E0(p, 20, 0);
    }
}
