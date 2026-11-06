/* Hit-stun update chosen by stance and air/ground state, and its dispatcher. */
#include "objects.h"
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c04428c(struct Actor *);
extern void func_0c0443ce(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c191980(struct Actor *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c129c96(struct Actor *a);
void func_0c129d12(struct Actor *a);
void func_0c129e44(struct Actor *a);
void func_0c129fee(struct Actor *a);
void func_0c12a0c8(struct Actor *a);

void func_0c129c88(struct Actor *a)
{
    func_0c043352(a);
    func_0c129c96(a);
}

void func_0c129c96(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (a->b1fe == 0) {
        if (a->b1f9 == 0) func_0c129d12(a);
        else func_0c129e44(a);
    } else {
        if (a->b1f9 == 0) func_0c129fee(a);
        else func_0c12a0c8(a);
    }
}

void func_0c129d12(struct Actor *a)
{
    void *zero;
    int animation;
    zero = 0;
    switch (a->b1e8) {
    case 0:
        if (func_0c02a026(a) < 0)
            goto fall;
        break;
    case 1:
        if (func_0c02a026(a) < 0)
            goto fall;
        if (!a->b141)
            break;
        if (func_0c04428c(a))
            break;
        if (!a->b19e)
            break;
        if ((a->w34e | a->w352) & 0x200) {
        a->w352 = (int)zero;
        func_0c0443ce(a);
        func_0c0344a0(a, 31);
        if (a->b141 == 1) {
            a->b1a1 = 28;
            a->w1ac = (int)zero;
            a->b19e = (int)zero;
            *(void **)&a->p1c4 = zero;
            dat_0c2f83f8->arr[a->b2]++;
            func_0c02a0c4(a, 7, 4);
        } else {
            a->b1a1 = 1;
            a->w1ac = (int)zero;
            a->b19e = (int)zero;
            *(void **)&a->p1c4 = zero;
            dat_0c2f83f8->arr[a->b2]++;
            func_0c02a0c4(a, 7, 1);
        }
        }
        break;
    case 2:
        if (func_0c02a026(a) < 0) {
fall:
            func_0c0437b8(a);
            break;
        }
        if (a->b141) {
            a->b141 = (int)zero;
            func_0c191980(a, 1);
        }
        break;
    }
}

void func_0c129e44(struct Actor *a)
{
    float fzero;
    switch (a->b1e8) {
    case 0:
        if (func_0c02a026(a) < 0)
            goto fall;
        break;
    case 1:
        if (func_0c02a026(a) < 0)
            goto fall;
        if (a->b141) {
            a->b141 = 0;
            func_0c191980(a, 2);
        }
        break;
    case 2:
        fzero = 0.0f;
        if (!a->b6) {
            if (!(a->b141 & 2)) {
                a->f52 += a->f92;
                a->f92 += a->f104;
            }
            if (func_0c02a026(a) < 0)
                goto fall;
            if (!(a->b141 & 1))
                break;
            a->f92 = fzero;
            a->f104 = fzero;
            func_0c0344a0(a, 32);
            func_0c191980(a, 3);
            break;
        }
        if (func_0c02a026(a) < 0) {
fall:
            func_0c0437b8(a);
            break;
        }
        if (a->b141 & 1) {
            a->b141 ^= 1;
            a->f92 = -7.91666651f;
            a->f104 = 0.15625f;
            if (a->b1d2) {
                a->f92 = -a->f92;
                a->f104 = -a->f104;
            }
            func_0c0346da(a, 41);
        }
        a->f52 += a->f92;
        a->f92 += a->f104;
        if (a->b141 & 2) {
            float dx;
            a->b141 ^= 2;
            a->f92 = fzero;
            a->f104 = fzero;
            dx = -53.3333321f;
            if (a->b1d2)
                dx = 53.3333321f;
            a->f52 += dx;
        }
        break;
    }
}


void func_0c129fee(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
    case 2:
        if (func_0c02a026(a) < 0)
            goto fall;
        break;
    case 1:
        if (func_0c02a026(a) < 0) {
fall:
            func_0c0437b8(a);
            break;
        }
        if (!a->b141)
            break;
        if (func_0c04428c(a))
            break;
        if ((a->w34e | a->w352) & 0x40) {
            a->w352 = 0;
            a->b1a1 = 27;
            a->w1ac = 0;
            a->b19e = 0;
            a->p1c4 = 0;
            dat_0c2f83f8->arr[a->b2]++;
            func_0c0443ce(a);
            func_0c0346da(a, 21);
            func_0c02a0c4(a, 8, 4);
        }
        break;
    }
}


void func_0c12a0c8(struct Actor *a)
{
    float dx;
    switch (a->b1e8) {
    case 0:
    case 1:
        if (func_0c02a026(a) < 0)
            goto fall;
        break;
    case 2:
        if (func_0c02a026(a) < 0) {
fall:
            func_0c0437b8(a);
            break;
        }
        dx = (char)a->b140 * 1.66666663f;
        if (!a->b1d2)
            dx = -dx;
        a->f52 += dx;
        break;
    }
}

