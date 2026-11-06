#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c08183c(struct Actor *);
extern void func_0c0818cc(struct Actor *);
extern void (*table_0c241ac4[])(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int);
void func_0c07eabc(struct Actor *a)
{
 a->l2c8=4;
 if(func_0c02a026(a)>=0){
 if(!a->b141){
 a->f52+=a->f92;
 a->f92+=a->f104;
 a->f56+=a->f96;
 a->f96+=a->f108;
 }
 }else{a->l2c8=0;func_0c08183c(a);}
}
void func_0c07eb2c(struct Actor *a)
{
 a->f52+=a->f92;
 a->f92+=a->f104;
 a->f56+=a->f96;
 a->f96+=a->f108;
 if(a->f56>a->f41c){func_0c02a026(a);return;}
 a->f56=a->f41c;
 a->b1f9=0;
 func_0c0818cc(a);
 func_0c08183c(a);
}
void func_0c07eb9e(struct Actor *a)
{
 table_0c241ac4[a->b6](a);
}
void func_0c07ebb0(struct Actor *a)
{
 a->b6++;
 func_0c0442fa(a);
 a->b1f9=0;
 func_0c0432ca(a);
 func_0c048bb0(a,5);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 func_0c02a0c4(a,21,26);
}
