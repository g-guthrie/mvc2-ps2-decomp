/* The two dispatchers and literal pool match exactly. The parent-state handler
 * differs only in the register used for the func_0c043fe6 predicate call. */
#include "objects.h"
typedef void (*ActorMethod)(struct Actor *);
extern unsigned char dat_0c2f8338;
extern unsigned char func_0c043fe6(struct Actor *),func_0c044e52(struct Actor *);
extern void func_0c04aad4(struct Actor *),func_0c02a39a(struct Actor *,int);
extern void func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *);
extern ActorMethod table_0c23ba8c[];
void func_0c03c806(struct Actor *);
void func_0c03c738(struct Actor *a)
{
 ((ActorMethod *)a->p428)[11](a);
}
void func_0c03c746(struct Actor *a)
{
 struct Actor *parent;
 a->b201=0;a->b1f5=1;
 if(a->w420){if(dat_0c2f8338==4){if(func_0c043fe6(a))goto done;}}
 if(a->b1f6){func_0c03c806(a);return;}
 parent=a->p1c8;
 if(!parent)goto remove;
 if(parent->b1a0)goto dispatch;
 if(parent->b254)goto dispatch;
 if(!parent->b1ea){
  goto word;
word:
  if(!a->w420){func_0c04aad4(a);return;}
  func_0c02a39a(a,1);
  if(func_0c044e52(a)){
remove:
   func_0c0437b8(a);return;
  }
  goto other;
other:func_0c0438de(a);return;
 }
 parent->b1ea=0;
dispatch:
 ((ActorMethod *)parent->p428)[12](a);
 return;
done:return;
}
void func_0c03c806(struct Actor *a)
{
 table_0c23ba8c[a->b1f6](a);
}
