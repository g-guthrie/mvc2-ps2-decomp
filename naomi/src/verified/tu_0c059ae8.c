#include "objects.h"

struct Vec3_0c059ae8 { float x, y, z; };
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c23f914[];
extern ActorHandler table_0c23f91c[];
extern ActorHandler table_0c23fd60[];
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c056bb8(struct Actor *);
extern void func_0c04b5cc(struct Actor *, int, int, int);
extern void func_0c0429a4(struct Actor *, struct Vec3_0c059ae8 *, int);

void func_0c059ae8(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c059b0a(struct Actor *a) { table_0c23f914[a->b6](a); }
void func_0c059b1c(struct Actor *a)
{
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 21, 7);
}
void func_0c059b3c(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c059b5e(struct Actor *a) { table_0c23f91c[a->b6](a); }
void func_0c059b70(struct Actor *a)
{
    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6++;
    func_0c056bb8(a);
    func_0c02a0c4(a, 15, 53);
    func_0c04b5cc(a, 10, 60, 60);
}
void func_0c059bb2(struct Actor *a)
{
    struct Vec3_0c059ae8 v;
    a->w3e4 = 2;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    if (func_0c02a026(a) < 0) {
        a->b3f0 = 0;
        a->b3f1 = 0;
        a->b6++;
        v.x = -40.0f;
        v.y = 154.28571f;
        func_0c0429a4(a, &v, 3);
        func_0c02a0c4(a, 15, 55);
    }
}
