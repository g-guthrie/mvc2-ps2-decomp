#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void (*table_0c2556a0[])(struct LinkedActor *,struct LinkedActor *);
void func_0c181b4e(struct LinkedActor *,struct LinkedActor *);
void func_0c181a74(struct LinkedActor *a,struct LinkedActor *owner)
{
 int state;short offset;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;
 a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->b36=0;a->sdc.w130=a->b32;a->b34=0;
 A(a)->pad178[0x19c-0x178]=66;A(a)->b19d=66;
 state=57;if(a->b33)state=58;A(a)->b1a1=state;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 offset=128;if(a->sdc.w130)offset=-128;a->f52+=offset*1.66666663f;
 func_0c02a0c4(a,22,0);func_0c181b4e(a,owner);
}
void func_0c181b4e(struct LinkedActor *a,struct LinkedActor *owner)
{
 int phase=(unsigned char)a->b5;
 if(phase!=0 && phase!=5 && (owner->b1d0!=29 || owner->b5)){a->b5=5;a->s28=1;}
 table_0c2556a0[(unsigned char)a->b5](a,owner);
}
