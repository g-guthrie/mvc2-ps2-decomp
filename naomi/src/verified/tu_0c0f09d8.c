/* Spawn checks, an empty predicate and a dispatcher that flips the partner facing first. */
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

struct Actor *func_0c0f09d8(struct Actor *a)
{
 struct Actor *result;
 if ((a->b34 = (a->w1fa & 0x0c00) >> 10) && !a->b1fe && (unsigned char)a->b1a3 == 1) {
  if ((result = func_0c037d54(a)) != 0) { a->b1f7=0; return result; }
 }
 return 0;
}

int func_0c0f0a2c(void) { return 0; }

struct Actor *func_0c0f0a30(struct Actor *a)
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

extern ActorHandler table_0c249ffc[];
void func_0c0f0a90(struct Actor *a)
{
    struct Actor *p = a->p1c8;
    p->b1d2 = p->w130 = a->b1d2 ^ 1;
    func_0c048ce6(a);
    table_0c249ffc[a->b1f7 & 63](a);
}
