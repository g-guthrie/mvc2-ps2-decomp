/* Candidate: func_0c08b606 allocates the one/zero constants and the command byte to different registers than retail and is four bytes shorter, which shifts func_0c08b5ee's pool loads; every other function is exact. */
#include "objects.h"
typedef void (*handler_0c08b720)(struct Actor *);
extern unsigned char dat_0c2425d4[];
extern unsigned char dat_0c2425d8[];
extern unsigned char dat_0c2425dc[];
extern unsigned char dat_0c2425e0[];
extern unsigned char dat_0c2425e4[];
extern unsigned char dat_0c2425e8[];
extern unsigned char dat_0c24261c[];
extern unsigned char dat_0c24262a[];
extern unsigned char dat_0c242638[];
extern unsigned char dat_0c242648[];
extern unsigned char dat_0c24265c[];
extern unsigned char dat_0c24266c[];
extern unsigned char dat_0c24267c[];
extern unsigned int dat_0c24268c[];
extern unsigned char dat_0c2426fc[];
extern unsigned char dat_0c24270c[];
struct AttackPair_0c08b606 { unsigned char b32, b33; };
extern struct AttackPair_0c08b606 dat_0c24271c[];
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
extern unsigned char func_0c047068(struct Actor*,unsigned char*,unsigned char*);
extern void func_0c047aac(struct Actor*,unsigned char*);
extern handler_0c08b720 table_0c242730[];
void func_0c08b154(struct Actor *a);
void func_0c08b170(struct Actor *a);
unsigned char func_0c08b210(struct Actor *a);
unsigned char func_0c08b292(struct Actor*a);
unsigned char func_0c08b2d8(struct Actor*a);
unsigned char func_0c08b31e(struct Actor*a);
unsigned char func_0c08b38c(struct Actor*a);
unsigned char func_0c08b3d2(struct Actor*a);
unsigned char func_0c08b418(struct Actor*a);
int func_0c08b45e(struct Actor *a);
int func_0c08b4bc(struct Actor*a);
int func_0c08b4fc(struct Actor *a);
int func_0c08b528(struct Actor *a);
int func_0c08b55e(struct Actor *a);
int func_0c08b594(struct Actor *a);
void func_0c08b5ee(struct Actor *a);
void func_0c08b606(struct Actor *a);
void func_0c08b6fc(struct Actor *a);
void func_0c08b720(struct Actor *a);
void func_0c08b734(struct Actor *a);
void func_0c08b77c(struct Actor *a);
void func_0c08b840(struct Actor *a);
void func_0c08b8d8(struct Actor *a);
void func_0c08b9a4(struct Actor *a);

void func_0c08b154(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c24268c;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

void func_0c08b170(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c08b38c(a))return;
 if(func_0c08b3d2(a))return;
 if(func_0c08b418(a))return;
 if(func_0c08b210(a))return;
 if(func_0c08b292(a))return;
 if(func_0c08b2d8(a))return;
 if(func_0c08b31e(a))return;
 if(func_0c08b4bc(a))return;
 if(func_0c08b45e(a))return;
 func_0c045f1c(a);
 func_0c0463fc(a);
}

unsigned char func_0c08b210(struct Actor *a)
{
 int zero;
 if(!func_0c047068(a,dat_0c24261c,a->x36c))return 0;
 func_0c047aac(a,a->x36c);
 zero=0;
 a->b5=zero;
 if(!a->b411)a->b6=zero;
 a->b7=zero;
 a->b1e9=zero;
 func_0c045248(a,21);return 1;
}

unsigned char func_0c08b292(struct Actor*a){if(!func_0c047068(a,dat_0c24262a,a->x374))return 0;func_0c047aac(a,a->x374);a->b5=0;a->b7=0;a->b6=0;a->b1e9=5;func_0c045248(a,21);return 1;}

unsigned char func_0c08b2d8(struct Actor*a){if(!func_0c046e7e(a,dat_0c242638,a->x37c))return 0;func_0c047aac(a,a->x37c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;func_0c045248(a,21);return 1;}

unsigned char func_0c08b31e(struct Actor*a){if(!func_0c046e7e(a,dat_0c242648,a->x384))return 0;func_0c047aac(a,a->x384);a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;func_0c045248(a,21);return 1;}

unsigned char func_0c08b38c(struct Actor*a){if(!func_0c046e7e(a,dat_0c24265c,a->x38c))return 0;else if(!*a->p40c)return 0;a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;func_0c045248(a,29);return 1;}

unsigned char func_0c08b3d2(struct Actor*a){if(!func_0c046e7e(a,dat_0c24266c,a->x394))return 0;else if(!*a->p40c)return 0;a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;func_0c045248(a,29);return 1;}

unsigned char func_0c08b418(struct Actor*a){if(!func_0c046e7e(a,dat_0c24267c,a->x39c))return 0;else if(!*a->p40c)return 0;a->b5=0;a->b7=0;a->b6=0;a->b1e9=10;func_0c045248(a,29);return 1;}

int func_0c08b45e(struct Actor *a)
{
    if (!func_0c046dd0(a, 9)) return 0;
    a->b1e9 = 9;
    a->b5 = 0;
    func_0c045248(a, 21);
    a->b6 = a->b7 = 0;
    return 1;
}

int func_0c08b4bc(struct Actor*a){if(!func_0c046d54(a))return 0;else if(!*a->p40c)return 0;a->b1e9=11;a->b5=0;func_0c045248(a,29);a->b6=(((char*)a)[7]=0);return 1;}

int func_0c08b4fc(struct Actor *a)
{
    if (func_0c08b528(a) || func_0c08b55e(a) || func_0c08b594(a))
        return 1;
    return 0;
}

int func_0c08b528(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24265c, (unsigned char *)a + 0x38c))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 3;
    return 1;
}

int func_0c08b55e(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24266c, (unsigned char *)a + 0x394))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 6;
    return 1;
}

int func_0c08b594(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24267c, (unsigned char *)a + 0x39c))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 10;
    return 1;
}

void func_0c08b5ee(struct Actor *a)
{
 a->w3e4=2;
 func_0c08b606(a);
 func_0c08b6fc(a);
}

void func_0c08b606(struct Actor *a)
{
 unsigned short v;
 int m;
 int one;
 int zero;
 one=1;
 m=a->b1e9;
 zero=0;
 if(m && m!=5)return;
 if(a->b6)return;
 m=a->b7;
 if(m!=1 && m!=2)return;
 if(!a->b525){
  if(a->w34e&96){
   if(a->w34e&64)a->b32=zero;else a->b32=one;
   v=(a->w34a&0x3c00)>>10;
   if(!a->b1e9)a->b33=dat_0c2426fc[v];else a->b33=dat_0c24270c[v];
  }else{a->b35=zero;goto tail;}
 }else{
  if(a->b411)goto tail;
  a->b32=dat_0c24271c[a->b1fe].b32;
  a->b33=dat_0c24271c[a->b1fe].b33;
 }
 a->b35=one;
tail:
 if(a->b19e && (a->b19e&one))a->b35=zero;
}

void func_0c08b6fc(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(a->b1e9==3 && sub->b2){sub->b2--;a->b1f4=2;}
}

void func_0c08b720(struct Actor *a)
{
 table_0c242730[a->b1ff](a);
}

void func_0c08b734(struct Actor *a){func_0c044cbc(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c08b9a4(a);else func_0c08b8d8(a);}else if(a->b1f9==1)func_0c08b840(a);else func_0c08b77c(a);}

void func_0c08b77c(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=zero;a->p3f4=dat_0c2425d4;a->b1a7=zero;func_0c0346da(a,20);break;
 case 1:a->b158=1;a->b1a1=1;a->p3f4=dat_0c2425d8;a->b1a7=1;func_0c0346da(a,21);break;
 case 2:a->b158=2;a->b1a1=2;a->p3f4=dat_0c2425dc;a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,7,a->b158);
}

void func_0c08b840(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=6;a->p3f4=dat_0c2425d4;a->b1a7=zero;func_0c0346da(a,20);break;
 case 1:a->b158=1;a->b1a1=7;a->p3f4=dat_0c2425d8;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=8;a->p3f4=dat_0c2425dc;a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,9,a->b158);
}

void func_0c08b8d8(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=3;func_0c0346da(a,20);a->p3f4=dat_0c2425e0;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=4;func_0c0346da(a,21);a->p3f4=dat_0c2425e4;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=5;a->p3f4=dat_0c2425e8;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,8,a->b158);}

void func_0c08b9a4(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=9;func_0c0346da(a,20);a->p3f4=dat_0c2425e0;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=10;a->p3f4=dat_0c2425e4;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=11;a->p3f4=dat_0c2425e8;a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,10,a->b158);
}
