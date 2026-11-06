#include "objects.h"

struct Act_0c081998 {
    unsigned char pad0[5];
    unsigned char b5, b6, b7;
    unsigned char pad1[0x1e9 - 8];
    unsigned char b1e9;
    unsigned char pad2[0x2a8 - 0x1ea];
    int l2a8;
    unsigned char pad3[0x4c9 - 0x2ac];
    char b4c9;
};

extern char dat_0c241dae[];
extern char dat_0c241db1[];
extern void func_0c045248(struct Actor *, int);

struct Pair_0c10c238 { unsigned char e, a; };
extern struct Pair_0c10c238 dat_0c241db4[];
extern struct Pair_0c10c238 dat_0c241dba[];

void func_0c081998(struct Act_0c081998 *a)
{
    int r5;

    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    r5 = a->b4c9;
    r5 = dat_0c241dae[r5];
    if (a->l2a8 == 39)
        r5 = 28;
    if (a->l2a8 == 7)
        r5 = 27;
    a->b1e9 = r5;
    func_0c045248((struct Actor *)a, 29);
}

void func_0c0819c6(struct Act_0c081998 *a)
{
    int r5;

    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    r5 = a->b4c9;
    r5 = dat_0c241db1[r5];
    if (a->l2a8 == 39)
        r5 = 28;
    if (a->l2a8 == 7)
        r5 = 27;
    a->b1e9 = r5;
    func_0c045248((struct Actor *)a, 29);
}

void func_0c0819f4(struct Actor *a)
{
    struct Pair_0c10c238 *t = dat_0c241db4;

    a->b6 = a->b7 = a->b5 = 0;
    a->b1e9 = t[a->b4c9].e;
    *(&a->b1a3) = t[a->b4c9].a;
    func_0c045248(a, 21);
}

void func_0c081a22(struct Actor *a)
{
    struct Pair_0c10c238 *t = dat_0c241dba;

    a->b6 = a->b7 = a->b5 = 0;
    a->b1e9 = t[a->b4c9].e;
    *(&a->b1a3) = t[a->b4c9].a;
    func_0c045248(a, 21);
}
