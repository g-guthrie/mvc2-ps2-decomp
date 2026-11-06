/* Ten-function effect lifecycle. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c029e70(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
extern char func_0c029fc4(struct LinkedActor *);
extern void (*table_0c258fc8[])(struct LinkedActor *);
extern void (*table_0c258fd8[])(struct LinkedActor *,struct LinkedActor *);
extern short dat_0c258fe8[];
void func_0c1a393e(struct LinkedActor *);
struct LinkedActor *func_0c1a390c(struct LinkedActor *owner){
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))){a->p16=func_0c1a393e;a->p24=owner;a->b1=owner->b1;a->w38=0x1502;}return a;
}
void func_0c1a393e(struct LinkedActor *a){table_0c258fc8[a->b4](a);}
void func_0c1a3950(struct LinkedActor *a){
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;a->b36=0;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&a->p24->f52;
 func_0c029e70(a,27,3);
}
void func_0c1a39d2(struct LinkedActor *a){
 struct LinkedActor *owner=a->p24;
 if(owner->b5 || owner->b1d0!=29)a->b4=2;
 else table_0c258fd8[(unsigned char)a->b5](a,owner);
}
void func_0c1a3a02(struct LinkedActor *a,struct LinkedActor *owner){
 func_0c029fc4(a);
 if(((struct Actor *)owner)->pad6d[2]){
 if(((struct Actor *)owner)->pad6d[2]==4){a->b5++;a->f96=34.2857132f;a->f108=0.2678571343422f;}
 else a->f56=owner->f56+dat_0c258fe8[((struct Actor *)owner)->pad6d[2]]*2.1428571f/256.0f;
 }
}
void func_0c1a3a98(struct LinkedActor *a){
 func_0c029fc4(a);a->f56+=a->f96;a->f96+=a->f108;
 if(1131.4286f<a->f56){a->b5++;a->sdc.b12c=0;}
}
void func_0c1a3adc(struct LinkedActor *a,struct LinkedActor *owner){
 if(owner->b6==2){
 a->b5++;a->sdc.b12c=1;a->s28=21;a->f108=-1.07142854f;
 a->f96=(owner->f56-a->f56)/21.0f-a->f108*21.0f/2.0f;
 }
}
void func_0c1a3b20(struct LinkedActor *a){
 func_0c029fc4(a);a->f56+=a->f96;a->f96+=a->f108;
 a->s28--;if(a->s28<=0)a->b4++;
}
void func_0c1a3b5e(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;}
void func_0c1a3b6c(struct LinkedActor *a){func_0c037688(a);}
