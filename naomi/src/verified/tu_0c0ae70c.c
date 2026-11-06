#include "objects.h"
extern void (*table_0c244890[])(struct Actor *);
/* func_0c0ae70c: no twin (52 bytes) */
extern char func_0c02a026(struct Actor*);
extern void func_0c0437b8(struct Actor*);
extern struct LinkedActor *func_0c152cb0(struct Actor *, unsigned char);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;

void func_0c0ae740(struct Actor *a,struct ActorSub2a4 *state);
void func_0c0ae762(struct Actor *a);
void func_0c0ae774(struct Actor *a);

void func_0c0ae70c(struct Actor *a)
{
 struct LinkedActor *r;
 func_0c02a026(a);
 if(a->b141){a->b6++;if(!a->b1e9)r=func_0c152cb0(a,0);else r=func_0c152cb0(a,1);}
}

void func_0c0ae740(struct Actor *a,struct ActorSub2a4 *state){if(func_0c02a026(a)<0)func_0c0437b8(a);}

void func_0c0ae762(struct Actor *a){table_0c244890[a->b6](a);}

/* func_0c0ae774: no twin (146 bytes) */
void func_0c0ae774(struct Actor *a)
{
 int zero;float z;
 a->b6++;func_0c0442fa(a);func_0c048bb0(a,5);
 z=0.0f;a->f92=z;a->f96=z;a->f104=z;a->f108=z;
 zero=0;
 if(a->b1f9!=2){a->b1f9=zero;a->f56=a->f41c;func_0c0432ca(a);}
 else a->b1f9=2;
 a->b1a1=a->b1a3+52;
 a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,a->b1a3+6);
}
