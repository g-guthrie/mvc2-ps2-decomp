#include "objects.h"
extern unsigned char dat_0c24df4c[];
extern unsigned char dat_0c24df5c[];
extern unsigned char dat_0c24df6c[];
extern unsigned char dat_0c24df7c[];
extern unsigned char dat_0c24df8c[];
extern unsigned char dat_0c24df9c[];
extern unsigned char dat_0c24dfac[];
extern unsigned int dat_0c24dfbc[];
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
void func_0c12e38c(struct Actor *a);
void func_0c12e3a8(struct Actor *a);
int func_0c12e458(struct Actor *a);
int func_0c12e4c0(struct Actor *a);
int func_0c12e50e(struct Actor*a);
int func_0c12e57c(struct Actor *a);
int func_0c12e5ca(struct Actor *a);
int func_0c12e61e(struct Actor *a);
int func_0c12e6a4(struct Actor *a);
int func_0c12e6e2(struct Actor*a);
int func_0c12e728(struct Actor *a);
int func_0c12e770(struct Actor *a);
int func_0c12e796(struct Actor *a);
int func_0c12e7fa(struct Actor *a);

void func_0c12e38c(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c24dfbc;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

void func_0c12e3a8(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c12e5ca(a))return;
 if(func_0c12e61e(a))return;
 if(func_0c12e6e2(a))return;
 if(func_0c12e458(a))return;
 if(func_0c12e50e(a))return;
 if(func_0c12e4c0(a))return;
 if(func_0c12e57c(a))return;
 if(func_0c12e728(a))return;
 if(func_0c12e6a4(a))return;
 func_0c045f1c(a);
 func_0c0463fc(a);
}

int func_0c12e458(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24df7c,a->x36c))goto fail;
 func_0c047aac(a,a->x36c);
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}}
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=0;
 func_0c045248(a,21);return 1;
}



int func_0c12e4c0(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24df9c,a->x38c))return 0;
 else if(*(int *)&a->sub2a4>0)return 0;
 func_0c047aac(a,a->x38c);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=7;
 func_0c045248(a,21);return 1;
}


int func_0c12e50e(struct Actor*a){if(!func_0c046e7e(a,dat_0c24df8c,a->x394))return 0;func_0c047aac(a,a->x394);a->b5=0;a->b7=0;a->b6=0;a->b1e9=9;func_0c045248(a,21);return 1;}

int func_0c12e57c(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24df6c,a->x374))return 0;
 else if(*(int *)&a->sub2a4>0)return 0;
 func_0c047aac(a,a->x374);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;
 func_0c045248(a,21);return 1;
}


int func_0c12e5ca(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24df4c,a->x37c))return 0;
 if(!*a->p40c)return 0;
 if(*(int *)&a->sub2a4>0)return 0;
 a->b12c=1;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;
 func_0c045248(a,29);return 1;
}



int func_0c12e61e(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24df5c,a->x384))return 0;
 else if(!*a->p40c)return 0;
 a->b12c=1;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=5;
 func_0c045248(a,29);
 a->b202=0x80;a->i204=10;
 return 1;
}


int func_0c12e6a4(struct Actor *a)
{
 if(!func_0c046d54(a))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b1e9=2;a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,29);return 1;
}

int func_0c12e6e2(struct Actor*a){if(!func_0c046e7e(a,dat_0c24dfac,a->x39c))return 0;func_0c047aac(a,a->x39c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=8;func_0c045248(a,21);return 1;}

int func_0c12e728(struct Actor *a)
{
 register char k;
 if(!func_0c046dd0(a,4))return 0;
 k=4;
 if(a->l2c8>0){k=10;a->l2c8=0;}
 a->b1e9=k;
 a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);return 1;
}


int func_0c12e770(struct Actor *a)
{
    if (func_0c12e796(a)) return 1;
    if (func_0c12e7fa(a)) return 1;
    return 0;
}

int func_0c12e796(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24df4c,a->x37c))return 0;
 else if(!*a->p40c)return 0;
 a->b12c=1;a->b258=3;return 1;
}

int func_0c12e7fa(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24df5c,a->x384))return 0;
 else if(!*a->p40c)return 0;
 a->b12c=1;a->b258=5;a->b202=0x80;a->i204=60;return 1;
}
