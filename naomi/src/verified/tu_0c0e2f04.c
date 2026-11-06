#include "objects.h"
extern void (*dat_0c24948c[])(struct Actor *);
extern void (*dat_0c24949c[])(struct Actor *);
extern unsigned char dat_0c249330[];
extern unsigned char dat_0c249334[];
extern unsigned char dat_0c249338[];
extern unsigned char dat_0c24933c[];
extern unsigned char dat_0c249340[];
extern unsigned char dat_0c249344[];
extern unsigned char dat_0c249348[],dat_0c24934c[],dat_0c249350[],dat_0c249354[],dat_0c249358[],dat_0c24935c[];
extern unsigned char dat_0c249360[],dat_0c249364[],dat_0c249368[],dat_0c24936c[],dat_0c249370[],dat_0c249374[];
extern int dat_0c249378;
extern unsigned char dat_0c249388[];
extern unsigned char dat_0c249398[];
extern unsigned char dat_0c2493a8[];
extern unsigned char dat_0c2493b8[];
extern unsigned char dat_0c2493c8[];
extern unsigned char dat_0c2493dc[];
extern unsigned char dat_0c2493ec[];
extern unsigned char dat_0c2493fc[];
extern unsigned char dat_0c24940c[];
extern unsigned int dat_0c24941c[];
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
void func_0c0e2f04(struct Actor *a);
void func_0c0e2f20(struct Actor *a);
unsigned char func_0c0e2ffc(struct Actor *a);
unsigned char func_0c0e3044(struct Actor*a);
unsigned char func_0c0e308a(struct Actor *a);
unsigned char func_0c0e30e6(struct Actor*a);
unsigned char func_0c0e3158(struct Actor*a);
unsigned char func_0c0e319e(struct Actor*a);
unsigned char func_0c0e31e4(struct Actor *a);
unsigned char func_0c0e3268(struct Actor *a);
unsigned char func_0c0e32b8(struct Actor *a);
unsigned char func_0c0e3328(struct Actor *a);
int func_0c0e33a0(struct Actor*a);
int func_0c0e33e0(struct Actor *a);
int func_0c0e341a(struct Actor *a);
int func_0c0e3446(struct Actor *a);
int func_0c0e347c(struct Actor *a);
int func_0c0e34d4(struct Actor *a);
void func_0c0e350a(struct Actor *a);
void func_0c0e350e(struct Actor *a);
void func_0c0e3522(struct Actor *a);
void func_0c0e356a(struct Actor *a);
void func_0c0e3648(struct Actor *a);
void func_0c0e36f4(struct Actor *a);
void func_0c0e37dc(struct Actor *a);
void func_0c0e38b0(struct Actor *a);
void func_0c0e3b84(struct Actor *a);

void func_0c0e2f04(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c24941c;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

void func_0c0e2f20(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c0e3268(a))return;
 if(func_0c0e32b8(a))return;
 if(func_0c0e3328(a))return;
 if(func_0c0e319e(a))return;
 if(func_0c0e2ffc(a))return;
 if(func_0c0e3044(a))return;
 if(func_0c0e308a(a))return;
 if(func_0c0e30e6(a))return;
 if(func_0c0e31e4(a))return;
 if(func_0c0e3158(a))return;
 if(func_0c0e33a0(a))return;
 if(func_0c0e33e0(a))return;
 func_0c045f1c(a);func_0c0463fc(a);
}

unsigned char func_0c0e2ffc(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c249378, a->x36c) == 0)
        return 0;
    func_0c047aac(a, a->x36c);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 0;
    func_0c045248(a, 21);
    return 1;
}

unsigned char func_0c0e3044(struct Actor*a){if(!func_0c046e7e(a,dat_0c249388,a->x374))return 0;func_0c047aac(a,a->x374);a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;func_0c045248(a,21);return 1;}

unsigned char func_0c0e308a(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c249398, a->x37c))
        return 0;
    else if (!a->b1fc) {
        if (a->b1d4)
            return 0;
        a->b1d4++;
    }
    func_0c047aac(a, a->x37c);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 9;
    func_0c045248(a, 21);
    return 1;
}

unsigned char func_0c0e30e6(struct Actor*a){if(!func_0c046e7e(a,dat_0c2493a8,a->x384))return 0;func_0c047aac(a,a->x384);a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;func_0c045248(a,21);return 1;}

unsigned char func_0c0e3158(struct Actor*a){if(!func_0c046e7e(a,dat_0c2493b8,a->x38c))return 0;func_0c047aac(a,a->x38c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;func_0c045248(a,21);return 1;}

unsigned char func_0c0e319e(struct Actor*a){if(!func_0c046e7e(a,dat_0c2493c8,a->x394))return 0;func_0c047aac(a,a->x394);a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;func_0c045248(a,21);return 1;}

unsigned char func_0c0e31e4(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c2493dc, a->x39c))
        return 0;
    else if (!a->b1fc) {
        if (a->b1d4)
            return 0;
        a->b1d4++;
    }
    func_0c047aac(a, a->x39c);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 8;
    func_0c045248(a, 21);
    return 1;
}

unsigned char func_0c0e3268(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c2493ec,a->x3a4))goto fail;
 if(!*a->p40c){fail:return 0;}
 func_0c047aac(a,a->x3a4);a->b5=0;a->b7=0;a->b6=0;a->b1e9=7;func_0c045248(a,29);return 1;
}

unsigned char func_0c0e32b8(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c2493fc,a->x3ac)||!*a->p40c)goto fail;
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}}
 func_0c047aac(a,a->x3ac);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=11;
 func_0c045248(a,29);return 1;
}

unsigned char func_0c0e3328(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24940c,a->x3b4))goto fail;
 if(!*a->p40c){fail:return 0;}
 func_0c047aac(a,a->x3b4);a->b5=0;a->b7=0;a->b6=0;a->b1e9=14;func_0c045248(a,29);return 1;
}

int func_0c0e33a0(struct Actor*a){if(!func_0c046d54(a))return 0;else if(!*a->p40c)return 0;a->b1e9=13;a->b5=0;func_0c045248(a,29);a->b6=(((char*)a)[7]=0);return 1;}

int func_0c0e33e0(struct Actor *a)
{
    if (!func_0c046dd0(a, 5)) return 0;
    a->b1e9 = 5;
    a->b5 = 0;
    func_0c045248(a, 21);
    a->b6 = a->b7 = 0;
    return 1;
}

int func_0c0e341a(struct Actor *a)
{
    if (func_0c0e347c(a) || func_0c0e3446(a) || func_0c0e34d4(a))
        return 1;
    return 0;
}

int func_0c0e3446(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c2493ec, (unsigned char *)a + 0x3a4))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 7;
    return 1;
}

int func_0c0e347c(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c2493fc, (unsigned char *)a + 0x3ac))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 11;
    return 1;
}

int func_0c0e34d4(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24940c, (unsigned char *)a + 0x3b4))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 14;
    return 1;
}

void func_0c0e350a(struct Actor *a) {}

void func_0c0e350e(struct Actor *a)
{
    dat_0c24948c[a->b1ff](a);
}

void func_0c0e3522(struct Actor *a){func_0c044cbc(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c0e37dc(a);else func_0c0e36f4(a);}else if(a->b1f9==1)func_0c0e3648(a);else func_0c0e356a(a);}

/* func_0c0e356a: no twin (174 bytes) */
void func_0c0e356a(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=3;a->b1a1=18;func_0c0346da(a,20);a->p3f4=dat_0c249330;a->b1a7=zero;break;case 1:a->b158=4;a->b1a1=19;func_0c0346da(a,21);a->p3f4=dat_0c249334;a->b1a7=1;break;case 2:a->b158=5;a->b1a1=20;func_0c0346da(a,21);a->p3f4=dat_0c249338;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,7,a->b158);}

void func_0c0e3648(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=6;func_0c0346da(a,20);a->p3f4=dat_0c249330;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=7;func_0c0346da(a,21);a->p3f4=dat_0c249334;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=8;func_0c0346da(a,22);a->p3f4=dat_0c249338;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,9,a->b158);}

/* func_0c0e36f4: no twin (196 bytes) */
void func_0c0e36f4(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=3;func_0c0346da(a,20);a->p3f4=dat_0c24933c;a->b1a7=zero;break;
 case 1:a->b158=4;a->b1a1=22;func_0c0346da(a,21);a->p3f4=dat_0c249340;a->b1a7=1;break;
 case 2:
  if(a->w1fa&0x400){a->b158=5;a->b1a1=23;}
  else{a->b158=2;a->b1a1=5;}
  func_0c0346da(a,22);a->p3f4=dat_0c249344;a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,8,a->b158);
}

void func_0c0e37dc(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=9;func_0c0346da(a,20);a->p3f4=dat_0c24933c;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=10;func_0c0346da(a,21);a->p3f4=dat_0c249340;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=11;func_0c0346da(a,22);a->p3f4=dat_0c249344;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,10,a->b158);}

void func_0c0e38d8(struct Actor *a);
static void punch_0c0e38ea(struct Actor *a);
static void kick_0c0e3a36(struct Actor *a);
void func_0c0e38b0(struct Actor *a)
{
 if((a->b1fe==0&&(a->b1d6&15))||(a->b1fe!=0&&(a->b1d6&0xf0)))func_0c0e38d8(a);
}
void func_0c0e38d8(struct Actor *a)
{
 if((unsigned char)a->b1fe==1)kick_0c0e3a36(a);
 else punch_0c0e38ea(a);
}
static void punch_0c0e38ea(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:
  if(a->b1d3<0)a->b158=zero;else a->b158=3;
  a->b1a1=12;func_0c0346da(a,20);
  if(!a->b1fc)a->p3f4=dat_0c249348;else a->p3f4=dat_0c249360;
  a->b1a7=zero;break;
 case 1:
  if(a->b1d3<0)a->b158=1;else a->b158=4;
  a->b1a1=13;func_0c0346da(a,21);
  if(!a->b1fc)a->p3f4=dat_0c24934c;else a->p3f4=dat_0c249364;
  a->b1a7=1;break;
 case 2:
  if(a->b1d3<0)a->b158=2;else a->b158=5;
  a->b1a1=14;func_0c0346da(a,22);
  if(!a->b1fc)a->p3f4=dat_0c249350;else a->p3f4=dat_0c249368;
  a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,11,a->b158);
 if(a->b1d6&15)a->b1d6--;
}
static void kick_0c0e3a36(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:
  if(a->b1d3<0)a->b158=zero;else a->b158=3;
  a->b1a1=15;func_0c0346da(a,20);
  if(!a->b1fc)a->p3f4=dat_0c249354;else a->p3f4=dat_0c24936c;
  a->b1a7=zero;break;
 case 1:
  if(a->b1d3<0)a->b158=1;else a->b158=4;
  a->b1a1=16;func_0c0346da(a,21);
  if(!a->b1fc)a->p3f4=dat_0c249358;else a->p3f4=dat_0c249370;
  a->b1a7=1;break;
 case 2:
  if(a->b1d3<0)a->b158=2;else a->b158=5;
  a->b1a1=17;func_0c0346da(a,22);
  if(!a->b1fc)a->p3f4=dat_0c24935c;else a->p3f4=dat_0c249374;
  a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,12,a->b158);
 if(a->b1d6&0xf0)a->b1d6-=16;
}

void func_0c0e3b84(struct Actor *a)
{
    dat_0c24949c[a->b1ff](a);
}
