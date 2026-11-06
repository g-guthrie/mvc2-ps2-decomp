#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c25768c[])(struct LinkedActor *);
extern struct ActorFlags *dat_0c2d6f84;
extern void func_0c037688(struct LinkedActor *);
void func_0c190d5c(struct LinkedActor *),func_0c190de8(struct LinkedActor *),func_0c190e36(struct LinkedActor *),func_0c190e40(struct LinkedActor *);
struct LinkedActor *func_0c190d1c(struct LinkedActor *parent,unsigned char mode,short timer)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))){a->p16=func_0c190d5c;a->p24=parent;a->b33=mode;a->s28=timer;a->w38=0x0502;}
 return a;
}
void func_0c190d5c(struct LinkedActor *a){table_0c25768c[a->b4](a);}
void func_0c190d6e(struct LinkedActor *a)
{
 struct LinkedActor *parent;
 parent=a->p24;a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;a->b36=7;a->f52=parent->f52;a->f56=parent->f56;
 func_0c190de8(a);
}
void func_0c190de8(struct LinkedActor *a)
{
 struct Actor *parent=(struct Actor *)a->p24;int visible=1;
 if(parent->b3==0){if(parent->b19f)goto destroy;if(parent->b1a0){a->sdc.b12c=visible;return;}}
 if(--a->s28!=0)goto kept;
destroy:func_0c190e36(a);return;
kept:a->sdc.b12c=visible;if(a->b33)a->sdc.b12c=dat_0c2d6f84->flags&1;goto done;
done:;
}
void func_0c190e36(struct LinkedActor *a){a->b4=3;a->sdc.b12c=0;func_0c190e40(a);}
void func_0c190e40(struct LinkedActor *a){func_0c037688(a);}
