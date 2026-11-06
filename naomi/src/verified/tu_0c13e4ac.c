/* Exact 0x0c13e4ac..0x0c13e550: allocate an effect child, cache the parent frame, and apply mirrored offsets. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c24f4c8[])(struct LinkedActor *);
void func_0c13e524(struct LinkedActor *);
struct LinkedActor *func_0c13e4ac(struct Actor *parent,float dx,float dy,char variant)
{
 struct LinkedActor *q;
 if((q=func_0c0374da(0,1,0))!=0){
 q->p16=func_0c13e524;q->p24=(struct LinkedActor *)parent;q->b1=parent->b1;q->w38=0x0a00;
 q->wcc.short_value=*(short *)&parent->b158;
 if(parent->w130)dx=-dx;
 q->f52=parent->f52+dx*1.66666663f;
 q->f56=parent->f56+dy*2.1428571f;
 q->b33=variant;
 }
 return q;
}
void func_0c13e524(struct LinkedActor *q){table_0c24f4c8[q->b4](q);}
