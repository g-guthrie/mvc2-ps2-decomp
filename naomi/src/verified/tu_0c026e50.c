/* Draws two digit counters (2 and 6 digits) as 0.25-wide texture cells, preceded by five fixed frame sprites. */
#include "objects.h"
extern struct DrawRect dat_0c23a40c;
extern void func_0c1f1f10(struct DrawRect *);
void func_0c026e50(int a, int b)
{
    float u, v;
    int i, n, digits;
    struct DrawRect *r = &dat_0c23a40c;
    r->flags=1;
    r->x=194.0f; r->y=426.0f; r->z=0.96f;
    r->u1=0.0f; r->v1=0.0f; r->u2=0.75f; r->v2=0.25f;
    r->u0=0.75f; r->v0=0.25f;
    r->a=0; r->b=1.0f; r->c=-1; r->d=5; r->e=-1; r->f=0;
    func_0c1f1f10(r);
    r->x=274.0f;
    r->u1=0.75f; r->v1=0.0f; r->u2=1.0f; r->v2=0.25f; r->u0=0.25f; r->v0=0.25f;
    func_0c1f1f10(r);
    r->x=298.0f;
    r->u1=0.0f; r->v1=0.0f; r->u2=0.25f; r->v2=0.25f; r->u0=0.25f; r->v0=0.25f;
    func_0c1f1f10(r);
    r->x=314.0f;
    r->u1=0.0f; r->v1=0.25f; r->u2=0.5f; r->v2=0.5f; r->u0=0.5f; r->v0=0.25f;
    func_0c1f1f10(r);
    r->x=442.0f;
    r->u1=0.75f; r->v1=0.0f; r->u2=1.0f; r->v2=0.25f; r->u0=0.25f; r->v0=0.25f;
    func_0c1f1f10(r);
    r->x=274.0f; r->z=0.95f; r->u0=0.25f; r->v0=0.25f;
    digits=a;
    for(i=0;i<2;i++){
        n=digits%10+2;
        u=(n&3)*0.25f; v=(n/4+1)*0.25f;
        digits/=10;
        r->x-=16.0f;
        r->u1=u; r->v1=v; u+=0.25f; v+=0.25f; r->u2=u; r->v2=v;
        func_0c1f1f10(&dat_0c23a40c);
    }
    r->x=442.0f; r->u0=0.25f; r->v0=0.25f;
    digits=b;
    for(i=0;i<6;i++){
        n=digits%10+2;
        u=(n&3)*0.25f; v=(n/4+1)*0.25f;
        digits/=10;
        r->x-=16.0f;
        r->u1=u; r->v1=v; u+=0.25f; v+=0.25f; r->u2=u; r->v2=v;
        func_0c1f1f10(&dat_0c23a40c);
    }
}
