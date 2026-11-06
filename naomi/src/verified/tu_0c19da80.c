/* Four linked-actor callbacks and their shared pool. The two long handlers
 * reuse the same structure and 0xc0-byte copy as tu_0c19dd70. */
#include "objects.h"
typedef void (*Handler_19da80)(struct LinkedActor *);
extern char func_0c029fc4(struct LinkedActor *);
extern void func_0c19ee84(struct LinkedActor *);
extern Handler_19da80 table_0c258a6c[];
extern void func_0c029e70(struct LinkedActor *, int, int);
extern short *dat_0c2fb3e8;

void func_0c19da80(struct LinkedActor *a)
{
    a->b4++;
    a->sdc = a->p24->sdc;
    a->sdc.b12c = 1;
    a->b2 = a->p24->b2;
    a->b1 = a->p24->b1;
    a->v80.x = a->p24->v80.x;
    a->v80.y = a->p24->v80.y;
    a->b1a3 = a->p24->b1a3;
    a->b1a4 = a->p24->b1a4;
    a->b48 = a->p24->b48;
    a->v80 = a->p24->v80;
    a->b36 = a->p24->b36;
    a->b36 = 11;
    a->f52 = a->p20->f52;
    a->f56 = a->p20->f56;
    func_0c029e70(a, 27, 9);
}

void func_0c19db04(struct LinkedActor *a)
{
    if (func_0c029fc4(a) < 0)
        func_0c19ee84(a);
}

void func_0c19db26(struct LinkedActor *a)
{
    table_0c258a6c[a->b4](a);
}

void func_0c19db38(struct LinkedActor *a)
{
    a->b4++;
    a->sdc = a->p24->sdc;
    a->sdc.b12c = 1;
    a->b2 = a->p24->b2;
    a->b1 = a->p24->b1;
    a->v80.x = a->p24->v80.x;
    a->v80.y = a->p24->v80.y;
    a->b1a3 = a->p24->b1a3;
    a->b1a4 = a->p24->b1a4;
    a->b48 = a->p24->b48;
    a->v80 = a->p24->v80;
    a->b36 = a->p24->b36;
    a->b36 = 0;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    *dat_0c2fb3e8 = a->p24->sdc.w158.short_value;
    func_0c029e70(a, 27, a->b33 + 10);
}
