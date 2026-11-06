#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c256244[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
void func_0c18c23c(struct LinkedActor *),func_0c18c2d8(struct LinkedActor *);
struct LinkedActor *func_0c18c1bc(struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,4,0))){a->p16=func_0c18c23c;a->p24=owner;a->w38=0;}
 return a;
}
void func_0c18c1e8(register struct LinkedActor *a)
{
 register int mode=*((char *)&A(a->p24)->w150+1);
 if(mode){a->sdc.b12c=1;
 if(a->s28!=mode){func_0c02a0c4(a,23,mode);a->s28=mode;return;}
 func_0c02a026(a);}
 if(A(a->p24)->b0)a->s28=*((char *)&A(a->p24)->w150+1);
}
void func_0c18c23c(struct LinkedActor *a){table_0c256244[a->b4](a);}
void func_0c18c24e(struct LinkedActor *a)
{
 int zero;
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;
 zero=0;a->b36=a->p24->b36;a->sdc.b12c=zero;a->b36=zero;a->s28=zero;
 a->f52=a->p24->f52;a->f56=a->p24->f56;func_0c18c2d8(a);
}
void func_0c18c2d8(struct LinkedActor *a)
{
 a->sdc.b12c=0;
 if(a->p24->sdc.b12c){a->f52=a->p24->f52;a->f56=a->p24->f56;a->sdc.w130=a->p24->sdc.w130;func_0c18c1e8(a);}
}
