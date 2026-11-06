/* Bounce on the owner's ground plane, then blink until the effect expires. */
#include "objects.h"
extern void func_0c029fc4(struct LinkedActor *),func_0c19ee84(struct LinkedActor *);
extern void (*table_0c258a3c[])(struct LinkedActor *);
void func_0c19d70c(struct LinkedActor *a){
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56>((struct Actor *)a->p24)->f41c)return;
 a->b5++;a->f56=((struct Actor *)a->p24)->f41c;a->f96=-(a->f96/2.0f);a->s28=48;
}
void func_0c19d778(struct LinkedActor *a){
 func_0c029fc4(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(--a->s28){
 a->sdc.b12c=(a->s28&4)?1:0;
 if(a->f56>((struct Actor *)a->p24)->f41c)return;
 a->f56=((struct Actor *)a->p24)->f41c;a->f96=-(a->f96/2.0f);
 return;
 }
 func_0c19ee84(a);
}
void func_0c19d812(struct LinkedActor *a){table_0c258a3c[a->b4](a);}
