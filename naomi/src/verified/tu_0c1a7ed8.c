/* Fourteen-function effect family at 0x0c1a7ed8 (exact). */
#include "objects.h"
extern void func_0c029e70(struct LinkedActor *,int,int),func_0c029f0e(struct Actor *,unsigned char,unsigned char,int),func_0c1a7372(struct LinkedActor *);
extern char func_0c029fc4(struct LinkedActor *);
extern struct LinkedActor *func_0c0374da(int,int,int);
extern short dat_0c2592d8[][2];
extern struct FollowOffset15e2 dat_0c259254[];
extern void (*table_0c2593d8[])(struct LinkedActor *,struct LinkedActor *),(*table_0c2593e0[])(struct LinkedActor *,struct LinkedActor *),(*table_0c2593e8[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1a7f1c(struct LinkedActor *,struct LinkedActor *);
void func_0c1a7fe4(struct LinkedActor *);
void func_0c1a80b4(struct LinkedActor *,struct LinkedActor *);
void func_0c1a8162(struct LinkedActor *);
void func_0c1a7ed8(struct LinkedActor *a,struct LinkedActor *owner){
 struct LinkedActor *parent=a->p20;
 a->b5++;a->sdc.b12c=1;((struct Actor *)a)->f264=1.0f;a->s28=5;
 a->b49=parent->b49-1;func_0c029e70(a,27,((struct Actor *)parent)->b158);func_0c1a7f1c(a,owner);
}
void func_0c1a7f1c(struct LinkedActor *a,struct LinkedActor *owner){if(--a->s28==0){a->b5++;a->s28=10;}}
void func_0c1a7f36(struct LinkedActor *a){((struct Actor *)a)->f264-=0.100000002;if(((struct Actor *)a)->f264<=0){a->b4++;a->sdc.b12c=0;}}
void func_0c1a7f5c(struct LinkedActor *a,struct LinkedActor *owner){table_0c2593d8[(unsigned char)a->b5](a,owner);}
void func_0c1a7f6e(struct LinkedActor *a,struct LinkedActor *owner){
 a->b5++;a->sdc.b12c=1;((struct Actor *)a)->f264=1.0f;
 if(a->sdc.w130==0)a->f52=owner->f52+(float)dat_0c2592d8[a->b35][0]*1.66666663f;
 else a->f52=owner->f52-dat_0c2592d8[a->b35][0]*1.66666663f;
 a->f56=owner->f56+dat_0c2592d8[a->b35][1]*2.1428571f;
 func_0c1a7fe4(a);
}
void func_0c1a7fe4(struct LinkedActor *a){if(func_0c029fc4(a)<0){a->b4++;a->sdc.b12c=0;}}
void func_0c1a8006(struct LinkedActor *a,struct LinkedActor *owner){
 if((signed char)((struct Actor *)owner)->b140!=1 || owner->b1d0!=22){a->b4++;a->sdc.b12c=0;return;}
 a->sdc.w130=owner->sdc.w130;a->f52=owner->f52;a->f56=owner->f56;
}
void func_0c1a8066(struct LinkedActor *a,struct LinkedActor *owner){table_0c2593e0[(unsigned char)a->b5](a,owner);}
void func_0c1a8078(struct LinkedActor *a,struct LinkedActor *owner){
 struct LinkedActor *child;
 a->b5++;((struct Actor *)a)->i72=0x2600;
 if((child=func_0c0374da((int)a,3,2))){child->p16=func_0c1a7372;child->p24=a;child->b32=18;}
 func_0c1a80b4(a,owner);
}
void func_0c1a80b4(struct LinkedActor *a,struct LinkedActor *owner){if(func_0c029fc4(a)<0){a->b4++;a->sdc.b12c=0;}}
void func_0c1a80d6(struct LinkedActor *a,struct LinkedActor *owner){
 struct FollowOffset15e2 *entry;
 if(owner->b4>=2){a->b4++;a->sdc.b12c=0;return;}
 if((signed char)(a->sdc.b12c=owner->sdc.b141)){
 ((struct Actor *)a)->i72=((struct Actor *)owner)->i72;
 entry=&dat_0c259254[a->b32];
 func_0c029f0e((struct Actor *)a,27,entry->metadata[1],(signed char)((struct Actor *)owner)->b140);
 }
}
void func_0c1a8138(struct LinkedActor *a,struct LinkedActor *owner){table_0c2593e8[(unsigned char)a->b5](a,owner);}
void func_0c1a814a(struct LinkedActor *a,struct LinkedActor *owner){a->b5++;a->f56=((struct Actor *)owner->p24)->f41c;a->v80.y=1.5f;func_0c1a8162(a);}
void func_0c1a8162(struct LinkedActor *a){if(func_0c029fc4(a)<0){a->b4++;a->sdc.b12c=0;}}
