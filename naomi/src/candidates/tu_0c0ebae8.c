/* Three functions and all pool bytes match. func_0c0ebbc6 retains
 * a different ordering and allocation of zero stores and child loads. */
#include "objects.h"
struct Vec3_0c05ec28 { float x, y, z; };
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c23fd60[];
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct Vec3_0c05ec28 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern ActorHandler table_0c249c18[];
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0426c2(struct Actor *, int);
extern void func_0c0427be(struct Actor *, int);

void func_0c0ebae8(struct Actor *a)
{
    struct Vec3_0c05ec28 v;
    if (!(a->b34 & 2)) {
        a->b1d2 ^= 1;
        a->w130 = (unsigned char)a->b1d2;
    }
    func_0c025900(a, 5, 5);
    v.x = -106.666664124f;
    v.y = 188.57143f;
    func_0c1d4610(a, &v);
    a->b1a0 = 10;
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 5);
}

void func_0c0ebb4a(struct Actor *a)
{
    struct Vec3_0c05ec28 v;
    func_0c025900(a, 5, 5);
    func_0c048ce6(a);
    v.x = -90.0f;
    v.y = 162.857132f;
    func_0c1d4610(a, &v);
    a->b1a0 = 10;
    a->s28 = 136;
    a->s30 = 0;
    func_0c0426c2(a->p1c8, 20);
    func_0c0427be(a, 3);
    func_0c02a0c4(a, 15, 0);
}

void func_0c0ebba8(struct Actor *a)
{
    a->b1ea = 1;
    table_0c249c18[a->b1f7 & 63](a);
}

void func_0c0ebbc6(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b1d2 ^= 1;
        func_0c0437b8(a);
    }
    if (a->b141) {
        struct Actor *child = a->p1c8;
        a->b141 = 0;
        child->p1b4 = a;
        child->b1f6 = 1;
        child->b1f9 = 0;
        func_0c025900(a, 0, 0);
        child->b1a1 = 33;
        child->b1d2 = a->b1d2;
    }
}
