#include "objects.h"

extern unsigned char dat_0c2f8380;
extern void func_0c1d6424(struct Actor *);
extern void func_0c1a82b4(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0344a0(struct Actor *, int);
extern char func_0c02a026(struct Actor *);

void func_0c0b6d98(struct Actor *a)
{
    a->b6 = a->b6 + 1;
    a->b12c = 0;
    a->f264 = 0.0f;
    a->s28 = 140;
    if (dat_0c2f8380 == 8)
        func_0c1d6424(a);
    func_0c1a82b4(a, 0);
    func_0c1a82b4(a, 1);
    func_0c1a82b4(a, 2);
    func_0c1a82b4(a, 3);
    func_0c1a82b4(a, 4);
    func_0c1a82b4(a, 5);
    func_0c1a82b4(a, 6);
    func_0c1a82b4(a, 7);
    func_0c1a82b4(a, 8);
    func_0c1a82b4(a, 9);
    func_0c1a82b4(a, 10);
    func_0c1a82b4(a, 11);
    func_0c1a82b4(a, 12);
    func_0c1a82b4(a, 13);
    func_0c1a82b4(a, 14);
    func_0c1a82b4(a, 15);
    func_0c1a82b4(a, 16);
    func_0c1a82b4(a, 17);
    func_0c1a82b4(a, 18);
    func_0c1a82b4(a, 19);
    func_0c1a82b4(a, 20);
    func_0c1a82b4(a, 21);
    func_0c1a82b4(a, 22);
    func_0c1a82b4(a, 23);
    func_0c1a82b4(a, 24);
    func_0c1a82b4(a, 25);
    func_0c02a0c4(a, 18, 0);
}

void func_0c0b6e74(struct Actor *a)
{
    if (--a->s28 == 0) {
        a->b6 = a->b6 + 1;
        a->b12c = 1;
        func_0c0344a0(a, 4);
    }
}

void func_0c0b6e96(struct Actor *a)
{
    a->f264 += 0.050000001f;
    if (!(1.0f > a->f264)) {
        a->f264 = 1.0f;
        a->b6 = a->b6 + 1;
    }
}


void func_0c0b6eb8(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141)
        a->b6 = a->b6 + 1;
}

void func_0c0b6ed6(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        a->b5++;
}
