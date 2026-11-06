/* Resource setup, cyclic counters, and scalar UV scrolling. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void ***dat_0c2d9670;
extern int func_0c1d91a8(void *),func_0c1d8ff8(void *,void *),func_0c1d901e(void),func_0c1d912a(float *,float *),func_0c1d917e(float *,float *);
void func_0c1cb230(struct LinkedActor *),func_0c1cb25a(struct LinkedActor *);
void func_0c1cb1f0(void){
 struct LinkedActor *a;
 if((a=func_0c0374da(0,11,1))){
 a->sdc.b12c=1;a->p16=func_0c1cb230;a->p84=(*dat_0c2d9670)[7];a->wcc.dword_value=0;
 func_0c1d91a8((*dat_0c2d9670)[7]);
 }
}
void func_0c1cb230(struct LinkedActor *a){
 if(++a->s28>=360)a->s28=0;
 if(++a->s30>=200)a->s30=0;
 func_0c1cb25a(a);
}
void func_0c1cb25a(struct LinkedActor *a){
 /* Native 0c1cb266/0c1cb2c2 reserves20 bytes; only u/v are accessed.
  * Retain the unused12 bytes without inventing additional UV semantics. */
 float u,v; unsigned char reserved[12];
 func_0c1d8ff8((*dat_0c2d9670)[8],a->p84);
 while(!func_0c1d901e()){
 func_0c1d912a(&u,&v);u-=a->s30*0.005f;v+=a->s30*0.005f;func_0c1d917e(&u,&v);
 }
}
