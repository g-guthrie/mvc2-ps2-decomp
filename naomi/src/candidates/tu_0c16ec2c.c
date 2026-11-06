/* Candidate 286/288: the mask constant is declared before a register copy
 * of the actor so mov #3,r13 lands in the prologue like retail. Remaining:
 * the else-arm 53 store uses r3 where retail uses r1. Second routine and
 * pool are exact. */
#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern int func_0c02849a(void),func_0c02850e(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0288a8(struct Actor *,int),func_0c037d0c(struct Actor *),func_0c037688(struct Actor *);
void func_0c16ec2c(struct Actor *a0)
{
 const int mask=3;
 register struct Actor *a=a0;
 if(func_0c02a026(a)<0){
 unsigned int zero=0;
 a->b5++;
 if(dat_0c2d6f84->flags&mask)a->b1a1=57;else a->b1a1=53;
 a->w1ac=zero;*(unsigned char *)&a->b19e=zero;a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 a->b34=func_0c02849a()&15;if(!a->w130)a->b34+=16;
 if(!a->b32)a->i204=(func_0c02849a()&mask)*100+1000;
 else a->i204=(func_0c02849a()&mask)*100+1800;
 }
}
void func_0c16ece0(struct Actor *a)
{
 if(!a->b19f){func_0c0288a8(a,a->i204);func_0c02a026(a);if(func_0c02850e(a)){func_0c037d0c(a);return;}}
 goto cleanup;cleanup:func_0c037688(a);
}
