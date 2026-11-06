#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c048ce6(struct Actor *),func_0c03489c(struct Actor *),func_0c0c201a(struct Actor *);
extern void func_0c025762(void);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c045248(struct Actor *,int),func_0c03edcc(struct Actor *,struct Actor *);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void (*table_0c246d8c[])(struct Actor *),(*table_0c246d94[])(struct Actor *),(*table_0c246d9c[])(struct Actor *);

void func_0c0c4ba8(struct Actor *a)
{
 struct LinkedActorVec3 v;
 v.x=0.0f;
 if((signed char)a->b1d3>=0){
  v.x=-6.66666651f;
  if(a->b1d2)v.x=-v.x;
  if(a->b1d3)v.x=-v.x;
 }
 a->f92=v.x;a->f104=0.0f;a->f96=0.0f;a->f108=-0.5357143f;
 if(a->b34&2){a->b1d2^=1;a->w130=(unsigned char)a->b1d2;}
 v.x=-73.33333f;v.y=107.142853f;
 func_0c1d4610(a,&v);a->b1a0=10;func_0c048ce6(a);func_0c02a0c4(a,15,1);
}
void func_0c0c4c44(struct Actor *a){a->b1ea=1;table_0c246d8c[a->b1f7&63](a);}
void func_0c0c4c62(struct Actor *a){table_0c246d94[a->b6](a);}
void func_0c0c4c74(struct Actor *a)
{
 struct Actor *child;
 func_0c02a026(a);
 if(a->b141==1){
  a->b6++;a->b141=0;
  child=a->p1c8;child->p1b4=a;child->b1d2=a->b1d2^1;child->b1a1=32;child->b1f6=1;
  func_0c025762();func_0c03489c(a);
 }
}
void func_0c0c4cc6(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141){
  a->b141=0;a->b1d2^=1;a->w130=(unsigned char)a->b1d2;
  if(!a->w130)a->f52-=26.666666031f;else a->f52+=26.666666031f;
 }
}
void func_0c0c4d64(struct Actor *a){table_0c246d9c[a->b6](a);}

void func_0c0c4d76(struct Actor *a)
{
    struct Actor *b;
    func_0c0c201a(a);
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        b = a->p1c8;
        b->p1b4 = a;
        b->b1f6 = 1;
        b->b1f9 = 2;
        b->b1a1 = 33;
        b->b1d2 = a->b1d2 ^ 1;
        if (a->w150 == 0)
            func_0c0438de(a);
    }
}

void func_0c0c4dd2(struct Actor *a)
{
    func_0c0c201a(a);
    if (func_0c02a026(a) < 0) func_0c0438de(a);
}

void func_0c0c4df8(struct Actor *a)
{
    func_0c03edcc(a->p1c8, a);
}

void func_0c0c4e06(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 7; break;
    case 1: a->b1e9 = 7; break;
    case 2: a->b1e9 = 7; break;
    }
    func_0c045248(a, 29);
}
