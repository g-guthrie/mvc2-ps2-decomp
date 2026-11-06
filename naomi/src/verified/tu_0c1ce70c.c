#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern void func_0c1ce692(struct Obj_tu5_03 *);
void func_0c1ce70c(struct Actor *owner,unsigned char x,unsigned char y,float scale_x,float scale_y)
{
 struct Obj_tu5_03 *q;
 if((q=func_0c0374da(0,7,1))){
 q->b12c=1;q->p16=func_0c1ce692;q->lcc=17;
 q->pos.x=owner->f52;q->pos.y=owner->f56;q->pos.z=0.0f;
 q->pos.x+=owner->w130?x:-x;
 q->pos.y+=y;
 q->f80=scale_x;q->f84=scale_y;q->f88=0.0f;
 }
}
void func_0c1ce7ae(struct Actor *owner,struct ActorVec2 *offset,float scale_x,float scale_y)
{
 struct Obj_tu5_03 *q;
 if((q=func_0c0374da(0,7,1))){
 q->b12c=1;q->p16=func_0c1ce692;q->lcc=17;
 q->pos.x=owner->f52;q->pos.y=owner->f56;q->pos.z=0.0f;
 q->pos.x+=owner->w130?offset->x:-offset->x;
 q->pos.y+=offset->y;
 q->f80=scale_x;q->f84=scale_y;q->f88=0.0f;
 }
}
