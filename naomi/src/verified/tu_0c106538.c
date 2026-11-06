/* Twenty-five connected motion, dispatch, and animation callbacks. */
#include "objects.h"
extern void func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *),func_0c172474(struct Actor *,int,int),func_0c02a0c4(struct Actor *,int,int),func_0c1b748c(struct Actor *,int,int),func_0c170b20(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
extern void (*dat_0c24b4cc[])(struct Actor *),(*dat_0c24b4dc[])(struct Actor *),(*dat_0c24b4e8[])(struct Actor *),(*dat_0c24b4f0[])(struct Actor *),(*dat_0c24b50c[])(struct Actor *),(*dat_0c24b518[])(struct Actor *);
extern void (*dat_0c24b4fc[])(struct Actor *,struct ActorSub2a4 *);
void func_0c10655a(struct Actor *),func_0c1065dc(struct Actor *),func_0c1066ce(struct Actor *),func_0c106818(struct Actor *),func_0c1068e4(struct Actor *);
void func_0c106538(struct Actor *a){dat_0c24b4cc[(unsigned char)a->b1ff](a);}
void func_0c10654c(struct Actor *a){func_0c043352(a);func_0c10655a(a);}
void func_0c10655a(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);
 if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c1068e4(a);else func_0c106818(a);}
 else{if(a->b1f9==1)func_0c1066ce(a);else func_0c1065dc(a);}
}
void func_0c1065dc(struct Actor *a){dat_0c24b4dc[a->b1e8](a);}
void func_0c1065f0(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c106612(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c106654(struct Actor *a)
{
 func_0c02a026(a);if(a->b141){int zero=0;a->b141=zero;func_0c172474(a,1,zero);}
 if(--a->s28==0){a->b6++;func_0c02a0c4(a,20,0);}
}
void func_0c10669a(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c1066bc(struct Actor *a){dat_0c24b4e8[a->b6](a);}
void func_0c1066ce(struct Actor *a){dat_0c24b4f0[a->b1e8](a);}
void func_0c1066e2(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c106704(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c106726(struct Actor *a)
{
 func_0c02a026(a);if(a->b141){a->b7++;a->s28=10;func_0c1b748c(a,2,2);}
}
void func_0c106778(struct Actor *a)
{
 func_0c02a026(a);if(--a->s28==0){a->b7++;func_0c170b20(a,0,2);a->b27a=16;a->b27b=0;}
}
void func_0c1067b0(struct Actor *a,struct ActorSub2a4 *sub)
{
 func_0c02a026(a);if(--a->s30==0){a->b7++;sub->b0=1;}
}
void func_0c1067e0(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c106802(struct Actor *a){dat_0c24b4fc[a->b7](a,&a->sub2a4);}
void func_0c106818(struct Actor *a){dat_0c24b50c[a->b1e8](a);}
void func_0c10682c(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c10684e(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141){a->b141=0;func_0c172474(a,1,2);}
}
void func_0c106888(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141){a->b141=0;func_0c172474(a,1,4);}
}
void func_0c1068e4(struct Actor *a){dat_0c24b518[a->b1e8](a);}
void func_0c1068f8(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c10691a(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141&2){a->b141&=(unsigned char)~2;func_0c172474(a,1,1);}
 if(a->b141&1){a->b141&=(unsigned char)~1;a->f92=-6.66666651f;a->f104=.41666666f;
  if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 }
}
void func_0c106994(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141){a->b141=0;func_0c172474(a,1,5);}
}
