/* Special-move checker unit for one character (0x0c1260d4-0x0c126578).
 */
#include "objects.h"
extern unsigned char dat_0c24d828[];
extern unsigned char dat_0c24d838[];
extern unsigned char dat_0c24d848[];
extern unsigned char dat_0c24d858[];
extern unsigned char dat_0c24d868[];
extern unsigned char dat_0c24d878[];
extern unsigned char dat_0c24d888[];
extern unsigned char dat_0c24d898[];
extern unsigned int dat_0c24d8a8[];
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
void func_0c1260d4(struct Actor *a);
void func_0c1260f0(struct Actor *a);
unsigned char func_0c1261bc(struct Actor *a);
unsigned char func_0c126216(struct Actor*a);
unsigned char func_0c12625c(struct Actor *a);
unsigned char func_0c1262ec(struct Actor*a);
unsigned char func_0c126332(struct Actor *a);
unsigned char func_0c12638a(struct Actor *a);
unsigned char func_0c126424(struct Actor *a);
unsigned char func_0c12648c(struct Actor*a);
int func_0c1264d2(struct Actor*a);
unsigned char func_0c126512(struct Actor*a);

void func_0c1260d4(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c24d8a8;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

void func_0c1260f0(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c126332(a))return;
 if(func_0c1262ec(a))return;
 if(func_0c1261bc(a))return;
 if(func_0c126424(a))return;
 if(func_0c12638a(a))return;
 if(func_0c126216(a))return;
 if(func_0c12625c(a))return;
 if(func_0c12648c(a))return;
 if(func_0c1264d2(a))return;
 if(func_0c126512(a))return;
 func_0c045f1c(a);
 func_0c0463fc(a);
}

unsigned char func_0c1261bc(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24d828,a->x364))return 0;
 if(!*a->p40c)return 0;
 if(((struct ActorSubMoveBytes *)&a->sub2a4)->b7)return 0;
 func_0c047aac(a,a->x364);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=0;
 func_0c045248(a,29);return 1;
}

unsigned char func_0c126216(struct Actor*a){if(!func_0c046e7e(a,dat_0c24d838,a->x36c))return 0;func_0c047aac(a,a->x36c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;func_0c045248(a,21);return 1;}

unsigned char func_0c12625c(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24d848,a->x37c))goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x37c);
 
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;
 func_0c045248(a,21);return 1;
}

unsigned char func_0c1262ec(struct Actor*a){if(!func_0c046e7e(a,dat_0c24d858,a->x374))return 0;func_0c047aac(a,a->x374);a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;func_0c045248(a,21);return 1;}

unsigned char func_0c126332(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24d868,a->x384))return 0;
 if(!*a->p40c)return 0;
 if(((struct ActorSubMoveBytes *)&a->sub2a4)->b7)return 0;
 func_0c047aac(a,a->x384);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;
 func_0c045248(a,29);return 1;
}

unsigned char func_0c12638a(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24d878,a->x38c))return 0;
 else if(((struct ActorSubMoveBytes *)&a->sub2a4)->b7)return 0;
 func_0c047aac(a,a->x38c);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=8;
 func_0c045248(a,21);
 if(!a->b525)a->sub2a4.w8=(unsigned char)a->b1a3;else a->sub2a4.w8=(unsigned char)a->b1fe;
 return 1;
}

unsigned char func_0c126424(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24d888,a->x39c))return 0;
 else if(((struct ActorSubMoveBytes *)&a->sub2a4)->b7)return 0;
 func_0c047aac(a,a->x39c);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=8;
 func_0c045248(a,21);
 if(!a->b525)a->sub2a4.w8=2;else a->sub2a4.w8=(unsigned char)a->b1fe;
 return 1;
}

unsigned char func_0c12648c(struct Actor*a){if(!func_0c046e7e(a,dat_0c24d898,a->x394))return 0;func_0c047aac(a,a->x394);a->b5=0;a->b7=0;a->b6=0;a->b1e9=12;func_0c045248(a,21);return 1;}

int func_0c1264d2(struct Actor*a){if(!func_0c046d54(a))return 0;else if(!*a->p40c)return 0;a->b1e9=13;a->b5=0;func_0c045248(a,29);a->b6=(((char*)a)[7]=0);return 1;}

unsigned char func_0c126512(struct Actor*a){if(!func_0c046dd0(a,7))return 0;a->b5=0;a->b7=0;a->b6=0;a->b1e9=7;func_0c045248(a,21);return 1;}
