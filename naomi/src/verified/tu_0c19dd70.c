/* Five actor callbacks and their shared pool. Assigning then clearing b36
 * makes SHC emit the retail parent-field read before the zero store. */
#include "objects.h"
typedef void (*Handler_19dd70)(struct LinkedActor *);
extern char func_0c029fc4(struct LinkedActor *);
extern void func_0c19ee84(struct LinkedActor *);
extern Handler_19dd70 table_0c258aac[];
extern Handler_19dd70 table_0c258abc[];
extern void func_0c029e70(struct LinkedActor *, int, int);

void func_0c19dd70(struct LinkedActor *a)
{
    if (func_0c029fc4(a) < 0)
        func_0c19ee84(a);
}

void func_0c19dd92(struct LinkedActor *a)
{
    table_0c258aac[a->b4](a);
}

void func_0c19dda4(struct LinkedActor *a)
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
    a->f52 = a->p20->f52;
    a->f56 = a->p20->f56;
    func_0c029e70(a, 27, 9);
}

void func_0c19de28(struct LinkedActor *a)
{
    if (func_0c029fc4(a) < 0)
        func_0c19ee84(a);
}

void func_0c19de4a(struct LinkedActor *a)
{
    table_0c258abc[a->b4](a);
}
