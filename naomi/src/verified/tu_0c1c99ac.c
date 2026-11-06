#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern int func_0c1d91a8(int);
extern void func_0c1d8ff8(int,int);
extern int func_0c1d901e(void);
extern void func_0c1d912a(float *,float *),func_0c1d917e(float *,float *);
extern unsigned char dat_0c2306ec[];
extern int **dat_0c2d9664;
extern struct Vec3_tu5_03 dat_0c230620[],dat_0c2306e0[];
void func_0c1c9b28(struct Obj_tu5_03 *);
#pragma inline(lerp)
static void lerp(struct Obj_tu5_03 *q,struct Vec3_tu5_03 *start,struct Vec3_tu5_03 *end){
 q->pos.x=start->x+(end->x-start->x)/30.0f*q->w28;
 q->pos.y=start->y+(end->y-start->y)/30.0f*q->w28;
 q->pos.z=start->z+(end->z-start->z)/30.0f*q->w28;
}
void func_0c1c99ac(struct Obj_tu5_03 *q){struct Vec3_tu5_03 *start=&dat_0c230620[q->b32*2];lerp(q,start,start+1);}
void func_0c1c9a16(int index){
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,11,1))){
 a->b12c=1;a->b32=index;a->p16=func_0c1c9b28;a->pad34=dat_0c2306ec[index];
 a->l84=(*dat_0c2d9664)[a->pad34];
 a->pos=dat_0c230620[index*2];
 a->angles.array[0]=(int)(dat_0c2306e0->x*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l44=(int)(dat_0c2306e0->y*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l48=(int)(dat_0c2306e0->z*65536.0f/360.0f+0.5f)&65535;
 a->lcc=3;
 a->w28=0;a->w30=0;
 if(index>=2)return;
 func_0c1d91a8(a->l84);
 }
}
void func_0c1c9b28(struct Obj_tu5_03 *a){
 float u,v;
 if(a->w28!=30){a->w28++;func_0c1c99ac(a);}
 if(a->b32>=2)return;
 a->w30++;if(a->w30>=200)a->w30=0;
 func_0c1d8ff8((*dat_0c2d9664)[a->pad34+1],a->l84);
 while(!func_0c1d901e()){
 func_0c1d912a(&u,&v);
 if(a->b32&1)u+=a->w30*0.005f;
 else u+=-(a->w30*0.005f)+1.0f;
 func_0c1d917e(&u,&v);
 }
}
