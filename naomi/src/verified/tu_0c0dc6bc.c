#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char dat_0c248e3c[];
extern short dat_0c248c50[];
extern float dat_0c248c54[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a39a(struct Actor *,int),func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0344a0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c1b1910(struct Actor *,int);
void func_0c0dc6bc(struct Actor *a){int zero=0;a->b6++;((struct ActorSubByteState *)&a->sub2a4.s10)->b4=zero;((struct ActorSubByteState *)&a->sub2a4.s10)->b5=zero;func_0c02a39a(a,zero);a->b1a1=dat_0c248e3c[(unsigned char)a->b1a3*2];a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c048bb0(a,4);func_0c0442fa(a);a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->s28=dat_0c248c50[(unsigned char)a->b1a3];a->f92=dat_0c248c54[(unsigned char)a->b1a3];if(!a->b1d2)a->f92=-a->f92;func_0c0344a0(a,20);func_0c02a0c4(a,21,(char)a->b1a3+29);if(a->i204){((struct ActorSubByteState *)&a->sub2a4.s10)->b5=zero;func_0c1b1910(a,6);}}
void func_0c0dc790(struct Actor *a){func_0c02a026(a);if(!a->b141){a->b6++;a->f52+=a->b1d2?32:-32;if(!a->i204){((struct ActorSubByteState *)&a->sub2a4.s10)->b5=1;func_0c1b1910(a,6);}}}
