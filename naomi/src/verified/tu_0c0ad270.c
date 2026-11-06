#include "objects.h"
extern unsigned int dat_0c244774[];
extern unsigned char dat_0c2446cc[],dat_0c2446dc[],dat_0c2446ec[],dat_0c2446fc[],dat_0c24470c[],dat_0c24471c[];
extern unsigned char dat_0c24472c[],dat_0c244730[],dat_0c244734[],dat_0c244738[],dat_0c24473c[],dat_0c244740[];
extern unsigned char dat_0c244744[],dat_0c244748[],dat_0c24474c[],dat_0c244750[],dat_0c244754[],dat_0c244758[];
extern unsigned char dat_0c24475c[],dat_0c244760[],dat_0c244764[],dat_0c244768[],dat_0c24476c[],dat_0c244770[];
extern void (*table_0c2447e4[])(struct Actor *),(*table_0c2447f4[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *),func_0c046dd0(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *),func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
extern void func_0c044cbc(struct Actor *),func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
unsigned char func_0c0ad324(struct Actor *a),func_0c0ad3b0(struct Actor *a),func_0c0ad40e(struct Actor *a),func_0c0ad454(struct Actor *a);
unsigned char func_0c0ad4dc(struct Actor *a),func_0c0ad522(struct Actor *a),func_0c0ad592(struct Actor *a),func_0c0ad5e4(struct Actor *a);
unsigned char func_0c0ad61a(struct Actor *a);
int func_0c0ad654(struct Actor *a);
static void ground_0c0ad74e(struct Actor *a),air_0c0ad7f8(struct Actor *a),kground_0c0ad8ca(struct Actor *a),kair_0c0ad9a4(struct Actor *a);
void func_0c0ada7a(struct Actor *a);
static void punch_0c0adab4(struct Actor *a),kick_0c0adbe0(struct Actor *a);
void func_0c0ad270(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c244774;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}
void func_0c0ad28c(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c0ad4dc(a))return;
 if(func_0c0ad522(a))return;
 if(func_0c0ad40e(a))return;
 if(func_0c0ad454(a))return;
 if(func_0c0ad324(a))return;
 if(func_0c0ad3b0(a))return;
 if(func_0c0ad654(a))return;
 if(func_0c0ad61a(a))return;
 func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c0ad324(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(!func_0c046e7e(a,dat_0c2446cc,a->x36c))return 0;
 else if(sub->b0>=2)return 0;
 func_0c047aac(a,a->x36c);
 {int zero=0;a->b5=zero;a->b6=zero;a->b7=zero;a->b1e9=zero;}
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0ad3b0(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(!func_0c046e7e(a,dat_0c2446dc,a->x394))return 0;
 else if(sub->b0>=2)return 0;
 func_0c047aac(a,a->x394);
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=8;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0ad40e(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c2446ec,a->x374))return 0;
 func_0c047aac(a,a->x374);
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=1;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0ad454(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c2446fc,a->x37c))goto fail;
 if(a->b1f9==2){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x37c);
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=2;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0ad4dc(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24470c,a->x384))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=3;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0ad522(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24471c,a->x38c))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=5;
 func_0c045248(a,29);return 1;
}
int func_0c0ad568(struct Actor *a)
{
 if(func_0c0ad5e4(a)||func_0c0ad592(a))return 1;
 return 0;
}
unsigned char func_0c0ad592(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24470c,a->x384))return 0;
 else if(!*a->p40c)return 0;
 a->b258=3;return 1;
}
unsigned char func_0c0ad5e4(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24471c,a->x38c))return 0;
 else if(!*a->p40c)return 0;
 a->b258=5;return 1;
}
unsigned char func_0c0ad61a(struct Actor *a)
{
 if(!func_0c046dd0(a,6))return 0;
 a->b1e9=6;a->b5=0;
 func_0c045248(a,21);
 a->b6=a->b7=0;return 1;
}
int func_0c0ad654(struct Actor *a)
{
 if(!func_0c046d54(a))return 0;
 else if(!*a->p40c)return 0;
 a->b1e9=7;a->b5=0;
 func_0c045248(a,29);
 a->b6=a->b7=0;return 1;
}
void func_0c0ad694(struct Actor *a)
{
 if(a->b1d1==29&&a->b1e9==3)*(struct LinkedActorVec3 *)&a->f80=a->v284;
}
void func_0c0ad6be(struct Actor *a){table_0c2447e4[a->b1ff](a);}
void func_0c0ad6d2(struct Actor *a){func_0c044cbc(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)kair_0c0ad9a4(a);else kground_0c0ad8ca(a);}else if(a->b1f9==1)air_0c0ad7f8(a);else ground_0c0ad74e(a);}
static void ground_0c0ad74e(struct Actor *a)
{
 int zero=0,one=1;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=zero;func_0c0346da(a,20);a->p3f4=dat_0c24472c;a->b1a7=zero;break;
 case 1:a->b158=one;a->b1a1=one;func_0c0346da(a,21);a->p3f4=dat_0c244730;a->b1a7=one;break;
 case 2:a->b158=2;a->b1a1=2;a->p3f4=dat_0c244734;a->b1a7=2;func_0c0346da(a,22);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,7,a->b158);
}
static void air_0c0ad7f8(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=6;func_0c0346da(a,20);a->p3f4=dat_0c24472c;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=7;func_0c0346da(a,21);a->p3f4=dat_0c244730;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=8;a->p3f4=dat_0c244734;a->b1a7=2;func_0c0346da(a,22);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,9,a->b158);
}
static void kground_0c0ad8ca(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=3;func_0c0346da(a,20);a->p3f4=dat_0c244738;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=4;func_0c0346da(a,21);a->p3f4=dat_0c24473c;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=5;a->p3f4=dat_0c244740;a->b1a7=2;func_0c0346da(a,22);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,8,a->b158);
}
static void kair_0c0ad9a4(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=9;func_0c0346da(a,20);a->p3f4=dat_0c244738;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=10;func_0c0346da(a,21);a->p3f4=dat_0c24473c;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=11;a->p3f4=dat_0c244740;a->b1a7=2;func_0c0346da(a,22);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,10,a->b158);
}
void func_0c0ada52(struct Actor *a)
{
 if((a->b1fe==0&&(a->b1d6&15))||(a->b1fe!=0&&(a->b1d6&0xf0)))func_0c0ada7a(a);
}
void func_0c0ada7a(struct Actor *a)
{
 if((unsigned char)a->b1fe==1)kick_0c0adbe0(a);
 else punch_0c0adab4(a);
}
static void punch_0c0adab4(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:
  a->b158=zero;a->b1a1=12;func_0c0346da(a,20);
  if(!a->b1fc)a->p3f4=dat_0c244744;else a->p3f4=dat_0c24475c;
  a->b1a7=zero;break;
 case 1:
  a->b158=1;a->b1a1=13;func_0c0346da(a,21);
  if(!a->b1fc)a->p3f4=dat_0c244748;else a->p3f4=dat_0c244760;
  a->b1a7=1;break;
 case 2:
  a->b158=2;a->b1a1=14;func_0c0346da(a,22);
  if(!a->b1fc)a->p3f4=dat_0c24474c;else a->p3f4=dat_0c244764;
  a->b1a7=2;func_0c0346da(a,22);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,11,a->b158);
 if(a->b1d6&15)a->b1d6--;
}
static void kick_0c0adbe0(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:
  a->b158=zero;a->b1a1=15;func_0c0346da(a,20);
  if(!a->b1fc)a->p3f4=dat_0c244750;else a->p3f4=dat_0c244768;
  a->b1a7=zero;break;
 case 1:
  a->b158=1;a->b1a1=16;func_0c0346da(a,21);
  if(!a->b1fc)a->p3f4=dat_0c244754;else a->p3f4=dat_0c24476c;
  a->b1a7=1;break;
 case 2:
  a->b158=2;a->b1a1=17;func_0c0346da(a,22);
  if(!a->b1fc)a->p3f4=dat_0c244758;else a->p3f4=dat_0c244770;
  a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,12,a->b158);
 if(a->b1d6&0xf0)a->b1d6-=16;
}
void func_0c0adcce(struct Actor *a){table_0c2447f4[a->b1ff](a);}
