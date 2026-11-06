#include "objects.h"
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028708(struct LinkedActor *),func_0c028642(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern void func_0c1ac31c(struct LinkedActor *,char);
extern void (*table_0c259d3c[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c259d44[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c259d4c[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1ac022(struct LinkedActor *,struct LinkedActor *);
void func_0c1ac0fc(struct LinkedActor *,struct LinkedActor *);
void func_0c1ac1a0(struct LinkedActor *,struct LinkedActor *);
void func_0c1ac26a(struct LinkedActor *,struct LinkedActor *);
int func_0c1ac2ec(struct LinkedActor *,struct LinkedActor *);
void func_0c1abfe8(struct LinkedActor *a,struct LinkedActor *parent)
{
 a->b7++;a->f92=0;a->f104=0;a->f96=17.142857f;a->f108=0;
 func_0c02a0c4(a,25,24);func_0c1ac022(a,parent);
}
void func_0c1ac022(struct LinkedActor *a,struct LinkedActor *parent)
{
 func_0c02a026(a);if(a->sdc.b141)a->b7++;
}
void func_0c1ac040(struct LinkedActor *a,struct LinkedActor *parent)
{
 struct ActorSub2a4 *state=&((struct Actor *)parent)->sub2a4;
 a->f56+=a->f96;a->f96+=a->f108;
 if(!func_0c028708(a)){
  state->b3=0;a->b4++;a->b7=0;a->b6=0;a->b5=0;
 }
}
void func_0c1ac096(struct LinkedActor *a,struct LinkedActor *parent){table_0c259d3c[a->b7](a,parent);}
void func_0c1ac0a8(struct LinkedActor *a,struct LinkedActor *parent)
{
 a->b7++;a->s28=30;a->f92=0;a->f104=0;a->f96=0;a->f108=0;
 if(!(a->f52<parent->f52))a->sdc.w130=0;else a->sdc.w130=1;
 func_0c02a0c4(a,25,20);func_0c1ac0fc(a,parent);
}
void func_0c1ac0fc(struct LinkedActor *a,struct LinkedActor *parent)
{
 if(func_0c02a026(a)<0){
  if(func_0c1ac2ec(a,parent))a->b6=4;else a->b6=3;
  a->b7=0;
 }
}
void func_0c1ac130(struct LinkedActor *a,struct LinkedActor *parent){table_0c259d44[a->b7](a,parent);}
void func_0c1ac160(struct LinkedActor *a,struct LinkedActor *parent)
{
 a->b7++;if(!a->sdc.w130)a->f92=-3.3333333f;else a->f92=3.3333333f;
 a->f104=0;func_0c02a0c4(a,25,21);func_0c1ac1a0(a,parent);
}
void func_0c1ac1a0(struct LinkedActor *a,struct LinkedActor *parent)
{
 struct ActorSub2a4 *state=&((struct Actor *)parent)->sub2a4;
 a->f52+=a->f92;a->f92+=a->f104;
 if(!func_0c028642(a)){
  state->b3=0;a->b4++;a->b7=0;a->b6=0;a->b5=0;
 }else{
  if(func_0c1ac2ec(a,parent)){a->b6=4;a->b7=0;}
  func_0c02a026(a);
 }
}
void func_0c1ac222(struct LinkedActor *a,struct LinkedActor *parent){table_0c259d4c[a->b7](a,parent);}
void func_0c1ac234(struct LinkedActor *a,struct LinkedActor *parent)
{
 a->b7++;a->f92=0;a->f104=0;a->f96=0;a->f108=0;
 func_0c02a0c4(a,25,22);func_0c1ac26a(a,parent);
}
void func_0c1ac26a(struct LinkedActor *a,struct LinkedActor *parent)
{
 func_0c02a026(a);
 if(a->sdc.b141){a->b7++;func_0c1ac31c(a,a->b32);}
}
void func_0c1ac296(struct LinkedActor *a,struct LinkedActor *parent)
{
 if(func_0c02a026(a)<0){a->b6=1;a->b7=0;}
}
void func_0c1ac2d8(struct LinkedActor *a,struct LinkedActor *parent){a->b4++;a->sdc.b12c=0;}
void func_0c1ac2e6(struct LinkedActor *a,struct LinkedActor *parent){func_0c037688(a);}
int func_0c1ac2ec(struct LinkedActor *a,struct LinkedActor *parent)
{
 float delta=a->f52-parent->f52;
 if(!(-160.0f>delta||delta>160.0f))return 1;
 return 0;
}
