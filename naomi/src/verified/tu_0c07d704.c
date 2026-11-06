/* Select attack tables, consume per-limb charges and handle the alternate mode. */
#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char dat_0c241949[],dat_0c241943[];
extern char dat_0c24194c[],dat_0c241952[];
extern void *dat_0c2417f4[];
extern void func_0c02a0c4(struct Actor *,int,int);
void func_0c07d704(struct Actor *a){
 unsigned char index;
 a->b7=0;a->b6=0;index=a->b1e8;if(a->b1fe)index+=3;
 a->l320=0;a->b1a7=dat_0c241949[a->b1e8];a->b1a1=dat_0c241943[index];
 a->w1ac=0;a->b19e=0;a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,dat_0c241952[index],dat_0c24194c[index]);
 if(index==5){if(a->w1fa&0x1000){a->l320=1;a->b1d6&=15;func_0c02a0c4(a,12,5);}}
 if(a->b1fc)index+=6;
 a->p3f4=dat_0c2417f4[index];
 if(!a->b1fe){if(a->b1d6&15)a->b1d6=a->b1d6-1;}
 else{if(a->b1d6&0xf0)a->b1d6=a->b1d6-16;}
}
void func_0c07d7e6(struct Actor *a){
 if(!a->b1fe){if(a->b1d6&15)goto call;}
 else{if(!(a->b1d6&0xf0))return;call:func_0c07d704(a);}
}
