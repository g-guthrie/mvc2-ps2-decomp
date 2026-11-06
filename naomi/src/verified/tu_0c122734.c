/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern signed char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
typedef void (*Handler_0c0a8698)(struct Actor *);
extern Handler_0c0a8698 table_0c244458[];
void func_0c122796(struct Actor *a);

void func_0c122734(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141)
        return;
    a->b6 = a->b6 + 1;
    a->f92 = 15.83333302f;
    a->f104 = -0.3125f;
    a->f96 = 6.428571224213f;
    a->f108 = -0.5357143f;
    if (a->w130) {
        a->f92 = -a->f92;
        a->f104 = -a->f104;
    }
    a->s28 = 16;
    func_0c122796(a);
}

void func_0c122796(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f41c < a->f56)
        return;
    a->b6 = a->b6 + 1;
    a->f56 = a->f41c;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    a->f92 = 4.16666651f;
    a->f104 = -0.3255208135f;
    if (a->w130) {
        a->f92 = -a->f92;
        a->f104 = -a->f104;
    }
    func_0c02a0c4(a, 2, 3);
}
