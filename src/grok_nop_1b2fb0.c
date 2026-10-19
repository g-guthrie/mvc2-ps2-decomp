typedef unsigned char u8;
typedef signed short s16;

extern void func_001B2FF0(u8 *);

void residual_001B2FB0(u8 *p)
{
    s16 t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t <= 0) {
        p[5]++;
        func_001B2FF0(p);
    }
}
