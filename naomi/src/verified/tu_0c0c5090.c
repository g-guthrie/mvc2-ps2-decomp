#include "objects.h"

struct Obj_0c0c5090 {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
};

struct Row_0c0c5090 {
    struct Obj_0c0c5090 *p[3];
};

struct Glob_0c0c5090 {
    unsigned char pad[24];
    struct Row_0c0c5090 row[64];
};

extern struct Glob_0c0c5090 dat_0c2f8338;

int func_0c0c5090(struct Obj_0c0c5090 *a, unsigned char c)
{
    unsigned int u = 0;
    struct Obj_0c0c5090 *p;

    do {
        p = *(struct Obj_0c0c5090 **)(u + (char *)&(&dat_0c2f8338.row[0])[a->b2]);
        if (p != a && p->b1 == c)
            return 1;
        u = u + 4;
    } while (u <= 8);
    return 0;
}
