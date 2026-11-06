#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern int func_0c02849a(void);
extern void func_0c02a18c(struct LinkedActor *, int, int, int);
extern void func_0c02a0c4(struct LinkedActor *, int, int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);

extern const short dat_0c24f224[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c13e266(struct LinkedActor *a);
void func_0c13e3e4(struct LinkedActor *a);
void func_0c13e3f6(struct LinkedActor *a, struct LinkedActor *o);

void func_0c13e1bc(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.b12c=1;
 a->b36=0;
 a->pad11[0]=69;a->pad11[1]=0;
 a->b6=0;
 a->s30=1;
 func_0c02a18c(a,20,3,func_0c02849a()%18);
 func_0c13e266(a);
}

void func_0c13e266(struct LinkedActor *a)
{
 struct LinkedActor *o=a->p24;
 unsigned char *q=(unsigned char *)o+0x2a4;
 float v;
 if(a->b5)goto b5;
 goto L35; L35: if(A(a)->b19e){
  a->b6++;
  A(a)->b19e=0;
  if(--q[1]<=0){
   a->b5++;
   a->sdc.b12c=1;
   func_0c02a0c4(a,20,4);
  }
 }
 if(!q[0])goto adv;
 goto LB0_44; LB0_44:
 if(A(a->p24)->b14b){
  a->sdc.b12c=1;
  a->f52=a->p24->f52;
  a->f56=a->p24->f56;
  v=dat_0c24f224[A(a->p24)->b14b*2]*1.66666663f;
  if(A(a->p24)->w130)v=-v;
  a->f52+=v;
  a->f56-=(&dat_0c24f224[A(a->p24)->b14b*2])[1]*2.1428571f;
 }
 else a->sdc.b12c=0;
 if((unsigned short)a->p24->sdc.w158.short_value!=a->s28)goto adv;
 if(!a->sdc.b12c)return;
 if(a->b6)return;
 if(a->s30)goto dec;
 goto LB1_59; LB1_59:
 if(!A(a->p24)->b14f)return;
 func_0c13e3f6(a,o);
 func_0c037d0c(a);
 return;
dec:
 a->s30--;
 return;
b5:
 goto L5; L5: if(func_0c02a026(a)>=0)return;
adv:
 a->b4++;
 func_0c13e3e4(a);
}

void func_0c13e3e4(struct LinkedActor *a)
{
 a->b4++;
 a->sdc.b12c=0;
 func_0c037688(a);
}

void func_0c13e3f6(struct LinkedActor *a, struct LinkedActor *o)
{
 switch(A(o)->b1a1){
 case 0: case 6: A(a)->b1a1=67; break;
 case 1: case 7: A(a)->b1a1=68; break;
 case 2: case 8: A(a)->b1a1=69; break;
 case 63: A(a)->b1a1=70; break;
 case 13: A(a)->b1a1=71; break;
 case 14: A(a)->b1a1=72; break;
 }
 A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 A(o)->b1a1=A(a)->b1a1;
 A(o)->w1ac=0;A(o)->b19e=0;A(o)->p1c4=0;dat_0c2f83f8->arr[o->b2]++;
}
