#include "objects.h"
extern unsigned int dat_0c242370[];
extern void func_0c045f1c(struct Actor*);
extern unsigned char func_0c04608a(struct Actor*,unsigned char*);
extern void func_0c0463fc(struct Actor*);
extern unsigned char func_0c0465cc(struct Actor*);
extern unsigned char func_0c0469f4(struct Actor*);
extern unsigned char func_0c046b6c(struct Actor*);
extern unsigned char func_0c046d3c(struct Actor*);
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *),func_0c046dd0(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern void func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
extern unsigned char dat_0c2422fa[],dat_0c24230a[],dat_0c24231a[],dat_0c24232a[],dat_0c24233e[],dat_0c24234e[],dat_0c24235e[];
void func_0c08643c(struct Actor *a);
void func_0c086458(struct Actor *a);
unsigned char func_0c086530(struct Actor *a);
unsigned char func_0c086578(struct Actor *a);
unsigned char func_0c0865ec(struct Actor *a);
unsigned char func_0c08669e(struct Actor *a);
unsigned char func_0c0866e4(struct Actor *a);
unsigned char func_0c0867b4(struct Actor *a);
unsigned char func_0c08680e(struct Actor *a);
unsigned char func_0c08685e(struct Actor *a);
unsigned char func_0c086896(struct Actor *a);

void func_0c08643c(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c242370;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

void func_0c086458(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c08680e(a))return;
 if(func_0c08669e(a))return;
 if(func_0c0866e4(a))return;
 if(func_0c0867b4(a))return;
 if(func_0c086530(a))return;
 if(func_0c086578(a))return;
 if(func_0c0865ec(a))return;
 if(func_0c08685e(a))return;
 if(func_0c086896(a))return;
 if(func_0c04608a(a,a->x3c4))return;
 func_0c045f1c(a);
 func_0c0463fc(a);
}

unsigned char func_0c086530(struct Actor *a)
{
 int zero;
 if(!func_0c046e7e(a,dat_0c2422fa,a->x36c))return 0;
 func_0c047aac(a,a->x36c);zero=0;a->b5=zero;a->b6=zero;a->b7=zero;a->b1e9=zero;func_0c045248(a,21);return 1;
}
unsigned char func_0c086578(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(!func_0c046e7e(a,dat_0c24230a,a->x374))goto fail;
 if(a->b1f9==2){if(a->b1d4)goto fail;a->b1d4++;}
 if(sub->b0){fail:return 0;}
 func_0c047aac(a,a->x374);a->b5=0;a->b6=0;a->b7=0;a->b1e9=1;func_0c045248(a,21);return 1;
}
unsigned char func_0c0865ec(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 int zero;
 if(!func_0c046e7e(a,dat_0c24231a,a->x37c))goto fail;
 if(a->b1d0==25)goto fail;
 zero=0;sub->b6=zero;
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}else sub->b6=3;}
 func_0c047aac(a,a->x37c);a->b5=zero;a->b6=zero;a->b7=zero;a->b1e9=2;func_0c045248(a,21);return 1;
}
unsigned char func_0c08669e(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24232a,a->x384))return 0;
 func_0c047aac(a,a->x384);a->b5=0;a->b6=0;a->b7=0;a->b1e9=3;func_0c045248(a,21);return 1;
}
unsigned char func_0c0866e4(struct Actor *a)
{
 unsigned int command;
 if(!func_0c046e7e(a,dat_0c24233e,a->x38c))goto fail;
 if(!*a->p40c)goto fail;
 if(a->b1f9==2){
 if(!a->b1fc && a->b1d4)goto fail;
 command=a->b1d0;
 if(command!=10 && command!=11){if(a->f56<a->f41c+25.714285f || a->f56>a->f41c+925.7142334f){fail:return 0;}}
 }
 func_0c047aac(a,a->x38c);a->b5=0;a->b6=0;a->b7=0;a->b1e9=4;func_0c045248(a,29);return 1;
}
unsigned char func_0c0867b4(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24234e,a->x394)||!*a->p40c||a->b1f9==2)return 0;
 func_0c047aac(a,a->x394);a->b5=0;a->b6=0;a->b7=0;a->b1e9=5;func_0c045248(a,29);return 1;
}
unsigned char func_0c08680e(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c24235e,a->x39c))goto fail;
 if(!*a->p40c){fail:return 0;}
 func_0c047aac(a,a->x39c);a->b5=0;a->b6=0;a->b7=0;a->b1e9=6;func_0c045248(a,29);return 1;
}
unsigned char func_0c08685e(struct Actor *a)
{
 if(!func_0c046dd0(a,7))return 0;
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=7;func_0c045248(a,21);return 1;
}
unsigned char func_0c086896(struct Actor *a)
{
 if(!func_0c046d54(a))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b5=0;a->b6=0;a->b7=0;a->b1e9=8;func_0c045248(a,29);return 1;
}
