#include "objects.h"
extern unsigned char dat_0c24a054[],dat_0c24a064[],dat_0c24a074[],dat_0c24a084[],dat_0c24a094[],dat_0c24a0a4[],dat_0c24a0b4[],dat_0c24a0c4[];
extern unsigned int dat_0c24a0d4[];
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *),func_0c046dd0(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *),func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
unsigned char func_0c0f0edc(struct Actor *a),func_0c0f0f60(struct Actor *a),func_0c0f0fca(struct Actor *a),func_0c0f103a(struct Actor *a),func_0c0f10b4(struct Actor *a);
unsigned char func_0c0f10fc(struct Actor *a),func_0c0f1172(struct Actor *a),func_0c0f11b8(struct Actor *a);
int func_0c0f11fe(struct Actor *a),func_0c0f123e(struct Actor *a);
void func_0c0f0df8(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c24a0d4;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}
void func_0c0f0e14(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c0f10fc(a))return;
 if(func_0c0f1172(a))return;
 if(func_0c0f11b8(a))return;
 if(func_0c0f0f60(a))return;
 if(func_0c0f0edc(a))return;
 if(func_0c0f0fca(a))return;
 if(func_0c0f10b4(a))return;
 if(func_0c0f103a(a))return;
 if(func_0c0f11fe(a))return;
 if(func_0c0f123e(a))return;
 func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c0f0edc(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 int zero,cmd;
 if(!func_0c046e7e(a,dat_0c24a054,a->x364)||sub->b2)return 0;
 cmd=zero=0;
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4)return 0;a->b1d4++;}cmd=4;}
 func_0c047aac(a,a->x364);
 a->b5=zero;a->b7=zero;a->b6=zero;a->b1e9=cmd;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0f0f60(struct Actor *a)
{
 int cmd;
 if(!func_0c046e7e(a,dat_0c24a064,a->x36c))return 0;
 cmd=1;
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4)return 0;a->b1d4++;}cmd=11;}
 func_0c047aac(a,a->x36c);
 a->b5=0;a->b1e9=cmd;
 func_0c045248(a,21);
 a->b6=a->b7=0;return 1;
}
unsigned char func_0c0f0fca(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a074,a->x374))return 0;
 func_0c047aac(a,a->x374);
 a->b1e9=2;a->b5=0;
 func_0c045248(a,21);
 a->b6=a->b7=0;return 1;
}
unsigned char func_0c0f103a(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a084,a->x37c))
 fail:return 0;
 if(a->f96<0.0f&&a->f56-a->f41c<102.85714f)return 1;
 else if(!a->b1fc){if(a->b1d4)return 0;a->b1d4++;}
 func_0c047aac(a,a->x37c);
 a->b1e9=3;a->b5=0;
 func_0c045248(a,21);
 a->b6=a->b7=0;return 1;
}
unsigned char func_0c0f10b4(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a0c4,a->x3a4))return 0;
 func_0c047aac(a,a->x3a4);
 a->b1e9=5;a->b5=0;
 func_0c045248(a,29);
 a->b6=a->b7=0;return 1;
}
unsigned char func_0c0f10fc(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a094,a->x394))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0f1172(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a0a4,a->x39c))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=7;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0f11b8(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a0b4,a->x3ac))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=14;
 func_0c045248(a,29);return 1;
}
int func_0c0f11fe(struct Actor *a)
{
 if(!func_0c046d54(a))return 0;
 else if(!*a->p40c)return 0;
 a->b1e9=16;a->b5=0;
 func_0c045248(a,29);
 a->b6=a->b7=0;return 1;
}
int func_0c0f123e(struct Actor *a)
{
 if(!func_0c046dd0(a,9))return 0;
 a->b1e9=9;a->b5=0;
 func_0c045248(a,21);
 a->b6=a->b7=0;return 1;
}
void func_0c0f1278(void){}
