/* Candidate: size exact. Differs: e6b2 keeps the stream pointer in r13 and
 * the cursor pointer in r12 in retail (swapped here); case 2 in retail
 * branches into the shared "pos += 2" tail (the goto form instead lets SHC
 * cross-jump the case 3/4 float tails and links 4 bytes short); e78e switch
 * comparisons run 0,5,2 in retail but SHC sorts them 0,2,5 (a known open
 * switch-order question). e82a and both pools after e7c8 match. */
#include "objects.h"
extern int func_0c04de10(struct Actor *, int);
extern int func_0c0519fc(struct Actor *);

void func_0c04e6a8(struct Actor *a)
{
    a->b441 = a->b440;
}

void func_0c04e6b2(struct Actor *a, struct OperandStream *s, int kind)
{
    unsigned char *q, *p;
    p = s->base + s->pos;
    q = p + 1;
    switch (kind) {
    case 0:
        func_0c04e6a8(a);
        a->b440 = *p;
        s->pos++;
        s->count++;
        break;
    case 1:
        a->parameter4b4.integer = *p;
        s->pos++;
        break;
    case 2:
        a->parameter4b4.integer = (unsigned short)((*p << 8 | *q) << 16 >> 16);
        s->pos += 2;
        break;
    case 3:
        a->parameter4b4.integer = (unsigned short)(*p << 8 | *q) << 16 >> 16;
        a->parameter4b4.real = a->parameter4b4.integer * 1.66666663f;
        goto two;
    case 4:
        a->parameter4b4.integer = (unsigned short)(*p << 8 | *q) << 16 >> 16;
        a->parameter4b4.real = a->parameter4b4.integer * 2.1428571f;
    two:
        s->pos += 2;
        break;
    }
}

int func_0c04e788(struct Actor *a, int mode)
{
    return func_0c04de10(a, mode);
}

int func_0c04e78e(struct Actor *a, int mode)
{
    switch (mode) {
    case 0:
        if (a->b1f9 == 2) return 0;
        break;
    case 5:
        if (a->b1f9 == 2) return 0;
        if (a->b495 & 2) goto call;
        break;
    case 2:
        if (!a->b14a & 0xe0) goto call;
        break;
    }
    if (a->b495 >= 0) return 1;
call:
    if (!func_0c04e788(a, mode)) return 0;
    if (a->b495) {
        if (a->b495 & 2) {
            a->b495 ^= 2;
            a->b495 |= -128;
        }
    }
    return 1;
}

int func_0c04e82a(struct Actor *a, void *p)
{
    if (a->b495) {
        if (a->b495 > 0) goto stop;
        if (!(a->b495 & 2)) {
            a->b495 &= 0x11;
        } else if (a->b495 & 0x10) {
stop:
            a->b495 = 0;
            func_0c0519fc(a);
            return 0;
        } else {
            a->b495 &= 0x7f;
        }
    }
    return 1;
}
