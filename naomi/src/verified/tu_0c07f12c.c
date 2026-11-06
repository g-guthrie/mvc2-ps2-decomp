#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c08183c(struct Actor *);
extern void func_0c08191c(struct Actor *);
extern void (*table_0c241b20[])(struct Actor *);
extern void (*table_0c241b40[])(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *,int);
extern void func_0c0818f8(struct Actor *);
extern short dat_0c241b38[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern float dat_0c241b2c[];
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c193440(struct Actor *,int,int);
extern void func_0c13e4ac(struct Actor *,float,float,char);
void func_0c07f12c(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c08183c(a);
}
void func_0c07f14e(struct Actor *a)
{
 table_0c241b20[a->b6](a);func_0c08191c(a);
}
void func_0c07f16c(struct Actor *a)
{
 int zero;
 float speed;
 a->b6++;
 func_0c0442fa(a);func_0c0432ca(a);func_0c048bb0(a,5);func_0c0818f8(a);
 a->s28=2;a->s30=dat_0c241b38[(unsigned char)a->b1a3];
 zero=0;a->b32=zero;a->b33=zero;a->b1a1=98;
 a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
 dat_0c2f83f8->arr[a->b2]++;
 speed=dat_0c241b2c[(unsigned char)a->b1a3];
 if(a->w130)speed=-speed;
 a->f92=speed;func_0c02a0c4(a,21,37);
}
void func_0c07f1fa(struct Actor *a)
{
 int zero=0;
 int frame;
 a->f52+=a->f92;a->f92+=a->f104;
 if(func_0c02a026(a)<0){
 if(a->b32){if(--a->s30>=0)a->s28++;a->b32=zero;a->w352=zero;}
 if(--a->s28<=0){a->b6++;frame=53;}
 else{a->b33^=1;frame=(char)a->b33+37;if(a->s28==1)frame+=3;}
 func_0c02a0c4(a,21,frame);return;
 }
 if((a->w348|a->w352)&0x60)a->b32=1;
 if(a->b141){func_0c193440(a,a->b141,a->b14b);func_0c193440(a,a->b141-1,a->b14b);a->b141=zero;}
}
void func_0c07f310(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c08183c(a);
}
void func_0c07f332(struct Actor *a)
{
 if(!a->b6){a->b6++;a->b1f9=0;a->s28=60;func_0c02a0c4(a,20,22);}
 else{
 func_0c02a026(a);
 if(a->b141){a->b141=0;func_0c13e4ac(a,-34.0f,95.0f,0);}
 if(--a->s28==0)func_0c08183c(a);
 }
 func_0c08191c(a);
}
void func_0c07f39a(struct Actor *a)
{
 table_0c241b40[a->b6](a);func_0c08191c(a);
}
