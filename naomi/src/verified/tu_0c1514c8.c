#include "objects.h"
#define OWNER(a) ((struct Actor *)((struct LinkedActor *)(a))->p24)
#define EFFECT_FLOOR(a) (*(float *)&(a)->pad5ba[0])
extern void (*table_0c25047c[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
void func_0c1514c8(struct Actor *a){struct Actor *owner;table_0c25047c[a->b6](a);owner=OWNER(a);owner->b1ea=1;}
void func_0c1514ea(struct Actor *a)
{
 struct Actor *owner;float offset;
 a->b6++;a->b12c=1;a->f92=-3.3333333f;a->f104=0.013020833023f;
 owner=OWNER(a);a->f52=owner->f52;a->f56=owner->f56;offset=-33.3333321f;
 if(owner->w130){a->f92=3.3333333f;a->f104=-0.013020833023f;offset=33.3333321f;}
 a->f52+=offset;a->f56+=77.142853f;a->f96=10.714285f;a->f108=-0.46875f;func_0c02a0c4(a,22,15);
}
void func_0c151562(struct Actor *a)
{
 struct Actor *owner;
 func_0c02a026(a);a->i72+=0x1200;a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(EFFECT_FLOOR(a)<a->f56)){a->f56=EFFECT_FLOOR(a);a->b6++;a->f92=-3.3333333f;a->f104=0.013020833023f;owner=OWNER(a);
 if(owner->w130){a->f92=3.3333333f;a->f104=-0.013020833023f;}
 a->f96=5.35714245f;a->f108=-0.234375f;}
}
