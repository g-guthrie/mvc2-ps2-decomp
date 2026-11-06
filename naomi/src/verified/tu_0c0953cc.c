/* Special-move checker unit for one character (0x0c0953cc-0x0c0956ec). */
#include "objects.h"
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *);
extern unsigned char func_0c04608a(struct Actor *,unsigned char *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *);
extern void func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern unsigned char func_0c046dd0(struct Actor *,int);
extern unsigned int dat_0c243024[];
extern unsigned char dat_0c242fd4[],dat_0c242fe4[],dat_0c242ff4[],dat_0c243004[],dat_0c243014[];
unsigned char func_0c0954a4(struct Actor *),func_0c09550c(struct Actor *),func_0c095552(struct Actor *),func_0c0955c8(struct Actor *),func_0c09560e(struct Actor *),func_0c095692(struct Actor *);
int func_0c095654(struct Actor *);

void func_0c0953cc(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c243024;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}
void func_0c0953e8(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c0955c8(a))return;
 if(func_0c09560e(a))return;
 if(func_0c095552(a))return;
 if(func_0c09550c(a))return;
 if(func_0c0954a4(a))return;
 if(func_0c095654(a))return;
 if(func_0c095692(a))return;
 func_0c04608a(a,a->x3cc);func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c0954a4(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c242fd4,a->x364))goto fail;
 if(a->b1f9==2 && a->b1fc==0){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x364);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=0;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c09550c(struct Actor*a){if(!func_0c046e7e(a,dat_0c242fe4,a->x36c))return 0;func_0c047aac(a,a->x36c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;func_0c045248(a,21);return 1;}
unsigned char func_0c095552(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c242ff4,a->x374))goto fail;
 if(((struct ActorSubMoveBytes *)&a->sub2a4)->b5){fail:return 0;}
 func_0c047aac(a,a->x374);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0955c8(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c243004,a->x37c))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c09560e(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c243014,a->x384))return 0;
 else if(!*a->p40c)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=5;
 func_0c045248(a,29);return 1;
}
int func_0c095654(struct Actor *a)
{
 if(!func_0c046d54(a))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b1e9=6;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,29);return 1;
}
unsigned char func_0c095692(struct Actor *a)
{
 if(!func_0c046dd0(a,3))return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;
 func_0c045248(a,21);return 1;
}
