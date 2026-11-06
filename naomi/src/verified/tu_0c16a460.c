#include "objects.h"
#define OWNER(a) ((struct Actor *)((struct LinkedActor *)(a))->p24)
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c037d0c(struct Actor *),func_0c0346da(struct Actor *,int),func_0c037688(struct Actor *);
void func_0c16a6d2(struct Actor *);
void func_0c16a460(struct Actor *a)
{
 struct Tbl_ub3_01 **counts;unsigned int zero;int effect;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);effect=63;counts=&dat_0c2f83f8;zero=0;
 if(a->b141){*(unsigned char *)&a->b141=zero;a->b1a1=effect;a->w1ac=zero;*(unsigned char *)&a->b19e=zero;a->p1c4=zero;(*counts)->arr[a->b2]++;a->s30=2;}
 if(! --a->s30 &&a->b19e){a->b1a1=effect;a->w1ac=zero;*(unsigned char *)&a->b19e=zero;a->p1c4=zero;(*counts)->arr[a->b2]++;}
 if(!(a->f56>OWNER(a)->f41c)){
 a->b5++;a->f56=OWNER(a)->f41c;func_0c02a0c4(a,21,20);
 }
 func_0c037d0c(a);
}

void func_0c16a53e(struct Actor *a)
{
 func_0c02a026(a);
 if(((unsigned char *)&a->w150)[1]){
 unsigned int zero=0;float stopped;
 a->b5++;((unsigned char *)&a->w150)[1]=zero;
 a->b1a1=63;a->w1ac=zero;*(unsigned char *)&a->b19e=zero;a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;a->s30=2;
 a->f92=a->w130?23.3333321f:-23.3333321f;a->f104=a->w130?-0.8333333135f:0.8333333135f;stopped=0.0f;a->f96=stopped;a->f108=stopped;func_0c0346da(a,41);
 }
 func_0c037d0c(a);
}
void func_0c16a5f6(struct Actor *a)
{
 unsigned int zero=0;
 if(((char *)&a->w150)[1]==2){((unsigned char *)&a->w150)[1]=zero;a->f92=0.0f;a->f104=0.0f;}
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c02a026(a)<0){func_0c16a6d2(a);return;}
 if(! --a->s30 &&a->b19e){a->b1a1=62;a->w1ac=zero;*(unsigned char *)&a->b19e=zero;a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;}
 func_0c037d0c(a);
}
void func_0c16a6b0(struct Actor *a){if(func_0c02a026(a)>=0)func_0c037d0c(a);else func_0c16a6d2(a);}
void func_0c16a6d2(struct Actor *a){a->b12c=0;func_0c037688(a);}
