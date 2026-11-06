/* State-driven scale transitions and parent display synchronization. */
#include "objects.h"
extern void func_0c1c7ac4(struct LinkedActor *,int);
extern void func_0c1c7dcc(struct LinkedActor *),func_0c1c8ee0(struct LinkedActor *),func_0c037688(struct LinkedActor *);
extern void (*table_0c25e8dc[])(struct LinkedActor *);
void func_0c1c7494(struct LinkedActor *a){
 switch((unsigned char)a->b5){
 case 0:a->b5++;func_0c1c7ac4(a,0);func_0c1c7dcc(a);func_0c1c8ee0(a);
 case 1:a->v80.y+=0.1000000015f;if(!(a->v80.y<1.0f)){a->b5++;a->v80.y=1.0f;}break;
 case 2:break;
 }
}
void func_0c1c74ec(struct LinkedActor *a){
 ((struct Actor *)a)->i72=((struct Actor *)a->p24)->i72;
 switch(a->b6){
 case 0:if((signed char)((struct Actor *)a->p20)->b4c9==(unsigned char)a->b33)a->b6=1;else a->b6=2;break;
 case 1:a->v80.y+=0.1000000015f;if(!(a->v80.y<1.0f)){a->b6=99;a->v80.y=1.0f;}break;
 case 2:a->v80.y-=0.1000000015f;if(!(a->v80.y>0.0f)){a->b6=99;a->v80.y=0.01f;}break;
 case 99:break;
 }
}
void func_0c1c7568(struct LinkedActor *a){func_0c037688(a);}
void func_0c1c756e(struct LinkedActor *a){table_0c25e8dc[a->p24->b4](a);}
