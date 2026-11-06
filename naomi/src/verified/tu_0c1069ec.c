/* Exact 584-byte actor group: eleven routines and two literal pools.
 * The initializer tail-calls 106a0c by fallthrough; 106b70 is an epilogue. */
#include "objects.h"

extern void func_0c0421f4(struct Actor *);
extern void func_0c0420f8(struct Actor *);
extern void func_0c042018(struct Actor *);
extern void func_0c0421b8(struct Actor *);
extern unsigned char func_0c0462a0(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c172474(struct Actor *, int, int);
extern void (*dat_0c24b524[])(struct Actor *);
extern void (*dat_0c24b530[])(struct Actor *);
extern void func_0c106a64(struct Actor *);
extern void func_0c106b42(struct Actor *);
extern void func_0c106a0c(struct Actor *);

void func_0c1069ec(struct Actor *a)
{
    if (a->b201)
        goto dispatch;
    func_0c0421f4(a);
    func_0c0420f8(a);
dispatch:
    func_0c106a0c(a);
}

void func_0c106a0c(struct Actor *a)
{
    if (a->b201 == 0 || func_0c0462a0(a) == 0) {
        func_0c042018(a);
        func_0c0421b8(a);
        if ((unsigned char)a->b1fe == 1)
            func_0c106b42(a);
        else
            func_0c106a64(a);
        if (func_0c044e52(a)) {
            func_0c044f1c(a);
            return;
        }
    }
}

void func_0c106a64(struct Actor *a)
{
    dat_0c24b524[a->b1e8](a);
}

void func_0c106a78(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c0438de(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        func_0c172474(a, 1, 6);
    }
}

void func_0c106ab2(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c0438de(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        func_0c172474(a, 1, 3);
    }
}

void func_0c106b20(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0438de(a);
}

void func_0c106b42(struct Actor *a)
{
    dat_0c24b530[a->b1e8](a);
}

void func_0c106b56(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0438de(a);
}

void func_0c106b78(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0438de(a);
}

void func_0c106b9a(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0438de(a);
}

void func_0c106bbc(struct Actor *a)
{
    func_0c02a026(a);
    if (!a->b141) {
        a->b141 = 0;
        a->b7++;
        a->f92 = -3.3333333f;
        a->f104 = 0.0f;
        a->f96 = -2.1428571f;
        a->f108 = -0.2678571343422f;
        if (a->w130 != 0) {
            a->f92 = -a->f92;
            a->f104 = -a->f104;
        }
    }
}
