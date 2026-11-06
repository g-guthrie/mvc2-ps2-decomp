/* Candidate: func_0c09be48 passes the r13 zero to func_0c19d2ac (retail uses mov #0,r6) and schedules the tail call later; func_0c09bdf0 exact. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c148d54(struct Actor *, int, int);
extern void func_0c19d2ac(struct Actor *, int, int);

void func_0c09bdf0(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        func_0c148d54(a, 1, (a->s30 & 3) + 0x80);
        func_0c19d2ac(a, 6, a->s30 & 3);
        a->s30++;
    }
}

void func_0c09be48(register struct Actor *a)
{
    register void *zero;
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if (a->b141) {
        zero = 0;
        a->b3f9 = (int)zero;
        a->b3f8 = (int)zero;
        a->b327 = (int)zero;
        a->b328 = (int)zero;
        a->b6++;
        a->b141 = (int)zero;
        a->b1f9 = 2;
        a->f92 = a->b1d2 ? -10.0f : 10.0f;
        a->f104 = 0.0f;
        a->f96 = 9.642857f;
        a->f108 = -0.80357140303f;
        func_0c19d2ac(a, 14, (int)zero);
    }
}
