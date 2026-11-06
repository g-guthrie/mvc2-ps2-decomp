/* Nine actor callbacks and both shared literal pools. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c120c24(struct Actor *);
extern struct Dat_13bb5c dat_0c2f8338;
extern int func_0c03916c(struct Actor *);
extern void (*dat_0c24d330[])(struct Actor *);
extern void (*dat_0c24d344[])(struct Actor *);
extern void (*dat_0c24d370[])(struct Actor *);
extern unsigned int func_0c02849a(void);
extern void func_0c1bc460(struct Actor *, int);
extern void func_0c0344a0(struct Actor *, int);
void func_0c11f7a8(struct Actor *);
void func_0c11f774(struct Actor *a)
{
    float speed, acceleration;
    a->b6++;
    a->s28 = 16;
    speed = -13.33333302f;
    acceleration = 0.41666666f;
    if (!a->b1d2) {
        speed = 13.33333302f;
        acceleration = -0.41666666f;
    }
    a->f92 = speed;
    a->f104 = acceleration;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    func_0c11f7a8(a);
}
void func_0c11f7a8(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141 >= 0) {
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
        if (--a->s28 < 0) {
            float speed;
            a->b6++;
            speed = -1.66666663f;
            if (!a->b1d2)
                speed = 1.66666663f;
            a->f92 = speed;
            a->f104 = 0.0f;
            func_0c02a0c4(a, 2, 3);
        }
    }
}
void func_0c11f832(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c02a026(a) < 0)
        func_0c120c24(a);
}
void func_0c11f88c(struct Actor *a)
{
    if (a->b6 == 0) {
        if (dat_0c2f8338.pad[0] < 2) {
            a->b12c = 0;
            return;
        }
        a->b6++;
        a->b12c = 1;
        func_0c02a0c4(a, 18, 0);
    } else if (func_0c02a026(a) < 0)
        a->b5++;
}
void func_0c11f912(struct Actor *a)
{
    if (func_0c03916c(a))
        func_0c120c24(a);
    else
        dat_0c24d330[a->b32](a);
}
void func_0c11f93e(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, func_0c02849a() & 1);
        func_0c1bc460(a, 1);
        func_0c0344a0(a, func_0c02849a() % 3 + 15);
    } else
        func_0c02a026(a);
}
void func_0c11f98e(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 19, 2);
    } else
        func_0c02a026(a);
}
void func_0c11f9a8(struct Actor *a) { dat_0c24d344[a->b1e9](a); }
void func_0c11f9bc(struct Actor *a) { dat_0c24d370[a->b6](a); }
