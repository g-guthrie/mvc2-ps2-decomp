#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c257d18[])(struct LinkedActor *);
extern short *table_0c257d10[];
extern void func_0c02a0c4(struct LinkedActor *,int,int);
void func_0c194a88(struct LinkedActor *);
int func_0c194a10(struct LinkedActor *owner,int mode)
{
 int i,count;struct LinkedActor *a;
 count=0;
 for(i=0;i<8;i++){
  if((a=func_0c0374da(0,3,1))){a->p16=func_0c194a88;a->w38=0xc00;a->b32=mode;a->b33=i>>1;
   if(i&1)*(unsigned char *)&a->b33|=128;
   a->p20=owner;a->p24=owner->p24;count++;
  }
 }
 return count;
}
void func_0c194a88(register struct LinkedActor *a){table_0c257d18[a->b4](a);}
void func_0c194a9a(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p20;short *row;int bank;
 a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;
 a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->b4++;a->b36=owner->b36;a->b49=owner->b49-4;
 row=table_0c257d10[a->b32];bank=8;
 if((unsigned char)a->b33&128){bank=12;row+=2;a->b33&=127;}
 row+=(unsigned char)a->b33*4;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 a->f52+=*row++*1.66666663f;a->f56+=*row*2.1428571f;
 func_0c02a0c4(a,23,(signed char)a->b32*2+bank);
}
