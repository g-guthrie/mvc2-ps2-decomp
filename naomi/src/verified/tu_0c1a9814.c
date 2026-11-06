/* Linked-actor setup and follow callbacks; the setup tail-calls the follow step. */
#include "objects.h"
typedef void (*Handler_1a9814)(struct LinkedActor *);
extern char func_0c029fc4(struct LinkedActor *);
extern void func_0c029e70(struct LinkedActor *, int, int);
extern Handler_1a9814 table_0c259664[];
/* Follow view: position block at 52 and the owner ground line at 0x41c; the
 * member-wise vector store is what gives retail the @(r0,r1) reload. */
struct Owner_1a9814 { unsigned char pad[24]; struct Owner_1a9814 *p24; unsigned char pad2[52-28]; struct LinkedActorVec3 v52; unsigned char pad3[0x41c-64]; float f41c; };
void func_0c1a98b8(struct LinkedActor *a);

void func_0c1a9814(struct LinkedActor *a)
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
    func_0c029e70(a, 27, 5);
    if (a->b33)
        a->sdc.w130 ^= 1;
    a->v80.x *= 0.800000012f;
    a->v80.y *= 0.800000012f;
    func_0c1a98b8(a);
}

void func_0c1a98b8(struct LinkedActor *a)
{
    if (func_0c029fc4(a) < 0) {
        a->b4++;
        a->sdc.b12c = 0;
    } else {
        ((struct Owner_1a9814 *)a)->v52 = ((struct Owner_1a9814 *)a)->p24->v52;
        ((struct Owner_1a9814 *)a)->v52.y = ((struct Owner_1a9814 *)a)->p24->f41c;
    }
}

void func_0c1a98f4(struct LinkedActor *a)
{
    table_0c259664[a->b4](a);
}
