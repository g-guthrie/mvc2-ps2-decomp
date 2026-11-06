/* Exact 880-byte packed-action group: guard, dispatcher, two selectors,
 * and three pools. Switch entries inside the selectors are not functions. */
#include "objects.h"

extern void func_0c107fc8(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern const unsigned short dat_0c24b3b8[], dat_0c24b3d0[];
extern const unsigned short dat_0c24b3bc[], dat_0c24b3d4[];
extern const unsigned short dat_0c24b3c0[], dat_0c24b3d8[];
extern const unsigned short dat_0c24b3c4[], dat_0c24b3dc[];
extern const unsigned short dat_0c24b3c8[], dat_0c24b3e0[];
extern const unsigned short dat_0c24b3cc[], dat_0c24b3e4[];
void func_0c10621c(struct Actor *);
void func_0c106354(struct Actor *);
void func_0c1061f8(struct Actor *);

void func_0c1061c8(struct Actor *a)
{
    if (!a->b201 && (a->b1fe || !(a->b1d6 & 15)) &&
        (!a->b1fe || !(a->b1d6 & 0xf0)))
        return;
    func_0c1061f8(a);
}

void func_0c1061f8(struct Actor *a)
{
    func_0c107fc8(a);
    if ((unsigned char)a->b1fe == 1)
        func_0c106354(a);
    else
        func_0c10621c(a);
}

void func_0c10621c(struct Actor *a)
{
    int zero = 0;

    switch (a->b1e8) {
    case 0:
        a->b158 = zero;
        a->b1a1 = 12;
        func_0c0346da(a, 20);
        if (!a->b1fc)
            a->p3f4 = (void *)dat_0c24b3b8;
        else
            a->p3f4 = (void *)dat_0c24b3d0;
        a->b1a7 = zero;
        break;
    case 1:
        a->b158 = 1;
        a->b1a1 = 13;
        if (!a->b1fc)
            a->p3f4 = (void *)dat_0c24b3bc;
        else
            a->p3f4 = (void *)dat_0c24b3d4;
        a->b1a7 = 1;
        break;
    case 2:
        if (!a->b1fc)
            a->p3f4 = (void *)dat_0c24b3c0;
        else
            a->p3f4 = (void *)dat_0c24b3d8;
        a->b1a7 = 2;
        a->b158 = 2;
        a->b1a1 = 14;
        if (a->w1fa & 0x2000) {
            a->b158 = 6;
            a->b1a1 = 18;
        }
        if (a->w1fa & 0x1000) {
            a->b158 = 7;
            a->b1a1 = 19;
        }
        break;
    }
    a->w1ac = zero;
    a->b19e = zero;
    *(void **)&a->p1c4 = (void *)zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 11, a->b158);
    if (a->b1d6 & 15)
        a->b1d6--;
}

void func_0c106354(struct Actor *a)
{
    int zero = 0;
    int one = 1;

    switch (a->b1e8) {
    case 0:
        func_0c02a0c4(a, 12, zero);
        a->b1a1 = 15;
        func_0c0346da(a, 20);
        if (!a->b1fc)
            a->p3f4 = (void *)dat_0c24b3c4;
        else
            a->p3f4 = (void *)dat_0c24b3dc;
        a->b1a7 = zero;
        break;
    case 1:
        a->b158 = one;
        func_0c02a0c4(a, 12, one);
        a->b1a1 = 16;
        func_0c0346da(a, 21);
        if (!a->b1fc)
            a->p3f4 = (void *)dat_0c24b3c8;
        else
            a->p3f4 = (void *)dat_0c24b3e0;
        a->b1a7 = one;
        break;
    case 2:
        if (!a->b1fc)
            a->p3f4 = (void *)dat_0c24b3cc;
        else
            a->p3f4 = (void *)dat_0c24b3e4;
        a->b1a7 = 2;
        if ((a->w1fa & 0x1000) && a->f56 > a->f41c + 137.142853f) {
            a->b201 = zero;
            a->b1d6 &= 15;
            a->b1fc = zero;
            func_0c02a0c4(a, 20, 4);
            a->b1a1 = 21;
            a->f92 = 0.0f;
            a->f96 = 0.0f;
            a->f104 = 0.0f;
            a->f108 = 0.0f;
            a->b6 = one;
            a->b7 = zero;
        } else {
            a->b6 = zero;
            a->b159 = 12;
            func_0c0346da(a, 22);
            if (a->w1fa & 0x2000) {
                func_0c02a0c4(a, 12, 6);
                a->b1a1 = 20;
            } else {
                func_0c02a0c4(a, 12, 2);
                a->b1a1 = 17;
            }
        }
        break;
    }
    a->w1ac = zero;
    a->b19e = zero;
    *(void **)&a->p1c4 = (void *)zero;
    dat_0c2f83f8->arr[a->b2]++;
    if (a->b1d6 & 0xf0)
        a->b1d6 -= 16;
}
