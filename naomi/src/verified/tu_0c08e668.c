/* Spawn check, factory dispatch and the two hit-reaction setups that snap
 * the effect offset after a state-15 animation. */
#include "objects.h"
typedef struct Actor *(*ActorFactory)(struct Actor *);
extern ActorFactory table_0c24298c[];
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int), func_0c1d4610(struct Actor *, struct LinkedActorVec3 *), func_0c048ce6(struct Actor *);
struct Actor *func_0c08e668(struct Actor *a)
{
 struct Actor *result;
 if ((a->b34 = (a->w1fa & 0x0c00) >> 10) && !a->b1fe && (unsigned char)a->b1a3 == 1) {
  if ((result = func_0c037d54(a)) != 0) { a->b1f7=1; return result; }
 }
 return 0;
}

struct Actor *func_0c08e6bc(struct Actor *a)
{
    return table_0c24298c[a->b1f9](a);
}

void func_0c08e6d4(struct Actor *a)
{
    struct LinkedActorVec3 v;

    if (a->b34 & 2) {
        a->b1d2 ^= 1;
        a->w130 = a->b1d2;
    }
    a->b1a0 = 10;
    func_0c02a0c4(a, 15, 0);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    v.x = -238.33333f;
    v.y = 169.28571f;
    v.z = 0;
    func_0c1d4610(a, &v);
    func_0c048ce6(a);
}

void func_0c08e742(struct Actor *a)
{
    struct LinkedActorVec3 v;

    func_0c02a0c4(a, 15, 1);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    v.x = -148.33333f;
    v.y = 267.85715f;
    v.z = 0;
    func_0c1d4610(a, &v);
    func_0c048ce6(a);
}
