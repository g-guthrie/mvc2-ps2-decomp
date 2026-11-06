#include "objects.h"
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c02a026(struct LinkedActor *);
extern void (*table_0c25bd80[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c25bd88[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1bc950(struct LinkedActor *,struct LinkedActor *);
void func_0c1bc810(struct LinkedActor *a,struct LinkedActor *parent) {
 a->b4++;
 a->sdc=parent->sdc; a->sdc.b12c=1;
 a->b2=parent->b2; a->b1=parent->b1;
 a->v80.x=parent->v80.x; a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3; a->b1a4=parent->b1a4;
 a->b48=parent->b48; a->v80=parent->v80;
 a->b36=parent->b36;
 a->sdc.b12c=0; a->b49=1;
 a->f52=parent->f52; a->f56=parent->f56; a->f60=parent->f60;
 a->f92=4.47916667f; a->f96=5.35714286f; a->f104=0.0f; a->f108=0.0f;
 if(a->sdc.w130) a->f92=-a->f92;
 func_0c02a0c4(a,18,2);
 func_0c1bc950(a,parent);
}
void func_0c1bc8ca(struct LinkedActor *a,struct LinkedActor *parent) {
 struct ActorSub2a4 *state=&((struct Actor *)parent)->sub2a4;
 a->f52=parent->f52; a->f56=parent->f56;
 if(state->b7) { a->b5++; a->sdc.b12c=1; a->s28=56; }
}
void func_0c1bc8f4(struct LinkedActor *a) {
 a->f52+=a->f92; a->f92+=a->f104;
 a->f56+=a->f96; a->f96+=a->f108;
 func_0c02a026(a);
 if(--a->s28==0) a->b4++;
}
void func_0c1bc950(struct LinkedActor *a,struct LinkedActor *parent) {
 a->b36=parent->b36;
 table_0c25bd80[(unsigned char)a->b5](a,parent);
}
void func_0c1bc96a(struct LinkedActor *a,struct LinkedActor *parent) { table_0c25bd88[a->b4](a,parent); }
