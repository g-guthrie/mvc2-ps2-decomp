#include "objects.h"

struct DecObj {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[21];
    short s28;
    unsigned char pad2[0x123];
    char b141;
    unsigned char pad3[0x177];
    char b2b9;
    unsigned char pad4[0x6d];
    unsigned char b327, b328;
    unsigned char pad5[0xcf];
    unsigned char b3f8, b3f9;
};

typedef void (*DecHandler)(struct DecObj *);

extern char func_0c02a026(struct DecObj *);
extern void func_0c1b19c6(struct DecObj *, int);
extern void func_0c16741c(struct DecObj *, float, float);
extern int func_0c047bbe(struct DecObj *);
extern void func_0c02a0c4(struct DecObj *, int, int);
extern void func_0c0437b8(struct DecObj *);
extern DecHandler table_0c248ef4[];

void func_0c0de378(struct DecObj *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if ((a->b141 & 0x80) == 0)
        return;
    a->b141 = 0;
    a->b6 = a->b6 + 1;
    func_0c1b19c6(a, 9);
    func_0c16741c(a, -195.0f, 113.57143f);
}

void func_0c0de3c4(struct DecObj *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (a->b2b9 != 0 && func_0c047bbe(a) != 0)
        a->b2b9 = a->b2b9 - 1;
    else if (--a->s28 <= 0) {
        a->b3f8 = a->b3f9 = 0;
        a->b328 = a->b327 = 0;
        a->b6 = a->b6 + 1;
        func_0c02a0c4(a, 22, 14);
    }
    func_0c02a026(a);
}

void func_0c0de42a(struct DecObj *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0de44c(struct DecObj *a)
{
    table_0c248ef4[a->b6](a);
}
