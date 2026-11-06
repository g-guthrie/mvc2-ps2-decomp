#include "objects.h"
extern void func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0451f2(struct Actor *);
extern char func_0c02a026(struct Actor *);
void func_0c0ee698(struct Actor *a,char *p){float delta;a->b6++;func_0c048bb0(a,10);func_0c0442fa(a);a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f92=a->p20c->f52-a->f52;a->f92/=32.0f;a->f104=0;a->f96=12.85714245f;a->f108=-1.2053571f;a->s28=0;if(p[3]){a->s28=5;a->f108=-1.07142854f;}delta=205.71428f;if(a->p20c->b1f9==2)delta=274.28571f;if(a->p20c->b1f9==1)delta=102.85714f;delta+=a->p20c->f56;delta-=a->f56;if(delta>0 && delta<308.571411133f)delta=308.571411133f;a->f96+=delta/32.0f;if(a->b1f9!=2)func_0c0432ca(a);func_0c02a0c4(a,21,7);func_0c02a026(a);}
void func_0c0ee788(struct Actor *a){if(--a->s28<0){a->b6++;if(a->b1f9!=2)func_0c0451f2(a);}}
