typedef unsigned char u8;
typedef signed short s16;

extern int func_00175670(u8 *);

void residual_001B2930(u8 *p)
{
    s16 t;

    func_00175670(p);
    t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t == 0) {
        p[5]++;
        *(s16 *)(p + 28) = 8;
    }
}
