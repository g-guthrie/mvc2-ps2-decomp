/* Actor state routines; reviewed span 0x0c0f9b64..0x0c0f9de4. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c1b3e6c(struct Actor *, int);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*dat_0c24a84c[])(struct Actor *);

void func_0c0f9b64(struct Actor *a)
{
    unsigned int anim;
    (void)func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    if ((a->f96 += a->f108) > 0.0f)
        return;
    if (a->f56 + 68.57143f > a->f41c)
        return;
    a->b6++;
    a->f56 = a->f41c;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    dat_0c2d9260.b5 = 3;
    dat_0c2d9260.b6 = 1;
    func_0c043324(a);
    if (a->b19e) {
        a->b1f9 = 1;
        anim = (unsigned char)a->b1a3 * 2 + 21;
    } else {
        a->b1f9 = 3;
        anim = (unsigned char)a->b1a3 * 2 + 24;
    }
    func_0c02a0c4(a, 21, anim);
}
void func_0c0f9c32(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c0f9c54(struct Actor *a)
{
    if (!a->b6) {
        a->b6++;
        a->s28 = 60;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f56 = a->f41c;
        func_0c0442fa(a);
        func_0c02a0c4(a, 21, 17);
        return;
    }
    goto g;
g:
    (void)func_0c02a026(a);
    if (--a->s28 != 0) {
        if (a->b141) {
            a->b141 = 0;
            func_0c1b3e6c(a, 7);
        }
    } else {
        func_0c0437b8(a);
    }
}
void func_0c0f9cf6(struct Actor *a)
{
    a->b6++;
    func_0c02a0c4(a, 20, 3);
}
void func_0c0f9d04(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c0f9d26(struct Actor *a)
{
    dat_0c24a84c[a->b6](a);
}
void func_0c0f9d38(struct Actor *a)
{
    a->b6++;
    func_0c02a39a(a, 0);
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 4.28571415f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 62;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}
