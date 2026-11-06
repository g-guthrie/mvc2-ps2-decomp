#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int),func_0c1b69e8(struct Actor *,int),func_0c1c1678(struct Actor *,short *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24b2f0[])(struct Actor *);
void func_0c104354(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 struct LinkedActorVec3 position;
 int zero=0;
 func_0c02a026(a);
 if(a->b141&1){
  a->b141^=1;position.x=66.666664124f;position.y=132.857132f;
  func_0c0429a4(a,&position,3);
  a->b1a1=57;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
  dat_0c2f83f8->arr[a->b2]++;
 }
 if(a->b141&2){
  a->b6++;a->b141^=2;func_0c1b69e8(a,5);
  ((unsigned char *)sub)[9]=2;sub->s10=500;((unsigned char *)sub)[8]=zero;
  ((unsigned char *)sub)[14]=8;((unsigned char *)sub)[15]=zero;
  func_0c1c1678(a,&sub->s10,6);
 }
}
void func_0c104408(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c10442a(struct Actor *a){table_0c24b2f0[a->b7](a);}
