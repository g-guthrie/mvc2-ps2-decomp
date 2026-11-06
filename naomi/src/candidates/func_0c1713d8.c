/* Complete effect actor translation. Both constructors and all three
 * dispatchers match independently. The initializer still differs in
 * position-offset evaluation and literal-pool ordering. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c2528a8[])(struct LinkedActor *,struct LinkedActor *),(*table_0c2528b0[])(struct LinkedActor *,struct LinkedActor *);
void func_0c171474(struct LinkedActor *);
struct LinkedActor *func_0c1713d8(struct LinkedActor *owner,unsigned char mode,unsigned char value)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c171474;a->w38=0x2e02;a->p24=owner;a->b1=owner->b1;*(&a->b32)=mode;*(&a->b33)=value;}
 return a;
}
struct LinkedActor *func_0c171426(struct LinkedActor *owner,unsigned char mode,unsigned char value)
{
 struct LinkedActor *a;
 if((a=func_0c0374da((int)owner,1,2))){a->p16=func_0c171474;a->w38=0x2e02;a->p20=owner;a->b1=owner->b1;a->p24=owner->p24;*(&a->b32)=mode;a->b33=value;}
 return a;
}
void func_0c171474(struct LinkedActor *a){table_0c2528a8[a->b32](a,a->p24);}
void func_0c17148a(struct LinkedActor *a,struct LinkedActor *owner){table_0c2528b0[a->b4](a,owner);}

#define A(a) ((struct Actor *)(a))
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short dat_0c252858[],dat_0c2f6830;
extern int dat_0c252860[];
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void (*table_0c2528c0[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1716ec(struct LinkedActor *,struct LinkedActor *);
void func_0c1714b0(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct ActorSub2a4 *context=&A(owner)->sub2a4;
 short *offsets;int *velocities;int one,zero,cursor;
 register float scale,divisor;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=one;a->b49=-2;context->b2++;zero=0;
 A(a)->b1a1=50;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 a->pad11[0]=66;a->pad11[1]=66;
 offsets=dat_0c252858;a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 scale=1.66666663f;
 cursor=(int)offsets;
 if(!A(a)->w130){cursor=(int)((short *)cursor+*(unsigned char *)((char *)a+33)*2);a->f52+=*(short *)cursor*scale;}
 else{cursor=(int)((short *)cursor+*(unsigned char *)((char *)a+33)*2);a->f52-=*(short *)cursor*scale;}
 offsets+=*(unsigned char *)((char *)a+33)*2;
 a->f56+=offsets[1]*2.1428571f;
 velocities=dat_0c252860;divisor=65536.0f;
 A(a)->f92=velocities[(unsigned char)owner->b1a3*3+(unsigned char)a->b33*9]*scale/divisor;
 A(a)->f104=velocities[(unsigned char)owner->b1a3*3+(unsigned char)a->b33*9+1]*scale/divisor;
 a->f96=0.0f;
 A(a)->f108=velocities[(unsigned char)owner->b1a3*3+(unsigned char)a->b33*9+2]*scale/divisor;
 if(A(a)->w130){A(a)->f92=-A(a)->f92;A(a)->f104=-A(a)->f104;}
 func_0c02a0c4(a,23,12);
 if(dat_0c2f6830>=4){func_0c171426(a,1,0);func_0c171426(a,1,0);func_0c171426(a,1,0);func_0c171426(a,1,0);}
 func_0c1716ec(a,owner);
}
void func_0c1716ec(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b36=owner->b36;table_0c2528c0[(unsigned char)a->b5](a,owner);
}
