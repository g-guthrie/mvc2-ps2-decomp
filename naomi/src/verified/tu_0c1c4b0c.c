/* Exact linked unit. Allocate positioned graphics and scroll coordinates with a wrapping counter. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d9658;
extern struct Vec3_tu5_03 dat_0c25db2c;
extern void func_0c1d91a8(void *),func_0c1d8ff8(void *,void *);
extern int func_0c1d901e(void);
extern void func_0c1d912a(float *,float *),func_0c1d917e(float *,float *);
void func_0c1c4b5a(struct Obj_tu5_03 *);
void func_0c1c4b0c(void)
{
 struct Obj_tu5_03 *q;
 if((q=func_0c0374da(0,5,1))){
 q->b12c=1;q->p16=func_0c1c4b5a;
 q->l84=(int)((void **)dat_0c2d9658->p0)[6];
 q->pos=dat_0c25db2c;
 q->lcc=0x801;
 func_0c1d91a8((void *)q->l84);
 }
}
void func_0c1c4b5a(struct Obj_tu5_03 *q)
{
 float y,x;
 q->w28++;if(q->w28>=1000)q->w28=0;
 func_0c1d8ff8(((void **)dat_0c2d9658->p0)[7],(void *)q->l84);
 while(!func_0c1d901e()){
 func_0c1d912a(&x,&y);
 y-=q->w28*0.00100000005f;
 func_0c1d917e(&x,&y);
 }
}
