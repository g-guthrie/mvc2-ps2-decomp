/* Unit 0x0c143388-0x0c1435c4. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,char);
extern int func_0c028642(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24f8f4[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c24f8f8[])(struct LinkedActor *);
extern void (*table_0c24f908[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1433d6(struct LinkedActor *);
void func_0c1433ec(struct LinkedActor *);
void func_0c143552(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c143388(struct LinkedActor *owner,unsigned char mode,unsigned char value)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c1433d6;a->w38=0x0f00;a->p24=owner;a->b1=owner->b1;*(&a->b32)=mode;*(&a->b33)=value;}
 return a;
}
void func_0c1433d6(struct LinkedActor *a){table_0c24f8f4[a->b32](a,a->p24);}
void func_0c1433ec(struct LinkedActor *a){table_0c24f8f8[a->b4](a);}
void func_0c1433fe(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=1;a->b49=1;a->b36=0;
 a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 if(!a->sdc.w130)a->f52+=-186.66666f;else a->f52-=-186.66666f;
 a->f56+=171.42856f;
 A(a)->b13e=A(a)->b13f=93;
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->f92=-13.33333302f;if(a->sdc.w130)a->f92=-a->f92;
 A(a)->b1a1=58;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0; goto c; c: dat_0c2f83f8->arr[a->b2]++;
 A(a)->b1a1|=16;
 a->pad11[0]=67;a->pad11[1]=66;
 func_0c02a0c4(a,23,0);
 func_0c143552(a,owner);
}
void func_0c143552(struct LinkedActor *a,struct LinkedActor *owner)
{
 if((unsigned char)A(owner)->b159!=22) goto x; if(!func_0c028642(a)){x:a->b4++;return;}
 table_0c24f908[(unsigned char)a->b5](a,owner);
}
