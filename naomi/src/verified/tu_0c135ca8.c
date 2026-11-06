/* func_0c135ca8..func_0c135e5c: owner-copy init falling into the linked-actor follow step. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern void func_0c02a18c(struct LinkedActor *, int, int, char);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c135d34(struct LinkedActor *a);

void func_0c135ca8(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.b12c=0;a->b33=0;a->f56=A(a->p24)->f41c;a->b36=0;
 a->pad11[0]=71;a->pad11[1]=1;
 func_0c135d34(a);
}

void func_0c135d34(struct LinkedActor *a)
{
 struct LinkedActor *p=a->p24;
 char c;
 unsigned char k;
 if(A(a)->b1a0)A(p)->b1a0=A(a)->b1a0--;
 a->sdc.b12c=0;
 if(A(p)->b1f9==2&&!A(p)->b1fc&&p->f56!=A(p)->f41c&&(c=((char *)&A(p)->w150)[0])!=0&&((char *)&A(p)->w150)[1]!=36&&(unsigned char)p->b5!=1&&A(p)->b1ff!=2){
 switch(A(p)->b1e8){
 case 0:k=15;break;
 case 1:k=16;break;
 case 2:k=17;break;
 default:return;
 }
 a->sdc.b12c=1;
 a->sdc.w130=p->sdc.w130;
 a->f52=p->f52;
 if(A(p)->b14f!=a->b33){
  a->b33=A(p)->b14f;
  A(a)->b1a1=k;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 }
 func_0c02a18c(a,20,6,c);
 if(A(p)->b14f)func_0c037d0c(a);
 }
}

void func_0c135e4e(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;}

void func_0c135e5c(struct LinkedActor *a){func_0c037688(a);}
