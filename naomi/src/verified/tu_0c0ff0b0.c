#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c025762(void),func_0c0437b8(struct Actor *);
extern struct LinkedActor *func_0c16e24c(struct LinkedActor *,int);
#define CHILD(p) (*(struct Actor **)((char *)(p)+8))
void func_0c0ff0b0(struct Actor *a,void *context)
{
 int zero;struct Actor *reference;
 a->b3f8=2;a->b328=5;a->f52+=a->f92;a->f92+=a->f104;func_0c02a026(a);
 if(a->b19e){reference=CHILD(context);
  if(a->p1b0!=reference){func_0c025762();func_0c0437b8(a);}}
 zero=0;
 if(a->b14b){a->b1a1=a->b14b+59;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
  dat_0c2f83f8->arr[a->b2]++;a->b14b=zero;}
 if(a->b141){
  a->b3f9=zero;a->b3f8=zero;a->b328=5;a->b7++;a->s28=50;a->b1f5=2;
  a->f92=-0.8333333135f;if(a->b1d2)a->f92=-a->f92;
  reference=CHILD(context);a->f52=reference->f52;func_0c16e24c((struct LinkedActor *)a,0);func_0c16e24c((struct LinkedActor *)a,1);
 }
}
