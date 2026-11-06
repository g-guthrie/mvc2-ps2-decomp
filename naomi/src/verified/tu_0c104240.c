#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c02a39a(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *);
extern void (*table_0c24b2e0[])(struct Actor *);
void func_0c104240(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(a->b141){float limit;
  a->f56+=a->f96;a->f96+=a->f108;
  limit=77.142853f+a->f41c;
  if(a->f56>limit)return;
  a->f56=limit;
 }
 goto animate;animate:
 if(func_0c02a026(a)<0){
  int zero=0;
  a->b6++;a->b7=zero;a->b1f9=zero;a->f56=a->f41c;*(char *)&sub->b7=-1;
  func_0c02a0c4(a,21,16);
 }
}
void func_0c1042ca(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c1042ec(struct Actor *a){table_0c24b2e0[a->b6](a);}
void func_0c1042fe(struct Actor *a){a->b6++;func_0c02a39a(a,0);func_0c0442fa(a);func_0c0432ca(a);func_0c02a0c4(a,22,0);}
