#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,char),func_0c02a684(struct Actor *,int,int,int),func_0c1bd8d8(struct Actor *),func_0c02a39a(struct Actor *,int);
extern unsigned char dat_0c2f8338;
void func_0c127002(struct Actor *);
void func_0c126ef4(struct Actor *a)
{
 int command;unsigned short event;
 a->b6++;a->b12c=1;event=a->b37*2+6;command=13;
 if(!a->b525 && !(a->w4dc&0x60)){command=0;event=a->b37*2+5;}
 func_0c02a0c4(a,18,command);func_0c02a684(a,2,event,1);
}
void func_0c126f52(struct Actor *a)
{
 if(dat_0c2f8338>=2){int zero;
  func_0c02a026(a);zero=0;
  if(a->b141){a->b141=zero;a->b6++;func_0c1bd8d8(a);a->s28=-1;}else if(a->b14b)a->b14b=zero;
 }
}
void func_0c126f98(struct Actor *a){func_0c127002(a);func_0c02a026(a);}
void func_0c126fa8(struct Actor *a){func_0c127002(a);a->b6++;func_0c02a0c4(a,18,1);func_0c02a39a(a,0);}
void func_0c126fcc(struct Actor *a)
{
 func_0c127002(a);
 if(func_0c02a026(a)<0){a->b5++;func_0c02a0c4(a,0,0);func_0c02a39a(a,0);}
}
void func_0c127002(struct Actor *a){a->s28++;a->s28&=3;func_0c02a684(a,1,a->s28,1);}
