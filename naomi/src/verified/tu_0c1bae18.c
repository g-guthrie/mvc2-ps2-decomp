#include "objects.h"
extern void (*table_0c25b944[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,char);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
void func_0c1baeea(struct LinkedActor *);
void func_0c1bae18(struct LinkedActor *a){table_0c25b944[a->b32](a);}
void func_0c1bae2c(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 func_0c02a026(a);
 if(owner->sdc.w158.short_value!=a->s28)func_0c1baeea(a);
}
void func_0c1bae5c(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 a->f52=owner->f52;a->f56=owner->f56;
 if(!owner->sdc.b141)func_0c1baeea(a);else if((a->b34==owner->sdc.b141)&1){a->b34=owner->sdc.b141&1;a->sdc.b142=1;func_0c02a026(a);}
}
void func_0c1bae9e(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 if(!a->b5){
  if(owner->sdc.w158.short_value!=a->s28){a->b5++;func_0c02a0c4(a,23,9);}
  func_0c02a026(a);
 }else if(func_0c02a026(a)<0)func_0c1baeea(a);
}
void func_0c1baeea(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;func_0c037688(a);}
void func_0c1baefc(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;func_0c037688(a);}
