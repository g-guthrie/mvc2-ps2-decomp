#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24ad68[];
extern ActorHandler table_0c24ad74[];
extern float dat_0c24abfc[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0451f2(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c0fdfe4(struct Actor *a)
{
    table_0c24ad68[a->b6](a);
}

void func_0c0fdff6(struct Actor *a)
{
    float stopped = 0.0f;
    int zero = 0;
    a->b6++;
    a->f56 = a->f41c;
    a->f92 = stopped;
    a->f96 = stopped;
    a->f104 = stopped;
    a->f108 = stopped;
    a->b1a1 = 51;
    a->w1ac = zero;
    a->b19e = zero;
    *(unsigned int *)&a->p1c4 = zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    func_0c0432ca(a);
    func_0c048bb0(a, 5);
    func_0c02a0c4(a, 21, 6);
}

void func_0c0fe064(struct Actor *a)
{
    table_0c24ad74[a->b7](a);
}

void func_0c0fe076(struct Actor *a)
{
    int zero = 0;
    func_0c02a026(a);
    if (a->b141)
    {
        a->b7++;
        a->b141 = zero;
        func_0c0451f2(a);
        a->f92 = dat_0c24abfc[(unsigned char)a->b1a3];
        a->f104 = 0.0f;
        a->f96 = 25.714285f;
        a->f108 = -1.33928561211f;
        if (a->b1d2)
            a->f92 = -a->f92;
    }
}
