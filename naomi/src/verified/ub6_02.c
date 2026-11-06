#include "objects.h"
typedef void (*handler_ub6_02)(struct Actor *);

extern handler_ub6_02 dat_0c249aa4[];
extern float dat_0c249ab0[];
extern signed char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c0438de(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0eb60a(struct Actor *);
extern void func_0c043324(struct Actor *);

void func_0c0e9950(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b140) {
        a->b140 = 0;
        func_0c0346da(a, 22);
    }
    if (--a->s30 > 0 && a->f56 > a->f41c)
        return;
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 11, 10);
}

void func_0c0e99b2(struct Actor *a)
{
    if (a->b1f9 == 2)
        func_0c0438de(a);
    else
        func_0c0437b8(a);
}

void func_0c0e99c8(struct Actor *a)
{
    dat_0c249aa4[a->b6](a);
}

void func_0c0e99da(struct Actor *a)
{
    if (a->f56 < a->f41c) {
        a->f56 = a->f41c;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c0437b8(a);
        func_0c043324(a);
        return;
    }
    if (a->b201)
        func_0c0eb60a(a);
    func_0c02a026(a);
    if (!a->b141)
        return;
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1fc = 0;
    if (a->b1e8 == 97) {
        a->f92 = 10.833333015441895f;
        a->f96 = -6.4285712242126465f;
        a->s30 = (short)dat_0c249ab0[0];
    } else if (a->b1e8 == 98) {
        a->f92 = 6.66666667f;
        a->f96 = -8.5714283f;
        a->s30 = (short)dat_0c249ab0[1];
    } else {
        a->f92 = 2.5f;
        a->f96 = -11.785714149475098f;
        a->s30 = (short)dat_0c249ab0[2];
    }
    if (!a->b1d2)
        a->f92 = -a->f92;
    a->b1fc = 0;
}

void func_0c0e9b04(struct Actor *a)
{
    if (a->b140) {
        a->b140 = 0;
        if (a->b1e8 == 97)
            func_0c0346da(a, 20);
        else if (a->b1e8 == 98)
            func_0c0346da(a, 21);
        else
            func_0c0346da(a, 22);
    }
    func_0c02a026(a);
    a->s30--;
    if (a->s30 != 0 && a->f56 > a->f41c)
        return;
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    if (a->b1f9 == 2) {
        if (a->b1e8 == 97)
            func_0c02a0c4(a, 12, 15);
        else if (a->b1e8 == 98)
            func_0c02a0c4(a, 12, 16);
        else
            func_0c02a0c4(a, 12, 17);
        return;
    }
    if (a->b1e8 == 97)
        func_0c02a0c4(a, 12, 12);
    else if (a->b1e8 == 98)
        func_0c02a0c4(a, 12, 13);
    else
        func_0c02a0c4(a, 12, 14);
}
void func_0c0e9c0c(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        if (a->b1f9 == 2)
            func_0c0438de(a);
        else
            func_0c0437b8(a);
    }
}
