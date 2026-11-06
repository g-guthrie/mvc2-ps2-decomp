#include "objects.h"
#define C(a) ((struct ActorCountdowns *)(a))
extern unsigned char dat_0c24815a[],dat_0c24814a[],dat_0c24816e[],dat_0c248126[],dat_0c248106[],dat_0c248116[],dat_0c2480dc[],dat_0c2480ea[],dat_0c2480f8[],dat_0c248182[];
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *),func_0c047068(struct Actor *,unsigned char *,unsigned char *),func_0c046dd0(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *),func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
unsigned char func_0c0ce670(struct Actor *a),func_0c0ce6b8(struct Actor *a),func_0c0ce6fe(struct Actor *a),func_0c0ce746(struct Actor *a),func_0c0ce7b4(struct Actor *a);
unsigned char func_0c0ce7fa(struct Actor *a),func_0c0ce860(struct Actor *a),func_0c0ce8dc(struct Actor *a),func_0c0ce92a(struct Actor *a),func_0c0ce978(struct Actor *a);
unsigned char func_0c0ce9b4(struct Actor *a),func_0c0cea20(struct Actor *a);
int func_0c0cea86(struct Actor *a),func_0c0ceabe(struct Actor *a),func_0c0ceaf4(struct Actor *a);
void func_0c0ce594(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c0ce670(a))return;
 if(func_0c0ce6b8(a))return;
 if(func_0c0ce6fe(a))return;
 if(func_0c0ce746(a))return;
 if(func_0c0ce7b4(a))return;
 if(func_0c0ce7fa(a))return;
 if(func_0c0ce860(a))return;
 if(func_0c0ce8dc(a))return;
 if(func_0c0ce92a(a))return;
 if(func_0c0ce978(a))return;
 if(func_0c0ce9b4(a))return;
 if(func_0c0cea20(a))return;
 func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c0ce670(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24815a,a->x364))return 0;
 else if(!*a->p40c)return 0;
 {int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;a->b1e9=zero;}
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0ce6b8(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24814a,a->x36c))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0ce6fe(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24816e,a->x374))return 0;
 else if(*a->p40c<1)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c0ce746(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248126,a->x384))return 0;
 func_0c047aac(a,a->x384);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0ce7b4(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248106,a->x394))return 0;
 func_0c047aac(a,a->x394);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=5;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0ce7fa(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248116,a->x3bc))goto fail;
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}}
 func_0c047aac(a,a->x3bc);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=12;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0ce860(struct Actor *a)
{
 if(!func_0c047068(a,dat_0c2480dc,a->x39c))return 0;
 else if(C(a)->l2f8)return 0;
 func_0c047aac(a,a->x39c);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0ce8dc(struct Actor *a)
{
 if(!func_0c047068(a,dat_0c2480ea,a->x3a4))return 0;
 else if(C(a)->l2f8)return 0;
 func_0c047aac(a,a->x3a4);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=7;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0ce92a(struct Actor *a)
{
 if(!func_0c047068(a,dat_0c2480f8,a->x3ac))return 0;
 else if(C(a)->l2f8)return 0;
 func_0c047aac(a,a->x3ac);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=8;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0ce978(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248182,a->x3b4))return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=9;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0ce9b4(struct Actor *a)
{
 if(!func_0c046d54(a))return 0;else if(!*a->p40c)return 0;
 a->b1e9=10;a->b5=0;func_0c045248(a,29);a->b6=(((char *)a)[7]=0);return 1;
}
unsigned char func_0c0cea20(struct Actor *a)
{
 if(!func_0c046dd0(a,11))return 0;
 a->b1e9=11;a->b5=0;func_0c045248(a,21);a->b6=(((char *)a)[7]=0);return 1;
}
unsigned char func_0c0cea5a(struct Actor *a)
{
 if(func_0c0cea86(a))return 1;
 if(func_0c0ceabe(a))return 1;
 if(func_0c0ceaf4(a))return 1;
 return 0;
}
int func_0c0cea86(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24814a,a->x364))return 0;else if(!*a->p40c)return 0;
 a->b258=1;return 1;
}
int func_0c0ceabe(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24815a,a->x36c))return 0;else if(!*a->p40c)return 0;
 a->b258=0;return 1;
}
int func_0c0ceaf4(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24816e,a->x374))return 0;else if(*a->p40c<1)return 0;
 a->b258=3;return 1;
}
void func_0c0ceb2c(void)
{
}
