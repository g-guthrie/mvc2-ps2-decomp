/* Resource setup, timed scale growth, and paired UV scrolling. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern int **dat_0c2d9670;
extern int func_0c02abd4(void),func_0c1d91a8(int),func_0c1d8ff8(int,int),func_0c1d901e(void),func_0c1d912a(float *,float *),func_0c1d917e(float *,float *);
void func_0c1ca868(struct Obj_tu5_03 *),func_0c1ca8c4(struct Obj_tu5_03 *);
void func_0c1ca828(void){
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,11,1))){a->b12c=1;a->p16=func_0c1ca868;a->l84=(*dat_0c2d9670)[5];a->lcc=0x800;func_0c1d91a8((*dat_0c2d9670)[5]);}
}
void func_0c1ca868(struct Obj_tu5_03 *a){
 if(++a->w28>=360)a->w28=0;
 if(++a->w30>=200)a->w30=0;
 if(!func_0c02abd4()){float scale=a->f120;if(scale<1.0f){scale+=0.00312500005f;a->f120=scale;a->f124=scale;a->f128=scale;}}
 func_0c1ca8c4(a);
}
void func_0c1ca8c4(struct Obj_tu5_03 *a){
 /* Retail reserves 20 bytes; only the two scalar UV slots are accessed. */
 float u,v;unsigned char reserved[12];
 func_0c1d8ff8((*dat_0c2d9670)[6],a->l84);
 while(!func_0c1d901e()){
 func_0c1d912a(&u,&v);u+=a->w30*0.005f;v+=a->w30*0.005f;func_0c1d917e(&u,&v);
 }
}
