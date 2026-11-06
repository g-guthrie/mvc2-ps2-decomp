/* Linked effect spawners and dispatchers 0x0c1476d0-0x0c1477d4. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern unsigned char *dat_0c2fb33c;
extern short *dat_0c2fb340;
extern void (*table_0c24fd00[])(struct LinkedActor *);
extern void (*table_0c24fd10[])(struct LinkedActor *);
void func_0c14777c(struct LinkedActor *);

struct LinkedActor *func_0c1476d0(struct LinkedActor *p,unsigned char x)
{
 struct LinkedActor *q;
 if((q=func_0c0374da(0,1,0))!=0){q->p16=func_0c14777c;q->p24=p;q->b32=x;q->w38=0x1101;}
 return q;
}

struct LinkedActor *func_0c147704(struct LinkedActor *p)
{
 struct LinkedActor *q;
 if((q=func_0c0374da((int)p,1,2))!=0){q->p16=func_0c14777c;q->p24=p->p24;q->p20=p;p->p20=q;q->b32=1;q->w38=0x1101;}
 return q;
}

struct LinkedActor *func_0c14773a(struct LinkedActor *p,unsigned char y)
{
 struct LinkedActor *q;
 if((q=func_0c0374da((int)p,1,2))!=0){q->p16=func_0c14777c;q->p24=p->p24;q->p20=p;q->b32=3;q->b33=y;q->w38=0x1101;}
 return q;
}

void func_0c14777c(struct LinkedActor *a)
{
 dat_0c2fb33c=(unsigned char *)&A(a->p24)->sub2a4;dat_0c2fb340=&a->wcc.short_value;
 table_0c24fd00[a->b32](a);
}

void func_0c1477a4(struct LinkedActor *a){table_0c24fd10[a->b4](a);}
