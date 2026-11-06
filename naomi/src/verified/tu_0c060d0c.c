#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c02a684(struct Actor *, int, int, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c18f420(struct Actor *, int);
extern int func_0c043628(struct Actor *);
extern int func_0c1ec190(void);
extern char dat_0c2f837e;
extern struct ActorFlags *dat_0c2d6f84;
extern int dat_0c23fd8c[];
extern const unsigned char dat_0c23ffac[][2];
extern void (*table_0c23ffa4[])(struct Actor *);
extern void (*table_0c23ffcc[])(struct Actor *);

void func_0c060d0c(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b140) {
        a->b140 = 0;
        func_0c02a684(a, 0, dat_0c23fd8c[a->b37] + a->b14b, 1);
        if ((a->s28)-- == 0) {
            func_0c02a684(a, 0, dat_0c23fd8c[a->b37] + 4, 1);
            a->b6++;
            func_0c02a0c4(a, 18, 2);
        }
    }
}

void func_0c060d80(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b5++;
        func_0c02a39a(a, 0);
        return;
    }
    if (a->b140) {
        if ((char)a->b140 == 96)
            func_0c02a39a(a, 0);
        else
            func_0c02a684(a, 0, dat_0c23fd8c[a->b37] + (char)a->b140, 1);
        a->b140 = 0;
    }
}

void func_0c060de4(struct Actor *a)
{
    table_0c23ffa4[a->b6](a);
}

void func_0c060df6(struct Actor *a)
{
    struct ActorSubControlBytes *sub = (struct ActorSubControlBytes *)&a->sub2a4;
    const unsigned char *p;
    char i;

    if (a->w340 & 0x3f0) {
        if (a->w340 & 0x200)
            i = 0;
        else if (a->w340 & 0x100)
            i = 4;
        else if (a->w340 & 0x80)
            i = 6;
        else if (a->w340 & 0x40)
            i = 8;
        else if (a->w340 & 0x20)
            i = 10;
        else if (dat_0c2f837e && func_0c043628(a) == 1)
            i = 12;
        else
            goto rnd;
    } else if (dat_0c2f837e && func_0c043628(a) == 1)
        i = (func_0c1ec190() + dat_0c2d6f84->flags) & 15;
    else
    rnd:
        i = (func_0c1ec190() + dat_0c2d6f84->flags) & 7;
    a->b158 = dat_0c23ffac[i][0];
    a->b33 = dat_0c23ffac[i][0];
    sub->b12 = dat_0c23ffac[i][1];
    func_0c02a0c4(a, 19, a->b158);
    if (a->b33 == 5)
        func_0c18f420(a, 2);
}

void func_0c060f14(struct Actor *a)
{
    struct ActorSubControlBytes *sub = (struct ActorSubControlBytes *)&a->sub2a4;

    sub->b12 = 9;
    func_0c02a0c4(a, 19, 7);
}

void func_0c060f24(struct Actor *a)
{
    struct ActorSubControlBytes *sub = (struct ActorSubControlBytes *)&a->sub2a4;

    sub->b12 = 9;
    func_0c02a0c4(a, 19, 8);
}

void func_0c060f34(struct Actor *a)
{
    a->b6++;
    a->b7 = 0;
    table_0c23ffcc[a->b32](a);
}
