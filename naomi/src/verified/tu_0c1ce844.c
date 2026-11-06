/* Exact 0x0c1ce844..0x0c1ce8c4: allocate and place a ground-aligned effect with unit horizontal and vertical scale. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c1ce692(struct LinkedActor *);
void func_0c1ce844(struct Actor *source)
{
 struct LinkedActor *q;float stopped,one;
 if((q=func_0c0374da(0,7,1))!=0){
 stopped=0.0f;q->sdc.b12c=1;q->p16=func_0c1ce692;q->wcc.dword_value=17;
 q->f52=source->f52;q->f56=source->f56;q->f60=stopped;
 q->f52+=source->w130?-32:32;
 q->f56=source->f41c;one=1.0f;q->v80.x=one;q->v80.y=one;q->v80.z=stopped;
 }
}
