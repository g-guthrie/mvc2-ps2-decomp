/* Twelve state handlers and their pools. func_0c02a0c4 takes a char variant
 * argument here, which is what drops the extend on the toggled direction. */
#include "objects.h"
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, char);
extern char func_0c02a026(struct Actor *);
extern void func_0c0451f2(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c241168[])(struct Actor *);
extern void (*table_0c241178[])(struct Actor *);
extern int *table_0c240fe0[];
void func_0c073368(struct Actor *, int);
void func_0c0733da(struct Actor *);
void func_0c07341e(struct Actor *);

void func_0c072ee8(struct Actor *a)
{
    int zero;
    a->b6++;
    zero = (a->b1f9 = 0);
    a->f56 = a->f41c;
    a->b1d4 = 1;
    a->b1fc = zero;
    a->pad7f2 = zero;
    a->b1ed = 4;
    a->s28 = zero;
    a->s30 = ((unsigned char)a->b1a3 << 1) + 3;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1a1 = ((unsigned char)a->b1a3 << 1) + 76;
    a->w1ac = zero;
    a->b19e = zero;
    *(unsigned int *)&a->p1c4 = zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    func_0c0432ca(a);
    func_0c048bb0(a, 5);
    func_0c02a0c4(a, 21, zero);
}
void func_0c072f8c(struct Actor *a) { table_0c241168[a->b7](a); }
void func_0c072f9e(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->b141) {
        a->b7++;
        a->b141 = 0;
        func_0c0451f2(a);
        func_0c073368(a, 0);
        func_0c0344a0(a, 31);
    }
    func_0c0733da(a);
    func_0c07341e(a);
}
void func_0c073044(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!(a->f92 * a->f104 < 0.0f)) {
        float z = 0.0f;
        a->f92 = z;
        a->f104 = z;
    }
    if (func_0c02a026(a) < 0) {
        a->b7++;
        func_0c073368(a, 1);
        func_0c0344a0(a, 31);
        if (!a->s28) {
            int zero = 0;
            a->b7 = 3;
            a->b1a1 = 75;
            a->w1ac = zero;
            a->b19e = zero;
            *(unsigned int *)&a->p1c4 = zero;
            dat_0c2f83f8->arr[a->b2]++;
            func_0c02a0c4(a, 21, 3);
            return;
        }
        {
            int one = 1;
            a->b32 = one;
            a->s28 = 0;
            a->s30--;
            func_0c02a0c4(a, 21, one);
        }
        return;
    }
    func_0c0733da(a);
    func_0c07341e(a);
}
void func_0c073138(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!(a->f92 * a->f104 < 0.0f)) {
        float z = 0.0f;
        a->f92 = z;
        a->f104 = z;
    }
    if (func_0c02a026(a) < 0) {
        int zero;
        func_0c0344a0(a, 31);
        zero = 0;
        if (a->s28) {
            a->s28 = zero;
            if (--a->s30 > 0) {
                a->f96 += 10.714285f;
                func_0c02a0c4(a, 21, (a->b32 ^= 1) + 1);
                return;
            }
        }
        a->b7 = 3;
        a->b1a1 = 75;
        a->w1ac = zero;
        a->b19e = zero;
        *(unsigned int *)&a->p1c4 = zero;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c02a0c4(a, 21, 3);
        return;
    }
    func_0c0733da(a);
    func_0c07341e(a);
}
void func_0c073234(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!(a->f92 * a->f104 < 0.0f)) {
        float z = 0.0f;
        a->f92 = z;
        a->f104 = z;
    }
    func_0c02a026(a);
    if (a->f96 < 0.0f) {
        a->b6++;
        a->b7 = 0;
        a->b19e = 1;
        a->f108 = -1.2053571f;
        func_0c02a0c4(a, 21, 4);
    }
}
void func_0c0732c8(struct Actor *a)
{
    if (!a->b7) {
        a->f56 += a->f96;
        a->f96 += a->f108;
        func_0c02a026(a);
        if (a->f56 < a->f41c) {
            a->b7++;
            a->b1f9 = 0;
            a->f56 = a->f41c;
            func_0c02a0c4(a, 21, a->b1a3 + 5);
            func_0c043324(a);
        }
    } else if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
    }
}
void func_0c073368(struct Actor *a, int idx)
{
    int *v;

    v = table_0c240fe0[idx];
    v += (unsigned char)a->b1a3 * 4;

    a->f92 = (float)*v++ * 1.66666663f / 65536.0f;
    a->f104 = (float)*v++ * 1.66666663f / 65536.0f;
    a->f96 = (float)*v++ * 2.1428571f / 65536.0f;
    a->f108 = (float)*v * 2.1428571f / 65536.0f;
    if (a->b1d2) {
        a->f92 = -a->f92;
        a->f104 = -a->f104;
    }
}
void func_0c0733da(struct Actor *a)
{
    if (a->b14b) {
        a->b1a1 = ((unsigned char)a->b1a3 << 1) + a->b14b + 75;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        a->b14b = 0;
    }
}
void func_0c07341e(struct Actor *a)
{
    if (a->b140) {
        if (!a->b525) {
            unsigned short t = a->w348 | a->w352;
            if (t & 0x300) {
                a->s28 = 1;
                a->w352 = 0;
            }
        } else {
            if (!a->b411)
                a->s28 = 1;
        }
    }
}
void func_0c073462(struct Actor *a) { table_0c241178[a->b6](a); }
