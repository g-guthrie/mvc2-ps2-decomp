typedef unsigned char u8;
typedef signed short s16;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_00302E50(u8 *p, u8 *context)
{
    s16 timer;

    func_00175700(p);
    timer = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = timer;
    if (timer == 0) {
        p[7]++;
        context[0] = 1;
        func_001757E0(p, 21, (u8)(p[0x1B7] + 2));
    }
}
