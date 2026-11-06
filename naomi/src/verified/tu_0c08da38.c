#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c08da38(struct Actor *a,unsigned char *context)
{
 a->b3f8=2;a->b328=5;
 func_0c02a026(a);
 if(a->b141){
 a->b141=0;a->b6++;a->b1f9=2;
 if(!a->b1d2){a->f92=-6.66666651f;a->f104=0.15625f;}
 else{a->f92=6.66666651f;a->f104=-0.15625f;}
 a->f96=34.2857132f;a->f108=1.07142854f;
 context[2]=70;
 a->s28=24;a->s30=3;
 }
}
void func_0c08dab8(struct Actor *a)
{
 int zero;
 a->b3f8=2;a->b328=5;
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 zero=0;
 if(a->b19e)a->s30=zero;
 if(a->s30 && --a->s30==0){
 a->b1a1=62;
 a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
 dat_0c2f83f8->arr[a->b2]++;
 }
 if(--a->s28==0){
 a->b6++;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->s28=10;
 }
}
