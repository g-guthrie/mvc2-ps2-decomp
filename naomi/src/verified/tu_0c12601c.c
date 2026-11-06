#include "objects.h"
extern void *func_0c1fba00(void *,int,unsigned int);
/* func_0c12601c: no twin (66 bytes) */
extern void func_0c045248(struct Actor*,int);
void func_0c12601c(struct Actor *a);
void func_0c12605e(struct Actor *a);

void func_0c12609c(struct Actor *a);
void func_0c12601c(struct Actor *a)
{
 int zero=0,one=1;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;a->b1a3=zero;break;case 1:a->b1e9=one;goto common;case 2:goto two;two:a->b1e9=10;common:((char *)a)[0x1a3]=one;break;}
 func_0c045248(a,21);
}

void func_0c12605e(struct Actor *a)
{
 int zero=0,one=1;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;break;case 1:a->b1e9=one;break;case 2:goto two;two:a->b1e9=10;break;default:goto call;}
 a->b1a3=one;
call:goto tail;
tail:func_0c045248(a,21);
}
void func_0c12609c(struct Actor *a)
{
 struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&a->sub2a4;
 char keep=sub->b8;
 func_0c1fba00(sub,0,128);
 sub->b8=keep;
}

