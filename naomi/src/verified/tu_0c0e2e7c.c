#include "objects.h"

extern void func_0c045248(struct Actor *a, int n);

void func_0c0e2e7c(struct Actor *a)
{
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    switch (a->b4c9) {
    case 0:
        a->b1e9 = 0;
        break;
    case 1:
        a->b1e9 = 1;
        break;
    case 2:
        a->b1e9 = 14;
        break;
    }
    a->b1a3 = 1;
    func_0c045248(a, 21);
}

void func_0c0e2eba(struct Actor *a)
{
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    switch (a->b4c9) {
    case 0:
        a->b1e9 = 0;
        break;
    case 1:
        a->b1e9 = 1;
        break;
    case 2:
        a->b1e9 = 2;
        break;
    }
    a->b1a3 = 1;
    func_0c045248(a, 21);
}
