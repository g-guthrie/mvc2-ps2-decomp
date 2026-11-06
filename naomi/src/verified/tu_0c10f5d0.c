/* Special-move checker unit for one character (0x0c10f5d0-0x0c10fb44). */
#include "objects.h"
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *);
extern void func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern unsigned char func_0c046dd0(struct Actor *,int);
extern unsigned int dat_0c24beac[];
extern unsigned char dat_0c24be18[],dat_0c24be2c[],dat_0c24be3c[],dat_0c24be4c[],dat_0c24be5c[],dat_0c24be6c[],dat_0c24be7c[],dat_0c24be9c[];
unsigned char func_0c10f6c8(struct Actor *),func_0c10f758(struct Actor *),func_0c10f81e(struct Actor *),func_0c10f8c4(struct Actor *),func_0c10f92a(struct Actor *),func_0c10f980(struct Actor *);
unsigned char func_0c10fa00(struct Actor *),func_0c10fa54(struct Actor *),func_0c10faa8(struct Actor *),func_0c10fae8(struct Actor *);

void func_0c10f5d0(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c24beac;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}
void func_0c10f5ec(struct Actor *a)
{
 struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&a->sub2a4;
 if(!sub->b22){if(func_0c0465cc(a))return;}
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c10f92a(a))return;
 if(func_0c10fa54(a))return;
 if(func_0c10f980(a))return;
 if(func_0c10fa00(a))return;
 if(func_0c10f6c8(a))return;
 if(func_0c10f758(a))return;
 if(func_0c10f81e(a))return;
 if(func_0c10f8c4(a))return;
 if(func_0c10faa8(a))return;
 if(func_0c10fae8(a))return;
 func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c10f6c8(register struct Actor *a)
{
 register struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&a->sub2a4;
 int n;unsigned char *p;
 if(!func_0c046e7e(a,dat_0c24be18,a->x36c))goto fail;
 n=0;
 p=(unsigned char *)sub;
 goto test;
loop:goto l;l:if(*p)n++;p++;
test:if(p<(unsigned char *)sub+6)goto loop;
 if(n==6)goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x36c);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=0;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c10f758(register struct Actor *a)
{
 register struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&a->sub2a4;
 int n;unsigned char *p;
 if(!func_0c046e7e(a,dat_0c24be2c,a->x374))goto fail;
 n=0;
 p=(unsigned char *)sub;
 goto test;
loop:goto l;l:if(!*p)n++;p++;
test:if(p<(unsigned char *)sub+6)goto loop;
 if(n==6)goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x374);
 a->b1a3+=a->b1fe*2;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c10f81e(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24be3c,a->x37c))goto fail;
 if(a->b1f9!=2 && ((unsigned short *)a->x37c)[3]&32)goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x37c);
 {int zero=0;a->b5=zero;a->b6=a->b1a3;a->b7=zero;}a->b1e9=2;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c10f8c4(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24be4c,a->x384))goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x384);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c10f92a(struct Actor *a)
{
 struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&a->sub2a4;
 if(sub->b22)return 0;
 if(!func_0c046e7e(a,dat_0c24be5c,a->x38c))return 0;
 else if(*a->p40c<3)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c10f980(struct Actor *a)
{
 struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&a->sub2a4;
 if(sub->b22)return 0;
 if(!func_0c046e7e(a,dat_0c24be6c,a->x394))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=10;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c10fa00(struct Actor *a)
{
 struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&a->sub2a4;
 if(sub->b22)return 0;
 if(!func_0c046e7e(a,dat_0c24be7c,a->x39c))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=11;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c10fa54(struct Actor *a)
{
 struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&a->sub2a4;
 if(sub->b22)return 0;
 if(!func_0c046e7e(a,dat_0c24be9c,a->x3ac))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=13;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c10faa8(struct Actor *a)
{
 if(!func_0c046d54(a))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b1e9=5;a->b5=0;
 func_0c045248(a,29);
 a->b6=a->b7=0;
 return 1;
}
unsigned char func_0c10fae8(struct Actor *a)
{
 if(!func_0c046dd0(a,6))return 0;
 a->b1e9=6;a->b5=0;
 func_0c045248(a,21);
 a->b6=a->b7=0;
 return 1;
}
