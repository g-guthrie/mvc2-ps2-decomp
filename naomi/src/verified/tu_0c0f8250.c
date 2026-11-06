/* Special-move checker unit for one character (0x0c0f8250-0x0c0f85b8). */
#include "objects.h"
extern unsigned char dat_0c24a664[];
extern unsigned char dat_0c24a674[];
extern unsigned char dat_0c24a684[];
extern unsigned char dat_0c24a694[];
extern unsigned char dat_0c24a6a8[];
extern unsigned int dat_0c24a6cc[];
extern void func_0c045248(struct Actor*,int);
extern void func_0c045f1c(struct Actor*);
extern void func_0c0463fc(struct Actor*);
extern unsigned char func_0c0465cc(struct Actor*);
extern unsigned char func_0c0469f4(struct Actor*);
extern unsigned char func_0c046b6c(struct Actor*);
extern unsigned char func_0c046d3c(struct Actor*);
extern int func_0c046d54(struct Actor*);
extern unsigned char func_0c046dd0(struct Actor*,int);
extern unsigned char func_0c046e7e(struct Actor*,unsigned char*,unsigned char*);
extern void func_0c047aac(struct Actor*,unsigned char*);
extern void func_0c048bb0(struct Actor*,int);
void func_0c0f8250(struct Actor *a);
void func_0c0f826c(struct Actor *a);
unsigned char func_0c0f82fa(struct Actor *a);
unsigned char func_0c0f8380(struct Actor *a);
unsigned char func_0c0f83d0(struct Actor*a);
unsigned char func_0c0f8416(struct Actor *a);
unsigned char func_0c0f8464(struct Actor *a);
unsigned char func_0c0f84e0(struct Actor*a);
int func_0c0f8518(struct Actor*a);
int func_0c0f8558(struct Actor *a);

void func_0c0f8250(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c24a6cc;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

void func_0c0f826c(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c0f83d0(a))return;
 if(func_0c0f8380(a))return;
 if(func_0c0f82fa(a))return;
 if(func_0c0f8464(a))return;
 if(func_0c0f8416(a))return;
 if(func_0c0f8518(a))return;
 if(func_0c0f84e0(a))return;
 func_0c045f1c(a);func_0c0463fc(a);
}

unsigned char func_0c0f82fa(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a664,a->x36c))return 0;
 func_0c047aac(a,a->x36c);func_0c048bb0(a,5);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=0;
 func_0c045248(a,21);return 1;
}

unsigned char func_0c0f8380(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a674,a->x374))goto fail;
 if(!*a->p40c){fail:return 0;}
 func_0c047aac(a,a->x374);a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;func_0c045248(a,29);return 1;
}

unsigned char func_0c0f83d0(struct Actor*a){if(!func_0c046e7e(a,dat_0c24a684,a->x37c))return 0;func_0c047aac(a,a->x37c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;func_0c045248(a,21);return 1;}

unsigned char func_0c0f8416(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a694,a->x384))return 0;
 func_0c047aac(a,a->x384);func_0c048bb0(a,10);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;
 func_0c045248(a,21);return 1;
}

unsigned char func_0c0f8464(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24a6a8,a->x38c))return 0;
 func_0c047aac(a,a->x38c);func_0c048bb0(a,10);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=7;
 func_0c045248(a,21);return 1;
}

unsigned char func_0c0f84e0(struct Actor*a){if(!func_0c046dd0(a,4))return 0;a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;func_0c045248(a,21);return 1;}

int func_0c0f8518(struct Actor*a){if(!func_0c046d54(a))return 0;else if(!*a->p40c)return 0;a->b1e9=9;a->b5=0;func_0c045248(a,29);a->b6=(((char*)a)[7]=0);return 1;}

int func_0c0f8558(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24a674, (unsigned char *)a + 0x374))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 1;
    return 1;
}
