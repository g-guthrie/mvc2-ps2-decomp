#include "objects.h"

struct Sub_0c13c434 {
    unsigned char pad[10];
    unsigned char b10;
};
struct Inner_0c13c434 {
    unsigned char pad[0x2a4];
    struct Sub_0c13c434 sub;
};
struct Obj_0c13c434 {
    unsigned char pad0[4];
    unsigned char b4;
    char b5;
    unsigned char pad1[0x18 - 6];
    struct Inner_0c13c434 *p18;
    unsigned char pad2[0x20 - 0x1c];
    unsigned char b20;
    unsigned char pad3[0x12c - 0x21];
    unsigned char b12c;
    unsigned char pad4[0x158 - 0x12d];
    char b158;
    char b159;
};
extern char dat_0c22f504[];
extern void func_0c02a0c4(struct Obj_0c13c434 *, int, int);
extern char func_0c02a026(struct Obj_0c13c434 *);
extern void func_0c037688(struct Obj_0c13c434 *);

void func_0c13c434(struct Obj_0c13c434 *a)
{
    struct Sub_0c13c434 *s;
    a->b5 = a->b5 + 1;
    s = &a->p18->sub;
    s->b10 = 0;
    a->b159 = 21;
    a->b158 = dat_0c22f504[a->b20];
    func_0c02a0c4(a, a->b159, a->b158);
}

void func_0c13c46a(struct Obj_0c13c434 *a)
{
    if (func_0c02a026(a) < 0) {
        a->b4 = a->b4 + 1;
        a->b12c = 0;
    }
}

void func_0c13c48c(struct Obj_0c13c434 *a)
{
    struct Sub_0c13c434 *s;
    s = &a->p18->sub;
    s->b10 = 0;
    a->b12c = 0;
    func_0c037688(a);
}
