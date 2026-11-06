#include "objects.h"
extern unsigned char *dat_0c2fb3bc;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *,int,int),func_0c037d0c(struct Actor *);
extern char func_0c02a026(struct Actor *);
void func_0c16a1ec(struct Actor *a)
{
 if(dat_0c2fb3bc[12]){
 if(! --a->s28){
 float stopped=0.0f;unsigned int zero=0;
 a->b5++;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 a->b1a1=63;a->w1ac=zero;*(unsigned char *)&a->b19e=zero;*(void **)&a->p1c4=(void *)zero;goto count_effect;count_effect:dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,18);
 }
 func_0c037d0c(a);
 }
}
void func_0c16a260(struct Actor *a)
{
 func_0c02a026(a);
 if(((unsigned char *)&a->w150)[1]){
 a->b5++;a->f92=a->w130?13.33333302f:-13.33333302f;a->f104=a->w130?-0.3125f:0.3125f;a->f96=6.428571224213f;a->f108=-0.80357140303f;
 }
 func_0c037d0c(a);
}
