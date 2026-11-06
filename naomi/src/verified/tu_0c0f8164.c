#include "objects.h"

extern void func_0c03efea(struct Actor *, struct Actor *);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c045248(struct Actor *, int);

void func_0c0f8164(struct Actor *a)
{
    if (a->p1c8->b14b)
        func_0c03efea(a->p1c8, a);
    else
        func_0c03edcc(a->p1c8, a);
}

void func_0c0f818c(struct Actor *a)
{
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 5;
    func_0c045248(a, 29);
}

void func_0c0f81a0(struct Actor *a)
{
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 5;
    func_0c045248(a, 29);
}

void func_0c0f81b4(struct Actor *a)
{
    char z;
    int one;

    z = 0;
    a->b5 = z;
    one = 1;
    a->b7 = z;
    a->b6 = z;
    a->b1a3 = one;
    switch (a->b4c9) {
    case 0:
        a->b1e9 = one;
        break;
    case 1:
        a->b1e9 = 3;
        a->b1a3 = 0;
        break;
    case 2:
        a->b1e9 = 15;
        break;
    }
    func_0c045248(a, 21);
}

void func_0c0f81f8(struct Actor *a)
{
    char z;
    int one;

    z = 0;
    a->b5 = z;
    one = 1;
    a->b7 = z;
    a->b6 = z;
    a->b1a3 = one;
    switch (a->b4c9) {
    case 0:
        a->b1e9 = one;
        break;
    case 1:
        a->b1e9 = 3;
        a->b1a3 = 0;
        break;
    case 2:
        a->b1e9 = 15;
        break;
    }
    func_0c045248(a, 21);
}
