/* Candidate: func_0c0fa9de decrements the 0x2b0 countdown in r3 where retail uses r1 (4 bytes); everything else matches. */
#include "objects.h"
extern unsigned char dat_0c24a920[];
extern unsigned char dat_0c24a930[];
extern unsigned char dat_0c24a944[];
extern unsigned char dat_0c24a958[];
extern unsigned char dat_0c24a968[];
extern unsigned char dat_0c24a978[];
extern unsigned int dat_0c24a988[];
extern void func_0c045248(struct Actor*,int);
extern void func_0c045f1c(struct Actor*);
extern unsigned char func_0c0462a0(struct Actor*);
extern void func_0c0463fc(struct Actor*);
extern unsigned char func_0c0465cc(struct Actor*);
extern unsigned char func_0c0469f4(struct Actor*);
extern unsigned char func_0c046b6c(struct Actor*);
extern unsigned char func_0c046d3c(struct Actor*);
extern int func_0c046d54(struct Actor*);
extern unsigned char func_0c046dd0(struct Actor*,int);
extern unsigned char func_0c046e7e(struct Actor*,unsigned char*,unsigned char*);
extern void func_0c047aac(struct Actor*,unsigned char*);
extern unsigned char func_0c047b60(struct Actor*,int,void*,int);
extern unsigned char func_0c0479a6(struct Actor*);
extern unsigned char func_0c047886(struct Actor*);
extern unsigned char dat_0c24a9f8[];
extern struct ActorFlags *dat_0c2d6f84;
extern void func_0c1b4548(struct Actor*,int,int);
extern int func_0c02849a(void);
extern void func_0c02a684(struct Actor*,int,int,int);
extern void func_0c02a39a(struct Actor*,int);
void func_0c0fa384(struct Actor *a);
void func_0c0fa3a0(struct Actor *a);
int func_0c0fa460(struct Actor *a);
int func_0c0fa4b0(struct Actor *a);
int func_0c0fa518(struct Actor *a);
int func_0c0fa5b2(struct Actor *a);
int func_0c0fa634(struct Actor *a);
int func_0c0fa78a(struct Actor *a);
int func_0c0fa7de(struct Actor *a);
int func_0c0fa816(struct Actor *a);
int func_0c0fa88a(struct Actor *a);
int func_0c0fa8f0(struct Actor *a);
int func_0c0fa916(struct Actor *a);
int func_0c0fa97c(struct Actor *a);

void func_0c0fa9de(struct Actor *a);
void func_0c0fa384(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c24a988;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

void func_0c0fa3a0(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c0fa460(a))return;
 if(func_0c0fa518(a))return;
 if(func_0c0fa78a(a))return;
 if(func_0c0fa88a(a))return;
 if(func_0c0fa4b0(a))return;
 if(func_0c0fa5b2(a))return;
 if(func_0c0fa634(a))return;
 if(func_0c0fa7de(a))return;
 if(func_0c0fa816(a))return;
 if(func_0c0462a0(a))return;
 func_0c045f1c(a);
 func_0c0463fc(a);
}

int func_0c0fa460(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a968,a->x384))return 0;
 else if(!*a->p40c)return 0;
 func_0c047aac(a,a->x384);
 a->b1e9=5;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,29);return 1;
}

int func_0c0fa4b0(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a920,a->x364))goto fail;
 func_0c047aac(a,a->x364);
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}}
 a->b1e9=0;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}

int func_0c0fa518(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a944,a->x36c)||!*a->p40c)goto fail;
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}}
 func_0c047aac(a,a->x36c);
 a->b1e9=1;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,29);return 1;
}

int func_0c0fa5b2(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a930,a->x38c))goto fail;
 func_0c047aac(a,a->x38c);
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}}
 a->b1e9=6;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}

/* func_0c0fa634: no twin (298 bytes) */
int func_0c0fa634(struct Actor *a)
{
 unsigned short buf;
 if(!func_0c047b60(a,0x140,&buf,4))goto fail;
 func_0c047aac(a,(void *)&buf);
 if(a->f41c+68.57143f>a->f56){if(a->w34a&0x1000){fail:return 0;}}
 if(a->b1d0==21&&a->b1e9==4){
  if(((struct ActorSubTimers *)&a->sub2a4)->t8)return 0;
  else if(!((struct ActorSubTimers *)&a->sub2a4)->t4)return 0;
  if(!func_0c0479a6(a))return 0;
  if(a->b19e&17)return 0;
  ((struct ActorCountdowns *)a)->l2e0=1;
  ((struct ActorSubTimers *)&a->sub2a4)->t4--;
 }else{
  if(a->b1f9==2&&a->b1d4)return 0;
  else if(!func_0c047886(a))return 0;
  if(a->b525){
   buf=a->w1fa>>10;
   if(a->b1d2){buf&=15;buf=dat_0c24a9f8[buf];}
   ((struct ActorCountdowns *)a)->l2e8=buf;
  }
  ((struct ActorCountdowns *)a)->l2e0=0;
  ((struct ActorSubTimers *)&a->sub2a4)->t4=2;
  ((struct ActorSubTimers *)&a->sub2a4)->t16=1;
  a->b201=0;
 }
 a->b1a3=0;
 a->b1d4++;
 ((struct ActorSubTimers *)&a->sub2a4)->t8=16;
 a->b1e9=4;
 a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);
 return 1;
}

int func_0c0fa78a(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a958,a->x37c))goto fail;
 func_0c047aac(a,a->x37c);
 if(a->b201){((struct ActorSubTimers *)&a->sub2a4)->t16=1;fail:return 0;}
 a->b1e9=3;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}

int func_0c0fa7de(struct Actor *a)
{
 if(!func_0c046dd0(a,8))return 0;
 a->b1e9=8;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}

int func_0c0fa816(struct Actor *a)
{
 if(!func_0c046d54(a))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b1e9=11;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,29);return 1;
}

int func_0c0fa88a(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a978,a->x374))goto fail;
 func_0c047aac(a,a->x374);
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}}
 a->b1e9=12;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}

int func_0c0fa8f0(struct Actor *a)
{
    if (func_0c0fa916(a)) return 1;
    if (func_0c0fa97c(a)) return 1;
    return 0;
}

int func_0c0fa916(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a968,a->x384))return 0;
 else if(!*a->p40c)return 0;
 func_0c047aac(a,a->x384);
 a->b258=5;return 1;
}

int func_0c0fa97c(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a944,a->x36c)||!*a->p40c)goto fail;
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}}
 func_0c047aac(a,a->x36c);
 a->b258=1;return 1;
}
void func_0c0fa9de(struct Actor *a)
{
 int t;
 ((struct ActorSubTimers *)&a->sub2a4)->t0=((signed char *)&a->w150)[1];
 if(((struct ActorSubTimers *)&a->sub2a4)->t8)((struct ActorSubTimers *)&a->sub2a4)->t8=((struct ActorSubTimers *)&a->sub2a4)->t8-1;
 if(a->b201){if(!(((struct ActorSubTimers *)&a->sub2a4)->t16=((struct ActorSubTimers *)&a->sub2a4)->t16-1))a->b201=0;}
 if(!a->b1d0){
  if(--((struct ActorSubTimers *)&a->sub2a4)->t12<0){
   ((struct ActorSubTimers *)&a->sub2a4)->t12=(dat_0c2d6f84->flags&31)+32;
   func_0c1b4548(a,0,func_0c02849a()&1);
  }
 }
 if(((struct ActorCountdowns *)a)->l2e4){((struct ActorCountdowns *)a)->l2e4--;return;}
 goto d;d:if((((struct ActorCountdowns *)a)->l2d0=((struct ActorCountdowns *)a)->l2d0-1)<0){
  ((struct ActorCountdowns *)a)->l2d0=1;
  ((struct ActorCountdowns *)a)->l2d4++;((struct ActorCountdowns *)a)->l2d4=((struct ActorCountdowns *)a)->l2d4&3;
  func_0c02a684(a,1,((struct ActorCountdowns *)a)->l2d4+6,1);
  ((struct ActorCountdowns *)a)->l2d8++;
  if(((struct ActorCountdowns *)a)->l2d8>4)((struct ActorCountdowns *)a)->l2d8=0;
  func_0c02a684(a,2,((struct ActorCountdowns *)a)->l2d8+10,1);
 }
 if(((struct ActorCountdowns *)a)->l2ec>0){
  if(*(short *)&a->b158!=*(short *)&((struct ActorCountdowns *)a)->l2f0){((struct ActorCountdowns *)a)->l2ec=0;func_0c02a39a(a,1);return;}
  t=--((struct ActorCountdowns *)a)->l2ec%6>>1;
  func_0c02a684(a,0,(int)(a->b37*3+16U)+t,1);
 }
}

