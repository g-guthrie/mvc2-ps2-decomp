/* Exact 0x0c1c6760..0x0c1c683c: allocate a selection-linked effect and select its owner-specific resource. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern unsigned char dat_0c2fb15a[];
extern char dat_0c25e274[][3];
extern struct ActorGlobalRoot *dat_0c2d9658;
void func_0c1c67b6(struct LinkedActor *);
void func_0c1c6760(struct LinkedActor *source)
{
 struct LinkedActor *q;float stopped;
 if((q=func_0c0374da(0,5,1))!=0){q->sdc.b12c=0;q->p16=func_0c1c67b6;
 q->p24=source;*(float **)&q->pad9b[0xc8-0x88]=&((struct Actor *)source)->f136;
 q->p20=source->p20;q->b32=source->b32;q->b33=source->b33;
 stopped=0.0f;q->f52=stopped;q->f56=stopped;q->f60=1.0f;q->wcc.dword_value=0x0801;}
}
void func_0c1c67b6(struct LinkedActor *q)
{
 switch(q->b4){case 0:
 if(dat_0c2fb15a[q->b32]&(16<<(unsigned char)q->b33)){
 struct Actor *owner=(struct Actor *)q->p20;
 q->b4++;q->sdc.b12c=1;
 q->p84=((void **)dat_0c2d9658->p0)[dat_0c25e274[q->b32][owner->b4c9]];
 }break;case 1:break;}
}
