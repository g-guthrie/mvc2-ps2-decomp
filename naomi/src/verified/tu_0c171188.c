#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c037688(struct LinkedActor *),func_0c037d0c(struct LinkedActor *),func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void (*table_0c252840[])(struct LinkedActor *,struct LinkedActor *),(*table_0c252844[])(struct LinkedActor *,struct LinkedActor *),(*table_0c252854[])(struct LinkedActor *,struct LinkedActor *);
extern char dat_0c25283c[],dat_0c252834[];
extern short dat_0c25282c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c1711d6(struct LinkedActor *),func_0c171302(struct LinkedActor *,struct LinkedActor *),func_0c171380(struct LinkedActor *,struct LinkedActor *),func_0c1713c8(struct LinkedActor *);
struct LinkedActor *func_0c171188(struct LinkedActor *owner,unsigned char mode,unsigned char value)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c1711d6;a->w38=0x2e01;a->p24=owner;a->b1=owner->b1;*(&a->b32)=mode;*(&a->b33)=value;}
 return a;
}
void func_0c1711d6(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 if((unsigned char)A(owner)->b159!=21)func_0c1713c8(a);
 else{goto dispatch;dispatch:table_0c252840[a->b32](a,owner);}
}
void func_0c1711fe(struct LinkedActor *a,struct LinkedActor *owner){table_0c252844[a->b4](a,owner);}
void func_0c171224(struct LinkedActor *a,struct LinkedActor *owner)
{
 int one,zero;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=one;a->b49=one;a->f60=owner->f60;zero=0;
 A(a)->b1a1=dat_0c25283c[(unsigned char)a->b33];A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 a->pad11[0]=66;a->pad11[1]=66;
 func_0c02a0c4(a,23,dat_0c252834[(unsigned char)a->b33+(unsigned char)owner->b1a3*4]);
 if((unsigned char)a->b33&2)A(a)->w130^=1;
 func_0c171302(a,owner);
}
void func_0c171302(struct LinkedActor *a,struct LinkedActor *owner){table_0c252854[(unsigned char)a->b5](a,owner);}
void func_0c171314(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b36=owner->b36;a->f52=owner->f52;a->f56=owner->f56;
 a->f56+=dat_0c25282c[(unsigned char)a->b33]*2.1428571f;
 func_0c037d0c(a);
 if(func_0c02a026(a)<0){a->b4++;func_0c171380(a,owner);}
}
void func_0c171380(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c1713c8(struct LinkedActor *a){a->sdc.b12c=0;func_0c037688(a);}
