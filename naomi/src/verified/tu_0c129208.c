#include "objects.h"
extern int dat_0c24dae0;
extern unsigned char dat_0c24daf0[];
extern unsigned char dat_0c24db10[];
extern unsigned char dat_0c24db20[];
extern unsigned int dat_0c24dc28[];
typedef void (*handler_0c129694)(struct Actor *);
extern handler_0c129694 dat_0c24dc98[];
extern unsigned char dat_0c24dbb0[];
extern unsigned char func_0c047b60(struct Actor*,int,unsigned short*,int);
extern unsigned char func_0c047886(struct Actor*);
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
void func_0c129208(struct Actor *a);
void func_0c129224(struct Actor *a);
unsigned char func_0c1292b4(struct Actor *a);
unsigned char func_0c129330(struct Actor *a);
unsigned char func_0c12941e(struct Actor*a);
unsigned char func_0c129494(struct Actor *a);
unsigned char func_0c1294e4(struct Actor *a);
unsigned char func_0c129534(struct Actor *a);
unsigned char func_0c129572(struct Actor*a);
int func_0c1295d2(struct Actor *a);
int func_0c1295f8(struct Actor *a);
int func_0c12962e(struct Actor *a);
void func_0c129664(struct Actor *a);
void func_0c129694(struct Actor *a);

void func_0c129208(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c24dc28;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

void func_0c129224(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c129494(a))return;
 if(func_0c1294e4(a))return;
 if(func_0c1292b4(a))return;
 if(func_0c12941e(a))return;
 if(func_0c129330(a))return;
 if(func_0c129572(a))return;
 if(func_0c129534(a))return;
 func_0c045f1c(a);
 func_0c0463fc(a);
}

unsigned char func_0c1292b4(struct Actor *a)
{
    if (func_0c046e7e(a, &dat_0c24dae0, a->x36c) == 0)
        return 0;
    func_0c047aac(a, a->x36c);
    a->b5 = 0;
    a->b6 = 0;
    a->b7 = 0;
    a->b1e9 = 0;
    func_0c045248(a, 21);
    return 1;
}

unsigned char func_0c129330(struct Actor *a)
{
    unsigned short v;
    int t;
    int one;
    struct ActorSub2a4 *sub=&a->sub2a4;
    if(sub->b0) return 0;
    if(!func_0c047b60(a,0x140,&v,1)) return 0;
    goto c;c:if(!func_0c047886(a)) return 0;
    if(a->b525){ v=a->w1fa; if(a->b1d2){if(v&0xc00) v^=0xc00;} }
    else v=a->w340;
    v=(v&0x3c00)>>10;
    if(!v) v=2-a->b1d2;
    if(a->b1f9==2) v+=16;
    t=dat_0c24dbb0[v];
    if(!t) return 0;
    one=1; if(a->b1f9==2) goto ok; goto s;s:if(v&(1<<a->b1d2)) return 0; ok:
    a->b34=t+255;
    a->b5=0;a->b6=0;a->b7=0;
    a->b1a3=one;a->b1e9=one;
    func_0c045248(a,21);
    return one;
}

unsigned char func_0c12941e(struct Actor*a){if(!func_0c046e7e(a,dat_0c24daf0,a->x37c))return 0;func_0c047aac(a,a->x37c);a->b5=0;a->b6=0;a->b7=0;a->b1e9=2;func_0c045248(a,21);return 1;}

unsigned char func_0c129494(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24db10,a->x38c))goto fail;
 if(!*a->p40c){fail:return 0;}
 func_0c047aac(a,a->x38c);a->b5=0;a->b6=0;a->b7=0;a->b1e9=4;func_0c045248(a,29);return 1;
}

unsigned char func_0c1294e4(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24db20,a->x394))goto fail;
 if(!*a->p40c){fail:return 0;}
 func_0c047aac(a,a->x394);a->b5=0;a->b6=0;a->b7=0;a->b1e9=5;func_0c045248(a,29);return 1;
}

unsigned char func_0c129534(struct Actor *a)
{
 if(!func_0c046d54(a))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=8;func_0c045248(a,29);return 1;
}

unsigned char func_0c129572(struct Actor*a){if(!func_0c046dd0(a,9))return 0;a->b5=0;a->b6=0;a->b7=0;a->b1e9=9;func_0c045248(a,21);return 1;}

int func_0c1295d2(struct Actor *a)
{
    if (func_0c1295f8(a)) return 1;
    if (func_0c12962e(a)) return 1;
    return 0;
}

int func_0c1295f8(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24db10, (unsigned char *)a + 0x38c))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 4;
    return 1;
}

int func_0c12962e(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24db20, (unsigned char *)a + 0x394))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 5;
    return 1;
}

void func_0c129664(struct Actor *a)
{
    struct ActorSub2a4 *sub=&a->sub2a4;
    if(a->b200) a->b205=24; else a->b205=0;
    if(sub->b0 && a->b1f9!=2) sub->b0=0;
}

void func_0c129694(struct Actor *a)
{
    dat_0c24dc98[a->b1ff](a);
}
