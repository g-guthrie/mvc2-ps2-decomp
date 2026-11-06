#include "objects.h"
extern struct Vec3_tu5_03 table_0c231e84[];
extern struct ActorGlobalRoot *dat_0c2d9680;
extern struct ActorFlags *dat_0c2d6f84;
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern void func_0c037688(struct Obj_tu5_03 *);
extern void func_0c1d8ff8(void *,void *);
extern int func_0c1d901e(void);
extern void func_0c1d9100(struct Vec3_tu5_03 *),func_0c1d914c(struct Vec3_tu5_03 *);
extern float func_0c1ec2c0(int);
void func_0c1cd404(struct Obj_tu5_03 *);
void func_0c1cd330(struct Obj_tu5_03 *q) {
 struct Vec3_tu5_03 *from=&table_0c231e84[0],*to=&table_0c231e84[1];
 q->pos.x=from->x+(to->x-from->x)*q->w28/60.0f;
 q->pos.y=from->y+(to->y-from->y)*q->w28/60.0f;
 q->pos.z=from->z+(to->z-from->z)*q->w28/60.0f;
 q->pos.x/=10.0f;q->pos.y/=10.0f;q->pos.z/=10.0f;
}
void func_0c1cd3aa(void) {
 struct Obj_tu5_03 *q;
 if((q=func_0c0374da(0,11,1))!=0) {
 q->b12c=1;q->p16=func_0c1cd404;
 q->l84=((int *)dat_0c2d9680->p0)[4];
 q->pos=table_0c231e84[0];q->lcc=0x811;q->w28=0;q->w30=0;
 q->f80=0.1000000015f;q->f84=0.1000000015f;q->f88=0.1000000015f;
 }
}
void func_0c1cd404(struct Obj_tu5_03 *q) {
 struct Vec3_tu5_03 point;int phase;float height;
 if(dat_0c2d6f84->b2!=5) {func_0c037688(q);return;}
 if(q->w28!=60) {q->w28++;func_0c1cd330(q);return;}
 q->w30+=20;if(q->w30>=360)q->w30=0;
 func_0c1d8ff8(((void **)dat_0c2d9680->p0)[5],(void *)q->l84);
 phase=0;
 while(!func_0c1d901e()) {
 func_0c1d9100(&point);height=point.y;
 point.z+=height*height*func_0c1ec2c0((int)((q->w30+phase)*65536.0f/360.0f+0.5f)&65535)*0.02f;
 phase+=20;func_0c1d914c(&point);
 }
}
