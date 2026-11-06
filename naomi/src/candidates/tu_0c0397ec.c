/* Candidate: actor mask and state dispatch at 0x0c0397ec. First three functions (156 executable bytes) are exact; final flag initializer differs in register allocation and one literal-pool word. */
#include "objects.h"
extern unsigned char dat_0c2f833e,dat_0c2f8338;
extern void func_0c043248(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0453c4(struct Actor *,int);
extern char func_0c02a026(struct Actor *);
extern void (*table_0c23b8b4[])(struct Actor *),(*table_0c23b8c4[])(struct Actor *);
void func_0c0397ec(register struct Actor *a)
{
 unsigned char mask;
 if(!a->b0||a->p20c->b248)goto done;
 goto mask_check;mask_check:mask=dat_0c2f833e;
 if(mask){if(mask&(1<<(a->b2^1)))goto done;goto fade_check;fade_check:if(!a->b3f0){func_0c043248(a);return;}}
 table_0c23b8b4[a->b4](a);return;
 done:return;
}
void func_0c039842(struct Actor *a){table_0c23b8c4[a->b5](a);}
void func_0c039854(struct Actor *a)
{
 a->b19d=0;((void (**)(struct Actor *))a->p428)[6](a);
 if(a->b5){a->b5=1;func_0c02a0c4(a,0,0);}
}
void func_0c039888(struct Actor *a)
{
 func_0c02a026(a);
 if(dat_0c2f8338>2){
 int zero=0;unsigned int flags;
 a->b4=1;a->b5=a->b6=a->b7=zero;a->b19d=-128;
 flags=a->l414;
 if(!((flags&0x06000000)|zero)){a->b1d2=a->b2?zero:1;a->w130=a->b1d2;}
 a->b1d0=0;func_0c0453c4(a,0);
 }
}
