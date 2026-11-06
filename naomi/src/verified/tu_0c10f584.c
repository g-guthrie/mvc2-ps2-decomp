#include "objects.h"

extern void func_0c045248(struct Actor *, int);

void func_0c10f584(struct Actor *a)
{
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    switch (a->b4c9) {
    case 0:
        a->b1e9 = 11;
        break;
    case 1:
        a->b1e9 = 4;
        a->b1a3 = 1;
        break;
    case 2:
        a->b1e9 = 12;
        break;
    }
    func_0c045248(a, 21);
}
