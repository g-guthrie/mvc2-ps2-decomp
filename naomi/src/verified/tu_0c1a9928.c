#include "objects.h"
extern void func_0c029e70(struct LinkedActor *,int,int);
extern void (*table_0c259674[])(struct LinkedActor *);
void func_0c1a9a46(struct LinkedActor *);
void func_0c1a9928(struct LinkedActor *a) {
 float horizontal;
 a->b4++;
 a->sdc=a->p24->sdc;
 a->sdc.b12c=1;
 a->b2=a->p24->b2; a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x; a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3; a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48; a->v80=a->p24->v80;
 a->b36=a->p24->b36;
 a->b36=0;
 func_0c029e70(a,27,4);
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&a->p24->f52;
 horizontal=-40.0f;
 if(a->sdc.w130) horizontal=40.0f;
 a->f52+=horizontal*a->v80.x;
 a->f56+=a->v80.y*205.7142791748047f;
 *(struct LinkedActorVec3 *)&a->f104=a->v80;
 a->v80.x*=0.400000006f; a->v80.y*=0.400000006f;
 ((struct Actor *)a)->f136=(a->f104*1.5f-a->v80.x)/20.0f;
 ((struct Actor *)a)->f140=(a->f108*1.5f-a->v80.y)/20.0f;
 a->s30=20; a->s28=30;
 ((struct Actor *)a)->i72=0;
 a->s28=240;
 func_0c1a9a46(a);
}
void func_0c1a9a46(struct LinkedActor *a) { table_0c259674[(unsigned char)a->b5](a); }
void func_0c1a9a58(struct LinkedActor *a) {
 a->v80.x+=((struct Actor *)a)->f136;
 a->v80.y+=((struct Actor *)a)->f140;
 ((struct Actor *)a)->f264-=0.04f;
 if(--a->s30<=0) { a->b4++; a->s30=19; }
}
