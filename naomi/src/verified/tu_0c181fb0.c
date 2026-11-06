/* Spawn pair, single spawn, dispatcher, owner-copy init and random-offset init. func_0c02849a returns unsigned: that keeps b34+59 computed before the call. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c2556d8[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c2556e8[])(struct LinkedActor *,struct LinkedActor *);
extern unsigned char table_0c2556f4[][2];
struct Glob_0c2f83f8 { unsigned char pad[0x7c]; short w7c[1]; };
extern struct Glob_0c2f83f8 *dat_0c2f83f8;
extern unsigned int func_0c02849a(void);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
#define A(a) ((struct Actor *)(a))
void func_0c18206e(struct LinkedActor *);
struct LinkedActor *func_0c181fb0(struct LinkedActor *p,unsigned short k)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c18206e;a->p24=p;a->b1=p->b1;a->w38=0x3602;a->b32=k>>8;a->b33=k;a->b34=0;}
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c18206e;a->p24=p;a->b1=p->b1;a->w38=0x3602;a->b32=k>>8;a->b33=k;a->b34=4;}
 return a;
}
struct LinkedActor *func_0c18202a(struct LinkedActor *p,unsigned short k)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c18206e;a->p24=p;a->b1=p->b1;a->w38=0x3602;a->b32=k>>8;a->b33=k;}
 return a;
}
void func_0c18206e(struct LinkedActor *a){table_0c2556d8[a->b4](a,a->p24);}
void func_0c182090(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 A(a)->i204=A(owner->p24)->f41c;
 A(a)->b19c=66;A(a)->b19d=66;
 A(a)->b1a1=table_0c2556f4[A(a)->b33][0];
 A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;
 dat_0c2f83f8->w7c[a->b2]++;
 table_0c2556e8[a->b32](a,owner);
}
void func_0c182146(struct LinkedActor *a,struct LinkedActor *owner)
{
 int d;
 a->b36=0;
 d=(unsigned char)func_0c02849a()*3;
 a->f52=owner->f52+(short)(((unsigned)d>>2)-96)*1.66666663f;
 a->f56=A(owner->p24)->f41c;
 a->f92=(owner->f52-a->f52)/24.0f;
 a->f96=(owner->f56-a->f56)/24.0f;
 a->f104=a->f108=0.0f;
 a->s28=24;
 func_0c02a0c4(a,22,a->b34+59+(func_0c02849a()&3));
 func_0c18202a(a,0x200);
}
