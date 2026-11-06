#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,char);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24f918[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c24f91c[])(struct LinkedActor *);
extern void (*table_0c24f92c[])(struct LinkedActor *,struct LinkedActor *);
void func_0c14382e(struct LinkedActor *);
void func_0c143982(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c1437e0(struct LinkedActor *owner,unsigned char mode,unsigned char value)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c14382e;a->w38=0x0f01;a->p24=owner;a->b1=owner->b1;*(&a->b32)=mode;*(&a->b33)=value;}
 return a;
}
void func_0c14382e(struct LinkedActor *a){table_0c24f918[a->b32](a,a->p24);}
void func_0c143844(struct LinkedActor *a){table_0c24f91c[a->b4](a);}
void func_0c143856(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=1;a->b49=1;
 a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 if(!a->sdc.w130)a->f52+=-120.0f;else a->f52-=-120.0f;
 a->f56+=377.142853f;
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->f96=17.142857f;
 A(a)->b1a1=60;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 a->pad11[0]=67;a->pad11[1]=66;
 func_0c02a0c4(a,23,3);
 func_0c143982(a,owner);
}
void func_0c143982(struct LinkedActor *a,struct LinkedActor *owner)
{
 if((unsigned char)A(owner)->b159!=22 || a->f56>A(owner)->f41c+1097.1428223f){a->b4++;return;}
 table_0c24f92c[(unsigned char)a->b5](a,owner);
}
void func_0c1439c0(struct LinkedActor *a)
{
 a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;func_0c02a026(a);func_0c037d0c(a);
 if(A(a)->b19e){a->b5++;a->f96=4.28571415f;a->s28=120;}
}
void func_0c143a3c(struct LinkedActor *a)
{
 a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;func_0c02a026(a);func_0c037d0c(a);
 if(!(a->s28&7)){A(a)->b1a1=60;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;}
 if(a->s28==8){A(a)->b1a1=61;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;}
 if((a->s28)--==0)a->b4++;
}
void func_0c143ad8(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct ActorSub2a4 *sub=&A(owner)->sub2a4;
 sub->b6=1;a->sdc.b12c=0;a->b4++;
}
void func_0c143aee(struct LinkedActor *a){a->sdc.b12c=0;func_0c037688(a);}
