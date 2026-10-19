typedef unsigned char u8;
typedef signed short s16;
typedef signed char s8;

extern void func_0035AE70(u8 *);
extern void func_0035ACA0(u8 *, u8 *);

void func_0035A500(u8 *p, u8 *q)
{
    s16 t;

    t = *(s16 *)(p + 28);
    t = t - 1;
    *(s16 *)(p + 28) = t;
    if (t == 0) {
        p[33] = 9;
        func_0035AE70(p);
        func_0035ACA0(p, q);
    }
}
