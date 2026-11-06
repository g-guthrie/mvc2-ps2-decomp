#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c174824(struct Actor *);
extern void func_0c044df4(struct Actor *),func_0c0344a0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c025762(void),func_0c0438de(struct Actor *);
extern char dat_0c24bcf2[];
void func_0c10ddec(struct Actor *a)
{
 func_0c044df4(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<a->f41c){float stopped=0.0f;a->f56=a->f41c;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;}
}
void func_0c10de5a(struct Actor *a)
{
 a->w352|=a->w34e&0x360;
 func_0c10ddec(a);func_0c02a026(a);
 if(a->b141){if(!func_0c174824(a)){a->b6=3;return;}a->b6++;func_0c0344a0(a,32);}
}
void func_0c10deb2(struct Actor *a){func_0c10ddec(a);func_0c02a026(a);}
void func_0c10defa(struct Actor *,struct ActorSub2a4 *);
void func_0c10dec2(struct Actor *a,struct ActorSub2a4 *sub)
{
 a->b6++;a->b19d=-128;a->b1ed=0;func_0c02a0c4(a,21,dat_0c24bcf2[*(unsigned short *)sub]);func_0c10defa(a,sub);
}
void func_0c10defa(struct Actor *a,struct ActorSub2a4 *sub)
{
 func_0c10ddec(a);
 if(func_0c02a026(a)<0){float stopped;func_0c025762();stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;a->f108=-0.80357140303f;func_0c0438de(a);}
}
