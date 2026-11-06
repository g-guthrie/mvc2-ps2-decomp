#include "objects.h"
#define OWNER(a) ((struct Actor *)((struct LinkedActor *)(a))->p24)
extern void (*table_0c250348[])(struct Actor *),(*table_0c250350[])(struct Actor *),(*table_0c250354[])(struct Actor *);
extern float dat_0c2500dc[];
extern char func_0c02a026(struct Actor *);
void func_0c14dea0(struct Actor *a)
{
 struct Actor *owner=OWNER(a);table_0c250348[a->b5](a);
 if(OWNER(a)->b19f || owner->b1d0!=21 || owner->b1e9!=6){a->b4++;a->b12c=0;}
}
void func_0c14dee8(struct Actor *a)
{
 float *offsets=dat_0c2500dc;
 a->b5++;a->b12c=1;a->b36=0;a->f52=OWNER(a)->f52;a->f56=OWNER(a)->f56;a->f60=OWNER(a)->f60;
 a->f52+=OWNER(a)->w130?146:-146;a->f56+=165.0f;
 a->f52+=OWNER(a)->w130?offsets[a->b35]:-offsets[a->b35];
}
void func_0c14df7a(struct Actor *a)
{
 float *offsets=dat_0c2500dc;
 if(a->b35==OWNER(a)->b141){OWNER(a)->b141=0;a->b4++;a->b12c=0;return;}
 a->f52=OWNER(a)->f52;a->f56=OWNER(a)->f56;a->f60=OWNER(a)->f60;
 if(OWNER(a)->b6==2)a->f52+=OWNER(a)->w130?135:-135;else {goto offset;offset:a->f52+=OWNER(a)->w130?146:-146;}
 a->f56+=165.0f;a->f52+=OWNER(a)->w130?offsets[a->b35]:-offsets[a->b35];
}
void func_0c14e062(struct Actor *a)
{
 struct Actor *owner=OWNER(a);table_0c250350[a->b5](a);
 if(owner->b1d0!=21 || owner->b1e9!=6){a->b4++;a->b12c=0;}
}
void func_0c14e0a0(struct Actor *a)
{
 func_0c02a026(a);if(a->b143<0){a->b4++;a->b12c=0;}
}
void func_0c14e0c4(struct Actor *a){struct Actor *record=a;table_0c250354[record->b5](record);}
void func_0c14e0d6(struct Actor *a)
{
 func_0c02a026(a);if(OWNER(a)->b6!=2){a->b4++;return;}
 a->f52=OWNER(a)->f52;a->f56=OWNER(a)->f56;
}
