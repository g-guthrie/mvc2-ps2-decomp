#include "objects.h"
extern unsigned int dat_0c24ac70[];
extern void (*dat_0c24ace0[])(struct Actor *);
extern unsigned char dat_0c24ac04[],dat_0c24ac14[],dat_0c24ac28[],dat_0c24ac50[],dat_0c24ac3c[],dat_0c24ac60[];
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *),func_0c046dd0(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *),func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
unsigned char func_0c0fcac6(struct Actor *a);
unsigned char func_0c0fcb36(struct Actor *a);
unsigned char func_0c0fcb92(struct Actor *a);
unsigned char func_0c0fcbd8(struct Actor *a);
unsigned char func_0c0fcc50(struct Actor *a);
unsigned char func_0c0fccb6(struct Actor *a);
unsigned char func_0c0fcd06(struct Actor *a);
unsigned char func_0c0fcd3e(struct Actor *a);
int func_0c0fcdce(struct Actor *a);
int func_0c0fce04(struct Actor *a);
int func_0c0fce3a(struct Actor *a);
void func_0c0fca10(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c24ac70;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}
void func_0c0fca2c(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c0fccb6(a))return;
 if(func_0c0fcbd8(a))return;
 if(func_0c0fcc50(a))return;
 if(func_0c0fcb92(a))return;
 if(func_0c0fcb36(a))return;
 if(func_0c0fcac6(a))return;
 if(func_0c0fcd06(a))return;
 if(func_0c0fcd3e(a))return;
 func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c0fcac6(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24ac04,a->x36c))return 0;
 func_0c047aac(a,a->x36c);
 {int zero=0;a->b5=zero;a->b6=zero;a->b7=zero;a->b1e9=zero;}
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0fcb36(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(!func_0c046e7e(a,dat_0c24ac14,a->x374))return 0;
 else if(sub->b0)return 0;
 func_0c047aac(a,a->x374);
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=1;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0fcb92(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24ac28,a->x384))return 0;
 func_0c047aac(a,a->x384);
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=2;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0fcbd8(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24ac50,a->x38c))return 0;
 else if(!*a->p40c)return 0;
 func_0c047aac(a,a->x38c);
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=3;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0fcc50(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(!func_0c046e7e(a,dat_0c24ac3c,a->x37c))return 0;
 if(!*a->p40c)return 0;
 if(sub->b0)return 0;
 func_0c047aac(a,a->x37c);
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=4;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0fccb6(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24ac60,a->x394))return 0;
 else if(!*a->p40c)return 0;
 func_0c047aac(a,a->x394);
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=5;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0fcd06(struct Actor *a)
{
 if(!func_0c046dd0(a,9))return 0;
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=9;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0fcd3e(struct Actor *a)
{
 if(!func_0c046d54(a))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=8;
 func_0c045248(a,29);return 1;
}
int func_0c0fcda2(struct Actor *a)
{
 if(func_0c0fcdce(a))return 1;
 if(func_0c0fce04(a))return 1;
 if(func_0c0fce3a(a))return 1;
 return 0;
}
int func_0c0fcdce(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24ac50,a->x38c))return 0;else if(!*a->p40c)return 0;
 a->b258=3;return 1;
}
int func_0c0fce04(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24ac3c,a->x37c))return 0;else if(!*a->p40c)return 0;
 a->b258=4;return 1;
}
int func_0c0fce3a(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24ac60,a->x394))return 0;else if(!*a->p40c)return 0;
 a->b258=5;return 1;
}
void func_0c0fce70(void)
{
}
void func_0c0fce74(struct Actor *a)
{
 dat_0c24ace0[a->b1ff](a);
}
