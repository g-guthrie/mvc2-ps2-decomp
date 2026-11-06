/* Spawn checks (ground and airborne), an empty predicate and a facing-flip dispatcher. */
#include "objects.h"
typedef void (*ActorHandler_d0f8)(struct Actor *);
extern ActorHandler_d0f8 table_0c24d0f8[];
typedef void (*ActorHandler)(struct Actor *);
typedef struct Actor *(*ActorFactory)(struct Actor *);
extern ActorHandler table_0c23f41c[];
extern ActorFactory table_0c23f424[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043014(struct Actor *, struct LinkedActorVec3 *);
extern struct Actor *func_0c037d54(struct Actor *);
void func_0c0547dc(struct Actor *a);
extern ActorHandler table_0c23f400[];
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern ActorFactory table_0c24298c[];
extern void func_0c02a0c4(struct Actor *, int, int), func_0c1d4610(struct Actor *, struct LinkedActorVec3 *), func_0c048ce6(struct Actor *);
extern ActorFactory table_0c240974[];
extern ActorHandler table_0c240984[];
extern void func_0c0439c4(struct Actor *);
extern void func_0c190d1c(struct Actor *, int, int);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c048ce6(struct Actor *);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);

struct Actor *func_0c11e274(struct Actor *a)
{
    struct Actor *r;

    if (!(a->b34 = (a->w1fa & 0x0c00) >> 10))
        return 0;
    if (!a->b1fe && (unsigned char)a->b1a3 == 1) {
        if ((r = func_0c037d54(a)) != 0) {
            a->b1f7 = 0;
            return r;
        }
    } else if ((unsigned char)a->b1fe == 1 && (unsigned char)a->b1a3 == 1) {
        if ((r = func_0c037d54(a)) != 0) {
            a->b1f7 = 1;
            return r;
        }
    }
    return 0;
}

int func_0c11e2ec(void) { return 0; }

struct Actor *func_0c11e2f0(struct Actor *a)
{
    struct Actor *t;
    if (!(a->b34 = (a->w1fa & 0x1c00) >> 10))
        return 0;
    if ((unsigned char)a->b1a3 == 1 && a->f56 > 137.142853f) {
        if (!(t = func_0c037d54(a)))
            return 0;
        a->b1f7 = 2;
        return t;
    }
    return 0;
}

void func_0c11e348(struct Actor *a)
{
    struct Actor *p;
    func_0c048ce6(a);
    p = a->p1c8;
    p->b1d2 = p->w130 = a->b1d2 ^ 1;
    table_0c24d0f8[a->b1f7 & 63](a);
}
