#include "objects.h"
extern void func_0c045248(struct Actor *, int);

void func_0c0d9ee4(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 2; break;
    case 1: a->b1e9 = 3; break;
    case 2: a->b1e9 = 2; break;
    }
    func_0c045248(a, 29);
}

void func_0c0d9f14(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 2; break;
    case 1: a->b1e9 = 3; break;
    case 2: a->b1e9 = 2; break;
    }
    func_0c045248(a, 29);
}

void func_0c0d9f44(struct Actor *a)
{
    a->b5 = 0; a->b7 = 0; a->b6 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 0; goto common;
    case 1: a->b1e9 = 1; goto common;
    case 2: ((volatile unsigned char *)a)[0x1e9] = 0; goto common;
    default: goto done;
    }
common:
    ((char *)a)[0x1a3] = 1;
done:
    func_0c045248(a, 21);
}

void func_0c0d9f80(struct Actor *a)
{
    a->b5 = 0; a->b7 = 0; a->b6 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 0; goto common;
    case 1: a->b1e9 = 1; goto common;
    case 2: ((volatile unsigned char *)a)[0x1e9] = 1; goto common;
    default: goto done;
    }
common:
    ((char *)a)[0x1a3] = 1;
done:
    func_0c045248(a, 21);
}
