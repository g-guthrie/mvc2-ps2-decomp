/* Special-move checker unit for one character (0x0c11ea20-0x0c11ef44). */
#include "objects.h"
extern unsigned char dat_0c24d1d4[];
extern unsigned char dat_0c24d1e4[];
extern unsigned char dat_0c24d1f4[];
extern unsigned char dat_0c24d204[];
extern unsigned char dat_0c24d214[];
extern unsigned char dat_0c24d224[];
extern unsigned int dat_0c24d234[];
extern void func_0c02a626(struct Actor*,int,int,int);
extern void func_0c02a684(struct Actor*,int,int,int);
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
void func_0c11ea20(struct Actor *a);
void func_0c11ea3c(struct Actor *a);
int func_0c11eae4(struct Actor *a);
int func_0c11eb5e(struct Actor*a);
int func_0c11eba4(struct Actor*a);
int func_0c11ec14(struct Actor*a);
int func_0c11ec5a(struct Actor*a);
int func_0c11eca0(struct Actor*a);
int func_0c11ece6(struct Actor *a);
int func_0c11ed40(struct Actor *a);
int func_0c11ed7e(struct Actor *a);
int func_0c11edb2(struct Actor *a);
int func_0c11ede8(struct Actor *a);
int func_0c11ee3c(struct Actor *a);
int func_0c11ee72(struct Actor *a);
void func_0c11eea8(struct Actor *a);

void func_0c11ea20(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c24d234;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

void func_0c11ea3c(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c11ec14(a))return;
 if(func_0c11eba4(a))return;
 if(func_0c11ec5a(a))return;
 if(func_0c11eca0(a))return;
 if(func_0c11eae4(a))return;
 if(func_0c11eb5e(a))return;
 if(func_0c11ece6(a))return;
 if(func_0c11ed40(a))return;
 func_0c045f1c(a);func_0c0463fc(a);
}

int func_0c11eae4(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24d1d4,a->x364))goto fail;
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4)goto fail;a->b1d4++;}}
 if(a->b1f9==2 && ((struct ActorSubTimers *)&a->sub2a4)->t8>0){fail:return 0;}
 func_0c047aac(a,a->x364);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=0;
 func_0c045248(a,21);return 1;
}

int func_0c11eb5e(struct Actor*a){if(!func_0c046e7e(a,dat_0c24d1e4,a->x36c))return 0;func_0c047aac(a,a->x36c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;func_0c045248(a,21);return 1;}

int func_0c11eba4(struct Actor*a){if(!func_0c046e7e(a,dat_0c24d1f4,a->x374))return 0;else if(!*a->p40c)return 0;a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;func_0c045248(a,29);return 1;}

int func_0c11ec14(struct Actor*a){if(!func_0c046e7e(a,dat_0c24d204,a->x38c))return 0;else if(!*a->p40c)return 0;a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;func_0c045248(a,29);return 1;}

int func_0c11ec5a(struct Actor*a){if(!func_0c046e7e(a,dat_0c24d214,a->x37c))return 0;else if(!*a->p40c)return 0;a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;func_0c045248(a,29);return 1;}

int func_0c11eca0(struct Actor*a){if(!func_0c046e7e(a,dat_0c24d224,a->x384))return 0;else if(!*a->p40c)return 0;a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;func_0c045248(a,29);return 1;}

int func_0c11ece6(struct Actor *a)
{
 if(!func_0c046dd0(a,8))return 0;
 a->b1e9=8;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}

int func_0c11ed40(struct Actor *a)
{
 if(!func_0c046d54(a))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b1e9=10;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,29);return 1;
}

int func_0c11ed7e(struct Actor *a)
{
 if(func_0c11ee72(a)||func_0c11edb2(a)||func_0c11ede8(a)||func_0c11ee3c(a))return 1;
 return 0;
}

int func_0c11edb2(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24d1f4, (unsigned char *)a + 0x374))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 2;
    return 1;
}

int func_0c11ede8(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24d214, (unsigned char *)a + 0x37c))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 3;
    return 1;
}

int func_0c11ee3c(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24d224, (unsigned char *)a + 0x384))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 4;
    return 1;
}

int func_0c11ee72(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24d204, (unsigned char *)a + 0x38c))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 6;
    return 1;
}

void func_0c11eea8(struct Actor *a)
{
 if((unsigned char)a->b159==17){
  int v;
  if(v=(signed char)a->b140){a->b140=0;if(v==1)v=0;else v=1;func_0c02a684(a,v,0,1);}
  else func_0c02a626(a,0,0,2);
 }
 if(((struct ActorSubTimers *)&a->sub2a4)->t8)((struct ActorSubTimers *)&a->sub2a4)->t8--;
 if(((struct ActorSubTimers *)&a->sub2a4)->t20)((struct ActorSubTimers *)&a->sub2a4)->t20=((struct ActorSubTimers *)&a->sub2a4)->t20-1;
 if(((struct ActorSubTimers *)&a->sub2a4)->t28)((struct ActorSubTimers *)&a->sub2a4)->t28--;
}
