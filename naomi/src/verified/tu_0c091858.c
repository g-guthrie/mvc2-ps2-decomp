#include "objects.h"
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void (*table_0c242c2c[])(struct Actor *);
extern void (*table_0c242c40[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c04b02a(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c025762(void);
extern void func_0c0437b8(struct Actor *);
extern void *func_0c1982f4(struct Actor *, struct Actor *, int);
void func_0c091858(struct Actor *a)
{
    struct LinkedActorVec3 position;
    func_0c025900(a, 5, 5);
    if (a->w1fa & 0x400) {
        a->w130 ^= 1;
        a->b1d2 ^= 1;
    }
    position.x = -173.33333f;
    position.y = 222.857132f;
    func_0c1d4610(a, &position);
    func_0c048ce6(a);
    a->b1a0 = 10;
    a->b7 = a->b6 = 0;
    func_0c02a0c4(a, 15, 2);
}
void func_0c0918c0(struct Actor *a)
{
    a->b1ea = 1;
    table_0c242c2c[a->b1f7 & 63](a);
}
void func_0c0918de(struct Actor *a)
{
    table_0c242c40[a->b6](a);
}
void func_0c091908(struct Actor *a);
void func_0c0918f0(struct Actor *a)
{
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c091908(a);
}
void func_0c091908(struct Actor *a)
{
    struct Actor *other;
    (void)func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        other = a->p1c8;
        other->p1b4 = a;
        other->b1a1 = 32;
        func_0c04b02a(a);
        if (!other->w420) {
            func_0c0442fa(a);
            other->b1f6 = 1;
            other->b1d2 = a->b1d2 ^ 1;
            other->w130 = a->w130 ^ 1;
            other->b1f9 = 2;
            func_0c025762();
            a->b1ea = 0;
            func_0c0437b8(a);
        } else {
            func_0c1982f4(a, other, 0);
            func_0c1982f4(a, other, 1);
            func_0c025762();
        }
    }
}
