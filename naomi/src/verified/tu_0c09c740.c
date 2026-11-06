#include "objects.h"
extern struct Actor *dat_0c2f8350[][3];
extern char func_0c02a026(struct Actor *);
extern int func_0c037f50(struct Actor *,struct Actor *,short,short);
extern void func_0c19d2ac(struct Actor *,int,int),func_0c04ae74(struct Actor *,int),func_0c1d5da8(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c042018(struct Actor *),func_0c02a39a(struct Actor *,int);
extern void (*table_0c24361c[])(struct Actor *);
unsigned char func_0c09c85c(struct Actor *);
void func_0c09c740(struct Actor *a)
{
 struct Actor *other=dat_0c2f8350[a->b2][0]; int animation;
 if(func_0c09c85c(a)){
  if(other->w420 || !other->b411){
   a->b6++;func_0c19d2ac(a,8,a->s30);
   func_0c04ae74(other,a->s30?20:10);func_0c1d5da8(other,4);
   animation=a->s30+21;goto action;
  }else a->s28=1;
 }
 if(--a->s28==0){a->b6+=2;animation=a->s30+23;
 action:func_0c02a0c4(a,21,animation);}
}
void func_0c09c7d8(struct Actor *a){if(func_0c02a026(a)<0){a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);}}
void func_0c09c80a(struct Actor *a){if(func_0c02a026(a)<0){a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);}}
unsigned char func_0c09c85c(struct Actor *a)
{
 struct Actor *other=dat_0c2f8350[a->b2][0];
 struct HitboxSelection_15dc08 *their=other->p1c0,*ours=a->p1c0;
 if(func_0c037f50(a,other,(unsigned char)ours->pad2,their->index4))return 1;
 if(func_0c037f50(a,other,(unsigned char)ours->pad2,*(short *)&their->pad6[0]))return 1;
 if(func_0c037f50(a,other,(unsigned char)ours->pad2,*(short *)&their->pad6[2]))return 1;
 if(!*(short *)&their->pad6[4])return 0;
 if(func_0c037f50(a,other,(unsigned char)ours->pad2,*(short *)&their->pad6[4]))return 1;
 return 0;
}
void func_0c09c8e2(struct Actor *a)
{
 if(!a->b6){a->b6++;func_0c02a0c4(a,20,2);}
 else if(func_0c02a026(a)<0){func_0c02a39a(a,0);a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);}
}
void func_0c09c938(struct Actor *a){struct Actor *p=a;table_0c24361c[p->b6](a);}
