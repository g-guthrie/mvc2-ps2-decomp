#include "objects.h"
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
extern float table_0c241a70[];
void func_0c07e494(struct Actor *a)
{
 float speed,acceleration;
 float *row;
 a->b6++;
 a->f92=0;
 a->f96=0;
 a->f104=0;
 a->f108=0;
 func_0c0442fa(a);
 if(a->b1f9!=2){a->b1f9=0;func_0c0432ca(a);}
 func_0c048bb0(a,16);
 row=&table_0c241a70[(unsigned char)a->b1a3*2];
 speed=*row++;
 acceleration=*row;
 if(a->w130){speed=-speed;acceleration=-acceleration;}
 a->f92=speed;
 a->f104=acceleration;
 func_0c02a0c4(a,21,(unsigned char)a->b1a3*2);
}
void func_0c07e510(struct Actor *a)
{
 if(!a->b141)a->b6++;
 func_0c02a026(a);
}
void func_0c07e524(struct Actor *a)
{
 float speed,acceleration;
 a->f52+=a->f92;
 a->f92+=a->f104;
 a->f56+=a->f96;
 a->f96+=a->f108;
 func_0c02a026(a);
 if(a->b141){
 a->b6++;
 a->b141=0;
 a->b1f9=2;
 speed=-10;
 acceleration=0.625f;
 if(a->w130){speed=10;acceleration=-0.625f;}
 a->f92=speed;
 a->f96=12.85714245f;
 a->f104=acceleration;
 a->f108=-0.80357140303f;
 }
}
