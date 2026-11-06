/* Verified: whole 2944-byte unit at 0x0c07a838. */
#include "objects.h"
extern void (*dat_0c2416a8[])(struct Actor *);
extern void (*dat_0c2416b8[])(struct Actor *);
extern unsigned char dat_0c2415ac[];
extern unsigned char dat_0c2415b0[];
extern unsigned char dat_0c2415b4[];
extern unsigned char dat_0c2415a0[],dat_0c2415a4[],dat_0c2415a8[];
extern unsigned char dat_0c2415b8[],dat_0c2415bc[],dat_0c2415c0[],dat_0c2415c4[],dat_0c2415c8[],dat_0c2415cc[];
extern unsigned char dat_0c2415d0[],dat_0c2415d4[],dat_0c2415d8[],dat_0c2415dc[],dat_0c2415e0[],dat_0c2415e4[];
extern int func_0c02849a(void);
extern void func_0c02a684(struct Actor *,int,int,int);
extern void func_0c192404(struct Actor *,unsigned char);
extern void func_0c13e168(struct Actor *,struct ActorSub2a4 *);
extern void func_0c13c814(struct Actor *,int);
extern unsigned char dat_0c2415e8[];
extern unsigned char dat_0c2415f8[];
extern unsigned char dat_0c241608[];
extern unsigned char dat_0c241618[];
extern unsigned char dat_0c241628[];
extern unsigned int dat_0c241638[];
extern struct Tbl_ub3_01*dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor*,int,int);
extern void func_0c0346da(struct Actor*,int);
extern void func_0c044cbc(struct Actor*);
extern void func_0c045248(struct Actor*,int);
extern void func_0c045f1c(struct Actor*);
extern void func_0c0463fc(struct Actor*);
extern unsigned char func_0c0465cc(struct Actor*);
extern unsigned char func_0c0469f4(struct Actor*);
extern unsigned char func_0c046b6c(struct Actor*);
extern unsigned char func_0c046d3c(struct Actor*);
extern int func_0c046d54(struct Actor*);
extern unsigned char func_0c046dd0(struct Actor*,int);
extern unsigned char func_0c046e7e(struct Actor*,unsigned char*,unsigned char*);
extern void func_0c047aac(struct Actor*,unsigned char*);
void func_0c07a838(struct Actor *a);
void func_0c07a854(struct Actor *a);
int func_0c07a8e0(struct Actor*a);
int func_0c07a94c(struct Actor *a);
unsigned char func_0c07a986(struct Actor *a);
unsigned char func_0c07a9ce(struct Actor *a);
unsigned char func_0c07aa2a(struct Actor *a);
unsigned char func_0c07aabc(struct Actor *a);
unsigned char func_0c07ab18(struct Actor *a);
int func_0c07ab80(struct Actor *a);
int func_0c07abc0(struct Actor *a);
void func_0c07abf6(struct Actor *a);
void func_0c07acb8();
void func_0c07accc(struct Actor *a);
void func_0c07ad14(struct Actor *a);
void func_0c07ad5c(struct Actor *a);
void func_0c07ae34(struct Actor *a);
void func_0c07af08(struct Actor *a);
void func_0c07afe0(struct Actor *a);
void func_0c07b08c(struct Actor *a);
void func_0c07b0c4(struct Actor *a);
void func_0c07b220(struct Actor *a);
void func_0c07b356(struct Actor *a);
void func_0c07b37e(struct Actor *a);

void func_0c07a838(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c241638;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

void func_0c07a854(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c07ab18(a))return;
 if(func_0c07aabc(a))return;
 if(func_0c07aa2a(a))return;
 if(func_0c07a986(a))return;
 if(func_0c07a9ce(a))return;
 if(func_0c07a8e0(a))return;
 if(func_0c07a94c(a))return;
 func_0c045f1c(a);
 func_0c0463fc(a);
}

int func_0c07a8e0(struct Actor*a){if(!func_0c046d54(a))return 0;else if(!*a->p40c)return 0;a->b1e9=6;a->b5=0;func_0c045248(a,29);a->b6=(((char*)a)[7]=0);return 1;}

int func_0c07a94c(struct Actor *a)
{
    if (!func_0c046dd0(a, 5)) return 0;
    a->b1e9 = 5;
    a->b5 = 0;
    func_0c045248(a, 21);
    a->b6 = a->b7 = 0;
    return 1;
}

unsigned char func_0c07a986(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c2415f8,a->x36c))return 0;
 func_0c047aac(a,a->x36c);
 a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);{int one=1;a->b1e9=one;return one;}
}

unsigned char func_0c07a9ce(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c241608, a->x384))
        return 0;
    else if (!a->b1fc) {
        if (a->b1d4)
            return 0;
        a->b1d4++;
    }
    func_0c047aac(a, a->x384);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 4;
    func_0c045248(a, 21);
    return 1;
}

unsigned char func_0c07aa2a(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c2415e8,a->x37c))goto fail;
 if(a->b1f9==2 && !a->b1fc){
 if(a->b1d4){fail:return 0;}
 a->b1d4++;
 }
 func_0c047aac(a,a->x37c);
 zero=0;
 a->b5=zero;a->b7=zero;a->b6=zero;a->b1e9=zero;
 func_0c045248(a,21);
 return 1;
}

unsigned char func_0c07aabc(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(!func_0c046e7e(a,dat_0c241618,a->x364))return 0;
 else if(sub->b0)return 0;
 func_0c047aac(a,a->x364);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;
 func_0c045248(a,21);return 1;
}

unsigned char func_0c07ab18(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c241628,a->x374)||!*a->p40c)goto fail;
 if(a->b1f9==2){if(a->b1d4 && !a->b1fc){fail:return 0;}a->b1d4++;}
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;
 func_0c045248(a,29);return 1;
}

int func_0c07ab80(struct Actor *a)
{
 if(func_0c07abc0(a))return 1;
 return 0;
}

int func_0c07abc0(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c241628, (unsigned char *)a + 0x374))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 2;
    return 1;
}

void func_0c07abf6(struct Actor *a)
{
 struct ActorSub2a4Idle *sub=(struct ActorSub2a4Idle *)&a->sub2a4;
 int zero=0;
 sub->b2=zero;
 if(sub->b0&&!sub->b1)sub->b0=zero;
 if(--sub->b4<=0){
  sub->b4=4;
  if(++sub->b5>6){
   sub->b5=zero;
   sub->b4+=func_0c02849a()%48u+16;
  }
  func_0c02a684(a,0,a->b37*7+sub->b5+24,1);
 }
 if(!a->b159&&((unsigned char)a->b158==2||(unsigned char)a->b158==3)&&a->b141){
  func_0c192404(a,a->b141-1);
  a->b141=zero;
 }
}

void func_0c07acb8(a,s)
struct Actor *a;struct ActorSub2a4 *s;
{
 s=&a->sub2a4;
 if(s->b0)func_0c13e168(a,s);
}

void func_0c07accc(struct Actor *a)
{
    dat_0c2416a8[a->b1ff](a);
}

void func_0c07ad14(struct Actor *a){func_0c044cbc(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c07afe0(a);else func_0c07af08(a);}else if(a->b1f9==1)func_0c07ae34(a);else func_0c07ad5c(a);}

void func_0c07ad5c(struct Actor *a)
{
 int zero=0,v;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=zero;func_0c0346da(a,20);a->p3f4=dat_0c2415a0;a->b1a7=zero;break;
 case 1:v=1;a->b158=v;a->b1a1=v;func_0c0346da(a,21);a->p3f4=dat_0c2415a4;a->b1a7=v;break;
 case 2:v=2;a->b158=v;a->b1a1=v;func_0c0346da(a,22);a->p3f4=dat_0c2415a8;a->b1a7=v;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,7,a->b158);
 func_0c07acb8(a);
}

void func_0c07ae34(register struct Actor *a)
{
 register void *zero;zero=0;
 switch(a->b1e8){
 case 0:a->b159=9;a->b158=(int)zero;a->b1a1=6;func_0c0346da(a,20);a->p3f4=dat_0c2415a0;a->b1a7=(int)zero;func_0c07acb8(a);break;
 case 1:a->b159=9;a->b158=1;a->b1a1=7;func_0c0346da(a,21);a->p3f4=dat_0c2415a4;a->b1a7=1;func_0c07acb8(a);break;
 case 2:a->b159=9;a->b158=2;a->b1a1=8;a->p3f4=dat_0c2415a8;func_0c0346da(a,22);a->b1a7=2;func_0c13c814(a,3);func_0c13c814(a,4);break;
 }
 a->w1ac=(int)zero;a->b19e=(int)zero;*(unsigned int*)&a->p1c4=(int)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,9,a->b158);
}

void func_0c07af08(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=3;func_0c0346da(a,20);a->p3f4=dat_0c2415ac;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=4;func_0c0346da(a,21);a->p3f4=dat_0c2415b0;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=5;func_0c0346da(a,22);a->p3f4=dat_0c2415b4;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,8,a->b158);}

void func_0c07afe0(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=9;func_0c0346da(a,20);a->p3f4=dat_0c2415ac;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=10;func_0c0346da(a,21);a->p3f4=dat_0c2415b0;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=11;func_0c0346da(a,22);a->p3f4=dat_0c2415b4;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,10,a->b158);}

void func_0c07b08c(struct Actor *a)
{
 if((unsigned char)a->b1fe==1)func_0c07b220(a);
 else func_0c07b0c4(a);
}

void func_0c07b0c4(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:
  a->b159=11;a->b158=zero;a->b1a1=12;func_0c0346da(a,20);
  if(!a->b1fc)a->p3f4=dat_0c2415b8;else a->p3f4=dat_0c2415d0;
  a->b1a7=zero;func_0c07acb8(a);func_0c13c814(a,2);break;
 case 1:
  a->b159=11;a->b158=1;a->b1a1=13;func_0c0346da(a,21);
  if(!a->b1fc)a->p3f4=dat_0c2415bc;else a->p3f4=dat_0c2415d4;
  a->b1a7=1;func_0c07acb8(a);break;
 case 2:
  a->b159=11;a->b158=2;a->b1a1=14;
  if(a->w1fa&0x1000){a->b158=5;a->b1a1=65;}
  else func_0c07acb8(a);
  func_0c0346da(a,22);
  if(!a->b1fc)a->p3f4=dat_0c2415c0;else a->p3f4=dat_0c2415d8;
  a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,11,a->b158);
 if(a->b1d6&15)a->b1d6--;
}

void func_0c07b220(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:
  a->b158=zero;a->b1a1=15;func_0c0346da(a,20);
  if(!a->b1fc)a->p3f4=dat_0c2415c4;else a->p3f4=dat_0c2415dc;
  a->b1a7=zero;break;
 case 1:
  a->b158=1;a->b1a1=16;func_0c0346da(a,21);
  if(!a->b1fc)a->p3f4=dat_0c2415c8;else a->p3f4=dat_0c2415e0;
  a->b1a7=1;break;
 case 2:
  a->b158=2;a->b1a1=17;
  if(a->w1fa&0x1000){a->b158=5;a->b1a1=18;}
  func_0c0346da(a,22);
  if(!a->b1fc)a->p3f4=dat_0c2415cc;else a->p3f4=dat_0c2415e4;
  a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,12,a->b158);
 if(a->b1d6&0xf0)a->b1d6-=16;
}

void func_0c07b356(struct Actor *a)
{
 if((a->b1fe==0&&(a->b1d6&15))||(a->b1fe!=0&&(a->b1d6&0xf0)))func_0c07b08c(a);
}

void func_0c07b37e(struct Actor *a)
{
    dat_0c2416b8[a->b1ff](a);
}
