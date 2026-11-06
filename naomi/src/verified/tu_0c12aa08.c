/* Landing check, round-start state handlers and their dispatchers. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern int func_0c03916c(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c191980(struct Actor *, int);
extern struct ActorFlags *dat_0c2d6f84;
extern void (*dat_0c24dcf4[])(struct Actor *);
extern void (*dat_0c24dcfc[])(struct Actor *);
extern void (*dat_0c24dd30[])(struct Actor *);
void func_0c12aa08(struct Actor *a)
{
    int zero;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (func_0c044e52(a)) {
        a->b6++;
        zero = 0;
        a->b7 = zero;
        a->f52 -= a->f92;
        a->b1f9 = zero;
        func_0c02a0c4(a, 18, 2);
    }
}
void func_0c12aa8c(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b5++;
        func_0c02a0c4(a, 0, 0);
    }
}
void func_0c12aab6(struct Actor *a) { dat_0c24dcf4[a->b6](a); }
void func_0c12aac8(struct Actor *a)
{
    a->b6++;
    switch (a->b32) {
    case 0:
    case 2:
        a->b33 = dat_0c2d6f84->flags & 1;
        func_0c02a0c4(a, 19, (char)a->b33);
        break;
    case 1:
    case 3:
    case 4:
        func_0c02a0c4(a, 19, 2);
        break;
    }
}
void func_0c12ab14(struct Actor *a)
{
    float shift;
    if (func_0c03916c(a)) {
        func_0c0437b8(a);
        return;
    }
    switch (a->b32) {
    case 0: case 2: case 4:
        if (!a->b33) {
            func_0c02a026(a);
            if (a->b141) {
                a->b141 = 0;
                shift = (signed char)a->b140;
                if (a->b1d2)
                    shift = -shift;
                a->f52 += shift;
            }
        } else if (func_0c02a026(a) >= 0) {
            if (a->b141) {
                a->b141 = 0;
                func_0c191980(a, 6);
            }
        } else {
            a->b32 = 4;
            func_0c02a0c4(a, 0, 0);
        }
        break;
    case 1: case 3:
        func_0c02a026(a);
        break;
    }
}
void func_0c12abea(struct Actor *a) { dat_0c24dcfc[a->b1e9](a); }
void func_0c12abfe(struct Actor *a) { dat_0c24dd30[a->b6](a); }
