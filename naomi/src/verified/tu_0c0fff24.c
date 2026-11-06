/* Special-move checker unit for one character (0x0c0fff24-0x0c1003d8). */
#include "objects.h"
extern unsigned char dat_0c24ae84[];
extern unsigned char dat_0c24ae98[];
extern unsigned char dat_0c24aeac[];
extern unsigned char dat_0c24aebc[];
extern unsigned char dat_0c24aecc[];
extern unsigned char dat_0c24aedc[];
extern unsigned char dat_0c24aef0[];
extern unsigned int dat_0c24af60[];
extern void func_0c045248(struct Actor*,int);
extern void func_0c045f1c(struct Actor*);
extern unsigned char func_0c0462a0(struct Actor*);
extern void func_0c0463fc(struct Actor*);
extern unsigned char func_0c0465cc(struct Actor*);
extern unsigned char func_0c0469f4(struct Actor*);
extern unsigned char func_0c046b6c(struct Actor*);
extern unsigned char func_0c046d3c(struct Actor*);
extern int func_0c046d54(struct Actor*);
extern unsigned char func_0c046dd0(struct Actor*,int);
extern unsigned char func_0c046e7e(struct Actor*,unsigned char*,unsigned char*);
extern void func_0c047aac(struct Actor*,unsigned char*);
void func_0c0fff24(struct Actor *a);
void func_0c0fff40(struct Actor *a);
int func_0c100010(struct Actor*a);
unsigned char func_0c100050(struct Actor *a);
unsigned char func_0c1000ac(struct Actor *a);
unsigned char func_0c100150(struct Actor *a);
unsigned char func_0c1001c0(struct Actor *a);
unsigned char func_0c10023c(struct Actor *a);
unsigned char func_0c1002b6(struct Actor *a);
unsigned char func_0c100308(struct Actor *a);
unsigned char func_0c10037a(struct Actor*a);

void func_0c0fff24(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c24af60;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

void func_0c0fff40(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c100050(a))return;
 if(func_0c1000ac(a))return;
 if(func_0c100308(a))return;
 if(func_0c1002b6(a))return;
 if(func_0c100150(a))return;
 if(func_0c1001c0(a))return;
 if(func_0c10023c(a))return;
 if(func_0c100010(a))return;
 if(func_0c10037a(a))return;
 if(func_0c0462a0(a))return;
 func_0c045f1c(a);
 func_0c0463fc(a);
}

int func_0c100010(struct Actor*a){if(!func_0c046d54(a))return 0;else if(!*a->p40c)return 0;a->b1e9=12;a->b5=0;func_0c045248(a,29);a->b6=(((char*)a)[7]=0);return 1;}

unsigned char func_0c100050(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c24aeac,a->x364))return 0;
 else if(!*a->p40c)return 0;
 func_0c047aac(a,a->x364);
 zero=0;a->b5=zero;func_0c045248(a,29);a->b7=zero;a->b6=zero;a->b1e9=2;a->b1ff=zero;
 return 1;
}

unsigned char func_0c1000ac(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c24aebc,a->x36c))goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4)goto fail;a->b1d4++;}
 if(!*a->p40c){fail:return 0;}
 func_0c047aac(a,a->x36c);
 zero=0;a->b5=zero;func_0c045248(a,29);a->b7=zero;a->b6=zero;a->b1e9=3;a->b1ff=zero;
 return 1;
}

unsigned char func_0c100150(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c24ae84,a->x374))goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x374);
 zero=0;a->b5=zero;func_0c045248(a,21);a->b7=zero;a->b6=zero;a->b1e9=zero;a->b1ff=zero;
 return 1;
}

unsigned char func_0c1001c0(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c24ae98,a->x37c))goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4)goto fail;a->b1d4++;}
 if(((struct ActorSubMoveBytes *)&a->sub2a4)->b14){fail:return 0;}
 func_0c047aac(a,a->x37c);
 zero=0;a->b5=zero;func_0c045248(a,21);a->b7=zero;a->b6=zero;a->b1e9=1;a->b1ff=zero;
 return 1;
}

unsigned char func_0c10023c(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c24aecc,a->x384))return 0;
 func_0c047aac(a,a->x384);
 zero=0;a->b5=zero;func_0c045248(a,21);a->b7=zero;a->b6=zero;a->b1e9=4;a->b1ff=zero;
 return 1;
}

unsigned char func_0c1002b6(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c24aedc,a->x394))return 0;
 func_0c047aac(a,a->x394);
 zero=0;a->b5=zero;func_0c045248(a,21);a->b7=zero;a->b6=zero;a->b1e9=8;a->b1ff=zero;
 return 1;
}

unsigned char func_0c100308(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c24aef0,a->x38c))goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x38c);
 zero=0;a->b5=zero;func_0c045248(a,21);a->b7=zero;a->b6=zero;a->b1e9=7;a->b1ff=zero;
 return 1;
}

unsigned char func_0c10037a(struct Actor*a){if(!func_0c046dd0(a,6))return 0;a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;func_0c045248(a,21);return 1;}
