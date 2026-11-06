#include "objects.h"
extern unsigned char dat_0c249c90[],dat_0c249ca4[],dat_0c249cb8[],dat_0c249ccc[],dat_0c249cdc[],dat_0c249cea[],dat_0c249cf8[],dat_0c249d08[],dat_0c249d18[],dat_0c249d28[];
extern unsigned int dat_0c249d3c[];
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *),func_0c047068(struct Actor *,unsigned char *,unsigned char *),func_0c046dd0(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *),func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int),func_0c0f0426(struct Actor *);
unsigned char func_0c0ec284(struct Actor *a),func_0c0ec2f0(struct Actor *a),func_0c0ec35a(struct Actor *a),func_0c0ec40a(struct Actor *a),func_0c0ec4c8(struct Actor *a);
unsigned char func_0c0ec568(struct Actor *a),func_0c0ec62e(struct Actor *a),func_0c0ec6ba(struct Actor *a),func_0c0ec742(struct Actor *a),func_0c0ec788(struct Actor *a);
int func_0c0ec7d8(struct Actor *a);
void func_0c0ec18c(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c249d3c;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}
void func_0c0ec1a8(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c0ec788(a))return;
 if(func_0c0ec742(a))return;
 if(func_0c0ec62e(a))return;
 if(func_0c0ec284(a))return;
 if(func_0c0ec6ba(a))return;
 if(func_0c0ec35a(a))return;
 if(func_0c0ec40a(a))return;
 if(func_0c0ec4c8(a))return;
 if(func_0c0ec568(a))return;
 if(func_0c0ec2f0(a))return;
 if(func_0c0ec7d8(a))return;
 if(func_0c0ec818(a))return;
 func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c0ec284(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(!func_0c046e7e(a,dat_0c249c90,a->x36c))return 0;
 else if(sub->b0)return 0;
 func_0c047aac(a,a->x36c);
 if(a->b201)func_0c0f0426(a);
 {int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;a->b1e9=zero;}
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0ec2f0(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(!func_0c046e7e(a,dat_0c249ca4,a->x374))return 0;
 else if(sub->b1)return 0;
 func_0c047aac(a,a->x374);
 if(a->b201)func_0c0f0426(a);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=7;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0ec35a(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c249cb8,a->x37c))goto fail;
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}}
 func_0c047aac(a,a->x37c);
 if(a->b201)func_0c0f0426(a);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;
 func_0c045248(a,21);
 if(a->b1f9==2)a->b6=1;
 return 1;
}
unsigned char func_0c0ec40a(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c249ccc,a->x384))goto fail;
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}}
 func_0c047aac(a,a->x384);
 if(a->b201)func_0c0f0426(a);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;
 func_0c045248(a,29);
 if(a->b525)a->b7=a->b1fe*2;
 else a->b7=a->b1fe*2+a->b1a3;
 return 1;
}
unsigned char func_0c0ec4c8(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(!func_0c047068(a,dat_0c249cdc,a->x38c))goto fail;
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4)goto fail;a->b1d4++;}}
 if(a->b525&&a->b201){fail:return 0;}
 func_0c047aac(a,a->x38c);
 if(a->b201)func_0c0f0426(a);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;
 func_0c045248(a,21);
 sub->b3=a->b1f9==2;
 return 1;
}
unsigned char func_0c0ec568(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(!func_0c047068(a,dat_0c249cea,a->x394))goto fail;
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4)goto fail;a->b1d4++;}}
 if(a->b525&&a->b201){fail:return 0;}
 if(a->b201)func_0c0f0426(a);
 a->b1a3=1;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;
 func_0c045248(a,21);
 sub->b3=a->b1f9==2;
 return 1;
}
unsigned char func_0c0ec62e(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c249cf8,a->x39c)||!*a->p40c)goto fail;
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}}
 func_0c047aac(a,a->x39c);
 if(a->b201)func_0c0f0426(a);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;
 func_0c045248(a,29);
 if(a->b1f9==2)a->b6=1;
 return 1;
}
unsigned char func_0c0ec6ba(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c249d08,a->x3a4))return 0;
 else if(!*a->p40c)return 0;
 func_0c047aac(a,a->x3a4);
 if(a->b201)func_0c0f0426(a);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=5;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0ec742(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c249d18,a->x3ac))return 0;
 func_0c047aac(a,a->x3ac);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=9;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0ec788(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c249d28,a->x3b4))return 0;
 else if(!*a->p40c)return 0;
 func_0c047aac(a,a->x3b4);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=15;
 func_0c045248(a,29);return 1;
}
int func_0c0ec7d8(struct Actor *a)
{
 if(!func_0c046d54(a))return 0;
 else if(!*a->p40c)return 0;
 a->b1e9=14;a->b5=0;
 func_0c045248(a,29);
 a->b6=a->b7=0;return 1;
}
int func_0c0ec818(struct Actor *a)
{
 if(!func_0c046dd0(a,11))return 0;
 a->b1e9=11;a->b5=0;
 func_0c045248(a,21);
 a->b6=a->b7=0;return 1;
}
int func_0c0ec880(struct Actor *a)
{
 if(func_0c0ec92a(a)||func_0c0ec8ac(a)||func_0c0ec8f4(a))return 1;
 return 0;
}
int func_0c0ec8ac(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c249cf8,a->x39c))return 0;
 else if(!*a->p40c)return 0;
 else if(a->b1f9==2)return 0;
 else if(a->b201)return 0;
 a->b258=6;return 1;
}
int func_0c0ec8f4(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c249d08,a->x3a4))return 0;
 else if(!*a->p40c)return 0;
 a->b258=5;return 1;
}
int func_0c0ec92a(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c249d28,a->x3b4))return 0;
 else if(!*a->p40c)return 0;
 a->b258=15;return 1;
}
