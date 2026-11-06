/* Three actor state handlers sharing one literal pool. */
#include "objects.h"
extern void func_0c025900(struct Actor*,int,int);
extern void func_0c02a0c4(struct Actor*,int,int);
extern void func_0c048ce6(struct Actor*);
extern void func_0c1d4610(struct Actor*,void*);
extern void (*table_0c23f440[])(struct Actor *);
void func_0c0549e0(struct Actor *a);
void func_0c054a52(struct Actor *a);
void func_0c054ae2(struct Actor *a);

void func_0c0549e0(struct Actor *a)
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
    func_0c02a0c4(a,15,1);
}

void func_0c054a52(struct Actor *a)
{
    struct Vec3_tu5_03 pos;
    a->b1d2 ^= 1;
    a->w130 = a->b1d2;
    if (!(a->b34 & 2)) {
        a->b1d2 ^= 1;
        a->w130 = a->b1d2;
    }
    func_0c025900(a, 5, 5);
    pos.x = -83.33333f;
    pos.y = 158.57143f;
    func_0c1d4610(a, &pos);
    a->b1a0 = 10;
    a->f92 = 0;
    a->f104 = 0;
    a->f96 /= 2.0f;
    a->f108 = -0.80357140303f;
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 2);
}

void func_0c054ae2(struct Actor *a)
{
    a->b1ea = 1;
    table_0c23f440[a->b1f7 & 63](a);
}
