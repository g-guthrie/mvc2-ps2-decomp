/* Actor motion, selection, and animation dispatch handlers. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043324(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern int func_0c03916c(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c244474[])(struct Actor *);
extern void (*table_0c244488[])(struct Actor *);
extern int func_0c043628(struct Actor *);
extern unsigned int func_0c02849a(void);
extern struct Actor *func_0c1a1a34(struct Actor *, int, int);
void func_0c0a8ac8(struct Actor *a)
{
    func_0c02a026(a);
    a->b6++;
    a->f92 = 0;
    a->f104 = 0;
    a->f96 = 10.714285f;
    a->f108 = -0.60267854f;
}
void func_0c0a8af8(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->f56 <= a->f41c) {
        a->b6++;
        a->f56 = a->f41c;
        a->b1f9 = 0;
        func_0c02a0c4(a, 1, 3);
        func_0c043324(a);
        func_0c0344a0(a, 10);
    }
}
void func_0c0a8b7e(struct Actor *a)
{
    if (func_0c02a026(a) < 0) a->b5++;
}
void func_0c0a8b9e(struct Actor *a)
{
    if (func_0c03916c(a)) {
        func_0c02a39a(a, 0);
        func_0c0437b8(a);
    } else table_0c244474[a->b32](a);
}
void func_0c0a8bd2(struct Actor *a) { table_0c244488[a->b6](a); }
void func_0c0a8be4(struct Actor *a)
{
    int kind, variation;
    a->b6 = 1;
    if (func_0c043628(a) >= 2) {
        if (func_0c02849a() & 1) func_0c02a0c4(a, 19, 4);
        else func_0c02a0c4(a, 19, 5);
        return;
    }
    switch (func_0c02849a() & 3) {
    case 0:
        func_0c02a0c4(a, 19, 0);
        variation = 5;
        kind = 19;
        goto spawn;
    case 1:
        func_0c02a0c4(a, 19, 2);
        variation = 10;
        kind = 20;
spawn:
        goto tail;
tail:
        func_0c1a1a34(a, kind, variation);
        return;
    case 2: variation = 4; goto animate;
    case 3: variation = 5;
animate:
        func_0c02a0c4(a, 19, variation);
        return;
    default: return;
    }
}
void func_0c0a8ca8(struct Actor *a) { func_0c02a026(a); }
void func_0c0a8cae(void) { }
void func_0c0a8cb2(void) { }

extern void (*table_0c244498[])(struct Actor *);
void func_0c0a8cb6(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 7);
    } else func_0c02a026(a);
}
void func_0c0a8cd0(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 8);
    } else func_0c02a026(a);
}
void func_0c0a8cea(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 6);
    } else func_0c02a026(a);
}
void func_0c0a8d04(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 8);
    } else func_0c02a026(a);
}
void func_0c0a8d1e(struct Actor *a) { table_0c244498[a->b1e9](a); }
