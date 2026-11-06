#include "objects.h"
struct InputHistory17c {unsigned short words[16];char read,write,count,pad;};
extern char func_0c02a026(struct Actor *);
extern int func_0c02850e(struct Actor *);
extern void func_0c037d0c(struct Actor *),func_0c0344a0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern short dat_0c253c3a[];
void func_0c17c218(struct Actor *a,struct Actor *owner)
{
 struct InputHistory17c *history=(struct InputHistory17c *)&a->f136;
 int zero=0,two=2;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 history->words[history->write]=owner->w34a;
 if(history->words[history->read]&0x2000)a->f56+=4.28571415f;
 if(history->words[history->read]&0x1000)a->f56-=2.1428571f;
 history->read++;history->write++;history->read&=15;history->write&=15;
 if(a->b19e){a->b4=two;a->b5=zero;}
 if(a->b19f){a->b4=two;a->b5=zero;}
 func_0c02a026(a);func_0c037d0c(a);if(!func_0c02850e(a))a->b4=3;
}
void func_0c17c31a(struct Actor *a)
{
 struct InputHistory17c *history=(struct InputHistory17c *)&a->f136;
 a->b5++;a->f104=a->f108=0.0f;a->s28=dat_0c253c3a[a->b33];history->count=3;func_0c0344a0(a,35);func_0c02a0c4(a,21,24);
}
