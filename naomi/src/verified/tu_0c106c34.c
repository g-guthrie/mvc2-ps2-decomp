/* Four actor callbacks and a shared pool. The active handler uses the retail
 * 5/3 and 15/7 float words before the optional facing flip. */
#include "objects.h"
typedef void (*Handler_106c34)(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern Handler_106c34 table_0c24b53c[];
extern Handler_106c34 table_0c24b548[];

void func_0c106c34(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->b19e) {
        a->b7++;
        func_0c02a0c4(a, 20, 5);
        a->f92 = 6.66666651f;
        a->f104 = -0.0520833321f;
        a->f96 = 12.85714245f;
        a->f108 = -0.80357140303f;
        if (a->w130) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
    }
}

void func_0c106cce(struct Actor *a)
{
    func_0c02a026(a);
}

void func_0c106cd4(struct Actor *a)
{
    table_0c24b53c[a->b7](a);
}

void func_0c106ce6(struct Actor *a)
{
    table_0c24b548[a->b6](a);
}
