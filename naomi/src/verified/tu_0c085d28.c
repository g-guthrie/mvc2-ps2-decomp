#include "objects.h"
extern void (*table_0c2421d4[])(struct Actor *);
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

struct Actor *func_0c085d28(struct Actor *a)
{
 struct Actor *target;
 if(!(a->w1fa&0xc00))goto rejected; if(a->b1f9==1)goto rejected; if(a->b1a3==0)goto rejected;
 if(a->b1fe){
 if(a->b1f9==2)goto rejected;
 if((target=func_0c037d54(a))!=0){a->b1f7=1;return target;}
 goto rejected;
 }else if(a->b1f9==2){
 if((target=func_0c037d54(a))!=0){a->b1f7=2;return target;}
 goto rejected;
 }else{
 if(!(target=func_0c037d54(a)))goto rejected;
 a->b1f7=0;
 }
 return target;
rejected:
 return 0;
}

void func_0c085dae(struct Actor *a)
{
    table_0c2421d4[a->b1f7&63](a);
}

void func_0c085dc6(struct Actor *a)
{
    struct LinkedActorVec3 v;
    if (a->w1fa & 0x800) {
        a->b1d2 = a->b1d2 ^ 1;
        a->w130 = a->w130 ^ 1;
    }
    func_0c025900(a, 5, 5);
    a->b1a0 = 10;
    a->b6 = 0;
    v.x = -53.3333321f;
    v.y = 137.142853f;
    func_0c1d4610(a, &v);
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 0);
}
