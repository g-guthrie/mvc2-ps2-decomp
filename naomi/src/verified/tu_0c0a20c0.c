#include "objects.h"

struct Motion_0c0a20c0 { float x, y, vx, vy; };
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c243aa4[];
extern float table_0c2437c4[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);

void func_0c0a20c0(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        func_0c043324(a);
        a->b6++;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        func_0c02a0c4(a, 20, 1);
    }
}

void func_0c0a2140(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0a2162(struct Actor *a)
{
    table_0c243aa4[a->b6](a);
}

void func_0c0a2174(struct Actor *a)
{
    float *p;
    a->b6++;
    a->b1a1 = 86;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    func_0c0432ca(a);
    p = table_0c2437c4;
    p += (unsigned char)a->b1a3 * 4;
    if (*(volatile unsigned char *)&a->b1d2)
        a->f92 = -p[0];
    else
        a->f92 = p[0];
    /* Member access keeps the retail indexed load for the second float. */
    if (*(volatile unsigned char *)&a->b1d2)
        a->f104 = -((struct Motion_0c0a20c0 *)p)->y;
    else
        a->f104 = ((struct Motion_0c0a20c0 *)p)->y;
    a->f96 = p[2];
    a->f108 = p[3];
    func_0c02a0c4(a, 21, 6);
}
