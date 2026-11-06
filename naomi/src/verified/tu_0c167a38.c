#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c251fec[])(struct LinkedActor *),(*table_0c251ffc[])(struct LinkedActor *);
extern void (*table_0c252008[])(struct LinkedActor *),(*table_0c252014[])(struct LinkedActor *);
void func_0c167a96(struct LinkedActor *);
struct LinkedActor *func_0c167a38(struct LinkedActor *owner,char kind,char sub){
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))){
  short *mark;
  a->p16=func_0c167a96;a->p24=owner;a->b32=kind;a->b33=sub;a->w38=0x2300;mark=&a->wcc.short_value;a->b1=owner->b1;
  *mark=owner->sdc.w158.short_value;
  return a;
 }
 return 0;
}
void func_0c167a96(struct LinkedActor *a){table_0c251fec[a->b4](a);}
void func_0c167aae(struct LinkedActor *a);
void func_0c167aa8(struct LinkedActor *a){a->b4++;func_0c167aae(a);}
void func_0c167aae(struct LinkedActor *a){table_0c251ffc[a->b32](a);}
void func_0c167ac2(struct LinkedActor *a){table_0c252008[(unsigned char)a->b5](a);}
void func_0c167ad4(struct LinkedActor *a)
{
 int one,zero;
 a->b5++;a->sdc=a->p24->sdc;one=1;a->sdc.b12c=one;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.b12c=one;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 zero=0;a->b36=zero;
 a->f52=a->p24->f52;a->f56=a->p24->f56+139.28571f;
 if(A(a)->w130){a->f52-=-163.33333f;a->f92=0.8333333135f;}
 else{a->f52-=163.33333f;a->f92=-0.8333333135f;}
 if(!a->b1a3){a->s28=4;A(a)->b1a1=48;}else{a->s28=16;A(a)->b1a1=49;}
 A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 a->pad11[0]=66;a->pad11[1]=66;
 goto tail;tail:func_0c02a0c4(a,23,3);
}
void func_0c167c22(struct LinkedActor *a)
{
 int zero=0,action;short *mark=&a->wcc.short_value;
 if(*mark!=a->p24->sdc.w158.short_value){a->b4=2;a->sdc.b12c=zero;return;}
 a->b36=zero;
 if(A(a)->b19e||A(a)->b19f){a->b5++;A(a->p24)->b1a0=A(a)->b1a0;action=5;}
 else{
  a->s28--;
  if(a->s28>=0)goto move;
  a->b5++;action=4;
 }
 func_0c02a0c4(a,23,action);
 return;
move:
 a->f52+=a->f92;a->f92+=a->f104;func_0c02a026(a);func_0c037d0c(a);
}
void func_0c167cc0(struct LinkedActor *a)
{
 a->b36=0;
 if(func_0c02a026(a)<0){a->sdc.b12c=0;a->b4=2;}
}
void func_0c167ce8(struct LinkedActor *a){table_0c252014[(unsigned char)a->b5](a);}
