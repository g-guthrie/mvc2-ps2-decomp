#include "objects.h"
extern void (*table_0c258018[])(struct LinkedActor *);
extern void (*table_0c25801c[])(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
void func_0c196f98(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c196ef4(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=1;a->b49=1;a->f60=owner->f60;
 func_0c02a0c4(a,23,4);
 func_0c196f98(a,owner);
}
void func_0c196f76(struct LinkedActor *a)
{
 if(func_0c02a026(a)<0){a->b4=a->b4+1;a->sdc.b12c=0;}
}
void func_0c196f98(struct LinkedActor *a,struct LinkedActor *owner)
{
 short *frame=&a->wcc.short_value;
 if(owner->sdc.w158.short_value!=*frame){a->b4++;return;}
 a->f52=owner->f52;a->f56=owner->f56;a->b36=7;
 table_0c258018[(unsigned char)a->b5](a);
}
void func_0c196fda(struct LinkedActor *a){table_0c25801c[a->b4](a);}
