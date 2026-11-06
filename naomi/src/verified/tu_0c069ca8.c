#include "objects.h"
extern void func_0c048bb0(struct Actor *,short);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0451f2(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern float dat_0c2d926c[];
void func_0c069ca8(struct Actor *a)
{
 a->b6++;
 func_0c048bb0(a,4);
 func_0c0442fa(a);
 a->f56=a->f41c;
 a->b1f9=0;
 a->f96=0;
 a->f108=0;
 a->s28=20;
 func_0c0432ca(a);
 func_0c02a0c4(a,21,2);
}
void func_0c069cf2(struct Actor *a)
{



 if(func_0c02a026(a)<0){
 a->b6++;
 a->b1d6=17;
 func_0c0451f2(a);
 a->f56=a->f56+(a->b1fe?68.57143f:274.28571f);
 a->f52=*dat_0c2d926c+(-320.0f);
 a->f52=a->f52+(a->b1a3?746.66663f:0.0f);
 func_0c02a0c4(a,21,3);
 }
}
void func_0c069d68(struct Actor *a)
{
 if(func_0c02a026(a)<0){
 a->b6++;
 a->f92=0;
 a->f96=0;
 a->f104=0;
 a->f108=0;
 a->f108=-0.80357140303f;
 if(!a->b1fe){func_0c0438de(a);return;}
 func_0c02a0c4(a,21,4);
 }
}
