#include "objects.h"
extern signed char func_0c029fc4(struct LinkedActor *);
extern void func_0c029e70(struct LinkedActor *,int,int);
extern struct ActorFlags *dat_0c2d6f84;
void func_0c1afc00(struct LinkedActor *a) {
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c029fc4(a)<0)a->b4=2;
}
void func_0c1afc54(struct LinkedActor *a) {
 struct Actor *parent=(struct Actor *)a->p24;
 if(!a->b5) {
 if(parent->b1d0!=29||parent->b1e9!=1||--a->s28<0) {
 a->b5++;func_0c029e70(a,27,42);
 }
 func_0c029fc4(a);
 }else if(func_0c029fc4(a)<0)a->b4=2;
}
void func_0c1afcb2(struct LinkedActor *a) {
 struct Actor *parent=(struct Actor *)a->p24;
 if(parent->b1d0!=29||parent->b1e9!=1){a->b4=2;return;}
 func_0c029fc4(a);
 if(!a->b34--) {
 a->b34=0;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(--a->s28<0){a->b4=2;return;}
 if(!a->s30--){a->sdc.b12c=dat_0c2d6f84->flags&1;a->s30=0;}
 }
}
void func_0c1afd6c(struct LinkedActor *a) {
 struct Actor *parent=(struct Actor *)a->p24;
 if(parent->b1d0!=29||parent->b1e9!=1){a->b4=2;return;}
 func_0c029fc4(a);
 if(!a->b5) {
 if(!a->b34--) {
 a->b5++;a->b49=-8;a->f52=140.0f;a->f56=516.428527833f;
 if(parent->w130)a->f52=-a->f52;
 a->f52+=parent->f52;a->f56+=parent->f56;
 }
 }else {
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(--a->s28<0){a->b4=2;return;}
 if(!a->s30--){a->sdc.b12c=dat_0c2d6f84->flags&1;a->s30=0;}
 }
}
