/* Exact actor-follow effect unit, 0x0c1aa314..0x0c1aa498.
 * Callback cell 0x0c2599d4 enters at 0x0c1aa3e2, after the initializer's
 * fallthrough epilogue. Preserve the parent recapture in the interpolation
 * helper and the two animation call sites: both reproduce native code.
 */
#include "objects.h"
extern void (*dat_0c2599d0[])(struct LinkedActor *);
extern struct LinkedActor *func_0c0374da(int, int, int);
extern void func_0c029e70(struct LinkedActor *, int, int);
extern void func_0c037688(struct LinkedActor *);

void func_0c1aa342(struct LinkedActor *a);
void func_0c1aa3e2(struct LinkedActor *a);
void func_0c1aa43a(struct LinkedActor *a, struct LinkedActor *sub);

struct LinkedActor *func_0c1aa314(struct LinkedActor *param1, unsigned char param2)
{
    struct LinkedActor *result;
    if ((result = func_0c0374da(0, 3, 0)) != 0) {
        result->p16 = func_0c1aa342;
        result->p24 = param1;
        result->b32 = param2;
    }
    return result;
}

void func_0c1aa342(struct LinkedActor *a)
{
    dat_0c2599d0[a->b4](a);
}

void func_0c1aa354(struct LinkedActor *a)
{
    struct LinkedActor *obj;
    register int one = 1;

    a->b4++;
    a->w38 = 0x1c01;
    a->sdc.b12c = one;
    obj = a->p24;
    a->sdc = obj->sdc;
    a->sdc.b12c = one;
    a->b2 = obj->b2;
    a->b1 = obj->b1;
    a->v80.x = obj->v80.x;
    a->v80.y = obj->v80.y;
    a->b1a3 = obj->b1a3;
    a->b1a4 = obj->b1a4;
    a->b48 = obj->b48;
    a->v80 = obj->v80;
    a->b36 = obj->b36;
    a->b49 = -1;
    a->f52 = obj->f52;
    if (a->b32)
        func_0c029e70(a, 27, 1);
    else
        func_0c029e70(a, 27, 2);
    func_0c1aa3e2(a);
}

void func_0c1aa3e2(struct LinkedActor *a)
{
    struct LinkedActor *sub = a->p24;
    if (sub->b6 > 2) {
        a->b4 = 2;
        a->sdc.b12c = 0;
        return;
    }
    a->b36 = sub->b36;
    if (a->b32 == 0)
        a->f56 = sub->f56 + 304.28571f;
    else
        func_0c1aa43a(a, sub);
}

void func_0c1aa426(struct LinkedActor *a)
{
    a->b4++;
    a->sdc.b12c = 0;
}

void func_0c1aa434(struct LinkedActor *a)
{
    func_0c037688(a);
}

void func_0c1aa43a(struct LinkedActor *a, struct LinkedActor *sub)
{
    struct LinkedActor *target;
    float base, step;
    sub = a->p24;
    target = sub->p20;
    base = sub->f56;
    step = (target->f56 - base + -34.2857132f) / 8.0f;
    a->f56 = base + step * (float)a->b32;
}
