/* Exact 0x0c1c24ac..0x0c1c2550: update health-display scale, arbitrate its owner slot, and retire invalid displays. */
#include "objects.h"
extern struct Actor *dat_0c2fb470[];
extern void func_0c037688(struct Actor *);
void func_0c1c24ac(struct Actor *a)
{
 struct Actor *owner=(struct Actor *)((struct LinkedActor *)a)->p24;int zero=0;short *health;struct Actor **registry;struct Actor *other;
 a->b12c=1;if(owner->b411)a->b12c=zero;
 registry=dat_0c2fb470;
 if(*(short *)&owner->w420<=0||!a->s28)goto cleanup;
 health=*(short **)&a->pad5ba;
 a->f80=(float)*health/(float)a->s28;
 if((other=registry[owner->pad7cc[0]])&&a!=other){if(health==*(short **)&other->pad5ba)goto cleanup;other->b12c=zero;}
 registry[owner->pad7cc[0]]=a;
 if(*health>0)return;
 cleanup:a->s28=zero;a->b12c=zero;registry[owner->pad7cc[0]]=(struct Actor *)zero;func_0c037688(a);
}
