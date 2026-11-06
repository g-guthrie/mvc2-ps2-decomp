#include "objects.h"
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *),func_0c0462a0(struct Actor *);
extern unsigned char func_0c04608a(struct Actor *,unsigned char *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *),func_0c0474f8(struct Actor *,unsigned char *,unsigned char *);
extern void func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern unsigned char func_0c046dd0(struct Actor *,int);
extern unsigned char dat_0c24026c[],dat_0c24027c[],dat_0c24028c[],dat_0c24029a[],dat_0c2402aa[],dat_0c2402bc[],dat_0c2402ca[],dat_0c2402dc[];
unsigned char func_0c06461c(struct Actor *),func_0c064696(struct Actor *),func_0c064720(struct Actor *),func_0c064786(struct Actor *),func_0c06480c(struct Actor *),func_0c064872(struct Actor *),func_0c0648d8(struct Actor *),func_0c064946(struct Actor *),func_0c0649ac(struct Actor *),func_0c0649ec(struct Actor *);
void func_0c064520(struct Actor *a)
{
 if(func_0c0465cc(a)||func_0c046b6c(a)||func_0c0469f4(a)||func_0c046d3c(a)||func_0c06480c(a)||func_0c064872(a)||func_0c0648d8(a)||func_0c064946(a)||func_0c06461c(a)||func_0c064696(a)||func_0c064786(a)||func_0c064720(a))return;
 if(a->b14a!=128 && func_0c0462a0(a))return;
 if(func_0c04608a(a,a->x3cc)||func_0c0649ac(a)||func_0c0649ec(a))return;
 func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c06461c(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24026c,a->x36c))goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x36c);
 a->b1a3+=a->b1fe*2;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=0;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c064696(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24027c,a->x374))goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x374);
 
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c064720(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24028c,a->x37c))goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x37c);
 
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c064786(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24029a,a->x384))goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x384);
 
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c06480c(struct Actor *a)
{
 if(!func_0c0474f8(a,dat_0c2402aa,a->x38c)||!*a->p40c)goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;
 func_0c045248(a,29);return 1;
}

unsigned char func_0c064872(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c2402bc,a->x394)||!*a->p40c)goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=5;
 func_0c045248(a,29);return 1;
}

unsigned char func_0c0648d8(struct Actor *a)
{
 if(!func_0c0474f8(a,dat_0c2402ca,a->x39c))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;func_0c045248(a,29);return 1;
}
unsigned char func_0c064946(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c2402dc,a->x3a4)||!*a->p40c)goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=7;
 func_0c045248(a,29);return 1;
}

unsigned char func_0c0649ac(struct Actor *a)
{
 if(!func_0c046d54(a))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b1e9=8;a->b5=0;
 func_0c045248(a,29);
 a->b6=a->b7=0;
 return 1;
}

unsigned char func_0c0649ec(struct Actor *a)
{
    if (!func_0c046dd0(a, 9)) return 0;
    a->b1e9 = 9;
    a->b5 = 0;
    func_0c045248(a, 21);
    a->b6 = a->b7 = 0;
    return 1;
}
