#include "objects.h"

extern void func_0c045248(struct Actor *, int);

void func_0c10219c(struct Actor *a)
{
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    switch (a->b4c9) {
    case 0:
        a->b1e9 = 0;
        goto set;
    case 1:
        a->b1e9 = 1;
        a->b1a3 = 0;
        break;
    case 2:
        a->b1e9 = 13;
    set:
        a->b1a3 = 1;
        break;
    }
    func_0c045248(a, 21);
}
