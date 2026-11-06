/* Candidate: size exact, 594/604 bytes. func_0c0510e0 (222 bytes) is exact.
 * func_0c0511be differs only in register choice at 0x0c051252-0x0c051272:
 * retail keeps the l414 pointer in r6 and a fresh `mov #0,r1` for both
 * `or r1,r2` and `add r1,r6`; here the zero is a named local (r6) and the
 * pointer lands in r7, and the base+zero join is `|` (an unsigned `+` is
 * folded away, a signed zero folds the OR too). long long is unavailable. */
#include "objects.h"

extern int func_0c04e788(struct Actor *, int);
extern void func_0c04e6b2(struct Actor *, void *, int);
extern unsigned char func_0c044a4a(struct Actor *);
extern int func_0c04debe(struct Actor *);
extern void func_0c0453c4(struct Actor *, int);

int func_0c0510e0(struct Actor *a, void *s)
{
    unsigned short w, bits, cmd;

    if (!func_0c04e788(a, 1))
        return 0;
    func_0c04e6b2(a, s, 0);
    func_0c04e6b2(a, s, 1);
    a->l44c = a->parameter4b4.integer;
    if (a->b202 || a->b1f0 || !func_0c044a4a(a) || !(w = func_0c04debe(a)))
        return 1;
    a->b43d++;
    bits = 0x400;
    if (a->b1f9 == 2) {
        cmd = 19;
    } else {
        if (a->b440 == 60 || (w & 4)) {
            bits = 0x1400;
            cmd = 5;
        } else {
            cmd = 7;
        }
        func_0c0453c4(a, cmd);
        cmd = 18;
    }
    a->l450 = bits ^ a->b1d2 * 0xc00;
    a->w4dc = a->l450;
    a->w34a = bits;
    func_0c0453c4(a, cmd);
    a->w34a = 0;
    return 0;
}

int func_0c0511be(struct Actor *a, void *s)
{
    int r, v, z;

    if (a->b411 || (a->b1d0 != 18 && a->b1d0 != 19)) {
        a->b43d--;
        return 1;
    }
    if (a->b45f == 1) {
        a->b45d = 1;
        a->b448 = 125;
        a->b4ab = 0;
        a->b4aa = 0;
        a->w4ac = 0;
    } else if (a->b4a7 == 1) {
        unsigned int *p = &a->l414;
        unsigned int zz;
        v = 0;
        zz = p[1] & 0;
        if (((p[0] & 0x30000000) | zz) != 0) {
            if (a->b1 == 28) {
                p = (unsigned int *)((unsigned int)&a->sub2a4 | zz);
                v = ((unsigned char *)p)[1];
            }
            if (a->b1 == 29) {
                p = (unsigned int *)&a->sub2a4;
                v = ((unsigned char *)p)[1];
            }
        }
        if (!v) {
            a->b1dd = -1;
            a->b4a7 = 0;
            a->b354 = 0;
            a->b355 = 0;
            a->b356 = 0;
            a->b357 = 0;
            a->b358 = 0;
            a->b359 = 0;
            a->w35a = 0;
        }
    }
    if (--a->l44c != 0) {
        if ((r = func_0c04debe(a)) != 0) {
            if (a->b1f9 == 2 || (r & 2))
                a->l450 &= ~0x1000;
            if (a->b1f9 == 1 || (r & 4) || a->b440 == 60)
                a->l450 |= 0x1000;
        }
        a->w4dc = a->l450;
    }
    return 0;
}
