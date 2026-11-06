#include "objects.h"
extern struct DrawRect dat_0c23a40c;
extern void func_0c1f1f10(struct DrawRect *);
void func_0c0270b8(void)
{
    float end, scale, zero;
    struct DrawRect *r = &dat_0c23a40c;
    r->flags=0xd50;
    r->x=40.0f; r->y=394.0f; r->z=0.96f;
    r->u1=zero=0.0f; r->v1=zero; r->u2=scale=1.0f; r->v2=end=0.625f;
    r->u0=scale; r->v0=end;
    r->a=0; r->b=scale; r->c=-1; r->d=5; r->e=-1; r->f=0;
    func_0c1f1f10(r);
    r->x=222.0f; r->y=448.0f;
    r->u1=zero; r->v1=end; r->u2=scale; end=0.75f; r->v2=end;
    r->u0=scale; scale=0.125f; r->v0=scale;
    func_0c1f1f10(r);
    r->x=350.0f;
    r->u1=zero; r->v1=end; r->u2=0.5f; r->v2=0.875f;
    r->u0=0.5f; r->v0=scale;
    func_0c1f1f10(r);
}
