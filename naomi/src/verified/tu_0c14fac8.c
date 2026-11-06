#include "objects.h"
extern void (*table_0c2503e8[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c037688(struct Actor *);
void func_0c14fac8(struct Actor *a)
{
 struct Actor *owner=(struct Actor *)((struct LinkedActor *)a)->p24;struct ActorSub2a4 *sub;
 table_0c2503e8[a->b5](a);sub=&owner->sub2a4;
 if(sub->b1 || owner->b5){int zero=0;a->b4++;a->b12c=zero;sub->b0=zero;}
}
void func_0c14fb04(struct Actor *a)
{
 if(a->b141==1){a->f264-=0.06f;if(a->f264<0.0f)a->f264=0.0f;}
 func_0c02a026(a);if(a->b143<0){a->b4++;a->b12c=0;}
}
void func_0c14fb4a(struct Actor *a)
{
 func_0c02a026(a);if(a->b141==1){a->f264-=0.06f;if(a->f264<0.0f)a->f264=0.0f;}
 if(a->b143<0){a->b4++;a->b12c=0;}
}
void func_0c14fb8e(struct Actor *a){a->b4++;a->b12c=0;}
void func_0c14fb9c(struct Actor *a){func_0c037688(a);}
