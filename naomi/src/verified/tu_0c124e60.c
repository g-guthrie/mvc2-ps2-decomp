/* Spawn check, empty predicate, factory dispatch and a hit reaction that pulls the partner. */
#include "objects.h"
typedef struct Actor *(*ActorFactory)(struct Actor *);
extern ActorFactory table_0c24298c[];
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int), func_0c1d4610(struct Actor *, struct LinkedActorVec3 *), func_0c048ce6(struct Actor *);
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c23f41c[];
extern ActorFactory table_0c24d730[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043014(struct Actor *, struct LinkedActorVec3 *);
void func_0c0547dc(struct Actor *a);
extern ActorHandler table_0c23f400[];
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);

struct Actor *func_0c124e60(struct Actor *a)
{
 struct Actor *result;
 if ((a->b34 = (a->w1fa & 0x0c00) >> 10) && !a->b1fe && (unsigned char)a->b1a3 == 1) {
  if ((result = func_0c037d54(a)) != 0) { a->b1f7=3; return result; }
 }
 return 0;
}

int func_0c124eb4(void) { return 0; }

struct Actor *func_0c124eb8(struct Actor *a)
{
    return table_0c24d730[a->b1f9](a);
}

extern void func_0c0426c2(struct Actor *, int), func_0c0427be(struct Actor *, int);
void func_0c124ed0(struct Actor *a)
{
    struct LinkedActorVec3 v;

    if (a->b34 & 1) {
        a->b1d2 ^= 1;
        a->w130 = a->b1d2;
    }
    a->b1a0 = 10;
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 0);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    v.x = -85.0f;
    v.y = 53.57143f;
    v.z = 0;
    func_0c1d4610(a, &v);
    func_0c0426c2(a->p1c8, 16);
    func_0c0427be(a, 1);
    a->s28 = 48;
    func_0c02a026(a);
    a->p1c8->f56 = a->p1c8->f41c;
}
