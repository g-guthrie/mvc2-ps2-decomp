#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0438de(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c0ae924(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;int zero;
 if(a->b1f9==2)a->b1f5=3;
 if(a->b19e){if(!(a->b19e&0x80))sub->b2++;}
 a->f52+=a->f92;a->f92+=a->f104;func_0c02a026(a);zero=0;
 if((unsigned char)a->b14b && (unsigned char)a->b14b<128){
  a->b1a1=a->b14b+51;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
  dat_0c2f83f8->arr[a->b2]++;a->b14b=zero;
 }
 a->s28--;
 if(a->s28<=0 || a->f92*a->f104>0.0f){
  a->b6++;if(a->b1f9==2)a->b1f5=zero;func_0c02a0c4(a,21,a->b1a3+8);
  a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;sub->b3=1;
 }
}
void func_0c0aea10(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141==9){a->b6++;a->b141=0;
  if(a->b1f9==2){a->f92=0.0f;a->f104=0.0f;func_0c0438de(a);}}
}
