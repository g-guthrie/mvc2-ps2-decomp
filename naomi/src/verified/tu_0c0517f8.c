/* func_0c051886: the label before the w4dc read-modify-write starts a new block there, so the 0x80 for b4ab is loaded after the w4dc read as in retail. */
#include "objects.h"
extern void func_0c04e6b2(struct Actor *, struct OperandStream *, int);
extern int func_0c04e788(struct Actor *, int);
extern int func_0c050792(struct Actor *, struct OperandStream *, int);
extern struct PlayerSlotScore dat_0c2d7088[];

int func_0c0517f8(struct Actor *a, struct OperandStream *s)
{
    int i, sum;
    struct PlayerSlotScore *p;
    int theirs, mine;
    func_0c04e6b2(a, s, 0);
    func_0c04e6b2(a, s, 2);
    sum = 0;
    p = dat_0c2d7088 + (a->b2 ^ 1);
    for (i = 0; i < 3; i++, p += 2)
        sum += (short)p->actor.w420;
    theirs = sum * 144 / 200;
    mine = a->parameter4b4.integer * 144 / 200;
    return func_0c050792(a, s, theirs <= mine);
}

int func_0c051886(struct Actor *a, struct OperandStream *s)
{
    int mask;
    func_0c04e6b2(a, s, 0);
    func_0c04e6b2(a, s, 1);
    a->w1fa = 0;
    a->w4ac = 0;
    mask = 0x240 >> a->parameter4b4.integer;
    if (a->b440 == 74) {
        mask &= 0x380;
        a->b4ab = 0;
    } else {
        mask &= 0x70;
        a->b4ab = 1;
    }
    if (!(a->w4ae & (unsigned short)mask)) {
        a->w4ae |= mask;
        if (func_0c04e788(a, 2)) {
            goto f;
        f:
            a->w4dc |= mask;
            a->b4ab |= 0x80;
            a->b4aa = *(unsigned char *)&a->parameter4b4;
        }
    }
    return 0;
}

int func_0c051918(struct Actor *a, struct OperandStream *s)
{
    func_0c04e6b2(a, s, 0);
    return 0;
}
