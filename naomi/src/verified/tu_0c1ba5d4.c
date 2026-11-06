/* Owner-anchored child: copies the owner's draw block, then follows the owner's position offset by a per-type table while the owner's 0x158 key matches. */
#include "objects.h"
#define A(x) ((struct Actor *)(x))
extern const short dat_0c25b8e4[];
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void (*table_0c25b8ec[])(struct LinkedActor *);
void func_0c1ba662(struct LinkedActor *,struct LinkedActor *);
int func_0c1ba782(struct LinkedActor *,struct LinkedActor *);
void func_0c1ba5d4(struct LinkedActor *a,struct LinkedActor *o)
{
    a->b4++;
    a->sdc=o->sdc; a->sdc.b12c=1;
    a->b2=o->b2; a->b1=o->b1;
    a->v80.x=o->v80.x; a->v80.y=o->v80.y;
    a->b1a3=o->b1a3; a->b1a4=o->b1a4; a->b48=o->b48;
    a->v80=o->v80;
    a->b36=o->b36;
    a->sdc.b12c=1;
    a->f92=0.0f; a->f96=0.0f; a->f104=0.0f; a->f108=0.0f;
    a->b49=-1;
    func_0c02a0c4(a,23,7);
    func_0c1ba662(a,o);
}
void func_0c1ba662(struct LinkedActor *a,struct LinkedActor *o)
{
    char *p;
    short *q;
    p=&A(o)->sub2a4.b0;
    q=&a->wcc.short_value;
    a->b36=o->b36;
    if(o->sdc.w158.short_value!=*q){
        a->b4++;
        func_0c1ba782(a,o);
        return;
    }
    func_0c02a026(a);
    a->f52=o->f52; a->f56=o->f56; a->f60=o->f60;
    if(!a->sdc.w130) a->f52+=*(dat_0c25b8e4+(unsigned char)a->b33*2)*1.66666663f;
    else a->f52-=*(dat_0c25b8e4+(unsigned char)a->b33*2)*1.66666663f;
    a->f56+=(dat_0c25b8e4+(unsigned char)a->b33*2)[1]*2.1428571f;
    if(*p) a->b4++;
}
void func_0c1ba770(struct LinkedActor *a){table_0c25b8ec[a->b4](a);}
int func_0c1ba782(struct LinkedActor *a,struct LinkedActor *o){a->b4++;a->sdc.b12c=0;}
void func_0c1ba790(struct LinkedActor *a){a->sdc.b12c=0;func_0c037688(a);}
