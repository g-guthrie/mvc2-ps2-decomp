/* Exact owner graphics copy, mirrored position, animation update, and state dispatch. */
#include "objects.h"
extern void func_0c029e70(struct LinkedActor *,int,int),func_0c19ee84(struct LinkedActor *);
extern char func_0c029fc4(struct LinkedActor *);
extern void (*table_0c258a4c[])(struct LinkedActor *);
void func_0c19d834(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;a->b36=0;
 a->f52=a->p24->f52+(a->sdc.w130?85.0f:-85.0f);
 a->f56=a->p24->f56+165.0f;
 func_0c029e70(a,27,2);
}
void func_0c19d8d2(struct LinkedActor *a){if(func_0c029fc4(a)<0)func_0c19ee84(a);}
void func_0c19d8f4(struct LinkedActor *a){table_0c258a4c[a->b4](a);}
