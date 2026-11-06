#include "objects.h"
struct Pos_0d6814 {float x,y,z;};
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c04b02a(struct Actor *),func_0c1cea66(struct Actor *,struct Pos_0d6814 *,int),func_0c0346da(struct Actor *,int),func_0c025900(struct Actor *,int,int);
extern void (*table_0c2487e0[])(struct Actor *);
void func_0c0d6814(struct Actor *a){if(func_0c02a026(a)>=0)return;a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);}
void func_0c0d6846(struct Actor *a){table_0c2487e0[a->b6](a);}
void func_0c0d6858(struct Actor *a){struct Pos_0d6814 v;func_0c02a026(a);if(a->b141>0){struct Actor *child;a->b141=0;child=a->p1c8;child->b1a1=38;func_0c04b02a(a);v.x=0;v.y=-6.428571224213f;v.z=0;func_0c1cea66(a,&v,1);func_0c0346da(a,15);}if(a->b141<0){a->b6++;a->b141=0;func_0c025900(a,0,0);a->f52+=a->b1d2?166.66666f:-166.66666f;a->f56=a->f41c;}}
void func_0c0d68f4(struct Actor *a){struct Actor *child;func_0c02a026(a);if(a->b141){a->b6++;child=a->p1c8;child->p1b4=a;child->b1f6=1;child->b1a1=37;func_0c025900(a,0,0);}}
