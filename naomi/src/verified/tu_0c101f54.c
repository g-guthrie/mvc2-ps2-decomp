/* Input-driven actor setup and state selection. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c025762(void);
extern void func_0c1004a0(struct Actor *,int),func_0c1b5f8c(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c045248(struct Actor *,int),func_0c03edcc(struct Actor *,struct Actor *);
extern char dat_0c24af00[];
extern short dat_0c24af20[],dat_0c24af40[];

void func_0c101f54(struct Actor *a)
{
 int z=0;
 a->b1ea=1;
 if(!a->b1f7){
  if(func_0c02a026(a)<0)goto failed;
  if(a->b141==1){a->b141=z;func_0c1b5f8c(a,3);}
  if(a->b141!=2)return;
  a->b141=z;
  a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
  a->p1c8->p1b4=a;
  a->p1c8->b1f6=5;
  a->p1c8->b1a1=dat_0c24af00[((a->w34a&0x3c00)>>10)*2];
  func_0c025762();
  return;
 }
 if(!a->b6){
  if(--a->s28<0){
   short index;
   a->b6++;
   index=(a->w34a&0x3c00)>>10;
   a->b1a3=dat_0c24af20[index];
   func_0c02a0c4(a,15,dat_0c24af40[index]);
  }
  func_0c02a026(a);
  return;
 }
 if(func_0c02a026(a)<0){
failed:
  goto complete;
complete:
  func_0c025762();
  func_0c1004a0(a,a->b1f9);
 }else if(a->b141){
  a->b141=z;
  a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
  a->p1c8->p1b4=a;
  a->p1c8->b1f6=1;
  a->p1c8->b1a1=a->b1a3;
 }
}

void func_0c1020da(struct Actor *a)
{
    func_0c03edcc(a->p1c8, a);
}

void func_0c1020e8(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 2; break;
    case 1: a->b1e9 = 3; break;
    case 2: a->b1e9 = 3; break;
    }
    func_0c045248(a, 29);
}

void func_0c102118(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 2; break;
    case 1: a->b1e9 = 3; break;
    case 2: a->b1e9 = 3; break;
    }
    func_0c045248(a, 29);
}

void func_0c102148(struct Actor *a)
{
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    switch (a->b4c9) {
    case 0:
        a->b1e9 = 0;
        goto set;
    case 1:
        a->b1e9 = 1;
        a->b1a3 = 0;
        break;
    case 2:
        a->b1e9 = 13;
    set:
        a->b1a3 = 1;
        break;
    }
    func_0c045248(a, 21);
}
