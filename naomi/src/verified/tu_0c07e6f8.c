#include "objects.h"
extern void func_0c0432ca(struct Actor *);
extern void func_0c0818f8(struct Actor *);
extern void func_0c08183c(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0451f2(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c1931e0(struct Actor *, int);
extern float dat_0c241a98[];
extern void (*table_0c241ab0[])(struct Actor *);
void func_0c07e82c(struct Actor *);
void func_0c07e6f8(struct Actor *a)
{
    float velocity, acceleration;
    float *target;
    a->b6++;
    func_0c0432ca(a);
    func_0c0818f8(a);
    func_0c048bb0(a, 5);
    velocity = *(float *)((char *)dat_0c241a98 + (((unsigned char)a->b1a3 << 1) << 2));
    acceleration = 0.72916663f;
    if (a->w130) { velocity = -velocity; acceleration = -0.72916663f; }
    a->f92 = velocity;
    a->f104 = acceleration;
    target = dat_0c241a98 + (unsigned char)a->b1a3 * 2;
    a->f96 = target[3];
    a->f108 = -1.07142854f;
    func_0c02a0c4(a, 21, (unsigned char)a->b1a3 * 2 + 18);
}
void func_0c07e774(struct Actor *a)
{
    func_0c02a026(a);
    if (!a->b141) { a->b6++; func_0c0451f2(a); }
}
void func_0c07e79c(struct Actor *a)
{
    func_0c07e82c(a);
    if (!a->b141) func_0c02a026(a);
    if (a->f56 < a->f41c) { a->b6++; func_0c0818f8(a); }
}
void func_0c07e7d4(struct Actor *a) { if (func_0c02a026(a) < 0) func_0c08183c(a); }
void func_0c07e82c(struct Actor *a)
{
    if (a->f92 * a->f104 < 0) { a->f52 += a->f92; a->f92 += a->f104; }
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f96 < 0) a->f108 = -2.1428571f;
}
void func_0c07e886(struct Actor *a) { func_0c08183c(a); }
void func_0c07e88c(struct Actor *a) { func_0c08183c(a); }
void func_0c07e892(struct Actor *a) { table_0c241ab0[a->b6](a); }
void func_0c07e8a4(struct Actor *a)
{
    float velocity, acceleration;
    a->b6++;
    func_0c0442fa(a);
    if (a->b1f9 != 2) { a->b1f9 = 0; func_0c0432ca(a); }
    a->sub2a4.l24 = 0;
    func_0c048bb0(a, 1);
    a->f96 = 0;
    a->f108 = 0;
    velocity = -16.666666031f;
    acceleration = 0.3125f;
    if (a->b1d2) { velocity = 16.666666031f; acceleration = -0.3125f; }
    a->f92 = velocity;
    a->f104 = acceleration;
    func_0c02a0c4(a, 21, 22);
}
void func_0c07e912(struct Actor *a)
{
    func_0c02a026(a);
    if (!a->b141) {
        a->b6++;
        a->s28 = 16;
        a->l2c8 = 4;
        func_0c1931e0(a, 0);
    }
}
