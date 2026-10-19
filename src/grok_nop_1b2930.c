typedef unsigned char u8;
typedef signed short s16;

extern int func_00175670(u8 *);

void func_001B2930(u8 *p)
{
    s16 timer;

    func_00175670(p);
    timer = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = timer - 1;
    if (timer == 0) {
        p[5]++;
        *(s16 *)(p + 28) = 8;
    }
}
