#include "objects.h"

/* Player slot records at 0x0c2f8350 (12 bytes, actor pointer at +4). */
struct PlayerSlot_045e10 { int pad0; struct Actor *actor; int pad8; };
struct Dat0c2f8338_045e10 {
    unsigned char b0, b1;
    unsigned char pad2[22];
    struct PlayerSlot_045e10 slots[6];
};
struct Methods_045e10 {
    void *slot0;
    void (*slot1)(struct Actor *);
    void *slot2[11];
    int (*slot13)(struct Actor *);
};

extern struct Dat0c2f8338_045e10 dat_0c2f8338;
struct Tbl_045e10 { unsigned char pad[74]; unsigned char bits[8]; };
extern struct Tbl_045e10 *dat_0c2f83f8;

void func_0c045e10(struct Actor *a)
{
    a->b254 = 0;
    if (!(dat_0c2f8338.b1 & 4) && !a->b411)
        ((struct Methods_045e10 *)a->p428)->slot1(a);
}

void func_0c045e3c(struct Actor *a)
{
    struct PlayerSlot_045e10 *s;
    struct Actor *t;

    if (a->b1d0 != 29)
        return;
    if (a->b254)
        return;
    if (dat_0c2f8338.b1 & 4)
        return;
    t = (&dat_0c2f8338.slots[0] + a->b2)->actor;
    if (dat_0c2f83f8->bits[t->b2] & (1 << (t->pad7cc[0] / 2)))
        return;
    if (t->b0)
        return;
    if ((short)t->w420 <= 0)
        return;
    if (t->w2a0)
        return;
    t->w340 = a->w340;
    t->w348 = a->w348;
    t->w342 = a->w342;
    t->w344 = a->w344;
    t->w346 = a->w346;
    t->w34a = a->w34a;
    t->w34e = a->w34e;
    t->w34c = a->w34c;
    if (((struct Methods_045e10 *)t->p428)->slot13(t)) {
        a->b254 = 6;
        a->b257 = 1;
    }
}
