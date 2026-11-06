/* Candidate: func_0c07d448 keeps the clamped motion value in a scratch register where retail uses r13 (so r12 is not saved) and rotates r1/r2/r3 differently in the countdown checks; func_0c07d5e6 differs in register choice around the __modls call; func_0c07d0ce and func_0c07d408 differ in one scratch register. Other functions are exact. */
#include "objects.h"
#define TIMER(a,off) (((struct ActorCountdowns *)(a))->l##off)
#define STATE(a) (*(int *)&(a)->sub2a4.w4)
extern void *dat_0c2417dc[];
extern unsigned char dat_0c241824[];
extern unsigned char dat_0c241834[];
extern unsigned char dat_0c241844[];
extern unsigned char dat_0c241854[];
extern unsigned char dat_0c241864[];
extern unsigned char dat_0c241874[];
extern unsigned char dat_0c24187e[];
extern unsigned char dat_0c24188e[];
extern unsigned int dat_0c2418a0[];
extern unsigned char dat_0c241910[];
extern unsigned char dat_0c24191c[];
extern char dat_0c24191f[];
extern char dat_0c24192b[];
extern unsigned char dat_0c241937[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor*,int,int);
extern void func_0c044cbc(struct Actor*);
extern void func_0c045248(struct Actor*,int);
extern void func_0c045f1c(struct Actor*);
extern unsigned char func_0c04608a(struct Actor*,unsigned char*);
extern void func_0c0463fc(struct Actor*);
extern unsigned char func_0c0465cc(struct Actor*);
extern unsigned char func_0c0469f4(struct Actor*);
extern unsigned char func_0c046b6c(struct Actor*);
extern unsigned char func_0c046d3c(struct Actor*);
extern int func_0c046d54(struct Actor*);
extern unsigned char func_0c046dd0(struct Actor*,int);
extern unsigned char func_0c046e7e(struct Actor*,unsigned char*,unsigned char*);
extern unsigned char func_0c04730c(struct Actor*,unsigned char*,unsigned char*);
extern unsigned char func_0c0474f8(struct Actor*,unsigned char*,unsigned char*);
extern void func_0c047aac(struct Actor*,unsigned char*);
extern void func_0c04ae74(struct Actor*,int);
extern void func_0c08151c(struct Actor*,struct Actor*);
void func_0c07cf9c(struct Actor *a);
void func_0c07cfb8(struct Actor *a);
int func_0c07d088(struct Actor *a);
int func_0c07d0ce(struct Actor *a);
int func_0c07d154(struct Actor *a);
int func_0c07d1bc(struct Actor *a);
int func_0c07d202(struct Actor *a);
int func_0c07d248(struct Actor *a);
int func_0c07d280(struct Actor *a);
int func_0c07d2ec(struct Actor *a);
int func_0c07d33c(struct Actor *a);
int func_0c07d37a(struct Actor *a);
int func_0c07d3c8(struct Actor *a);
int func_0c07d408(struct Actor *a);
void func_0c07d448(struct Actor *a);
void func_0c07d5e6(struct Actor *a);

void func_0c07cf9c(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c2418a0;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

void func_0c07cfb8(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c07d2ec(a))return;
 if(func_0c07d280(a))return;
 if(func_0c07d37a(a))return;
 if(func_0c07d154(a))return;
 if(func_0c07d1bc(a))return;
 if(func_0c07d202(a))return;
 if(func_0c07d088(a))return;
 if(func_0c07d0ce(a))return;
 if(func_0c07d248(a))return;
 if(func_0c04608a(a,a->x394))return;
 if(func_0c07d33c(a))return;
 func_0c045f1c(a);
 func_0c0463fc(a);
}

int func_0c07d088(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c241824,a->x36c))return 0;
 func_0c047aac(a,a->x36c);
 a->b1e9=3;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}

int func_0c07d0ce(struct Actor *a)
{
 char k;
 if(!func_0c046e7e(a,dat_0c24187e,a->x3a4))return 0;
 if(STATE(a)==39)goto ok;
 if(STATE(a)==7)goto ok;
 if(STATE(a)==57)goto ok;
 if(STATE(a)==36)goto ok;
 return 0;
ok:
 func_0c047aac(a,a->x3a4);
 k=8;
 if(STATE(a)==7)k=18;
 if(STATE(a)==57)k=18;
 if(STATE(a)==36)k=17;
 a->b1e9=k;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}

int func_0c07d154(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c241834,a->x37c))return 0;
 func_0c047aac(a,a->x37c);
 a->b1e9=13;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}

int func_0c07d1bc(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c241844,a->x38c))return 0;
 func_0c047aac(a,a->x38c);
 a->b1e9=22;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}

int func_0c07d202(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c241854,a->x374))return 0;
 func_0c047aac(a,a->x374);
 a->b1e9=11;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}

int func_0c07d248(struct Actor *a)
{
 if(!func_0c046dd0(a,19))return 0;
 a->b1e9=19;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}

int func_0c07d280(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c241864,a->x384))return 0;
 else if(!*a->p40c)return 0;
 a->b1e9=20;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,29);return 1;
}

int func_0c07d2ec(struct Actor *a)
{
 if(!func_0c0474f8(a,dat_0c24188e,a->x3ac))return 0;
 else if(STATE(a)!=30)return 0;
 else if(*a->p40c<3)return 0;
 a->b1e9=23;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,29);return 1;
}

int func_0c07d33c(struct Actor *a)
{
 if(!func_0c046d54(a))return 0;
 else if(!*a->p40c)return 0;
 a->b1e9=26;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,29);return 1;
}

int func_0c07d37a(struct Actor *a)
{
 if(!func_0c04730c(a,dat_0c241874,a->x39c))return 0;
 else if(STATE(a)!=1)return 0;
 func_0c047aac(a,a->x39c);
 a->b1e9=12;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}

int func_0c07d3c8(struct Actor *a)
{
 if(func_0c07d408(a))return 1;
 return 0;
}

int func_0c07d408(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c241864,a->x384))return 0;
 else if(!*a->p40c)return 0;
 func_0c047aac(a,a->x384);
 a->b258=20;return 1;
}

void func_0c07d448(struct Actor *a)
{
 int three;
 char limit;
 int move;
 three=3;
 if(a->b1a0)goto busy;
 if(a->l2c8)a->l2c8--;
 if(TIMER(a,2f0)>0){TIMER(a,2f0)=TIMER(a,2f0)-1;return;}
 if(TIMER(a,2d0)>0 && --TIMER(a,2d0)<=0)goto act;
 if(TIMER(a,2d4)>0 && --TIMER(a,2d4)<=0)goto act;
 if(TIMER(a,2d8)>0){TIMER(a,2d8)=TIMER(a,2d8)-1;a->w3ea=three;}
 if(TIMER(a,2e8)>0 && !a->pad1d7[0x1dc-0x1d7]){
  TIMER(a,2e8)=TIMER(a,2e8)-1;
  if(!(TIMER(a,2e8)&7))func_0c04ae74(a,1);
 }
 if(TIMER(a,2e0)>0){TIMER(a,2e0)=TIMER(a,2e0)-1;a->w3e4=three;}
 if(TIMER(a,2ec)>0){TIMER(a,2ec)=TIMER(a,2ec)-1;a->w3e4=three;}
 if(TIMER(a,2dc)>0 && --TIMER(a,2dc)<=0)goto act;
 if(TIMER(a,2e4)<=0 || --TIMER(a,2e4)>0)return;
act:
 STATE(a)=a->b1;
 func_0c08151c(a,a);
 if(a->b159)return;
 move=(unsigned char)a->b158;
 if(move==8 || move==9 || move==1){
  three=((char *)&a->w150)[1]-64;
  if(three<0)three=0;
  limit=a->b142;
  func_0c02a0c4(a,0,three);
  if(a->b142>limit)a->b142=limit;
 }
 return;
busy:
 if(TIMER(a,2f0)==0 && TIMER(a,2e0)>0)a->w3e4=three;
}



void func_0c07d5e6(struct Actor *a)
{
 unsigned char k;
 func_0c044cbc(a);
 a->b7=0;a->b6=0;
 k=a->b1e8;
 if(a->b1f9==1)k+=6;
 if(a->b1fe)k+=3;
 a->l320=dat_0c241937[k];
 a->p3f4=dat_0c2417dc[k%6];
 a->b1a7=dat_0c24191c[a->b1e8];
 a->b1a1=dat_0c241910[k];
 a->w1ac=0;a->b19e=0;a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,dat_0c24192b[k],dat_0c24191f[k]);
 if(k==2 && STATE(a)==41 && (a->w34a&0x800)){
  a->l320=5;
  a->s28=60;
  func_0c02a0c4(a,7,3);
 }
}
