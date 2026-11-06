#include "objects.h"
extern unsigned int dat_0c240ca0[];
extern void func_0c045f1c(struct Actor*);
extern void func_0c0463fc(struct Actor*);
extern unsigned char func_0c0465cc(struct Actor*);
extern unsigned char func_0c0469f4(struct Actor*);
extern unsigned char func_0c046b6c(struct Actor*);
extern unsigned char func_0c046d3c(struct Actor*);
unsigned char func_0c06d6e8(struct Actor *a);
unsigned char func_0c06d74e(struct Actor *a);
unsigned char func_0c06d7d4(struct Actor *a);
unsigned char func_0c06d83c(struct Actor *a);
unsigned char func_0c06d8c2(struct Actor *a);
unsigned char func_0c06d93c(struct Actor *a);
unsigned char func_0c06d97a(struct Actor *a);
unsigned char func_0c06d9c0(struct Actor *a);
int func_0c06d884(struct Actor *a);
int func_0c06da08(struct Actor *a);
int func_0c06da74(struct Actor *a);
void func_0c06d5fc(struct Actor *a);
void func_0c06d618(struct Actor *a);
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *);
extern unsigned char dat_0c240c10[],dat_0c240c20[];
extern void func_0c045248(struct Actor *,int);
extern unsigned char func_0c047068(struct Actor *,unsigned char *,unsigned char *);
extern void func_0c047aac(struct Actor *,unsigned char *);
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c044450(struct Actor *,struct Actor *);
extern int func_0c046d54(struct Actor *);
extern unsigned char dat_0c240c30[],dat_0c240c60[],dat_0c240c8c[],dat_0c240c70[],dat_0c240c7e[],dat_0c240c40[],dat_0c240c50[];
extern unsigned char func_0c046dd0(struct Actor *, int);
extern void func_0c045248(struct Actor *, int);
extern unsigned char func_0c046e7e(struct Actor *, unsigned char *, unsigned char *);
extern unsigned char dat_0c240c10[];
extern unsigned char dat_0c240c20[];
extern void (*table_0c240d10[])(struct Actor *);
void func_0c06d5fc(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c240ca0;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

void func_0c06d618(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c06d6e8(a))return;
 if(func_0c06d74e(a))return;
 if(func_0c06d83c(a))return;
 if(func_0c06d884(a))return;
 if(func_0c06d97a(a))return;
 if(func_0c06d7d4(a))return;
 if(func_0c06d9c0(a))return;
 if(func_0c06d8c2(a))return;
 if(func_0c06d93c(a))return;
 if(func_0c06da08(a))return;
 if(func_0c06da74(a))return;
 func_0c045f1c(a);
 func_0c0463fc(a);
}

unsigned char func_0c06d6e8(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c240c10,a->x374)||!*a->p40c)goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;
 func_0c045248(a,29);return 1;
}

unsigned char func_0c06d74e(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c240c20,a->x36c)||!*a->p40c)goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;
 func_0c045248(a,29);return 1;
}

unsigned char func_0c06d7d4(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c240c30,a->x364))goto fail;
 if(a->b1f9==2 && !a->b1fc){
 if(a->b1d4){fail:return 0;}
 a->b1d4++;
 }
 func_0c047aac(a,a->x364);
 zero=0;
 a->b5=zero;a->b7=zero;a->b6=zero;a->b1e9=zero;
 func_0c045248(a,21);
 return 1;
}
unsigned char func_0c06d83c(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c240c60,a->x37c))return 0;
 func_0c047aac(a,a->x37c);
 a->b1e9=3;
 a->b5=0;
 func_0c045248(a,21);
 a->b6=a->b7=0;
 return 1;
}
int func_0c06d884(struct Actor *a)
{
 struct Actor *target;
 if(!func_0c046e7e(a,dat_0c240c8c,a->x3a4))goto fail;
 if(!(target=func_0c037d54(a))){fail:return 0;}
 a->b1f7=67;
 func_0c044450(a,target);
 return 1;
}
unsigned char func_0c06d8c2(struct Actor *a)
{
 if(!func_0c047068(a,dat_0c240c70,a->x384))return 0;
 a->b1e9=4;
 a->b5=0;
 func_0c045248(a,21);
 a->b6=a->b7=0;
 return 1;
}
unsigned char func_0c06d93c(struct Actor *a)
{
 if(!func_0c047068(a,dat_0c240c7e,a->x394))return 0;
 a->b1e9=9;
 a->b5=0;
 func_0c045248(a,21);
 a->b6=a->b7=0;
 return 1;
}
unsigned char func_0c06d97a(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c240c40,a->x38c))return 0;
 func_0c047aac(a,a->x38c);
 a->b5=0;a->b7=0;a->b6=0;
 a->b1e9=8;
 func_0c045248(a,21);
 return 1;
}
unsigned char func_0c06d9c0(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c240c50,a->x39c))return 0;
 func_0c047aac(a,a->x39c);
 a->b1e9=7;
 a->b5=0;
 func_0c045248(a,21);
 a->b6=a->b7=0;
 return 1;
}
int func_0c06da08(struct Actor *a)
{
 if(!func_0c046d54(a))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b1e9=12;a->b5=0;
 func_0c045248(a,29);
 a->b6=a->b7=0;
 return 1;
}

int func_0c06da74(struct Actor *a)
{
    if (!func_0c046dd0(a, 11)) return 0;
    a->b1e9 = 11;
    a->b5 = 0;
    func_0c045248(a, 21);
    a->b6 = a->b7 = 0;
    return 1;
}

int func_0c06daae(struct Actor *a)
{
    if (func_0c06dad4(a)) return 1;
    if (func_0c06db0a(a)) return 1;
    return 0;
}

int func_0c06dad4(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c240c10, (unsigned char *)a + 0x374))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 2;
    return 1;
}

int func_0c06db0a(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c240c20, (unsigned char *)a + 0x36c)) return 0;
    if (!*a->p40c) return 0;
    if (a->b1f9 == 2) return 0;
    a->b258 = 1;
    return 1;
}

void func_0c06db4c(struct Actor *a)
{
    if (a->b1a0 == 0 || a->b5 != 0) *(unsigned char *)((char *)a + 0x2a8) = 0;
}

void func_0c06db64(struct Actor *a)
{
    table_0c240d10[a->b1ff](a);
}
