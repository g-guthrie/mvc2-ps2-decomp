/* Actor timer and animation callbacks, reviewed 280-byte span. */
#include "objects.h"
extern void func_0c0344a0(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c173868(struct Actor *);
extern int func_0c047bbe(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c10c188(struct Actor *);
extern void (*dat_0c24b974[])(struct Actor *);
void func_0c10a598(struct Actor *a)
{
    *(int *)&a->pad10c[40] = 4;
    if (--*(int *)&a->pad10c[12] < 0) {
        *(int *)&a->pad10c[12] = 16;
        func_0c0344a0(a, 3);
    }
    (void)func_0c02a026(a);
    if (a->b14b) {
        a->b1a1 = a->b14b + *(unsigned char *)((char *)a + 0x2c0);
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->b14b = 0;
    }
    if ((signed char)a->b141 < 0) {
        a->b141 = 0;
        func_0c173868(a);
    }
    if (!func_0c047bbe(a) || a->b525) {
        if (--a->s28 == 0) {
            a->b6++;
            func_0c02a0c4(a, 21, a->b158 + 1);
        }
    } else {
        a->s28 = 30;
    }
}
void func_0c10a64e(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c10c188(a);
}
void func_0c10a670(struct Actor *a)
{
    dat_0c24b974[a->b6](a);
}
