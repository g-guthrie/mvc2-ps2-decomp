#include "objects.h"
extern unsigned char dat_0c2412f0[],dat_0c241300[];
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *);
extern void func_0c047aac(struct Actor *,unsigned char *);
extern void func_0c045248(struct Actor *,int);
unsigned char func_0c076574(struct Actor *a)
{
    int one;
    struct ActorSub2a4Extended *sub;
    if(!func_0c046e7e(a,dat_0c2412f0,a->x374))return 0;
    if(a->b1f9==2&&!a->b1fc){if(a->b1d4)return 0;a->b1d4++;}
    func_0c047aac(a,a->x374);
    a->b5=0;a->b7=0;a->b6=0;one=1;a->b1e9=one;
    func_0c045248(a,21);
    sub=(struct ActorSub2a4Extended *)&a->sub2a4;
    sub->s34=one;
    return one;
}
unsigned char func_0c0765e4(struct Actor *a)
{
    struct ActorSub2a4Extended *sub;
    if(!func_0c046e7e(a,dat_0c241300,a->x384))return 0;
    if(!*a->p40c)return 0;
    if(a->b1f9==2){if(a->b1d4)return 0;if(!a->b1fc)a->b1d4++;}
    a->b1a3=1;a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;
    sub=(struct ActorSub2a4Extended *)&a->sub2a4;
    sub->w42=a->w1fa;
    func_0c045248(a,29);
    return 1;
}
