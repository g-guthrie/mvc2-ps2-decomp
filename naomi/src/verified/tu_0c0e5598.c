/* Three actor-state functions sharing the 62-byte literal pool at 0x0c0e56a6. */
#include "objects.h"

struct Vec_tu_0c0e5598 { float x, y, z; };
struct Glob_0c2f83f8 { unsigned char pad[0x7c]; short w7c[1]; };
typedef void (*ActorHandler_0c0e5598)(struct Actor *);

extern ActorHandler_0c0e5598 table_0c249600[];
extern struct Glob_0c2f83f8 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct Vec_tu_0c0e5598 *, int);

void func_0c0e5598(struct Actor *a)
{
    table_0c249600[a->b6](a);
}

void func_0c0e55aa(struct Actor *a)
{
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6++;
    a->b1a1 = 64;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->w7c[a->b2]++;
    func_0c0442fa(a);
    a->f56 = a->f41c;
    a->b1f9 = 0;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c0432ca(a);
    func_0c02a39a(a, 0);
    func_0c02a0c4(a, 21, 15);
}

void func_0c0e5636(struct Actor *a)
{
    struct Vec_tu_0c0e5598 v;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        a->b3f0 = 0;
        a->b3f1 = 0;
        v.x = -8.33333302f;
        v.y = 42.85714f;
        v.z = 0.0f;
        func_0c0429a4(a, &v, 1);
    }
}
