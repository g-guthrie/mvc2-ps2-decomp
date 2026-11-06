/* Exact linked unit. Alternate display position and update scrolling coordinates. */
#include "objects.h"
extern struct Vec3_tu5_03 table_0c232014[];
extern struct ActorGlobalRoot *dat_0c2d9680;
extern void func_0c1d8ff8(void *,void *);
extern int func_0c1d901e(void);
extern void func_0c1d912a(float *,float *),func_0c1d917e(float *,float *);
void func_0c1cd99c(struct Obj_tu5_03 *q)
{
 float offset;
 q->w28++;offset=0.050000001f;
 if(q->w28&1)offset=-0.050000001f;
 q->pos.y=table_0c232014[1].y+offset;
 if(q->w28==20){q->b4++;q->w28=0;q->pos=table_0c232014[1];}
}
void func_0c1cd9e2(struct Obj_tu5_03 *q)
{
 float x,y;
 q->w30++;if(q->w30>=200)q->w30=0;
 func_0c1d8ff8(((void **)dat_0c2d9680->p0)[7],(void *)q->l84);
 while(!func_0c1d901e()){
 func_0c1d912a(&x,&y);
 x+=-(q->w30*0.005f)+1.0f;
 func_0c1d917e(&x,&y);
 }
}
