#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *,int),func_0c0438de(struct Actor *),func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c18f420(struct Actor *,int),func_0c02a684(struct Actor *,int,int,int);
extern int dat_0c23fd8c[];
extern void (*table_0c23ff88[])(struct Actor *),(*table_0c23ff94[])(struct Actor *);
void func_0c060a50(struct Actor *a)
{
 struct ActorSubMotionFlags *sub=(struct ActorSubMotionFlags *)&a->sub2a4;
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<a->f41c)a->f56=a->f41c;
 if(!--a->s28){a->f104=0;sub->flag28=0;sub->flag25=0;func_0c0344a0(a,43);func_0c0438de(a);}
}
void func_0c060ae4(struct Actor *a){table_0c23ff88[a->b6](a);}
void func_0c060af6(struct Actor *a)
{
 struct ActorSubMotionFlags *sub=(struct ActorSubMotionFlags *)&a->sub2a4;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->b6++;a->s28=16;a->f92=a->b1d2?-11.666666031f:11.666666031f;
 sub->flag28=1;func_0c0344a0(a,31);
}
void func_0c060b38(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(!--a->s28){a->b6++;a->f104=a->b1d2?0.8333333135f:-0.8333333135f;func_0c02a0c4(a,2,3);}
}
void func_0c060bdc(struct Actor *a)
{
 struct ActorSubMotionFlags *sub=(struct ActorSubMotionFlags *)&a->sub2a4;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c02a026(a)<0){
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;sub->flag28=0;func_0c0344a0(a,43);func_0c0437b8(a);
 }
}
void func_0c060c64(struct Actor *a){table_0c23ff94[a->b6](a);}
void func_0c060c76(struct Actor *a)
{
 a->b6++;a->b12c=1;func_0c18f420(a,0);
 func_0c02a684(a,2,dat_0c23fd8c[a->b37],1);func_0c02a0c4(a,18,0);
}
void func_0c060cb4(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b6++;a->s28=32;func_0c02a0c4(a,18,1);}
}
