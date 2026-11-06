/* Exact 0x0c08a500..0x0c08a66c: select an action variant from input or RNG, dispatch its state, and initialize animation and action counters. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a39a(struct Actor *,int),func_0c0437b8(struct Actor *);
extern unsigned int func_0c02849a(void);
extern void func_0c195384(struct Actor *,int);
extern void func_0c02a684(struct Actor *,int,int,int);
extern void (*table_0c24254c[])(struct Actor *,struct MotionContext8a3 *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
void func_0c08a500(struct Actor *a,struct MotionContext8a3 *m)
{
 if(func_0c02a026(a)<0){func_0c02a39a(a,1);func_0c0437b8(a);return;}
 if(a->b141&1){
 unsigned short buttons;
 int choice=-1,offset;
 a->b141^=1;buttons=a->w34a;
 if(buttons&0x800)choice=0;
 if(buttons&0x400)choice=1;
 if(buttons&0x1000)choice=2;
 if(choice==-1)choice=(func_0c02849a()&15u)%3u;
 a->b32=choice;
 func_0c195384(a,2);
 offset=a->b37*16;
 func_0c02a684(a,1,choice+offset+9,1);
 }
}
void func_0c08a5b0(struct Actor *a,struct MotionContext8a3 *m){table_0c24254c[a->b6](a,m);}
void func_0c08a5c2(register struct Actor *a,struct MotionContext8a3 *m)
{
 float stopped=0.0f;
 a->b6++;a->b1f9=0;a->f56=a->f41c;
 a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 a->b1a1=103;a->w1ac=0;a->b19e=0;a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c0442fa(a);func_0c0432ca(a);func_0c02a0c4(a,21,31);
}
