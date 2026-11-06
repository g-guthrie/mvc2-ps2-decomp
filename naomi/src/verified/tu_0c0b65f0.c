#include "objects.h"
extern int dat_0c244f78;
extern int dat_0c244f88;
extern int dat_0c244f98;
extern unsigned char dat_0c244fa8[];
extern unsigned char dat_0c244fb8[];
extern int dat_0c244fc8;
extern unsigned int dat_0c244fd8[];
extern void func_0c045248(struct Actor*,int);
extern void func_0c045f1c(struct Actor*);
extern void func_0c0463fc(struct Actor*);
extern unsigned char func_0c0465cc(struct Actor*);
extern unsigned char func_0c0469f4(struct Actor*);
extern unsigned char func_0c046b6c(struct Actor*);
extern unsigned char func_0c046d3c(struct Actor*);
extern unsigned char func_0c046e7e(struct Actor*,unsigned char*,unsigned char*);
extern void func_0c047aac(struct Actor*,unsigned char*);
void func_0c0b65f0(struct Actor *a);
void func_0c0b660c(struct Actor *a);
unsigned char func_0c0b6692(struct Actor *a);
unsigned char func_0c0b66ce(struct Actor *a);
unsigned char func_0c0b674a(struct Actor *a);
unsigned char func_0c0b6786(struct Actor*a);
unsigned char func_0c0b67cc(struct Actor *a);
unsigned char func_0c0b6808(struct Actor*a);

int func_0c0b684e(void);
void func_0c0b65f0(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c244fd8;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

void func_0c0b660c(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c0b674a(a))return;
 if(func_0c0b67cc(a))return;
 if(func_0c0b66ce(a))return;
 if(func_0c0b6692(a))return;
 if(func_0c0b6808(a))return;
 if(func_0c0b6786(a))return;
 func_0c045f1c(a);
 func_0c0463fc(a);
}

unsigned char func_0c0b6692(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c244f78, a->x364) == 0)
        return 0;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 5;
    func_0c045248(a, 21);
    return 1;
}

unsigned char func_0c0b66ce(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c244f88, a->x36c) == 0)
        return 0;
    func_0c047aac(a, a->x36c);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 0;
    func_0c045248(a, 21);
    return 1;
}

unsigned char func_0c0b674a(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c244f98, a->x374) == 0)
        return 0;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 1;
    func_0c045248(a, 29);
    return 1;
}

unsigned char func_0c0b6786(struct Actor*a){if(!func_0c046e7e(a,dat_0c244fa8,a->x37c))return 0;func_0c047aac(a,a->x37c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;func_0c045248(a,21);return 1;}

unsigned char func_0c0b67cc(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c244fc8, a->x384) == 0)
        return 0;
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 3;
    func_0c045248(a, 29);
    return 1;
}

unsigned char func_0c0b6808(struct Actor*a){if(!func_0c046e7e(a,dat_0c244fb8,a->x38c))return 0;func_0c047aac(a,a->x38c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;func_0c045248(a,21);return 1;}
int func_0c0b684e(void) { return 0; }

