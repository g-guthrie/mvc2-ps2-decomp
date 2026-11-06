/* State-driven scale transitions and parent display synchronization. */
#include "objects.h"
extern void func_0c1c7ac4(struct LinkedActor *,int);
extern struct ActorFlags *dat_0c2d6f84;
extern void (*table_0c25e8f4[])(struct LinkedActor *);
void func_0c1c75a0(struct LinkedActor *a){
 switch((unsigned char)a->b5){
 case 0:a->b5++;func_0c1c7ac4(a,1);
 case 1:a->v80.y+=0.1000000015f;if(!(a->v80.y<1.0f)){a->b5++;a->v80.y=1.0f;}break;
 case 2:break;
 }
}
void func_0c1c75ec(struct LinkedActor *a){
 ((struct Actor *)a)->i72=((struct Actor *)a->p24)->i72;
 switch(a->b6){
 case 0:if((signed char)dat_0c2d6f84->pad137[0]==(unsigned char)a->b33)a->b6=1;else a->b6=2;break;
 case 1:a->v80.y+=0.1000000015f;if(!(a->v80.y<1.0f)){a->b6=99;a->v80.y=1.0f;}break;
 case 2:a->v80.y-=0.1000000015f;if(!(a->v80.y>0.0f)){a->b6=99;a->v80.y=0.01f;}break;
 case 99:break;
 }
}
void func_0c1c766a(struct LinkedActor *a){struct LinkedActor *owner=a->p24->p24;table_0c25e8f4[owner->b4](a);}
void func_0c1c7682(struct LinkedActor *a){a->sdc.b12c=a->p24->sdc.b12c;a->v80=a->p24->v80;}
