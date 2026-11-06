#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c025762(void);
extern void func_0c1d1622(struct LinkedActorVec3 *, int);
extern void func_0c03489c(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void (*table_0c242c4c[])(struct Actor *);
extern void (*table_0c242c58[])(struct Actor *);
void func_0c091a44(struct Actor *);
void func_0c0919f4(struct Actor *a)
{
    if (func_0c02a026(a) < 0) { func_0c0442fa(a); func_0c0437b8(a); }
}
void func_0c091a1a(struct Actor *a) { table_0c242c4c[a->b6](a); }
void func_0c091a2c(struct Actor *a)
{
    a->b6++;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c091a44(a);
}
void func_0c091a44(struct Actor *a)
{
    struct LinkedActorVec3 position;
    struct Actor *child;
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        child = a->p1c8;
        child->p1b4 = a;
        child->b1f6 = 11;
        child->b1d2 = a->b1d2;
        child->w130 = a->w130;
        child->b1f9 = 2;
        child->b1a1 = 33;
        func_0c025762();
        position.x = child->f52;
        position.y = child->f41c;
        func_0c1d1622(&position, child->b2);
        func_0c03489c(a);
        dat_0c2d9260.b5 = 1;
        dat_0c2d9260.b6 = 1;
    }
}
void func_0c091abe(struct Actor *a)
{
    if (func_0c02a026(a) < 0) { func_0c0442fa(a); func_0c0437b8(a); }
}
void func_0c091ae4(struct Actor *a) { table_0c242c58[a->b6](a); }
