#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c037688(struct LinkedActor *),func_0c037d0c(struct LinkedActor *),func_0c02a0c4(struct LinkedActor *,int,int),func_0c0344a0(struct LinkedActor *,int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c02849a(void);
extern float dat_0c2d92f0;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern signed char dat_0c24f814[],dat_0c24f81c[];
extern short dat_0c24f824[];
extern void (*table_0c24f834[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c24f840[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c24f850[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c24f854[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c24f864[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c24f868[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c24f878[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1420f8(struct LinkedActor *),func_0c14219a(struct LinkedActor *,struct LinkedActor *),func_0c142384(struct LinkedActor *,struct LinkedActor *),func_0c142566(struct LinkedActor *,struct LinkedActor *),func_0c14262c(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c14205c(struct LinkedActor *owner,unsigned char mode,unsigned char value)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c1420f8;a->w38=0x0d02;a->p24=owner;*(&a->b32)=mode;*(&a->b33)=value;a->b1=owner->b1;}
 return a;
}
struct LinkedActor *func_0c1420aa(struct LinkedActor *parent,unsigned char mode,char value)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c1420f8;a->w38=0x0d02;a->p24=parent->p24;a->p20=parent;*(&a->b32)=mode;a->b33=value;a->b1=parent->b1;}
 return a;
}
void func_0c1420f8(struct LinkedActor *a){table_0c24f834[a->b32](a,a->p24);}
void func_0c14210e(struct LinkedActor *a,struct LinkedActor *owner){table_0c24f840[a->b4](a,owner);}
void func_0c142120(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=0;
 a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 a->s28=1;a->s30=48;func_0c14219a(a,owner);
}
void func_0c14219a(struct LinkedActor *a,struct LinkedActor *owner)
{if((unsigned char)A(owner)->b159!=22){a->b4++;return;}else table_0c24f850[(unsigned char)a->b5](a,owner);}
void func_0c1421f0(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(--a->s28==0){a->s28=3;func_0c1420aa(a,1,a->s30);}
 if(--a->s30==0){a->b4++;func_0c14262c(a,owner);}
}
void func_0c14223a(struct LinkedActor *a,struct LinkedActor *owner){table_0c24f854[a->b4](a,owner);}
void func_0c142250(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct LinkedActor *parent=a->p20;
 short random,offset;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=1;a->b49=-1;
 A(a)->b1a1=82;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 A(a)->b19c=66;A(a)->b19d=66;
 a->f52=parent->f52;a->f56=dat_0c2d92f0;a->f60=parent->f60;
 random=(unsigned char)func_0c02849a();a->f52+=(128-random)*1.66666663f;
 random=func_0c02849a()&127;a->f56+=(64-random)*2.1428571f;
 offset=-106;if(a->sdc.w130)offset=106;a->f52+=offset;
 A(a)->f96=12.8571429f;A(a)->f108=-1.33928562f;
 func_0c02a0c4(a,23,dat_0c24f814[func_0c02849a()&7]);func_0c142384(a,owner);
}
void func_0c142384(struct LinkedActor *a,struct LinkedActor *owner){a->b36=owner->b36;table_0c24f864[(unsigned char)a->b5](a,owner);}
void func_0c1423dc(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;func_0c02a026(a);func_0c037d0c(a);
 if(A(owner)->f41c>=a->f56){a->f56=A(owner)->f41c;if(((unsigned char)a->b33&15)==0)func_0c0344a0(a,30);func_0c1420aa(a,2,0);a->b4++;func_0c14262c(a,owner);}
}
void func_0c142454(struct LinkedActor *a,struct LinkedActor *owner){table_0c24f868[a->b4](a,owner);}
void func_0c142478(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct LinkedActor *parent=a->p20;
 unsigned char choice;
 short *row;
 int x,y;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->b49=-2;a->sdc.b12c=1;
 a->f52=parent->f52;a->f56=parent->f56;a->f60=parent->f60;
 choice=func_0c02849a()&3;row=dat_0c24f824+2*choice;
 x=row[0]<<8;y=row[1]<<8;
 A(a)->f92=x*1.66666663f/65536.0f;A(a)->f96=y*2.1428571f/65536.0f;
 A(a)->f104=0.0f;A(a)->f108=-0.401785702f;
 choice=func_0c02849a()&7;func_0c02a0c4(a,23,dat_0c24f81c[choice]);func_0c142566(a,owner);
}
void func_0c142566(struct LinkedActor *a,struct LinkedActor *owner){a->b36=owner->b36;table_0c24f878[(unsigned char)a->b5](a,owner);}
void func_0c142580(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->f52+=A(a)->f92;A(a)->f92+=A(a)->f104;a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;
 func_0c02a026(a);if(A(owner)->f41c>=a->f56){a->b4++;func_0c14262c(a,owner);}
}
void func_0c14262c(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c14263a(struct LinkedActor *a){a->sdc.b12c=0;func_0c037688(a);}
