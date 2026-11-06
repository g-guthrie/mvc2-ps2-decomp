#include "objects.h"

struct Glob_0c2f8338 {
    unsigned char pad[0x3b];
    unsigned char b3b;
    unsigned short w3c;
};

extern struct Glob_0c2f8338 dat_0c2f8338;
extern char func_0c02a026(struct Actor *a);
extern void func_0c037688(struct Actor *a);

void func_0c195874(struct Actor *a, struct Actor *b)
{
    if ((dat_0c2f8338.w3c & (1 << dat_0c2f8338.b3b)) == 0) {
        if (func_0c02a026(a) < 0) {
            a->b4 = 2;
            a->b12c = 0;
        } else {
            a->f52 += a->f92;
            a->f92 += a->f104;
            a->f56 += a->f96;
            a->f96 += a->f108;
            if (a->f56 < b->f41c) {
                a->f56 = b->f41c;
                a->f92 = 0.0f;
                a->f96 = 0.0f;
                a->f104 = 0.0f;
                a->f108 = 0.0f;
            }
        }
    }
}

void func_0c195916(struct Actor *a)
{
    func_0c037688(a);
}
