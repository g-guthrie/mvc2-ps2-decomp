#include "objects.h"
extern char func_0c02a026(struct Actor*);
extern void func_0c0344a0(struct Actor*,int),func_0c095380(struct Actor*,struct ActorSubByteState*),func_0c0953be(struct Actor*),func_0c02a0c4(struct Actor*,int,int),func_0c143b10(struct Actor*,int,int),func_0c0438de(struct Actor*);
extern void (*table_0c242eb0[])(struct Actor*,struct ActorSubByteState*),(*table_0c242ec0[])(struct Actor*,struct ActorSubByteState*);
void func_0c09431c(struct Actor*a,struct ActorSubByteState*sub){a->b3f8=2;a->b328=5;if(a->s28==90)func_0c0344a0(a,21);func_0c095380(a,sub);func_0c02a026(a);func_0c0953be(a);if(a->s28--==0){a->b7++;func_0c02a0c4(a,22,8);a->b3f9=0;a->b3f8=0;a->b327=0;a->b328=0;}else if(a->s30--==0){a->s30=10;if(sub->b7){int i,limit=15;sub->b7--;for(i=10;i<limit;i++)func_0c143b10(a,1,i);func_0c0344a0(a,31);}}}
void func_0c0943de(struct Actor*a,struct ActorSubByteState*sub){if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c094400(struct Actor*a,struct ActorSubByteState*sub){table_0c242eb0[a->b7](a,sub);}
void func_0c094412(struct Actor*a,struct ActorSubByteState*sub){if(a->b1f9==2)a->b6=1;table_0c242ec0[a->b6](a,sub);}
