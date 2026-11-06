/* Owner-follow initialization and update handlers. The owner byte at 0x14b is read
 * through a char view for the compare with a->b34, which keeps it in r2 as retail. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a18c(struct LinkedActor *,int,int,int),func_0c037d0c(struct LinkedActor *);
void func_0c15a85c(struct LinkedActor *);
void func_0c15a7b8(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;
 A(a)->b1a1=56;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 A(a)->b19c=66;A(a)->b19d=66;
 a->b36=0;a->b34=0xff;
 func_0c15a85c(a);
}
void func_0c15a85c(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 a->sdc.b12c=0;
 if(A(owner)->b14b==0xff||a->s30!=owner->sdc.w158.short_value){a->b4=2;return;}
 if(!A(owner)->b14b)return;
 a->sdc.b12c=1;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 {if(((char *)owner)[0x14b]!=(char)a->b34){
  a->b34=A(owner)->b14b;
  func_0c02a18c(a,23,4,a->b34-1);
  if(A(a)->b14b){
   A(a)->b14b=0;A(a)->b1a1=A(a)->b14b+56;
   A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;
   dat_0c2f83f8->arr[a->b2]++;
  }
 }
 }func_0c037d0c(a);
}
