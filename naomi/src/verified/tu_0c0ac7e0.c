#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c04b02a(struct Actor *),func_0c025762(void),func_0c0346da(struct Actor *,int),func_0c1a286c(struct Actor *,int,int);
extern void func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int);
extern void (*table_0c24466c[])(struct Actor *),(*table_0c24467c[])(struct Actor *);
void func_0c0ac7e0(struct Actor *a){a->b1ea=1;table_0c24466c[a->b1f7&63](a);}
void func_0c0ac7fe(struct Actor *a){struct Actor *p=a;table_0c24467c[p->b6](a);}
void func_0c0ac810(struct Actor *a)
{
 struct LinkedActorVec3 position;
 func_0c02a026(a);
 if(a->b141==1){
  struct Actor *child;
  a->b141=3;child=a->p1c8;child->b1a1=32;func_0c04b02a(a);
  position.x=0.0f;position.y=0.0f;func_0c1cea66(a,&position,1);func_0c0346da(a,14);
 }
 if(a->b141==2){
  struct Actor *child=a->p1c8;
  a->b6++;child->p1b4=a;child->b1d2=a->b1d2^1;child->b1a1=34;child->b1f6=1;
  func_0c025762();func_0c1a286c(a,31,0);
  a->f52+=a->w130?-106.666664124f:106.666664124f;
  a->f56+=-154.28571f;a->f96=11.78571415f;a->f108=-0.90401781f;
 }
}
