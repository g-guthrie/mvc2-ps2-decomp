/* Four actor state callbacks and their shared pool. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c17ed28(struct Actor *, int, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *), func_0c0438de(struct Actor *);
extern void (*dat_0c24d0d4[])(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *), func_0c0432ca(struct Actor *);
void func_0c11de58(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->b328 = 5;
    func_0c02a026(a);
    if (--a->s28 != 0) {
        if (--a->s30 == 0) {
            a->s30 = 4;
            if (a->b1f9 != 2)
                func_0c17ed28(a, 10, 0);
            else
                func_0c17ed28(a, 11, 0);
        }
    } else {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        a->b6++;
        func_0c02a0c4(a, 22, a->b1f9 == 2 ? 16 : 14);
    }
}
void func_0c11dee6(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        if (a->b1f9 == 2)
            func_0c0438de(a);
        else
            func_0c0437b8(a);
    }
}
void func_0c11df1a(struct Actor *a)
{
    dat_0c24d0d4[a->b6](a);
}
void func_0c11df2c(struct Actor *a)
{
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c02a39a(a, 0);
    func_0c0442fa(a);
    func_0c0432ca(a);
    func_0c02a0c4(a, 21, 26);
}
