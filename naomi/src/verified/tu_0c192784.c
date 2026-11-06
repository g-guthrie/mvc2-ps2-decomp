#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c02a026(struct LinkedActor *),func_0c037688(struct LinkedActor *);
void func_0c19290e(struct LinkedActor *);void func_0c192998(struct LinkedActor *);
extern void (*table_0c257b04[])(struct LinkedActor *);
void func_0c19280e(struct LinkedActor *);
struct LinkedActor *func_0c192784(struct LinkedActor *owner,char mode)
{struct LinkedActor *a;if((a=func_0c0374da(0,3,0))){a->p16=func_0c19280e;a->p24=owner;a->b32=mode;a->w38=0x903;}return a;}
void func_0c1927b8(struct LinkedActor *owner)
{struct LinkedActor *a;if((a=func_0c0374da(0,3,0))){a->p16=func_0c19280e;a->p24=owner->p24;a->b32=2;a->w38=0x903;}}
void func_0c1927ec(struct LinkedActor *a)
{a->b36=a->p24->b36;if(a->b32){a->b49=1;return;}else {a->b49=-1;return;}}
void func_0c19280e(struct LinkedActor *a){table_0c257b04[a->b4](a);}

void func_0c192830(struct LinkedActor *a)
{
 register float animation;int one,zero;
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;one=1;a->sdc.b12c=one;
 a->f52=a->p24->f52;a->f56=a->p24->f56;zero=0;
 if(a->b32){a->b36=7;animation=8.0f;
 if(a->b32==1){animation=6.0f;if(a->p24->sdc.w130)a->f52+=236.66666f;a->sdc.w130=zero;}}
 else {a->b36=zero;animation=5.0f;}
 func_0c02a0c4(a,19,(int)animation);func_0c19290e(a);
}
void func_0c19290e(struct LinkedActor *a)
{
 func_0c02a026(a);func_0c1927ec(a);
 if(((struct MeActor *)a->p24)->blk_dc.b159!=19){a->b4++;func_0c192998(a);return;}
 if(!a->b32 && !a->b5 && a->p24->sdc.b141){a->b5++;func_0c02a0c4(a,19,7);func_0c1927b8(a);}
}
void func_0c192998(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;func_0c037688(a);}
