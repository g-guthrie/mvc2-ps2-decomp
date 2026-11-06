/* Four callbacks and both literal pools match. The trajectory initializer
 * differs in fourteen bytes of temporary-register allocation. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c1b2e10(struct Actor *,int),func_0c043324(struct Actor *),func_0c0437b8(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c0451f2(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c249f48[])(struct Actor *,struct ActorSub2a4 *);
void func_0c0eeb8c(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(a->f56>a->f41c){
  if(((char *)&a->w150)[1]){((char *)&a->w150)[1]=0;func_0c1b2e10(a,7);}
 }else{float stopped=0.0f;
  a->b6++;a->f56=a->f41c;a->b1f9=1;
  a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
  func_0c043324(a);func_0c02a0c4(a,21,12);
 }
}
void func_0c0eec3a(struct Actor *a)
{
 if(func_0c02a026(a)<0){float stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;func_0c0437b8(a);}
}
void func_0c0eec6c(struct Actor *a){table_0c249f48[a->b6](a,&a->sub2a4);}
void func_0c0eec82(struct Actor *a,struct ActorSub2a4 *sub)
{
 float stopped,offset;
 a->b6++;func_0c048bb0(a,5);func_0c0442fa(a);
 stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 a->f92=a->p20c->f52-a->f52;
 if(0.0f>*(&a->f92))a->f92+=-20.0f;else a->f92+=20.0f;
 a->f92/=32.0f;a->f104=stopped;a->f96=12.85714245f;a->f108=-0.9375f;
 a->s28=sub->b3?5:0;
 offset=205.71428f;
 if(a->p20c->b1f9==2)offset=274.28571f;
 if(a->p20c->b1f9==1)offset=102.85714f;
 offset+=a->p20c->f56;offset-=a->f56;
 if(offset>0.0f && offset<308.571411133f)offset=308.571411133f;
 offset/=32.0f;a->f96+=offset;
 if(a->b1f9!=2)func_0c0432ca(a);
 func_0c02a0c4(a,21,13);
}
void func_0c0eedb4(struct Actor *a)
{
 if(--a->s28<0){a->b6++;if(a->b1f9!=2)func_0c0451f2(a);}
}
