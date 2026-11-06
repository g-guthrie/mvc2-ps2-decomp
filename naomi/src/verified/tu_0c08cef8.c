#include "objects.h"
extern void func_0c048bb0(struct Actor *,int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *,int);
extern void func_0c0432ca(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0451f2(struct Actor *);
extern int dat_0c24283c[];
extern char dat_0c24284c[];
extern void func_0c0344a0(struct Actor *,int);
extern void func_0c196c1c(struct Actor *,int,int);
void func_0c08cf8e(struct Actor *,void *);
void func_0c08cef8(struct Actor *a,void *context)
{
 register int zero=0;
 a->b7++;a->b35=zero;
 func_0c048bb0(a,5);
 func_0c0442fa(a);
 func_0c02a39a(a,zero);
 func_0c0432ca(a);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->b1f9=zero;
 a->f56=a->f41c;
 a->b1a1=a->b1a3*2+67;
 a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,a->b1a3+14);
 func_0c08cf8e(a,context);
}
void func_0c08cf8e(struct Actor *a,void *context)
{
 int horizontal,vertical;
 int *row;
 func_0c02a026(a);
 if(a->b141){
 a->b7++;
 func_0c0451f2(a);
 horizontal=dat_0c24283c[(unsigned char)a->b1a3*2];
 a->f92=a->b1d2 ? -(horizontal*1.66666663f/65536.0f) : horizontal*1.66666663f/65536.0f;
 a->f104=a->b1d2 ? -0.20833333f : 0.20833333f;
 row=&dat_0c24283c[(unsigned char)a->b1a3*2];
 vertical=row[1];
 a->f96=vertical*2.1428571f/65536.0f;
 a->f108=-0.46875f;
 a->s28=dat_0c24284c[(unsigned char)a->b1a3];
 a->s30=4;
 func_0c0344a0(a,20);
 func_0c0344a0(a,32);
 func_0c196c1c(a,5,1);
 }
}
void func_0c08d09a(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!a->s30){
 if(a->b35){a->b6++;a->b7=0;return;}
 }else a->s30--;
 if(--a->s28==0){
 a->b7++;
 a->b159=21;a->b158=10;
 func_0c02a0c4(a,a->b159,a->b158);
 a->f92=a->f92/4.0f;a->f104=a->f104/4.0f;
 }
}
