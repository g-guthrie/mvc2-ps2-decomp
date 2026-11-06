/* Candidate (199/204): func_0c06d5b0 holds the selected byte in r2 and the 0x0c1fba00 call address in r3 where retail uses r3/r2; the other two functions are exact. */
#include "objects.h"
extern struct Dat_13bb5c dat_0c2f8338;
extern void func_0c045248(struct Actor*,int);
extern void func_0c1fba00(void *, int, int);
void func_0c06d530(struct Actor *a);
void func_0c06d570(struct Actor *a);
void func_0c06d5b0(struct Actor *a);

void func_0c06d530(struct Actor *a)
{
 int zero=0;
 a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;goto strength;case 1:a->b1e9=13;goto strength;case 2:goto variant_two;variant_two:a->b1e9=9;strength:a->b1a3=1;break;}
 func_0c045248(a,21);
}

void func_0c06d570(struct Actor *a)
{
 int zero=0;
 a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;goto strength;case 1:a->b1e9=13;goto strength;case 2:goto variant_two;variant_two:a->b1e9=9;strength:a->b1a3=1;break;}
 func_0c045248(a,21);
}

void func_0c06d5b0(struct Actor *a)
{
 struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&a->sub2a4;
 char keep;
 goto k; k: keep=dat_0c2f8338.pad[0]>=5?sub->b1:0;
 func_0c1fba00(sub,0,128);
 sub->b1=keep;
}
