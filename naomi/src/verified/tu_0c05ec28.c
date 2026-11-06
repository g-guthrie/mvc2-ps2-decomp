#include "objects.h"

struct Vec3_0c05ec28 { float x, y, z; };
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c23fd60[];
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct Vec3_0c05ec28 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c05ec28(struct Actor *a)
{
    struct Vec3_0c05ec28 v;
    if (!(a->b34 & 2)) {
        a->b1d2 ^= 1;
        a->w130 = (unsigned char)a->b1d2;
    }
    func_0c025900(a, 5, 5);
    v.x = 33.3333320618f;
    v.y = 195.0f;
    func_0c1d4610(a, &v);
    a->b1a0 = 10;
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 1);
}
void func_0c05ec8a(struct Actor *a)
{
    struct Vec3_0c05ec28 v;
    if (!(a->b34 & 2)) {
        a->b1d2 ^= 1;
        a->w130 = (unsigned char)a->b1d2;
    }
    func_0c025900(a, 5, 5);
    v.x = 86.666664124f;
    v.y = 300.0f;
    func_0c1d4610(a, &v);
    a->b1a0 = 10;
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 2);
}
void func_0c05ecec(struct Actor *a)
{
    struct Vec3_0c05ec28 v;
    if (!(a->b34 & 2)) {
        a->b1d2 ^= 1;
        a->w130 = (unsigned char)a->b1d2;
    }
    func_0c025900(a, 5, 5);
    v.x = -80.0f;
    v.y = 184.28571f;
    v.z = 0.0f;
    func_0c1d4610(a, &v);
    a->b1a0 = 10;
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 3);
}
void func_0c05ed54(struct Actor *a)
{
    a->b1ea = 1;
    table_0c23fd60[a->b1f7 & 63](a);
}
