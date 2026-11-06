/* Landing/bounce handlers for a falling body: lands on the floor at f41c,
 * clears velocity, and integrates position while airborne. */
#include "objects.h"
extern void func_0c09e43a(struct Actor *), func_0c09e45e(struct Actor *), func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int), func_0c043324(struct Actor *), func_0c0437b8(struct Actor *);
extern char func_0c02a026(struct Actor *);
void func_0c0a16f8(struct Actor *a)
{
    func_0c09e43a(a);
    if (a->b1f9 != 2) {
        if (a->b143 < 0) {
            a->b6 = 4;
            func_0c02a39a(a, 0);
            func_0c02a0c4(a, 22, 3);
            return;
        }
    } else if (a->b143 < 0) {
        a->b6++;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        a->f108 = -0.80357140303f;
        func_0c02a39a(a, 0);
        func_0c02a0c4(a, 22, 4);
        return;
    }
    func_0c02a026(a);
    func_0c02a39a(a, 0);
    if (a->b141 == 3)
        func_0c02a39a(a, 4);
}
void func_0c0a1786(struct Actor *a)
{
    func_0c09e45e(a);
    if (a->f56 < a->f41c) {
        a->b6++;
        a->b1f9 = 0;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        a->f56 = a->f41c;
        func_0c043324(a);
        func_0c02a0c4(a, 22, 5);
    }
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
}
void func_0c0a1816(struct Actor *a)
{
    func_0c09e45e(a);
    if (func_0c02a026(a) < 0) func_0c0437b8(a);
}
