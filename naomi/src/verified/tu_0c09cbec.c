/* Spawn checks (ground and airborne), an empty predicate and the b1f7 dispatcher. */
#include "objects.h"
typedef struct Actor *(*ActorFactory)(struct Actor *);
extern ActorFactory table_0c24298c[];
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int), func_0c1d4610(struct Actor *, struct LinkedActorVec3 *), func_0c048ce6(struct Actor *);
typedef void (*ActorHandler)(struct Actor *);
extern ActorFactory table_0c240974[];
extern ActorHandler table_0c240984[];
extern char func_0c02a026(struct Actor *);
extern void func_0c0439c4(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c190d1c(struct Actor *, int, int);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c048ce6(struct Actor *);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern ActorHandler table_0c243640[];
extern void func_0c025900(struct Actor *,int,int);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c02a0c4(struct Actor *,int,int);

struct Actor *func_0c09cbec(struct Actor *a)
{
 struct Actor *result;
 if ((a->b34 = (a->w1fa & 0x0c00) >> 10) && !a->b1fe && (unsigned char)a->b1a3 == 1) {
  if ((result = func_0c037d54(a)) != 0) { a->b1f7=0; return result; }
 }
 return 0;
}

int func_0c09cc40(void) { return 0; }

struct Actor *func_0c09cc44(struct Actor *a)
{
    int z;
    struct Actor *q;

    z = 0;
    if (!(a->b34 = (a->w1fa & 0x0c00) >> 10))
        return (struct Actor *)z;
    if (a->b1fe)
        return (struct Actor *)z;
    if ((unsigned char)a->b1a3 != 1)
        return (struct Actor *)z;
    if (a->f56 > 137.142853f) {
        if ((q = func_0c037d54(a)) != 0) {
            a->b1f7 = 1;
            return q;
        }
    }
    return (struct Actor *)z;
}

void func_0c09cca4(struct Actor *a)
{
    table_0c243640[a->b1f7&63](a);
}
