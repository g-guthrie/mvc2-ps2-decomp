/* Reviewed candidate: 0548c0..0549e0. */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c23f434[];
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c025900(struct Actor *,int,int);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);

struct Actor *func_0c0548c0(struct Actor *a)
{
    struct Actor *child;
    if(!(a->b34=(a->w1fa&0x0c00)>>10))return 0;
    if((unsigned char)a->b1fe!=1)return 0;
    if((unsigned char)a->b1a3!=1)return 0;
    if(!(a->f56>137.142853f))return 0;
    if((child=func_0c037d54(a))) {
        a->b1f7=2;
        return child;
    }
    return 0;
}

void func_0c054922(struct Actor *a)
{
    table_0c23f434[a->b1f7&63](a);
}

void func_0c05493a(struct Actor *a)
{
    struct LinkedActorVec3 position;
    a->b1d2^=1;
    a->w130=a->b1d2;
    if(!(a->b34&2)) {
        a->b1d2^=1;
        a->w130=a->b1d2;
    }
    func_0c025900(a,5,5);
    position.x=-83.33333f;
    position.y=158.57143f;
    func_0c1d4610(a,&position);
    a->b1a0=10;
    func_0c048ce6(a);
    func_0c02a0c4(a,15,0);
}
