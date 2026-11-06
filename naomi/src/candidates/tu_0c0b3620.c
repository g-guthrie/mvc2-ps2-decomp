/* Candidate: four complete functions and the pool match. The bookkeeping
 * function differs in six register-allocation words. */
#include "objects.h"
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *);
extern int func_0c046d54(struct Actor *);
extern void func_0c045248(struct Actor *,int);
extern unsigned char dat_0c244c64[],dat_0c244c74[];
extern void (*table_0c244db0[])(struct Actor *);
int func_0c0b3620(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c244c64,a->x364))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b258=0;return 1;
}
int func_0c0b3656(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c244c74,a->x36c))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b258=1;return 1;
}
int func_0c0b368e(struct Actor *a)
{
 if(!func_0c046d54(a))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b1e9=8;a->b5=0;
 func_0c045248(a,29);
 a->b6=a->b7=0;return 1;
}
void func_0c0b36ce(struct Actor *a)
{
 ((struct ActorCommandState *)&a->sub2a4)->flags12 = ((struct ActorCommandState *)&a->sub2a4)->flags12 & a->w340;
 if(((struct ActorCommandState *)&a->sub2a4)->timer32){
  if(((struct ActorCommandState *)&a->sub2a4)->timer32<0) ((struct ActorCommandState *)&a->sub2a4)->timer32=0;
  else ((struct ActorCommandState *)&a->sub2a4)->timer32--;
 }
}
void func_0c0b36fc(struct Actor *a){table_0c244db0[a->b1ff](a);}
