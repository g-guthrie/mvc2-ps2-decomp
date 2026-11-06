/* Private complete effects chain. Retail control flow includes continuations across pools. */
#include "objects.h"
#define L(a) ((struct LinkedActor *)(a))
#define TIMER(a) ((short *)&(a)->i204)
extern struct Actor *func_0c0374da(int,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void func_0c037d0c(struct Actor *),func_0c037688(struct Actor *);
extern void func_0c025900(struct Actor *,char,char),func_0c0344a0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c255954[])(struct Actor *,struct Actor *),(*table_0c255958[])(struct Actor *),(*table_0c255968[])(struct Actor *,struct Actor *),(*table_0c255970[])(struct Actor *,struct Actor *);
extern char table_0c255924[];
void func_0c184e6e(struct Actor *),func_0c185018(struct Actor *,struct Actor *);
struct Actor *func_0c184e20(struct Actor *owner,unsigned char mode,unsigned char value)
{struct Actor *a;if((a=func_0c0374da(0,1,0))){L(a)->p16=(void (*)(struct LinkedActor *))func_0c184e6e;a->w38=0x3702;L(a)->p24=L(owner);a->b1=owner->b1;a->b32=mode;a->b33=value;}return a;}
void func_0c184e6e(register struct Actor *a)
{table_0c255954[a->b32](a,(struct Actor *)L(a)->p24);}
void func_0c184e84(struct Actor *a)
{table_0c255958[a->b4](a);}
void func_0c184e96(struct Actor *a,struct Actor *owner)
{
 short *timer=&L(a)->wcc.short_value;unsigned int zero;int one=1;
 a->b4++;L(a)->sdc=L(owner)->sdc;a->b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->f80=owner->f80;a->f84=owner->f84;a->b1a3=owner->b1a3;a->pad7cc[0]=owner->pad7cc[0];L(a)->b48=L(owner)->b48;L(a)->v80=L(owner)->v80;
 a->b36=owner->b36;a->b12c=one;L(a)->b49=2;zero=0;*timer=zero;a->s28=zero;
 a->b1a1=55;a->w1ac=zero;a->b19e=zero;a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 a->pad178[0x19c-0x178]=66;a->b19d=66;a->f60=owner->f60;
 owner->f92=0;owner->f96=0;owner->f104=0;owner->f108=0;
 a->f92=20.0f;func_0c02a0c4(a,22,10);func_0c185018(a,owner);
}
void func_0c184f70(struct Actor *a,struct Actor *owner)
{short *timer=TIMER(a);struct MotionGlobal_0c2d9260 *global=&dat_0c2d9260;
 timer[1]=!a->w130?global->f8c:global->f88;
 if((float)*timer>600.0f)*timer=600;
}
void func_0c184fe0(struct Actor *a,struct Actor *owner)
{short *timer=TIMER(a);*timer+=a->f92;}
void func_0c184ff8(struct Actor *a,struct Actor *owner)
{short *timer=TIMER(a);int value=*timer;if(!a->w130)value=-value;value=(short)value;value+=timer[1];a->f52=value;}
void func_0c185018(register struct Actor *a,struct Actor *owner)
{if(owner->b5 || (unsigned char)owner->b159!=22) {a->b4++;return;}a->b36=12;table_0c255968[a->b5](a,owner);}
void func_0c185064(struct Actor *a,struct Actor *owner)
{
 short *timer=(short *)&a->i204;int zero;
 func_0c184f70(a,owner);
 if(a->b1a0)a->b1a0--;
 zero=0;
 if(a->s28)a->s28--;
 if(!a->b1a0){
  func_0c184fe0(a,owner);func_0c184ff8(a,owner);
  if(!a->s28){
   func_0c037d0c(a);
   if(a->b19e){
    a->s28=8;a->b1a1=55;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
    dat_0c2f83f8->arr[a->b2]++;
   }
  }
 }
 if(!((float)*timer<600.0f)){
  *timer=600;func_0c184ff8(a,owner);
  if(owner->b255==4 || owner->b255==5)a->b1a1=75;else {goto M;M:a->b1a1=56;}
  a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;goto L;L:
  func_0c025900(owner,13,0);dat_0c2d9260.b5=3;dat_0c2d9260.b6=1;
  a->s28=48;a->s30=24;a->b5++;func_0c0344a0(a,30);
 }
}

void func_0c1851a4(struct Actor *a,struct Actor *owner)
{char dx;func_0c184f70(a,owner);func_0c184ff8(a,owner);
 if(a->s30){a->s30--;func_0c037d0c(a);}dx=table_0c255924[a->s30];if(a->w130)dx=-dx;a->f52+=dx;
 if(a->s28--==0){a->b4++;a->b5=0;}}
void func_0c185208(register struct Actor *a,struct Actor *owner)
{a->b36=12;table_0c255970[a->b6](a,owner);}
void func_0c185222(struct Actor *a,struct Actor *owner)
{a->b6++;a->f92=-26.666666031f;a->s28=8;}
void func_0c185236(struct Actor *a,struct Actor *owner)
{struct ActorSub2a4 *context=&owner->sub2a4;func_0c184f70(a,owner);func_0c184ff8(a,owner);if(a->s28--==0){*((unsigned char *)&context->s18)=1;a->b6++;}}
void func_0c18527a(struct Actor *a,struct Actor *owner)
{short *timer=TIMER(a);func_0c184f70(a,owner);func_0c184fe0(a,owner);func_0c184ff8(a,owner);if(*timer<0)a->b4++;}
void func_0c1852b6(struct Actor *a,struct Actor *owner)
{a->b12c=0;func_0c037688(a);}
