#include "objects.h"

extern int func_0c04e78e(struct Actor *, int);
extern int func_0c04e82a(struct Actor *, struct OperandStream *);
extern void func_0c04e6b2(struct Actor *, struct OperandStream *, int);
extern int func_0c051b50(struct Actor *, void *);
extern int (*const table_0c23e97c[])(struct Actor *, void *);

int func_0c050ea4(struct Actor *a, struct OperandStream *s)
{
    int bits;

    if (!func_0c04e78e(a, 3))
        return 0;
    if (!func_0c04e82a(a, s))
        return 0;
    func_0c04e6b2(a, s, 0);
    goto f; f: a->b43d++;
    a->b43e = 0;
    a->b43f = 0;
    a->b45d = 1;
    func_0c04e6b2(a, s, 1);
    a->b448 = a->parameter4b4.integer;
    func_0c04e6b2(a, s, 1);
    a->l44c = a->parameter4b4.integer;
    func_0c04e6b2(a, s, 1);
    a->b4ab = a->parameter4b4.integer;
    func_0c04e6b2(a, s, 1);
    a->b4aa = a->parameter4b4.integer;
    func_0c04e6b2(a, s, 1);
    bits = a->parameter4b4.integer << 8;
    if ((unsigned short)bits & 0x0c00)
        bits ^= a->b1d2 * 0xc00;
    a->w4ac = a->parameter4b4.integer << 8;
    a->l450 = (unsigned short)bits;
    a->w4dc = bits;
    if (a->b1 == 48)
        { goto g; g: a->f498 = table_0c23e97c[a->l44c]; }
    else
        a->f498 = func_0c051b50;
    return 0;
}

int func_0c050f8e(struct Actor *a, struct OperandStream *s)
{
    unsigned char *p;
    int bits;

    if (a->b5 == 0 && (a->b1d0 == 21 || a->b1d0 == 29))
        goto next;
    goto f; f: a->b43d--;
    a->w442 = 0;
    return 1;
next:
    if (a->w442 && !--a->w442) {
        p = s->base;
        p += a->w444;
        a->b45d = 1;
        a->b448 = *p++;
        a->l44c = *p++;
        a->b4ab = *p++;
        a->b4aa = *p++;
        bits = *p << 8;
        if ((unsigned short)bits & 0x0c00) {
            bits ^= a->b1d2 * 0xc00;
            a->w4ac = bits;
        }
    }
    a->w4dc = a->l450;
    return a->f498(a, s);
}

int func_0c05105c(struct Actor *a, struct OperandStream *s)
{
    func_0c04e6b2(a, s, 0);
    func_0c04e6b2(a, s, 1);
    a->l44c = a->parameter4b4.integer;
    a->b45f = a->parameter4b4.integer + 1;
    return 1;
}

int func_0c051094(struct Actor *a, struct OperandStream *s)
{
    func_0c04e6b2(a, s, 0);
    func_0c04e6b2(a, s, 1);
    a->l44c = a->parameter4b4.integer;
    a->b4a7 = *(unsigned char *)&a->l44c + 1;
    return 1;
}
