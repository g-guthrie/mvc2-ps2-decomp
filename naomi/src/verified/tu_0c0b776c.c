#include "objects.h"
struct Pos_0b776c {float x,y,z;};
extern char func_0c02a026(struct Actor *);
extern int func_0c047bbe(struct Actor *);
extern void func_0c0429a4(struct Actor *,struct Pos_0b776c *,int),func_0c158860(struct Actor *,int,float,float),func_0c1a72d4(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *);
extern void (*table_0c245108[])(struct Actor *);
void func_0c0b776c(struct Actor *a){struct Pos_0b776c v;func_0c02a026(a);if(a->b141){a->b6++;a->b141=0;v.x=-53.3333321f;v.y=214.28571f;v.z=0;func_0c0429a4(a,&v,1);}}
void func_0c0b77b2(struct Actor *a){a->b328=5;func_0c02a026(a);if(a->b141){float x,y;a->b141=0;a->b6++;x=93.33333f;y=227.142853f;func_0c158860(a,0,x,y);func_0c1a72d4(a,13);func_0c1a72d4(a,21);}}
void func_0c0b7800(struct Actor *a,char *p){a->b328=5;func_0c02a026(a);if(*p>=0 && func_0c047bbe(a)){(*p)--;a->s28++;}if(--a->s28<=0){a->b6++;func_0c02a0c4(a,21,4);}}
void func_0c0b7860(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0b7882(struct Actor *a){a->b1f5=1;table_0c245108[a->b6](a);}
