/* Exact 936-byte dispatcher and four state selectors, including three pools. */
#include "objects.h"

extern void func_0c044cbc(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern const unsigned short dat_0c24b3a0[], dat_0c24b3a4[], dat_0c24b3a8[];
extern const unsigned short dat_0c24b3ac[], dat_0c24b3b0[], dat_0c24b3b4[];
void func_0c105e68(struct Actor *);
void func_0c105f38(struct Actor *);
void func_0c10602c(struct Actor *);
void func_0c106102(struct Actor *);

void func_0c105e20(struct Actor *a)
{
    func_0c044cbc(a);
    if ((unsigned char)a->b1fe == 1) {
        if (a->b1f9 == 1)
            func_0c106102(a);
        else
            func_0c10602c(a);
    } else {
        if (a->b1f9 == 1)
            func_0c105f38(a);
        else
            func_0c105e68(a);
    }
}

void func_0c105e68(struct Actor *a)
{
    int zero = 0;
    int mode;

    switch (a->b1e8) {
    case 0:
        a->b158 = zero;
        a->b1a1 = zero;
        a->p3f4 = (void *)dat_0c24b3a0;
        a->b1a7 = zero;
        mode = 20;
        goto set_mode;
    case 1:
        a->b158 = 1;
        a->b1a1 = 1;
        a->p3f4 = (void *)dat_0c24b3a4;
        a->b1a7 = 1;
        mode = 21;
set_mode:
        func_0c0346da(a, mode);
        break;
    case 2:
        a->b158 = 2;
        a->b1a1 = 2;
        a->p3f4 = (void *)dat_0c24b3a8;
        a->b1a7 = 2;
        a->b6 = zero;
        a->s28 = 40;
        break;
    }
    a->w1ac = zero;
    a->b19e = zero;
    *(void **)&a->p1c4 = (void *)zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 7, a->b158);
}

void func_0c105f38(struct Actor *a)
{
    struct ActorSub2a4 *sub = &a->sub2a4;
    int zero = 0;
    int mode;

    switch (a->b1e8) {
    case 0:
        a->b158 = zero;
        a->b1a1 = 6;
        a->p3f4 = (void *)dat_0c24b3a0;
        a->b1a7 = zero;
        mode = 20;
        goto set_mode;
    case 1:
        a->b158 = 1;
        a->b1a1 = 7;
        a->p3f4 = (void *)dat_0c24b3a4;
        a->b1a7 = 1;
        mode = 21;
set_mode:
        func_0c0346da(a, mode);
        a->w1ac = zero;
        a->b19e = zero;
        *(void **)&a->p1c4 = (void *)zero;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c02a0c4(a, 9, a->b158);
        return;
    case 2:
        a->b158 = 2;
        a->b1a1 = 8;
        a->p3f4 = (void *)dat_0c24b3a8;
        a->b1a7 = 2;
        a->b1a1 = 53;
        a->w1ac = zero;
        a->b19e = zero;
        *(void **)&a->p1c4 = (void *)zero;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c02a0c4(a, 9, a->b158);
        a->b7 = zero;
        sub->b0 = zero;
        a->s30 = a->b141;
        a->b141 = zero;
        break;
    }
}

void func_0c10602c(struct Actor *a)
{
    int zero = 0;

    switch (a->b1e8) {
    case 0:
        a->b158 = zero;
        a->b1a1 = 3;
        func_0c0346da(a, 20);
        a->p3f4 = (void *)dat_0c24b3ac;
        a->b1a7 = zero;
        break;
    case 1:
        a->b158 = 1;
        a->b1a1 = 4;
        func_0c0346da(a, 21);
        a->p3f4 = (void *)dat_0c24b3b0;
        a->b1a7 = 1;
        break;
    case 2:
        a->b158 = 2;
        a->b1a1 = 5;
        a->p3f4 = (void *)dat_0c24b3b4;
        a->b1a7 = 2;
        func_0c0346da(a, 22);
        break;
    }
    a->w1ac = zero;
    a->b19e = zero;
    *(void **)&a->p1c4 = (void *)zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 8, a->b158);
}

void func_0c106102(struct Actor *a)
{
    int zero = 0;

    switch (a->b1e8) {
    case 0:
        a->b158 = zero;
        a->b1a1 = 9;
        func_0c0346da(a, 20);
        a->p3f4 = (void *)dat_0c24b3ac;
        a->b1a7 = zero;
        break;
    case 1:
        a->b158 = 1;
        a->b1a1 = 10;
        a->p3f4 = (void *)dat_0c24b3b0;
        a->b1a7 = 1;
        break;
    case 2:
        a->b158 = 2;
        a->b1a1 = 11;
        a->p3f4 = (void *)dat_0c24b3b4;
        a->b1a7 = 2;
        func_0c0346da(a, 22);
        break;
    }
    a->w1ac = zero;
    a->b19e = zero;
    *(void **)&a->p1c4 = (void *)zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 10, a->b158);
}
