/* Exact 0x0c1aff4c..0x0c1b0014: allocate three effect variants and dispatch their states. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c25a994[])(struct LinkedActor *);
void func_0c1afff2(struct LinkedActor *);
struct LinkedActor *func_0c1aff4c(struct Actor *source)
{
 struct LinkedActor *q;
 if((q=func_0c0374da(0,3,0))!=0){
 q->p16=func_0c1afff2;q->p24=(struct LinkedActor *)source;q->b1=source->b1;q->b32=0;q->w38=0x1f01;
 q->f52=source->f52;q->f56=source->f56;
 }
 if((q=func_0c0374da(0,3,0))!=0){
 q->p16=func_0c1afff2;q->p24=(struct LinkedActor *)source;q->b1=source->b1;q->b32=1;q->w38=0x1f01;
 q->f52=source->f52;q->f56=source->f56;
 }
 if((q=func_0c0374da(0,3,0))!=0){
 q->p16=func_0c1afff2;q->p24=(struct LinkedActor *)source;q->b1=source->b1;q->b32=2;q->w38=0x1f01;
 q->f52=source->f52;q->f56=source->f56;
 }
 return q;
}
void func_0c1afff2(register struct LinkedActor *q){table_0c25a994[q->b4](q);}
