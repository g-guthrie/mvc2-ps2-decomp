/* Table-driven offset/velocity initialization and owner-animation lifetime. */
#include "objects.h"
extern short dat_0c25bd08[][2];
extern signed char dat_0c25bd30[];
extern void (*table_0c25be08[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
void func_0c1bd236(struct LinkedActor *,struct LinkedActor *);
void func_0c1bd13c(struct LinkedActor *a,struct LinkedActor *owner){
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=1;a->b49=-1;
 a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 a->f92=((short *)dat_0c25bd08)[(unsigned char)a->b33*2]*1.66666663f;
 a->f56+=(((short *)dat_0c25bd08)+(unsigned char)a->b33*2)[1]*2.1428571f;
 if(a->sdc.w130)a->f92=-a->f92;
 a->f52+=a->f92;func_0c02a0c4(a,23,dat_0c25bd30[(unsigned char)a->b33]);func_0c1bd236(a,owner);
}
void func_0c1bd236(struct LinkedActor *a,struct LinkedActor *owner){
 short *frame=&a->wcc.short_value;
 a->b36=owner->b36;
 if(owner->sdc.w158.short_value!=*frame)goto advance;
 if(func_0c02a026(a)<0){a->sdc.b12c=0;advance:a->b4++;}
}
void func_0c1bd26e(struct LinkedActor *a){table_0c25be08[a->b4](a);}
